/*
 * background.cpp
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/23/2013
 */

#include "background.h"
#include "display.h"
#include <array>

static const GLfloat quad_vertex_data[4 * 3] = {
    -1.0f,   -1.0f,   0.f,
    1.0f,    -1.0f,   0.f,
    -1.0f,   1.0f,    0.f,
    1.0f,    1.0f,    0.f
};

namespace zdev {

Background::Background() :
    _begin_color({ 0.f, 0.f, 0.f, 1.f }),
    _end_color({ 0.332391, 0.159366, 0.450777, 1.f }),
    _modelview_uniform(-1),
    _begin_color_uniform(-1),
    _end_color_uniform(-1)
{}

Background::~Background()
{
    glDeleteBuffers(1, &_vertex_buffer);
}

void Background::initialize()
{
    _load_buffers();
    _load_shaders();
}

void Background::draw()
{
    _shader_program->use_program();
    _update_uniforms();
    
    glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
    glVertexAttribPointer(VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

// internal

void Background::_load_buffers()
{
    glGenBuffers(1, &_vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, 4 * 3 * sizeof(GLfloat), quad_vertex_data, GL_STATIC_DRAW);
}

void Background::_load_shaders()
{
    _shader_program = ShaderProgramRef(new ShaderProgram);
    _shader_program->load_shader("shaders/projection_vertex.glsl", GL_VERTEX_SHADER);
    _shader_program->load_shader("shaders/background_frag.glsl", GL_FRAGMENT_SHADER);
    _shader_program->bind_attribute(VERTEX_ATTRIB_POSITION, "position");
    _shader_program->link_program();
    
    _modelview_uniform = _shader_program->get_uniform("modelview");
    _begin_color_uniform = _shader_program->get_uniform("begin_color");
    _end_color_uniform = _shader_program->get_uniform("end_color");
}

void Background::_update_uniforms()
{
    Display *display = get_display();
    
    // setup the modelview and projection matrices
    if (display != nullptr) {
        display->update_programmable_projection(_shader_program);
        display->update_programmable_viewport(_shader_program);
    }
    
    glUniformMatrix4fv(_modelview_uniform, 1, GL_FALSE, Util::identity_matrix().data());
    glUniform4fv(_begin_color_uniform, 1, _begin_color.data());
    glUniform4fv(_end_color_uniform, 1, _end_color.data());
}

} // namespace zdev
