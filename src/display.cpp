/*
 * display.cpp
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/23/2013
 */
 
#include "display.h"
#include "background.h"
#include "wave.h"

#include <iostream>
#include <SDL2/SDL_opengl.h>

namespace zdev {

Display::Display()
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

// internal

void Display::_init_window()
{
    _window = SDL_CreateWindow("Wavelike",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                1024, 768,
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
}

void Display::_init_layers()
{
    Background *background = new Background();
    Wave *wave = new Wave();
    
    _layers.push_back(LayerRef(background));
    _layers.push_back(LayerRef(wave));
}

} // namespace zdev
