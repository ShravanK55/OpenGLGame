#include "Component.h"
#include "Entity.h"


Component::Component() :
	owner(nullptr), tag("")
{}

Component::Component(Entity* owner) :
	owner(owner), tag("")
{}

Component::Component(std::string tag) :
	owner(owner), tag("")
{}

Component::Component(Entity* owner, std::string tag) :
	owner(owner),tag(tag)
{}

std::string Component::GetTag() const { return tag; }
void Component::SetOwner(Entity* owner) { this->owner = owner; }

void Component::HandleInput(Input* input) {}
void Component::Draw() {}
