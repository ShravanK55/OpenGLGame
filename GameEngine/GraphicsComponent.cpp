#include "GraphicsComponent.h"
#include "Entity.h"
#include "TransformComponent.h"


const char* GraphicsComponent::name = "GraphicsComponent";

GraphicsComponent::GraphicsComponent() :
	Component(), sprite(nullptr)
{}

GraphicsComponent::GraphicsComponent(Entity* owner) :
	Component(owner), sprite(nullptr)
{}

GraphicsComponent::~GraphicsComponent() { delete sprite; }

bool GraphicsComponent::Init(tinyxml2::XMLElement* componentElement)
{
	if (componentElement != nullptr)
		return true;
	else
		return false;
}

const char* GraphicsComponent::GetName() const { return name; }

void GraphicsComponent::HandleInput(Input* input) {}

void GraphicsComponent::Update(GLfloat elapsedTime) { sprite->Update(elapsedTime); }

void GraphicsComponent::Draw(SpriteBatch* spriteBatch)
{
	TransformComponent* transformComponent = owner->GetComponent<TransformComponent>(TransformComponent::name);
	sprite->Draw(spriteBatch, transformComponent->GetPosition(), transformComponent->GetRotation(), transformComponent->GetScale());
}
