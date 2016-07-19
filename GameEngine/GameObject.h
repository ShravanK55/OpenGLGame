#pragma once
#include <GLM/glm.hpp>
#include "Entity.h"
#include "TransformComponent.h"

class GameObject : public Entity
{
public:
	GameObject() :
		Entity()
	{}

	GameObject(glm::vec2 position, glm::vec2 size, GLfloat rotation, GLfloat scale)
	{
		Entity::AddComponent(new TransformComponent(this, position, size, rotation, scale));
	}

	virtual ~GameObject() {}

	TransformComponent* GetTransformComponent()
	{
		for (unsigned int i = 0; i < components.size(); i++)
		{
			if (components[i]->GetTag() == "Transform")
				return static_cast<TransformComponent*>(components[i]);
		}

		return nullptr;
	}

	virtual void Update(float elapsedTime) = 0;
};
