#include "stdafx.h"
#include <iostream>

#include "CreateHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace logLiterals;
using namespace funs;

CCreateHandler::CCreateHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

ERROR_CODE CCreateHandler::performOn(std::vector<CTable*>& inCache)
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

void CCreateHandler::performOnProperArgs(std::vector<CTable*>& inCache, ERROR_CODE& inResultCode)
{
    std::string receivedId(wholeCommand_[idxOf::idOfCTable]);
    int idxOrAmount = std::stoi(receivedId);
    std::string receivedNewSize(wholeCommand_[idxOf::newSize]);
    int newSize = std::stoi(receivedNewSize);
    std::string initialName(wholeCommand_[idxOf::initialName]);

    if(idxOrAmount < 0)
    {
        inResultCode = ERROR_CODE::INDEX_OUT_OF_BOUNDS;
        if(flag::printOn)
        {
            std::cout << toString(inResultCode);
        }
    }
    else
    {
        if(newSize > 0)
        {
            if(idxOrAmount > inCache.size())
            {
                inCache.resize(idxOrAmount + ONE);
            }
            if(inCache[idxOrAmount] != nullptr)
            {
                delete inCache[idxOrAmount];
            }
            inCache[idxOrAmount] = CTable::buildNewObj(newSize, initialName);
        }
        else
        {
            inResultCode = ERROR_CODE::WRONG_VALUE;
            if(flag::printOn)
            {
                std::cout << toString(inResultCode);
            }
        }
    }
}

CCreateHandler::~CCreateHandler()
{}
