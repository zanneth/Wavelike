/*
 * display.h
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/23/2013
 */

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <algorithm>
#include <utility>

#include "layer.h"
#include "shader_program.h"
#include "utility.h"

namespace zdev {

class Display {
public:
    Display();
    Display(const Display&) = delete;
    ~Display();
    
    void initialize();
    void update();
    
    const Matrix4f& get_projection_matrix();
    const std::pair<unsigned, unsigned>& get_viewport_size() const;
    void set_viewport_size(const std::pair<unsigned, unsigned> &size);
    
    void update_programmable_projection(ShaderProgramRef shader_program);
    void update_programmable_viewport(ShaderProgramRef shader_program);
    
protected:
    void _init_window();
    void _init_opengl();
    void _init_layers();
    
protected:
    SDL_Window *_window;
    SDL_GLContext _context;
    std::pair<unsigned, unsigned> _viewport_size;
    std::vector<LayerRef> _layers;
    Matrix4f _projection_matrix;
    bool _projection_dirty;
};

} // namespace zdev

