#include "GameScene2D.h"
#include "EntityManager.h"


GameScene2D::GameScene2D() :
	Scene2D()
{
	gameEntityFactory = new GameEntityFactory();
}

GameScene2D::~GameScene2D()
{
	delete gameEntityFactory;
}

void GameScene2D::LoadEntity(tinyxml2::XMLElement* entityNode)
{
	std::string entitySource;

	tinyxml2::XMLElement* propertiesNode = nullptr;
	propertiesNode = entityNode->FirstChildElement("properties");
	if (propertiesNode != nullptr)
	{
		while (propertiesNode)
		{
			tinyxml2::XMLElement* propertyNode = nullptr;
			propertyNode = propertiesNode->FirstChildElement("property");
			if (propertyNode != nullptr)
			{
				while (propertyNode)
				{
					if (propertiesNode->Attribute("name") == "Source")
						entitySource = propertyNode->Attribute("value");

					propertyNode = propertyNode->NextSiblingElement("property");
				}
			}

			propertiesNode = propertiesNode->NextSiblingElement("properties");
		}
	}

	entityManager->AddEntity(gameEntityFactory->CreateEntity(entitySource.c_str()));
}
