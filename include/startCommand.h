//
// Created by logia on 29/12/17.
//

#ifndef SERVER_STARTCOMMMAND_H
#define SERVER_STARTCOMMMAND_H
#include <map>
#include <string.h>
#include "Command.h"
#include "Task.h"


/*
 * StartCommand is the command that start a game
 * It open a new Task that manage a thread itself
*/
using namespace std;
 class startCommand : Command {

 public:
     //Constructor
     startCommand(map<string, Task*>* threadMap);

     //the command execute
     string execute(vector<string> args);

     //
     ~Command() {}

 private:
     map<string, Task *> *mapOfThread;
 };


#endif //SERVER_STARTCOMMMAND_H
