/*
 * main.cpp
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/22/2013
 */

#include "wavelike_app.h"

int main(int argc, const char **argv)
{
    using namespace zdev;
    
    WavelikeApp app(argc, argv);
    app.run();
    
    return 0;
}
