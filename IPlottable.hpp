#ifndef _PLOTTABLE_
#define _PLOTTABLE_

class IPlottable
{
public:
    virtual ~IPlottable() = default;
    virtual bool isValidX(int x) = 0;
    virtual bool isValidY(int y) = 0;
};

#endif //_PLOTTABLE_