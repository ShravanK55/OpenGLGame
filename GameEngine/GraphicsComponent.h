#pragma once
#include "Component.h"

class GraphicsComponent : public Component
{
public:
	GraphicsComponent() {}
	GraphicsComponent(Entity* owner) :
		Component(owner)
	{}
	virtual ~GraphicsComponent() {}

	virtual void Update(GLfloat elapsedTime) {}
	virtual void Draw() {}
};
