#pragma once
#include "Common/MEngine.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

NS_BEGIN
    class RenderWindow
    {
    public:
        bool start();
        void destroy();
        bool is_close();
        void draw();
    private:
        GLFWwindow* window_;
    };
NS_END