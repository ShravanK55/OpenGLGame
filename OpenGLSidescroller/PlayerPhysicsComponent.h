#pragma once
#include "PhysicsComponent.h"
#include "PlayerStateComponent.h"

namespace PlayerConstants
{
	const GLfloat VELOCITY_HORIZONTAL = 180.0f;
	const GLfloat VELOCITY_VERTICAL = 180.0f;
}

enum class Direction
{
	RIGHT,
	LEFT,
	UP,
	DOWN
};

class PlayerPhysicsComponent : public PhysicsComponent
{
public:
	PlayerPhysicsComponent();
	PlayerPhysicsComponent(Entity* owner);
	PlayerPhysicsComponent(Entity* owner, glm::vec2 spawnPoint, glm::vec2 size);
	PlayerPhysicsComponent(Entity* owner, glm::vec2 spawnPoint, glm::vec2 size, PlayerStateComponent* stateComponent);
	~PlayerPhysicsComponent();

	Direction GetFacing() const;

	void Update(float elapsedTime);

	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();

	void StopHorizontalMovement();
	void StopVerticalMovement();
	void StopAllMovement();

private:
	PlayerStateComponent* stateComponent;
	GLfloat dx, dy;
	Direction facing;
};

