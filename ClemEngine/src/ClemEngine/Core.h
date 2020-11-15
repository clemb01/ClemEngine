#pragma once

#ifdef CE_PLATFORM_WINDOWS
	#ifdef CE_BUILD_DLL
		#define CLEMENGINE_API __declspec(dllexport)
	#else
		#define CLEMENGINE_API __declspec(dllimport)
	#endif
#else
	#error Engine only support Windows !
#endif

#define BIT(x) (1 << x)