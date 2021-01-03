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

#ifdef CE_ENABLE_ASSERTS
	#define CE_ASSERT(x, ...) { if(!(x)) { CE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CE_CORE_ASSERT(x, ...) { if(!(x)) { CE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CE_ASSERT(x, ...)
	#define CE_CORE_ASSERT(x, ...)
#endif

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