#pragma once
#include <GLM/glm.hpp>

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

	// Makes the camera to center on a position.
	void CenterAt(const glm::vec2& position);
	
	// Initializes the camera. Sets up the required ortho matrix and translates it to the centre of the screen.
	void Init(GLfloat screenWidth, GLfloat screenHeight);

	// Updates the camera when needed to move to it's new position.
	void Update(GLfloat elapsedTime);

	/* Moves the camera in the required direction and signals it to update.
	 * Since we actually move the game world and not the camera itself, the camera's position is moved opposite to the usual convention.
	 */
	void Move(MovementDirection direction, GLfloat elapsedTime);

private:
	// The camera's position is at the bottom left corner of the screen.
	glm::vec2 position;

	GLfloat screenWidth, screenHeight;
	GLboolean needsUpdate;
	glm::vec2 deltaMove;
	glm::mat4 cameraMatrix;
	glm::mat4 orthoMatrix;
	GLfloat scale;
	GLfloat cameraSpeed;
};

