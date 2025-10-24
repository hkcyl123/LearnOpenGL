#version 330 core

out vec4 FragColor;

in vec3 FragNormal;
in vec3 outPos;

uniform vec3 lightPositions;
uniform vec3 lightColors;
uniform vec3 camPos;

vec3 Gooch() {

    vec3 lightDir= normalize(lightPositions-outPos);
	vec3 viewDir= normalize(camPos-outPos);

	vec3 cool = vec3(0.0, 0.0, 0.55) + 0.25 * lightColors;
	vec3 warm = vec3(0.3, 0.3, 0.0) + 0.25 * lightColors;
	float t = (dot(FragNormal, lightDir) + 1) / 2;
	vec3 r = 2 * dot(FragNormal, lightDir) * FragNormal - lightDir;
	float s = clamp((100* dot(r, viewDir) - 97), 0, 1);
    vec3 finalColor = s * vec3(1.0, 1.0, 1.0) + (1-s) * ((t) * warm + (1 - t) * cool);
	return finalColor;
}



void main() {
    FragColor = vec4(Gooch(), 1.0f);
}