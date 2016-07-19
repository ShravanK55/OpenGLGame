#include "PlayerGraphicsComponent.h"
#include "PlayerStateComponent.h"
#include "Player.h"


PlayerGraphicsComponent::PlayerGraphicsComponent() :
	AnimatedGraphicsComponent(owner)
{}

PlayerGraphicsComponent::PlayerGraphicsComponent(Entity* owner, const GLchar* filePath, const GLchar* name, const glm::vec2& size, GLfloat timeToUpdate,
												 GLboolean alpha) :
	AnimatedGraphicsComponent(owner, filePath, name, size, timeToUpdate, alpha)
{
	PlayerGraphicsComponent::SetupAnimations();
	UpdateAnimation();
}

PlayerGraphicsComponent::~PlayerGraphicsComponent() {}

Player* PlayerGraphicsComponent::GetOwner() const { return static_cast<Player*>(owner); }

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
	switch (GetOwner()->GetStateComponent()->GetState())
	{
	case PlayerState::IDLE:
		switch (GetOwner()->GetStateComponent()->GetFacing())
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
		switch (GetOwner()->GetStateComponent()->GetFacing())
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

void PlayerGraphicsComponent::SetupAnimations()
{
	sprite->AddAnimation("IdleDown", 1, 0, 0, 32, 32, glm::vec2(0.0f));
	sprite->AddAnimation("RunDown", 4, 32, 0, 32, 32, glm::vec2(0.0f));
	sprite->AddAnimation("IdleRight", 1, 0, 32, 32, 32, glm::vec2(0.0f));
	sprite->AddAnimation("RunRight", 4, 32, 32, 32, 32, glm::vec2(0.0f));
	sprite->AddAnimation("IdleLeft", 1, 0, 64, 32, 32, glm::vec2(0.0f));
	sprite->AddAnimation("RunLeft", 4, 32, 64, 32, 32, glm::vec2(0.0f));
	sprite->AddAnimation("IdleUp", 1, 0, 96, 32, 32, glm::vec2(0.0f));
	sprite->AddAnimation("RunUp", 4, 32, 96, 32, 32, glm::vec2(0.0f));
}
