//
// Created by logia on 07/12/17.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H


#include <string>
#include <map>
#include "CommandsManagers.h"

class Server {
public:
    Server(int port);

    void start();
    void stop();
    void handleRequest(char* str);
private:
    int port;
    CommandsManager cmdm=CommandsManager();
    int serverSocket; // the socket's file descriptor
    void handleClient(int currentClientSocket,int otherClientSocket);
    void initilaizeTurns(int firstClientSocket,int secondClientSocket);

};


#endif //SERVER_SERVER_H
