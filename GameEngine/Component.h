#pragma once
#include <string>
#include "Input.h"

class Entity;

class Component
{
public:
	Component();
	Component(std::string tag);
	virtual ~Component() {}
	
	std::string GetTag() const;
	void SetOwner(Entity* owner);

	virtual void HandleInput(Input* input);
	virtual void Update(GLfloat elapsedTime) = 0;
	virtual void Draw();

protected:
	Entity* owner;

	Component(Entity* owner);
	Component(Entity* owner, std::string tag);

private:
	std::string tag;
};

