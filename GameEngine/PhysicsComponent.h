#pragma once
#include <GLM/glm.hpp>
#include "Component.h"

class UpdateComponent : public Component
{
public:
	UpdateComponent() {}
	UpdateComponent(Entity* owner) :
		Component(owner)
	{}
	virtual ~UpdateComponent() {}

	virtual void Update(GLfloat elapsedTime) {}

private:
	glm::vec2 position;
};
