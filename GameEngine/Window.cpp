#include "Window.h"
#include <string>


Window::Window() :
	window(nullptr),
	width(Global::SCREEN_WIDTH),
	height(Global::SCREEN_HEIGHT)
{}

Window::Window(Input* input) :
	window(nullptr),
	width(Global::SCREEN_WIDTH),
	height(Global::SCREEN_HEIGHT),
	input(input)
{}

Window::~Window()
{
	if (input != nullptr)
		delete input;
	glfwTerminate();
}

GLFWwindow* Window::GetWindow() const { return window; }

Input* Window::GetInput(Input* input) { return input; }

void Window::SetInput(Input* input) { this->input = input; }

GLboolean Window::CreateWindow(GLsizei screenWidth, GLsizei screenHeight, const std::string& windowName)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	width = screenWidth;
	height = screenHeight;
	window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);

	if (window == nullptr)
	{
		std::cout << "Couldn't create the window!" << std::endl;
		return GL_FALSE;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW!" << std::endl;
		return GL_FALSE;
	}

	if (input == nullptr)
		input = new Input();

	if (input != nullptr)
		glfwSetKeyCallback(window, input->key_callback);

	glViewport(0, 0, width, height);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return GL_TRUE;
}
