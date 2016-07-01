#pragma once
#include <GLM/glm.hpp>
#include "Component.h"

class AnimatedSprite;
class GameObject;

class AnimatedGraphicsComponent : public Component
{
public:
	AnimatedGraphicsComponent();
	AnimatedGraphicsComponent(Entity* owner);
	AnimatedGraphicsComponent(Entity* owner, const GLchar* filePath, const GLchar* name, const glm::vec2& size, GLfloat timeToUpdate,
							  GLboolean alpha = false);
	virtual ~AnimatedGraphicsComponent();

	GameObject* GetOwner() const;

	virtual void Update(GLfloat elapsedTime);
	virtual void Draw();

protected:
	AnimatedSprite* sprite;

	virtual void SetupAnimations() = 0;
};