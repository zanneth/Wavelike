/*
 * utility.cpp
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 01/20/2013
 */
 
#include "utility.h"

namespace zdev {

Matrix4f Util::identity_matrix()
{
    return {
        {1.f, 0.f, 0.f, 0.f,
        0.f, 1.f, 0.f, 0.f,
        0.f, 0.f, 1.f, 0.f,
        0.f, 0.f, 0.f, 1.f}
    };
}

Matrix4f Util::ortho_matrix(GLfloat left,
                            GLfloat right,
                            GLfloat bottom,
                            GLfloat top,
                            GLfloat near,
                            GLfloat far)
{
    GLfloat m11 = 2.f / (right - left);
    GLfloat m14 = -((right + left) / (right - left));
    GLfloat m22 = 2.f / (top - bottom);
    GLfloat m24 = -((top + bottom) / (top - bottom));
    GLfloat m33 = -2.f / (far - near);
    GLfloat m34 = -((far + near) / (far - near));
    
    return {
        {m11, 0.f, 0.f, m14,
        0.f, m22, 0.f, m24,
        0.f, 0.f, m33, m34,
        0.f, 0.f, 0.f, 1.f}
    };
}

} // namespace julia
