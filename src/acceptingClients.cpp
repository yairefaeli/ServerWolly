//
// Created by logia on 03/01/18.
//

#include "../include/acceptingClients.h"
#include "../include/Server.h"

acceptingClients :: acceptingClients(Server server,ThreadPool* tp){
    this->server=server;
    this->tp=tp;

}

void acceptingClients :: run(){
    server.start();
}