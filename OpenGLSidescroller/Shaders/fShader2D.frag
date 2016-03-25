#version 330 core
in vec4 fragmentColor;
in vec2 fragmentUV;

out vec4 color;

uniform sampler2D image;

void main()
{
	color = fragmentColor * texture(image, fragmentUV);
}