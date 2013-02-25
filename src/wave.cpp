/*
 * wave.cpp
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/23/2013
 */

#include "wave.h"
#include "display.h"
#include <iostream>

namespace zdev {

Wave::Wave() :
    _vertex_count(0),
    _current_time(0.0),
    _thickness(0.2),
    _speed(0.4),
    _modelview_uniform(-1),
    _time_uniform(-1)
{}

Wave::~Wave()
{
    glDeleteBuffers(1, &_vertex_buffer);
}

void Wave::initialize()
{
    _load_buffers();
    _load_shaders();
}

void Wave::draw()
{
    _shader_program->use_program();
    _update_uniforms();
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableVertexAttribArray(VERTEX_ATTRIB_POSITION);
    
    glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
    glVertexAttribPointer(VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, _vertex_count);
    
    glDisableVertexAttribArray(VERTEX_ATTRIB_POSITION);
    glDisableClientState(GL_VERTEX_ARRAY);
}

// internal

void Wave::_generate_wave_vertices(unsigned resolution, std::vector<GLfloat> &out_vertices)
{
    if (resolution == 0) { return; }
    
    const float y1 = -(_thickness / 2.f);
    const float y2 = -y1;
    const float z = 0.f;
    
    unsigned upper_bound = resolution + 1;
    for (unsigned i = 0; i < upper_bound; ++i) {
        float x = ((float(i) / float(resolution)) * 2.0) - 1.0;
        
        out_vertices.push_back(x);
        out_vertices.push_back(y1);
        out_vertices.push_back(z);
        
        out_vertices.push_back(x);
        out_vertices.push_back(y2);
        out_vertices.push_back(z);
    }
}

void Wave::_load_buffers()
{
    std::vector<GLfloat> vertices;
    _generate_wave_vertices(100, vertices);
    
    GLfloat *vertex_data = vertices.data();
    _vertex_count = (unsigned) vertices.size() / 3;
    
    glGenBuffers(1, &_vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, _vertex_count * 3 * sizeof(GLfloat), vertex_data, GL_STATIC_DRAW);
}

void Wave::_load_shaders()
{
    _shader_program = ShaderProgramRef(new ShaderProgram);
    _shader_program->load_shader("shaders/wave_vertex.glsl", GL_VERTEX_SHADER);
    _shader_program->load_shader("shaders/wave_frag.glsl", GL_FRAGMENT_SHADER);
    _shader_program->bind_attribute(VERTEX_ATTRIB_POSITION, "position");
    _shader_program->link_program();
    _shader_program->use_program();
    
    _modelview_uniform = _shader_program->get_uniform("modelview");
    _time_uniform = _shader_program->get_uniform("time");
}

void Wave::_update_uniforms()
{
    Display *display = get_display();
    if (display != nullptr) {
        display->update_programmable_projection(_shader_program);
        display->update_programmable_viewport(_shader_program);
    }
    
    glUniformMatrix4fv(_modelview_uniform, 1, GL_FALSE, Util::identity_matrix().data());
    glUniform1f(_time_uniform, _current_time);
    
    _current_time += _speed / 100.f;
}

} // namespace zdev
