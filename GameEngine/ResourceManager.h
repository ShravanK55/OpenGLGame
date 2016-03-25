#pragma once
#include <iostream>
#include <string>
#include <map>

#include <fstream>
#include <sstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <SOIL/SOIL.h>

#include "Shader.h"
#include "Texture.h"

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	static Shader LoadShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile, std::string name);
	static Shader GetShader(std::string name);

	static Texture LoadTexture(const GLchar* textureFile, GLboolean alpha, std::string name);
	static Texture GetTexture(std::string name);

	static void Clear();

private:
	static std::map<std::string, Shader> shaders;
	static std::map<std::string, Texture> textures;

	static Shader LoadShaderFromFile(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile = nullptr);
	static Texture LoadTextureFromFile(const GLchar* textureFile, GLboolean alpha);
};

