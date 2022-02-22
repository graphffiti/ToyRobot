
#include <regex>

#include "CommandFactory.hpp"
#include "PlaceCommand.hpp"
#include "MoveCommand.hpp"
#include "LeftCommand.hpp"
#include "RightCommand.hpp"
#include "ReportCommand.hpp"

std::unique_ptr<ICommand> CommandFactory::createCommand(std::map<int, Robot> &bots, std::string cmd)
{

    std::string direction{"NORTH|EAST|SOUTH|WEST"};

    size_t s = bots.size();
    if (s < 1)
    {
        return nullptr;
    }

    int id = 0;

    if (cmd == "MOVE" && s == 1)
    {
        id = bots.begin()->second.getID();

        
        auto itr = bots.find(id);
        return itr != bots.end() && itr->second.getPlane() != nullptr ? std::make_unique<MoveCommand>(itr->second) : nullptr;
    }
    else if (std::regex_match(cmd, std::regex{"MOVE(\\s+)(\\+|-)?(\\d+)"}) && s > 1)
    {

        std::string s = cmd;
        std::regex token{"[\\s]+"};
        std::sregex_token_iterator it(s.begin(), s.end(), token, -1);
        std::sregex_token_iterator reg_end;

        int argc = 0;
        for (; it != reg_end; ++it)
        {
            if (argc == 1)
            {
                id = std::stoi(it->str());
            }
            ++argc;
        }

        auto itr = bots.find(id);
        return itr != bots.end() && itr->second.getPlane() != nullptr ? std::make_unique<MoveCommand>(itr->second) : nullptr;
    }
    else if (cmd == "LEFT" && s == 1)
    {
        id = bots.begin()->second.getID();
        auto itr = bots.find(id);
        return itr != bots.end() && itr->second.getPlane() != nullptr ? std::make_unique<LeftCommand>(itr->second) : nullptr;
    }
    else if (std::regex_match(cmd, std::regex{"LEFT(\\s+)(\\+|-)?(\\d+)"}) && s > 1)
    {

        std::string s = cmd;
        std::regex token{"[\\s]+"};
        std::sregex_token_iterator it(s.begin(), s.end(), token, -1);
        std::sregex_token_iterator reg_end;

        int argc = 0;
        for (; it != reg_end; ++it)
        {
            if (argc == 1)
            {
                id = std::stoi(it->str());
            }
            ++argc;
        }

        auto itr = bots.find(id);
        return itr != bots.end() && itr->second.getPlane() != nullptr ? std::make_unique<LeftCommand>(itr->second) : nullptr;
    }
    else if (cmd == "RIGHT" && s == 1)
    {
        id = bots.begin()->second.getID();
        auto itr = bots.find(id);
        return itr != bots.end() && itr->second.getPlane() != nullptr ? std::make_unique<RightCommand>(itr->second) : nullptr;
    }
    else if (std::regex_match(cmd, std::regex{"RIGHT(\\s+)(\\+|-)?(\\d+)"}) && s > 1)
    {

        std::string s = cmd;
        std::regex token{"[\\s]+"};
        std::sregex_token_iterator it(s.begin(), s.end(), token, -1);
        std::sregex_token_iterator reg_end;

        int argc = 0;
        for (; it != reg_end; ++it)
        {
            if (argc == 1)
            {
                id = std::stoi(it->str());
            }
            ++argc;
        }

        auto itr = bots.find(id);
        return itr != bots.end() && itr->second.getPlane() != nullptr ? std::make_unique<RightCommand>(itr->second) : nullptr;
    }
    else if (cmd == "REPORT" && s == 1)
    {
        id = bots.begin()->second.getID();
        auto itr = bots.find(id);
        return itr != bots.end() && itr->second.getPlane() != nullptr ? std::make_unique<ReportCommand>(itr->second) : nullptr;
    }
    else if (std::regex_match(cmd, std::regex{"REPORT(\\s+)(\\+|-)?(\\d+)"}) && s > 1)
    {

        std::string s = cmd;
        std::regex token{"[\\s]+"};
        std::sregex_token_iterator it(s.begin(), s.end(), token, -1);
        std::sregex_token_iterator reg_end;

        int argc = 0;
        for (; it != reg_end; ++it)
        {
            if (argc == 1)
            {
                id = std::stoi(it->str());
            }
            ++argc;
        }

        auto itr = bots.find(id);
        return itr != bots.end() && itr->second.getPlane() != nullptr ? std::make_unique<ReportCommand>(itr->second) : nullptr;
    }
    else if (std::regex_match(cmd, std::regex{"((PLACE (\\+|-)?\\d+, ?(\\+|-)?\\d+), ?(" + direction + "))"}))
    {
        std::string s = cmd;
        std::regex token{"[\\s,]+"};
        std::sregex_token_iterator it(s.begin(), s.end(), token, -1);
        std::sregex_token_iterator reg_end;

        int x = 0;
        int y = 0;
        std::string d{"NORTH"};

        int argc = 0;
        for (; it != reg_end; ++it)
        {
            if (argc == 1)
            {
                x = std::stoi(it->str());
            }
            else if (argc == 2)
            {
                y = std::stoi(it->str());
            }
            else if (argc == 3)
            {
                d = it->str();
            }

            ++argc;
        }

        std::map<int, Robot>::iterator availableBot = std::find_if(bots.begin(), bots.end(), [&](const std::pair<const int, Robot> &r)
                                                                   { return r.second.getPlane() == nullptr; });

        if (availableBot == bots.end())
        {
            return nullptr;
        }

        if (!(Table::getInstance().isValidX(x) && Table::getInstance().isValidY(y)))
        {
            return nullptr;
        }
        availableBot->second.setPlane(Table::getInstance());
        return std::make_unique<PlaceCommand>(availableBot->second, x, y, d);
    }
    else
    {
        return nullptr;
    }
}