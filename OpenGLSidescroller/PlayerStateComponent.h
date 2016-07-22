#pragma once
#include "Component.h"

class Player;

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
	const static char* name;

	PlayerStateComponent();
	PlayerStateComponent(Entity* owner);
	~PlayerStateComponent();

	bool Init(tinyxml2::XMLElement* componentElement);
	static unsigned long GetIDFromName();
	const char* GetName() const;

	PlayerState GetState() const;
	Direction GetFacing() const;
	void SetState(PlayerState state);
	void SetFacing(Direction facing);

	void HandleInput(Input* input);
	void Update(float elapsedTime);
	void Draw(SpriteBatch* spriteBatch);

private:
	PlayerState state;
	Direction facing;
};

