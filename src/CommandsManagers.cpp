//
// Created by yair on 26/12/17.
//

#include "../include/CommandsManagers.h"
#include "../include/startCommand.h"
#include "../include/CloseCommand.h"
#include "../include/JoinCommand.h"
#include "../include/ListCommand.h"
#include "../include/playCommand.h"

// declariton on help function


// application of the class CommandManager
CommandsManager::CommandsManager(){

    this->tp = 0;
    this->threadMap = 0;
    this->clientSocket = 0;
}

CommandsManager::CommandsManager(map<string, Task *> *threadMap, int theClientSocket, ThreadPool *tp) {
    this->threadMap = threadMap;
    this->tp = tp;
    this->clientSocket = theClientSocket;
    initializeMap();
}

void CommandsManager::executeCommand(string command, vector<string> args) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(args);

}

CommandsManager::~CommandsManager() {
    //for(map<string, Command *>:: iterator it = commandsMap.begin(); it != commandsMap.; ++it){
    //      delete it->second;
    //}
}

void CommandsManager::addClientSocket(int clientSocket) {
    this->clientSocket = clientSocket;
}

void CommandsManager::addThreadMap(map<string, Task *> *threadMap) {
    this->threadMap = threadMap;
}

void CommandsManager::addPlayCommand(int fsocket,int ssocket) {

    commandsMap["play"]=(Command*)new playCommand(fsocket,ssocket);
}

void CommandsManager::addThreadPool(ThreadPool *tp) {
    this->tp = tp;
}

void CommandsManager :: initializeMap() {
    map<string, Command *> commandsMap;
    commandsMap["start"] = (Command *) new startCommand(this->threadMap, this->clientSocket, this->tp);
    commandsMap["close"] = (Command *) new CloseCommand(this->threadMap, this->clientSocket, this->tp);
    commandsMap["join"] = (Command *) new joinCommand(this->threadMap, this->clientSocket);
    commandsMap["list_games"] = (Command *) new ListCommand(this->threadMap, this->clientSocket);
    this->commandsMap = commandsMap;
}