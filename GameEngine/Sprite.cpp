#include "Sprite.h"
#include <GLM/detail/type_mat.hpp>
#include "SpriteBatch.h"


Sprite::Sprite() :
	posX(0), posY(0),
	width(0), height(0)
{}

Sprite::Sprite(const GLchar* filePath, const GLchar* name, const glm::vec2& position, const glm::vec2& size, GLboolean alpha) :
	posX(position.x), posY(position.y),
	width(size.x), height(size.y)
{
	Load(filePath, name, alpha);
}

Sprite::~Sprite()
{}

void Sprite::Load(const GLchar* filePath, const GLchar* name, GLboolean alpha)
{
	texture = ResourceManager::LoadTexture(filePath, alpha, name);
}

glm::vec2 Sprite::GetPosition() const { return glm::vec2(this->posX, this->posY); }
glm::vec2 Sprite::GetSize() const { return glm::vec2(this->width, this->height); }
glm::vec4 Sprite::GetRectangle() const { return glm::vec4(posX, posY, width, height); }
Texture Sprite::GetTexture() const { return texture; }

void Sprite::SetPosition(glm::vec2 position)
{
	posX = position.x;
	posY = position.y;
}

void Sprite::Draw()
{
	SpriteBatch::Draw(texture, glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), GetRectangle(), 0.0f);
}

void Sprite::Update(GLfloat elapsedTime) {}
