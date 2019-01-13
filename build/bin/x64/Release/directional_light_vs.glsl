#version 430

in vec2 vertex_position; //this is light position

void main(void)
{
    gl_Position = vec4(vertex_position, 0.0, 1.0); //gl_Position Needed to draw quad
}
