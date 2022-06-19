#ifndef include_shader_proc
#define include_shader_proc

#include <iostream>
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cerrno>



// Classes.
//
class Sunset_shaders
{
public:

    // All the class variables.
    //
    GLuint _shader_program_id;

public:

    // Constructors.
    //
    Sunset_shaders(const char* vertex_program, const char* fragment_program);


    // Some string functions.
    //
    std::string content_passout(const char* file_program);


    // Some void functions.
    //
    void activate_shaders();
    void delete_shaders();

};


#endif