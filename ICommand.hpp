#ifndef _ICOMMAND_
#define _ICOMMAND_

class ICommand
{
public:
    virtual void execute() = 0;
    virtual ~ICommand() {}
};

#endif //_ICOMMAND_