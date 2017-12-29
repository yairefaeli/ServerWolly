//
// Created by or on 28/12/17.
//

#ifndef SERVER_POOLWORKERTHREAD_H
#define SERVER_POOLWORKERTHREAD_H
#include <stdio.h>
#include <queue>
#include <unistd.h>
#include <pthread.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include "Thread.h"
#include "WorkQueue.h"
#include "Task.h"


// Thanks to the reusable thread class implementing threads is
// simple and free of pthread api usage.
class PoolWorkerThread : public Thread
{
public:
    PoolWorkerThread(WorkQueue& _work_queue) : work_queue(_work_queue) {}
protected:
    virtual void run()
    {
        while (Task* task = work_queue.nextTask())
            task->run();
    }
private:
    WorkQueue& work_queue;
};
#endif //SERVER_POOLWORKERTHREAD_H