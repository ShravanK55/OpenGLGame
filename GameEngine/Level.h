#pragma once
#include <GLM/glm.hpp>
#include <string>
#include <sstream>
#include "Tile.h"

struct Layer
{
	std::vector<Tile*> tiles;
};

class Level
{
public:
	Level();
	Level(const std::string& levelName);
	~Level();

private:
	std::string levelName;

	glm::vec2 playerSpawnPoint;

	glm::vec2 levelSize;
	glm::vec2 tileSize;

	std::vector<Tileset*> tilesets;
	std::vector<Layer*> layers;

	void LoadLevel(const std::string& mapName);
};

