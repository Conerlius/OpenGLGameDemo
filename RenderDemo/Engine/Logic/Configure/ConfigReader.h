#pragma once
#include "Common/MEngine.h"
#include <string>
#include "Logic/Configure/GConfig.h"

NS_BEGIN
class ConfigReader
{
public:
    static void Parse(const std::string absolut_config_path, std::shared_ptr<Config> config);
};
NS_END