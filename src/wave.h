/*
 * wave.h
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/23/2013
 */

#pragma once

#include "layer.h"
#include "shader_program.h"
#include <vector>

namespace zdev {

class Wave : public Layer {
public:
    Wave();
    ~Wave();
    
    void initialize() override;
    void draw() override;
    
    float get_thickness() const { return _thickness; }
    void set_thickness(float thickness) { _thickness = thickness; }
    
protected:
    void _generate_wave_vertices(unsigned resolution, std::vector<GLfloat> &out_vertices);
    void _load_buffers();
    void _load_shaders();
    void _update_uniforms();
    
protected:
    GLuint _vertex_buffer;
    unsigned _vertex_count;
    float _thickness;
    float _current_time;
    
    ShaderProgramRef _shader_program;
    GLint _modelview_uniform;
    GLint _time_uniform;
};

} // namespace zdev
