/*
 * wavelike_app.h
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/22/2013
 */
 
#pragma once

#include <SDL2/SDL.h>

namespace zdev {

class WavelikeApp {
public:
    WavelikeApp(int argc = 0, const char **argv = nullptr);
    ~WavelikeApp();
    
    void run();

protected:
    int _argc;
    const char **_argv;
    SDL_Window *_window;
    bool _running;
};
    
} // namespace
