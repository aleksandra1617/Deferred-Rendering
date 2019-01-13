#version 430

layout(location = 0) out vec3 fragment_position;
layout(location = 1) out vec3 fragment_normal;
layout(location = 2) out vec3 diffused_colour;
layout(location = 3) out vec3 specular_colour;

in vec3 varying_position;
in vec3 varying_normal;
in vec3 varying_diff_col;
in vec3 varying_spec_col;

void main(void)
{
	//This will be attached to the g-buffer position and normal tex 
	fragment_position = varying_position;
	fragment_normal = varying_normal;
	diffused_colour = varying_diff_col;
	specular_colour = varying_spec_col;

	//TODO: add material colour not ambient colour without it the sponza will be gray scale 
	//fragment_colour = vec4(0.2, 1, 1, 1.0); //not used
}

