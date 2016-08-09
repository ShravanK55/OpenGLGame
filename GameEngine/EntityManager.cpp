#include "EntityManager.h"

EntityManager::EntityManager() {}
EntityManager::~EntityManager() { Clear(); }

void EntityManager::Update(GLfloat elapsedTime)
{
	for (auto entityItr = entityMap.begin(); entityItr != entityMap.end(); entityItr++)
	{
		auto componentMap = entityItr->second->componentMap;

		for (auto componentItr = componentMap.begin(); componentItr != componentMap.end(); componentItr++)
		{
			componentItr->second->Update(elapsedTime);
		}
	}
}

void EntityManager::Draw(SpriteBatch* spriteBatch)
{
	for (auto entityItr = entityMap.begin(); entityItr != entityMap.end(); entityItr++)
	{
		auto componentMap = entityItr->second->componentMap;

		for (auto componentItr = componentMap.begin(); componentItr != componentMap.end(); componentItr++)
		{
			componentItr->second->Draw(spriteBatch);
		}
	}
}

void EntityManager::HandleInput(Input* input)
{
	for (auto entityItr = entityMap.begin(); entityItr != entityMap.end(); entityItr++)
	{
		auto componentMap = entityItr->second->componentMap;

		for (auto componentItr = componentMap.begin(); componentItr != componentMap.end(); componentItr++)
		{
			componentItr->second->HandleInput(input);
		}
	}
}

void EntityManager::AddEntity(Entity* entity) { entityMap.insert(std::pair<unsigned long, Entity*>(entity->GetID(), entity)); }

void EntityManager::Clear()
{
	for (auto itr = entityMap.begin(); itr != entityMap.end(); itr++)
	{
		delete itr->second;
	}

	entityMap.clear();
}
