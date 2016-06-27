#pragma once
#include <GLM/glm.hpp>
#include "Component.h"

class TransformComponent : public Component
{
public:
	TransformComponent() :
		position(glm::vec2(0, 0)),
		size(glm::vec2(0, 0)),
		rotation(0.0f),
		scale(0.0f)
	{}

	TransformComponent(Entity* owner) :
		Component(owner),
		position(glm::vec2(0, 0)),
		size(glm::vec2(0, 0)),
		rotation(0.0f),
		scale(0.0f)
	{}

	TransformComponent(Entity* owner, glm::vec2 position, glm::vec2 size) :
		Component(owner),
		position(position),
		size(size),
		rotation(0.0f),
		scale(0.0f)
	{}

	TransformComponent(Entity* owner, glm::vec2 position, glm::vec2 size, GLfloat rotation) :
		Component(owner),
		position(position),
		size(size),
		rotation(rotation),
		scale(0.0f)
	{}

	TransformComponent(Entity* owner, glm::vec2 position, glm::vec2 size, GLfloat rotation, GLfloat scale) :
		Component(owner),
		position(position),
		size(size),
		rotation(rotation),
		scale(scale)
	{}

	~TransformComponent() {}

	void Update(GLfloat elapsedTime) {}

	glm::vec2 GetPosition() const { return position; }
	glm::vec2 GetSize() const { return size; }
	GLfloat GetRotation() const { return rotation; }
	GLfloat GetScale() const { return scale; }

	void SetPosition(glm::vec2 position) { this->position = position; }
	void SetSize(glm::vec2 size) { this->size = size; }
	void SetRotation(GLfloat rotation) { this->rotation = rotation; }
	void SetScale(GLfloat scale) { this->scale = scale; }

private:
	glm::vec2 position;
	glm::vec2 size;
	GLfloat rotation;
	GLfloat scale;
};

