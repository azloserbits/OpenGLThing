#include <glad/glad.h>
#include "header/Texture.h"

class Mesh
{
public:
    Texture texture;
    int[] vertexData;
    Mesh(){
        
    }

    void initTextureAttrib() const{}
}