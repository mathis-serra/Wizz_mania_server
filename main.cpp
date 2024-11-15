#include "Server.h"

int main() {
    Server server(54000);
    if (server.start()) {
        std::cout << "Serveur démarré avec succès !" << std::endl;
    } else {
        std::cerr << "Échec du démarrage du serveur." << std::endl;
    }
    server.stop();
    return 0;
}
