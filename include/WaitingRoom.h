//
// Created by or on 01/01/18.
//

#ifndef SERVER_WAITINGROOM_H
#define SERVER_WAITINGROOM_H

#include <string.h>
#include "Task.h"
#include "CommandsManagers.h"
#include "ThreadPool.h"

class WaitingRoom :Task {
public:
    WaitingRoom(map<string,Task*> threadMap,CommandsManager cmdm , int clientSocket, ThreadPool tp);




     void run()=0;
     void showTask()=0;

private:
    map<string,Task*> threadMap;
    CommandsManager cmdm=CommandsManager();
    int clientSocket;
    ThreadPool tp=0;

};
#endif //SERVER_WAITINGROOM_H
