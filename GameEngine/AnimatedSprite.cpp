#include "AnimatedSprite.h"
#include "SpriteBatch.h"


AnimatedSprite::AnimatedSprite() :
	Sprite(),
	timeToUpdate(0),
	currentAnimationOnce(false),
	currentAnimation(""),
	frameIndex(0),
	timeElapsed(0),
	visible(true)
{}

AnimatedSprite::AnimatedSprite(const GLchar* filePath, const GLchar* name, const glm::vec2& position, const glm::vec2& size, GLfloat timeToUpdate, GLboolean alpha) :
	Sprite(filePath, name, position, size, alpha),
	timeToUpdate(timeToUpdate),
	currentAnimationOnce(false),
	currentAnimation(""),
	frameIndex(0),
	timeElapsed(0),
	visible(true)
{}

AnimatedSprite::~AnimatedSprite()
{
}


void AnimatedSprite::PlayAnimation(const std::string& animation, GLboolean once)
{
	currentAnimationOnce = once;

	if (currentAnimation != animation)
	{
		currentAnimation = animation;
		frameIndex = 0;
	}
}

void AnimatedSprite::Update(GLfloat elapsedTime)
{
	Sprite::Update(elapsedTime);

	timeElapsed += elapsedTime;

	if (timeElapsed > timeToUpdate)
	{
		timeElapsed -= timeToUpdate;

		if (frameIndex < animations[currentAnimation].size() - 1)
			frameIndex++;

		else
		{
			if (currentAnimationOnce)
				SetVisible(false);

			frameIndex = 0;
		}
	}
}

void AnimatedSprite::Draw(glm::vec2 position)
{
	if (visible)
	{
		SpriteBatch::Draw(texture, animations[currentAnimation][frameIndex], glm::vec4(position, spriteSize), 0.0f);
	}
}

void AnimatedSprite::SetVisible(GLboolean visible) { this->visible = visible; }

void AnimatedSprite::AddAnimation(const std::string& name, GLint frames, GLfloat x, GLfloat y, GLfloat width, GLfloat height, glm::vec2 offset)
{
	std::vector<glm::vec4> rectangles;

	for (int i = 0; i < frames; i++)
	{
		glm::vec4 rectangle;
		rectangle.x = ((i * width) + x) / texture.GetWidth();
		rectangle.y = 1.0f - ((y + height) / texture.GetHeight());
		rectangle.z = width / texture.GetWidth();
		rectangle.w = height / texture.GetHeight();

		rectangles.push_back(rectangle);
	}

	animations.insert(std::pair<std::string, std::vector<glm::vec4> >(name, rectangles));
	offsets.insert(std::pair<std::string, glm::vec2>(name, offset));
}

void AnimatedSprite::ResetAnimations()
{
	animations.clear();
	offsets.clear();
}

void AnimatedSprite::StopAnimation()
{
	frameIndex = 0;
}
