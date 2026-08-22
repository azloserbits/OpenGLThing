#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
class Window
{
    GLFWwindow* window;
    void framebuffer_size_callback(GLFWwindow* window, int width, int height){}
    bool m_shouldClose = false;
    
public:
    Window(const char* name, unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT){}

    GLFWwindow* getWindow(){}

    void framebuffer_size_callback(GLFWwindow* window, int width, int height){}

    void processInput(GLFWwindow *window){}

    bool shouldClose(){}  
};
#endif