#pragma once
#include <GLM/glm.hpp>
#include "Component.h"

class AnimatedSprite;

class AnimatedGraphicsComponent : public Component
{
public:
	const static char* name;

	AnimatedGraphicsComponent();
	AnimatedGraphicsComponent(Entity* owner);
	~AnimatedGraphicsComponent();

	virtual bool Init(tinyxml2::XMLElement* componentElement);

	static unsigned long GetID();
	const char* GetName() const;

	void HandleInput(Input* input);
	virtual void Update(GLfloat elapsedTime);
	virtual void Draw(SpriteBatch* spriteBatch);

protected:
	AnimatedSprite* sprite;

	virtual void SetupAnimations(tinyxml2::XMLElement* animationsNode);
};