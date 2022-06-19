#include "Sunset_ebo.h"



Sunset_ebo::Sunset_ebo(GLuint* _indices_input, GLsizeiptr _size_input)
{

    // Generates, bind and pass the buffer data.
    //
    glGenBuffers(1, &this->_ebo_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_ebo_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _size_input, _indices_input, GL_STATIC_DRAW);

}


void Sunset_ebo::bind_ebo()
{

    // Binds the buffer below.
    //
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_ebo_id);

}


void Sunset_ebo::unbind_ebo()
{

    // Unbind the buffer below.
    //
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}


void Sunset_ebo::delete_ebo()
{

    // Deletes the buffer below.
    //
    glDeleteBuffers(1, &this->_ebo_id);
    
}