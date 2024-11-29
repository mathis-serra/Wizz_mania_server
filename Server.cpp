#include "Server.h"

#include <sys/types.h>        // Pour types comme sockaddr_in
#include <sys/socket.h>       // Pour socket(), bind(), etc.
#include <netinet/in.h>       // Pour sockaddr_in, AF_INET
#include <arpa/inet.h>        // Pour inet_pton() et inet_ntoa()
#include <unistd.h>           // Pour close() (au lieu de closesocket())
#include <cstring>            // Pour memset()
#include <errno.h>            // Pour strerror(errno)


Server::Server(int port) : port(port), listenSocket(-1) {
    // Aucun besoin de WSAStartup sous macOS
}

Server::~Server() {
    stop();
}

bool Server::start() {
    listenSocket = socket(AF_INET, SOCK_STREAM, 0);  // Pas besoin de spécifier IPPROTO_TCP sous macOS
    if (listenSocket == -1) {
        std::cerr << "Erreur de création du socket : " << strerror(errno) << std::endl;
        return false;
    }

    sockaddr_in serverAddress;
    std::memset(&serverAddress, 0, sizeof(serverAddress));  // Initialisation de la structure
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    if (bind(listenSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Erreur de liaison du socket : " << strerror(errno) << std::endl;
        close(listenSocket);
        return false;
    }

    if (listen(listenSocket, SOMAXCONN) == -1) {
        std::cerr << "Erreur lors de l'écoute : " << strerror(errno) << std::endl;
        close(listenSocket);
        return false;
    }

    std::cout << "Serveur en écoute sur le port " << port << std::endl;

    while (true) {
        int clientSocket = accept(listenSocket, nullptr, nullptr);
        if (clientSocket == -1) {
            std::cerr << "Erreur d'acceptation de la connexion : " << strerror(errno) << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Attente avant de réessayer
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


void Server::handleClient(int clientSocket) {
    char buffer[1024];
    ssize_t bytesReceived;

    while (true) {
        bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesReceived == -1 || bytesReceived == 0) {
            std::cout << "Client déconnecté." << std::endl;
            close(clientSocket);

            {
                std::lock_guard<std::mutex> lock(clientMutex);
                clientSockets.erase(std::remove(clientSockets.begin(), clientSockets.end(), clientSocket), clientSockets.end());
            }
            return;
        }

        buffer[bytesReceived] = '\0';  // Assurez-vous que la chaîne est terminée par un caractère nul
        std::string message = buffer;
        std::cout << "Message reçu : " << message << std::endl;

        broadcastMessage(message, clientSocket);
    }
}

void Server::broadcastMessage(const std::string &message, int senderSocket) {
    std::lock_guard<std::mutex> lock(clientMutex);
    std::cout << "Diffusion du message : " << message << std::endl;

    for (int client : clientSockets) {
        if (client != senderSocket) {
            send(client, message.c_str(), message.size() + 1, 0);
            std::cout << "Message envoyé au client sur socket : " << client << std::endl;
        }
    }
}

void Server::stop() {
    if (listenSocket != -1) {
        close(listenSocket);
        listenSocket = -1;
    }

    for (int clientSocket : clientSockets) {
        close(clientSocket);
    }
    clientSockets.clear();
}
