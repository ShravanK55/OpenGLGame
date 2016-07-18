#include "Tileset.h"

Tileset::Tileset() : Sprite(), firstGid(-1), tileSize(glm::vec2()) {}

Tileset::Tileset(const GLchar* filePath, const GLchar* name, int firstGid, const glm::vec2& tilesetSize, const glm::vec2& tileSize,
				 GLboolean alpha) :
	Sprite(filePath, name, tilesetSize, alpha),
	firstGid(firstGid),
	tileSize(tileSize)
{}

Tileset::~Tileset() {}

void Tileset::Update(GLfloat elapsedTime) {}

void Tileset::Draw(glm::vec2 position, GLfloat rotation, GLfloat scale, glm::vec2 positionOnTexture)
{
	Sprite::DrawPortion(position, tileSize, rotation, scale, positionOnTexture, tileSize);
}