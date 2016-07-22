#include "Tile.h"
#include "Tileset.h"


Tile::Tile() :
	transformComponent(nullptr),
	tileset(nullptr),
	tilesetPosition(glm::vec2(0, 0))
{}

Tile::Tile(Tileset* tileset, glm::vec2 position, GLfloat rotation, GLfloat scale, glm::vec2 tilesetPosition) :
	tileset(tileset),
	tilesetPosition(tilesetPosition)
{
	transformComponent = new TransformComponent(position, tileset->tileSize, rotation, scale);
}

Tile::~Tile() {}

void Tile::Update(GLfloat elapsedTime) {}

void Tile::Draw(SpriteBatch* spriteBatch)
{
	tileset->Draw(spriteBatch, transformComponent->GetPosition(), transformComponent->GetRotation(), transformComponent->GetScale(), tilesetPosition);
}
