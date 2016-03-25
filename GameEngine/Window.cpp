#include "Window.h"


GLboolean Window::keys[1024];

Window::Window() :
	window(nullptr),
	width(Global::SCREEN_WIDTH),
	height(Global::SCREEN_HEIGHT)
{
	for (int i = 0; i < 1024; i++)
		keys[i] = false;
}

Window::~Window()
{
	glfwTerminate();
}

GLFWwindow* Window::GetWindow() const { return window; }

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

	glfwSetKeyCallback(window, key_callback);
	glViewport(0, 0, width, height);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return GL_TRUE;
}

void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
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