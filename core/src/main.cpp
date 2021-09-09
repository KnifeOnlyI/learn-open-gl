#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION

#include <exception/STBIException.hpp>
#include <texture/Texture.hpp>

#include "buffer/VertexArrayObject.hpp"
#include "shader/ShaderProgram.hpp"
#include "buffer/Buffer.hpp"
#include "window/Window.hpp"

int main()
{
    gl::Window window {"Learn OpenGL", 640, 480};

    gl::Shader vertexShader {gl::VERTEX, "resources/shaders/vertex.shader"};
    gl::Shader fragmentShader {gl::FRAGMENT, "resources/shaders/fragment.shader"};
    gl::ShaderProgram shaderProgram {vertexShader, fragmentShader};

    gl::Texture texture {"resources/textures/container.jpg"};

    bool play {true};

    // [x,y,z, r,g,b, s,t]
    float vertices[] = {
        // Positions      // Colors         // Texture coords
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
    };

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    gl::Buffer vbo;
    gl::Buffer ebo;
    gl::VertexArrayObject vao;

    vao.bind();

    vbo.bindTo(GL_ARRAY_BUFFER);
    vbo.sendData(GL_STATIC_DRAW, vertices, sizeof(vertices));

    ebo.bindTo(GL_ELEMENT_ARRAY_BUFFER);
    ebo.sendData(GL_STATIC_DRAW, indices, sizeof(indices));

    //Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) nullptr);
    glEnableVertexAttribArray(0);

    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    vbo.unbind();
    vao.unbind();

    float hGap {0.0f};
    float vGap {0.0f};

    shaderProgram.use();
    shaderProgram.setInt("imageTexture", 0);

    while (play)
    {
        while (window.pollEvent())
        {
            switch (window.getEvent()->window.type)
            {
                case SDL_QUIT:
                    play = false;
                    break;
                case SDL_KEYDOWN:
                    switch (window.getEvent()->key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            play = false;
                            break;
                        case SDLK_UP:
                            vGap += 0.1f;
                            break;
                        case SDLK_DOWN:
                            vGap -= 0.1f;
                            break;
                        case SDLK_LEFT:
                            hGap -= 0.1f;
                            break;
                        case SDLK_RIGHT:
                            hGap += 0.1f;
                            break;
                    }
            }
        }

        gl::Window::clear();

        shaderProgram.use();

        glActiveTexture(GL_TEXTURE0);
        texture.bind(GL_TEXTURE_2D);

        vao.bind();

        shaderProgram.setFloat("hGap", hGap);
        shaderProgram.setFloat("vGap", vGap);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        window.swapBuffers();
    }

    return 0;
}
