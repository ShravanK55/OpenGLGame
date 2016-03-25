#pragma once
#include <map>
#include <vector>

#include "Sprite.h"


class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite();
	AnimatedSprite(const GLchar* filePath, const GLchar* name, const glm::vec2& position, const glm::vec2& size, GLfloat timeToUpdate, GLboolean alpha = false);
	~AnimatedSprite();

	void PlayAnimation(const std::string& animation, GLboolean once = false);
	virtual void Update(GLfloat elapsedTime);
	virtual void Draw();

protected:
	GLfloat timeToUpdate;
	GLboolean currentAnimationOnce;
	std::string currentAnimation;

	void SetVisible(GLboolean visible);

	void AddAnimation(const std::string& name, GLint frames, GLfloat x, GLfloat y, GLfloat width, GLfloat height, glm::vec2 offset);
	void ResetAnimations();
	void StopAnimation();

	virtual void AnimationDone(std::string currentAnimation);
	virtual void SetupAnimations();

private:
	std::map<std::string, std::vector<glm::vec4> > animations;
	std::map<std::string, glm::vec2> offsets;

	GLint frameIndex;
	GLfloat timeElapsed;
	GLboolean visible;
};

