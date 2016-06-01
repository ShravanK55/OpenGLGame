#pragma once
#include "Input.h"
#include "Component.h"

class InputComponent : public Component
{
public:
	InputComponent() {}
	InputComponent(Entity* owner) :
		Component(owner)
	{}
	virtual ~InputComponent() {}

	virtual void Update(GLfloat elapsedTime) {}

	virtual void HandleInput(Input* input) = 0;
};
