#ifndef LEARNOPENGL_BUFFER_HPP
#define LEARNOPENGL_BUFFER_HPP

namespace gl
{
/**
 * Represent a buffer
 *
 * @author Dany Pignoux <dany.pignoux@outlook.fr>
 */
class Buffer
{
public:

    /**
     * Create new buffer
     */
    Buffer();

    /**
     * Destroy the buffer
     */
    virtual ~Buffer();

    /**
     * Bind the buffer to the specified target
     *
     * @param target The target to bind
     */
    void bindTo(GLenum target);

    /**
     * Unbind of the target
     */
    void unbind();

    /**
     * Send the specified data to the buffer
     *
     * @param usage The usage
     * @param data The data to send
     * @param size The size of the data
     */
    void sendData(GLenum usage, const void *data, GLsizeiptr size) const;

private:

    /** @var The handle */
    GLuint _handle {};

    /** @var The binding target */
    GLenum _target {0};
};
}

#endif //LEARNOPENGL_BUFFER_HPP
