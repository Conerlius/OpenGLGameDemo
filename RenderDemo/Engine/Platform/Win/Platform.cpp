#include "Platform/Win/Platform.h"
#include <iostream>
#include <filesystem>

std::string Platform::GetRuntimePath()
    {
    // 获取当前可执行文件的路径
    std::string exePath = std::filesystem::current_path().string();

    std::cout << "当前可执行文件路径为：" << exePath << std::endl;

    // 获取当前工作目录的路径
    std::string workDir = std::filesystem::current_path().parent_path().string();
    return workDir;
    }
