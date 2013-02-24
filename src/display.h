/*
 * display.h
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/23/2013
 */

#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "layer.h"

namespace zdev {

class Display {
public:
    Display();
    Display(const Display&) = delete;
    ~Display();
    
    void initialize();
    void update();
    
protected:
    void _init_window();
    void _init_opengl();
    void _init_layers();
    
protected:
    SDL_Window *_window;
    SDL_GLContext _context;
    std::vector<LayerRef> _layers;
};

} // namespace zdev

