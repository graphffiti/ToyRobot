#ifndef _COMMAND_FACTORY_
#define _COMMAND_FACTORY_

#include <memory>
#include <iostream>
#include <map>
#include "ICommand.hpp"
#include "Robot.hpp"

class CommandFactory
{
public:
    std::unique_ptr<ICommand> createCommand(std::map<int, Robot>&  bots, std::string cmd);
};

#endif //_COMMAND_FACTORY_