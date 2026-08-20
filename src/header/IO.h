#include <sstream>
#include <iostream>
#include <filesystem>


class IO
{
public:
    std::string contentPath;
    std::ifstream streamedFile;
    std::stringstream contentStream;

    IO(const char* filePath)
    {
        streamedFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

        //file streaming
        try
        {
        streamedFile.open(contentPath);

        contentStream << contentPath.rdbuf(); //might be calling rdbuf on the wrong thing

        streamedFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
        }
        catch (std::ifstream::failure e)
        {
            std::cout << "ERROR::FILE_NOT_SUCCESSFULY_READ" << std::endl;
        }

        //store results in char array
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();

    }

    void 

    std::string* listFiles(char* contentFolder, char* fileExtension) //probably shouldnt be a void
    {
        for(const auto &entry : std::filesystem::directory_iterator(contentFolder)){

        }
    }

    void readFile()
    {
        //check for if the file exists
    }

    void processTextures(const std::string &name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }

    void processVertexData()
    {

    }
};
#endif