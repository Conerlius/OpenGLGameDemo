#pragma once
#include <string>
#include "Platform/interfaces/IPlatform.h"

class Platform: public IPlatform
{
public:
    std::string GetRuntimePath() override;
};