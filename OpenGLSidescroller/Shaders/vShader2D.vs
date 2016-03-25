#version 330 core
layout (location = 0) in vec2 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 uv;

out vec4 fragmentColor;
out vec2 fragmentUV;

uniform mat4 projection;

void main()
{
	gl_Position = projection * vec4(position.xy, 0.0, 1.0);
	fragmentColor = color;
	fragmentUV = vec2(uv.x, 1.0 - uv.y);
}