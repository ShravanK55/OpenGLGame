#pragma once
#include <GLM/glm.hpp>
#include "Character.h"

class PlayerStateComponent;
class PlayerPhysicsComponent;
class PlayerInputComponent;
class PlayerGraphicsComponent;

namespace PlayerSpriteConstants
{
	static const char* FILE_PATH = "Textures/GokuSpriteSheet.png";
	static const char* SPRITE_NAME = "Goku";
	static const GLfloat TIME_TO_UPDATE = 0.10f;
};

class Player : public Character
{
public:
	Player(glm::vec2 spawnPoint, glm::vec2 size, GLfloat rotation = 0.0f, GLfloat scale = 1.0f);
	~Player();

	PlayerGraphicsComponent* GetGraphicsComponent() const;
	PlayerInputComponent* GetInputComponent() const;
	PlayerPhysicsComponent* GetPhysicsComponent() const;
	PlayerStateComponent* GetStateComponent() const;

	void HandleInput(Input* input);
	void Update(GLfloat elapsedTime);
	void Draw();
};
