//
// Created by or on 29/12/17.
//

#include <sstream>
#include <zconf.h>
#include <cstring>
#include "../include/ListCommand.h"

#define SIZEOF 2000

ListCommand::ListCommand(map<string, Task *> *threadMap,int clientSocket) {
    this->threadMap = threadMap;
    this->clientSocket = clientSocket;
}

string ListCommand::execute(vector<string> args){

    char listOfGames[SIZEOF] = "";
    for (map<string,Task*>::iterator it = this->threadMap->begin(); it != this->threadMap->end(); it++) {
        strcat(listOfGames, it->first.c_str());
        strcat(listOfGames, "\n");
    }
    int n = write(clientSocket,listOfGames,SIZEOF);
    cout << listOfGames << endl;
    return listOfGames;

}