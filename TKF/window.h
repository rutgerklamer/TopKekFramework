// Inlcude GLEW
#include <GL/glew.h>
// Include GFLW3
#include <glfw3.h>
// Include GLM
#include <glm/glm.hpp>

#include "config.h"
#include "iostream"	

namespace TKF
{
	namespace Graphics
	{
		///@brief the Window class makes a nice little window.
		class Window
		{
		public:
			///@brief Constructor
			Window();
			///@brief Destructor
			~Window();

			///@brief Gets the GLFWwindow
			///@return m_Window the current window
			GLFWwindow* GetWindow() { return m_Window; }

		private:
			///@brief Current window
			GLFWwindow * m_Window;
		};
	}
}