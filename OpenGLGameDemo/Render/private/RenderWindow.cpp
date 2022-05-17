#include "RenderWindow.h"
#include "Log/EngineLog.h"

NS_BEGIN
    bool RenderWindow::Start()
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if ENGINE_MACOS
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
        window_ = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
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

    void RenderWindow::Destroy()
    {
        glfwTerminate();
        window_ = nullptr;
    }

    bool RenderWindow::IsClose()
    {
        if (window_)
            return glfwWindowShouldClose(window_);
        return true;
    }

    void RenderWindow::Draw()
    {
        glfwSwapBuffers(window_);
        glfwPollEvents();    
    }
NS_END
