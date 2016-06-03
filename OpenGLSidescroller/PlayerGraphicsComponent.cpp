#include "PlayerGraphicsComponent.h"


PlayerGraphicsComponent::PlayerGraphicsComponent() {}

PlayerGraphicsComponent::PlayerGraphicsComponent(Entity* owner) :
	GraphicsComponent(owner),
	physicsComponent(nullptr),
	stateComponent(nullptr)
{
	playerSprite = new AnimatedSprite("Textures/AltairSpriteSheet.png", "Altair", glm::vec2(0.0f, 0.0f), glm::vec2(96.0f, 84.0f), 0.08f, GL_TRUE);
	playerSprite->AddAnimation("IdleRight", 6, 0, 0, 96, 84, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunRight", 8, 0, 84, 96, 84, glm::vec2(0.0f));
	playerSprite->AddAnimation("IdleLeft", 6, 0, 168, 96, 84, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunLeft", 8, 0, 252, 96, 84, glm::vec2(0.0f));
	
	switch (stateComponent->GetState())
	{
	case PlayerState::IDLE:
		playerSprite->PlayAnimation(physicsComponent->GetFacing() == Direction::RIGHT ? "IdleRight" : "IdleLeft");
		break;

	case PlayerState::RUNNING:
		playerSprite->PlayAnimation(physicsComponent->GetFacing() == Direction::RIGHT ? "RunRight" : "RunLeft");
		break;
	}
}

PlayerGraphicsComponent::PlayerGraphicsComponent(Entity* owner, glm::vec2 spawnPoint, glm::vec2 size) :
	GraphicsComponent(owner),
	physicsComponent(nullptr),
	stateComponent(nullptr)
{
	playerSprite = new AnimatedSprite("Textures/AltairSpriteSheet.png", "Altair", spawnPoint, size, 0.08f, GL_TRUE);
	playerSprite->AddAnimation("IdleRight", 6, 0, 0, 96, 84, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunRight", 8, 0, 84, 96, 84, glm::vec2(0.0f));
	playerSprite->AddAnimation("IdleLeft", 6, 0, 168, 96, 84, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunLeft", 8, 0, 252, 96, 84, glm::vec2(0.0f));

	switch (stateComponent->GetState())
	{
	case PlayerState::IDLE:
		playerSprite->PlayAnimation(physicsComponent->GetFacing() == Direction::RIGHT ? "IdleRight" : "IdleLeft");
		break;

	case PlayerState::RUNNING:
		playerSprite->PlayAnimation(physicsComponent->GetFacing() == Direction::RIGHT ? "RunRight" : "RunLeft");
		break;
	}
}

PlayerGraphicsComponent::PlayerGraphicsComponent(Entity* owner, glm::vec2 spawnPoint, glm::vec2 size, PlayerStateComponent* stateComponent,
	PlayerPhysicsComponent* physicsComponent) :
	GraphicsComponent(owner),
	physicsComponent(physicsComponent),
	stateComponent(stateComponent)
{
	playerSprite = new AnimatedSprite("Textures/AltairSpriteSheet.png", "Altair", spawnPoint, size, 0.08f, GL_TRUE);
	playerSprite->AddAnimation("IdleRight", 6, 0, 0, 96, 84, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunRight", 8, 0, 84, 96, 84, glm::vec2(0.0f));
	playerSprite->AddAnimation("IdleLeft", 6, 0, 168, 96, 84, glm::vec2(0.0f));
	playerSprite->AddAnimation("RunLeft", 8, 0, 252, 96, 84, glm::vec2(0.0f));

	switch (stateComponent->GetState())
	{
	case PlayerState::IDLE:
		playerSprite->PlayAnimation(physicsComponent->GetFacing() == Direction::RIGHT ? "IdleRight" : "IdleLeft");
		break;

	case PlayerState::RUNNING:
		playerSprite->PlayAnimation(physicsComponent->GetFacing() == Direction::RIGHT ? "RunRight" : "RunLeft");
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
		playerSprite->PlayAnimation(physicsComponent->GetFacing() == Direction::RIGHT ? "IdleRight" : "IdleLeft");
		break;

	case PlayerState::RUNNING:
		playerSprite->PlayAnimation(physicsComponent->GetFacing() == Direction::RIGHT ? "RunRight" : "RunLeft");
		break;
	}

	playerSprite->Update(elapsedTime);
}

void PlayerGraphicsComponent::Draw() { playerSprite->Draw(physicsComponent->GetPosition()); }
