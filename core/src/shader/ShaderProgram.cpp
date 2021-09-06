#include <glad/glad.h>

#include "exception/GLException.hpp"
#include "shader/ShaderProgram.hpp"
#include "shader/Shader.hpp"

namespace gl
{
ShaderProgram::ShaderProgram(const std::string &vertexSource, const std::string &fragmentSource)
{
    char infoLog[512];
    int success;

    gl::Shader vertexShader {gl::ShaderType::VERTEX, vertexSource};
    gl::Shader fragmentShader {gl::ShaderType::FRAGMENT, fragmentSource};

    _handle = glCreateProgram();

    glAttachShader(_handle, vertexShader.getHandle());
    glAttachShader(_handle, fragmentShader.getHandle());
    glLinkProgram(_handle);

    glGetProgramiv(_handle, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(_handle, 512, nullptr, infoLog);

        throw gl::GLException(infoLog);
    }
}

ShaderProgram::ShaderProgram(const Shader &vertexShader, const Shader &fragmentShader)
{
    char infoLog[512];
    int success;

    _handle = glCreateProgram();

    glAttachShader(_handle, vertexShader.getHandle());
    glAttachShader(_handle, fragmentShader.getHandle());
    glLinkProgram(_handle);

    glGetProgramiv(_handle, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(_handle, 512, nullptr, infoLog);

        throw gl::GLException(infoLog);
    }
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(_handle);
}

void ShaderProgram::use() const
{
    glUseProgram(_handle);
}

void ShaderProgram::setBool(const std::string &varName, bool value) const
{
    setInt(varName, value);
}

void ShaderProgram::setInt(const std::string &varName, int value) const
{
    glUniform1i(getUniformLocation(varName), value);
}

void ShaderProgram::setFloat(const std::string &varName, float value) const
{
    glUniform1f(getUniformLocation(varName), value);
}

void ShaderProgram::setVec3(const std::string &varName, GLfloat v1, GLfloat v2, GLfloat v3) const
{
    glUniform3f(getUniformLocation(varName), v1, v2, v3);
}

void ShaderProgram::setVec4(const std::string &varName, GLfloat v1, GLfloat v2, GLfloat v3, GLfloat v4) const
{
    glUniform4f(getUniformLocation(varName), v1, v2, v3, v4);
}

GLint ShaderProgram::getUniformLocation(const std::string &varName) const
{
    GLint results {glGetUniformLocation(_handle, varName.c_str())};

    if (results == -1)
    {
        throw GLException(
            boost::format("Cannot find uniform variable \"%1%\" in the current used shader program") % varName
        );
    }

    return results;
}
}
