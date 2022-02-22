#include "Direction.hpp"

Direction::Direction()
{

    currState = State::NORTH;

    stateChart[State::NORTH] = {{Trigger::LEFT, State::WEST},
                                    {Trigger::RIGHT, State::EAST}};

    stateChart[State::EAST] = {{Direction::Trigger::LEFT, State::NORTH},
                                   {Direction::Trigger::RIGHT, State::SOUTH}};

    stateChart[State::SOUTH] = {{Direction::Trigger::LEFT, State::EAST},
                                    {Trigger::RIGHT, State::WEST}};

    stateChart[State::WEST] = {{Trigger::LEFT, State::SOUTH},
                                   {Trigger::RIGHT, State::NORTH}};

    stringMap[State::NORTH] = "NORTH";
    stringMap[State::EAST] = "EAST";
    stringMap[State::SOUTH] = "SOUTH";
    stringMap[State::WEST] = "WEST";

                                   
}



void Direction::processTrigger (Trigger trigger)
{
    currState=stateChart[currState][trigger];
}