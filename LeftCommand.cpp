#include <iostream>
#include "LeftCommand.hpp"

LeftCommand::LeftCommand(Robot &pbot)
    : mbot(pbot)
{
}
void LeftCommand::execute()
{
    mbot.turnLeft();
    //std::cout << "Turn LEFT from current direction, do not change coordinate\n";
}