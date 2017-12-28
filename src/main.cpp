#include "../include/Server.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;
int main() {



    std::ifstream file("server_definitions");
    int port;
    file >> port;

    Server server(port);

    char* str=(char*)malloc(300);
    char* str2=(char*)malloc(300);
    scanf("%s%s",str,str2);
    strcat(str," ");
    strcat(str,str2);
    printf("%s \n",str);

    server.handleRequest(str);
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
    server.stop();
}