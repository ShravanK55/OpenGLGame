#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Component.h"
#include "tinyxml2.h"


class Entity
{
public:
	Entity(unsigned long entityID) : id(entityID) {}

	virtual ~Entity()
	{
		for (auto iterator = componentMap.begin(); iterator != componentMap.end(); iterator++)
		{
			delete iterator->second;
		}
	}

	virtual bool Init(tinyxml2::XMLElement*) = 0;
	virtual void Destroy() = 0;

	unsigned long GetID() const { return id; }

	template <class ComponentType>
	ComponentType* GetComponent(std::string name)
	{
		auto iterator = componentMap.find(HashString::HashName(name));

		if (iterator != componentMap.end())
			return static_cast<ComponentType*>(iterator->second);

		else
			return nullptr;
	}

protected:
	unsigned long id;
	std::map<unsigned long, Component*> componentMap;

private:
	void AddComponent(Component* component)
	{
		componentMap.insert(std::pair<unsigned long, Component*> (component->GetIDFromName(), component));
	}
};

