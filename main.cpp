#include "Server.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;
int main() {
    std::ifstream file("definitions");
    int port;
    file >> port;

    Server server(port);
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
    server.stop();
}