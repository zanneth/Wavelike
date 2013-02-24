/*
 * wave.h
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/23/2013
 */

#pragma once

#include "layer.h"
#include "shader_program.h"

namespace zdev {

class Wave : public Layer {
public:
    Wave();
    ~Wave();
    
    void initialize() override;
    void draw() override;
    
protected:
    void _generate_wave_vertices(unsigned count, GLfloat *out_vertices);
    void _load_buffers();
    
protected:
    GLuint _vertex_buffer;
};

} // namespace zdev
