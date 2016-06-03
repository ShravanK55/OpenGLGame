#pragma once
#include "PhysicsComponent.h"
#include "PlayerStateComponent.h"

namespace PlayerConstants
{
	const GLfloat velocity = 180.0f;
};

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

	void MoveRight();
	void MoveLeft();
	void StopMoving();

private:
	PlayerStateComponent* stateComponent;
	GLfloat dx, dy;
	Direction facing;
};

