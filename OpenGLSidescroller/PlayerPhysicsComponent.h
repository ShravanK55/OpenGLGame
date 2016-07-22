#pragma once
#include "Component.h"


class Player;

class PlayerPhysicsComponent : public Component
{
public:
	const static char* name;

	PlayerPhysicsComponent();
	PlayerPhysicsComponent(Entity* owner);
	~PlayerPhysicsComponent();

	bool Init(tinyxml2::XMLElement* componentElement);
	static unsigned long GetIDFromName();
	const char* GetName() const;

	void HandleInput(Input* input);
	void Update(float elapsedTime);
	void Draw(SpriteBatch* spriteBatch);

	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();

	void StopHorizontalMovement();
	void StopVerticalMovement();
	void StopAllMovement();

private:
	GLfloat dx, dy;
	GLfloat horizontalVelocity;
	GLfloat verticalVelocity;
};

