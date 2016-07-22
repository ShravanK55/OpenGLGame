#include "Component.h"
#include "Entity.h"


Component::Component() :
	owner(nullptr)
{}

Component::Component(Entity* owner) :
	owner(owner)
{}

void Component::SetOwner(Entity* owner) { this->owner = owner; }
