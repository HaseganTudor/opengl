#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {

	if (!glfwInit()) { std::cout << "Couldn't load GLFW!!!" << std::endl; return -1; }

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	int width = 800, height = 800;
	GLFWwindow* window = glfwCreateWindow(width, height, "Terraria", NULL, NULL);

	if (!window) { std::cout << "Couldn't create window!" << std::endl; return -1; }

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { std::cout << "Couldn't load GLAD!!!" << std::endl; return -1; }

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, GLFW_TRUE);
			std::cout << "The window was closed from ESC key!!!" << std::endl;
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}