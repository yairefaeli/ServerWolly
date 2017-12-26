//
// Created by or on 26/12/17.
//
#include <vector>
#include <string>
#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H
using namespace std;
class Command {
public:
    virtual void execute(vector<string> args) = 0;
    virtual ~Command(){}

};
#endif //SERVER_COMMAND_H
