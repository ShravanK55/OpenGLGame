#include "PlayerGraphicsComponent.h"

namespace PlayerSpriteConstants
{
	const char* FILE_PATH = "Textures/GokuSpriteSheet.png";
	const char* SPRITE_NAME = "Goku";
	const GLfloat TIME_TO_UPDATE = 0.10f;
}

PlayerGraphicsComponent::PlayerGraphicsComponent() {}

PlayerGraphicsComponent::PlayerGraphicsComponent(Entity* owner) :
	GraphicsComponent(owner),
	transformComponent(nullptr),
	stateComponent(nullptr)
{
	playerSprite = new AnimatedSprite(PlayerSpriteConstants::FILE_PATH, PlayerSpriteConstants::SPRITE_NAME, glm::vec2(0.0f, 0.0f), glm::vec2(32.0f, 32.0f),
	                                  PlayerSpriteConstants::TIME_TO_UPDATE, GL_TRUE);
	SetupAnimations();
	UpdateAnimation();
}

PlayerGraphicsComponent::PlayerGraphicsComponent(Entity* owner, TransformComponent* transformComponent) :
	GraphicsComponent(owner),
	transformComponent(transformComponent),
	stateComponent(nullptr)
{
	playerSprite = new AnimatedSprite(PlayerSpriteConstants::FILE_PATH, PlayerSpriteConstants::SPRITE_NAME, transformComponent->GetPosition(), transformComponent->GetSize(),
									  PlayerSpriteConstants::TIME_TO_UPDATE, GL_TRUE);
	SetupAnimations();
	UpdateAnimation();
}

PlayerGraphicsComponent::PlayerGraphicsComponent(Entity* owner, PlayerStateComponent* stateComponent, TransformComponent* transformComponent) :
	GraphicsComponent(owner),
	transformComponent(transformComponent),
	stateComponent(stateComponent)
{
	playerSprite = new AnimatedSprite(PlayerSpriteConstants::FILE_PATH, PlayerSpriteConstants::SPRITE_NAME, transformComponent->GetPosition(), transformComponent->GetSize(),
									  PlayerSpriteConstants::TIME_TO_UPDATE, GL_TRUE);
	SetupAnimations();
	UpdateAnimation();
}

PlayerGraphicsComponent::~PlayerGraphicsComponent() { delete playerSprite; }

glm::vec2 PlayerGraphicsComponent::GetSize() const { return playerSprite->GetSize(); }

void PlayerGraphicsComponent::Update(GLfloat elapsedTime)
{
	UpdateAnimation();
	playerSprite->Update(elapsedTime);
}

void PlayerGraphicsComponent::Draw()
{
	playerSprite->Draw(transformComponent->GetPosition(), transformComponent->GetRotation(), transformComponent->GetScale());
}

void PlayerGraphicsComponent::UpdateAnimation()
{
	switch (stateComponent->GetState())
	{
	case PlayerState::IDLE:
		switch (stateComponent->GetFacing())
		{
		case Direction::RIGHT:
			playerSprite->PlayAnimation("IdleRight");
			break;
		case Direction::LEFT:
			playerSprite->PlayAnimation("IdleLeft");
			break;
		case Direction::UP:
			playerSprite->PlayAnimation("IdleUp");
			break;
		case Direction::DOWN:
			playerSprite->PlayAnimation("IdleDown");
			break;
		}
		break;

	case PlayerState::RUNNING:
		switch (stateComponent->GetFacing())
		{
		case Direction::RIGHT:
			playerSprite->PlayAnimation("RunRight");
			break;
		case Direction::LEFT:
			playerSprite->PlayAnimation("RunLeft");
			break;
		case Direction::UP:
			playerSprite->PlayAnimation("RunUp");
			break;
		case Direction::DOWN:
			playerSprite->PlayAnimation("RunDown");
			break;
		}
		break;
	}
}

void PlayerGraphicsComponent::SetupAnimations()
{
	playerSprite->AddAnimation("IdleDown", 1, 0, 0, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunDown", 4, 32, 0, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("IdleRight", 1, 0, 32, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunRight", 4, 32, 32, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("IdleLeft", 1, 0, 64, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunLeft", 4, 32, 64, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("IdleUp", 1, 0, 96, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunUp", 4, 32, 96, 32, 32, glm::vec2(0.0f));
}
