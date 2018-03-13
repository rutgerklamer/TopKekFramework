#include "window.h"

namespace TKF
{
	namespace Graphics
	{

		Window::Window()
		{
			// Init glfw
			if(!glfwInit())
			{
				fprintf(stderr, "GLFW Did not Initialize!");
				return;
			}

			// Setup glfw shizzle
			glfwWindowHint(GLFW_SAMPLES, 4); // 4X Antialiasing
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL Version 3.3
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want old OpenGL

			// Setup primary monitor if we want to go fullscreen
			GLFWmonitor* primary = nullptr;
			if(FULLSCREEN) { primary = glfwGetPrimaryMonitor(); }

			// Create the glfw window with the given width, height & name.
			m_Window = glfwCreateWindow(SWIDTH, SHEIGHT, WINDOWNAME, primary, nullptr);

			// Check if the window is correctly created.
			if(m_Window == nullptr)
			{
				fprintf(stderr, "Failed to open GLFW Window");
				glfwTerminate();
				return;
			}

			glfwMakeContextCurrent(m_Window); // Initialize GLEW.
			glClearColor(0.25f, 0.25f, 0.25f, 1.0f);

			// Make sure we cant capture the keys being pressed.
			glfwSetInputMode(m_Window, GLFW_STICKY_KEYS, GL_TRUE);

			glewExperimental = true;
			if(glewInit() != GLEW_OK)
			{
				fprintf(stderr, "Failed to initialize GLEW\n");
				return;
			}
		}

		Window::~Window()
		{

		}
	}
}