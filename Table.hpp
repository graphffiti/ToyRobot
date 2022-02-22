#ifndef _TABLE_HPP_
#define _TABLE_HPP_

#include "IPlottable.hpp"

class Table : public IPlottable
{
public:
    static Table &getInstance();

    bool isValidX(int x) override;
    bool isValidY(int y) override;
    void setMaxX(int x);
    void setMaxY(int y);

    // bool isValidCoordinate(int id);
    // void addRobot(std::unique_ptr<Robot> bot);

private:
    Table() = default;
    Table(const Table &) = delete;
    Table &operator=(const Table &) = delete;
    Table(Table &&) = delete;
    Table &operator=(Table &&) = delete;

    int x_max;
    int y_max;
};

#endif //_TABLE_HPP_