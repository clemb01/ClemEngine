#include <ClemEngine.h>

class Application : public ClemEngine::Application
{
public:
	Application()
	{

	}

	~Application()
	{

	}
};

ClemEngine::Application* ClemEngine::CreateApplication()
{
	ClemEngine::Log::Init();
	CE_CORE_WARN("Initialized Log!");
	CE_INFO("Initialized Client!");

	return new Application();
}