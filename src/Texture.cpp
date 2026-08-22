#ifndef TEXTURE_H
#define TEXTURE_H

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class Texture
{
    public:
    std::string instanceName;
    unsigned int textureID;
    unsigned int width, height, nrChannels;
    float borderColor[]; //pretty sure i need to create the float then.. its finicky

    enum TextureType {
        GL_TEXTURE_1D,
        GL_TEXTURE_2D,
        GL_TEXTURE_3D
    };

    enum TextureFiltering {};

    enum TextureMipMapMode {};

    enum TextureMipMapMethod {};

    //1 read assets folder
    //find all txt files
    //parse and find image files if not available continue processing and print failed ones at the end of processing
    //use constructor on textures to make texture objects
    Texture(char* imagePath, TextureType type) //might need to disable configureAllNow
    {
        glGenTextures(1, &textureID);
        glBindTexture(textureType, textureID);

        configureTexture();//insert the params here from what was obtained from the filereader
        processImageFile(imagePath);

    }
    
    void configureTextureWrap(TextureType type, GLenum wrapMode_S, GLenum wrapMode_T)
    {
        glTexParameteri(textureType, GL_TEXTURE_WRAP_S, wrapMode_S);
        glTexParameteri(textureType, GL_TEXTURE_WRAP_T, wrapMode_T);
    }
    void configureBorderColor(TextureType type, float *borderColor) //note you pass in the pointer to a float integer array
    {
        glTexParameterfv(textureType, GL_TEXTURE_BORDER_COLOR, borderColor); //Done
    }
    void configureTextureFiltering(TextureType type, TextureFiltering minFilter, TextureFiltering magFilter)
    {
        glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, magFilter);
        glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, minFilter);
    }
    void configureMipmap(TextureType type, TextureMipMapMode filterMode, TextureMipMapMode filterMethod)
    {
        glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, filterMode);
        glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, filterMethod);
    }

    private:
    void configureTexture(TextureType type)
    {
        configureTextureWrap();
        configureBorderColor();
        configureTextureFiltering();
        configureMipmap();
    }

    //todo: handle null or invalids, what happens if you change the state of one parameter or none so it stays the same
    loadTexture(TextureType type, char* imagePath)
    {
        unsigned char *data = stbi_load(imagePath, &width, &height, &nrChannels, 0);
        if (!data)
        {
            std::cout << "Texture loading failed" << std::endl;
        }
        if(type==GL_TEXTURE_1D)
        {
            glTexImage1D(textureID, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        } else if (type==GL_TEXTURE_2D)
        {
            glTexImage2D(textureID, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        } else if (type==GL_TEXTURE_3D)
        {
            glTexImage3D(textureID, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        } else {
            std::cout << "Invalid TextureType!" << std::endl;
        }
        glGenerateMipmap(texture);
        stbi_image_free(data);
    }

    void processTextures(const std::string &name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }

    

    
}