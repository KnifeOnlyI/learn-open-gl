#ifndef LEARNOPENGL_FILESERVICE_HPP
#define LEARNOPENGL_FILESERVICE_HPP

#include <string>

namespace gl
{
/**
 * Service to manage files
 */
class FileService
{
public:

    /**
     * Get the content of the specified file
     *
     * @param filepath The filepath
     *
     * @return The file content
     */
    static std::string getContent(const std::string &filepath);
};
}

#endif //LEARNOPENGL_FILESERVICE_HPP
