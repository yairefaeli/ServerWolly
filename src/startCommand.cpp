//
// Created by logia on 29/12/17.
//

#include "../include/startCommand.h"
#include "../include/threadFor2Clients.h"


string startCommand :: execute(vector<string> args) {

    Task *t = (Task *) new threadFor2Clients(this->firstClientSocket, 0, this->& mapOfThreads);
    this->tp.addTask(t);

    mapOfThreads->insert(std::pair<string, Task *>(args[1], t));

}

startCommand::startCommand(map<string, Task*>* threadMap,int firstClientSocket,ThreadPool tp) {

    mapOfThreads = threadMap;
    this->firstClientSocket = firstClientSocket;
    this->tp = tp;

}
