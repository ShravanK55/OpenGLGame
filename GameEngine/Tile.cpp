#include "Tile.h"
#include "TileGraphicsComponent.h"


Tile::Tile() :
	GameObject()
{}

Tile::Tile(glm::vec2 position, glm::vec2 size, GLfloat rotation, GLfloat scale, glm::vec2 tilesetPosition) :
	GameObject(position, size, rotation, scale)
{
	Entity::AddComponent(new TileGraphicsComponent());
}

Tile::~Tile() {}


void Tile::Update(GLfloat elapsedTime)
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->Update(elapsedTime);
	}
}

void Tile::Draw()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->Draw();
	}
}
