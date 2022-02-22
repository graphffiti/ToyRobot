#include "RobotController.hpp"

void RobotController::addCommand(std::unique_ptr<ICommand> cmd)
{
    if (cmd != nullptr)
    {
        robotCommands.push_back(std::move(cmd));
    }
}

void RobotController::executeCommands()
{
    for (std::vector<std::unique_ptr<ICommand>>::iterator it = robotCommands.begin();
         it != robotCommands.end(); ++it)
    {
        (*it)->execute();
    }
}