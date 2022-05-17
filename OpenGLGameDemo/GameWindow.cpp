#include "GameWindow.h"
#include "RenderWindow.h"
#include "LogicWindow.h" 

NS_BEGIN
    bool GameWindow::Start()
    {
        if (render_window_ == nullptr)
        {
            render_window_ = new RenderWindow();
        }
        if (render_window_->Start())
        {
            return false;
        }
        if (logic_window_ == nullptr)
        {
            logic_window_ = new LogicWindow();
        }
        logic_window_->Start();
        return true;
    }

    void GameWindow::Destroy()
    {
        if (render_window_)
        {
            render_window_->Destroy();
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

    void GameWindow::Loop()
    {
        while (true)
        {
            if (render_window_)
            {
                if (!render_window_->IsClose())
                {
                    render_window_->Draw();
                }
                else
                {
                    break;
                }
            }
            if (logic_window_)
            {
            
            }
        }
    }
NS_END