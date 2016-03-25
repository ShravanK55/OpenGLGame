#include "Player.h"



Player::Player() {}

Player::Player(glm::vec2 spawnPoint, GLfloat runSpeed) :
	AnimatedSprite("Textures/AltairSpriteSheet.png", "altair", glm::vec2(spawnPoint.x, spawnPoint.y), glm::vec2(96.0f, 84.0f), 0.08f, GL_TRUE),
	dx(0), dy(0),
	facing(Direction::RIGHT),
	runSpeed(runSpeed)
{
	SetupAnimations();
	PlayAnimation("IdleRight");
	facing = Direction::RIGHT;
}

Player::~Player()
{}

const GLfloat Player::GetX() const { return posX; }
const GLfloat Player::GetY() const { return posY; }

void Player::Update(GLfloat elapsedTime)
{
	this->posX += dx * elapsedTime;

	AnimatedSprite::Update(elapsedTime);
}

void Player::Draw()
{
	AnimatedSprite::Draw();
}

void Player::MoveLeft()
{
	dx = -runSpeed;
	PlayAnimation("RunLeft");
	facing = Direction::LEFT;
}

void Player::MoveRight()
{
	dx = runSpeed;
	PlayAnimation("RunRight");
	facing = Direction::RIGHT;
}

void Player::StopMoving()
{
	dx = 0;
	PlayAnimation(facing == Direction::RIGHT ? "IdleRight" : "IdleLeft");
}

void Player::AnimationDone(std::string currentAnimation)
{
}

void Player::SetupAnimations()
{
	AddAnimation("IdleRight", 6, 0, 0, 96, 84, glm::vec2(0.0f));
	AddAnimation("RunRight", 8, 0, 84, 96, 84, glm::vec2(0.0f));
	AddAnimation("IdleLeft", 6, 0, 168, 96, 84, glm::vec2(0.0f));
	AddAnimation("RunLeft", 8, 0, 252, 96, 84, glm::vec2(0.0f));
}
