#pragma once
#include "AnimatedSprite.h"
#include "GameObject.h"

enum class Player_State
{
	IDLE,
	RUNNING,
	JUMPING,
	ATTACKING
};

enum class Direction
{
	LEFT,
	RIGHT
};

class Player : public AnimatedSprite
{
public:
	Player();
	Player(glm::vec2 spawnPoint, GLfloat runSpeed);
	~Player();

	const GLfloat GetX() const;
	const GLfloat GetY() const;

	void Update(GLfloat elapsedTime);
	void Draw();

	void MoveLeft();
	void MoveRight();
	void StopMoving();

	void AnimationDone(std::string currentAnimation);
	void SetupAnimations();

private:
	GLfloat dx, dy;
	Direction facing;
	GLfloat runSpeed;
};

//class Player : public GameObject
//{
//public:
//	Player();
//	Player(glm::vec2 spawnPoint);
//	~Player();
//
//	void Update(GLfloat elapsedTime);
//	void Draw();
//
//private:
//
//};