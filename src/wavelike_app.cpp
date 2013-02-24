/*
 * wavelike_app.cpp
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/22/2013
 */
 
#include "wavelike_app.h"
#include <iostream>
#include <unistd.h>

namespace zdev {

WavelikeApp::WavelikeApp(int argc, const char **argv) :
    _argc(argc),
    _argv(argv),
    _running(false)
{}

WavelikeApp::~WavelikeApp()
{}

void WavelikeApp::run()
{
    SDL_Init(SDL_INIT_VIDEO);
    
    _display.initialize();
    
    _running = true;
    while (_running) {
        // update the display
        _display.update();
        
        // update input
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    _running = false;
                    break;
                default:
                    break;
            }
        }
        
        // sleep so that we update on an interval
        usleep(1000);
    }
    
    SDL_Quit();
}
    
} // namespace
