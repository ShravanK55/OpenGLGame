#include "Actor.h"

Actor::Actor(unsigned long entityID) :
	Entity(entityID)
{}

Actor::~Actor() {}

bool Actor::Init(tinyxml2::XMLElement* node)
{
	if (node != nullptr)
		return true;
	else
		return false;
}

void Actor::Destroy() {}
