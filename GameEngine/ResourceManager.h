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

	// Loads vertex, fragment and geometry shader from the specified filepath.
	static Shader LoadShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile, std::string name);
	static Shader GetShader(std::string name);

	// Loads a texture from the specified filepath.
	static Texture LoadTexture(const GLchar* textureFile, GLboolean alpha, std::string name);
	static Texture GetTexture(std::string name);

	static void Clear();

private:
	static std::map<std::string, Shader> shaders;
	static std::map<std::string, Texture> textures;

	// Accesses the file from the filepath, and loads the shader code from it.
	static Shader LoadShaderFromFile(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile = nullptr);
	// Accesses the file from the filepath, and loads the texture from it.
	static Texture LoadTextureFromFile(const GLchar* textureFile, GLboolean alpha);
};

