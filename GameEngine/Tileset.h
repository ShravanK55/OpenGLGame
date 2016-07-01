#pragma once
#include <GLM/glm.hpp>
#include "Sprite.h"

class Tileset : public Sprite
{
	Tileset() : Sprite(), firstGid(0), tileSize(glm::vec2()) {}

	Tileset(const GLchar* filePath, const GLchar* name, int firstGid, const glm::vec2& tilesetSize, const glm::vec2& tileSize,
			GLboolean alpha = false) :
		Sprite(filePath, name, tilesetSize, alpha),
		firstGid(firstGid),
		tileSize(tileSize)
	{}

	virtual ~Tileset() {}

private:
	int firstGid;
	glm::vec2 tileSize;
};