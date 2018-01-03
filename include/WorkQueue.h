//
// Created by or on 28/12/17.
//

#ifndef SERVER_WORKQUEUE_H
#define SERVER_WORKQUEUE_H
#include <stdio.h>
#include <queue>
#include <unistd.h>
#include <pthread.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include "Task.h"


// Wrapper around std::queue with some mutex protection
class WorkQueue
{
public:
    WorkQueue() {
        pthread_mutex_init(&qmtx,0);

        // wcond is a condition variable that's signaled
        // when new work arrives
        pthread_cond_init(&wcond, 0);
    }

    ~WorkQueue() {
        // Cleanup pthreads
        pthread_mutex_destroy(&qmtx);
        pthread_cond_destroy(&wcond);
    }

    // Retrieves the next task from the queue
    Task *nextTask() {
        // The return value
        Task *nt = 0;

        // Lock the queue mutex
        pthread_mutex_lock(&qmtx);

        while (tasks.empty())
            pthread_cond_wait(&wcond, &qmtx);

        nt = tasks.front();
        tasks.pop();

        // Unlock the mutex and return
        pthread_mutex_unlock(&qmtx);
        return nt;
    }
    // Add a task
    void addTask(Task *nt) {
        // Lock the queue
        pthread_mutex_lock(&qmtx);
        // Add the task
        tasks.push(nt);
        // signal there's new work
        pthread_cond_signal(&wcond);
        // Unlock the mutex
        pthread_mutex_unlock(&qmtx);
    }

private:
    std::queue<Task*> tasks;
    pthread_mutex_t qmtx;
    pthread_cond_t wcond;
};



#endif //SERVER_WORKQUEUE_H
