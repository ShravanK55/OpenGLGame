#include "PlayerPhysicsComponent.h"
#include "Player.h"
#include <GLM/glm.hpp>


PlayerPhysicsComponent::PlayerPhysicsComponent() :
	dx(0.0f), dy(0.0f)
{}

PlayerPhysicsComponent::PlayerPhysicsComponent(Entity* owner) :
	PhysicsComponent(owner),
	dx(0.0f), dy(0.0f)
{}

PlayerPhysicsComponent::~PlayerPhysicsComponent()
{}

void PlayerPhysicsComponent::Update(float elapsedTime)
{
	glm::vec2 newPosition;
	newPosition.x = GetOwner()->GetTransformComponent()->GetPosition().x + (dx * elapsedTime);
	newPosition.y = GetOwner()->GetTransformComponent()->GetPosition().y + (dy * elapsedTime);
	GetOwner()->GetTransformComponent()->SetPosition(newPosition);
}

Player* PlayerPhysicsComponent::GetOwner() const { return static_cast<Player*>(owner); }

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

	GetOwner()->GetStateComponent()->SetState(PlayerState::RUNNING);
	GetOwner()->GetStateComponent()->SetFacing(Direction::UP);
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
	GetOwner()->GetStateComponent()->SetState(PlayerState::RUNNING);
	GetOwner()->GetStateComponent()->SetFacing(Direction::DOWN);
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
	GetOwner()->GetStateComponent()->SetState(PlayerState::RUNNING);
	GetOwner()->GetStateComponent()->SetFacing(Direction::LEFT);
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
	GetOwner()->GetStateComponent()->SetState(PlayerState::RUNNING);
	GetOwner()->GetStateComponent()->SetFacing(Direction::RIGHT);
}

void PlayerPhysicsComponent::StopHorizontalMovement()
{
	dx = 0;

	if (dy > 0)
		GetOwner()->GetStateComponent()->SetFacing(Direction::UP);
	else if (dy < 0)
		GetOwner()->GetStateComponent()->SetFacing(Direction::DOWN);
	else
		GetOwner()->GetStateComponent()->SetState(PlayerState::IDLE);
}

void PlayerPhysicsComponent::StopVerticalMovement()
{
	dy = 0;

	if (dx > 0)
		GetOwner()->GetStateComponent()->SetFacing(Direction::RIGHT);
	else if (dx < 0)
		GetOwner()->GetStateComponent()->SetFacing(Direction::LEFT);
	else
		GetOwner()->GetStateComponent()->SetState(PlayerState::IDLE);
}

void PlayerPhysicsComponent::StopAllMovement()
{
	dx = 0;
	dy = 0;
	GetOwner()->GetStateComponent()->SetState(PlayerState::IDLE);
}
