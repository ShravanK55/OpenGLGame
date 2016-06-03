#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Input
{
public:
	Input();
	~Input();

	// A keyboard callback function, called when the user interacts with the keyboard.
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	
	static GLboolean WasKeyPressed(GLuint key);
	static GLboolean WasKeyReleased(GLuint key);
	
	static GLboolean keys[1024];
};

