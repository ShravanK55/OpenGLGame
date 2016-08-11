#pragma once
#include <string>
#include <vector>
#include <GL/glew.h>
#include <GLM/glm.hpp>
#include "tinyxml2.h"

class Input;
class SpriteBatch;
class EntityManager;
class EntityFactory;
class Tile;
class Tileset;

struct Layer
{
	std::vector<Tile*> tiles;
};

class Scene2D
{
public:
	Scene2D();
	virtual ~Scene2D();

	virtual void LoadScene(const std::string& mapName);

	void HandleInput(Input* input);
	void Update(GLfloat elapsedTime);
	void Draw(SpriteBatch* spriteBatch);

protected:
	EntityFactory* entityFactory;
	EntityManager* entityManager;

	glm::vec2 levelSize;
	glm::vec2 tileSize;

	std::vector<Tileset*> tilesets;
	std::vector<Layer*> layers;

	virtual void LoadEntity(tinyxml2::XMLElement* entityNode);
};
