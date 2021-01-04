#pragma once

#include <memory>
#include "ClemEngine/Core/PlatformDetection.h"

#ifdef CE_DEBUG
	#if defined(CE_PLATFORM_WINDOWS)
		#define CE_DEBUGBREAK() __debugbreak()
	#elif defined(CE_PLATFORM_LINUX)
		#include <signal.h>
		#define CE_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
#endif
	#define CE_ENABLE_ASSERTS
#else
	#define CE_DEBUGBREAK()
#endif

#define CE_EXPAND_MACRO(x) x
#define CE_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define CE_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace ClemEngine
{
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}

#include "ClemEngine/Core/Log.h"
#include "ClemEngine/Core/Assert.h"