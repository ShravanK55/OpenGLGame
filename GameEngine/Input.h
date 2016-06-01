#pragma once
#include <GLFW/glfw3.h>

class Input
{
public:
	Input();
	~Input();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	
	static GLboolean WasKeyPressed(GLuint key);
	static GLboolean WasKeyReleased(GLuint key);
	
private:
	static GLboolean keys[1024];
};

