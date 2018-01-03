//
// Created by logia on 07/12/17.
//

#include "../include/Server.h"
#include "../include/Task.h"
#include "../include/ThreadPool.h"
#include "../include/threadFor2Clients.h"
#include "../include/WaitingRoom.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define MAX_CONNECTED_CLIENTS 10
Server::Server(int port): port(port), serverSocket(0) {
    cout << "Server" << endl;
}
void Server::start() {

    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }

    int enable=1;
    if(setsockopt(serverSocket,SOL_SOCKET,SO_REUSEADDR,&enable,sizeof(int))<0){
        perror("failed");
    }


    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }

    // threadFor2Clients listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);

    // Define the client socket's structures
    struct sockaddr_in firstClientAddress, secondClientAddress;
    socklen_t firstClientAddressLen, secondClientAddressLen;
    //Define the turns
    int turn = 0;
    ThreadPool tp = ThreadPool(50);
    map<string, Task *> threadMap;
    while (true) {

        cout << "Waiting for client connections..." << endl;

        // Accept a new client connection
        int firstClientSocket = accept(serverSocket, (struct sockaddr *) &firstClientAddress, &firstClientAddressLen);
        cout << "Client connected" << endl;
        if (firstClientSocket == -1)
            throw "Error on accept";

        Task *t ;
        t=new WaitingRoom(&threadMap, firstClientSocket, &tp);
        tp.addTask(t);


        //reading the command of the player

  }
}


void Server::stop() {
    close(serverSocket);
}