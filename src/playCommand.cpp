//
// Created by logia on 02/01/18.
//


#include "../include/playCommand.h"
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>
#include <map>
#include <cstring>
#include <iostream>
#define SIZEOF 2000

playCommand::playCommand(int fSocket, int sSocket) {
    this->fSocket=fSocket;
    this->sSocket=sSocket;
    turn=0;
}

string playCommand::execute(vector<string> args) {
    char s[SIZEOF];
    strcpy(s,args.at(1).c_str());
    strcat(s," ");
    strcat(s,args.at(2).c_str());
    if(turn%2==0){
        long n = write(sSocket, s, SIZEOF);
        if (n == -1) {
            cout << "Error witing point" << endl;
        }
    }
    else{
        long n = write(fSocket, s, SIZEOF);
        if (n == -1) {
            cout << "Error witing point" << endl;
        }
    }
    turn++;
    return "s";
}

