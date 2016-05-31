#pragma once
#include <vector>
#include <algorithm>

#include <GL/glew.h>
#include <GLM/glm.hpp>

#include "Vertex.h"
#include "Texture.h"
#include "Shader.h"


enum class GlyphSortType
{
	NONE,
	FRONT_TO_BACK,
	BACK_TO_FRONT,
	TEXTURE
};

// Contains information regarding a particular object to be drawn to the screen.
struct Glyph
{
	Texture texture;
	GLfloat depth;

	Vertex topLeft;
	Vertex bottomLeft;
	Vertex topRight;
	Vertex bottomRight;
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
	static void Draw(Texture texture, const glm::vec4& sourceRect, const glm::vec4& destRect, const GLfloat& depth, const glm::vec4& color = glm::vec4(1.0f));

	// The created batches are now rendered to the screen.
	void RenderBatches();

private:
	GLuint vbo;
	GLuint vao;

	Shader shader;

	static std::vector<Glyph*> glyphs;
	std::vector<RenderBatch> renderBatches;

	GlyphSortType sortType;

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

