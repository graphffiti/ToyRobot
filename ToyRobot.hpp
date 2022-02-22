#ifndef _TOY_ROBOT_
#define _TOY_ROBOT_

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <regex>

class ToyRobot
{
public:
    ToyRobot(std::string file);
    ToyRobot();
    ~ToyRobot();
    void run();
    void setFile(std::string file);

private:
    std::string commandScript;
    std::ifstream ifs;
    int maxRobot;

    std::vector<std::string> botCmd;
    void getCmdLines(std::istream& is);
};

#endif //_TOY_ROBOT_