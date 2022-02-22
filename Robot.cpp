#include <iostream>
#include "Robot.hpp"

int Robot::robotCount = 0;

Robot::Robot() : coordinate{0, 0}, id(++robotCount), plane(nullptr)
{
}

Robot::Robot(Robot &&r) : id(std::move(r.id))
{
    r.id = 0;
}

Robot::~Robot()
{
}

int Robot::getID() const
{
    return id;
}

void Robot::report()
{
    std::cout << id <<"|Output: " << coordinate.first << "," << coordinate.second << "," << currentDir.str() << std::endl;
}

std::pair<int, int> Robot::getCoordinate()
{
    return coordinate;
}

void Robot::place(int x, int y, std::string d)
{
    if (!(Table::getInstance().isValidX(x) && Table::getInstance().isValidY(y)))
    {
        plane = nullptr;
        return;
    }

    coordinate.first = x;
    coordinate.second = y;
    currentDir.setState(d);
    std::cout << "places Robot with ID " << id << std::endl;
}

void Robot::move()
{
    if (currentDir.getState() == Direction::State::NORTH)
    {
        incrementY();

        // std::cout << "NEW (" << coordinate.first << ", " << coordinate.second << ")" << std::endl;
    }
    else if (currentDir.getState() == Direction::State::EAST)
    {
        incrementX();

        // std::cout << "NEW (" << coordinate.first << ", " << coordinate.second << ")" << std::endl;
    }
    else if (currentDir.getState() == Direction::State::SOUTH)
    {
        decrementY();

        // std::cout << "NEW (" << coordinate.first << ", " << coordinate.second << ")" << std::endl;
    }
    else if (currentDir.getState() == Direction::State::WEST)
    {
        decrementX();

        // std::cout << "NEW (" << coordinate.first << ", " << coordinate.second << ")" << std::endl;
    }
}

void Robot::turnLeft()
{
    // std::cout << "TURN LEFT\n";
    currentDir.processTrigger(Direction::Trigger::LEFT);
}

void Robot::turnRight()
{
    // std::cout << "TURN RIGHT\n";
    currentDir.processTrigger(Direction::Trigger::RIGHT);
}