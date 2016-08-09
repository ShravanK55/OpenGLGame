#include "Level.h"
#include <sstream>
#include "Tileset.h"
#include "tinyxml2.h"

/*
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
	for (unsigned int i = 0; i < tilesets.size(); i++)
	{
		delete tilesets[i];
	}

	for (unsigned int i = 0; i < layers.size(); i++)
	{
		delete layers[i];
	}
}

void Level::LoadLevel(const std::string& mapName)
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

	int levelWidth = tileWidth * hNumTiles;
	int levelHeight = tileHeight * vNumTiles;

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
							tileX = tileWidth * (tileCounter % hNumTiles);
							tileY = levelHeight - (tileHeight * (tileCounter / hNumTiles));

							int tilesetWidth = static_cast<int>(tileset->GetSize().x);
							int tilesetHeight = static_cast<int>(tileset->GetSize().y);

							int tilesetX, tilesetY;
							tilesetX = tileWidth * ((gid - tileset->firstGid) % (tilesetWidth / tileWidth));
							tilesetY = tileHeight * ((gid - tileset->firstGid) / (tilesetWidth / tileWidth) + 1);

							Tile* tile = new Tile(tileset, glm::vec2(tileX, tileY), glm::vec2(tileWidth, tileHeight), 0.0f, 1.0f, glm::vec2(tilesetX, tilesetY));
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
}

void Level::Update(GLfloat elapsedTime) {}

void Level::Draw(SpriteBatch* spriteBatch)
{
	for (unsigned int i = 0; i < layers.size(); i++)
	{
		for (unsigned int j = 0; j < layers[i]->tiles.size(); j++)
		{
			layers[i]->tiles[j]->Draw(spriteBatch);
		}
	}
}
*/
