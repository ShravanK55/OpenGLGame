#pragma once
#include "GraphicsComponent.h"

class Tileset;
class Tile;

class TileGraphicsComponent : public GraphicsComponent
{
public:
	TileGraphicsComponent();
	TileGraphicsComponent(Entity* owner);
	TileGraphicsComponent(Entity* owner, Tileset* tileset, const glm::vec2& tilesetPosition);
	~TileGraphicsComponent();

	Tile* GetOwner() const;

	virtual void Update(GLfloat elapsedTime);
	virtual void Draw();

private:
	Tileset* tileset;
	glm::vec2 tilesetPosition;
};

