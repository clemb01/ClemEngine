#pragma once

#include "ClemEngine/Core/Base.h"
#include "ClemEngine/Core/Log.h"

#include <filesystem>

#ifdef CE_ENABLE_ASSERTS
	#define CE_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { CE##type##ERROR(msg, __VA_ARGS__); CE_DEBUGBREAK(); } }
	#define CE_INTERNAL_ASSERT_WITH_MSG(type, check, ...) CE_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define CE_INTERNAL_ASSERT_NO_MSG(type, check) CE_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0} failed at {1}:{2}'", CE_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define CE_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define CE_INTERNAL_ASSERT_GET_MACRO(...) CE_EXPAND_MACRO( CE_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, CE_INTERNAL_ASSERT_WITH_MSG, CE_INTERNAL_ASSERT_NO_MSG) )

	#define CE_ASSERT(...) CE_EXPAND_MACRO(CE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__))
	#define CE_CORE_ASSERT(...) CE_EXPAND_MACRO(CE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__))
#else
	#define CE_ASSERT(...)
	#define CE_CORE_ASSERT(...)
#endif