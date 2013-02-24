/*
 * wave.cpp
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/23/2013
 */

#include "wave.h"
#include <array>

namespace zdev {

Wave::Wave()
{}

Wave::~Wave()
{
    glDeleteBuffers(1, &_vertex_buffer);
}

void Wave::initialize()
{
    glGenBuffers(1, &_vertex_buffer);
}

void Wave::draw()
{
    // TODO
}

// internal

void Wave::_generate_wave_vertices(unsigned count, GLfloat *out_vertices)
{
    // TODO
}

void Wave::_load_buffers()
{
    const unsigned wave_vertices_count = 4;
    GLfloat wave_vertices[wave_vertices_count];
    _generate_wave_vertices(wave_vertices_count, wave_vertices);
    
    glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, wave_vertices_count * 3 * sizeof(GLfloat), wave_vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(VERTEX_ATTRIB_POSITION);
}

} // namespace zdev
