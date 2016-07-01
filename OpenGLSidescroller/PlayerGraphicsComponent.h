#pragma once
#include "AnimatedGraphicsComponent.h"
#include "AnimatedSprite.h"

class Player;

class PlayerGraphicsComponent : public AnimatedGraphicsComponent
{
public:
	PlayerGraphicsComponent();
	PlayerGraphicsComponent(Entity* owner, const GLchar* filePath, const GLchar* name, const glm::vec2& size, GLfloat timeToUpdate,
							GLboolean alpha = false);
	~PlayerGraphicsComponent();

	Player* GetOwner() const;

	void Update(GLfloat elapsedTime);
	void Draw();

	// Sets up the animations for the player.
	void SetupAnimations();

private:
	// Updates the current animation based on the player's state.
	void UpdateAnimation();
};

