//Sphere mesh rendered with the point light & the gbuffer data
#version 430
uniform vec3 camPos;

uniform sampler2DRect sampler_world_position;
uniform sampler2DRect sampler_world_normal;
uniform sampler2DRect sampler_diff;
uniform sampler2DRect sampler_spec;

uniform vec3 lightPosition;
uniform vec3 direction;
uniform vec3 intensity;
uniform float lightRange;
uniform float coneAngle;

out vec3 reflected_light;


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
	//float fc = float(dot(-L, direction) < cos(coneAngle));
	float fc = smoothstep(cos(0.5 * radians(coneAngle)), 0, acos(dot(-L, direction)));

	vec3 diffused = diffTexColouring * vec3(max(dot(L, N), 0.0)); //kd*(L.N)

	//SPECULAR LIGHT
	vec3 specTexColouring = texelFetch(sampler_spec, ivec2(gl_FragCoord.xy)).rgb;
	vec3 r = reflect(-L, N);
	vec3 Rv = normalize(camPos - P);
	vec3 specular = specTexColouring * pow(max(dot(r, Rv), 0.0), 64);

	float atten = 1;
	float bias = 0.005;
	vec3 spot_light = vec3(0,0,0);

	if (dot(-L, direction) > cos(0.5 * coneAngle))
	{
		//ATTENUATION 
		float dist = distance(lightPosition, P);
		atten = smoothstep(lightRange, 0, dist);

		vec3 phong = intensity * atten * (diffused + specular);
		spot_light = phong *(1.0 - (1.0 - dot(-L, direction)) * 1.0 / (1.0 - cos(0.5 * coneAngle)));
	}

	reflected_light = spot_light;
}