#ifndef include_vao_proc
#define include_vao_proc

#include <glad/glad.h>
#include "Sunset_vbo.h"



// Classes.
//
class Sunset_vao
{
public:

    // All the class variables.
    //
    GLuint _vao_id;

public:

    // Constructors.
    //
    Sunset_vao();


    // Some void functions.
    //
    void link_attrib(Sunset_vbo&  _vbo_input, GLuint _layout_input, GLuint _components, GLenum _type, GLsizeiptr _stride, void* _offset);

    void bind_vao();
    void unbind_vao();
    void delete_vao();

};

#endif