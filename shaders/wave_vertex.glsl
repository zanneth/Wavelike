/*
 * wave_vertex.glsl
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/24/2013
 */

uniform mat4 projection;
uniform mat4 modelview;
uniform float time;

attribute vec4 position;

const float PI = 3.14159265358979;

float wave_function(float x)
{
    const float amp = 0.2;
    
    float x1 = amp * sin(x - time);
    float x2 = amp * cos(x - time);
    float x3 = pow(cos(x / PI), 2.0);
    
    return (x1 + x2 + x3) - 1.0;
}

void main()
{
    vec4 projected_position = projection * modelview * position;
    projected_position.y = projected_position.y + wave_function(projected_position.x);
    gl_Position = projected_position;
}
