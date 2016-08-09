#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Component.h"
#include "tinyxml2.h"


class Entity
{
	friend class EntityFactory;
	friend class EntityManager;

public:
	Entity(unsigned long entityID) : id(entityID) {}

	virtual ~Entity()
	{
		for (auto iterator = componentMap.begin(); iterator != componentMap.end(); iterator++)
		{
			delete iterator->second;
		}
	}

	virtual bool Init(tinyxml2::XMLElement* entityElement)
	{
		if (entityElement != nullptr)
			return true;
		else
			return false;
	}

	virtual void Destroy() {}

	unsigned long GetID() const { return id; }

	template <class ComponentType>
	ComponentType* GetComponent()
	{
		auto iterator = componentMap.find(ComponentType::GetName());

		if (iterator != componentMap.end())
			return static_cast<ComponentType*>(iterator->second);

		else
			return nullptr;
	}

protected:
	unsigned long id;
	std::map<std::string, Component*> componentMap;

private:
	void AddComponent(Component* component)
	{
		componentMap.insert(std::pair<std::string, Component*> (component->GetName(), component));
		component->SetOwner(this);
	}
};

