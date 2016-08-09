#pragma once
#include <GLM/glm.hpp>
#include "Component.h"

class TransformComponent : public Component
{
public:
	static const char* name;

	TransformComponent();
	TransformComponent(glm::vec2 position, glm::vec2 size);
	TransformComponent(glm::vec2 position, glm::vec2 size, GLfloat rotation);
	TransformComponent(glm::vec2 position, glm::vec2 size, GLfloat rotation, GLfloat scale);
	TransformComponent(Entity* owner);
	TransformComponent(Entity* owner, glm::vec2 position, glm::vec2 size);
	TransformComponent(Entity* owner, glm::vec2 position, glm::vec2 size, GLfloat rotation);
	TransformComponent(Entity* owner, glm::vec2 position, glm::vec2 size, GLfloat rotation, GLfloat scale);

	~TransformComponent() {}

	bool Init(tinyxml2::XMLElement* componentElement);

	const char* GetName() const;

	glm::vec2 GetPosition() const;
	glm::vec2 GetSize() const;
	GLfloat GetRotation() const;
	GLfloat GetScale() const;

	void SetPosition(glm::vec2 position);
	void SetSize(glm::vec2 size);
	void SetRotation(GLfloat rotation);
	void SetScale(GLfloat scale);

	void HandleInput(Input* input);
	void Update(GLfloat elapsedTime);
	void Draw(SpriteBatch* spriteBatch);

private:
	glm::vec2 position;
	glm::vec2 size;
	GLfloat rotation;
	GLfloat scale;
};

