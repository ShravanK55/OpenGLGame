#pragma once
#include <GLM/glm.hpp>
#include "Entity.h"

class GameObject : public Entity
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update(float elapsedTime) = 0;

private:
	glm::vec2 position;
};
