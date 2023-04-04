#include "GameApplication.h"
#include "Render/RenderWindow.h"
#include "Logic/LogicWindow.h"
#include <chrono>
#include <thread>

NS_BEGIN

std::string GameApplication::RuntimePath;
    bool GameApplication::start()
    {
        pre_init();
        if (logic_window_ == nullptr)
        {
            logic_window_ = new LogicWindow();
        }
        logic_window_->Start();
    
        if (render_window_ == nullptr)
        {
            render_window_ = new RenderWindow();
        }
        if (!render_window_->start())
        {
            return false;
        }
        return true;
    }

    void GameApplication::destroy()
    {
        if (render_window_)
        {
            render_window_->destroy();
            delete render_window_;
            render_window_ = nullptr;
        }
        if (logic_window_)
        {
            logic_window_->Destroy();
            delete logic_window_;
            logic_window_ = nullptr;
        }
    }

    void GameApplication::loop() const
    {
        const int TICK_RATE = 60; // Number of ticks per second
        const std::chrono::nanoseconds TICK_DURATION = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::seconds(1)) / TICK_RATE;
        std::chrono::steady_clock::time_point begin_time = std::chrono::steady_clock::now();
        std::chrono::steady_clock::time_point lastTickTime = begin_time;
        while (true)
        {
            std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
            std::chrono::nanoseconds elapsed = currentTime - lastTickTime;
            float detla_time = 0.0;
            if (elapsed < TICK_DURATION)
            {
                std::this_thread::sleep_for(TICK_DURATION-elapsed);
                detla_time = std::chrono::duration_cast<std::chrono::duration<float>>(TICK_DURATION).count();
            }
            else
            {
                detla_time = std::chrono::duration_cast<std::chrono::duration<float>>(elapsed).count();
            }
            if (logic_window_)
            {
                logic_window_->update(detla_time);
            }
            if (render_window_)
            {
                if (!render_window_->is_close())
                {
                    render_window_->draw();
                }
                else
                {
                    break;
                }
            }
            lastTickTime = std::chrono::steady_clock::now();
        }
    }

void GameApplication::pre_init()
{
    Platform p;
    RuntimePath = p.GetRuntimePath(); 
}

NS_END
