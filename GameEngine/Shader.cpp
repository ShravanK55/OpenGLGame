#include "Shader.h"



Shader::Shader() {}
Shader::~Shader() {}

GLint Shader::GetProgram() const { return programID; }

Shader& Shader::Use()
{
	glUseProgram(programID);
	return *this;
}

void Shader::Compile(const GLchar* vShaderSource, const GLchar* fShaderSource, const GLchar* gShaderSource)
{
	GLuint vShader = 0;
	GLuint fShader = 0;
	GLuint gShader = 0;

	vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, &vShaderSource, NULL);
	glCompileShader(vShader);
	CheckCompileErrors(vShader, "VERTEX");


	fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShader, 1, &fShaderSource, NULL);
	glCompileShader(fShader);
	CheckCompileErrors(fShader, "FRAGMENT");


	if (gShaderSource != nullptr)
	{
		gShader = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(gShader, 1, &gShaderSource, NULL);
		glCompileShader(gShader);
		CheckCompileErrors(gShader, "GEOMETRY");
	}

	programID = glCreateProgram();
	glAttachShader(programID, vShader);
	glAttachShader(programID, fShader);
	if (gShaderSource != nullptr)
		glAttachShader(programID, gShader);
	glLinkProgram(programID);
	CheckCompileErrors(programID, "PROGRAM");

	glDeleteShader(vShader);
	glDeleteShader(fShader);
	if (gShaderSource != nullptr)
		glDeleteShader(gShader);
}

void Shader::CheckCompileErrors(GLuint object, std::string type)
{
	GLint success;
	GLchar infoLog[1024];

	if (type == "VERTEX")
	{
		glGetShaderiv(object, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(object, 1024, NULL, infoLog);
			std::cout << "VERTEX SHADER COMPILATION ERROR! INFOLOG:\n" << infoLog << std::endl;
		}
	}

	else if (type == "FRAGMENT")
	{
		glGetShaderiv(object, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(object, 1024, NULL, infoLog);
			std::cout << "FRAGMENT SHADER COMPILATION ERROR! INFOLOG:\n" << infoLog << std::endl;
		}
	}

	else
	{
		glGetProgramiv(object, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(object, 1024, NULL, infoLog);
			std::cout << "SHADER PROGRAM LINKING ERROR! INFOLOG:\n" << infoLog << std::endl;
		}
	}
}

void Shader::SetFloat(const GLchar* name, GLfloat value, GLboolean useShader)
{
	if (useShader)
		Use();
	glUniform1f(glGetUniformLocation(programID, name), value);
}

void Shader::SetInteger(const GLchar* name, GLfloat value, GLboolean useShader)
{
	if (useShader)
		Use();
	glUniform1i(glGetUniformLocation(programID, name), value);
}

void Shader::SetVector2f(const GLchar* name, GLfloat x, GLfloat y, GLboolean useShader)
{
	if (useShader)
		Use();
	glUniform2f(glGetUniformLocation(programID, name), x, y);
}

void Shader::SetVector2f(const GLchar* name, const glm::vec2& value, GLboolean useShader)
{
	if (useShader)
		Use();
	glUniform2f(glGetUniformLocation(programID, name), value.x, value.y);
}

void Shader::SetVector3f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader)
{
	if (useShader)
		Use();
	glUniform3f(glGetUniformLocation(programID, name), x, y, z);
}

void Shader::SetVector3f(const GLchar* name, const glm::vec3& value, GLboolean useShader)
{
	if (useShader)
		Use();
	glUniform3f(glGetUniformLocation(programID, name), value.x, value.y, value.z);
}

void Shader::SetVector4f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader)
{
	if (useShader)
		Use();
	glUniform4f(glGetUniformLocation(programID, name), x, y, z, w);
}

void Shader::SetVector4f(const GLchar* name, const glm::vec4& value, GLboolean useShader)
{
	if (useShader)
		Use();
	glUniform4f(glGetUniformLocation(programID, name), value.x, value.y, value.z, value.w);
}

void Shader::SetMatrix4(const GLchar* name, const glm::mat4& value, GLboolean useShader)
{
	if (useShader)
		Use();
	glUniformMatrix4fv(glGetUniformLocation(programID, name), 1, GL_FALSE, glm::value_ptr(value));
}
