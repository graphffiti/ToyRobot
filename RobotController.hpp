#ifndef _ROBOT_CONTROLLER_
#define _ROBOT_CONTROLLER_

#include <vector>
#include <memory>
#include "ICommand.hpp"

class RobotController
{
public:
    
    void addCommand(std::unique_ptr<ICommand> cmd);
    void executeCommands();
private:
    std::vector<std::unique_ptr<ICommand>> robotCommands;
};
#endif //_ROBOT_CONTROLLER_