#include "Sunset_shader.h"



Sunset_shaders::Sunset_shaders(const char* vertex_program, const char* fragment_program)
{

    // Create some variables to pass the shaders source.
    //
    std::string vertex_code_input = this->content_passout(vertex_program);
    std::string fragment_code_input = this->content_passout(fragment_program);

    const char* vertex_source = vertex_code_input.c_str();
    const char* fragment_source = fragment_code_input.c_str();


    // Generates and compiler the shaders below.
    //
    GLuint _vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(_vertex_shader, 1, &vertex_source, NULL);
    glCompileShader(_vertex_shader);


    GLuint _fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(_fragment_shader, 1, &fragment_source, NULL);
    glCompileShader(_fragment_shader);
    

    // Creates an program and attach the shaders. 
    //
    this->_shader_program_id = glCreateProgram();
    glAttachShader(this->_shader_program_id, _vertex_shader);
    glAttachShader(this->_shader_program_id, _fragment_shader);


    // Link the shader program to the current application.
    //
    glLinkProgram(this->_shader_program_id);


    // Deletes the shaders because they already have been attached.
    //
    glDeleteShader(_vertex_shader);
    glDeleteShader(_fragment_shader);

}



std::string Sunset_shaders::content_passout(const char* filename)
{   

    // Gets some information about the current file.
    //
    std::ifstream file_input(filename, std::ios::binary);


    // Check if the input is not empty.
    //
    if(file_input)
    {

        // Create the some string variable to hold the files content.
        //
        std::string filename_content;


        // Pass the contents of the file to the variable.
        //
        file_input.seekg(0, std::ios::end);
        filename_content.resize(file_input.tellg());
        file_input.seekg(0, std::ios::beg);
        file_input.read(&filename_content[0], filename_content.size());


        // Close the file and return the content.
        //
        file_input.close();
        return(filename_content);

    }


    // Throw an error.
    throw(errno);

}



void Sunset_shaders::activate_shaders()
{

    // Uses the shader program below.
    //
    glUseProgram(this->_shader_program_id);
}



void Sunset_shaders::delete_shaders()
{

    // Deletes the shader program below.
    //
    glDeleteProgram(this->_shader_program_id);
}

