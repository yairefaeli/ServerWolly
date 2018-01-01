//
// Created by or on 01/01/18.
//

#include "../include/WaitingRoom.h"
#include "../include/threadFor2Clients.h"

WaitingRoom::WaitingRoom(map<string, Task *> threadMap,int clientSocket, ThreadPool tp) {
    this->threadMap=threadMap;
    this->cmdm=cmdm;
    this->clientSocket=clientSocket;
    this->tp=tp;
}


void WaitingRoom::run() {
    string str;
    int n = read(clientSocket, &str, sizeof(str));
    char delim=' ';
    char* toDelim=&delim;
    vector<string> command;
    command.push_back(strtok((char *)&str,toDelim));
    command.push_back(strtok(NULL,toDelim));

    cmdm.executeCommand(*command.at(0),command);

    Task* t=(Task*)new threadFor2Clients(clientSocket,turn,map);
    tp.addTask(t);





}