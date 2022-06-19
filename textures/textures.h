#ifndef include_textures_proc
#define include_textures_proc

#include <glad/glad.h>

#include "../addons/images.h"
#include "../addons/images.cpp"

#include "../shaders/shaders_processing/Sunset_shader.h"
#include "../shaders/shaders_processing/Sunset_shader.cpp"


// Classes.
//
class Sunset_textures
{
public:

    // All the class variables.
    //
    GLuint _texture_id;
    GLenum _texture_type;

public:

    // Constructors.
    //
    Sunset_textures(const char* _image_dir, GLenum _texture_type, GLenum _slots, GLenum _format, GLenum _pixel_type);


    // Some void functions.
    //
    void _texture_unit(Sunset_shaders&  _shader_object, const char* _uniform, GLuint _unit);
    void _texture_bind();
    void _texture_unbind();
    void _texture_delete();
    
};

#endif