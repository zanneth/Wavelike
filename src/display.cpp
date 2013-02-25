/*
 * display.cpp
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/23/2013
 */
 
#include "display.h"
#include "background.h"
#include "shader_program.h"
#include "utility.h"
#include "wave.h"

#include <iostream>
#include <SDL2/SDL_opengl.h>

namespace zdev {

Display::Display() :
    _viewport_size(1024, 768),
    _projection_dirty(true)
{}

Display::~Display()
{
    if (_window != nullptr) {
        SDL_DestroyWindow(_window);
    }
    
    if (_context != nullptr) {
        SDL_GL_DeleteContext(_context);
    }
}

void Display::initialize()
{
    _init_window();
    _init_opengl();
    _init_layers();
}

void Display::update()
{
    SDL_GL_MakeCurrent(_window, _context);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    
    for (LayerRef layer : _layers) {
        layer->draw();
    }
    
    SDL_GL_SwapWindow(_window);
}

const Matrix4f& Display::get_projection_matrix()
{
    if (_projection_dirty) {
        _projection_matrix = Util::ortho_matrix(-1.f, 1.f, -1.f, 1.f, 0.01f, 100.f);
        _projection_dirty = false;
    }
    return _projection_matrix;
}

const std::pair<unsigned, unsigned>& Display::get_viewport_size() const
{
    return _viewport_size;
}

void Display::set_viewport_size(const std::pair<unsigned int, unsigned int> &size)
{
    glViewport(0, 0, size.first, size.second);
}

void Display::update_programmable_projection(ShaderProgramRef shader_program)
{
    GLint proj_uniform = shader_program->get_uniform("projection");
    glUniformMatrix4fv(proj_uniform, 1, GL_FALSE, get_projection_matrix().data());
}

void Display::update_programmable_viewport(ShaderProgramRef shader_program)
{
    GLint viewport_uniform = shader_program->get_uniform("viewport_size");
    glUniform2f(viewport_uniform, _viewport_size.first, _viewport_size.second);
}

// internal

void Display::_init_window()
{
    _window = SDL_CreateWindow("Wavelike",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                _viewport_size.first, _viewport_size.second,
                                SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (_window == nullptr) {
        std::cerr << "Could not create SDL window." << std::endl;
    }
}

void Display::_init_opengl()
{
    _context = SDL_GL_CreateContext(_window);
    SDL_GL_MakeCurrent(_window, _context);
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glViewport(0, 0, _viewport_size.first, _viewport_size.second);
}

void Display::_init_layers()
{
    _layers.push_back(LayerRef(new Background));
    _layers.push_back(LayerRef(new Wave));
    
    for (LayerRef layer : _layers) {
        layer->set_display(this);
        layer->initialize();
    }
}

} // namespace zdev
