//
// Created by logia on 07/12/17.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H


#include <string>
#include <map>
#include "CommandsManagers.h"
#include "Task.h"

class Server {
public:
    Server(int port);
    void getPool(ThreadPool *tp);
    void start();
    void stop();
    void handleRequest(char* str);
private:
    int port;

    //CommandsManager cmdm=CommandsManager(mapTasks);
    int serverSocket; // the socket's file descriptor
    void handleClient(int currentClientSocket,int otherClientSocket);
    void initilaizeTurns(int firstClientSocket,int secondClientSocket);
    ThreadPool *tp;
};


#endif //SERVER_SERVER_H
