#pragma once
#include "Common/MEngine.h"

NS_BEGIN

    class GameApplication
    {
    public:
        bool start();
        void destroy();
        void loop() const;
private:
    void pre_init();
public:
    static std::string RuntimePath;
    
    private:
        class RenderWindow* render_window_ = nullptr;
        class LogicWindow* logic_window_ = nullptr;


    };
NS_END
