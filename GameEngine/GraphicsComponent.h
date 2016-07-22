#pragma once
#include "Component.h"

class Sprite;

class GraphicsComponent : public Component
{
public:
	const static char* name;

	GraphicsComponent();
	GraphicsComponent(Entity* owner);
	virtual ~GraphicsComponent();

	virtual bool Init(tinyxml2::XMLElement* componentElement);

	static unsigned long GetID();
	const char* GetName() const;

	void HandleInput(Input* input);
	virtual void Update(GLfloat elapsedTime);
	virtual void Draw(SpriteBatch* spriteBatch);

protected:
	Sprite* sprite;
};
