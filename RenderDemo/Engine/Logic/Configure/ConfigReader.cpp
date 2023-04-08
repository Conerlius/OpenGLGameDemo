#include "Logic/Configure/ConfigReader.h"

#include <codecvt>
#include <fstream>
#include <regex>
#include <filesystem>
#include "Common/MEngine.h"
#include "Logic/Configure/GConfig.h"

NS_BEGIN
void ConfigReader::Parse(const std::string absolut_config_path, std::shared_ptr<Config> config)
{
    LOG("ConfigReader", LogLevel::Info, absolut_config_path);
    std::ifstream infile(absolut_config_path);
    std::string current_section;
    std::string line;
    // infile.imbue(std::locale(std::locale::classic(), new std::codecvt_utf8<wchar_t>));
    while(std::getline(infile, line))
    {
        // 删除行首和行尾的空格和制表符
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);
        
        // 忽略注释和空行
        if (line.empty() || line[0] == ';') {
            continue;
        }
        
        // 匹配节
        std::smatch section_match;
        if (std::regex_match(line, section_match, std::regex(R"(\[([^\]]+)\])"))) {
            current_section = section_match.str(1);
            continue;
        }
        
        // 匹配键值对
        std::smatch key_value_match;
        if (std::regex_match(line, key_value_match, std::regex(R"(([^\=]+)\=(.*))"))) {
            std::string key = key_value_match.str(1);
            std::string value = key_value_match.str(2);
            // std::cout << value << std::endl;
            config->set(current_section +"." + key, value);
        }
    }
}

NS_END 