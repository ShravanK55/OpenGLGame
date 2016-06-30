#pragma once
#include "GameObject.h"


class Character : public GameObject
{
public:
	Character();
	Character(glm::vec2 spawnPoint, glm::vec2 size, GLfloat rotation, GLfloat scale);
	virtual ~Character();

	virtual void HandleInput(Input* input);
	virtual void Update(GLfloat elapsedTime);
	virtual void Draw();
};

