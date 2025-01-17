#pragma once

#include "ClemEngine/Core/Base.h"

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace ClemEngine {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define CE_CORE_TRACE(...)    ::ClemEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CE_CORE_INFO(...)     ::ClemEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CE_CORE_WARN(...)     ::ClemEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CE_CORE_ERROR(...)    ::ClemEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CE_CORE_CRITICAL(...) ::ClemEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)
								
// Client log macros			
#define CE_TRACE(...)	      ::ClemEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CE_INFO(...)	      ::ClemEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CE_WARN(...)	      ::ClemEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CE_ERROR(...)	      ::ClemEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CE_CRITICAL(...)	  ::ClemEngine::Log::GetClientLogger()->critical(__VA_ARGS__)