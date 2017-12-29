//
// Created by or on 29/12/17.
//

#include "../include/ListCommand.h"
#include <map>





string ListCommand::execute(vector<string> args){

    for (map<string,Task*>::iterator auto it=threadMap->begin(); it != threadMap->end(); it++) {
        
        cout <<it <<endl;
    }
}