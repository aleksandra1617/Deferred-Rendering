#version 430

in vec3 vertex_position; //this is light position

uniform mat4 model_xform;
uniform mat4 projection_view_xform;


void main(void)
{
    gl_Position = projection_view_xform * model_xform * vec4(vertex_position, 1.0); //gl_Position 
}
