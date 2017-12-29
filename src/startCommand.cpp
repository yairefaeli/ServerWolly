//
// Created by logia on 29/12/17.
//

#include "../include/startCommand.h"
#include "../include/threadFor2Clients.h"


string startCommand :: execute(vector<string> args){

    // we need to find how the fuck we will move the socket and turn to here.
    // the shit face Or say that we wiil change the vector to have
    // them.

    Task* t=(Task*)new threadFor2Clients(firstClientSocket,turn,map);
    tp.addTask(t);

}

startCommand::startCommand(map<string, Task *> *threadMap) {
    mapOfThread = threadMap;
}
