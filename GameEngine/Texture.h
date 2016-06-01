#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Texture
{
public:
	Texture();
	~Texture();

	// Generates the texture from the source.
	void Generate(unsigned char* source, int width, int height);
	// Binds the texture.
	void Bind() const;

	GLuint GetInternalFormat();
	GLuint GetImageFormat();
	GLuint GetWidth();
	GLuint GetHeight();
	GLuint GetID();

	void SetInternalFormat(GLuint format);
	void SetImageFormat(GLuint format);

private:
	GLuint textureID;
	GLuint width, height;

	GLuint internalFormat;
	GLuint imageFormat;

	GLuint wrapS;
	GLuint wrapT;
	GLuint filterMinimize;
	GLuint filterMagnify;
};

