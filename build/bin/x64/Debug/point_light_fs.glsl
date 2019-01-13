//Sphere mesh rendered with the point light & the gbuffer data
#version 430
uniform vec3 camPos;

uniform sampler2DRect sampler_world_position;
uniform sampler2DRect sampler_world_normal;
uniform sampler2DRect sampler_diff;
uniform sampler2DRect sampler_spec;

uniform vec3 lightPosition;
uniform float lightRange;

out vec3 reflected_light;

float CalculateAttenuation(vec3 vertPos, vec3 lightPosition)
{
	//Attenuation constants
	const float ATTENUATION_CONSTANT = 1;
	const float ATTENUATION_LINEAR = 0.0;
	const float ATTENUATION_QUADRATIC = 0.0001;

	float d = distance(lightPosition, vertPos);
	float fd = 1.0 / (ATTENUATION_CONSTANT
		+ d * ATTENUATION_LINEAR
		+ d * d * ATTENUATION_QUADRATIC);

	return fd;
}

void main(void)
{
	// Fetching Worldspace Normal
	vec3 texel_N = texelFetch(sampler_world_normal, ivec2(gl_FragCoord.xy)).rgb; //gl_FragCoord screen coordinates
	vec3 N = normalize(texel_N);

	//Fetching Worldspace Posititon
	vec3 P = texelFetch(sampler_world_position, ivec2(gl_FragCoord.xy)).rgb;

	//DIFFUSED LIGHT
	vec3 diffTexColouring = texelFetch(sampler_diff, ivec2(gl_FragCoord.xy)).rgb;
	vec3 L = normalize(lightPosition - P);
	vec3 diffused = diffTexColouring * vec3(max(dot(N, L), 0.0)); //kd*(L.N)

	//SPECULAR LIGHT
	vec3 specTexColouring = texelFetch(sampler_spec, ivec2(gl_FragCoord.xy)).rgb;
	vec3 r = reflect(-L, N);
	vec3 Rv = normalize(camPos - P);
	vec3 specular = specTexColouring * pow(max(dot(r, Rv), 0.0), 64);

	//ATTENUATION 
	float dist = distance(P, lightPosition);
	float atten = smoothstep(lightRange, 0, dist);
	//float atten = CalculateAttenuation(P, lightPosition);

	reflected_light = atten * (diffused + specular);
}