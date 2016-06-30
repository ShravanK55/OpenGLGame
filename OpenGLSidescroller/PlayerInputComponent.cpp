#include "PlayerInputComponent.h"
#include "Player.h"


PlayerInputComponent::PlayerInputComponent()
{}

PlayerInputComponent::PlayerInputComponent(Entity* owner) :
	InputComponent(owner)
{}

PlayerInputComponent::~PlayerInputComponent() {}

Player* PlayerInputComponent::GetOwner() const { return static_cast<Player*>(owner); }

void PlayerInputComponent::HandleInput(Input* input)
{
	if (!input->WasKeyPressed(GLFW_KEY_A) && !input->WasKeyPressed(GLFW_KEY_D) &&
		!input->WasKeyPressed(GLFW_KEY_W) && !input->WasKeyPressed(GLFW_KEY_S))
		GetOwner()->GetPhysicsComponent()->StopAllMovement();

	else
	{
		if ((!input->WasKeyPressed(GLFW_KEY_A) && !input->WasKeyPressed(GLFW_KEY_D)) ||
			(input->WasKeyPressed(GLFW_KEY_A) && input->WasKeyPressed(GLFW_KEY_D)))
			GetOwner()->GetPhysicsComponent()->StopHorizontalMovement();
		else
		{
			if (input->WasKeyPressed(GLFW_KEY_D))
				GetOwner()->GetPhysicsComponent()->MoveRight();
			if (input->WasKeyPressed(GLFW_KEY_A))
				GetOwner()->GetPhysicsComponent()->MoveLeft();
		}

		if ((!input->WasKeyPressed(GLFW_KEY_W) && !input->WasKeyPressed(GLFW_KEY_S)) ||
			(input->WasKeyPressed(GLFW_KEY_W) && input->WasKeyPressed(GLFW_KEY_S)))
			GetOwner()->GetPhysicsComponent()->StopVerticalMovement();
		else
		{
			if (input->WasKeyPressed(GLFW_KEY_W))
				GetOwner()->GetPhysicsComponent()->MoveUp();
			if (input->WasKeyPressed(GLFW_KEY_S))
				GetOwner()->GetPhysicsComponent()->MoveDown();
		}
	}
}