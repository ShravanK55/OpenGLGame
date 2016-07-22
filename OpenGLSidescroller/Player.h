#pragma once
#include <GLM/glm.hpp>
#include "Actor.h"


class Player : public Actor
{
public:
	Player(unsigned long entityID);
	~Player();

	bool Init(tinyxml2::XMLElement* node);
	void Destroy();
};
