#pragma once
#include <iostream>

#include "ResourceManager.h"
#include "Camera2D.h"
#include "Window.h"
#include "SpriteBatch.h"
#include "Player.h"

class Game
{
public:
	Game();
	Game(GLfloat width, GLfloat height);
	~Game();

	void Init();
	void GameLoop();
	void Update(GLfloat elapsedTime);
	void Draw();
	void ProcessInput(GLfloat elapsedTime);

	static GLboolean wasKeyPressed(GLuint key);
	static GLboolean wasKeyReleased(GLuint key);

private:
	Window window;
	GLfloat width, height;
	Player player;
	Camera2D camera;
	SpriteBatch spriteBatch;
};

