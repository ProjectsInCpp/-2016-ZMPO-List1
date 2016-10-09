#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class GetSizeHandler final : public IHandler
{
public:
    GetSizeHandler(std::vector<std::string>& inCommand);
    virtual ~GetSizeHandler();
    ERROR_CODE performOn(std::vector<CTable*>& inFlyweightCache) override;
};
