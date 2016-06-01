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
	~Game();

	// Constructor that calls the init function with the width and height passed.
	Game(GLfloat width, GLfloat height);

	// Initializes the game, creates window, sets up the camera, loads shaders and sets up the spritebatch.
	void Init();

	// The main game loop, handling input, calling update and draw functions.
	void GameLoop();

	// Calls the update function of each component of the game, passing in the time elapsed since the last frame.
	void Update(GLfloat elapsedTime);

	// Draws objects to the screen.
	void Draw();

	// Handles the input.
	void ProcessInput(GLfloat elapsedTime);

private:
	Window window;
	GLfloat width, height;
	Player player;
	Camera2D camera;
	SpriteBatch spriteBatch;
};

