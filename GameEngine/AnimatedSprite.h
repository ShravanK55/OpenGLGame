#pragma once
#include <map>
#include <vector>
#include "Sprite.h"


class AnimatedSprite : public Sprite
{
public:
	GLfloat timeToUpdate;
	GLboolean currentAnimationOnce;
	std::string currentAnimation;

	AnimatedSprite();
	AnimatedSprite(const GLchar* filePath, const GLchar* name, const glm::vec2& size, GLfloat timeToUpdate, GLboolean alpha = false);
	~AnimatedSprite();

	// Adds an animation to the list of animations.
	void AddAnimation(const std::string& name, GLint frames, GLfloat x, GLfloat y, GLfloat width, GLfloat height, glm::vec2 offset);

	// Plays the specified animation.
	void PlayAnimation(const std::string& animation, GLboolean once = false);

	// Clears the list of animations and offsets.
	void ResetAnimations();

	// Stops the current animation.
	void StopAnimation();

	// Updates the animated sprite frame counter.
	virtual void Update(GLfloat elapsedTime);

	// Passes the sprite's information to the spritebatch from which it is drawn.
	virtual void Draw(SpriteBatch* spriteBatch, glm::vec2 position);
	virtual void Draw(SpriteBatch* spriteBatch, glm::vec2 position, GLfloat rotation);
	virtual void Draw(SpriteBatch* spriteBatch, glm::vec2 position, GLfloat rotation, GLfloat scale);

	void SetVisible(GLboolean visible);

private:
	std::map<std::string, std::vector<glm::vec4> > animations;
	std::map<std::string, glm::vec2> offsets;

	GLint frameIndex;
	GLfloat timeElapsed;
	GLboolean visible;
};

