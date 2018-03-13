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
		/// 
		class Window
		{
		public:
			///@brief Constructor
			Window();
			///@brief Destructor
			~Window();

			GLFWwindow* GetWindow() { return m_Window; }

		private:
			GLFWwindow * m_Window;
		};
	}
}