#include "Game.h"

Game::Game() :
	width(Global::SCREEN_WIDTH),
	height(Global::SCREEN_HEIGHT)
{
	Init();
	GameLoop();
}

Game::~Game()
{
	ResourceManager::Clear();
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
	camera->SetScale(1.0f);
	camera->CenterAt(glm::vec2(0.0f, 0.0f));

	ResourceManager::LoadShader("Shaders/vShader2D.vs", "Shaders/fShader2D.frag", nullptr, "2D Shader");

	ResourceManager::GetShader("2D Shader").SetInteger("image", 0);
	ResourceManager::GetShader("2D Shader").SetMatrix4("projection", camera->GetCameraMatrix());

	spriteBatch = new SpriteBatch();
	spriteBatch->Init(ResourceManager::GetShader("2D Shader"));

	player = new Player(PlayerConstants::SPAWN_POINT, PlayerConstants::SPRITE_SIZE,
						PlayerConstants::DEFAULT_ROTATION, PlayerConstants::SPRITE_SCALE);
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

		glClearColor(43.0f / 255.0f, 47.0f / 255.0f, 63.0f / 255.0f, 0.0f);
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
