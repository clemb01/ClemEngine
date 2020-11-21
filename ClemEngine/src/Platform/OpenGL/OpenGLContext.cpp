#include "cepch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>

namespace ClemEngine
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		CE_CORE_ASSERT(windowHandle, "Window handle is null !");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		CE_CORE_ASSERT(status, "Failed to initialize Glad !");

		CE_CORE_INFO("OpenGL Infos:");
		CE_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		CE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		CE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
