//
// Created by logia on 02/01/18.
//

#include "../include/CloseCommand.h"

string CloseCommand :: execute(vector<string> args){
    this->mapOfThreads->erase(args[1]);
}

CloseCommand::CloseCommand(map<string, Task*>* threadMap,int firstClientSocket,ThreadPool *tp) {

    mapOfThreads = threadMap;
    this->firstClientSocket = firstClientSocket;
    this->tp = tp;

}