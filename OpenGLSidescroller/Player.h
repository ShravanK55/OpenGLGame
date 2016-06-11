#pragma once
#include <GLM/glm.hpp>
#include "GameObject.h"


class Player : public GameObject
{
public:
	Player(glm::vec2 spawnPoint, glm::vec2 size);
	~Player();

	void HandleInput(Input* input);
	void Update(GLfloat elapsedTime);
	void Draw();
};