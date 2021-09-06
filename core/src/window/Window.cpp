#include <glad/glad.h>

#include "exception/SDLException.hpp"
#include "window/Window.hpp"

namespace gl
{
Window::Window(const std::string &title, unsigned int width, unsigned int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        throw gl::SDLException(SDL_GetError());
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    _handle = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        static_cast<int>(width),
        static_cast<int>(height),
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );

    if (!_handle)
    {
        SDL_Quit();

        throw gl::SDLException(SDL_GetError());
    }

    if (!SDL_GL_CreateContext(_handle))
    {
        SDL_DestroyWindow(_handle);
        SDL_Quit();

        throw gl::SDLException(SDL_GetError());
    }

    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress))
    {
        SDL_DestroyWindow(_handle);
        SDL_Quit();

        throw gl::SDLException(SDL_GetError());
    }

    SDL_GL_SetSwapInterval(1);
}

Window::~Window()
{
    SDL_DestroyWindow(_handle);
    SDL_Quit();
}

SDL_Window *Window::getHandle()
{
    return _handle;
}

SDL_Event *Window::getEvent()
{
    return &_event;
}

bool Window::pollEvent()
{
    return SDL_PollEvent(&_event);
}

void Window::swapBuffers()
{
    SDL_GL_SwapWindow(_handle);
}

void Window::clear(float red, float green, float blue, float alpha)
{
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT);
}
}
