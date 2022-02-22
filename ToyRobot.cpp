#include <set>
#include "ToyRobot.hpp"
#include "Table.hpp"
#include "Robot.hpp"
#include "RobotController.hpp"
#include "CommandFactory.hpp"

ToyRobot::ToyRobot(std::string file)
    : commandScript(file), maxRobot(1)
{
    ifs.open(commandScript);
}

ToyRobot::ToyRobot()
:maxRobot(1)
{

}

void ToyRobot::setFile(std::string file)
{
    commandScript = file;
}

void ToyRobot::getCmdLines(std::istream &is)
{
    std::regex empytLine{"^[\\s]*$", std::regex::egrep};
    std::regex placeCommand{"PLACE.*", std::regex::egrep};
    //std::regex maxRobotCommand{"(\\d+)"};

    std::string line;

    bool isPlaceCommandOccured = false;

    while (std::getline(is, line))
    {
        if (std::regex_match(line, empytLine))
        {
            break;
        }


        if (isPlaceCommandOccured || std::regex_match(line, placeCommand))
        {
            isPlaceCommandOccured = true;
            botCmd.push_back(std::move(line));
        }

        
    }
}

void ToyRobot::run()
{
    std::map<int, Robot> r;

    RobotController botControl;
    CommandFactory cmdFactory;
    Table &table = Table::getInstance();

    getCmdLines(ifs.is_open() ? ifs : std::cin);

    for (int i = 0; i < maxRobot; ++i)
    {
        Robot &&rs = Robot();
        r.insert({rs.getID(), std::move(rs)});
    }

    for (auto cmd : botCmd)
    {
        botControl.addCommand(cmdFactory.createCommand(r, cmd));
    }

    botControl.executeCommands();
}

ToyRobot::~ToyRobot()
{
    if (ifs.is_open())
    {
        ifs.close();
    }
}