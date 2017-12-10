//
// Created by logia on 07/12/17.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H


class Server {
public:
    Server(int port);

    void start();

    void stop();

private:
    int port;
    int serverSocket; // the socket's file descriptor
    void handleClient(int currentClientSocket,int otherClientSocket);
    void initilaizeTurns(int firstClientSocket,int secondClientSocket);

};


#endif //SERVER_SERVER_H
