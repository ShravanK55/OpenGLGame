#pragma once
#include "Entity.h"

class GameObject : public Entity
{
public:
	GameObject() :
		Entity()
	{}
	virtual ~GameObject() {}

	virtual void Update(float elapsedTime) = 0;
};
