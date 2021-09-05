#ifndef LEARNOPENGL_WINDOW_HPP
#define LEARNOPENGL_WINDOW_HPP

#include <SDL2/SDL.h>
#include <string>

namespace gl
{
/**
 * Represent a window
 *
 * @author Dany Pignoux <dany.pignoux@outlook.fr>
 */
class Window
{
public:

    /**
     * Create new window
     *
     * @param title The title
     * @param width The width
     * @param height The height
     */
    Window(const std::string &title, unsigned int width, unsigned int height);

    /**
     * Destroy the window
     */
    virtual ~Window();

    /**
     * Get the handle
     *
     * @return The handle
     */
    SDL_Window *getHandle();

    /**
     * Get the event manager
     *
     * @return The event manager
     */
    SDL_Event *getEvent();

private:

    /** @var The handle SDL window */
    SDL_Window *_handle;

    /** @var The SDL event manager */
    SDL_Event _event {};
};
}

#endif //LEARNOPENGL_WINDOW_HPP
