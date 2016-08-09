#include "PlayerInputComponent.h"
#include "Entity.h"
#include "PlayerStateComponent.h"
#include "PlayerPhysicsComponent.h"


const char* PlayerInputComponent::name = "PlayerInputComponent";

PlayerInputComponent::PlayerInputComponent()
{}

PlayerInputComponent::PlayerInputComponent(Entity* owner) :
	Component(owner)
{}

PlayerInputComponent::~PlayerInputComponent() {}

bool PlayerInputComponent::Init(tinyxml2::XMLElement* componentElement)
{
	if (componentElement != nullptr)
		return true;
	else
		return false;
}

const char* PlayerInputComponent::GetName() const { return name; }

void PlayerInputComponent::HandleInput(Input* input)
{
	PlayerPhysicsComponent* physicsComponent = owner->GetComponent<PlayerPhysicsComponent>();

	if (!input->WasKeyPressed(GLFW_KEY_A) && !input->WasKeyPressed(GLFW_KEY_D) &&
		!input->WasKeyPressed(GLFW_KEY_W) && !input->WasKeyPressed(GLFW_KEY_S))
		physicsComponent->StopAllMovement();

	else
	{
		if ((!input->WasKeyPressed(GLFW_KEY_A) && !input->WasKeyPressed(GLFW_KEY_D)) ||
			(input->WasKeyPressed(GLFW_KEY_A) && input->WasKeyPressed(GLFW_KEY_D)))
			physicsComponent->StopHorizontalMovement();
		else
		{
			if (input->WasKeyPressed(GLFW_KEY_D))
				physicsComponent->MoveRight();
			if (input->WasKeyPressed(GLFW_KEY_A))
				physicsComponent->MoveLeft();
		}

		if ((!input->WasKeyPressed(GLFW_KEY_W) && !input->WasKeyPressed(GLFW_KEY_S)) ||
			(input->WasKeyPressed(GLFW_KEY_W) && input->WasKeyPressed(GLFW_KEY_S)))
			physicsComponent->StopVerticalMovement();
		else
		{
			if (input->WasKeyPressed(GLFW_KEY_W))
				physicsComponent->MoveUp();
			if (input->WasKeyPressed(GLFW_KEY_S))
				physicsComponent->MoveDown();
		}
	}
}

void PlayerInputComponent::Update(GLfloat elapsedTime) {}
void PlayerInputComponent::Draw(SpriteBatch* spriteBatch) {}
