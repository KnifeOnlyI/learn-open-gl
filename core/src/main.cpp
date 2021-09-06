#include <glad/glad.h>

#include "buffer/VertexArrayObject.hpp"
#include "shader/ShaderProgram.hpp"
#include "file/FileService.hpp"
#include "buffer/Buffer.hpp"
#include "window/Window.hpp"

int main()
{
    gl::Window window {"Learn OpenGL", 640, 480};

    gl::Shader vertexShader {gl::VERTEX, gl::FileService::getContent("vertex.shader")};
    gl::Shader fragmentShader {gl::FRAGMENT, gl::FileService::getContent("fragment.shader")};
    gl::ShaderProgram shaderProgram {vertexShader, fragmentShader};

    bool play {true};

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
    };

    unsigned int indices[] = {0, 1, 2};

    gl::Buffer vbo;
    gl::Buffer ebo;
    gl::VertexArrayObject vao;

    vao.bind();

    vbo.bindTo(GL_ARRAY_BUFFER);
    vbo.sendData(GL_STATIC_DRAW, vertices, sizeof(vertices));

    ebo.bindTo(GL_ELEMENT_ARRAY_BUFFER);
    ebo.sendData(GL_STATIC_DRAW, indices, sizeof(indices));

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    vbo.unbind();
    vao.unbind();

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
                    }
            }
        }

        gl::Window::clear();

        shaderProgram.use();
        vao.bind();

        shaderProgram.setFloat("colorMultiplier", 1.0f);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        window.swapBuffers();
    }

    return 0;
}
