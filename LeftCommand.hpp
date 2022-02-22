#ifndef _LEFT_COMMAND_
#define _LEFT_COMMAND_

#include "ICommand.hpp"
#include "Robot.hpp"

class LeftCommand : public ICommand
{
public:
    LeftCommand(Robot& pbot);
    void execute() override;

private:
    Robot& mbot;
};

#endif //_LEFT_COMMAND_