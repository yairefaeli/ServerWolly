//
// Created by logia on 28/12/17.
//

#include "../include/threadFor2Clients.h"
#include <pthread.h>
#include <cstdlib
#include <unistd.h>
#include <map>
#include <cstring>

using namespace std;

threadFor2Clients::threadFor2Clients(int firstClientSocket,int turn,map<string,Command *> cmdMap){
    int n = write(firstClientSocket, &turn, sizeof(int));
    this->firstClientSocket=firstClientSocket;
    this->turn=turn;
    this->cmdMap=cmdMap;
}

virtual ~Task() {}
 void threadFor2Clients::run(){

     if (turn % 2 == 1) {
         handleClient(firstClientSocket, secondClientSocket);
     } else {
         handleClient(secondClientSocket, firstClientSocket);
     }
     turn++;

};
virtual void showTask(){

}


void threadFor2Clients::join(int secondClientSocket){
    this->secondClientSocket=secondClientSocket;
}


void threadFor2Clients::handleClient(int currentClientSocket,int otherClientSocket) {
    //the value of X and Y
    std::vector<string> cmd;
    string str;
    int thePointY;

    //start the reading and writing
    // Read new string command from the player that this is his turn
    int n = read(currentClientSocket, &str, sizeof(str));
    char delim=' ';
    char* toDelim=&delim;
    vector<string> command;
    command.push_back(strtok(str,toDelim));
    command.push_back(strtok(NULL,toDelim));
    cout << command.at(0)<<" "<<command.at(1);


    if (n == -1) {
        cout << "Error reading point" << endl;
        return;
    }

    Command *exe = cmdMap.at(*cmd.at(0));
   string result= exe->execute(cmd);





    // Read new y value from the player that this his turn
    n = read(currentClientSocket, &thePointY, sizeof(thePointY));
    if (n == -1) {
        cout << "Error reading point" << endl;
        return;
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
