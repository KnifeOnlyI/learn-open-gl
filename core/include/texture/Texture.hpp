#ifndef LEARNOPENGL_TEXTURE_HPP
#define LEARNOPENGL_TEXTURE_HPP

#include <string>

#include <stb/stb_image.h>
#include <glad/glad.h>

namespace gl
{
/**
 * Represent a texture
 *
 * @author Dany Pignoux <dany.pignoux@outlook.fr>
 */
class Texture
{
public:

    /**
     * Create a new texture
     *
     * @param filepath The texture filepath
     */
    explicit Texture(const std::string &filepath);

    /**
     * Destroy the texture
     */
    virtual ~Texture();

    /**
     * Bind the texture to the specified texture buffer
     *
     * @param target The target
     */
    void bind(GLuint target);

    /**
     * Unbind the texture of his current buffer binding
     */
    void unbind();

private:

    /** @var The handle */
    GLuint _handle {};

    /** @var The current buffer binding */
    GLuint _buffer {};
};
}

#endif //LEARNOPENGL_TEXTURE_HPP
