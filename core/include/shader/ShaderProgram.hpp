#ifndef LEARNOPENGL_SHADERPROGRAM_HPP
#define LEARNOPENGL_SHADERPROGRAM_HPP

#include <string>

namespace gl
{
/**
 * Represent a shader program
 *
 * @author Dany Pignoux <dany.pignoux@outlook.fr>
 */
class ShaderProgram
{
public:

    /**
     * Create a new shader program
     *
     * @param vertexSource The vertex shader source code
     * @param fragmentSource The fragment shader source code
     */
    ShaderProgram(const std::string &vertexSource, const std::string &fragmentSource);

    /**
     * Destroy the shader program
     */
    virtual ~ShaderProgram();

    /**
     * Use the program
     */
    void use() const;

    /**
     * Get the location of the specified uniform variable
     *
     * @param varName The uniform variable name to find
     *
     * @return The location of the specified uniform variable
     */
    [[nodiscard]] GLint getUniformLocation(const std::string &varName) const;

    /**
     * Set the value of the specified uniform 3f variable
     *
     * @param varName The uniform variable to update
     * @param v1 The first value
     * @param v2 The second value
     * @param v3 The third value
     */
    void setUniform3f(const std::string &varName, GLfloat v1, GLfloat v2, GLfloat v3) const;

private:

    /** @var The handle */
    GLuint _handle;
};
}

#endif //LEARNOPENGL_SHADERPROGRAM_HPP
