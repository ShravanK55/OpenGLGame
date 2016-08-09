#include "TransformComponent.h"


const char* name = "TransformComponent";

TransformComponent::TransformComponent() :
	Component(),
	position(glm::vec2(0, 0)),
	size(glm::vec2(0, 0)),
	rotation(0.0f),
	scale(1.0f)
{}

TransformComponent::TransformComponent(glm::vec2 position, glm::vec2 size) :
	Component(),
	position(position),
	size(size),
	rotation(0.0f),
	scale(1.0f)
{}

TransformComponent::TransformComponent(glm::vec2 position, glm::vec2 size, GLfloat rotation) :
	Component(),
	position(position),
	size(size),
	rotation(rotation),
	scale(1.0f)
{}

TransformComponent::TransformComponent(glm::vec2 position, glm::vec2 size, GLfloat rotation, GLfloat scale) :
	Component(),
	position(position),
	size(size),
	rotation(rotation),
	scale(scale)
{}

TransformComponent::TransformComponent(Entity* owner) :
	Component(owner),
	position(glm::vec2(0, 0)),
	size(glm::vec2(0, 0)),
	rotation(0.0f),
	scale(1.0f)
{}

TransformComponent::TransformComponent(Entity* owner, glm::vec2 position, glm::vec2 size) :
	Component(owner),
	position(position),
	size(size),
	rotation(0.0f),
	scale(1.0f)
{}

TransformComponent::TransformComponent(Entity* owner, glm::vec2 position, glm::vec2 size, GLfloat rotation) :
	Component(owner),
	position(position),
	size(size),
	rotation(rotation),
	scale(1.0f)
{}

TransformComponent::TransformComponent(Entity* owner, glm::vec2 position, glm::vec2 size, GLfloat rotation, GLfloat scale) :
	Component(owner),
	position(position),
	size(size),
	rotation(rotation),
	scale(scale)
{}

bool TransformComponent::Init(tinyxml2::XMLElement* componentElement)
{
	if (componentElement != nullptr)
	{
		position.x = componentElement->IntAttribute("x");
		position.y = componentElement->IntAttribute("y");
		size.x = componentElement->IntAttribute("width");
		size.y = componentElement->IntAttribute("height");
		rotation = componentElement->FloatAttribute("rotation");
		scale = componentElement->FloatAttribute("scale");
		return true;
	}
	else
		return false;
}

const char* TransformComponent::GetName() const { return name; }

glm::vec2 TransformComponent::GetPosition() const { return position; }
glm::vec2 TransformComponent::GetSize() const { return size; }
GLfloat TransformComponent::GetRotation() const { return rotation; }
GLfloat TransformComponent::GetScale() const { return scale; }

void TransformComponent::SetPosition(glm::vec2 position) { this->position = position; }
void TransformComponent::SetSize(glm::vec2 size) { this->size = size; }
void TransformComponent::SetRotation(GLfloat rotation) { this->rotation = rotation; }
void TransformComponent::SetScale(GLfloat scale) { this->scale = scale; }

void TransformComponent::HandleInput(Input* input) {}
void TransformComponent::Update(GLfloat elapsedTime) {}
void TransformComponent::Draw(SpriteBatch* spriteBatch) {}
