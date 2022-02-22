#ifndef _DIRECTION_
#define _DIRECTION_

#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

class Direction
{
public:
    enum class State
    {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    enum class Trigger
    {
        LEFT,
        RIGHT
    };

    Direction();
    State getState() { return currState; }
    void setState(Direction::State d) { currState = d;}
    void setState(const std::string& d) { 
        std::map<State, std::string>::iterator it = std::find_if(stringMap.begin(), stringMap.end(), [&d](const std::pair<State, std::string>& p){
            return d == p.second;
        });
        
        if(it!=stringMap.end())
            currState=it->first;
        }
    //void setState(std::string d) { currState = d;}

    void processTrigger(Trigger trigger);

    std::string str() 
    {
        return stringMap[currState];
    }
    /*
    friend std::ostream &operator<<(std::ostream &os,  Direction &d)
    {
        os << d.stringMap[d.currState];

        return os;
    }*/

private:
    std::map<State, std::map<Trigger, State>> stateChart;
    std::map<State, std::string> stringMap;

    State currState;
};

#endif //_DIRECTION_