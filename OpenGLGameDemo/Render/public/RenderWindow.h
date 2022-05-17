#pragma once
#include "Common/MEngine.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

NS_BEGIN
    class RenderWindow
    {
    public:
        bool Start();
        void Destroy();
        bool IsClose();
        void Draw();
    private:
        GLFWwindow* window_;
    };
NS_END