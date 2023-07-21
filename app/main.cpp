#include <iostream>
#include <memory>
#include <cmath>

#include <Core/h/Vertex.h>
#include <Core/h/VertexVector.h>
#include <Core/h/Shader.h>
#include <Core/h/ShaderProgram.h>
#include <Core/h/BufferData.h>
#include <Core/h/VertexArray.h>
#include <Core/h/RenderTarget.h>
#include <Core/h/Position.h>
#include <Shapes/h/Triangle.h>
#include <Shapes/h/Rectangle.h>


#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>


float Normalice(float max, float current)
{
	float relative = (2 * current) / max;
	return -1.f + relative;
}

float Degrees2Rads(float degrees)
{
	return degrees * (3.14f / 180.f);
}

int main()
{
	using namespace easy::core;

	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();

	glViewport(0, 0, 800, 800);

	easy::shapes::Triangle t1(
		Position{ -0.5, -0.5, 0},
		Position{ 0.5, -0.5, 0},
		Position{ 0, 0.5, 0}
	);

	easy::shapes::Rectangle r1(Position{ -0.5, -0.5, 0 }, 0.5, 0.5);

	t1.SetFillColor(Palette::RED);

	int w, h;
	glfwGetWindowSize(window, &w, &h);

	float degrees = 0.1;
	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
#if 1
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		xpos = Normalice(w, xpos);
		ypos = -1 * Normalice(h, ypos);

		r1.Position(Position{ (float)xpos, (float)ypos });

		r1.Rotate(Degrees2Rads(degrees));
#endif


		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);

		std::cout << "x: " << t1.Position().x << " y:" << t1.Position().y << "\n";
		//t1.Draw();
		r1.Draw();

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();

		//std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}


	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}

