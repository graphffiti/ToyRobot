#include <iostream>
#include "ReportCommand.hpp"

ReportCommand::ReportCommand(Robot& pbot)
: mbot{pbot}
{

}
void ReportCommand::execute()
{
   // std::cout << "Turn RIGHT from current direction, do not change coordinate\n";
   mbot.report();
}