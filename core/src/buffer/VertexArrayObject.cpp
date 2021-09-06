#include <glad/glad.h>

#include "buffer/VertexArrayObject.hpp"

namespace gl
{
VertexArrayObject::VertexArrayObject()
{
    glGenVertexArrays(1, &_handle);
}

VertexArrayObject::~VertexArrayObject()
{
    glDeleteVertexArrays(1, &_handle);
}

void VertexArrayObject::bind() const
{
    glBindVertexArray(_handle);
}

void VertexArrayObject::unbind() const
{
    glBindVertexArray(_handle);
}
}
