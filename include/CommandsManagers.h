//
// Created by or on 26/12/17.
//

#ifndef SERVER_COMMANDSMANAGERS_H
#define SERVER_COMMANDSMANAGERS_H
#include <map>
#include "Command.h"

class CommandsManager {
public:
    CommandsManager();
    ~CommandsManager();
    void executeCommand(string command,vector<string> args);
private:
    map<string,Command *> commandsMap;

};




#endif //SERVER_COMMANDSMANAGERS_H
