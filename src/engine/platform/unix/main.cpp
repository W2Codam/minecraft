// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#include <core/engine.hpp>
#include <core/types/common.hpp>
#include <iostream>
#include <platform/defines.hpp>
#include <glfw/glfw3.h>
#include <core/collections/array.hpp>	

// ============================================================================

int main(int argc, const char* argv[]) {
	core::Array<int> array = {1, 2, 3, 4, 5};
	std::cout << "Hello, Unix!" << std::endl;

	glfwInit();
	GLFWwindow* win = glfwCreateWindow(800, 600, "Hello, Unix!", nullptr, nullptr);
	while (glfwWindowShouldClose(win) == GLFW_FALSE) {
		glfwPollEvents();
		glfwSwapBuffers(win);
	}

	for (size_t i = 0; i < array.length(); i++)
		std::cout << array[i] << std::endl;
	glfwTerminate();
	return (EXIT_SUCCESS);
}
