//
// Created by logia on 28/12/17.
//

#ifndef SERVER_START_H
#define SERVER_START_H

#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include "Command.h"

using namespace std;

class Start : Command{
    void execute(vector<string> args);
    ~Command(){}
};


#endif //SERVER_START_H
