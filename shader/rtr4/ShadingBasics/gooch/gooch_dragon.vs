#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec3 FragNormal;
out vec3 outPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    vec4 tran = model * vec4(aPos, 1.0);
    outPos = vec3(tran.x, tran.y, tran.z);
    FragNormal = mat3(transpose(inverse(model))) * aNormal;
}