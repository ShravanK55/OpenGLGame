#pragma once
#include <vector>
#include <GLM/glm.hpp>

#include "Vertex.h"
#include "Texture.h"
#include "Shader.h"


// Contains information regarding a particular object to be drawn to the screen.
class Glyph
{
public:
	Texture texture;
	GLfloat depth;

	Vertex topLeft;
	Vertex bottomLeft;
	Vertex topRight;
	Vertex bottomRight;

	Glyph() {}

	Glyph(Texture texture, const glm::vec4& sourceRect, const glm::vec4& destRect, const GLfloat& depth, const GLfloat& scale,
		  const glm::vec4& color) :
		texture(texture),
		depth(depth)
	{
		topLeft.SetPosition(destRect.x, destRect.y + (destRect.w * scale));
		topLeft.SetColor(color.x, color.y, color.z, color.w);
		topLeft.SetUV(sourceRect.x, sourceRect.y + sourceRect.w);

		bottomLeft.SetPosition(destRect.x, destRect.y);
		bottomLeft.SetColor(color.x, color.y, color.z, color.w);
		bottomLeft.SetUV(sourceRect.x, sourceRect.y);

		bottomRight.SetPosition(destRect.x + (destRect.z * scale), destRect.y);
		bottomRight.SetColor(color.x, color.y, color.z, color.w);
		bottomRight.SetUV(sourceRect.x + sourceRect.z, sourceRect.y);

		topRight.SetPosition(destRect.x + (destRect.z * scale), destRect.y + (destRect.w * scale));
		topRight.SetColor(color.x, color.y, color.z, color.w);
		topRight.SetUV(sourceRect.x + sourceRect.z, sourceRect.y + sourceRect.w);
	}

	Glyph(Texture texture, const glm::vec4& sourceRect, const glm::vec4& destRect, const GLfloat& depth, const GLfloat& angle,
		  const GLfloat& scale, const glm::vec4& color) :
		texture(texture),
		depth(depth)
	{
		glm::vec2 halfSize(destRect.z * scale / 2.0f, destRect.w * scale / 2.0f);

		// Centre the points at the origin.
		glm::vec2 rTopLeft(-halfSize.x, halfSize.y);
		glm::vec2 rBottomLeft(-halfSize.x, -halfSize.y);
		glm::vec2 rBottomRight(halfSize.x, -halfSize.y);
		glm::vec2 rTopRight(halfSize.x, halfSize.y);

		GLfloat radAngle = glm::radians(angle);

		// Rotate the points about the origin, and return them to their original position.
		rTopLeft = RotatePoint(rTopLeft, radAngle) + halfSize;
		rBottomLeft = RotatePoint(rBottomLeft, radAngle) + halfSize;
		rBottomRight = RotatePoint(rBottomRight, radAngle) + halfSize;
		rTopRight = RotatePoint(rTopRight, radAngle) + halfSize;

		topLeft.SetPosition(destRect.x + rTopLeft.x, destRect.y + (rTopLeft.y));
		topLeft.SetColor(color.x, color.y, color.z, color.w);
		topLeft.SetUV(sourceRect.x, sourceRect.y + sourceRect.w);

		bottomLeft.SetPosition(destRect.x + rBottomLeft.x, destRect.y + rBottomLeft.y);
		bottomLeft.SetColor(color.x, color.y, color.z, color.w);
		bottomLeft.SetUV(sourceRect.x, sourceRect.y);

		bottomRight.SetPosition(destRect.x + (rBottomRight.x), destRect.y + rBottomRight.y);
		bottomRight.SetColor(color.x, color.y, color.z, color.w);
		bottomRight.SetUV(sourceRect.x + sourceRect.z, sourceRect.y);

		topRight.SetPosition(destRect.x + (rTopRight.x), destRect.y + (rTopRight.y));
		topRight.SetColor(color.x, color.y, color.z, color.w);
		topRight.SetUV(sourceRect.x + sourceRect.z, sourceRect.y + sourceRect.w);
	}

private:
	glm::vec2 RotatePoint(glm::vec2 position, GLfloat angle)
	{
		glm::vec2 newPosition;

		newPosition.x = (position.x * cos(angle)) - (position.y * sin(angle));
		newPosition.y = (position.x * sin(angle)) + (position.y * cos(angle));

		return newPosition;
	}
};

// Type of sorting to be done on glyphs.
enum class GlyphSortType
{
	NONE,
	FRONT_TO_BACK,
	BACK_TO_FRONT,
	TEXTURE
};

// Contains details about the batch that we are about to render.
class RenderBatch
{
public:
	GLuint offset;
	GLuint numVertices;
	Texture texture;

	RenderBatch(GLuint offset, GLuint numVertices, Texture texture);
};

class SpriteBatch
{
public:
	SpriteBatch();
	~SpriteBatch();

	// Initializes the sprite batch, by setting the shader to be used and creating the VAO.
	void Init(Shader shader);

	// Begins the batch process, sets the sort type and clears all previous render batches.
	void Begin(GlyphSortType sortType = GlyphSortType::TEXTURE);

	// Ends the batch process, orders all the glyphs by the required sort type and calls the CreateRenderBatches() function.
	void End();

	// Passing in the details of a game object, a glyph is creating containing information regarding it.
	void Draw(Texture texture, const glm::vec4& sourceRect, const glm::vec4& destRect, const GLfloat& depth, const GLfloat& scale,
					 const glm::vec4& color = glm::vec4(1.0f));

	// Overloaded draw function with rotation. Angle must be in degrees.
	void Draw(Texture texture, const glm::vec4& sourceRect, const glm::vec4& destRect, const GLfloat& depth, const GLfloat& angle,
					 const GLfloat& scale, const glm::vec4& color = glm::vec4(1.0f));

	// The created batches are now rendered to the screen.
	void RenderBatches();

private:
	GLuint vbo;
	GLuint vao;

	Shader shader;

	std::vector<Glyph> glyphs;
	std::vector<Glyph*> glyphPointers;
	std::vector<RenderBatch> renderBatches;

	GlyphSortType sortType;

	// Rotates a given position vector about an angle.
	glm::vec2 RotatePoint(glm::vec2 position, GLfloat angle);

	// Creates the render batches, comparing each glyph with the other by the required sort type.
	void CreateRenderBatches();
	// Creates the VAO.
	void CreateVertexArray();
	// Function to sort the glyphs.
	void SortGlyphs();

	static bool CompareFrontToBack(Glyph* a, Glyph* b);
	static bool CompareBackToFront(Glyph* a, Glyph* b);
	static bool CompareTexture(Glyph* a, Glyph* b);
};

