/*
 * background_frag.glsl
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 02/24/2013
 */

uniform vec4 begin_color;
uniform vec4 end_color;

void main()
{
    gl_FragColor = mix(begin_color, end_color, gl_PointCoord.y);
}
