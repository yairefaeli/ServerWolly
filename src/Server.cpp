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
    ThreadPool tp=ThreadPool(50);
    map<string,Task*> threadMap;
    while (true) {

        cout << "Waiting for client connections..." << endl;

        // Accept a new client connection
        int firstClientSocket = accept(serverSocket, (struct sockaddr *) &firstClientAddress, &firstClientAddressLen);
        cout << "Client1 connected" << endl;
        if (firstClientSocket == -1)
            throw "Error on accept";

        Task* t=(Task*)new WaitingRoom(&threadMap,firstClientSocket,tp);
        tp.addTask(t);

        //reading the command of the player


}

void Server::handleRequest(char* str){
    char delim=' ';
    char* toDelim=&delim;
    vector<string> command;
           command.push_back(strtok(str,toDelim));
    command.push_back(strtok(NULL,toDelim));
    cout << command.at(0)<<" "<<command.at(1);
}

void Server::initilaizeTurns(int firstClientSocket,int secondClientSocket){
    int first = 0;
    int second = 1;
    // Write for the first player that he plays first
    int n = write(firstClientSocket, &first, sizeof(int));
    if (n == -1) {
        cout << "Error writing who first" << endl;
        return;
    }
    // Write for the second player that he plays second
    n = write(secondClientSocket, &second, sizeof(int));
    if (n == -1) {
        cout << "Error writing who second" << endl;
        return;
    }
}
void Server::handleClient(int currentClientSocket,int otherClientSocket) {

    //the value of X and Y
    int thePointX;
    int thePointY;

    //start the reading and writing
    // Read new x value from the player that this his turn
    int n = read(currentClientSocket, &thePointX, sizeof(thePointX));
    if (n == -1) {
        cout << "Error reading point" << endl;
        return;
    }
    // Read new y value from the player that this his turn
    n = read(currentClientSocket, &thePointY, sizeof(thePointY));
    if (n == -1) {
        cout << "Error reading point" << endl;
        return;
    }

    //if the game is ends
    if(thePointX == -1 && thePointY== -1){
        this -> stop();
    }

    // Write the x value back to the other player
    n = write(otherClientSocket, &thePointX, sizeof(thePointX));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }
    // Write the y value back to the other player
    n = write(otherClientSocket, &thePointY, sizeof(thePointY));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return;
    }
}

void Server::stop() {
    close(serverSocket);
}