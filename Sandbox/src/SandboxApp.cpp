#include <ClemEngine.h>
#include <ClemEngine/Core/EntryPoint.h>

#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class SandboxApp : public ClemEngine::Application
{
public:
	SandboxApp()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~SandboxApp()
	{
	}
};

ClemEngine::Application* ClemEngine::CreateApplication()
{
	return new SandboxApp();
}