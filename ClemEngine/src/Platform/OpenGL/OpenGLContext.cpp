#include "cepch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace ClemEngine
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		CE_CORE_ASSERT(windowHandle, "Window handle is null !");
	}

	void OpenGLContext::Init()
	{
		CE_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		CE_CORE_ASSERT(status, "Failed to initialize Glad !");

		CE_CORE_INFO("OpenGL Infos:");
		CE_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		CE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		CE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		CE_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Hazel requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		CE_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}
}
