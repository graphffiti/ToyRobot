#include <iostream>
#include "RightCommand.hpp"

RightCommand::RightCommand(Robot& pbot)
: mbot{pbot}
{

}
void RightCommand::execute()
{
   // std::cout << "Turn RIGHT from current direction, do not change coordinate\n";
   mbot.turnRight();
}