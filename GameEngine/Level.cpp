#include "Level.h"
#include "Tileset.h"
#include "tinyxml2.h"


Level::Level() :
	levelName(""),
	playerSpawnPoint(glm::vec2()),
	levelSize(glm::vec2()),
	tileSize(glm::vec2())
{}

Level::Level(const std::string& levelName) :
	levelName(levelName),
	playerSpawnPoint(glm::vec2()),
	levelSize(glm::vec2()),
	tileSize(glm::vec2())
{
	LoadLevel(levelName);
}

Level::~Level()
{
	for (int i = 0; i < tilesets.size(); i++)
	{
		delete tilesets[i];
	}

	for (int i = 0; i < layers.size(); i++)
	{
		delete layers[i];
	}
}

void Level::LoadLevel(const std::string& mapName)
{
	tinyxml2::XMLDocument document;
	std::stringstream levelPath;
	levelPath << "Levels/" << mapName << ".tmx";
	if (document.LoadFile(levelPath.str().c_str()) != tinyxml2::XMLError::XML_SUCCESS)
	{
		std::cout << "Could not load the level document!" << std::endl;
		return;
	}

	tinyxml2::XMLElement* mapNode = document.FirstChildElement("map");

	int tileWidth, tileHeight;
	mapNode->QueryIntAttribute("tilewidth", &tileWidth);
	mapNode->QueryIntAttribute("tileheight", &tileHeight);
	tileSize = glm::vec2(tileWidth, tileHeight);

	int levelWidth, levelHeight;
	mapNode->QueryIntAttribute("width", &levelWidth);
	mapNode->QueryIntAttribute("height", &levelHeight);
	levelSize = glm::vec2(levelWidth, levelHeight);

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

	tinyxml2::XMLElement* layerNode = mapNode->FirstChildElement("layer");
	if (layerNode != nullptr)
	{
		while (layerNode)
		{
			Layer* layer = new Layer();

			tinyxml2::XMLElement* dataNode = layerNode->FirstChildElement("data");
			if (dataNode != nullptr)
			{
				tinyxml2::XMLElement* tileNode = dataNode->FirstChildElement("tile");
				while (tileNode)
				{
					int gid;
					tileNode->QueryIntAttribute("gid", &gid);

					tileNode = tileNode->NextSiblingElement("tile");
				}

				dataNode = dataNode->NextSiblingElement("data");
			}

			layers.push_back(layer);

			layerNode = layerNode->NextSiblingElement("layer");
		}
	}
}
