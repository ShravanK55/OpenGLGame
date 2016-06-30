#pragma once
#include "Input.h"
#include "Component.h"

class InputComponent : public Component
{
public:
	InputComponent() :
		Component("Input")
	{}
	InputComponent(Entity* owner) :
		Component(owner, "Input")
	{}
	virtual ~InputComponent() {}

	virtual void Update(GLfloat elapsedTime) {}

	virtual void HandleInput(Input* input) = 0;
};
