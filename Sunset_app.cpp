#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw.h>
#include <math.h>

#include "addons/glad.c"

#include "shaders/Sunset_ebo.h"
#include "shaders/Sunset_vao.h"
#include "shaders/Sunset_vbo.h"

#include "shaders/Sunset_ebo.cpp"
#include "shaders/Sunset_vao.cpp"
#include "shaders/Sunset_vbo.cpp"


#include "./textures/textures.h"
#include "./textures/textures.cpp"



void _gl_init()
{

    // Initializes the graphics library.
    //
    glfwInit();

}


void _gl_version_setup(GLint v_Major_, GLint v_Minor_)
{

    // Setup library version data. Only change that if you want change the library version.
    //
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, v_Major_);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, v_Minor_);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

}


void _gl_glad_setup(GLint h_Width, GLint h_Height)
{

    // Initialize the graphics extension library.
    //
    gladLoadGL();
    glViewport(0, 0, h_Width, h_Height);

}


int main()
{

    // Functions will setup the versions and the libraries. 
    //
    _gl_init();
    _gl_version_setup(3, 3);


    // Window objects vertices.
    //
    GLfloat _gl_vertices_data[] = 
    {
        -0.5f, -0.5f, 0.0f,         1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f,         0.0f, 1.0f, 0.0f,   0.0f, 1.0f,
         0.5f,  0.5f, 0.0f,         0.0f, 0.0f, 1.0f,   1.0f, 1.0f,
         0.5f, -0.5f, 0.0f,         1.0f, 1.0f, 1.0f,   1.0f, 0.0f
    };

    GLuint _gl_indices_data[] =
    {
        0, 2, 1,
        0, 3, 2
    };

    // Variable that goes store the window object. This is literally the window.
    //
    auto h_Window = glfwCreateWindow(800, 800, "", NULL, NULL);


    // Function will show the current window below.
    //
    glfwMakeContextCurrent(h_Window);


    // Function that goes setup the graphics extension library.
    //
    _gl_glad_setup(800, 800);


    // Generate the shaders and process.
    //
    Sunset_shaders _shaders("./shaders/sources/Sunset_shader.vert", "./shaders/sources/Sunset_shader.frag");


    // Generates an buffer and binds him.
    //
    Sunset_vao _vao;
    _vao.bind_vao();


    // Generates more buffers.
    //
    Sunset_vbo _vbo(_gl_vertices_data, sizeof(_gl_vertices_data));
    Sunset_ebo _ebo(_gl_indices_data, sizeof(_gl_indices_data));


    // Links an buffer to the another one.
    //
    _vao.link_attrib(_vbo, 0, 3, GL_FLOAT, 8*sizeof(float), (void*)0);
    _vao.link_attrib(_vbo, 1, 3, GL_FLOAT, 8*sizeof(float), (void*)(3* sizeof(float)));
    _vao.link_attrib(_vbo, 2, 2, GL_FLOAT, 8*sizeof(float), (void*)(6* sizeof(float)));


    // Unbinds the buffers because they already have been linked.
    //
    _vao.unbind_vao();
    _vbo.unbind_vbo();
    _ebo.unbind_ebo();


    // Create and load some textures. Tells the unit processment local.
    //
    Sunset_textures _texture_load("./textures/media/Noise.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    _texture_load._texture_unit(_shaders, "tex0", 0);


    // Window main loop. That will makes him stay open while the user are using.
    //
    while(!glfwWindowShouldClose(h_Window))
    {

        // Use programs and buffers to draw something on the screen.
        //
        _shaders.activate_shaders();
        _texture_load._texture_bind();
        _vao.bind_vao();

        
        glDrawElements(GL_TRIANGLES, sizeof(_gl_indices_data)/sizeof(GLuint), GL_UNSIGNED_INT, 0);
        

        // Swap the window buffers.
        //
        glfwSwapBuffers(h_Window);


        // Generates window events.
        //
        glfwPollEvents();

    }

    // Deletes the shaders, objects and buffers used in the window.
    //
    _vao.delete_vao();
    _vbo.delete_vbo();
    _ebo.delete_ebo();
    _texture_load._texture_delete();
    _shaders.delete_shaders();


    // Destroy and terminate the window process. You do not need change nothing here.
    //
    glfwTerminate();
    glfwDestroyWindow(h_Window);

    return 0;

}