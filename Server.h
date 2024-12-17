#ifndef SERVER_H
#define SERVER_H

#include <ws2tcpip.h>
#include <string>
#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/sha.h>

#pragma comment(lib, "ws2_32.lib")

class Server {
public:
    Server(int port);
    ~Server();
    bool start();
    void stop();

private:
    void handleClient(SOCKET clientSocket);
    void broadcastMessage(const std::string &message, SOCKET senderSocket);

    int port;
    SOCKET listenSocket;
    WSADATA wsaData;
    std::vector<SOCKET> clientSockets;
    std::mutex clientMutex;

    SSL_CTX* ctx;

    SSL_CTX* InitServerCTX();
    void LoadCertificates(const char* CertFile, const char* KeyFile);
    void handleSSLClient(SSL* ssl, SOCKET clientSocket);
};

#endif
