#include <fstream>

#include "file/FileService.hpp"

namespace gl
{
std::string FileService::getContent(const std::string &filepath)
{
    std::string fileContent;
    std::string line;
    std::ifstream file {filepath};

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            fileContent.append(line).append("\n");
        }

        file.close();
    }

    return fileContent;
}
}
