#pragma once
#include "GraphicsComponent.h"
#include "PlayerPhysicsComponent.h"
#include "AnimatedSprite.h"


class PlayerGraphicsComponent : public GraphicsComponent
{
public:
	PlayerGraphicsComponent();
	PlayerGraphicsComponent(Entity* owner);
	PlayerGraphicsComponent(Entity* owner, TransformComponent* transformComponent);
	PlayerGraphicsComponent(Entity* owner, PlayerStateComponent* stateComponent, TransformComponent* transformComponent);
	~PlayerGraphicsComponent();

	void Update(GLfloat elapsedTime);
	void Draw();

	glm::vec2 GetSize() const;

private:
	AnimatedSprite* playerSprite;
	PlayerStateComponent* stateComponent;
	TransformComponent* transformComponent;

	// Updates the current animation based on the player's state.
	void UpdateAnimation();
	// Sets up the animations for the player.
	void SetupAnimations();
};

