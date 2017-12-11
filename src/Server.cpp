//
// Created by logia on 07/12/17.
//

#include "../include/Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
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

    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);

    // Define the client socket's structures
    struct sockaddr_in firstClientAddress, secondClientAddress;
    socklen_t firstClientAddressLen, secondClientAddressLen;
    //Define the turns
    int turn = 1;

    while (true) {
        cout << "Waiting for client connections..." << endl;

        // Accept a new client connection
        int firstClientSocket = accept(serverSocket, (struct sockaddr *) &firstClientAddress, &firstClientAddressLen);
        cout << "Client1 connected" << endl;
        int secondClientSocket = accept(serverSocket, (struct sockaddr *) &secondClientAddress,
                                        &secondClientAddressLen);
        cout << "Client2 connected" << endl;
      /*  if (firstClientSocket == -1)
            throw "Error on accept";
        if (secondClientSocket == -1)
            throw "Error on accept";
            */
        if (turn == 1) {
            initilaizeTurns(firstClientSocket, secondClientSocket);
        }
        // Change the turn to the current player
        while (true) {
            if (turn % 2 == 1) {
                handleClient(firstClientSocket, secondClientSocket);
            } else {
                handleClient(secondClientSocket, firstClientSocket);
            }
            turn++;
        }

    }

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