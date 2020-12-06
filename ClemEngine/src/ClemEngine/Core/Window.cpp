#include "cepch.h"
#include "ClemEngine/Core/Window.h"

#ifdef CE_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace ClemEngine
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef CE_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		CE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}