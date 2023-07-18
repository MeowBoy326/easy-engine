#include <iostream>
#include <memory>

#include <Core/h/Vertex.h>
#include <Core/h/VertexVector.h>
#include <Core/h/Shader.h>
#include <Core/h/ShaderProgram.h>
#include <Core/h/BufferData.h>
#include <Core/h/VertexArray.h>
#include <Core/h/RenderTarget.h>




#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

void LogShader(GLuint id, GLuint type)
{
    GLint status;
    GLsizei info_lenght = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &status);

    if (status == GL_FALSE) {
        glGetShaderiv(id, type, &info_lenght);
        GLchar* buffer = (GLchar*)_malloca(info_lenght * sizeof(GLchar));
        glGetShaderInfoLog(id, info_lenght, NULL, buffer);
        std::cout << buffer << std::endl;
        _freea(buffer);
    }
}

GLuint CreateShader(GLuint type, const char*& src)
{
   GLuint shader = glCreateShader(type);
   glShaderSource(shader, 1, &src, NULL);
   glCompileShader(shader);

   LogShader(shader, type);

   return shader;
}

// Vertex Shader source code
const char* vertexShaderSource = R"(#version 460 core
        layout (location = 0) in vec3 aPos;
        void main()
        {
           gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
        }
    )";

//Fragment Shader source code
const char* fragmentShaderSource = R"(
        #version 460 core
        out vec4 FragColor;
        in vec4 outColor;
        void main()
        {
           FragColor = outColor;
        }
    )";

float Normalice(float max, float current)
{
	float relative = (2 * current) / max;
	return -1.f + relative;
}

int main()
{
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

	// Create Vertex Shader Object and get its reference
	easy::graphics::core::Shader vertex_shader(GL_VERTEX_SHADER, vertexShaderSource);

	// Create Fragment Shader Object and get its reference
	easy::graphics::core::Shader fragment_shader(GL_FRAGMENT_SHADER, fragmentShaderSource);

	std::vector<easy::graphics::core::Shader> shaders;
	shaders.push_back(std::move(vertex_shader));
	shaders.push_back(std::move(fragment_shader));

	easy::graphics::core::ShaderProgram shader_program(shaders);

	// Delete the now useless Vertex and Fragment Shader objects
	vertex_shader.Clean();
	fragment_shader.Clean();


	// Vertices coordinates
	easy::graphics::core::VertexVector vertices =
	{
		{ -0.5f,   -0.5f * float(sqrt(3)) / 3,     0.0f},  // Lower left corner
		{  0.5f,   -0.5f * float(sqrt(3)) / 3,     0.0f }, // Lower right corner
		{  0.0f,    0.5f * float(sqrt(3)) * 2 / 3, 0.0f}   // Upper corner
	};

	easy::graphics::core::VertexVector vertices2 =
	{
		{-1, -1, 0},
		{1, -1, 0},
		{0, 1, 0}
	};

	easy::graphics::core::RenderTarget render1(GL_ARRAY_BUFFER, shader_program);
	easy::graphics::core::RenderTarget render2(GL_ARRAY_BUFFER, shader_program);

	int w, h;
	glfwGetWindowSize(window, &w, &h);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{

		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		xpos = Normalice(w, xpos);
		ypos = -1 *  Normalice(h, ypos);

		vertices.At(2).GetX() = xpos;
		vertices.At(2).GetY() = ypos;

		vertices2.At(0).GetX() = xpos;
		vertices2.At(0).GetY() = ypos;

		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);

		// 
		render1.Draw(vertices, GL_TRIANGLES);
		//

		// 
		render2.Draw(vertices2, GL_TRIANGLES);
		//

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}


	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}

