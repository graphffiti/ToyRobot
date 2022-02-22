#ifndef _MOVE_COMMAND_
#define _MOVE_COMMAND_
#include "ICommand.hpp"
#include "Robot.hpp"

class MoveCommand : public ICommand
{
public:
    MoveCommand(Robot &pbot);
    void execute() override;

private:
    Robot& mbot;
};

#endif //_MOVE_COMMAND_