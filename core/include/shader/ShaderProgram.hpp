#ifndef LEARNOPENGL_SHADERPROGRAM_HPP
#define LEARNOPENGL_SHADERPROGRAM_HPP

#include <string>
#include "Shader.hpp"

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
     * Create a new shader program
     *
     * @param vertexShader The vertex shader
     * @param fragmentShader The fragment shader
     */
    ShaderProgram(const Shader &vertexShader, const Shader &fragmentShader);

    /**
     * Destroy the shader program
     */
    virtual ~ShaderProgram();

    /**
     * Use the program
     */
    void use() const;

    /**
     * Set the value of the specified uniform bool variable
     *
     * @param varName The uniform variable to update
     * @param value The value
     */
    void setBool(const std::string &varName, bool value) const;

    /**
     * Set the value of the specified uniform int variable
     *
     * @param varName The uniform variable to update
     * @param value The value
     */
    void setInt(const std::string &varName, int value) const;

    /**
     * Set the value of the specified uniform float variable
     *
     * @param varName The uniform variable to update
     * @param value The value
     */
    void setFloat(const std::string &varName, float value) const;

    /**
     * Set the value of the specified uniform vec3 variable
     *
     * @param varName The uniform variable to update
     * @param v1 The first value
     * @param v2 The second value
     * @param v3 The third value
     */
    void setVec3(const std::string &varName, GLfloat v1, GLfloat v2, GLfloat v3) const;

    /**
     * Set the value of the specified uniform vec4 variable
     *
     * @param varName The uniform variable to update
     * @param v1 The first value
     * @param v2 The second value
     * @param v3 The third value
     * @param v4 The fourth value
     */
    void setVec4(const std::string &varName, GLfloat v1, GLfloat v2, GLfloat v3, GLfloat v4) const;

private:

    /**
     * Get the location of the specified uniform variable
     *
     * @param varName The uniform variable name to find
     *
     * @return The location of the specified uniform variable
     */
    [[nodiscard]] GLint getUniformLocation(const std::string &varName) const;

private:

    /** @var The handle */
    GLuint _handle;
};
}

#endif //LEARNOPENGL_SHADERPROGRAM_HPP
