#include "PlayerPhysicsComponent.h"
#include <GLM/glm.hpp>


PlayerPhysicsComponent::PlayerPhysicsComponent() :
	stateComponent(nullptr),
	transformComponent(nullptr),
	dx(0.0f), dy(0.0f)
{
	stateComponent->SetState(PlayerState::IDLE);
}

PlayerPhysicsComponent::PlayerPhysicsComponent(Entity* owner) :
	PhysicsComponent(owner),
	stateComponent(nullptr),
	transformComponent(nullptr),
	dx(0.0f), dy(0.0f)
{
	stateComponent->SetState(PlayerState::IDLE);
}

PlayerPhysicsComponent::PlayerPhysicsComponent(Entity* owner, TransformComponent* transformComponent) :
	PhysicsComponent(owner),
	transformComponent(transformComponent),
	stateComponent(nullptr),
	dx(0.0f), dy(0.0f)
{
	stateComponent->SetState(PlayerState::IDLE);
}

PlayerPhysicsComponent::PlayerPhysicsComponent(Entity* owner, TransformComponent* transformComponent, PlayerStateComponent* stateComponent) :
	PhysicsComponent(owner),
	transformComponent(transformComponent),
	stateComponent(stateComponent),
	dx(0.0f), dy(0.0f)
{
	stateComponent->SetState(PlayerState::IDLE);
}

PlayerPhysicsComponent::~PlayerPhysicsComponent()
{}

void PlayerPhysicsComponent::Update(float elapsedTime)
{
	glm::vec2 newPosition;
	newPosition.x = transformComponent->GetPosition().x + (dx * elapsedTime);
	newPosition.y = transformComponent->GetPosition().y + (dy * elapsedTime);
	transformComponent->SetPosition(newPosition);
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
	stateComponent->SetFacing(Direction::UP);
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
	stateComponent->SetFacing(Direction::DOWN);
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
	stateComponent->SetFacing(Direction::LEFT);
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
	stateComponent->SetFacing(Direction::RIGHT);
}

void PlayerPhysicsComponent::StopHorizontalMovement()
{
	dx = 0;

	if (dy > 0)
		stateComponent->SetFacing(Direction::UP);
	else if (dy < 0)
		stateComponent->SetFacing(Direction::DOWN);
	else
		stateComponent->SetState(PlayerState::IDLE);
}

void PlayerPhysicsComponent::StopVerticalMovement()
{
	dy = 0;

	if (dx > 0)
		stateComponent->SetFacing(Direction::RIGHT);
	else if (dx < 0)
		stateComponent->SetFacing(Direction::LEFT);
	else
		stateComponent->SetState(PlayerState::IDLE);
}

void PlayerPhysicsComponent::StopAllMovement()
{
	dx = 0;
	dy = 0;
	stateComponent->SetState(PlayerState::IDLE);
}
