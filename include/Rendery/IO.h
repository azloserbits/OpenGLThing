#include <sstream>
#include <iostream>
#include <filesystem>


class IO
{
public:
    std::string contentPath;
    std::ifstream streamedFile;
    std::stringstream contentStream;

    IO(const char* filePath){}

    std::string* listFiles(char* contentFolder, char* fileExtension) //probably shouldnt be a void{}

    void readFile(){}

    void processTextures(const std::string &name, bool value) const{}

    void processVertexData(){}
};
#endif