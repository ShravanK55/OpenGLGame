#include "SpriteBatch.h"
#include <algorithm>


std::vector<Glyph*> SpriteBatch::glyphPointers;
std::vector<Glyph> SpriteBatch::glyphs;

RenderBatch::RenderBatch(GLuint offset, GLuint numVertices, Texture texture) :
	offset(offset),
	numVertices(numVertices),
	texture(texture)
{}

SpriteBatch::SpriteBatch() :
	vbo(0),
	vao(0),
	sortType(GlyphSortType::TEXTURE)
{}

SpriteBatch::~SpriteBatch() {}


void SpriteBatch::Init(Shader shader)
{
	this->shader = shader;
	CreateVertexArray();
}

void SpriteBatch::Begin(GlyphSortType sortType)
{
	this->sortType = sortType;
	renderBatches.clear();
	glyphs.clear();
}

void SpriteBatch::End()
{
	glyphPointers.resize(glyphs.size());
	for (int i = 0; i < glyphs.size(); i++)
	{
		glyphPointers[i] = &glyphs[i];
	}

	SortGlyphs();
	CreateRenderBatches();
}

void SpriteBatch::Draw(Texture texture, const glm::vec4& sourceRect, const glm::vec4& destRect, const GLfloat& depth, const GLfloat& scale,
					   const glm::vec4& color)
{
	glyphs.emplace_back(texture, sourceRect, destRect, depth, scale, color);
}

void SpriteBatch::Draw(Texture texture, const glm::vec4& sourceRect, const glm::vec4& destRect, const GLfloat& depth, const GLfloat& angle,
					   const GLfloat& scale, const glm::vec4& color)
{
	glyphs.emplace_back(texture, sourceRect, destRect, depth, angle, scale, color);
}

void SpriteBatch::RenderBatches()
{
	shader.Use();

	glBindVertexArray(vao);

	for (int i = 0; i < renderBatches.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0);
		renderBatches[i].texture.Bind();
		glDrawArrays(GL_TRIANGLES, renderBatches[i].offset, renderBatches[i].numVertices);
	}

	glBindVertexArray(0);
}

glm::vec2 SpriteBatch::RotatePoint(glm::vec2 position, GLfloat angle)
{
	glm::vec2 newPosition;

	newPosition.x = (position.x * cos(angle)) - (position.y * sin(angle));
	newPosition.y = (position.x * sin(angle)) + (position.y * cos(angle));

	return newPosition;
}

void SpriteBatch::CreateRenderBatches()
{
	if (glyphPointers.empty())
		return;

	std::vector<Vertex> vertices;
	vertices.resize(glyphPointers.size() * 6);

	int offset = 0;
	int currentVertex = 0;

	renderBatches.emplace_back(offset, 6, glyphPointers[0]->texture);

	vertices[currentVertex++] = glyphPointers[0]->topLeft;
	vertices[currentVertex++] = glyphPointers[0]->bottomLeft;
	vertices[currentVertex++] = glyphPointers[0]->bottomRight;
	vertices[currentVertex++] = glyphPointers[0]->bottomRight;
	vertices[currentVertex++] = glyphPointers[0]->topRight;
	vertices[currentVertex++] = glyphPointers[0]->topLeft;
	offset += 6;


	for (int currentGlyph = 1; currentGlyph < glyphPointers.size(); currentGlyph++)
	{
		if (glyphPointers[currentGlyph]->texture.GetID() != glyphPointers[currentGlyph - 1]->texture.GetID())
			renderBatches.emplace_back(offset, 6, glyphPointers[currentGlyph]->texture);
		else
			renderBatches.back().numVertices += 6;

		vertices[currentVertex++] = glyphPointers[currentGlyph]->topLeft;
		vertices[currentVertex++] = glyphPointers[currentGlyph]->bottomLeft;
		vertices[currentVertex++] = glyphPointers[currentGlyph]->bottomRight;
		vertices[currentVertex++] = glyphPointers[currentGlyph]->bottomRight;
		vertices[currentVertex++] = glyphPointers[currentGlyph]->topRight;
		vertices[currentVertex++] = glyphPointers[currentGlyph]->topLeft;
		offset += 6;
	}

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex), vertices.data());
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void SpriteBatch::CreateVertexArray()
{
	if (vao == 0)
		glGenVertexArrays(1, &vao);
	if (vbo == 0)
		glGenBuffers(1, &vbo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, uv));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void SpriteBatch::SortGlyphs()
{
	switch (sortType)
	{
	case GlyphSortType::NONE:
		break;

	case GlyphSortType::FRONT_TO_BACK:
		std::stable_sort(glyphPointers.begin(), glyphPointers.end(), CompareFrontToBack);
		break;

	case GlyphSortType::BACK_TO_FRONT:
		std::stable_sort(glyphPointers.begin(), glyphPointers.end(), CompareBackToFront);
		break;

	case GlyphSortType::TEXTURE:
		std::stable_sort(glyphPointers.begin(), glyphPointers.end(), CompareTexture);
		break;
	}
}

bool SpriteBatch::CompareFrontToBack(Glyph* a, Glyph* b) { return (a->depth < b->depth); }
bool SpriteBatch::CompareBackToFront(Glyph* a, Glyph* b) { return (a->depth > b->depth); }
bool SpriteBatch::CompareTexture(Glyph* a, Glyph* b) { return (a->texture.GetID() < b->texture.GetID()); }