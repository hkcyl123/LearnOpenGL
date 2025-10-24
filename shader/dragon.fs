#version 330 core

out  vec4     FragColor;

in   vec3     FragNormal;
in   vec3     FragPos;


uniform  vec3 lightPositions;
uniform  vec3 lightColors;

vec3 light(const  float specular_strength, const  float shininess) {
    vec3  light_direction = normalize(lightPositions - FragPos);
    float specular        = pow(max(dot(lightPositions, reflect(-light_direction, FragNormal)), 0.0f), shininess);
    float light_resultant = max(dot(FragNormal, light_direction), 0.0f);

    return vec3(light_resultant) + (specular_strength * vec3(specular));
}

void main() {
    vec3 light1 = light(10.0f, 32.0f);
    FragColor = vec4(lightColors * light1, 0.0f);
}