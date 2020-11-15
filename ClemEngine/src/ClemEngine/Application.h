#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace ClemEngine
{
	class CLEMENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}

