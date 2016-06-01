#pragma once
#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Globals.h"
#include "Input.h"

class Window
{
public:
	Input* input;

	Window();
	Window(Input* input);
	~Window();

	GLFWwindow* GetWindow() const;
	Input* GetInput(Input* input);
	void SetInput(Input* input);

	// Creates the window and input.
	GLboolean CreateWindow(GLsizei screenWidth, GLsizei screenHeight, const std::string& windowName);

private:
	GLFWwindow* window;
	GLsizei width, height;
};

