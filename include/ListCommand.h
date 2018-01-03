//
// Created by or on 29/12/17.
//

#ifndef SERVER_LISTCOMMAND_H
#define SERVER_LISTCOMMAND_H

#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <map>
#include "Command.h"
#include "Task.h"

using namespace std;

class ListCommand : Command {
public:
    ListCommand(map<string,Task*>* threadMap, int clientSocket);
    string execute(vector<string> args);
    //virtual ~Command(){}

private:
    map<string,Task*>* threadMap;
    int clientSocket;
};
#endif //SERVER_LISTCOMMAND_H
