cmake_minimum_required(VERSION 3.8)
project(server)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES src/main.cpp src/Server.cpp include/Server.h include/Command.h src/PrintCommand.cpp PrintCommand.h src/CommandsManagers.cpp include/CommandsManagers.h src/threadFor2Clients.cpp include/threadFor2Clients.h try.cpp src/Thread.cpp include/Thread.h src/Task.cpp include/Task.h src/WorkQueue.cpp include/WorkQueue.h src/PoolWorkerThread.cpp include/PoolWorkerThread.h src/ThreadPool.cpp include/ThreadPool.h)
add_executable(server ${SOURCE_FILES})