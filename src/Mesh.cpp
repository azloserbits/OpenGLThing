#include <glad/glad.h>
#include "header/Texture.h"

class Mesh
{
public:
    Texture texture;
    int[] vertexData;
    TextureType type;

struct meshdata {
    string instanceName;
    char* texturePath;
    bool eboEnabled;
    TextureType type;
    TextureWrap wrap;
    TextureFiltering filter;
    TextureMipMapMethod method;
    TextureMipMapMode mode;
}

    Mesh(meshdata data)
    {
        texture(data.texturePath, data.type);
        processVertexData();
        readVertexAttrib();
        configureTextureAttrib();  
    }

    void processVertexData()
    {

    }

    void readVertexAttrib() const
    void configureTextureAttrib() const
    {
        // Positional attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Colour attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
        glEnableVertexAttribArray(1);

        // Texture attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6*sizeof(float)));
        glEnableVertexAttribArray(2);
    }
}