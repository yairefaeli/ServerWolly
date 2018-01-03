
#include "../include/WaitingRoom.h"
#include "../include/threadFor2Clients.h"
#define SIZEOF 2000
WaitingRoom::WaitingRoom(map<string, Task *>* threadMap ,int clientSocket, ThreadPool *tp) {
    this->threadMap = threadMap;
    this->clientSocket = clientSocket;
    this->tp = tp;
    this->cmdm.addThreadMap(this->threadMap);
    this->cmdm.addClientSocket(this->clientSocket);
    this->cmdm.addThreadPool(tp);
}


void WaitingRoom::run() {

    vector<string> command;
    do {
        char str[SIZEOF];
        long n = read(clientSocket, &str, SIZEOF);
        //breaking the string
        char delim = ' ';
        char *toDelim = &delim;
        char* token=strtok(str, toDelim);
        command.push_back(token);
        command.push_back(strtok(NULL, toDelim));

        // the command he chose
        cmdm.initializeMap();
        //cout<<"before command watingroom"
        cout << command.at(0) << endl;
        cmdm.executeCommand(command.at(0), command);
    } while (strcmp(command.at(0).c_str(),"list_games") == 0);
}