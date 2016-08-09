#pragma once
#include "AnimatedGraphicsComponent.h"


class PlayerGraphicsComponent : public AnimatedGraphicsComponent
{
public:
	static const char* name;

	PlayerGraphicsComponent();
	PlayerGraphicsComponent(Entity* owner);
	~PlayerGraphicsComponent();

	void Update(GLfloat elapsedTime);
	void Draw(SpriteBatch* spriteBatch);

private:
	// Updates the current animation based on the player's state.
	void UpdateAnimation();
};

