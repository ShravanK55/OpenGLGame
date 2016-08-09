#pragma once
#include "Component.h"
#include "Sprite.h"


class GraphicsComponent : public Component
{
public:
	static const char* name;

	GraphicsComponent();
	GraphicsComponent(Entity* owner);
	virtual ~GraphicsComponent();

	virtual bool Init(tinyxml2::XMLElement* componentElement);

	const char* GetName() const;

	void HandleInput(Input* input);
	virtual void Update(GLfloat elapsedTime);
	virtual void Draw(SpriteBatch* spriteBatch);

protected:

	Sprite* sprite;
};
