#pragma once

#include "ClemEngine/Core/Core.h"

#ifdef CE_PLATFORM_WINDOWS

extern ClemEngine::Application* ClemEngine::CreateApplication();

int main(int argc, char** argv)
{
	ClemEngine::Log::Init();

	CE_PROFILE_BEGIN_SESSION("Startup", "ClemEngineProfile-Startup.json");
	auto app = ClemEngine::CreateApplication();
	CE_PROFILE_END_SESSION();

	CE_PROFILE_BEGIN_SESSION("Runtime", "ClemEngineProfile-Runtime.json");
	app->Run();
	CE_PROFILE_END_SESSION();

	CE_PROFILE_BEGIN_SESSION("Shutdown", "ClemEngineProfile-Shutdown.json");
	delete app;
	CE_PROFILE_END_SESSION();
}

#endif