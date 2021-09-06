#include <glad/glad.h>

#include "exception/GLException.hpp"
#include "shader/Shader.hpp"

namespace gl
{
Shader::Shader(ShaderType type, const std::string &source)
{
    const char *code {source.c_str()};
    char infoLog[512];
    int success;
    GLenum shaderType;

    switch (type)
    {
        case VERTEX:
            shaderType = GL_VERTEX_SHADER;
            break;
        case FRAGMENT:
            shaderType = GL_FRAGMENT_SHADER;
            break;
    }

    _handle = glCreateShader(shaderType);

    glShaderSource(_handle, 1, &code, nullptr);
    glCompileShader(_handle);
    glGetShaderiv(_handle, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(_handle, 512, nullptr, infoLog);

        throw gl::GLException(infoLog);
    }
}

Shader::~Shader()
{
    glDeleteShader(_handle);
}

GLuint Shader::getHandle() const
{
    return _handle;
}
}
