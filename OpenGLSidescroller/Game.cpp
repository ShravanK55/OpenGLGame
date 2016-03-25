#include "Game.h"

Game::Game() :
	width(Global::SCREEN_WIDTH),
	height(Global::SCREEN_HEIGHT)
{
	Init();
}

Game::Game(GLfloat width, GLfloat height) :
	width(width),
	height(height)
{
	Init();
}

Game::~Game()
{
}

void Game::Init()
{
	window.CreateWindow(width, height, "OpenGL Sidescroller");

	camera.Init(width, height);
	camera.SetScale(2.0f);

	ResourceManager::LoadShader("Shaders/vShader2D.vs", "Shaders/fShader2D.frag", nullptr, "2D Shader");

	ResourceManager::GetShader("2D Shader").SetInteger("image", 0);
	ResourceManager::GetShader("2D Shader").SetMatrix4("projection", camera.GetCameraMatrix());

	spriteBatch.Init(ResourceManager::GetShader("2D Shader"));

	player = Player(glm::vec2(-48.0f, -42.0f), 180.0f);

	GameLoop();
}

void Game::GameLoop()
{
	GLfloat currentTime = 0.0f, previousTime = 0.0f;
	GLfloat elapsedTime = 0.0f;

	while (!glfwWindowShouldClose(window.GetWindow()))
	{
		currentTime = glfwGetTime();
		elapsedTime = currentTime - previousTime;
		previousTime = currentTime;

		glfwPollEvents();

		ProcessInput(elapsedTime);
		Update(elapsedTime);
		camera.Update(elapsedTime);

		glClearColor(0.2f, 0.1f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		Draw();

		glfwSwapBuffers(window.GetWindow());
	}

}

void Game::Update(GLfloat elapsedTime)
{
	camera.Update(elapsedTime);
	ResourceManager::GetShader("2D Shader").SetMatrix4("projection", camera.GetCameraMatrix());
	player.Update(elapsedTime);
}

void Game::Draw()
{
	spriteBatch.Begin();
	player.Draw();
	spriteBatch.End();
	spriteBatch.RenderBatches();
}

void Game::ProcessInput(GLfloat elapsedTime)
{
	if (wasKeyPressed(GLFW_KEY_A) && wasKeyPressed(GLFW_KEY_D))
		player.StopMoving();
	else if (wasKeyPressed(GLFW_KEY_A))
		player.MoveLeft();
	else if (wasKeyPressed(GLFW_KEY_D))
		player.MoveRight();
	if (!wasKeyPressed(GLFW_KEY_A) && !wasKeyPressed(GLFW_KEY_D))
		player.StopMoving();

	if (wasKeyPressed(GLFW_KEY_UP))
		camera.Move(MovementDirection::UP, elapsedTime);
	if (wasKeyPressed(GLFW_KEY_DOWN))
		camera.Move(MovementDirection::DOWN, elapsedTime);
	if (wasKeyPressed(GLFW_KEY_RIGHT))
		camera.Move(MovementDirection::RIGHT, elapsedTime);
	if (wasKeyPressed(GLFW_KEY_LEFT))
		camera.Move(MovementDirection::LEFT, elapsedTime);
}

GLboolean Game::wasKeyPressed(GLuint key)
{
	return Window::keys[key];
}

GLboolean Game::wasKeyReleased(GLuint key)
{
	return !(Window::keys[key]);
}
