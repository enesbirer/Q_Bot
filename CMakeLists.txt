cmake_minimum_required(VERSION 3.10)

project(RLGameBot)

set(CMAKE_CXX_STANDARD 17)

add_executable(RLGameBot
    main.cpp
    GridWorld.cpp
    Agent.cpp
    QTable.cpp
)