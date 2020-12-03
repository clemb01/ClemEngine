#pragma once

#include "ClemEngine/Core/Core.h"

#ifdef CE_PLATFORM_WINDOWS

extern ClemEngine::Application* ClemEngine::CreateApplication();

int main(int argc, char** argv)
{
	ClemEngine::Log::Init();
	CE_CORE_WARN("Initialized Log!");

	auto app = ClemEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif