#pragma once
#include <GL/glew.h>
#include <GLM/glm.hpp>
#include "TransformComponent.h"

class SpriteBatch;
class Tileset;

class Tile
{
public:
	Tile();
	Tile(Tileset* tileset, glm::vec2 position, GLfloat rotation, GLfloat scale, glm::vec2 tilesetPosition);
	virtual ~Tile();

	virtual void Update(GLfloat elapsedTime);
	virtual void Draw(SpriteBatch* spriteBatch);

private:
	TransformComponent* transformComponent;
	Tileset* tileset;
	glm::vec2 tilesetPosition;
};

