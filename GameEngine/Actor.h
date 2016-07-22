#pragma once
#include "Entity.h"


class Actor : public Entity
{
public:
	Actor(unsigned long entityID);
	~Actor();

	virtual bool Init(tinyxml2::XMLElement* node);
	virtual void Destroy();
};

