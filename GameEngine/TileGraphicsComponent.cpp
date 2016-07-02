#include "TileGraphicsComponent.h"
#include "Tileset.h"
#include "Tile.h"


TileGraphicsComponent::TileGraphicsComponent() :
	GraphicsComponent(), tileset(nullptr), tilesetPosition(glm::vec2())
{}

TileGraphicsComponent::TileGraphicsComponent(Entity* owner) :
	GraphicsComponent(owner), tileset(nullptr), tilesetPosition(glm::vec2())
{}

TileGraphicsComponent::TileGraphicsComponent(Entity* owner, Tileset* tileset, const glm::vec2& tilesetPosition) :
	GraphicsComponent(owner), tileset(tileset), tilesetPosition(tilesetPosition)
{}

TileGraphicsComponent::~TileGraphicsComponent() {}

Tile* TileGraphicsComponent::GetOwner() const { return static_cast<Tile*>(owner); }

void TileGraphicsComponent::Update(GLfloat elapsedTime) {}

void TileGraphicsComponent::Draw()
{
	tileset->Draw(GetOwner()->GetTransformComponent()->GetPosition(), GetOwner()->GetTransformComponent()->GetRotation(),
				  GetOwner()->GetTransformComponent()->GetScale(), tilesetPosition);
}
