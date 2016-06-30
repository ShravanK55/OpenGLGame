#pragma once
#include "Component.h"

class GraphicsComponent : public Component
{
public:
	GraphicsComponent() :
		Component("Graphics")
	{}
	GraphicsComponent(Entity* owner) :
		Component(owner, "Graphics")
	{}
	virtual ~GraphicsComponent() {}

	virtual void Update(GLfloat elapsedTime) {}
	virtual void Draw() {}
};
