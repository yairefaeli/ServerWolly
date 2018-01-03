//
// Created by or on 29/12/17.
//

#include <sstream>
#include "../include/ListCommand.h"



ListCommand::ListCommand(map<string, Task *> *threadMap) {
    this->threadMap = threadMap;
}

string ListCommand::execute(vector<string> args){

    this->threadMap;
    string listOfGames = "";
    for (map<string,Task*>::iterator auto it = this->threadMap->begin(); it != this->threadMap->end(); it++) {
        listOfGames += it->first + " ";
    }
    return listOfGames;

}