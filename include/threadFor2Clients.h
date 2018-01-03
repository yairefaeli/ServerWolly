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
#include "ThreadPool.h"
#include "CommandsManagers.h"

using namespace std;

class threadFor2Clients : public Task {
public:
    threadFor2Clients(int firstClientSocket, int turn, ThreadPool* tp,
                      map<string, Task *> *threadMap);

    void handleClient(int currentClientSocket, int otherClientSocket);

    void join(int secondClientSocket);

    void run();

    void showTask(){};
    bool available();

private:
    int firstClientSocket;
    int secondClientSocket;
    int turn;
    CommandsManager cmdm = CommandsManager();

    ThreadPool *tp;
    map<string, Task *> *threadMap;


    //~Task() {}

};


#endif //SERVER_START_H
