#include "Player.h"
#include "PlayerGraphicsComponent.h"
#include "PlayerInputComponent.h"
#include "PlayerPhysicsComponent.h"
#include "PlayerStateComponent.h"


Player::Player(glm::vec2 spawnPoint, glm::vec2 size, GLfloat rotation, GLfloat scale) :
	Character(spawnPoint, size, rotation, scale)
{
	Entity::AddComponent(new PlayerStateComponent(this));
	Entity::AddComponent(new PlayerPhysicsComponent(this));
	Entity::AddComponent(new PlayerInputComponent(this));
	Entity::AddComponent(new PlayerGraphicsComponent(this, PlayerSpriteConstants::FILE_PATH, PlayerSpriteConstants::SPRITE_NAME,
	                                                 size, PlayerSpriteConstants::TIME_TO_UPDATE, GL_TRUE));
}

Player::~Player() {}


PlayerGraphicsComponent* Player::GetGraphicsComponent() const
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		if (components[i]->GetTag() == "Graphics")
			return static_cast<PlayerGraphicsComponent*>(components[i]);
	}
	
	return nullptr;
}

PlayerInputComponent* Player::GetInputComponent() const
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		if (components[i]->GetTag() == "Input")
			return static_cast<PlayerInputComponent*>(components[i]);
	}

	return nullptr;
}

PlayerPhysicsComponent* Player::GetPhysicsComponent() const
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		if (components[i]->GetTag() == "Physics")
			return static_cast<PlayerPhysicsComponent*>(components[i]);
	}

	return nullptr;
}

PlayerStateComponent* Player::GetStateComponent() const
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		if (components[i]->GetTag() == "State")
			return static_cast<PlayerStateComponent*>(components[i]);
	}

	return nullptr;
}

void Player::HandleInput(Input* input)
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		components[i]->HandleInput(input);
	}
}

void Player::Update(GLfloat elapsedTime)
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		components[i]->Update(elapsedTime);
	}
}

void Player::Draw(SpriteBatch* spriteBatch)
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		components[i]->Draw(spriteBatch);
	}
}
