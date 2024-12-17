#include "Server.h"
#include <algorithm>
#include <map>

std::map<SOCKET, SSL*> sslClients;

Server::Server(int port) : port(port), listenSocket(INVALID_SOCKET) {
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        std::cerr << "Erreur d'initialisation de WinSock : " << result << std::endl;
    }

    SSL_library_init();
    ctx = InitServerCTX();
    LoadCertificates("../certs/server_cert.pem", "../certs/server_key.pem");
}

Server::~Server() {
    stop();
    SSL_CTX_free(ctx);
    WSACleanup();
    EVP_cleanup();
}

SSL_CTX* Server::InitServerCTX() {
    SSL_CTX* ctx;
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(TLS_server_method());

    if (ctx == nullptr) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    return ctx;
}

void Server::LoadCertificates(const char* CertFile, const char* KeyFile) {
    if (SSL_CTX_use_certificate_file(ctx, CertFile, SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    if (SSL_CTX_use_PrivateKey_file(ctx, KeyFile, SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    if (!SSL_CTX_check_private_key(ctx)) {
        std::cerr << "La clé privée ne correspond pas au certificat public" << std::endl;
        exit(EXIT_FAILURE);
    }
}

bool Server::start() {
    listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listenSocket == INVALID_SOCKET) {
        std::cerr << "Erreur de création du socket : " << WSAGetLastError() << std::endl;
        WSACleanup();
        return false;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    if (bind(listenSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Erreur de liaison du socket : " << WSAGetLastError() << std::endl;
        closesocket(listenSocket);
        WSACleanup();
        return false;
    }

    if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Erreur lors de l'écoute : " << WSAGetLastError() << std::endl;
        closesocket(listenSocket);
        WSACleanup();
        return false;
    }

    std::cout << "Serveur sécurisé en écoute sur le port " << port << std::endl;

    while (true) {
        SOCKET clientSocket = accept(listenSocket, nullptr, nullptr);
        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "Erreur d'acceptation de la connexion : " << WSAGetLastError() << std::endl;
            continue;
        }

        std::cout << "Connexion client acceptée !" << std::endl;

        SSL* ssl = SSL_new(ctx);
        SSL_set_fd(ssl, clientSocket);

        if (SSL_accept(ssl) <= 0) {
            ERR_print_errors_fp(stderr);
            SSL_free(ssl);
            closesocket(clientSocket);
            continue;
        }

        {
            std::lock_guard<std::mutex> lock(clientMutex);
            clientSockets.push_back(clientSocket);
            sslClients[clientSocket] = ssl;
        }

        std::thread(&Server::handleSSLClient, this, ssl, clientSocket).detach();
    }

    return true;
}

void Server::handleSSLClient(SSL* ssl, SOCKET clientSocket) {
    char buffer[1024];
    int bytesReceived;

    while (true) {
        bytesReceived = SSL_read(ssl, buffer, sizeof(buffer) - 1);
        if (bytesReceived <= 0) {
            std::cout << "Client déconnecté." << std::endl;
            SSL_free(ssl);
            closesocket(clientSocket);

            {
                std::lock_guard<std::mutex> lock(clientMutex);
                clientSockets.erase(std::remove(clientSockets.begin(), clientSockets.end(), clientSocket), clientSockets.end());
                sslClients.erase(clientSocket);
            }
            return;
        }

        buffer[bytesReceived] = '\0';
        std::string message = buffer;
        std::cout << "Message reçu : " << message << std::endl;

        broadcastMessage(message, clientSocket);
    }
}

void Server::broadcastMessage(const std::string &message, SOCKET senderSocket) {
    std::lock_guard<std::mutex> lock(clientMutex);
    std::cout << "Diffusion du message : " << message << std::endl;

    for (SOCKET client : clientSockets) {
        if (client != senderSocket) {
            SSL* ssl = sslClients[client];
            SSL_write(ssl, message.c_str(), message.size());
            std::cout << "Message envoyé au client sur socket : " << client << std::endl;
        }
    }
}

void Server::stop() {
    if (listenSocket != INVALID_SOCKET) {
        closesocket(listenSocket);
        listenSocket = INVALID_SOCKET;
    }

    for (SOCKET clientSocket : clientSockets) {
        SSL_free(sslClients[clientSocket]);
        closesocket(clientSocket);
    }
    clientSockets.clear();
    sslClients.clear();
}