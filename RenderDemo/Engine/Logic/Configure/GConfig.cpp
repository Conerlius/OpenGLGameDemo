#include "Logic/Configure/GConfig.h"
#include "Logic/Configure/ConfigReader.h"
#include "GameApplication.h"
NS_BEGIN

std::string Config::operator[](std::string key)
{
    return key_values[key];
}

void Config::set(const std::string key,const std::string value)
{
    // LOG("Config", LogLevel::Info, value);
    key_values.insert(std::make_pair(key, value));
}


std::map<std::string, std::shared_ptr<Config>> GConfig::all_configs;

Config* GConfig::get(const std::string config_name)
{
    std::shared_ptr<Config> config = nullptr;
    auto result = all_configs.find(config_name);
    if (result !=all_configs.end())
    {
        LOG("Config", LogLevel::Info, config_name);
        return result->second.get();
    }
    else
    {
        auto runtime_path = GameApplication::RuntimePath;
        LOG("Config", LogLevel::Info, runtime_path);
        config = std::make_shared<Config>();
        all_configs.insert(make_pair(config_name, config));
        ConfigReader::Parse(runtime_path+"/RenderDemo/Engine/Configes/"+config_name+".ini", config);
    }
    return config.get();
}

NS_END