#pragma once
#include <GL/glew.h>

struct Position
{
	GLfloat x, y;
};

struct Color
{
	GLfloat r, g, b, a;
};

struct UV
{
	GLfloat u, v;
};

struct Vertex
{
	Position position;
	Color color;
	UV uv;
	
	void SetPosition(GLfloat x, GLfloat y)
	{
		position.x = x;
		position.y = y;
	}

	void SetColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
	{
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;
	}

	void SetUV(GLfloat u, GLfloat v)
	{
		uv.u = u;
		uv.v = v;
	}
};