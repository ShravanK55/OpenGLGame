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

struct Glyph
{
	Texture texture;
	GLfloat depth;

	Vertex topLeft;
	Vertex bottomLeft;
	Vertex topRight;
	Vertex bottomRight;
};

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

	void Init(Shader shader);

	void Begin(GlyphSortType sortType = GlyphSortType::TEXTURE);
	void End();

	static void Draw(Texture texture, const glm::vec4& sourceRect, const glm::vec4& destRect, const GLfloat& depth, const glm::vec4& color = glm::vec4(1.0f));

	void RenderBatches();

private:
	GLuint vbo;
	GLuint vao;

	Shader shader;

	static std::vector<Glyph*> glyphs;
	std::vector<RenderBatch> renderBatches;

	GlyphSortType sortType;

	void CreateRenderBatches();
	void CreateVertexArray();
	void SortGlyphs();

	static bool CompareFrontToBack(Glyph* a, Glyph* b);
	static bool CompareBackToFront(Glyph* a, Glyph* b);
	static bool CompareTexture(Glyph* a, Glyph* b);
};

