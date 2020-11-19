#include <ClemEngine.h>

class ExampleLayer : public ClemEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (ClemEngine::Input::IsKeyPressed(CE_KEY_TAB))
			CE_TRACE("Tab key is pressed !");
	}

	void OnEvent(ClemEngine::Event& event) override
	{
		if (event.GetEventType() == ClemEngine::EventType::KeyPressed)
		{
			ClemEngine::KeyPressedEvent& e = (ClemEngine::KeyPressedEvent&)event;
			CE_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class MinecraftApp : public ClemEngine::Application
{
public:
	MinecraftApp()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new ClemEngine::ImGuiLayer());
	}

	~MinecraftApp()
	{

	}

};

ClemEngine::Application* ClemEngine::CreateApplication()
{
	return new MinecraftApp();
}