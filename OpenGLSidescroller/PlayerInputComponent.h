#pragma once
#include "Component.h"


class PlayerInputComponent : public Component
{
public:
	static const char* name;

	PlayerInputComponent();
	PlayerInputComponent(Entity* owner);
	~PlayerInputComponent();

	bool Init(tinyxml2::XMLElement* componentElement);
	static unsigned long GetIDFromName();
	const char* GetName() const;

	void HandleInput(Input* input);
	void Update(GLfloat elapsedTime);
	void Draw(SpriteBatch* spriteBatch);
};

