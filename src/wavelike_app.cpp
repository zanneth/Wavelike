/*
 * wavelike_app.cpp
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/22/2013
 */
 
#include "wavelike_app.h"
#include <iostream>

namespace zdev {

WavelikeApp::WavelikeApp(int argc, const char **argv) :
    _argc(argc),
    _argv(argv),
    _running(false)
{}

WavelikeApp::~WavelikeApp()
{
    if (_window != nullptr) {
        SDL_DestroyWindow(_window);
    }
}

void WavelikeApp::run()
{
    _running = true;
    SDL_Init(SDL_INIT_VIDEO);
    
    _window = SDL_CreateWindow("Wavelike",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                1024, 768,
                                SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (_window == nullptr) {
        std::cerr << "Could not create SDL window." << std::endl;
        return;
    }
    
    while (_running) {
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
    }
    
    SDL_Quit();
}
    
} // namespace
