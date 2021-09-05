#include "window/Window.hpp"

int main()
{
    gl::Window window {"sdf", 640, 480};

    bool play {true};

    while (play)
    {
        while (SDL_PollEvent(window.getEvent()))
        {
            if (window.getEvent()->type == SDL_QUIT)
            {
                play = false;
            }
        }
    }

    return 0;
}
