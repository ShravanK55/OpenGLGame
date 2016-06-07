#include "PlayerGraphicsComponent.h"


PlayerGraphicsComponent::PlayerGraphicsComponent() {}

PlayerGraphicsComponent::PlayerGraphicsComponent(Entity* owner) :
	GraphicsComponent(owner),
	physicsComponent(nullptr),
	stateComponent(nullptr)
{
	playerSprite = new AnimatedSprite("Textures/GokuSpriteSheet.png", "Goku", glm::vec2(0.0f, 0.0f), glm::vec2(32.0f, 32.0f), 0.08f, GL_TRUE);
	playerSprite->AddAnimation("IdleDown", 1, 0, 0, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunDown", 4, 32, 0, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("IdleRight", 1, 0, 32, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunRight", 4, 32, 32, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("IdleLeft", 1, 0, 64, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunLeft", 4, 32, 64, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("IdleUp", 1, 0, 96, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunUp", 4, 32, 96, 32, 32, glm::vec2(0.0f));
	
	switch (stateComponent->GetState())
	{
	case PlayerState::IDLE:
		switch(physicsComponent->GetFacing())
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
		switch (physicsComponent->GetFacing())
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

PlayerGraphicsComponent::PlayerGraphicsComponent(Entity* owner, glm::vec2 spawnPoint, glm::vec2 size) :
	GraphicsComponent(owner),
	physicsComponent(nullptr),
	stateComponent(nullptr)
{
	playerSprite = new AnimatedSprite("Textures/GokuSpriteSheet.png", "Goku", spawnPoint, size, 0.08f, GL_TRUE);
	playerSprite->AddAnimation("IdleDown", 1, 0, 0, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunDown", 4, 32, 0, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("IdleRight", 1, 0, 32, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunRight", 4, 32, 32, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("IdleLeft", 1, 0, 64, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunLeft", 4, 32, 64, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("IdleUp", 1, 0, 96, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunUp", 4, 32, 96, 32, 32, glm::vec2(0.0f));

	switch (stateComponent->GetState())
	{
	case PlayerState::IDLE:
		switch (physicsComponent->GetFacing())
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
		switch (physicsComponent->GetFacing())
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

PlayerGraphicsComponent::PlayerGraphicsComponent(Entity* owner, glm::vec2 spawnPoint, glm::vec2 size, PlayerStateComponent* stateComponent,
	PlayerPhysicsComponent* physicsComponent) :
	GraphicsComponent(owner),
	physicsComponent(physicsComponent),
	stateComponent(stateComponent)
{
	playerSprite = new AnimatedSprite("Textures/GokuSpriteSheet.png", "Goku", spawnPoint, size, 0.08f, GL_TRUE);
	playerSprite->AddAnimation("IdleDown", 1, 0, 0, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunDown", 4, 32, 0, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("IdleRight", 1, 0, 32, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunRight", 4, 32, 32, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("IdleLeft", 1, 0, 64, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunLeft", 4, 32, 64, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("IdleUp", 1, 0, 96, 32, 32, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunUp", 4, 32, 96, 32, 32, glm::vec2(0.0f));

	switch (stateComponent->GetState())
	{
	case PlayerState::IDLE:
		switch (physicsComponent->GetFacing())
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
		switch (physicsComponent->GetFacing())
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

PlayerGraphicsComponent::~PlayerGraphicsComponent() { delete playerSprite; }

glm::vec2 PlayerGraphicsComponent::GetSize() const { return playerSprite->GetSize(); }

void PlayerGraphicsComponent::Update(GLfloat elapsedTime)
{
	switch (stateComponent->GetState())
	{
	case PlayerState::IDLE:
		switch (physicsComponent->GetFacing())
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
		switch (physicsComponent->GetFacing())
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

	playerSprite->Update(elapsedTime);
}

void PlayerGraphicsComponent::Draw() { playerSprite->Draw(physicsComponent->GetPosition()); }
