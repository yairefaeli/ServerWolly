//
// Created by or on 26/12/17.
//

#ifndef SERVER_COMMANDSMANAGERS_H
#define SERVER_COMMANDSMANAGERS_H
#include <map>
#include "Command.h"
#include "Task.h"
#include <pthread.h>

class CommandsManager {
public:
    CommandsManager();
    CommandsManager(map<string,Task*>* threadMap, int firstClientSocket);
    ~CommandsManager();
    void executeCommand(string command,vector<string> args);
private:
    map<string,Command *> commandsMap;
    map<string,Task*>* threadMap;
    int clientSocket;
};




#endif //SERVER_COMMANDSMANAGERS_H
