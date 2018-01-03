//
// Created by or on 02/01/18.
//

#include "../include/JoinCommand.h"

#include <string.h>
#include <iostream>

joinCommand::joinCommand(map<string, Task *>* threadMap,int firstClientSocket) {
this->threadMap=threadMap;
this->firstClientSocket = firstClientSocket;
}

string joinCommand::execute(vector<string> args) {
    if (threadMap->count(args.at(1)) == 1) {

        string str = args.at(1);
        (*(this->threadMap))[str]->join(this->firstClientSocket);
   }
    return "s";
}