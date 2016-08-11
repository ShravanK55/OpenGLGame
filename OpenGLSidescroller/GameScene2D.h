#pragma once
#include "Scene2D.h"
#include "GameEntityFactory.h"

class GameScene2D : public Scene2D
{
public:
	GameScene2D();
	~GameScene2D();

protected:
	void LoadEntity(tinyxml2::XMLElement* entityNode);

private:
	GameEntityFactory* gameEntityFactory;
};
