// TableCtors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

#include <boost/optional.hpp>
#include <boost/tokenizer.hpp>

#include "Interface.h"

namespace
{
constexpr char* SEPARATOR = " ";
constexpr int idOfcommand = 0;
constexpr char* createDefLiteral = "createDef";

using tokenizer = boost::tokenizer<boost::char_separator<char>>;

std::vector<std::string> receiveCommandFromUser()
{
    std::cout << "Pass command" << std::endl;
    std::cout << "$ ";

    std::string inChain;
    getline(std::cin, inChain);

    boost::char_separator<char> sep(SEPARATOR);
    tokenizer tokens(inChain, sep);
    std::vector<std::string> retVal(tokens.begin(), tokens.end());

    return std::move(retVal);
}
}

int main()
{
    std::vector<std::string> tokenizedCommand(receiveCommandFromUser());
    std::string receivedCommand = tokenizedCommand[idOfcommand];

    if (receivedCommand == createDefLiteral)
    {
        std::cout << "Stworze tablice";
    }
    else
    {
        std::cout << "Nie znam takiej komendy";
    }

    std::cout << std::endl;
    return 0;
}
