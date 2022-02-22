cmake_minimum_required(VERSION 3.0.0)
project(ToyRobot VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
ToyRobot
 main.cpp
 PlaceCommand.cpp
 MoveCommand.cpp
 LeftCommand.cpp
 RightCommand.cpp
 ReportCommand.cpp
 CommandFactory.cpp
 Robot.cpp
 RobotController.cpp
 Direction.cpp
 ToyRobot.cpp
 Table.cpp
 )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
