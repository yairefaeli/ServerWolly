#include "../include/Server.h"
#include "../include/acceptingClients.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;
int main() {


    std::ifstream file("../src/server_definitions");
    int port;
    file >> port;


    ThreadPool tp = ThreadPool(50);
    Server server(port);
    server.getPool(&tp);
    Task *s = (Task *) new acceptingClients(server, &tp);
    tp.addTask(s);
    string c = "x";
    while (c.compare("exit") != 0) {
        cin >> c;
    }

    exit(0);
}