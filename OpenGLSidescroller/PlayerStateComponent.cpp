#include "PlayerStateComponent.h"



PlayerStateComponent::PlayerStateComponent() :
	state(PlayerState::IDLE),
	facing(Direction::DOWN)
{}

PlayerStateComponent::PlayerStateComponent(Entity* owner) :
	Component(owner),
	state(PlayerState::IDLE),
	facing(Direction::DOWN)
{}

PlayerStateComponent::~PlayerStateComponent() {}

PlayerState PlayerStateComponent::GetState() const { return state; }
Direction PlayerStateComponent::GetFacing() const { return facing; }
void PlayerStateComponent::SetState(PlayerState state) { this->state = state; }
void PlayerStateComponent::SetFacing(Direction facing) { this->facing = facing; }

void PlayerStateComponent::Update(float elapsedTime) {}
