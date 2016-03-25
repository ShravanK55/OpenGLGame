#include "ResourceManager.h"


std::map<std::string, Shader> ResourceManager::shaders;
std::map<std::string, Texture> ResourceManager::textures;

ResourceManager::ResourceManager() {}
ResourceManager::~ResourceManager() {}

Shader ResourceManager::GetShader(std::string name) { return shaders[name]; }
Texture ResourceManager::GetTexture(std::string name) { return textures[name]; }


Shader ResourceManager::LoadShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile, std::string name)
{
	shaders[name] = LoadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
	return shaders[name];
}

Shader ResourceManager::LoadShaderFromFile(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile)
{
	// Vertex Shader
	const GLchar* vShaderSource;
	std::string vertexShaderCode;
	std::ifstream vertexShaderStream(vShaderFile, std::ios::in);
	if (vertexShaderStream.is_open())
	{
		std::string line = "";
		while (std::getline(vertexShaderStream, line))
		{
			vertexShaderCode += "\n" + line;
		}
		vertexShaderStream.close();
	}
	else
		std::cout << "Could not access vertex shader!\n";

	vShaderSource = vertexShaderCode.c_str();

	// Fragment Shader
	const GLchar* fShaderSource;
	std::string fragmentShaderCode;
	std::ifstream fragmentShaderStream(fShaderFile, std::ios::in);
	if (fragmentShaderStream.is_open())
	{
		std::string line = "";
		while (std::getline(fragmentShaderStream, line))
		{
			fragmentShaderCode += "\n" + line;
		}
		fragmentShaderStream.close();
	}
	else
		std::cout << "Could not access fragment shader!\n";

	fShaderSource = fragmentShaderCode.c_str();

	// Geometry Shader
	const GLchar* gShaderSource = NULL;
	if (gShaderFile != nullptr)
	{
		std::string geometryShaderCode;
		std::ifstream geometryShaderStream(gShaderFile, std::ios::in);
		if (geometryShaderStream.is_open())
		{
			std::string line = "";
			while (std::getline(geometryShaderStream, line))
			{
				geometryShaderCode += "\n" + line;
			}
			geometryShaderStream.close();
		}
		else
			std::cout << "Could not access geometry shader!\n";

		gShaderSource = geometryShaderCode.c_str();
	}

	Shader shader;
	shader.Compile(vShaderSource, fShaderSource, gShaderSource);

	return shader;
}

Texture ResourceManager::LoadTexture(const GLchar* textureFile, GLboolean alpha, std::string name)
{
	auto mit = textures.find(name);

	if (mit == textures.end())
	{
		textures[name] = LoadTextureFromFile(textureFile, alpha);
	}

	return textures[name];
}

Texture ResourceManager::LoadTextureFromFile(const GLchar* textureFile, GLboolean alpha)
{
	Texture texture;

	if (!alpha)
	{
		texture.SetImageFormat(GL_RGB);
		texture.SetInternalFormat(GL_RGB);
	}

	int width, height;
	unsigned char* image = SOIL_load_image(textureFile, &width, &height, 0, texture.GetImageFormat() == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
	texture.Generate(image, width, height);
	SOIL_free_image_data(image);

	return texture;
}

void ResourceManager::Clear()
{
}
