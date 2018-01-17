//
// Created by or on 17/01/18.
//

#ifndef SERVER_LISTOFSOCKETS_H
#define SERVER_LISTOFSOCKETS_H
#include <iostream>
class ListOfSockets{
public:
    static ListOfSockets *getInstance();
private:
    ListOfSockets(){}
    static ListOfSockets *instance;

};
#endif //SERVER_LISTOFSOCKETS_H
