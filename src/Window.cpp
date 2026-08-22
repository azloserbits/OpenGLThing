#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
class Window
{
    GLFWwindow* window;
    void framebuffer_size_callback(GLFWwindow* window, int width, int height){}
    bool m_shouldClose = false;

public:
    Window(const char* name, unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT)
    {
        window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, name, NULL, NULL);
        if (window == NULL)
        {
           std::cout << "Failed to create GLFW window" << std::endl;
           glfwTerminate();
        }
        glfwMakeContextCurrent(window);
        // glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    }

    GLFWwindow* getWindow()
    {
        return window;
    }

    // void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    // {
    //     glViewport(0, 0, width, height);
    // }

    void processInput(GLFWwindow *window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            m_shouldClose = true;
    }

    bool shouldClose()
    {
        return m_shouldClose;
    }

    
};
