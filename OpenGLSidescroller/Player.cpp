#include "Player.h"
#include "PlayerGraphicsComponent.h"
#include "PlayerInputComponent.h"
#include "PlayerPhysicsComponent.h"
#include "PlayerStateComponent.h"


Player::Player(glm::vec2 spawnPoint, glm::vec2 size)
{
	PlayerStateComponent* stateComponent = new PlayerStateComponent(this);
	PlayerPhysicsComponent* physicsComponent = new PlayerPhysicsComponent(this, spawnPoint, size, stateComponent);

	AddComponent(stateComponent);
	AddComponent(physicsComponent);
	AddComponent(new PlayerInputComponent(this, stateComponent, physicsComponent));
	AddComponent(new PlayerGraphicsComponent(this, spawnPoint, size, stateComponent, physicsComponent));
}

Player::~Player() {}

void Player::HandleInput(Input* input)
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->HandleInput(input);
	}
}

void Player::Update(GLfloat elapsedTime)
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->Update(elapsedTime);
	}
}

void Player::Draw()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->Draw();
	}
}
