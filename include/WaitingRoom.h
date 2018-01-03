//
// Created by or on 01/01/18.
//

#ifndef SERVER_WAITINGROOM_H
#define SERVER_WAITINGROOM_H

#include <string.h>
#include "Task.h"
#include "CommandsManagers.h"
#include "ThreadPool.h"
using namespace std;
class WaitingRoom :public Task {
public:
    WaitingRoom(map<string, Task *> *threadMap, int clientSocket, ThreadPool *tp);


    ~WaitingRoom() {};


    void showTask(){};

    void join(int secondClientSocket){};

    void run();


private:
    map<string, Task *> *threadMap;
    CommandsManager cmdm = CommandsManager();
    int clientSocket;
    ThreadPool *tp;

};
#endif //SERVER_WAITINGROOM_H
