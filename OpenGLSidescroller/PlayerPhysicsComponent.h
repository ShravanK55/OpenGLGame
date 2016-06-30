#pragma once
#include "PhysicsComponent.h"
#include "TransformComponent.h"
#include "PlayerStateComponent.h"

class Player;

namespace PlayerConstants
{
	const GLfloat VELOCITY_HORIZONTAL = 300.0f;
	const GLfloat VELOCITY_VERTICAL = 300.0f;
}

class PlayerPhysicsComponent : public PhysicsComponent
{
public:
	PlayerPhysicsComponent();
	PlayerPhysicsComponent(Entity* owner);
	~PlayerPhysicsComponent();

	Player* GetOwner() const;

	void Update(float elapsedTime);

	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();

	void StopHorizontalMovement();
	void StopVerticalMovement();
	void StopAllMovement();

private:
	GLfloat dx, dy;
};

