#include "SpriteBatch.h"
#include <algorithm>


std::vector<Glyph*> SpriteBatch::glyphs;

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

	for (int i = 0; i < glyphs.size(); i++) {
		delete glyphs[i];
	}

	glyphs.clear();
}

void SpriteBatch::End()
{
	SortGlyphs();
	CreateRenderBatches();
}

void SpriteBatch::Draw(Texture texture, const glm::vec4& sourceRect, const glm::vec4& destRect, const GLfloat& depth, const GLfloat& scale,
					   const glm::vec4& color)
{
	Glyph* newGlyph = new Glyph();
	newGlyph->texture = texture;
	newGlyph->depth = depth;

	newGlyph->topLeft.SetPosition(destRect.x, destRect.y + (destRect.w * scale));
	newGlyph->topLeft.SetColor(color.x, color.y, color.z, color.w);
	newGlyph->topLeft.SetUV(sourceRect.x, sourceRect.y + sourceRect.w);

	newGlyph->bottomLeft.SetPosition(destRect.x, destRect.y);
	newGlyph->bottomLeft.SetColor(color.x, color.y, color.z, color.w);
	newGlyph->bottomLeft.SetUV(sourceRect.x, sourceRect.y);

	newGlyph->bottomRight.SetPosition(destRect.x + (destRect.z * scale), destRect.y);
	newGlyph->bottomRight.SetColor(color.x, color.y, color.z, color.w);
	newGlyph->bottomRight.SetUV(sourceRect.x + sourceRect.z, sourceRect.y);

	newGlyph->topRight.SetPosition(destRect.x + (destRect.z * scale), destRect.y + (destRect.w * scale));
	newGlyph->topRight.SetColor(color.x, color.y, color.z, color.w);
	newGlyph->topRight.SetUV(sourceRect.x + sourceRect.z, sourceRect.y + sourceRect.w);

	glyphs.push_back(newGlyph);
}

void SpriteBatch::Draw(Texture texture, const glm::vec4& sourceRect, const glm::vec4& destRect, const GLfloat& depth, const GLfloat& angle,
					   const GLfloat& scale, const glm::vec4& color)
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

	Glyph* newGlyph = new Glyph();
	newGlyph->texture = texture;
	newGlyph->depth = depth;

	newGlyph->topLeft.SetPosition(destRect.x + rTopLeft.x, destRect.y + (rTopLeft.y));
	newGlyph->topLeft.SetColor(color.x, color.y, color.z, color.w);
	newGlyph->topLeft.SetUV(sourceRect.x, sourceRect.y + sourceRect.w);

	newGlyph->bottomLeft.SetPosition(destRect.x + rBottomLeft.x, destRect.y + rBottomLeft.y);
	newGlyph->bottomLeft.SetColor(color.x, color.y, color.z, color.w);
	newGlyph->bottomLeft.SetUV(sourceRect.x, sourceRect.y);

	newGlyph->bottomRight.SetPosition(destRect.x + (rBottomRight.x), destRect.y + rBottomRight.y);
	newGlyph->bottomRight.SetColor(color.x, color.y, color.z, color.w);
	newGlyph->bottomRight.SetUV(sourceRect.x + sourceRect.z, sourceRect.y);

	newGlyph->topRight.SetPosition(destRect.x + (rTopRight.x), destRect.y + (rTopRight.y));
	newGlyph->topRight.SetColor(color.x, color.y, color.z, color.w);
	newGlyph->topRight.SetUV(sourceRect.x + sourceRect.z, sourceRect.y + sourceRect.w);

	glyphs.push_back(newGlyph);
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
	if (glyphs.empty())
		return;

	std::vector<Vertex> vertices;
	vertices.resize(glyphs.size() * 6);

	int offset = 0;
	int currentVertex = 0;

	renderBatches.emplace_back(offset, 6, glyphs[0]->texture);

	vertices[currentVertex++] = glyphs[0]->topLeft;
	vertices[currentVertex++] = glyphs[0]->bottomLeft;
	vertices[currentVertex++] = glyphs[0]->bottomRight;
	vertices[currentVertex++] = glyphs[0]->bottomRight;
	vertices[currentVertex++] = glyphs[0]->topRight;
	vertices[currentVertex++] = glyphs[0]->topLeft;
	offset += 6;


	for (int currentGlyph = 1; currentGlyph < glyphs.size(); currentGlyph++)
	{
		if (glyphs[currentGlyph]->texture.GetID() != glyphs[currentGlyph - 1]->texture.GetID())
			renderBatches.emplace_back(offset, 6, glyphs[currentGlyph]->texture);
		else
			renderBatches.back().numVertices += 6;

		vertices[currentVertex++] = glyphs[currentGlyph]->topLeft;
		vertices[currentVertex++] = glyphs[currentGlyph]->bottomLeft;
		vertices[currentVertex++] = glyphs[currentGlyph]->bottomRight;
		vertices[currentVertex++] = glyphs[currentGlyph]->bottomRight;
		vertices[currentVertex++] = glyphs[currentGlyph]->topRight;
		vertices[currentVertex++] = glyphs[currentGlyph]->topLeft;
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
		std::stable_sort(glyphs.begin(), glyphs.end(), CompareFrontToBack);
		break;

	case GlyphSortType::BACK_TO_FRONT:
		std::stable_sort(glyphs.begin(), glyphs.end(), CompareBackToFront);
		break;

	case GlyphSortType::TEXTURE:
		std::stable_sort(glyphs.begin(), glyphs.end(), CompareTexture);
		break;
	}
}

bool SpriteBatch::CompareFrontToBack(Glyph* a, Glyph* b) { return (a->depth < b->depth); }
bool SpriteBatch::CompareBackToFront(Glyph* a, Glyph* b) { return (a->depth > b->depth); }
bool SpriteBatch::CompareTexture(Glyph* a, Glyph* b) { return (a->texture.GetID() < b->texture.GetID()); }