#ifndef LEARNOPENGL_GLEXCEPTION_HPP
#define LEARNOPENGL_GLEXCEPTION_HPP

#include "exception/BaseException.hpp"

namespace gl
{
class GLException : public BaseException
{
public:

    EMPTY_CONSTRUCTOR(GLException)

    EMPTY_FORMAT_CONSTRUCTOR(GLException)

    BASIC_CONSTRUCTOR(GLException)

    FORMAT_CONSTRUCTOR(GLException)
};
}

#endif //LEARNOPENGL_GLEXCEPTION_HPP
