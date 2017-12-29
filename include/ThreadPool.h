//
// Created by or on 28/12/17.
//

#ifndef SERVER_THREADPOOL_H
#define SERVER_THREADPOOL_H

#include <stdio.h>
#include <queue>
#include <unistd.h>
#include <pthread.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include "PoolWorkerThread.h"
#include "Task.h"

class ThreadPool {
public:
    // Allocate a thread pool and set them to work trying to get tasks
    ThreadPool(int n) {
        printf("Creating a thread pool with %d threads\n", n);
        for (int i=0; i<n; ++i)
        {
            threads.push_back(new PoolWorkerThread(workQueue));
            threads.back()->start();
        }
    }

    // Wait for the threads to finish, then delete them
    ~ThreadPool() {
        finish();
    }

    // Add a task
    void addTask(Task *nt) {
        workQueue.addTask(nt);
    }

    // Asking the threads to finish, waiting for the task
    // queue to be consumed and then returning.
    void finish() {
        for (size_t i=0,e=threads.size(); i<e; ++i)
            workQueue.addTask(NULL);
        for (size_t i=0,e=threads.size(); i<e; ++i)
        {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
    }

private:
    std::vector<PoolWorkerThread*> threads;
    WorkQueue workQueue;
};


#endif //SERVER_THREADPOOL_H
