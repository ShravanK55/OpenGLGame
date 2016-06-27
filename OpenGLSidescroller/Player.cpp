#include "Player.h"
#include "TransformComponent.h"
#include "PlayerGraphicsComponent.h"
#include "PlayerInputComponent.h"
#include "PlayerPhysicsComponent.h"
#include "PlayerStateComponent.h"


Player::Player(glm::vec2 spawnPoint, glm::vec2 size, GLfloat rotation, GLfloat scale)
{
	TransformComponent* transformComponent = new TransformComponent(this, spawnPoint, size, rotation, scale);
	PlayerStateComponent* stateComponent = new PlayerStateComponent(this);
	PlayerPhysicsComponent* physicsComponent = new PlayerPhysicsComponent(this, transformComponent, stateComponent);

	AddComponent(transformComponent);
	AddComponent(stateComponent);
	AddComponent(physicsComponent);
	AddComponent(new PlayerInputComponent(this, stateComponent, physicsComponent));
	AddComponent(new PlayerGraphicsComponent(this, stateComponent, transformComponent));
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
