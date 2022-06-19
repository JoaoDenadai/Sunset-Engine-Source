#ifndef include_ebo_proc
#define include_ebo_proc

#include <glad/glad.h>




// Classes.
//
class Sunset_ebo
{
public:

    // All the class variables.
    //
    GLuint _ebo_id;

public:

    // Constructors.
    //
    Sunset_ebo(GLuint* _indices_input, GLsizeiptr _size_input);


    // Some void functions.
    //
    void bind_ebo();
    void unbind_ebo();
    void delete_ebo();
};

#endif