/*
 * background.h
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/23/2013
 */

#pragma once

#include "layer.h"
#include "shader_program.h"
#include "utility.h"

namespace zdev {

class Background : public Layer {
public:
    Background();
    ~Background();
    
    void initialize() override;
    void draw() override;
    
protected:
    void _load_buffers();
    void _load_shaders();
    void _update_uniforms();

protected:
    Vertex4f _begin_color;
    Vertex4f _end_color;
    GLuint _vertex_buffer;
    
    ShaderProgramRef _shader_program;
    GLint _modelview_uniform;
    GLint _begin_color_uniform;
    GLint _end_color_uniform;
};

} // namespace zdev
