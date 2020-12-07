#pragma once

namespace ClemEngine
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define CE_MOUSE_BUTTON_0      ::ClemEngine::Mouse::Button0
#define CE_MOUSE_BUTTON_1      ::ClemEngine::Mouse::Button1
#define CE_MOUSE_BUTTON_2      ::ClemEngine::Mouse::Button2
#define CE_MOUSE_BUTTON_3      ::ClemEngine::Mouse::Button3
#define CE_MOUSE_BUTTON_4      ::ClemEngine::Mouse::Button4
#define CE_MOUSE_BUTTON_5      ::ClemEngine::Mouse::Button5
#define CE_MOUSE_BUTTON_6      ::ClemEngine::Mouse::Button6
#define CE_MOUSE_BUTTON_7      ::ClemEngine::Mouse::Button7
#define CE_MOUSE_BUTTON_LAST   ::ClemEngine::Mouse::ButtonLast
#define CE_MOUSE_BUTTON_LEFT   ::ClemEngine::Mouse::ButtonLeft
#define CE_MOUSE_BUTTON_RIGHT  ::ClemEngine::Mouse::ButtonRight
#define CE_MOUSE_BUTTON_MIDDLE ::ClemEngine::Mouse::ButtonMiddle