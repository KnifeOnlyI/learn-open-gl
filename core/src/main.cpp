#include <glad/glad.h>
#include "window/Window.hpp"

int main()
{
    gl::Window window {"Learn OpenGL", 640, 480};

    bool play {true};

    while (play)
    {
        while (window.pollEvent())
        {
            switch (window.getEvent()->window.type)
            {
                case SDL_QUIT:
                    play = false;
                case SDL_KEYDOWN:
                    break;
            }
        }

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.swapBuffers();
    }

    return 0;
}
