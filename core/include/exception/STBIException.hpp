#ifndef LEARNOPENGL_STBIEXCEPTION_HPP
#define LEARNOPENGL_STBIEXCEPTION_HPP

#include "exception/BaseException.hpp"

namespace gl
{
class STBIException : public BaseException
{
public:

    EMPTY_CONSTRUCTOR(STBIException)

    EMPTY_FORMAT_CONSTRUCTOR(STBIException)

    BASIC_CONSTRUCTOR(STBIException)

    FORMAT_CONSTRUCTOR(STBIException)
};
}

#endif //LEARNOPENGL_STBIEXCEPTION_HPP
