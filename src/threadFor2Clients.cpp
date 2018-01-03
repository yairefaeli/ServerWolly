//
// Created by logia on 28/12/17.
//

#include "../include/threadFor2Clients.h"
#include "../include/ThreadPool.h"
#include "../include/CommandsManagers.h"
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>
#include <map>
#include <cstring>

using namespace std;

threadFor2Clients::threadFor2Clients(int firstClientSocket, int turn, ThreadPool *tp, map<string,Task*>* threadMap) {
    int n = write(firstClientSocket, &turn, sizeof(int));
    this->firstClientSocket = firstClientSocket;
    this->turn = turn;
    this->secondClientSocket = 0;
    //
    this->tp = tp;
    this->threadMap = threadMap;
    // initialize command manager
    this->cmdm.addThreadMap(this->threadMap);
    this->cmdm.addClientSocket(this->firstClientSocket);
    this->cmdm.addThreadPool(tp);
    this->cmdm.initializeMap();
}


 void threadFor2Clients::run(){

     if (turn % 2 == 1) {
         handleClient(firstClientSocket, secondClientSocket);
     } else {
         handleClient(secondClientSocket, firstClientSocket);
     }
     turn++;

};


void threadFor2Clients::join(int secondClientSocket){
    this->secondClientSocket = secondClientSocket;
}

bool threadFor2Clients::available() {
    if(secondClientSocket != 0){
        return false;
    }
    return true;
}


void threadFor2Clients::handleClient(int currentClientSocket,int otherClientSocket) {
    //the value of X and Y
    std::vector<string> cmd;
    string str;
    int thePointY;

    //start the reading and writing
    // Read new string command from the player that this is his turn
    int n = read(currentClientSocket, &str, sizeof(str));
    if (n == -1) {
        cout << "Error reading point" << endl;
        return;
    }
    char delim = ' ';
    char *toDelim = &delim;
    vector<string> command;
    command.push_back(strtok((char*)&str, toDelim));
    command.push_back(strtok(NULL, toDelim));
    command.push_back(strtok(NULL, toDelim));
    cout << command.at(0) << " " << command.at(1);

    // execute command
    cmdm.executeCommand(cmd.at(0),command);

}

