#pragma once
#include "GameObject.h"

class Tileset;

class Tile : public GameObject
{
public:
	Tile();
	Tile(Tileset* tileset, glm::vec2 position, glm::vec2 size, GLfloat rotation, GLfloat scale, glm::vec2 tilesetPosition);
	virtual ~Tile();

	virtual void Update(GLfloat elapsedTime);
	virtual void Draw();
};

