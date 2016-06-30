#pragma once
#include "GraphicsComponent.h"
#include "PlayerPhysicsComponent.h"
#include "AnimatedSprite.h"

class Player;

class PlayerGraphicsComponent : public GraphicsComponent
{
public:
	PlayerGraphicsComponent();
	PlayerGraphicsComponent(Entity* owner);
	~PlayerGraphicsComponent();

	Player* GetOwner() const;
	glm::vec2 GetSize() const;

	void Update(GLfloat elapsedTime);
	void Draw();

private:
	AnimatedSprite* playerSprite;

	// Updates the current animation based on the player's state.
	void UpdateAnimation();
	// Sets up the animations for the player.
	void SetupAnimations();
};

