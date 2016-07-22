#include <GLM/glm.hpp>
#include "PlayerPhysicsComponent.h"
#include "Player.h"
#include "TransformComponent.h"
#include "PlayerStateComponent.h"


const char* PlayerPhysicsComponent::name = "PlayerPhysicsComponent";

PlayerPhysicsComponent::PlayerPhysicsComponent() :
	dx(0.0f), dy(0.0f)
{}

PlayerPhysicsComponent::PlayerPhysicsComponent(Entity* owner) :
	Component(owner),
	dx(0.0f), dy(0.0f)
{}

PlayerPhysicsComponent::~PlayerPhysicsComponent()
{}

bool PlayerPhysicsComponent::Init(tinyxml2::XMLElement* componentElement)
{
	if (componentElement != nullptr)
	{
		horizontalVelocity = componentElement->FloatAttribute("velocity_horizontal");
		verticalVelocity = componentElement->FloatAttribute("velocity_vertical");

		return true;
	}
	else
		return false;
}

unsigned long PlayerPhysicsComponent::GetIDFromName() { return HashString::HashName(name); }
const char* PlayerPhysicsComponent::GetName() const { return name; }

void PlayerPhysicsComponent::HandleInput(Input* input) {}

void PlayerPhysicsComponent::Update(float elapsedTime)
{
	TransformComponent* transformComponent = owner->GetComponent<TransformComponent>(TransformComponent::name);

	glm::vec2 newPosition;
	newPosition.x = transformComponent->GetPosition().x + (dx * elapsedTime);
	newPosition.y = transformComponent->GetPosition().y + (dy * elapsedTime);
	transformComponent->SetPosition(newPosition);
}

void PlayerPhysicsComponent::Draw(SpriteBatch* spriteBatch) {}

void PlayerPhysicsComponent::MoveUp()
{
	if (dx != 0)
	{
		dy = sqrt((verticalVelocity * verticalVelocity) + (horizontalVelocity * horizontalVelocity)) / 2;
		if (dx < 0)
			dx = -dy;
		else
			dx = dy;
	}
	else
		dy = verticalVelocity;

	PlayerStateComponent* stateComponent = owner->GetComponent<PlayerStateComponent>(PlayerStateComponent::name);
	stateComponent->SetState(PlayerState::RUNNING);
	stateComponent->SetFacing(Direction::UP);
}

void PlayerPhysicsComponent::MoveDown()
{
	if (dx != 0)
	{
		dy = -(sqrt((verticalVelocity * verticalVelocity) + (horizontalVelocity * horizontalVelocity)) / 2);
		if (dx > 0)
			dx = -dy;
		else
			dx = dy;
	}
	else
		dy = -verticalVelocity;

	PlayerStateComponent* stateComponent = owner->GetComponent<PlayerStateComponent>(PlayerStateComponent::name);
	stateComponent->SetState(PlayerState::RUNNING);
	stateComponent->SetFacing(Direction::DOWN);
}

void PlayerPhysicsComponent::MoveLeft()
{
	if (dy != 0)
	{
		dx = -(sqrt((verticalVelocity * verticalVelocity) + (horizontalVelocity * horizontalVelocity)) / 2);
		if (dy > 0)
			dy = -dx;
		else
			dy = dx;
	}
	else
		dx = -horizontalVelocity;

	PlayerStateComponent* stateComponent = owner->GetComponent<PlayerStateComponent>(PlayerStateComponent::name);
	stateComponent->SetState(PlayerState::RUNNING);
	stateComponent->SetFacing(Direction::LEFT);
}

void PlayerPhysicsComponent::MoveRight()
{
	if (dy != 0)
	{
		dx = sqrt((verticalVelocity * verticalVelocity) + (horizontalVelocity * horizontalVelocity)) / 2;
		if (dy < 0)
			dy = -dx;
		else
			dy = dx;
	}
	else
		dx = horizontalVelocity;

	PlayerStateComponent* stateComponent = owner->GetComponent<PlayerStateComponent>(PlayerStateComponent::name);
	stateComponent->SetState(PlayerState::RUNNING);
	stateComponent->SetFacing(Direction::RIGHT);
}

void PlayerPhysicsComponent::StopHorizontalMovement()
{
	dx = 0;

	if (dy > 0)
		owner->GetComponent<PlayerStateComponent>(PlayerStateComponent::name)->SetFacing(Direction::UP);
	else if (dy < 0)
		owner->GetComponent<PlayerStateComponent>(PlayerStateComponent::name)->SetFacing(Direction::DOWN);
	else
		owner->GetComponent<PlayerStateComponent>(PlayerStateComponent::name)->SetState(PlayerState::IDLE);
}

void PlayerPhysicsComponent::StopVerticalMovement()
{
	dy = 0;

	if (dx > 0)
		owner->GetComponent<PlayerStateComponent>(PlayerStateComponent::name)->SetFacing(Direction::RIGHT);
	else if (dx < 0)
		owner->GetComponent<PlayerStateComponent>(PlayerStateComponent::name)->SetFacing(Direction::LEFT);
	else
		owner->GetComponent<PlayerStateComponent>(PlayerStateComponent::name)->SetState(PlayerState::IDLE);
}

void PlayerPhysicsComponent::StopAllMovement()
{
	dx = 0;
	dy = 0;
	owner->GetComponent<PlayerStateComponent>(PlayerStateComponent::name)->SetState(PlayerState::IDLE);
}
