#pragma once
#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Globals.h"

class Window
{
public:
	Window();
	~Window();

	GLFWwindow* GetWindow() const;

	// Creates the window.
	GLboolean CreateWindow(GLsizei screenWidth, GLsizei screenHeight, const std::string& windowName);

	// A keyboard callback function, called when the user interacts with the keyboard.
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

	static GLboolean keys[1024];

private:
	GLFWwindow* window;
	GLsizei width, height;
};

