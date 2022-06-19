#include "Sunset_vao.h"



Sunset_vao::Sunset_vao()
{

    // Generates the buffer.
    //
    glGenVertexArrays(1, &this->_vao_id);

}


void Sunset_vao::link_attrib(Sunset_vbo _vbo_input, GLuint _layout_input, GLuint _components, GLenum _type, GLsizeiptr _stride, void* _offset)
{

    // Binds the another buffer to this one.
    //
    _vbo_input.bind_vbo();
    glVertexAttribPointer(_layout_input, _components, _type, GL_FALSE, _stride, _offset);
    glEnableVertexAttribArray(_layout_input);
    _vbo_input.unbind_vbo();

}


void Sunset_vao::bind_vao()
{

    // Binds the buffer below.
    //
    glBindVertexArray(this->_vao_id);

}


void Sunset_vao::unbind_vao()
{

    // Unbinds the buffer below.
    //
    glBindVertexArray(0);

}


void Sunset_vao::delete_vao()
{

    // Delete the buffer below.
    //
    glDeleteVertexArrays(1, &this->_vao_id);
    
}