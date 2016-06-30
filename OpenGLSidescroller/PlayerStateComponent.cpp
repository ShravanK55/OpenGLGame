#include "PlayerStateComponent.h"
#include "Player.h"


PlayerStateComponent::PlayerStateComponent() :
	Component("State"),
	state(PlayerState::IDLE),
	facing(Direction::DOWN)
{}

PlayerStateComponent::PlayerStateComponent(Entity* owner) :
	Component(owner, "State"),
	state(PlayerState::IDLE),
	facing(Direction::DOWN)
{}

PlayerStateComponent::~PlayerStateComponent() {}

Player* PlayerStateComponent::GetOwner() const { return static_cast<Player*>(owner); }
PlayerState PlayerStateComponent::GetState() const { return state; }
Direction PlayerStateComponent::GetFacing() const { return facing; }
void PlayerStateComponent::SetState(PlayerState state) { this->state = state; }
void PlayerStateComponent::SetFacing(Direction facing) { this->facing = facing; }

void PlayerStateComponent::Update(float elapsedTime) {}
