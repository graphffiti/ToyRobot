#include <iostream>
#include "PlaceCommand.hpp"



PlaceCommand::PlaceCommand(Robot& pbot, int x, int y, std::string d):
mbot(pbot),abscissa(x), ordinate(y), direction(d)
{

}

void PlaceCommand::execute()
{
    //std::cout << "Place to (" << abscissa << ", " << ordinate << ")\n";

    mbot.place(abscissa,ordinate, direction);
}