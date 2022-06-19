#ifndef include_vbo_proc
#define include_vbo_proc

#include <glad/glad.h>




// Classes.
//
class Sunset_vbo
{
public:

    // All the class variables.
    //
    GLuint _vbo_id;

public:

    // Constructors.
    //
    Sunset_vbo(GLfloat* _vertices_input, GLsizeiptr _size_input);


    // Some void functions.
    //
    void bind_vbo();
    void unbind_vbo();
    void delete_vbo();
};

#endif