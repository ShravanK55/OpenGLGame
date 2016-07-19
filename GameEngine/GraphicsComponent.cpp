#include "GraphicsComponent.h"
#include "Sprite.h"
#include "GameObject.h"


GraphicsComponent::GraphicsComponent() :
	Component("Graphics"), sprite(nullptr)
{}

GraphicsComponent::GraphicsComponent(Entity* owner) :
	Component(owner, "Graphics"), sprite(nullptr)
{}

GraphicsComponent::GraphicsComponent(Entity* owner, const GLchar* filePath, const GLchar* name, const glm::vec2& size, GLboolean alpha) :
	Component(owner, "Graphics")
{
	sprite = new Sprite(filePath, name, size, alpha);
}

GraphicsComponent::GraphicsComponent(Entity* owner, Sprite* sprite) :
	Component(owner, "Graphics"), sprite(sprite)
{}

GraphicsComponent::~GraphicsComponent() { delete sprite; }

GameObject* GraphicsComponent::GetOwner() const { return static_cast<GameObject*>(owner); }

void GraphicsComponent::Update(GLfloat elapsedTime) { sprite->Update(elapsedTime); }

void GraphicsComponent::Draw(SpriteBatch* spriteBatch)
{
	sprite->Draw(spriteBatch, GetOwner()->GetTransformComponent()->GetPosition(), GetOwner()->GetTransformComponent()->GetRotation(),
				 GetOwner()->GetTransformComponent()->GetScale());
}
