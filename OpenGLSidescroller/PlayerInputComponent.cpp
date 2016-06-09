#include "PlayerInputComponent.h"


PlayerInputComponent::PlayerInputComponent() :
	stateComponent(NULL),
	physicsComponent(NULL)
{}

PlayerInputComponent::PlayerInputComponent(Entity* owner) :
	InputComponent(owner),
	stateComponent(NULL),
	physicsComponent(NULL)
{}

PlayerInputComponent::PlayerInputComponent(Entity* owner, PlayerStateComponent* stateComponent, PlayerPhysicsComponent* physicsComponent) :
	InputComponent(owner),
	stateComponent(stateComponent),
	physicsComponent(physicsComponent)
{}

PlayerInputComponent::~PlayerInputComponent() {}

void PlayerInputComponent::HandleInput(Input* input)
{
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