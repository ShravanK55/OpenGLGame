#include "PlayerStateComponent.h"


const char* PlayerStateComponent::name = "PlayerStateComponent";

PlayerStateComponent::PlayerStateComponent() :
	Component(),
	state(PlayerState::IDLE),
	facing(Direction::DOWN)
{}

PlayerStateComponent::PlayerStateComponent(Entity* owner) :
	Component(owner),
	state(PlayerState::IDLE),
	facing(Direction::DOWN)
{}

PlayerStateComponent::~PlayerStateComponent() {}

bool PlayerStateComponent::Init(tinyxml2::XMLElement* componentElement)
{
	if (componentElement != nullptr)
		return true;
	else
		return false;
}

const char* PlayerStateComponent::GetName() const { return name; }

PlayerState PlayerStateComponent::GetState() const { return state; }
Direction PlayerStateComponent::GetFacing() const { return facing; }
void PlayerStateComponent::SetState(PlayerState state) { this->state = state; }
void PlayerStateComponent::SetFacing(Direction facing) { this->facing = facing; }

void PlayerStateComponent::HandleInput(Input* input) {}
void PlayerStateComponent::Update(float elapsedTime) {}
void PlayerStateComponent::Draw(SpriteBatch* spriteBatch) {}
