#include "Server.h"
#include "applink.c"

int main() {
    Server server(40000);
    if (server.start()) {
        std::cout << "Serveur démarré avec succès !" << std::endl;
    } else {
        std::cerr << "Échec du démarrage du serveur." << std::endl;
    }
    server.stop();
    return 0;
}
