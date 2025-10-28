#version 330 core

out vec4 FragColor;

in vec3 FragNormal;
in vec3 outPos;

uniform vec3 lightPositions;
uniform vec3 lightColors;
uniform vec3 camPos;

// 环境光 ambient
vec3 La() {
    float ka = 0.3f;
    vec3 Ia = vec3(1.0f, 1.0f, 1.0f);
    return ka * Ia;
}

// 漫反射 diffuse
vec3 Ld(vec3 I, float r, vec3 n, vec3 l) {
    float kd = 0.3f;
    return kd * (I / pow(r, 2)) * max(0, dot(n, l));
}

// 高光 specular
vec3 Ls(vec3 I, float r, vec3 n, vec3 h) {
    float ks = 0.3f;
    int p = 200;
    return ks * (I/ pow(r, 2)) * pow(max(0, dot(n, h)), p);
}

vec3 blinnPhong() {
    vec3 n = normalize(FragNormal);
    vec3 l = normalize(lightPositions - outPos);
    vec3 v = normalize(camPos - outPos);
    vec3 h = normalize(l + v);
    float r = distance(l, outPos);

    return La() + Ld(lightColors, r, n, l) + Ls(lightColors, r, n, h);
}

void main() {
    FragColor = vec4(blinnPhong(), 1.0f);
}