#ifndef TEXTURE_H
#define TEXTURE_H

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
class enum TextureType {
        tex1d = GL_TEXTURE_1D,
        tex2d = GL_TEXTURE_2D,
        tex3d = GL_TEXTURE_3D
};

class enum TextureWrap {
    repeat = GL_REPEAT,
    mirror = GL_MIRRORED_REPEAT,
    clamp = GL_CLAMP_TO_EDGE,
    border = GL_CLAMP_TO_BORDER
};

class enum TextureFiltering {
    nearest = GL_NEAREST,
    linear = GL_LINEAR
};

    class enum TextureMipMapMode {
        nearest = GL_NEAREST,
        linear = GL_LINEAR
    };
    class enum TextureMipMapMethod {
        nNear = GL_NEAREST_MIPMAP_NEAREST,
        lNear = GL_LINEAR_MIPMAP_NEAREST,
        nLinear = GL_NEAREST_MIPMAP_LINEAR,
        lLinear = GL_LINEAR_MIPMAP_LINEAR
    };

struct mesh {
    string instanceName;
    char* texturePath;
    bool eboEnabled;
    TextureType type;
    TextureWrap wrap;
    TextureFiltering filter;
    TextureMipMapMethod method;
    TextureMipMapMode mode;
}

class Texture
{
    public:
    std::string instanceName;
    unsigned int textureID;
    unsigned int width, height, nrChannels;
    float borderColor[];

    

    Texture(char* imagePath, TextureType type){}
    void configureTextureWrap(TextureType type, GLenum wrapMode_S, GLenum wrapMode_T){}
    void configureBorderColor(TextureType type, float *borderColor){}
    void configureTextureFiltering(TextureType type, TextureFiltering minFilter, TextureFiltering magFilter){}
    void configureMipmap(TextureType type, TextureMipMapMode filterMode, TextureMipMapMode filterMethod){}

    private:
    void configureTexture(TextureType type){}
    loadTexture(TextureType type, char* imagePath){}
}