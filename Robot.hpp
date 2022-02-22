#ifndef _ROBOT_
#define _ROBOT_
#include <memory>
#include "ICommand.hpp"
#include "Direction.hpp"
#include "Table.hpp"

class Robot
{
public:
    Robot();
    Robot(Robot &&r);
    ~Robot();

    int getID() const;

    void place(int x, int y, std::string d);
    void move();
    void turnLeft();
    void turnRight();
    void report();
    IPlottable *getPlane() const
    {
        return plane;
    }

    void setPlane(IPlottable &pl)
    {
        plane = &pl;
    }

    std::pair<int, int> getCoordinate();

private:
    Direction currentDir;
    std::pair<int, int> coordinate;

    void incrementX()
    {
        //std::cout << "INCEREMET\n";
        if (plane->isValidX(coordinate.first + 1))
            ++coordinate.first;
    }

    void decrementX()
    {
        if (plane->isValidX(coordinate.first - 1))
            --coordinate.first;
    }

    void incrementY()
    {
        if (plane->isValidY(coordinate.second + 1))
            ++coordinate.second;
    }

    void decrementY()
    {
        if (plane->isValidY(coordinate.second - 1))
            --coordinate.second;
    }

    static int robotCount;
    int id;

    IPlottable *plane;
};

/*
struct RobotCmp
{
    bool operator()(const Robot& lhs, const Robot& rhs) const
    {
        return lhs.getID() < rhs.getID();
    }
};

struct RobotID
{

    int id;
};

bool operator<(const Robot& lhs, const RobotID& rhs);
bool operator<(const RobotID& lhs, const Robot& rhs);
bool operator<(const Robot& lhs, const Robot& rhs);
*/
#endif //_ROBOT_