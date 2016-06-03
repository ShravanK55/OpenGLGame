#pragma once
#include "Input.h"

class Entity;

class Component
{
public:
	Component() : owner(NULL) {}
	virtual ~Component() {}
	
	void SetOwner(Entity* owner) { this->owner = owner; }

	virtual void HandleInput(Input* input) {}
	virtual void Update(GLfloat elapsedTime) = 0;
	virtual void Draw() {}

protected:
	Component(Entity* owner) : owner(owner) {}

private:
	Entity* owner;
};

