#include "PlayerPhysicsComponent.h"
#include <GLM/glm.hpp>


PlayerPhysicsComponent::PlayerPhysicsComponent() :
	stateComponent(nullptr),
	dx(0.0f), dy(0.0f),
	facing(Direction::RIGHT)
{
	stateComponent->SetState(PlayerState::IDLE);
}

PlayerPhysicsComponent::PlayerPhysicsComponent(Entity* owner) :
	PhysicsComponent(owner),
	stateComponent(nullptr),
	dx(0.0f), dy(0.0f),
	facing(Direction::RIGHT)
{
	stateComponent->SetState(PlayerState::IDLE);
}

PlayerPhysicsComponent::PlayerPhysicsComponent(Entity* owner, glm::vec2 spawnPoint, glm::vec2 size) :
	PhysicsComponent(owner, spawnPoint, size),
	stateComponent(nullptr),
	dx(0.0f), dy(0.0f),
	facing(Direction::RIGHT)
{
	stateComponent->SetState(PlayerState::IDLE);
}

PlayerPhysicsComponent::PlayerPhysicsComponent(Entity* owner, glm::vec2 spawnPoint, glm::vec2 size, PlayerStateComponent* stateComponent) :
	PhysicsComponent(owner, spawnPoint, size),
	stateComponent(stateComponent),
	dx(0.0f), dy(0.0f),
	facing(Direction::RIGHT)
{
	stateComponent->SetState(PlayerState::IDLE);
}

PlayerPhysicsComponent::~PlayerPhysicsComponent()
{}

Direction PlayerPhysicsComponent::GetFacing() const { return facing; }

void PlayerPhysicsComponent::Update(float elapsedTime)
{
	position.x += dx * elapsedTime;
	position.y += dy * elapsedTime;
}

void PlayerPhysicsComponent::MoveUp()
{
	if (dx != 0)
	{
		dy = (sqrt((PlayerConstants::VELOCITY_VERTICAL * PlayerConstants::VELOCITY_VERTICAL) +
			 (PlayerConstants::VELOCITY_HORIZONTAL * PlayerConstants::VELOCITY_HORIZONTAL)) / 2);
		if (dx < 0)
			dx = -dy;
		else
			dx = dy;
	}
	else
		dy = PlayerConstants::VELOCITY_VERTICAL;

	stateComponent->SetState(PlayerState::RUNNING);
	facing = Direction::UP;
}

void PlayerPhysicsComponent::MoveDown()
{
	if (dx != 0)
	{
		dy = -(sqrt((PlayerConstants::VELOCITY_VERTICAL * PlayerConstants::VELOCITY_VERTICAL) +
			  (PlayerConstants::VELOCITY_HORIZONTAL * PlayerConstants::VELOCITY_HORIZONTAL)) / 2);
		if (dx > 0)
			dx = -dy;
		else
			dx = dy;
	}
	else
		dy = -PlayerConstants::VELOCITY_VERTICAL;
	stateComponent->SetState(PlayerState::RUNNING);
	facing = Direction::DOWN;
}

void PlayerPhysicsComponent::MoveLeft()
{
	if (dy != 0)
	{
		dx = -(sqrt((PlayerConstants::VELOCITY_VERTICAL * PlayerConstants::VELOCITY_VERTICAL) +
			  (PlayerConstants::VELOCITY_HORIZONTAL * PlayerConstants::VELOCITY_HORIZONTAL)) / 2);
		if (dy > 0)
			dy = -dx;
		else
			dy = dx;
	}
	else
		dx = -PlayerConstants::VELOCITY_HORIZONTAL;
	stateComponent->SetState(PlayerState::RUNNING);
	facing = Direction::LEFT;
}

void PlayerPhysicsComponent::MoveRight()
{
	if (dy != 0)
	{
		dx = (sqrt((PlayerConstants::VELOCITY_VERTICAL * PlayerConstants::VELOCITY_VERTICAL) +
			 (PlayerConstants::VELOCITY_HORIZONTAL * PlayerConstants::VELOCITY_HORIZONTAL)) / 2);
		if (dy < 0)
			dy = -dx;
		else
			dy = dx;
	}
	else
		dx = PlayerConstants::VELOCITY_HORIZONTAL;
	stateComponent->SetState(PlayerState::RUNNING);
	facing = Direction::RIGHT;
}

void PlayerPhysicsComponent::StopHorizontalMovement()
{
	dx = 0;

	if (dy > 0)
		facing = Direction::UP;
	else if (dy < 0)
		facing = Direction::DOWN;
	else
		stateComponent->SetState(PlayerState::IDLE);
}

void PlayerPhysicsComponent::StopVerticalMovement()
{
	dy = 0;

	if (dx > 0)
		facing = Direction::RIGHT;
	else if (dx < 0)
		facing = Direction::LEFT;
	else
		stateComponent->SetState(PlayerState::IDLE);
}

void PlayerPhysicsComponent::StopAllMovement()
{
	dx = 0;
	dy = 0;
	stateComponent->SetState(PlayerState::IDLE);
}
