#pragma once
#include "Component.h"


enum class PlayerState
{
	IDLE,
	RUNNING
};

class PlayerStateComponent : public Component
{
public:
	PlayerStateComponent();
	PlayerStateComponent(Entity* owner);
	~PlayerStateComponent();

	PlayerState GetState() const;
	void SetState(PlayerState state);

	void Update(float elapsedTime);

private:
	PlayerState state;
};

