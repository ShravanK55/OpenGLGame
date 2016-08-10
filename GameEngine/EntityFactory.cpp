#include "Entity.h"
#include "EntityFactory.h"
#include "TransformComponent.h"
#include "GraphicsComponent.h"
#include "AnimatedGraphicsComponent.h"


EntityFactory::EntityFactory() :
	nextEntityId(0)
{
	componentFactory.Register<TransformComponent>(TransformComponent::name);
	componentFactory.Register<GraphicsComponent>(GraphicsComponent::name);
	componentFactory.Register<AnimatedGraphicsComponent>(AnimatedGraphicsComponent::name);
}

EntityFactory::~EntityFactory() {}

Entity* EntityFactory::CreateEntity(const char* filePath)
{
	tinyxml2::XMLDocument document;
	auto errorCode = document.LoadFile(filePath);

	if (errorCode)
	{
		std::cout << "Failed to read the entity's document." << std::endl;
		return nullptr;
	}

	tinyxml2::XMLElement* entityElement = document.FirstChildElement();
	if (entityElement != nullptr)
	{
		unsigned long entityID = GetNextEntityID();
		Entity* entity = new Entity(entityID);

		if (!entity->Init(entityElement))
		{
			std::cout << "Problem with initializing the entity. Entity number: " << entityID << std::endl;
			return nullptr;
		}

		tinyxml2::XMLElement* componentElement = entityElement->FirstChildElement();
		if (componentElement != nullptr)
		{
			while (componentElement != nullptr)
			{
				Component* component = CreateComponent(componentElement, entity);

				if (component == nullptr)
				{
					std::cout << "Failed to create an entity component. Entity number: " << entityID << std::endl;
					return nullptr;
				}

				componentElement = componentElement->NextSiblingElement();
			}
		}

		return entity;
	}

	std::cout << "Problem occurred creating an entity. Entity number: " << nextEntityId << std::endl;
	return nullptr;
}

Component* EntityFactory::CreateComponent(tinyxml2::XMLElement* componentElement, Entity* owner)
{
	const char* componentName = componentElement->Name();

	Component* component = componentFactory.Create(componentName);

	if (component != nullptr)
	{
		owner->AddComponent(component);
		component->SetOwner(owner);

		if (!component->Init(componentElement))
		{
			std::cout << "Problem occurred during initialization of the component." << std::endl;
			return nullptr;
		}
	}
	else
	{
		std::cout << "Error in creating the component." << std::endl;
		return nullptr;
	}

	return component;
}

unsigned long EntityFactory::GetNextEntityID() { return nextEntityId++; }
