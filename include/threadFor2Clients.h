//
// Created by logia on 28/12/17.
//

#ifndef SERVER_START_H
#define SERVER_START_H

#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <map>
#include "Command.h"
#include "Task.h"

using namespace std;

class threadFor2Clients : Task{
public:
    threadFor2Clients(int firstClientSocket,int turn,map<string,Command*> cmdMap);
    void handleClient(int currentClientSocket,int otherClientSocket);
    void join(int secondClientSocket);
    bool available();

    private:
    int firstClientSocket;
    int secondClientSocket;
    int turn;
    map<string,Command*> cmdMap;
     ~Task() {}
    void run();
    void showTask();
};


#endif //SERVER_START_H
