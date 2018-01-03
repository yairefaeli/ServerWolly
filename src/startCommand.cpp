//
// Created by logia on 29/12/17.
//

#include "../include/startCommand.h"
#include "../include/threadFor2Clients.h"


startCommand::startCommand(map<string, Task*>* threadMap,int firstClientSocket,ThreadPool* tp) {

    mapOfThreads = threadMap;
    this->firstClientSocket = firstClientSocket;
    this->tp = tp;

}

string startCommand :: execute(vector<string> args) {

    Task *t = (Task *) new threadFor2Clients(this->firstClientSocket, 0,tp ,mapOfThreads);
    //(*(this->mapOfThreads))[args[1]] =  t;
    this->tp->addTask(t);

}
