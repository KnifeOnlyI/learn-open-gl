#include <boost/format.hpp>


#include "exception/STBIException.hpp"
#include "texture/Texture.hpp"

namespace gl
{
Texture::Texture(const std::string &filepath)
{
    int width, height, nrChannels;
    unsigned char *data {stbi_load(filepath.c_str(), &width, &height, &nrChannels, 0)};

    if (!data)
    {
        throw gl::STBIException(
            boost::format("Cannot open file \"%1%\" because : %2%") % filepath % stbi_failure_reason()
        );
    }

    glGenTextures(1, &_handle);
    glBindTexture(GL_TEXTURE_2D, _handle);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
}

Texture::~Texture()
{
    glDeleteTextures(1, &_handle);
}

void Texture::bind(GLuint target)
{
    glBindTexture(target, _handle);

    _buffer = target;
}

void Texture::unbind()
{
    glBindTexture(_buffer, 0);

    _buffer = 0;
}
}
