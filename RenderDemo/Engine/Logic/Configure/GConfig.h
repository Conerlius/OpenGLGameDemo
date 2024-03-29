﻿#pragma once
#include <map>
#include <Common/MEngine.h>

NS_BEGIN
    class Config
    {
    public:
        std::string operator[](std::string key);
        void set(const std::string key,const std::string value);
    private:
        std::map<std::string, std::string> key_values;
    };

    class GConfig
    {
    public:
    static Config* get(const std::string config_name);
private:
        static std::map<std::string, std::shared_ptr<Config>> all_configs;
    };


NS_END