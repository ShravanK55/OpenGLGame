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
	delete window;
	delete player;
	delete camera;
	delete spriteBatch;
}

void Game::Init()
{
	window = new Window();
	window->CreateWindow(width, height, "OpenGL Sidescroller");

	camera = new Camera2D();
	camera->Init(width, height);
	camera->SetScale(2.0f);

	ResourceManager::LoadShader("Shaders/vShader2D.vs", "Shaders/fShader2D.frag", nullptr, "2D Shader");

	ResourceManager::GetShader("2D Shader").SetInteger("image", 0);
	ResourceManager::GetShader("2D Shader").SetMatrix4("projection", camera->GetCameraMatrix());

	spriteBatch = new SpriteBatch();
	spriteBatch->Init(ResourceManager::GetShader("2D Shader"));

	player = new Player(glm::vec2(-48.0f, -42.0f), glm::vec2(96.0f, 84.0f));

	GameLoop();
}

void Game::GameLoop()
{
	GLfloat currentTime = 0.0f, previousTime = 0.0f;
	GLfloat elapsedTime = 0.0f;

	while (!glfwWindowShouldClose(window->GetWindow()))
	{
		currentTime = glfwGetTime();
		elapsedTime = currentTime - previousTime;
		previousTime = currentTime;

		glfwPollEvents();

		ProcessInput(elapsedTime);
		Update(elapsedTime);
		camera->Update(elapsedTime);

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		Draw();

		glfwSwapBuffers(window->GetWindow());
	}
}

void Game::Update(GLfloat elapsedTime)
{
	camera->Update(elapsedTime);
	ResourceManager::GetShader("2D Shader").SetMatrix4("projection", camera->GetCameraMatrix());
	player->Update(elapsedTime);
}

void Game::Draw()
{
	spriteBatch->Begin();
	player->Draw();
	spriteBatch->End();
	spriteBatch->RenderBatches();
}

void Game::ProcessInput(GLfloat elapsedTime)
{
	player->HandleInput(window->input);

	if (window->input->WasKeyPressed(GLFW_KEY_UP))
		camera->Move(MovementDirection::UP, elapsedTime);
	if (window->input->WasKeyPressed(GLFW_KEY_DOWN))
		camera->Move(MovementDirection::DOWN, elapsedTime);
	if (window->input->WasKeyPressed(GLFW_KEY_RIGHT))
		camera->Move(MovementDirection::RIGHT, elapsedTime);
	if (window->input->WasKeyPressed(GLFW_KEY_LEFT))
		camera->Move(MovementDirection::LEFT, elapsedTime);
}
