#include "Camera2D.h"
#include <GLM/gtc/matrix_transform.hpp>


Camera2D::Camera2D() :
	screenWidth(Global::SCREEN_WIDTH),
	screenHeight(Global::SCREEN_HEIGHT),
	needsUpdate(true),
	position(0.0f, 0.0f),
	deltaMove(0.0f, 0.0f),
	cameraMatrix(1.0f),
	orthoMatrix(1.0f),
	scale(1.0f),
	cameraSpeed(200.0f)
{}

Camera2D::~Camera2D() {}

glm::vec2 Camera2D::GetPosition() const { return position; }
glm::mat4 Camera2D::GetCameraMatrix() const { return cameraMatrix; }

void Camera2D::SetPosition(const glm::vec2& position)
{
	this->position = position;
	needsUpdate = true;
}

void Camera2D::SetScale(const GLfloat& scale)
{
	this->scale = scale;
	needsUpdate = true;
}

void Camera2D::CenterAt(const glm::vec2& position)
{
	this->position = glm::vec2(screenWidth / 2, screenHeight / 2) - position;
	needsUpdate = true;
}

void Camera2D::Init(GLfloat screenWidth, GLfloat screenHeight)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	orthoMatrix = glm::ortho(position.x, position.x + screenWidth, position.y, position.y + screenHeight);
	cameraMatrix = orthoMatrix;
	needsUpdate = true;
}

void Camera2D::Update(GLfloat elapsedTime)
{
	if (needsUpdate)
	{
		cameraMatrix = glm::translate(orthoMatrix, glm::vec3(position, 0.0f));
		cameraMatrix = glm::scale(cameraMatrix, glm::vec3(scale, scale, 1.0f));
		needsUpdate = false;
	}
}

void Camera2D::Move(MovementDirection direction, GLfloat elapsedTime)
{
	GLfloat velocity = cameraSpeed * elapsedTime;
	if (direction == MovementDirection::UP)
		position.y -= velocity;
	if (direction == MovementDirection::DOWN)
		position.y += velocity;
	if (direction == MovementDirection::RIGHT)
		position.x -= velocity;
	if (direction == MovementDirection::LEFT)
		position.x += velocity;

	needsUpdate = true;
}
