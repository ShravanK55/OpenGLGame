#include "AnimatedGraphicsComponent.h"
#include "AnimatedSprite.h"
#include "GameObject.h"


AnimatedGraphicsComponent::AnimatedGraphicsComponent() :
	Component("Animated Graphics"), sprite(nullptr)
{}

AnimatedGraphicsComponent::AnimatedGraphicsComponent(Entity* owner) :
	Component(owner, "Animated Graphics"), sprite(nullptr)
{}

AnimatedGraphicsComponent::AnimatedGraphicsComponent(Entity* owner, const GLchar* filePath, const GLchar* name,
													 const glm::vec2& size, GLfloat timeToUpdate, GLboolean alpha) :
	Component(owner, "Animated Graphics")
{
	sprite = new AnimatedSprite(filePath, name, size, timeToUpdate, alpha);
}

AnimatedGraphicsComponent::~AnimatedGraphicsComponent() { delete sprite; }

GameObject* AnimatedGraphicsComponent::GetOwner() const { return static_cast<GameObject*>(owner); }

void AnimatedGraphicsComponent::Update(GLfloat elapsedTime)
{
	sprite->Update(elapsedTime);
}

void AnimatedGraphicsComponent::Draw()
{
	sprite->Draw(GetOwner()->GetTransformComponent()->GetPosition(), GetOwner()->GetTransformComponent()->GetRotation(),
				 GetOwner()->GetTransformComponent()->GetScale());
}
