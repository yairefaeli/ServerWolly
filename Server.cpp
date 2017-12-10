//
// Created by logia on 07/12/17.
//

#include "Server.h"
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
        if (firstClientSocket == -1)
            throw "Error on accept";
        if (secondClientSocket == -1)
            throw "Error on accept";

        // Change the turn to the current player
        if (turn % 2 == 1) {
            handleClient(firstClientSocket, secondClientSocket);
        } else {
            handleClient(secondClientSocket, firstClientSocket);
        }
        turn++;
    }
}

void Server::handleClient(int currentClientSocket,int otherClientSocket) {

    //the value of X and Y
    string thePoint;

    //start the reading and writing
    while (true) {

        // Read new point from the player that this his turn
        int n = read(currentClientSocket, &thePoint, sizeof(thePoint));
        if (n == -1) {
            cout << "Error reading point" << endl;
            return;
        }

        // Write the result back to the other player
        n = write(otherClientSocket, &thePoint, sizeof(thePoint));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
    }
}

void Server::stop() {
    close(serverSocket);
}