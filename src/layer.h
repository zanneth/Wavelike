/*
 * layer.h
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/24/2013
 */

#pragma once

#include "shader_program.h"
#include <memory>
#include <SDL2/SDL_opengl.h>

namespace zdev {

class Display;

class Layer {
public:
    Layer();
    virtual ~Layer();
    
    virtual void initialize();
    virtual void draw();
    
    Display* get_display() const { return _display; }
    void set_display(Display *display) { _display = display; }
    
protected:
    Display *_display;
};

typedef std::shared_ptr<Layer> LayerRef;

} // namespace zdev
