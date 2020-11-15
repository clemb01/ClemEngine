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
		CE_INFO("ExampleLayer::Update");
	}

	void OnEvent(ClemEngine::Event& event) override
	{
		CE_TRACE("{0}", event);
	}

};

class MinecraftApp : public ClemEngine::Application
{
public:
	MinecraftApp()
	{
		PushLayer(new ExampleLayer());
	}

	~MinecraftApp()
	{

	}

};

ClemEngine::Application* ClemEngine::CreateApplication()
{
	return new MinecraftApp();
}