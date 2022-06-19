#include "Sunset_vbo.h"



Sunset_vbo::Sunset_vbo(GLfloat* _vertices_input, GLsizeiptr _size_input)
{  

    // Generates, bind and pass the buffer data.
    //
    glGenBuffers(1, &this->_vbo_id);
    glBindBuffer(GL_ARRAY_BUFFER, this->_vbo_id);
    glBufferData(GL_ARRAY_BUFFER, _size_input, _vertices_input, GL_STATIC_DRAW);

}


void Sunset_vbo::bind_vbo()
{

    // Binds the buffer below.
    //
    glBindBuffer(GL_ARRAY_BUFFER, this->_vbo_id);

}


void Sunset_vbo::unbind_vbo()
{

    // Unbind the buffer below.
    //
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}


void Sunset_vbo::delete_vbo()
{

    // Deletes the buffer below.
    //
    glDeleteBuffers(1, &this->_vbo_id);

}