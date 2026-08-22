#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include


class Shader
{
public:
    // shader program ID
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath)
    {
        IO io;
        string vertexCode = io.readFileFStream("vertex.vs");
        //there's probably a way to hunt for shaders like Program: programName {shaders in use here}
        //allowing for more than one vertex and fragment shader
        //iterating through shaders 
        string fragmentCode = io.readFileFStream("shader.fs");
        
        string fragmentCode;
        unsigned int vertex, fragment;
        compileShader(vertex, "Vertex", vertexCode);
        compileShader(fragment, "Fragment", fragmentCode);
        compileShader(ID, "Program", " ");
    }

    void use()
    {
        glUseProgram(ID);
    }

    // Uniform setters
    void setBool(const std::string &name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }
    void setInt(const std::string &name, int value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }
    void setFloat(const std::string &name, float value) const
    {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }
    void setMatrix(const std:: string &name, glm::mat4 value) const
    {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1 , GL_FALSE, &value[0][0]);
    }

private:
    void compileShader(unsigned int shader, std::string shaderType, std::string shaderCode){
        int success;
        char errorLog[1024];

        if(shaderType!="Program"){
            const char* code = shaderCode.c_str();

            glShaderSource(shader, 1, code, NULL);
            glCompileShader(shader);
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

            if(!success)
            {
                glGetShaderInfoLog(vertex, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
            }
        } 
        elseif (shaderType == "Vertex" || shaderType == "Fragment") {
            ID = glCreateProgram();
            glAttachShader(ID, vertex);
            glAttachShader(ID, fragment);
            glLinkProgram(ID);
            glGetProgramiv(ID, GL_LINK_STATUS, &success);
            if(!success)
            {
                glGetProgramInfoLog(ID, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER:PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
            }

            glDeleteShader(vertex);
            glDeleteShader(fragment);
        } 
        else
        {
            std::cout << "Invalid shader type\n"
        }
    }
};