#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 1) uniform sampler2D textureSampler; 

layout(location = 0) in vec3 outNormal;
layout(location = 1) in vec3 lightDir[3];
layout(location = 4) in vec3 eyeDir;
layout(location = 5) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

void main() { 
	vec4 ks[3] = vec4[] (vec4(0.4, 0.0, 0.0, 0.0), vec4(0.0, 0.4, 0.0, 0.0), vec4(0.0, 0.0, 0.4, 0.0));
	vec4 kd[3] = vec4[] (vec4(1.0, 0.0, 0.0, 0.0), vec4(0.0, 1.0, 0.0, 0.0), vec4(0.0, 0.0, 1.0, 0.0));
	vec4 kt = texture(textureSampler, fragTexCoord);

	vec4 ka = 0.1 * kt;

	float diff[3];
	vec3 reflection[3];
	float spec[3];

	for(int i = 0; i < 3; ++i){
		diff[i]= max(dot(outNormal, lightDir[i]), 0.0);

		/// Reflection is based incedent which means a vector from the light source not the direction to the light source
		reflection[i] = normalize(reflect(-lightDir[i], outNormal));
		spec[i] = max(dot(eyeDir, reflection[i]), 0.0);

		
		spec[i] = pow(spec[i], 14.0);
	}

	outColor = ka;
	for(int i = 0; i < 3; ++i){
		outColor += (diff[i] * kd[i] * kt) + (spec[i] * ks[i]);
	}
} 

