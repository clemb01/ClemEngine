#pragma once

#include "ClemEngine/Core/Base.h"
#include "ClemEngine/Core/KeyCodes.h"
#include "ClemEngine/Core/MouseCodes.h"

namespace ClemEngine
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}