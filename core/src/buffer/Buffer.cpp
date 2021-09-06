#include <glad/glad.h>

#include "buffer/Buffer.hpp"

namespace gl
{
Buffer::Buffer()
{
    glGenBuffers(1, &_handle);
}

Buffer::~Buffer()
{
    glDeleteBuffers(1, &_handle);
}

void Buffer::bindTo(GLenum target)
{
    glBindBuffer(target, _handle);

    _target = target;
}

void Buffer::unbind()
{
    glBindBuffer(_target, 0);

    _target = 0;
}

void Buffer::sendData(GLenum usage, const void *data, GLsizeiptr size) const
{
    glBufferData(_target, size, data, usage);
}
}
