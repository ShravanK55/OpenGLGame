#pragma once
#include <GLM/glm.hpp>
#include "Sprite.h"

class Tileset : public Sprite
{
public:
	Tileset();

	Tileset(const GLchar* filePath, const GLchar* name, int firstGid, const glm::vec2& tilesetSize, const glm::vec2& tileSize,
			GLboolean alpha = false);

	virtual ~Tileset();

	virtual void Update(GLfloat elapsedTime);
	virtual void Draw(glm::vec2 position, GLfloat rotation, GLfloat scale, glm::vec2 positionOnTexture);

private:
	int firstGid;
	glm::vec2 tileSize;
};