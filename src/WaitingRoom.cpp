
#include "../include/WaitingRoom.h"
#include "../include/threadFor2Clients.h"

WaitingRoom::WaitingRoom(map<string, Task *>* threadMap ,int clientSocket, ThreadPool *tp) {
    cout<<"inside building watingroom";
    this->threadMap=threadMap;
    this->clientSocket=clientSocket;
    this->tp=tp;
    this->cmdm.addThreadMap(this->threadMap);
    this->cmdm.addClientSocket(this->clientSocket);
    this->cmdm.addThreadPool(tp);
    cout<<" finnish"<<endl;
}


void WaitingRoom::run() {
    cout<<"inside run watingroom";
    string str;
    int n = read(clientSocket, &str, sizeof(str));

    //breaking the string
    char delim=' ';
    char* toDelim=&delim;
    vector<string> command;
    command.push_back(strtok((char *)&str,toDelim));
    command.push_back(strtok(NULL,toDelim));
    // the command he chose
    cmdm.initializeMap();
    cout<<"bedore command watingroom";
    cmdm.executeCommand(command.at(0),command);
}