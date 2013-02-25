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
    
    _change_resources_dir();
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
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                        _display.set_viewport_size(std::make_pair(event.window.data1, event.window.data2));
                    }
                    break;
                default:
                    break;
            }
        }
        
        // sleep so that we update on an interval
        usleep(16667);
    }
    
    SDL_Quit();
}

// internal

void WavelikeApp::_change_resources_dir()
{
#ifdef __APPLE__
#include "CoreFoundation/CoreFoundation.h"
#endif
#ifdef __APPLE__
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
    char path[PATH_MAX];
    if (!CFURLGetFileSystemRepresentation(resourcesURL, TRUE, (UInt8 *)path, PATH_MAX))
    {
        // error!
    }
    CFRelease(resourcesURL);
    chdir(path);
#endif
}
    
} // namespace
