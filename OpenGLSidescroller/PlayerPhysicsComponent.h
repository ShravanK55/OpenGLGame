#pragma once
#include "PhysicsComponent.h"
#include "TransformComponent.h"
#include "PlayerStateComponent.h"


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
	PlayerPhysicsComponent(Entity* owner, TransformComponent* transformComponent);
	PlayerPhysicsComponent(Entity* owner, TransformComponent* transformComponent, PlayerStateComponent* stateComponent);
	~PlayerPhysicsComponent();

	void Update(float elapsedTime);

	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();

	void StopHorizontalMovement();
	void StopVerticalMovement();
	void StopAllMovement();

private:
	TransformComponent* transformComponent;
	PlayerStateComponent* stateComponent;
	GLfloat dx, dy;
};

