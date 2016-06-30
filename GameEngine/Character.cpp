#include "Character.h"


Character::Character() :
	GameObject()
{}

Character::Character(glm::vec2 spawnPoint, glm::vec2 size, GLfloat rotation, GLfloat scale) :
	GameObject(spawnPoint, size, rotation, scale)
{}

Character::~Character() {}


void Character::HandleInput(Input* input)
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->HandleInput(input);
	}
}

void Character::Update(GLfloat elapsedTime)
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->Update(elapsedTime);
	}
}

void Character::Draw()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->Draw();
	}
}
