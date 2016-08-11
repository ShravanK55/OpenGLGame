#pragma once
#include <string>
#include "Scene2D.h"
#include "GameEntityFactory.h"

class GameScene2D : public Scene2D
{
public:
	GameScene2D();
	~GameScene2D();

	void LoadScene(const std::string& mapName);

protected:
	void LoadEntity(tinyxml2::XMLElement* entityNode);

private:
	GameEntityFactory* gameEntityFactory;
};
