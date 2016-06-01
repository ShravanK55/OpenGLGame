#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>

class Shader
{
public:
	Shader();
	~Shader();

	// Uses the shader program.
	Shader& Use();

	// Compiles the vertex, fragment and geometry shaders from the specified source code.
	void Compile(const GLchar* vShaderSource, const GLchar* fShaderSource, const GLchar* gShaderSource = nullptr);
	// Checks for errors that occurred in compilation.
	void CheckCompileErrors(GLuint object, std::string type);
	// Returns the shader program ID.
	GLint GetProgram() const;

	void SetFloat(const GLchar* name, GLfloat value, GLboolean useShader = false);
	void SetInteger(const GLchar* name, GLfloat value, GLboolean useShader = false);
	void SetVector2f(const GLchar* name, GLfloat x, GLfloat y, GLboolean useShader = false);
	void SetVector2f(const GLchar* name, const glm::vec2& value, GLboolean useShader = false);
	void SetVector3f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader = false);
	void SetVector3f(const GLchar* name, const glm::vec3& value, GLboolean useShader = false);
	void SetVector4f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader = false);
	void SetVector4f(const GLchar* name, const glm::vec4& value, GLboolean useShader = false);
	void SetMatrix4(const GLchar* name, const glm::mat4& value, GLboolean useShader = false);

private:
	GLint programID;
};

