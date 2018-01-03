//
// Created by logia on 29/12/17.
//

#ifndef SERVER_STARTCOMMMAND_H
#define SERVER_STARTCOMMMAND_H
#include <map>
#include <string.h>
#include "Command.h"
#include "Task.h"
#include "ThreadPool.h"


/*
 * StartCommand is the command that start a game
 * It open a new Task that manage a thread itself
*/
using namespace std;
 class startCommand : Command {

 public:
     //Constructor
     startCommand(map<string, Task *> *threadMap, int firstClientSocket, ThreadPool* tp);

     //the command execute
     string execute(vector<string> args);

     // destructor
    // ~Command() {}

 private:
     map<string, Task *> *mapOfThreads;
     int firstClientSocket;
     ThreadPool *tp;
 };


#endif //SERVER_STARTCOMMMAND_H