#pragma once
#include <GL/glew.h>

class Entity;

class Component
{
public:
	Component() : owner(NULL) {}
	virtual ~Component() {}
	
	void SetOwner(Entity* owner) { this->owner = owner; }

	virtual void Update(GLfloat elapsedTime) = 0;

protected:
	Component(Entity* owner) : owner(owner) {}

private:
	Entity* owner;
};

