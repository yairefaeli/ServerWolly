#include "../include/Server.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;
int main() {



    std::ifstream file("../src/server_definitions");
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