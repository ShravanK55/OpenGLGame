#pragma once
#include "InputComponent.h"
#include "PlayerStateComponent.h"
#include "PlayerPhysicsComponent.h"

class PlayerInputComponent : public InputComponent
{
public:
	PlayerInputComponent();
	PlayerInputComponent(Entity* owner);
	PlayerInputComponent(Entity* owner, PlayerStateComponent* stateComponent, PlayerPhysicsComponent* physicsComponent);
	~PlayerInputComponent();

	void HandleInput(Input* input);

private:
	PlayerStateComponent* stateComponent;
	PlayerPhysicsComponent* physicsComponent;
};

