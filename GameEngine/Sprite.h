#pragma once
#include "ResourceManager.h"


class Sprite
{
public:
	Sprite();
	Sprite(const GLchar* filePath, const GLchar* name, const glm::vec2& position, const glm::vec2& size, GLboolean alpha = false);
	virtual ~Sprite();

	// Loads a sprite texture from the specified file path.
	void Load(const GLchar* filePath, const GLchar* name, GLboolean alpha = false);

	glm::vec2 GetSize() const;
	Texture GetTexture() const;

	// Function to pass the sprite's information to the spritebatch from which it is drawn.
	virtual void Draw(glm::vec2 position);
	virtual void Draw(glm::vec2 position, GLfloat rotation);
	virtual void Draw(glm::vec2 position, GLfloat rotation, GLfloat scale);

	// Function to update the sprite.
	virtual void Update(GLfloat elapsedTime);

protected:
	glm::vec2 spriteSize;
	Texture* texture;
};
