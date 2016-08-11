#include "GameScene2D.h"
#include "EntityManager.h"
#include "Tileset.h"
#include "Tile.h"


GameScene2D::GameScene2D() :
	Scene2D()
{
	gameEntityFactory = new GameEntityFactory();
}

GameScene2D::~GameScene2D()
{
	delete gameEntityFactory;
}


void GameScene2D::LoadScene(const std::string& mapName)
{
	tinyxml2::XMLDocument document;
	std::stringstream levelPath;
	levelPath << "Levels/" << mapName << ".tmx";

	document.LoadFile(levelPath.str().c_str());

	tinyxml2::XMLElement* mapNode = nullptr;
	mapNode = document.FirstChildElement("map");

	int tileWidth, tileHeight;
	mapNode->QueryIntAttribute("tilewidth", &tileWidth);
	mapNode->QueryIntAttribute("tileheight", &tileHeight);
	tileSize = glm::vec2(tileWidth, tileHeight);

	int hNumTiles, vNumTiles;
	mapNode->QueryIntAttribute("width", &hNumTiles);
	mapNode->QueryIntAttribute("height", &vNumTiles);
	levelSize = glm::vec2(hNumTiles, vNumTiles);

	GLfloat tileScale = 1.0f;

	tinyxml2::XMLElement* propertiesNode = mapNode->FirstChildElement("properties");
	tinyxml2::XMLElement* propertyElement = propertiesNode->FirstChildElement("property");
	if (propertyElement != nullptr)
	{
		while (propertyElement)
		{
			std::string propertyNodeName = propertyElement->Attribute("name");
			if (propertyNodeName == "Tile Scale")
				tileScale = propertyElement->FloatAttribute("value");

			propertyElement = propertyElement->NextSiblingElement("property");
		}
	}

	int levelWidth = tileWidth * tileScale * hNumTiles;
	int levelHeight = tileHeight * tileScale * vNumTiles;

	tinyxml2::XMLElement* tilesetNode = mapNode->FirstChildElement("tileset");
	if (tilesetNode != nullptr)
	{
		while (tilesetNode)
		{
			const char* tilesetName = tilesetNode->Attribute("name");
			int firstGid;
			tilesetNode->QueryIntAttribute("firstgid", &firstGid);

			const char* tilesetPath = tilesetNode->FirstChildElement("image")->Attribute("source");
			int tilesetWidth, tilesetHeight;
			tilesetNode->FirstChildElement("image")->QueryIntAttribute("width", &tilesetWidth);
			tilesetNode->FirstChildElement("image")->QueryIntAttribute("height", &tilesetHeight);

			tilesets.push_back(new Tileset(tilesetPath, tilesetName, firstGid, glm::vec2(tilesetWidth, tilesetHeight), tileSize, GL_TRUE));

			tilesetNode = tilesetNode->NextSiblingElement("tileset");
		}
	}

	tinyxml2::XMLElement* layerNode = nullptr;
	layerNode = mapNode->FirstChildElement("layer");
	if (layerNode != nullptr)
	{
		while (layerNode)
		{
			Layer* layer = new Layer();

			tinyxml2::XMLElement* dataNode = layerNode->FirstChildElement("data");
			if (dataNode != nullptr)
			{
				while (dataNode)
				{
					tinyxml2::XMLElement* tileNode = dataNode->FirstChildElement("tile");
					if (tileNode != nullptr)
					{
						int tileCounter = 0;

						while (tileNode)
						{
							int gid = tileNode->IntAttribute("gid");

							if (gid == 0)
							{
								tileCounter++;
								tileNode = tileNode->NextSiblingElement("tile");
								continue;
							}

							Tileset* tileset = nullptr;

							for (unsigned int i = 0; i < tilesets.size(); i++)
							{
								if (tilesets[i]->firstGid <= gid)
								{
									tileset = tilesets[i];
									break;
								}
							}

							if (tileset->firstGid == -1)
							{
								tileCounter++;
								tileNode = tileNode->NextSiblingElement("tile");
								continue;
							}

							int tileX = 0, tileY = 0;
							tileX = tileWidth * (tileCounter % hNumTiles) * tileScale;
							tileY = levelHeight - (tileHeight * (tileCounter / hNumTiles) * tileScale);

							int tilesetWidth = static_cast<int>(tileset->GetSize().x);
							int tilesetHeight = static_cast<int>(tileset->GetSize().y);

							int tilesetX, tilesetY;
							tilesetX = tileWidth * ((gid - tileset->firstGid) % (tilesetWidth / tileWidth));
							tilesetY = tileHeight * ((gid - tileset->firstGid) / (tilesetWidth / tileWidth) + 1);

							Tile* tile = new Tile(tileset, glm::vec2(tileX, tileY), 0.0f, tileScale, glm::vec2(tilesetX, tilesetY));
							layer->tiles.push_back(tile);
							tileCounter++;

							tileNode = tileNode->NextSiblingElement("tile");
						}
					}

					dataNode = dataNode->NextSiblingElement("data");
				}
			}

			layers.push_back(layer);

			layerNode = layerNode->NextSiblingElement("layer");
		}
	}

	tinyxml2::XMLElement* objectGroupNode = nullptr;
	objectGroupNode = mapNode->FirstChildElement("objectgroup");
	if (objectGroupNode != nullptr)
	{
		while (objectGroupNode)
		{
			std::string objectGroupName = objectGroupNode->Attribute("name");
			if (objectGroupName == "Entities")
			{
				tinyxml2::XMLElement* objectNode = nullptr;
				objectNode = objectGroupNode->FirstChildElement("object");
				if (objectNode != nullptr)
				{
					while (objectNode)
					{
						LoadEntity(objectNode);
						objectNode = objectNode->NextSiblingElement("object");
					}
				}
			}

			objectGroupNode = objectGroupNode->NextSiblingElement("objectgroup");
		}
	}
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
					std::string propertyNodeName = propertyNode->Attribute("name");
					if (propertyNodeName == "Source")
						entitySource = propertyNode->Attribute("value");

					propertyNode = propertyNode->NextSiblingElement("property");
				}
			}

			propertiesNode = propertiesNode->NextSiblingElement("properties");
		}
	}

	entityManager->AddEntity(gameEntityFactory->CreateEntity(entitySource.c_str()));
}
