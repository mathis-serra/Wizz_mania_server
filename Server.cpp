#include "Server.h"
#include <algorithm>

Server::Server(int port) : port(port), listenSocket(INVALID_SOCKET) {
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        std::cerr << "Erreur d'initialisation de WinSock : " << result << std::endl;
    }
}

Server::~Server() {
    stop();
    WSACleanup();
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

    std::cout << "Serveur en écoute sur le port " << port << std::endl;

    while (true) {
        SOCKET clientSocket = accept(listenSocket, nullptr, nullptr);
        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "Erreur d'acceptation de la connexion : " << WSAGetLastError() << std::endl;
            continue;
        }

        std::cout << "Connexion client acceptée !" << std::endl;

        {
            std::lock_guard<std::mutex> lock(clientMutex);
            clientSockets.push_back(clientSocket);
        }

        std::thread(&Server::handleClient, this, clientSocket).detach();
    }

    return true;
}

void Server::handleClient(SOCKET clientSocket) {
    char buffer[1024];
    int bytesReceived;

    while (true) {
        bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesReceived == SOCKET_ERROR || bytesReceived == 0) {
            std::cout << "Client déconnecté." << std::endl;
            closesocket(clientSocket);

            {
                std::lock_guard<std::mutex> lock(clientMutex);
                clientSockets.erase(std::remove(clientSockets.begin(), clientSockets.end(), clientSocket), clientSockets.end());
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
            send(client, message.c_str(), message.size() + 1, 0);
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
        closesocket(clientSocket);
    }
    clientSockets.clear();
}
