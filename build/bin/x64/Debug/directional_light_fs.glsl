//Quad mesh rendered with the directional light & the gbuffer data
#version 430

uniform vec3 camPos;

//G-Buffer Data
uniform sampler2DRect sampler_world_position;
uniform sampler2DRect sampler_world_normal;
uniform sampler2DRect sampler_diff;
uniform sampler2DRect sampler_spec;

uniform vec3 direction;//Light direction 

layout(location = 0) out vec3 reflected_light;

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
	vec3 LP = vec3(0, 10, 0);

    // Fetching Worldspace Normal
    vec3 texel_N = texelFetch(sampler_world_normal, ivec2(gl_FragCoord.xy)).rgb; //gl_FragCoord screen coordinates
    vec3 N = normalize(texel_N);

    //Fetching Worldspace Posititon
    vec3 P = texelFetch(sampler_world_position, ivec2(gl_FragCoord.xy)).rgb;

	//Fetching diffused
	vec3 diffTexColouring = texelFetch(sampler_diff, ivec2(gl_FragCoord.xy)).rgb;

	//Fetching specular
	vec3 specTexColouring = texelFetch(sampler_spec, ivec2(gl_FragCoord.xy)).rgb;

    //DIFFUSED LIGHT
    //vec3 L = normalize(LP - P);
	vec3 L = normalize(direction);
    vec3 diffused = diffTexColouring * max(dot(N, L), 0.0); //kd*(L.N)

    //SPECULAR LIGHT
    vec3 r = reflect(-L, N);
    vec3 Rv = normalize(camPos - P); 
    vec3 specular = specTexColouring * pow(max(dot(r, Rv), 0.0), 64);

    //ATTENUATION 
    float fd = CalculateAttenuation(P, LP);

    //PHONG
    vec3 phong = fd * (diffused + specular);

	//TODO: if lit
    reflected_light = phong;

	//TODO: else if in shadow -> reflected_light = vec3(0,0,0);
}
