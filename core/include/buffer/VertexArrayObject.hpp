#ifndef LEARNOPENGL_VERTEXARRAYOBJECT_HPP
#define LEARNOPENGL_VERTEXARRAYOBJECT_HPP

namespace gl
{
/**
 * Represent a vertex array object
 *
 * @author Dany Pignoux <dany.pignoux@outlook.fr>
 */
class VertexArrayObject
{
public:

    /**
     * Create a new vertex array object
     */
    VertexArrayObject();

    /**
     * Destroy the vertex array object
     */
    virtual ~VertexArrayObject();

    /**
     * Bind the vertex array object
     */
    void bind() const;

    /**
     * Unbind the vertex array object
     */
    void unbind() const;

private:

    /** @var The handle */
    GLuint _handle {};
};
}

#endif //LEARNOPENGL_VERTEXARRAYOBJECT_HPP
