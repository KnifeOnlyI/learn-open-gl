#ifndef LEARNOPENGL_SHADER_HPP
#define LEARNOPENGL_SHADER_HPP

#include <string>

namespace gl
{
/**
 * Represent a shader type
 *
 * @author Dany Pignoux <dany.pignoux@outlook.fr>
 */
enum ShaderType
{
    VERTEX,     /* The vertex shader */
    FRAGMENT,   /* The fragment shader */
};

/**
 * Represent an OpenGL shader
 *
 * @author Dany Pignoux <dany.pignoux@outlook.fr>
 */
class Shader
{
public:

    /**
     * Create a new shader
     *
     * @param type The shader type
     * @param filepath The shader's source code filepath
     */
    Shader(ShaderType type, const std::string &filepath);

    /**
     * Destroy the shader
     */
    virtual ~Shader();

    /**
     * Get the handle
     *
     * @return The handle
     */
    [[nodiscard]] GLuint getHandle() const;

private:

    /** @var The handle */
    GLuint _handle;
};
}

#endif //LEARNOPENGL_SHADER_HPP
