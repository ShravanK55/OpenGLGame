#pragma once
#include <string>
#include "tinyxml2.h"
#include "Input.h"
#include "HashString.h"

class Entity;
class SpriteBatch;

class Component
{
public:
	Component();
	Component(Entity* owner);
	virtual ~Component() {}

	virtual bool Init(tinyxml2::XMLElement* componentElement) = 0;
	virtual unsigned long GetIDFromName() { return HashString::HashName(""); }
	virtual const char* GetName() const = 0;
	void SetOwner(Entity* owner);

	virtual void HandleInput(Input* input) = 0;
	virtual void Update(GLfloat elapsedTime) = 0;
	virtual void Draw(SpriteBatch* spriteBatch) = 0;

protected:
	Entity* owner;
};

