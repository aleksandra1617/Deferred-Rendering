#version 430

// Writing into the g buffer/ RENDER SPONZA NORMALLY
layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 vertex_normal;

//layout(location = 2) reserved for tex coordinates

layout(location = 3) in mat4 model_xform;
layout(location = 7) in vec3 diffused_col;
layout(location = 8) in vec3 specular_col;

uniform mat4 projection_view_xform;

out vec3 varying_normal;
out vec3 varying_position;
out vec3 varying_diff_col;
out vec3 varying_spec_col;


void main(void)
{
	//vec4 normal_colour = vec4(vertex_normal, 0);
	//varying_normal = model_xform * normal_colour;
	//varying_position = mat4x3(model_xform) * vec4(vertex_position, 1.0); 

	//gl_Position = projection_view_xform * model_xform * vec4(vertex_position, 1.0); 

	varying_normal = mat3(model_xform) * normalize(vertex_normal);
	varying_position = mat4x3(model_xform) * vec4(vertex_position, 1.0);
	varying_diff_col = diffused_col;
	varying_spec_col = specular_col;

	gl_Position = projection_view_xform * model_xform * vec4(vertex_position, 1.0);
}
