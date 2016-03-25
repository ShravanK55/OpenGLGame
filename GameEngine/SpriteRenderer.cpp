#include "SpriteRenderer.h"


SpriteRenderer::SpriteRenderer() {}

SpriteRenderer::SpriteRenderer(Shader& shader)
{
	this->shader = shader;
	InitRenderData();
}

SpriteRenderer::~SpriteRenderer()
{
	glDeleteVertexArrays(1, &quadVAO);
}

void SpriteRenderer::DrawSprite(Texture texture, glm::vec2 position, glm::vec2 size, GLfloat scale, GLfloat rotate, glm::vec3 color)
{
	shader.Use();
	glm::mat4 model;

	model = glm::translate(model, glm::vec3(position.x, position.y, 0.0f));

	model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
	model = glm::rotate(model, rotate, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

	model = glm::scale(model, glm::vec3(size.x * scale, size.y * scale, 1.0f));

	shader.SetMatrix4("model", model);
	shader.SetVector3f("spriteColor", color);

	glActiveTexture(GL_TEXTURE0);
	texture.Bind();

	glBindVertexArray(quadVAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void SpriteRenderer::DrawSpriteSheet(Texture texture, glm::vec2 position, glm::vec2 size, GLint frameIndex)
{
	shader.Use();

	glm::mat4 model;
	model = glm::translate(model, glm::vec3(position.x, position.y, 0.0f));
	model = glm::scale(model, glm::vec3(size.x, size.y, 1.0f));

	shader.SetMatrix4("model", model);
	shader.SetVector3f("spriteColor", glm::vec3(1.0f));

	GLfloat tw = size.x / texture.GetWidth();
	GLfloat th = size.y / texture.GetHeight();
	GLint numPerRow = texture.GetWidth() / size.x;
	GLfloat tx = (frameIndex % numPerRow) * tw;
	GLfloat ty = (frameIndex / numPerRow + 1) * th;

	GLuint VBO;
	GLfloat vertices[] = {
		0.0f, 1.0f, tx,		 ty + th,
		1.0f, 0.0f, tx + tw, ty,
		0.0f, 0.0f, tx,		 ty,

		0.0f, 1.0f, tx,		 ty + th,
		1.0f, 1.0f, tx + tw, ty + th,
		1.0f, 0.0f, tx + tw, ty
	};

	glGenBuffers(1, &VBO);

	glBindVertexArray(quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GL_FLOAT), (GLvoid*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glActiveTexture(GL_TEXTURE0);
	texture.Bind();

	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void SpriteRenderer::SetShader(Shader shader) {	this->shader = shader; }

void SpriteRenderer::InitRenderData()
{
	GLuint VBO;
	GLfloat vertices[] = {
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};

	glGenVertexArrays(1, &quadVAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(quadVAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GL_FLOAT), (GLvoid*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
