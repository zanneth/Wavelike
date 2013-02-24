/*
 * projection_vertex.glsl
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/24/2013
 */

uniform mat4 projection;
uniform mat4 modelview;

attribute vec4 position;

void main()
{
    gl_Position = projection * modelview * position;
}
