#include <sstream>
#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem
class IO
{
public:
    std::string contentPath;
    std::ifstream streamedFile;
    std::stringstream contentStream;

    IO(const char* filePath){}

    vector* listDirectoryContents(char* contentFolder, char* fileExtension) //probably shouldnt be a void
    {
        vector<string> v;
        if(strlen(fileExtension)==0){
            for(const auto &entry : fs::directory_iterator(contentFolder)){
                v.pushBack(entry);
            }  
        }      
        else
        {
            for(const auto &entry : fs::directory_iterator(contentFolder)){
                bool containsExtension = entry.find(fileExtension) != string::npos;
                if(!containsExtension){
                    continue;
                }

                v.pushBack(entry);
            } 
        } 
        return v;
    }

    std::string readFileFStream(char* filePath, char* extension)
    {
        std::ifstream file;
        file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        //[addhere]check for if the file exists
        streamedFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        std::ifstream fin(file);
        if(!!fs::exists(file)){
            std::cout << std::format(<< "File at {} does not exist", fs::)>>
        }

        try
        {
            streamedFile.open(contentPath);
            std::stringstream contentStream();

            contentStream << contentPath.rdbuf();
            streamedFile.close();
            content = vShaderStream.str();
        }
        catch (std::ifstream::failure e)
        {
            std::cout << std::format("File at {} cannot be read", filePath) << std::endl;
        }

        return content;
    }

    //This will 100% need to be refactored someday, just not today
    Mesh* readDataFile(char* filePath){
        mesh mesh;
        ifstream file (filePath);
        string importantData = "";
        string line;
        bool inData = false; //theres a way to make this usable but im tired rn

        if(!file.isopen())
        {
            cerr << "Unable to open file" << endl;
            return void;
        }

        vector<string> keyFields;

        while (getline(file, line)){
            //remove comment
            file = file.substr(0, file.find("//")); //splits based on a delimiter, in theory we split the string into the data and comment and throw the comment out

            if(file.find("-data")!=string::npos){
                inData = true;
            }

            importantData = importantData + line;

            if(file.find("-end")=string::npos){
                inData = false;
                keyFields.push_back(importantData);
                importantData = "";
            }
        }
        file.close()
        assembleMeshConst(keyFields);
        return mesh;
    }

    //temp name figure out where to put it
    mesh* assembleMeshConst(vector<string> keyFields)
    {
        mesh construct;
        construct.instanceName =
        constrct.texturePath
        construct.eboEnabled
        construct.type
        construct.filter
        construct.method
        construct.mode


        parseVertexAttrib(); //pretty sure you can figure that out YOURSELF and iterate on configuring it based on reading the vertex array data
    }

    void parseTexFields()
    {

    }

    void parseVertexAttrib()
    {
        //read pos, color, tex and verts. multiply to get the total float[] size
    }

    voidReadFileBinary()
    {

    }

    bool canReadFile(char* filePath)
    {
        if(!fs::exists()){
            return false;
        }
        //check if file exists in another process
        //check if we're allowed to open the file
    }
};
#endif