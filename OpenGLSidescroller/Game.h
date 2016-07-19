#pragma once
#include "Camera2D.h"
#include "Window.h"
#include "SpriteBatch.h"
#include "Player.h"
#include "Level.h"

class Game
{
public:
	Game();
	~Game();

	// Initializes the game, creates window, sets up the camera, loads shaders and sets up the spritebatch.
	void Init();

	// The main game loop, handling input, calling update and draw functions.
	void GameLoop();

	// Calls the update function of each component of the game, passing in the time elapsed since the last frame.
	void Update(GLfloat elapsedTime);

	// Draws objects to the screen.
	void Draw(SpriteBatch* spriteBatch);

	// Handles the input.
	void ProcessInput(GLfloat elapsedTime);

private:
	Window* window;
	GLint width, height;
	Level* level;
	Player* player;
	Camera2D* camera;
	SpriteBatch* spriteBatch;
};

