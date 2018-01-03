//
// Created by or on 02/01/18.
//

#ifndef SERVER_JOINCOMMAND_H
#define SERVER_JOINCOMMAND_H


#include <map>
#include "Command.h"
#include "Task.h"

using namespace std;

class joinCommand : Command {
public:
    joinCommand(map<string,Task*>* threadMap,int firstClientSocket);

    string execute(vector<string> args) ;
    //virtual ~Command(){}

private:
    map<string,Task*>* threadMap;
    int firstClientSocket;
};


#endif //SERVER_JOINCOMMAND_H
