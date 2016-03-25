#pragma once

#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>

#include "Globals.h"
#include "Texture.h"
#include "Shader.h"
#include "Vertex.h"

class SpriteRenderer
{
public:
	SpriteRenderer();
	SpriteRenderer(Shader& shader);
	~SpriteRenderer();

	void DrawSprite(Texture texture, glm::vec2 position, glm::vec2 size, GLfloat scale = 1.0f, GLfloat rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
	void DrawSpriteSheet(Texture texture, glm::vec2 position, glm::vec2 size, GLint frameIndex);

	void SetShader(Shader shader);

private:
	Shader shader;
	GLuint quadVAO;

	void InitRenderData();
};

