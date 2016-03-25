#include "Texture.h"



Texture::Texture() :
	width(0), height(0), internalFormat(GL_RGBA), imageFormat(GL_RGBA),
	wrapS(GL_REPEAT), wrapT(GL_REPEAT), filterMinimize(GL_NEAREST), filterMagnify(GL_NEAREST),
	textureID(0)
{
	glGenTextures(1, &textureID);
}

Texture::~Texture() {}

GLuint Texture::GetInternalFormat() { return internalFormat; }
GLuint Texture::GetImageFormat() { return imageFormat; }
GLuint Texture::GetWidth() { return width; }
GLuint Texture::GetHeight() { return height; }
GLuint Texture::GetID() { return textureID; }

void Texture::SetInternalFormat(GLuint format) { internalFormat = format; }
void Texture::SetImageFormat(GLuint format) { imageFormat = format; }

void Texture::Generate(unsigned char* source, int width, int height)
{
	this->width = width;
	this->height = height;

	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, imageFormat, GL_UNSIGNED_BYTE, source);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filterMinimize);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filterMagnify);

	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, textureID);
}
