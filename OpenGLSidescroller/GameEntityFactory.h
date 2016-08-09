#pragma once
#include "EntityFactory.h"
#include "PlayerGraphicsComponent.h"
#include "PlayerInputComponent.h"
#include "PlayerPhysicsComponent.h"
#include "PlayerStateComponent.h"


class GameEntityFactory : public EntityFactory
{
public:
	GameEntityFactory() :
		EntityFactory()
	{
		componentFactory.Register<PlayerGraphicsComponent>(PlayerGraphicsComponent::name);
		componentFactory.Register<PlayerInputComponent>(PlayerInputComponent::name);
		componentFactory.Register<PlayerPhysicsComponent>(PlayerPhysicsComponent::name);
		componentFactory.Register<PlayerStateComponent>(PlayerStateComponent::name);
	}

	~GameEntityFactory() {}
};
