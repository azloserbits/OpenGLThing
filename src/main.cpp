#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>
//my headers start
#include "header/Shader.h"
#include "header/Window.h"
#include "header/Init.h"
#include "header/Texture.h"
#include "header/Mesh.h"
//my headers end
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


int main()
{
    Init initialize;
    initialize.initGLFW();
    Window programWindow("yaoi window", 800, 600);
    GLFWwindow* window = programWindow.getWindow();
    initialize.initGLAD();
    Shader programShader("glsl/shader.vs", "glsl/shader.fs");
    
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    initialize.initTextureAttrib();

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0); 
     
    // Wireframe mode
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loprogramWindowop
    while (!glfwWindowShouldClose(window))
    {
        programWindow.processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        programShader.use();
        // Spin me right
        float timeValue = glfwGetTime();
        glm::quat rotation(glm::vec3(0,0,timeValue));
        programShader.setMatrix("transform", glm::mat4_cast(rotation));

        //Texture rendering
        glBindTexture(GL_TEXTURE_2D, texture);
        glBindVertexArray(VAO); 
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}
