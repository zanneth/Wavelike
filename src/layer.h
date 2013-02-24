/*
 * layer.h
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/24/2013
 */

#pragma once

#include <memory>

namespace zdev {

class Layer {
public:
    virtual void draw();
};

typedef std::shared_ptr<Layer> LayerRef;

} // namespace zdev
