//
// Created by logia on 02/01/18.
//


#include "playCommand.h"
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>
#include <map>
#include <cstring>
#include <iostream>


playCommand::playCommand(int fSocket, int sSocket) {
    this->fSocket=fSocket;
    this->sSocket=sSocket;
    turn=0;
}

string playCommand::execute(vector<string> args) {
    string s=args.at(1)+" "+args.at(2);
    if(turn%2==0){
        int n = write(sSocket, &s, sizeof(s));
        if (n == -1) {
            cout << "Error witing point" << endl;
        }
    }
    else{
        int n = write(fSocket, &s, sizeof(s));
        if (n == -1) {
            cout << "Error witing point" << endl;
        }
    }
    turn++;
}
