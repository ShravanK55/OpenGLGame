#include "PlayerPhysicsComponent.h"


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

void PlayerPhysicsComponent::MoveLeft()
{
	dx = -PlayerConstants::velocity;
	stateComponent->SetState(PlayerState::RUNNING);
	facing = Direction::LEFT;
}

void PlayerPhysicsComponent::MoveRight()
{
	dx = PlayerConstants::velocity;
	stateComponent->SetState(PlayerState::RUNNING);
	facing = Direction::RIGHT;
}

void PlayerPhysicsComponent::StopMoving()
{
	dx = 0;
	stateComponent->SetState(PlayerState::IDLE);
}
