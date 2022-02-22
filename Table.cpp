#include <algorithm>
#include "Table.hpp"

Table &Table::getInstance()
{
    static Table *singleton = new Table();
    singleton->setMaxX(5);
    singleton->setMaxY(5);
    return *singleton;
}

void Table::setMaxX(int x)
{
    x_max = x;
}

void Table::setMaxY(int y)
{
    y_max = y;
}

bool Table::isValidX(int x)
{
    return x>=0 && x<=x_max;
}


bool Table::isValidY(int y)
{
    return  y >=0 &&  y<=y_max;
}