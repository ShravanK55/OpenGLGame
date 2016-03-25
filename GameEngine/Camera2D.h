#pragma once
#include <GL/glew.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>

#include "Globals.h"

enum class MovementDirection
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Camera2D
{
public:
	Camera2D();
	~Camera2D();

	glm::vec2 GetPosition() const;
	glm::mat4 GetCameraMatrix() const;

	void SetPosition(const glm::vec2& position);
	void SetScale(const GLfloat& scale);
	
	void Init(GLfloat screenWidth, GLfloat screenHeight);
	void Update(GLfloat elapsedTime);
	void Move(MovementDirection direction, GLfloat elapsedTime);

private:
	GLfloat screenWidth, screenHeight;
	GLboolean needsUpdate;
	glm::vec2 position;
	glm::vec2 deltaMove;
	glm::mat4 cameraMatrix;
	glm::mat4 orthoMatrix;
	GLfloat scale;
	GLfloat cameraSpeed;
};

