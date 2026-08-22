#include "vector"
#include "string"

class Init
{
public:
    IO io;
    Init(){}

    void initGLFW() const
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    void initGLAD() const
    {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
        }
    }

    Mesh* initMeshes()
    {
        vector<string> dataFilePaths = io.listDirectoryContents("assets/data");
        vector<string> imgFilePaths = (assets/img);
        vector<Mesh> Meshes;

        for(auto &entry : io.listDirectoryContents())
        {
            Mesh m(io.);
            Meshes.pushBack;
        }
    }

    void
};
#endif


struct mesh {
    2d = GL_IMAGE_2D;
}
mesh mesh;
string = "2d";
mesh.type = str;