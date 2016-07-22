#include "AnimatedGraphicsComponent.h"
#include "AnimatedSprite.h"
#include "Entity.h"
#include "TransformComponent.h"


const char* AnimatedGraphicsComponent::name = "AnimatedGraphicsComponent";

AnimatedGraphicsComponent::AnimatedGraphicsComponent() :
	Component(), sprite(nullptr)
{}

AnimatedGraphicsComponent::AnimatedGraphicsComponent(Entity* owner) :
	Component(owner), sprite(nullptr)
{}

AnimatedGraphicsComponent::~AnimatedGraphicsComponent() { delete sprite; }

bool AnimatedGraphicsComponent::Init(tinyxml2::XMLElement* componentElement)
{
	if (componentElement != nullptr)
	{
		tinyxml2::XMLElement* sourceNode = componentElement->FirstChildElement("source");
		if (sourceNode != nullptr)
		{
			std::string filePath = sourceNode->Attribute("file_path");
			std::string spriteName = sourceNode->Attribute("sprite_name");
			GLfloat timeToUpdate = sourceNode->FloatAttribute("time_to_update");

			sprite = new AnimatedSprite(filePath.c_str(), spriteName.c_str(),
										owner->GetComponent<TransformComponent>(TransformComponent::name)->GetSize(), timeToUpdate);

			SetupAnimations(sourceNode->NextSiblingElement("animations"));

			return true;
		}

		else
			return false;
	}

	else
		return false;
}

unsigned long AnimatedGraphicsComponent::GetID() { return HashString::HashName(name); }
const char* AnimatedGraphicsComponent::GetName() const { return name; }

void AnimatedGraphicsComponent::HandleInput(Input* input) {}

void AnimatedGraphicsComponent::Update(GLfloat elapsedTime)
{
	sprite->Update(elapsedTime);
}

void AnimatedGraphicsComponent::Draw(SpriteBatch* spriteBatch)
{
	TransformComponent* transformComponent = owner->GetComponent<TransformComponent>(TransformComponent::name);
	sprite->Draw(spriteBatch, transformComponent->GetPosition(), transformComponent->GetRotation(), transformComponent->GetScale());
}

void AnimatedGraphicsComponent::SetupAnimations(tinyxml2::XMLElement* animationsNode)
{
	if (animationsNode != nullptr)
	{
		while (animationsNode)
		{
			tinyxml2::XMLElement* animationNode = animationsNode->FirstChildElement("animation");
			if (animationNode != nullptr)
			{
				while (animationNode)
				{
					std::string name = animationNode->Attribute("name");
					int frames = animationNode->IntAttribute("frames");
					int x = animationNode->IntAttribute("x");
					int y = animationNode->IntAttribute("y");
					int width = animationNode->IntAttribute("width");
					int height = animationNode->IntAttribute("height");
					int offsetX = animationNode->IntAttribute("offsetX");
					int offsetY = animationNode->IntAttribute("offsetY");

					sprite->AddAnimation(name, frames, x, y, width, height, glm::vec2(offsetX, offsetY));

					animationNode = animationNode->NextSiblingElement("animations");
				}
			}

			animationsNode = animationsNode->NextSiblingElement("animations");
		}
	}
}
