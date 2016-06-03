#pragma once
#include <GLM/glm.hpp>
#include "Component.h"

class PhysicsComponent : public Component
{
public:
	PhysicsComponent() :
		position(glm::vec2(0, 0)),
		size(glm::vec2(0, 0))
	{}

	PhysicsComponent(Entity* owner) :
		Component(owner),
		position(glm::vec2(0, 0)),
		size(glm::vec2(0, 0))
	{}

	PhysicsComponent(Entity* owner, glm::vec2 spawnPoint, glm::vec2 size) :
		Component(owner),
		position(spawnPoint),
		size(size)
	{}

	virtual ~PhysicsComponent() {}

	glm::vec2 GetPosition() const { return position; }
	glm::vec2 GetSize() const { return size; }

	virtual void Update(GLfloat elapsedTime) {}

protected:
	glm::vec2 position;
	glm::vec2 size;
};
