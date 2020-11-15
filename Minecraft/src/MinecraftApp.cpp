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

class Sandbox : public ClemEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

ClemEngine::Application* ClemEngine::CreateApplication()
{
	return new Sandbox();
}