#include "stdafx.h"
#include <iostream>

#include "PrintHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

PrintHandler::PrintHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
    performOn(Flyweight::cache_);
}

ERROR_CODE PrintHandler::performOn(std::vector<CTable*>& inCache)
{
    if(flag::printOn)
    {
        std::cout << wholeCommand_[idxOf::command] << POST_PRINT;
    }
    std::string receivedId(wholeCommand_[idxOf::amount]);
    int idxOrAmount = std::stoi(receivedId);

    if(isProperIdx(idxOrAmount, inCache))
    {
        CTable* retTable = inCache.at(idxOrAmount);
        if(retTable != nullptr)
        {
            std::cout << retTable->toString();
        }
        else
        {
            if(flag::printOn)
            {
                std::cout << undefinedObject;
            }
        }
        retTable = nullptr;
    }
    else
    {
        if(flag::printOn)
        {
            std::cout << indexOutOfBound;
        }
    }
    return ERROR_CODE::NOT_HANDLED_ERROR_REPORTING;
}

PrintHandler::~PrintHandler()
{}
