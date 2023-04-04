#pragma once

class IPlatform
{
public:
    virtual std::string GetRuntimePath() = 0;
    virtual ~IPlatform(){}
};
