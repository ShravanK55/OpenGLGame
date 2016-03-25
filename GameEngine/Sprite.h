#pragma once
#include <GL/glew.h>

#include "ResourceManager.h"
#include "Texture.h"
#include "SpriteBatch.h"

class Sprite
{
public:
	Sprite();
	Sprite(const GLchar* filePath, const GLchar* name, const glm::vec2& position, const glm::vec2& size, GLboolean alpha = false);
	virtual ~Sprite();

	void Load(const GLchar* filePath, const GLchar* name, GLboolean alpha = false);

	glm::vec2 GetPosition() const;
	glm::vec2 GetSize() const;
	glm::vec4 GetRectangle() const;
	Texture GetTexture() const;

	void SetPosition(glm::vec2 position);

	virtual void Draw();
	virtual void Update(GLfloat elapsedTime);

protected:
	GLfloat posX, posY;
	GLfloat width, height;
	Texture texture;
};

