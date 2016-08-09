#pragma once
#include <GLM/glm.hpp>
#include "Entity.h"


class Player : public Entity
{
public:
	Player(unsigned long entityID);
	~Player();

	bool Init(tinyxml2::XMLElement* node);
	void Destroy();
};
