//
// Created by or on 26/12/17.
//

#include "../include/CommandsManagers.h"
#include "../include/startCommand.h"
#include <sys/socket.h>
#include <unistd.h>

CommandsManager::CommandsManager(map<string,Task*>* threadMap, int* firstClientSocket) {
    this->threadMap=threadMap;
 //   commandsMap["start"] = new startCommand(threadMap,firstClientSocket);
}



void CommandsManager::executeCommand(string command, vector<string> args){
    Command *commandObj = commandsMap[command];
    commandObj->execute(args);
}





CommandsManager::~CommandsManager() {

//    for(map<string, Command *>:: iterator it = commandsMap.begin(); it != commandsMap.; ++it){
  //      delete it->second;
   // }
}