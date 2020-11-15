#pragma once

#ifdef CE_PLATFORM_WINDOWS

extern ClemEngine::Application* ClemEngine::CreateApplication();

int main(int argc, char* argv[])
{
	auto app = ClemEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif