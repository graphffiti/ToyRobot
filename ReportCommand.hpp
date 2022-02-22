#ifndef _REPORT_COMMAND_
#define _REPORT_COMMAND_

#include "ICommand.hpp"
#include "Robot.hpp"

class ReportCommand : public ICommand
{
public:
    ReportCommand(Robot& pbot);
    void execute() override;
private:
    Robot& mbot;
};

#endif //_REPORT_COMMAND_