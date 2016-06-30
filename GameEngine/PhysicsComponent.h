#pragma once
#include "Component.h"

class PhysicsComponent : public Component
{
public:
	PhysicsComponent() :
		Component("Physics")
	{}

	PhysicsComponent(Entity* owner) :
		Component(owner, "Physics")
	{}

	virtual ~PhysicsComponent() {}

	virtual void Update(GLfloat elapsedTime) {}
};
