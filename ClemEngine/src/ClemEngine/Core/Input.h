#pragma once

#include <glm/glm.hpp>

#include "ClemEngine/Core/KeyCodes.h"
#include "ClemEngine/Core/MouseCodes.h"

namespace ClemEngine
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}