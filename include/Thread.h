//
// Created by or on 28/12/17.
//

#ifndef SERVER_THREAD_H
#define SERVER_THREAD_H
#include <stdio.h>
#include <queue>
#include <unistd.h>
#include <pthread.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>

class Thread
{
public:
    Thread()
    {
        state = EState_None;
        handle = 0;
    }

    virtual ~Thread()
    {
        assert(state != EState_Started || joined);
    }

    void start()
    {
        assert(state == EState_None);
        // in case of thread create error I usually FatalExit...
        if (pthread_create(&handle, NULL, threadProc, this))
            abort();
        state = EState_Started;
    }

    void join()
    {
        // A started thread must be joined exactly once!
        // This requirement could be eliminated with an alternative implementation but it isn't needed.
        assert(state == EState_Started);
        pthread_join(handle, NULL);
        state = EState_Joined;
    }

protected:
    virtual void run() = 0;

private:
    static void* threadProc(void* param)
    {
        Thread* thread = reinterpret_cast<Thread*>(param);
        thread->run();
        return NULL;
    }

private:
    enum EState
    {
        EState_None,
        EState_Started,
        EState_Joined
    };

    EState state;
    bool joined;
    pthread_t handle;
};


#endif //SERVER_THREAD_H
