//
// Created by or on 26/12/17.
//

#include "../include/CommandsManagers.h"
#include <sys/socket.h>
#include <unistd.h>

CommandsManager::CommandsManager() {
    commandsMap["start"] = new PrintCommand();
    commandsMap["list_games"] = new PrintCommand();
    commandsMap["join"] = new PrintCommand();
    commandsMap["play"] = new PrintCommand();
    commandsMap["close"] = new PrintCommand();
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