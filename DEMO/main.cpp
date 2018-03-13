#include "window.h"

#include <iostream>

using namespace TKF;
using namespace Graphics;

int main()
{
	Window* window = new Window();

	do
	{
		glfwSwapBuffers(window->GetWindow());
		glfwPollEvents();

	} while(glfwGetKey(window->GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
			glfwWindowShouldClose(window->GetWindow()) == 0);
	
	glfwTerminate();

	return 0;
}
