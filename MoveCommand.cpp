#include <iostream>
#include "MoveCommand.hpp"


MoveCommand::MoveCommand(Robot& pbot):
mbot(pbot)
{

}

void MoveCommand::execute()
{
    mbot.move();
   // std::cout << "MOVE 1 UNIT TO THE CURRENT DIRECTION\n";
}