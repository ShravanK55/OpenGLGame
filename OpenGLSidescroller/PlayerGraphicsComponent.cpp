#include "PlayerGraphicsComponent.h"
#include "Entity.h"
#include "PlayerStateComponent.h"


PlayerGraphicsComponent::PlayerGraphicsComponent() :
	AnimatedGraphicsComponent(owner)
{}

PlayerGraphicsComponent::PlayerGraphicsComponent(Entity* owner) :
	AnimatedGraphicsComponent(owner)
{
	UpdateAnimation();
}

PlayerGraphicsComponent::~PlayerGraphicsComponent() {}

void PlayerGraphicsComponent::Update(GLfloat elapsedTime)
{
	UpdateAnimation();
	AnimatedGraphicsComponent::Update(elapsedTime);
}

void PlayerGraphicsComponent::Draw(SpriteBatch* spriteBatch)
{
	AnimatedGraphicsComponent::Draw(spriteBatch);
}

void PlayerGraphicsComponent::UpdateAnimation()
{
	PlayerStateComponent* stateComponent = owner->GetComponent<PlayerStateComponent>();

	switch (stateComponent->GetState())
	{
	case PlayerState::IDLE:
		switch (stateComponent->GetFacing())
		{
		case Direction::RIGHT:
			sprite->PlayAnimation("IdleRight");
			break;
		case Direction::LEFT:
			sprite->PlayAnimation("IdleLeft");
			break;
		case Direction::UP:
			sprite->PlayAnimation("IdleUp");
			break;
		case Direction::DOWN:
			sprite->PlayAnimation("IdleDown");
			break;
		}
		break;

	case PlayerState::RUNNING:
		switch (stateComponent->GetFacing())
		{
		case Direction::RIGHT:
			sprite->PlayAnimation("RunRight");
			break;
		case Direction::LEFT:
			sprite->PlayAnimation("RunLeft");
			break;
		case Direction::UP:
			sprite->PlayAnimation("RunUp");
			break;
		case Direction::DOWN:
			sprite->PlayAnimation("RunDown");
			break;
		}

		break;
	}
}

