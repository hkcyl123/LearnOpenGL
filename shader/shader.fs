#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D DIFFUSE1;

void main()
{
    FragColor = texture(DIFFUSE1, TexCoords);
}