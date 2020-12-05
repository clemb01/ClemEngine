#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "ClemEngine/Core/Log.h"
#include "ClemEngine/Debug/Instrumentor.h"

#ifdef CE_PLATFORM_WINDOWS
	#include <Windows.h>
#endif