//
// Created by or on 26/12/17.
//

#ifndef SERVER_COMMANDSMANAGERS_H
#define SERVER_COMMANDSMANAGERS_H
#include <map>
#include "Command.h"
#include "Task.h"
#include "ThreadPool.h"
#include <pthread.h>

class CommandsManager {
public:
    CommandsManager();

    CommandsManager(map<string, Task *> *threadMap, int theClientSocket, ThreadPool *tp);

    ~CommandsManager();

    void executeCommand(string command, vector<string> args);

    void addPlayCommand(int fsocket,int ssocket);
    void addThreadMap(map<string, Task *> *threadMap);

    void addClientSocket(int clientSocket);

    void addThreadPool(ThreadPool *tp);

    void initializeMap();
private:
    map<string, Command *> commandsMap;
    map<string, Task *> *threadMap;
    int clientSocket;
    ThreadPool *tp;
};




#endif //SERVER_COMMANDSMANAGERS_H
