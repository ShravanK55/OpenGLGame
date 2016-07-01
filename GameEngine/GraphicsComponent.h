#pragma once
#include <GLM/glm.hpp>
#include "Component.h"

class Sprite;
class GameObject;

class GraphicsComponent : public Component
{
public:
	GraphicsComponent();
	GraphicsComponent(Entity* owner);
	GraphicsComponent(Entity* owner, const GLchar* filePath, const GLchar* name, const glm::vec2& size, GLboolean alpha = false);
	virtual ~GraphicsComponent();

	GameObject* GetOwner() const;

	virtual void Update(GLfloat elapsedTime);
	virtual void Draw();

protected:
	Sprite* sprite;
};
