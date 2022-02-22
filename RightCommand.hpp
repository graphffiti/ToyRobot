#ifndef _RIGHT_COMMAND_
#define _RIGHT_COMMAND_

#include "ICommand.hpp"
#include "Robot.hpp"

class RightCommand : public ICommand
{
public:
    RightCommand(Robot& pbot);
    void execute() override;
private:
    Robot& mbot;
};

#endif //_RIGHT_COMMAND_