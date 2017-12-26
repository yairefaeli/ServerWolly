cmake_minimum_required(VERSION 3.8)
project(server)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES src/main.cpp src/Server.cpp include/Server.h include/Command.h src/PrintCommand.cpp PrintCommand.h src/CommandsManagers.cpp include/CommandsManagers.h)
add_executable(server ${SOURCE_FILES})