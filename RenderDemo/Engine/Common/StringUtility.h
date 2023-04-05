#pragma once
#include <string>
#include <locale>
#include <iostream>

static const char* StringToUTF8(std::string str)
{
    // 将std::string转换为std::wstring
    // std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    // std::wstring wstr = converter.from_bytes(str);
    //
    // // 将std::wstring转换为UTF-8编码的char数组
    // std::string_view sv(reinterpret_cast<const char*>(wstr.data()), wstr.size() * sizeof(wchar_t));
    // return sv.data();
    std::cout << str << std::endl;
    std::string_view sv(str);
    std::cout << sv.data() << std::endl;
    return sv.data();
}
