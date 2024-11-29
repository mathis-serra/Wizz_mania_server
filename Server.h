#ifndef SERVER_H
#define SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

class Server {
public:
    Server(int port);
    ~Server();
    bool start();
    void stop();

private:
    void handleClient(int clientSocket);
    void broadcastMessage(const std::string &message, int senderSocket);

    int port;
    int listenSocket;  // Utilisation d'un entier pour le descripteur de socket
    std::vector<int> clientSockets;  // Liste des sockets clients
    std::mutex clientMutex;  // Mutex pour la gestion concurrente des sockets clients
};

#endif
