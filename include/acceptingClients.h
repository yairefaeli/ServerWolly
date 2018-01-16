//
// Created by logia on 03/01/18.
//

#ifndef SERVER_ACCEPTINGCLIENTS_H
#define SERVER_ACCEPTINGCLIENTS_H

#include "Task.h"
#include "Server.h"

class acceptingClients : public Task{
public:
    acceptingClients(Server server,ThreadPool* tp);
    ~acceptingClients(){};
    void join(int secondClientSocket){};
    void run();
    void showTask(){};


private:
    Server server=0;
    ThreadPool* tp=0;
};
#endif //SERVER_ACCEPTINGCLIENTS_H
