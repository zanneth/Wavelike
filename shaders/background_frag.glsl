/*
 * background_frag.glsl
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/24/2013
 */

uniform vec4 begin_color;
uniform vec4 end_color;
uniform vec2 viewport_size;

void main()
{
    float normalized_y = gl_FragCoord.y / viewport_size.y;
    gl_FragColor = mix(end_color, begin_color, normalized_y);
}
