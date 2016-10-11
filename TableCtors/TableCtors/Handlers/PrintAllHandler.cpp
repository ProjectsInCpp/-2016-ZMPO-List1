#include "stdafx.h"
#include <iostream>

#include "PrintAllHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

PrintAllHandler::PrintAllHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

ERROR_CODE PrintAllHandler::performOn(std::vector<CTable*>& inCache)
{
    ERROR_CODE resultCode = ERROR_CODE::SEEMS_LEGIT;
    if(flag::printOn)
    {
        std::cout << wholeCommand_[idxOf::command] << POST_PRINT;
    }

    if(isProperAmmountOfArgs(wholeCommand_, PROPER_AMOUNT_OF_ARGS))
    {
        if(isProperTypeOfArgs(wholeCommand_, PROPER_TYPES_OF_ARGS))
        {
            performOnProperArgs(inCache, resultCode);
        }
        else
        {
            resultCode = ERROR_CODE::ERROR_ARGS_PARSING;
            if(flag::printOn)
            {
                std::cout << toString(resultCode);
            }
        }
    }
    else
    {
        resultCode = ERROR_CODE::WRONG_AMOUNT_OF_ARGS;
        if(flag::printOn)
        {
            std::cout << toString(resultCode);
        }
    }

    return resultCode;
}

void PrintAllHandler::performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
    if(inCache.size() == 0)
    {
        inResultCode = ERROR_CODE::UNDEFINED_OBJECT;
        if(flag::printOn)
        {
            std::cout << toString(inResultCode);
        }
    }
    else
    {
        for(int i = 0; i < inCache.size(); i++)
        {
            std::cout << i << SEPARATOR;

            if(inCache[i] == nullptr)
            {
                std::cout << undefinedObject;
            }
            else
            {
                std::cout << inCache[i]->toString();
            }

            std::cout << POST_PRINT;
        }
    }
}
PrintAllHandler::~PrintAllHandler()
{}
