#pragma once
#include <GL/glew.h>
#include <GLM/glm.hpp>

struct Global
{
	static const GLint SCREEN_WIDTH = 1024;
	static const GLint SCREEN_HEIGHT = 768;
};

namespace PlayerConstants
{
	const glm::vec2 SPAWN_POINT = glm::vec2(-16.0f, -16.0f);
	const glm::vec2 SPRITE_SIZE = glm::vec2(32.0f, 32.0f);
	const GLfloat DEFAULT_ROTATION = 0.0f;
	const GLfloat SPRITE_SCALE = 2.0f;
}