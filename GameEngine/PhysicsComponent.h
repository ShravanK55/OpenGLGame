#pragma once
#include "Component.h"

class PhysicsComponent : public Component
{
public:
	PhysicsComponent() :
		Component(nullptr)
	{}

	PhysicsComponent(Entity* owner) :
		Component(owner)
	{}

	virtual ~PhysicsComponent() {}

	virtual void Update(GLfloat elapsedTime) {}
};
