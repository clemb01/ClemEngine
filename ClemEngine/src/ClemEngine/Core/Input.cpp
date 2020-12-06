#include "cepch.h"
#include "Input.h"

#ifdef CE_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
#endif

namespace ClemEngine
{
	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
#ifdef CE_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
#else
		CE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}
