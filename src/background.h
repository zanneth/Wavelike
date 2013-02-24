/*
 * background.h
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/23/2013
 */

#pragma once

#include "layer.h"

namespace zdev {

class Background : public Layer {
public:
    Background();
    ~Background();
    
    void draw() override;
};

} // namespace zdev
