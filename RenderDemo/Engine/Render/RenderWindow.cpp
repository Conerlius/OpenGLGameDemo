#include "RenderWindow.h"
#include "Common/Log/EngineLog.h"
#include "Logic/Configure/GConfig.h"

NS_BEGIN
    bool RenderWindow::start()
    {
        auto conf = GConfig::get("GameConfig");
    std::string width = (*conf)["Window.Width"];
    std::string height = (*conf)["Window.Height"];
    std::string title = (*conf)["Window.Title"];
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if ENGINE_MACOS
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);#prama 
#endif
    
    
        window_ = glfwCreateWindow(std::stoi(width), std::stoi(height), title.c_str(), NULL, NULL);
        if (window_ == NULL)
        {
            LOG("RenderWindow", LogLevel::Info, "Failed to create GLFW window");
            glfwTerminate();
            return false;
        }
        glfwMakeContextCurrent(window_);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            LOG("RenderWindow", LogLevel::Info, "Failed to initialize GLAD");
            return false;
        }
        glViewport(0, 0, 800, 600);
        return true;
    }

    void RenderWindow::destroy()
    {
        glfwTerminate();
        window_ = nullptr;
    }

    bool RenderWindow::is_close()
    {
        if (window_)
            return glfwWindowShouldClose(window_);
        return true;
    }

    void RenderWindow::draw()
    {
        glfwSwapBuffers(window_);
        glfwPollEvents();    
    }
NS_END
