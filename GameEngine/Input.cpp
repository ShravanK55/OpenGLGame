#include "Input.h"


GLboolean Input::keys[1024];

Input::Input()
{
	for (int i = 0; i < 1024; i++)
		keys[i] = false;
}

Input::~Input()
{}

void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			keys[key] = true;
		if (action == GLFW_RELEASE)
			keys[key] = false;
	}
}

GLboolean Input::WasKeyPressed(GLuint key) { return keys[key]; }
GLboolean Input::WasKeyReleased(GLuint key) { return !keys[key]; }
