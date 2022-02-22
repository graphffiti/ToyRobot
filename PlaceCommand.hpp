#ifndef _PLACE_COMMAND_
#define _PLACE_COMMAND_

#include "ICommand.hpp"
#include "Robot.hpp"

class PlaceCommand : public ICommand
{
public:

    PlaceCommand(Robot& pbot, int x, int y, std::string d);

    void execute() override;
   

private:
    Robot& mbot;
    int abscissa;
    int ordinate;

    std::string direction;
};



#endif //_PLACE_COMMAND_