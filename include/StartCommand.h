//
// Created by logia on 29/12/17.
//

#ifndef SERVER_STARTCOMMAND_H
#define SERVER_STARTCOMMAND_H

#include "include/Command.h"

class StartCommand : Command {
public:
    string execute(vector<string> args);
    ~Command(){}
};


#endif //SERVER_STARTCOMMAND_H
