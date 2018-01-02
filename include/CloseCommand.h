//
// Created by logia on 02/01/18.
//

#ifndef SERVER_CLOSECOMMAND_H
#define SERVER_CLOSECOMMAND_H


#include <map>
#include "Command.h"
#include "Task.h"
#include "ThreadPool.h"

using namespace std;

class CloseCommand : Command {
public:
    //Constructor
    CloseCommand(map<string, Task *> *threadMap, int firstClientSocket, ThreadPool tp);

    //the command execute
    string execute(vector<string> args);

    // destructor
    ~Command() {}

private:
    map<string, Task *> *mapOfThreads;
    int firstClientSocket;
    ThreadPool tp = 0;
};


#endif //SERVER_CLOSECOMMAND_H
