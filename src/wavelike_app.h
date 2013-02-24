/*
 * wavelike_app.h
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/22/2013
 */
 
#pragma once

#include <SDL2/SDL.h>
#include "display.h"

namespace zdev {

class WavelikeApp {
public:
    WavelikeApp(int argc = 0, const char **argv = nullptr);
    WavelikeApp(const WavelikeApp&) = delete;
    ~WavelikeApp();
    
    void run();

protected:
    void _change_resources_dir();

protected:
    int _argc;
    const char **_argv;
    bool _running;
    Display _display;
};
    
} // namespace
