cmake_minimum_required(VERSION 3.8)
project(server)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -pthread")
set(SOURCE_FILES src/main.cpp src/Server.cpp include/Server.h include/Command.h src/CommandsManagers.cpp include/CommandsManagers.h src/threadFor2Clients.cpp include/threadFor2Clients.h src/Thread.cpp include/Thread.h src/Task.cpp include/Task.h src/WorkQueue.cpp include/WorkQueue.h src/PoolWorkerThread.cpp include/PoolWorkerThread.h src/ThreadPool.cpp include/ThreadPool.h src/ListCommand.cpp include/ListCommand.h src/startCommand.cpp include/startCommand.h include/startCommand.h src/WaitingRoom.cpp include/WaitingRoom.h src/CloseCommand.cpp include/CloseCommand.h src/JoinCommand.cpp include/JoinCommand.h src/playCommand.cpp include/playCommand.h src/acceptingClients.cpp include/acceptingClients.h ListOfSockets.cpp ListOfSockets.h)
add_executable(server ${SOURCE_FILES})
