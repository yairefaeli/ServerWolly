//
// Created by or on 28/12/17.
//

#ifndef SERVER_TASK_H
#define SERVER_TASK_H



// Base task for Tasks
// run() should be overloaded and expensive calculations done there
// showTask() is for debugging and can be deleted if not used
class Task {
public:
    Task() {}
    virtual ~Task() {};
   virtual  void join(int secondClientSocket);
    virtual void run()=0;
    virtual void showTask()=0;
};

#endif //SERVER_TASK_H