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

			glfwWindowHint(GLFW_SAMPLES, 4); // 4X Antialiasing
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			GLFWmonitor* primary = nullptr;
			if(FULLSCREEN) { primary = glfwGetPrimaryMonitor(); }

			m_Window = glfwCreateWindow(SWIDTH, SHEIGHT, WINDOWNAME, primary, nullptr);

			if(m_Window == nullptr)
			{
				fprintf(stderr, "Failed to open GLFW Window");
				glfwTerminate();
				return;
			}

			glfwMakeContextCurrent(m_Window);
			glClearColor(0.25f, 0.25f, 0.25f, 1.0f);

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