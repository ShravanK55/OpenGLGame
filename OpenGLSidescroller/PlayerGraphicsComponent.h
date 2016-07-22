#pragma once
#include "AnimatedGraphicsComponent.h"
#include "AnimatedSprite.h"

class Player;

class PlayerGraphicsComponent : public AnimatedGraphicsComponent
{
public:
	PlayerGraphicsComponent();
	PlayerGraphicsComponent(Entity* owner);
	~PlayerGraphicsComponent();

	void Update(GLfloat elapsedTime);
	void Draw(SpriteBatch* spriteBatch);

private:
	// Updates the current animation based on the player's state.
	void UpdateAnimation();
};

