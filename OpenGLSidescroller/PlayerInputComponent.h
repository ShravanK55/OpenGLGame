#pragma once
#include "Component.h"


class Player;

class PlayerInputComponent : public Component
{
public:
	const static char* name;

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

