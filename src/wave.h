/*
 * wave.h
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/23/2013
 */

#pragma once

#include "layer.h"

namespace zdev {

class Wave : public Layer {
public:
    Wave();
    ~Wave();
    
    void draw() override;
};

} // namespace zdev
