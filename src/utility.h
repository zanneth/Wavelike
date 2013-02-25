/*
 * utility.h
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 01/20/2013
 */
 
#pragma once

#include <array>
#include <SDL2/SDL_opengl.h>

namespace zdev {

typedef std::array<GLfloat, 4*4> Matrix4f;
typedef std::array<GLfloat, 4> Vertex4f;

class Util {
public:
    static const Matrix4f& identity_matrix();
    static Matrix4f ortho_matrix(GLfloat left,
                                 GLfloat right,
                                 GLfloat bottom,
                                 GLfloat top,
                                 GLfloat near,
                                 GLfloat far);
};

} // namespace julia
