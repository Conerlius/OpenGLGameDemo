#pragma once
#include "Common/MEngine.h"

NS_BEGIN

    class GameWindow
    {
    public:
        bool Start();
        void Destroy();
        void Loop();
    private:
        class RenderWindow* render_window_ = nullptr;
        class LogicWindow* logic_window_ = nullptr;
    };
NS_END
