#pragma once
#include "InputComponent.h"
#include "PlayerStateComponent.h"
#include "PlayerPhysicsComponent.h"

class Player;

class PlayerInputComponent : public InputComponent
{
public:
	PlayerInputComponent();
	PlayerInputComponent(Entity* owner);
	~PlayerInputComponent();

	Player* GetOwner() const;

	void HandleInput(Input* input);
};

