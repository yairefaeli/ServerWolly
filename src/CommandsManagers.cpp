//
// Created by or on 26/12/17.
//

#include "../include/CommandsManagers.h"
CommandsManager::CommandsManager() {
    commandsMap["start"] = new PrintCommand();
    commandsMap["list_games"] = new PrintCommand();
    commandsMap["join"] = new PrintCommand();
    commandsMap["play"] = new PrintCommand();
    commandsMap["close"] = new PrintCommand();
}