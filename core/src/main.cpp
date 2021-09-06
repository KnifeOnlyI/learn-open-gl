#include <glad/glad.h>

#include "buffer/VertexArrayObject.hpp"
#include "shader/ShaderProgram.hpp"
#include "buffer/Buffer.hpp"
#include "window/Window.hpp"

int main()
{
    gl::Window window {"Learn OpenGL", 640, 480};
    gl::ShaderProgram shaderProgram {"#version 330 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\0",
                                     "#version 330 core\n"
                                     "uniform vec3 triangleColor;\n"
                                     "out vec4 color;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   color = vec4(triangleColor, 1.0f);\n"
                                     "}\n\0"
    };

    bool play {true};

    float vertices[] = {
        0.5f, 0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f, 0.5f, 0.0f   // top left
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    gl::Buffer vbo;
    gl::Buffer ebo;
    gl::VertexArrayObject vao;

    vao.bind();

    vbo.bindTo(GL_ARRAY_BUFFER);
    vbo.sendData(GL_STATIC_DRAW, vertices, sizeof(vertices));

    ebo.bindTo(GL_ELEMENT_ARRAY_BUFFER);
    ebo.sendData(GL_STATIC_DRAW, indices, sizeof(indices));

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) nullptr);
    glEnableVertexAttribArray(0);

    vbo.unbind();
    vao.unbind();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

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

        shaderProgram.setUniform3f("triangleColor", 0.5f, 1.0f, 1.0f);

        // Set the value of uniform variable triangleColor in fragment shader
        glUniform3f(shaderProgram.getUniformLocation("triangleColor"), 0.5f, 1.0f, 1.0f);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        window.swapBuffers();
    }

    return 0;
}
