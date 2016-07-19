#pragma once
#include "ResourceManager.h"

class SpriteBatch;

class Sprite
{
public:
	Sprite();
	Sprite(const GLchar* filePath, const GLchar* name, const glm::vec2& size, GLboolean alpha = false);
	virtual ~Sprite();

	// Loads a sprite texture from the specified file path.
	virtual void Load(const GLchar* filePath, const GLchar* name, GLboolean alpha = true);

	glm::vec2 GetSize() const;
	Texture GetTexture() const;

	// Function to pass the sprite's information to the spritebatch from which it is drawn.
	virtual void Draw(SpriteBatch* spriteBatch, glm::vec2 position);
	virtual void Draw(SpriteBatch* spriteBatch, glm::vec2 position, GLfloat rotation);
	virtual void Draw(SpriteBatch* spriteBatch, glm::vec2 position, GLfloat rotation, GLfloat scale);

	// Function to pass the sprite's information to spritebatch, wherein only a portion of the sprite's texture is drawn.
	virtual void DrawPortion(SpriteBatch* spriteBatch, glm::vec2 position, glm::vec2 size,
							 glm::vec2 positionOnTexture, glm::vec2 sizeOnTexture);

	virtual void DrawPortion(SpriteBatch* spriteBatch, glm::vec2 position, glm::vec2 size,
							 GLfloat rotation, glm::vec2 positionOnTexture, glm::vec2 sizeOnTexture);

	virtual void DrawPortion(SpriteBatch* spriteBatch, glm::vec2 position, glm::vec2 size,
							 GLfloat rotation, GLfloat scale, glm::vec2 positionOnTexture, glm::vec2 sizeOnTexture);

	// Function to update the sprite.
	virtual void Update(GLfloat elapsedTime);

protected:
	glm::vec2 spriteSize;
	Texture* texture;
};
