#pragma once
#include "GraphicsComponent.h"
#include "PlayerPhysicsComponent.h"
#include "AnimatedSprite.h"


class PlayerGraphicsComponent : public GraphicsComponent
{
public:
	PlayerGraphicsComponent();
	PlayerGraphicsComponent(Entity* owner);
	PlayerGraphicsComponent(Entity* owner, glm::vec2 spawnPoint, glm::vec2 size);
	PlayerGraphicsComponent(Entity* owner, glm::vec2 spawnPoint, glm::vec2 size, PlayerStateComponent* stateComponent, PlayerPhysicsComponent* physicsComponent);
	~PlayerGraphicsComponent();

	void Update(GLfloat elapsedTime);
	void Draw();

	glm::vec2 GetSize() const;

private:
	AnimatedSprite* playerSprite;
	PlayerStateComponent* stateComponent;
	PlayerPhysicsComponent* physicsComponent;

	// Updates the current animation based on the player's state.
	void UpdateAnimation();
	// Sets up the animations for the player.
	void SetupAnimations();
};

