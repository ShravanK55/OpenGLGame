#pragma once
#include <map>
#include "tinyxml2.h"
#include "Component.h"


template <class BaseType, class SubType>
BaseType* GenericObjectCreationFunction() { return new SubType; }

template <class BaseClass, class IdType>
class GenericObjectFactory
{
	typedef BaseClass* (*ObjectCreationFunction)();

private:
	std::map<IdType, ObjectCreationFunction> creationFunctions;

public:
	template <class SubClass>
	bool Register(IdType id)
	{
		auto itr = creationFunctions.find(id);

		if (itr == creationFunctions.end())
		{
			creationFunctions[id] = &GenericObjectCreationFunction<BaseClass, SubClass>;
			return true;
		}

		return false;
	}

	BaseClass* Create(IdType id)
	{
		auto itr = creationFunctions.find(id);

		if (itr != creationFunctions.end())
		{
			ObjectCreationFunction creationFunction = itr->second;
			return creationFunction();
		}

		return nullptr;
	}
};


class EntityFactory
{
public:
	EntityFactory();
	virtual ~EntityFactory();

	Entity* CreateEntity(const char* filePath);
	virtual Component* CreateComponent(tinyxml2::XMLElement* componentElement, Entity* owner);

	unsigned long GetNextEntityID();

protected:
	GenericObjectFactory<Component, std::string> componentFactory;

private:
	unsigned long nextEntityId;
};




