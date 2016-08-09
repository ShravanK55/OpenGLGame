#pragma once
#include <GLM/glm.hpp>
#include "Component.h"
#include "AnimatedSprite.h"


class AnimatedGraphicsComponent : public Component
{
public:
	static const char* name;

	AnimatedGraphicsComponent();
	AnimatedGraphicsComponent(Entity* owner);
	~AnimatedGraphicsComponent();

	virtual bool Init(tinyxml2::XMLElement* componentElement);

	const char* GetName() const;

	void HandleInput(Input* input);
	virtual void Update(GLfloat elapsedTime);
	virtual void Draw(SpriteBatch* spriteBatch);

protected:
	AnimatedSprite* sprite;

	virtual void SetupAnimations(tinyxml2::XMLElement* animationsNode);
};