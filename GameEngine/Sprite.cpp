#include "Sprite.h"
#include "SpriteBatch.h"


Sprite::Sprite() :
	spriteSize(glm::vec2(0.0f, 0.0f))
{}

Sprite::Sprite(const GLchar* filePath, const GLchar* name, const glm::vec2& size, GLboolean alpha) :
	spriteSize(size)
{
	Sprite::Load(filePath, name, alpha);
}

Sprite::~Sprite()
{}

void Sprite::Load(const GLchar* filePath, const GLchar* name, GLboolean alpha)
{
	texture = ResourceManager::LoadTexture(filePath, alpha, name);
}

glm::vec2 Sprite::GetSize() const { return spriteSize; }
Texture Sprite::GetTexture() const { return *texture; }

void Sprite::Draw(glm::vec2 position)
{
	SpriteBatch::Draw(*texture, glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), glm::vec4(position, spriteSize), 0.0f, 1.0f);
}

void Sprite::Draw(glm::vec2 position, GLfloat rotation)
{
	SpriteBatch::Draw(*texture, glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), glm::vec4(position, spriteSize), 0.0f, rotation, 1.0f);
}

void Sprite::Draw(glm::vec2 position, GLfloat rotation, GLfloat scale)
{
	SpriteBatch::Draw(*texture, glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), glm::vec4(position, spriteSize), 0.0f, rotation, scale);
}

void Sprite::Update(GLfloat elapsedTime) {}
