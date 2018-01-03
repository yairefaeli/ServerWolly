//
// Created by logia on 02/01/18.
//

#ifndef SERVER_PLAYCOMMAND_H
#define SERVER_PLAYCOMMAND_H


#include "include/Task.h"
#include "include/Command.h"
#include <cstdlib>

class playCommand : Command {
public:
    playCommand(int fSocket,int sSocket);

    string execute(vector<string> args);
    //virtual ~Command(){}

private:
    int fSocket;
    int sSocket;
    int turn;
    };




#endif //SERVER_PLAYCOMMAND_H
