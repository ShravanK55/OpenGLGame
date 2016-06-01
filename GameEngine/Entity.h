#pragma once
#include <vector>
#include <GL/glew.h>
#include "Component.h"


class Entity
{
public:
	virtual ~Entity() {}
	virtual void Update(GLfloat elapsedTime) = 0;
	virtual void AddComponent(Component* component)
	{
		component->SetOwner(this);
		components.push_back(component);
	}

protected:
	Entity() {}

private:
	std::vector<Component*> components;
};

