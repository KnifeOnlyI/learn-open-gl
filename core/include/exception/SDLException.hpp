#ifndef LEARNOPENGL_SDLEXCEPTION_HPP
#define LEARNOPENGL_SDLEXCEPTION_HPP

#include "exception/BaseException.hpp"

namespace gl
{
class SDLException : public BaseException
{
public:

    EMPTY_CONSTRUCTOR(SDLException)

    EMPTY_FORMAT_CONSTRUCTOR(SDLException)

    BASIC_CONSTRUCTOR(SDLException)

    FORMAT_CONSTRUCTOR(SDLException)
};
}

#endif //LEARNOPENGL_SDLEXCEPTION_HPP
