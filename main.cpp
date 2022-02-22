#include <iostream>
#include <map>
#include <string>
#include <memory>
#include "MoveCommand.hpp"
#include "PlaceCommand.hpp"
#include "ICommand.hpp"
#include "CommandFactory.hpp"

#include "ToyRobot.hpp"

#include <regex>
#include <filesystem>
#include <fstream>

int main(int argc, char **argv)
{
    /*
        std::string cmd = "MOVE      98";
        if (std::regex_match(cmd, std::regex{"MOVE +(\\+|-)?(\\d+)?"}))
        {
            std::cout << "HHHHHHHHHHHHHHHHHHHHHHHHHH\n";
        }

    
   std::string line = "123";
    std::regex maxRobotCommand{"(\\d+)"};
   if(std::regex_match(line, maxRobotCommand))
   {
       std::cout << "DAPAT\n" <<std::endl;
   }
*/


    if (argc == 2)
    {
        if (std::regex_match(argv[1], std::regex{"(\\d+)"}))
        {
            std::cout << "NUMMBBBB\n";
        }
       
    }



    ToyRobot toyRobot;



    toyRobot.run();

    return 0;
}