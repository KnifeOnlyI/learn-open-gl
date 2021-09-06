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

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(_handle);
}

void ShaderProgram::use() const
{
    glUseProgram(_handle);
}

GLint ShaderProgram::getUniformLocation(const std::string &varName) const
{
    return glGetUniformLocation(_handle, varName.c_str());
}

void ShaderProgram::setUniform3f(const std::string &varName, GLfloat v1, GLfloat v2, GLfloat v3) const
{
    glUniform3f(getUniformLocation(varName), 0.5f, 1.0f, 1.0f);
}
}
