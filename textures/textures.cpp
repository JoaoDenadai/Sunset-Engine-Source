#include "textures.h"



Sunset_textures::Sunset_textures(const char* _image_dir, GLenum _texture_type, GLenum _slots, GLenum _format, GLenum _pixel_type)
{

    // Takes the texture type and locks in an class variable.
    //
    this->_texture_type = _texture_type;


    // Create some variables to hold some informations about the texture.
    //
    int _width_img, _height_img, num_colch;
    stbi_set_flip_vertically_on_load(true);


    // Loads an texture an saves on a variable.
    //
    unsigned char* _data_pack = stbi_load(_image_dir, &_width_img, &_height_img, &num_colch, 0);


    // Generate, active and bind textures to the library.
    //
    glGenTextures(1, &this->_texture_id);
    glActiveTexture(_slots);
    glBindTexture(_texture_type, this->_texture_id);
    

    // Set some additional parameters to at the textures.
    //
    glTexParameteri(_texture_type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(_texture_type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(_texture_type, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(_texture_type, GL_TEXTURE_WRAP_T, GL_REPEAT);


    // Generate the texture image.
    //
    glTexImage2D(_texture_type, 0, GL_RGBA, _width_img, _height_img, 0, _format, _pixel_type, _data_pack);


    // Generate mipmaps.
    //
    glGenerateMipmap(_texture_type);


    // After the texture has been applied, we just need set some variables in null.
    //
    stbi_image_free(_data_pack);
    glBindTexture(_texture_type, 0);

}


void Sunset_textures::_texture_unit(Sunset_shaders& _shader_object, const char* _uniform, GLuint _unit)
{

    // Get the uniform location in vertices shader.
    //
    GLuint _tex_uniform = glGetUniformLocation(_shader_object._shader_program_id, _uniform);
    _shader_object.activate_shaders();


    // Get uniforms.
    //
    glUniform1i(_tex_uniform, _unit);

}


void Sunset_textures::_texture_bind()
{

    // Binds the texture to some object.
    //
    glBindTexture(this->_texture_type, this->_texture_id);

}


void Sunset_textures::_texture_unbind()
{

    // Unbinds the texture to some object.
    //
    glBindTexture(this->_texture_type, 0);

}

void Sunset_textures::_texture_delete()
{

    // Delete the current texture.
    //
    glDeleteTextures(1, &this->_texture_id);

}