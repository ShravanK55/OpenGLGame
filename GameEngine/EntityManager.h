#pragma once
#include <map>
#include "Entity.h"

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	void Update(GLfloat elapsedTime);
	void Draw(SpriteBatch* spriteBatch);
	void HandleInput(Input* input);

	void AddEntity(Entity* entity);
	void Clear();

private:
	std::map<unsigned long, Entity*> entityMap;
};