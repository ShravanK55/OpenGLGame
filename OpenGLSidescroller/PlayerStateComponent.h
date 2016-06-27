#pragma once
#include "Component.h"


enum class PlayerState
{
	IDLE,
	RUNNING
};

enum class Direction
{
	RIGHT,
	LEFT,
	UP,
	DOWN
};

class PlayerStateComponent : public Component
{
public:
	PlayerStateComponent();
	PlayerStateComponent(Entity* owner);
	~PlayerStateComponent();

	PlayerState GetState() const;
	Direction GetFacing() const;
	void SetState(PlayerState state);
	void SetFacing(Direction facing);

	void Update(float elapsedTime);

private:
	PlayerState state;
	Direction facing;
};

