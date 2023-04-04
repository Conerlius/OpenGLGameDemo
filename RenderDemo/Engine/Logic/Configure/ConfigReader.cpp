#include "Logic/Configure/ConfigReader.h"
#include <fstream>
#include "Common/MEngine.h"
#include "Logic/Configure/GConfig.h"

NS_BEGIN
void ConfigReader::Parse(const std::string absolut_config_path, std::shared_ptr<Config> config)
{
    LOG("ConfigReader", LogLevel::Info, absolut_config_path);
    std::ifstream infile(absolut_config_path);
    std::string section;
    std::string line;
    auto  conf = config.get();
    while(std::getline(infile, line))
    {
        if (!line.empty() && line.front() != '#') // 忽略注释和空行
        {
            section = line.substr(1, line.size() - 2); // 移除方括号
        }
        else// 键值对
        {
            auto pos = line.find('=');
            if (pos != std::string::npos) // 确保有等号
            {
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);
                (*conf)[section + "." + key] = value; // 保存键值对，使用区域和键进行唯一性标识
            }
        }
    }
}

NS_END 