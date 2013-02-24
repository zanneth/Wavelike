/*
 * shader_program.h
 *
 * Author: Charles Magahern <charles@magahern.com>
 * Date Created: 04/30/2012
 */
 
#pragma once

#include <SDL2/SDL_opengl.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

namespace zdev {

enum VertexAttribute {
    VERTEX_ATTRIB_POSITION,
    VERTEX_ATTRIB_NORMAL,
    VERTEX_ATTRIB_COLOR,
    VERTEX_ATTRIB_TEXCOORD0,
    VERTEX_ATTRIB_TEXCOORD1,
    VERTEX_ATTRIB_COUNT
};

class ShaderProgram {
public:
    ShaderProgram();
    ShaderProgram(const ShaderProgram&) = delete;
    ~ShaderProgram();
    
    GLuint get_program() const { return _program; }
    std::vector<GLuint> get_attached_shaders() const { return _shaders; }
    bool is_linked() const { return _linked; }
    
    static GLuint compile_shader(const char *filename, GLenum type);
    bool attach_shader(GLuint shader);
    bool detach_shader(GLuint shader);
    bool load_shader(const char *filename, GLenum type); // convenience -- compiles and attaches a shader
    
    bool bind_attribute(VertexAttribute attrib, std::string name);
    bool link_program();
    bool use_program();
    
    GLint get_uniform(std::string name);
    
protected:
    GLuint _program;
    std::vector<GLuint> _shaders;
    std::map<GLuint, std::string> _attrib_map;
    std::map<std::string, GLint> _uniform_map;
    bool _linked;
};

typedef std::shared_ptr<ShaderProgram> ShaderProgramRef;

} // namespace julia
