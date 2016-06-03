#include "PlayerStateComponent.h"



PlayerStateComponent::PlayerStateComponent() :
	state(PlayerState::IDLE)
{}

PlayerStateComponent::PlayerStateComponent(Entity* owner) :
	Component(owner),
	state(PlayerState::IDLE)
{}

PlayerStateComponent::~PlayerStateComponent() {}

PlayerState PlayerStateComponent::GetState() const { return state; }
void PlayerStateComponent::SetState(PlayerState state) { this->state = state; }

void PlayerStateComponent::Update(float elapsedTime) {}
