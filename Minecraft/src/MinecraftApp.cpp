#include <ClemEngine.h>
#include <ClemEngine/Core/EntryPoint.h>

#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class MinecraftApp : public ClemEngine::Application
{
public:
	MinecraftApp()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~MinecraftApp()
	{
	}
};

ClemEngine::Application* ClemEngine::CreateApplication()
{
	return new MinecraftApp();
}