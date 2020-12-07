#pragma once

namespace ClemEngine
{
	typedef enum class KeyCode : uint16_t
	{
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

#ifdef CE_KEYBOARD_QWERTY
	#define CE_KEY_SPACE           ::ClemEngine::Key::Space
	#define CE_KEY_APOSTROPHE      ::ClemEngine::Key::Apostrophe    /* ' */
	#define CE_KEY_COMMA           ::ClemEngine::Key::Comma         /* , */
	#define CE_KEY_MINUS           ::ClemEngine::Key::Minus         /* - */
	#define CE_KEY_PERIOD          ::ClemEngine::Key::Period        /* . */
	#define CE_KEY_SLASH           ::ClemEngine::Key::Slash         /* / */
	#define CE_KEY_0               ::ClemEngine::Key::D0
	#define CE_KEY_1               ::ClemEngine::Key::D1
	#define CE_KEY_2               ::ClemEngine::Key::D2
	#define CE_KEY_3               ::ClemEngine::Key::D3
	#define CE_KEY_4               ::ClemEngine::Key::D4
	#define CE_KEY_5               ::ClemEngine::Key::D5
	#define CE_KEY_6               ::ClemEngine::Key::D6
	#define CE_KEY_7               ::ClemEngine::Key::D7
	#define CE_KEY_8               ::ClemEngine::Key::D8
	#define CE_KEY_9               ::ClemEngine::Key::D9
	#define CE_KEY_SEMICOLON       ::ClemEngine::Key::Semicolon     /* ; */
	#define CE_KEY_EQUAL           ::ClemEngine::Key::Equal         /* = */
	#define CE_KEY_A               ::ClemEngine::Key::A
	#define CE_KEY_B               ::ClemEngine::Key::B
	#define CE_KEY_C               ::ClemEngine::Key::C
	#define CE_KEY_D               ::ClemEngine::Key::D
	#define CE_KEY_E               ::ClemEngine::Key::E
	#define CE_KEY_F               ::ClemEngine::Key::F
	#define CE_KEY_G               ::ClemEngine::Key::G
	#define CE_KEY_H               ::ClemEngine::Key::H
	#define CE_KEY_I               ::ClemEngine::Key::I
	#define CE_KEY_J               ::ClemEngine::Key::J
	#define CE_KEY_K               ::ClemEngine::Key::K
	#define CE_KEY_L               ::ClemEngine::Key::L
	#define CE_KEY_M               ::ClemEngine::Key::M
	#define CE_KEY_N               ::ClemEngine::Key::N
	#define CE_KEY_O               ::ClemEngine::Key::O
	#define CE_KEY_P               ::ClemEngine::Key::P
	#define CE_KEY_Q               ::ClemEngine::Key::Q
	#define CE_KEY_R               ::ClemEngine::Key::R
	#define CE_KEY_S               ::ClemEngine::Key::S
	#define CE_KEY_T               ::ClemEngine::Key::T
	#define CE_KEY_U               ::ClemEngine::Key::U
	#define CE_KEY_V               ::ClemEngine::Key::V
	#define CE_KEY_W               ::ClemEngine::Key::W
	#define CE_KEY_X               ::ClemEngine::Key::X
	#define CE_KEY_Y               ::ClemEngine::Key::Y
	#define CE_KEY_Z               ::ClemEngine::Key::Z
	#define CE_KEY_LEFT_BRACKET    ::ClemEngine::Key::LeftBracket   /* [ */
	#define CE_KEY_BACKSLASH       ::ClemEngine::Key::Backslash     /* \ */
	#define CE_KEY_RIGHT_BRACKET   ::ClemEngine::Key::RightBracket  /* ] */
	#define CE_KEY_GRAVE_ACCENT    ::ClemEngine::Key::GraveAccent   /* ` */
	#define CE_KEY_WORLD_1         ::ClemEngine::Key::World1        /* non-US #1 */
	#define CE_KEY_WORLD_2         ::ClemEngine::Key::World2        /* non-US #2 */

	/* Function keys */
	#define CE_KEY_ESCAPE          ::ClemEngine::Key::Escape
	#define CE_KEY_ENTER           ::ClemEngine::Key::Enter
	#define CE_KEY_TAB             ::ClemEngine::Key::Tab
	#define CE_KEY_BACKSPACE       ::ClemEngine::Key::Backspace
	#define CE_KEY_INSERT          ::ClemEngine::Key::Insert
	#define CE_KEY_DELETE          ::ClemEngine::Key::Delete
	#define CE_KEY_RIGHT           ::ClemEngine::Key::Right
	#define CE_KEY_LEFT            ::ClemEngine::Key::Left
	#define CE_KEY_DOWN            ::ClemEngine::Key::Down
	#define CE_KEY_UP              ::ClemEngine::Key::Up
	#define CE_KEY_PAGE_UP         ::ClemEngine::Key::PageUp
	#define CE_KEY_PAGE_DOWN       ::ClemEngine::Key::PageDown
	#define CE_KEY_HOME            ::ClemEngine::Key::Home
	#define CE_KEY_END             ::ClemEngine::Key::End
	#define CE_KEY_CAPS_LOCK       ::ClemEngine::Key::CapsLock
	#define CE_KEY_SCROLL_LOCK     ::ClemEngine::Key::ScrollLock
	#define CE_KEY_NUM_LOCK        ::ClemEngine::Key::NumLock
	#define CE_KEY_PRINT_SCREEN    ::ClemEngine::Key::PrintScreen
	#define CE_KEY_PAUSE           ::ClemEngine::Key::Pause
	#define CE_KEY_F1              ::ClemEngine::Key::F1
	#define CE_KEY_F2              ::ClemEngine::Key::F2
	#define CE_KEY_F3              ::ClemEngine::Key::F3
	#define CE_KEY_F4              ::ClemEngine::Key::F4
	#define CE_KEY_F5              ::ClemEngine::Key::F5
	#define CE_KEY_F6              ::ClemEngine::Key::F6
	#define CE_KEY_F7              ::ClemEngine::Key::F7
	#define CE_KEY_F8              ::ClemEngine::Key::F8
	#define CE_KEY_F9              ::ClemEngine::Key::F9
	#define CE_KEY_F10             ::ClemEngine::Key::F10
	#define CE_KEY_F11             ::ClemEngine::Key::F11
	#define CE_KEY_F12             ::ClemEngine::Key::F12
	#define CE_KEY_F13             ::ClemEngine::Key::F13
	#define CE_KEY_F14             ::ClemEngine::Key::F14
	#define CE_KEY_F15             ::ClemEngine::Key::F15
	#define CE_KEY_F16             ::ClemEngine::Key::F16
	#define CE_KEY_F17             ::ClemEngine::Key::F17
	#define CE_KEY_F18             ::ClemEngine::Key::F18
	#define CE_KEY_F19             ::ClemEngine::Key::F19
	#define CE_KEY_F20             ::ClemEngine::Key::F20
	#define CE_KEY_F21             ::ClemEngine::Key::F21
	#define CE_KEY_F22             ::ClemEngine::Key::F22
	#define CE_KEY_F23             ::ClemEngine::Key::F23
	#define CE_KEY_F24             ::ClemEngine::Key::F24
	#define CE_KEY_F25             ::ClemEngine::Key::F25

	/* Keypad */
	#define CE_KEY_KP_0            ::ClemEngine::Key::KP0
	#define CE_KEY_KP_1            ::ClemEngine::Key::KP1
	#define CE_KEY_KP_2            ::ClemEngine::Key::KP2
	#define CE_KEY_KP_3            ::ClemEngine::Key::KP3
	#define CE_KEY_KP_4            ::ClemEngine::Key::KP4
	#define CE_KEY_KP_5            ::ClemEngine::Key::KP5
	#define CE_KEY_KP_6            ::ClemEngine::Key::KP6
	#define CE_KEY_KP_7            ::ClemEngine::Key::KP7
	#define CE_KEY_KP_8            ::ClemEngine::Key::KP8
	#define CE_KEY_KP_9            ::ClemEngine::Key::KP9
	#define CE_KEY_KP_DECIMAL      ::ClemEngine::Key::KPDecimal
	#define CE_KEY_KP_DIVIDE       ::ClemEngine::Key::KPDivide
	#define CE_KEY_KP_MULTIPLY     ::ClemEngine::Key::KPMultiply
	#define CE_KEY_KP_SUBTRACT     ::ClemEngine::Key::KPSubtract
	#define CE_KEY_KP_ADD          ::ClemEngine::Key::KPAdd
	#define CE_KEY_KP_ENTER        ::ClemEngine::Key::KPEnter
	#define CE_KEY_KP_EQUAL        ::ClemEngine::Key::KPEqual

	#define CE_KEY_LEFT_SHIFT      ::ClemEngine::Key::LeftShift
	#define CE_KEY_LEFT_CONTROL    ::ClemEngine::Key::LeftControl
	#define CE_KEY_LEFT_ALT        ::ClemEngine::Key::LeftAlt
	#define CE_KEY_LEFT_SUPER      ::ClemEngine::Key::LeftSuper
	#define CE_KEY_RIGHT_SHIFT     ::ClemEngine::Key::RightShift
	#define CE_KEY_RIGHT_CONTROL   ::ClemEngine::Key::RightControl
	#define CE_KEY_RIGHT_ALT       ::ClemEngine::Key::RightAlt
	#define CE_KEY_RIGHT_SUPER     ::ClemEngine::Key::RightSuper
	#define CE_KEY_MENU            ::ClemEngine::Key::Menu
#elif CE_KEYBOARD_AZERTY
	#define CE_KEY_SPACE           ::ClemEngine::Key::Space
	#define CE_KEY_APOSTROPHE      ::ClemEngine::Key::Apostrophe    /* ' */
	#define CE_KEY_COMMA           ::ClemEngine::Key::M         /* , */
	#define CE_KEY_MINUS           ::ClemEngine::Key::Minus         /* - */
	#define CE_KEY_PERIOD          ::ClemEngine::Key::Period        /* . */
	#define CE_KEY_SLASH           ::ClemEngine::Key::Slash         /* / */
	#define CE_KEY_0               ::ClemEngine::Key::D0
	#define CE_KEY_1               ::ClemEngine::Key::D1
	#define CE_KEY_2               ::ClemEngine::Key::D2
	#define CE_KEY_3               ::ClemEngine::Key::D3
	#define CE_KEY_4               ::ClemEngine::Key::D4
	#define CE_KEY_5               ::ClemEngine::Key::D5
	#define CE_KEY_6               ::ClemEngine::Key::D6
	#define CE_KEY_7               ::ClemEngine::Key::D7
	#define CE_KEY_8               ::ClemEngine::Key::D8
	#define CE_KEY_9               ::ClemEngine::Key::D9
	#define CE_KEY_SEMICOLON       ::ClemEngine::Key::Semicolon     /* ; */
	#define CE_KEY_EQUAL           ::ClemEngine::Key::Equal         /* = */
	#define CE_KEY_A               ::ClemEngine::Key::Q
	#define CE_KEY_B               ::ClemEngine::Key::B
	#define CE_KEY_C               ::ClemEngine::Key::C
	#define CE_KEY_D               ::ClemEngine::Key::D
	#define CE_KEY_E               ::ClemEngine::Key::E
	#define CE_KEY_F               ::ClemEngine::Key::F
	#define CE_KEY_G               ::ClemEngine::Key::G
	#define CE_KEY_H               ::ClemEngine::Key::H
	#define CE_KEY_I               ::ClemEngine::Key::I
	#define CE_KEY_J               ::ClemEngine::Key::J
	#define CE_KEY_K               ::ClemEngine::Key::K
	#define CE_KEY_L               ::ClemEngine::Key::L
	#define CE_KEY_M               ::ClemEngine::Key::Comma
	#define CE_KEY_N               ::ClemEngine::Key::N
	#define CE_KEY_O               ::ClemEngine::Key::O
	#define CE_KEY_P               ::ClemEngine::Key::P
	#define CE_KEY_Q               ::ClemEngine::Key::A
	#define CE_KEY_R               ::ClemEngine::Key::R
	#define CE_KEY_S               ::ClemEngine::Key::S
	#define CE_KEY_T               ::ClemEngine::Key::T
	#define CE_KEY_U               ::ClemEngine::Key::U
	#define CE_KEY_V               ::ClemEngine::Key::V
	#define CE_KEY_W               ::ClemEngine::Key::Z
	#define CE_KEY_X               ::ClemEngine::Key::X
	#define CE_KEY_Y               ::ClemEngine::Key::Y
	#define CE_KEY_Z               ::ClemEngine::Key::W
	#define CE_KEY_LEFT_BRACKET    ::ClemEngine::Key::LeftBracket   /* [ */
	#define CE_KEY_BACKSLASH       ::ClemEngine::Key::Backslash     /* \ */
	#define CE_KEY_RIGHT_BRACKET   ::ClemEngine::Key::RightBracket  /* ] */
	#define CE_KEY_GRAVE_ACCENT    ::ClemEngine::Key::GraveAccent   /* ` */
	#define CE_KEY_WORLD_1         ::ClemEngine::Key::World1        /* non-US #1 */
	#define CE_KEY_WORLD_2         ::ClemEngine::Key::World2        /* non-US #2 */

	/* Function keys */
	#define CE_KEY_ESCAPE          ::ClemEngine::Key::Escape
	#define CE_KEY_ENTER           ::ClemEngine::Key::Enter
	#define CE_KEY_TAB             ::ClemEngine::Key::Tab
	#define CE_KEY_BACKSPACE       ::ClemEngine::Key::Backspace
	#define CE_KEY_INSERT          ::ClemEngine::Key::Insert
	#define CE_KEY_DELETE          ::ClemEngine::Key::Delete
	#define CE_KEY_RIGHT           ::ClemEngine::Key::Right
	#define CE_KEY_LEFT            ::ClemEngine::Key::Left
	#define CE_KEY_DOWN            ::ClemEngine::Key::Down
	#define CE_KEY_UP              ::ClemEngine::Key::Up
	#define CE_KEY_PAGE_UP         ::ClemEngine::Key::PageUp
	#define CE_KEY_PAGE_DOWN       ::ClemEngine::Key::PageDown
	#define CE_KEY_HOME            ::ClemEngine::Key::Home
	#define CE_KEY_END             ::ClemEngine::Key::End
	#define CE_KEY_CAPS_LOCK       ::ClemEngine::Key::CapsLock
	#define CE_KEY_SCROLL_LOCK     ::ClemEngine::Key::ScrollLock
	#define CE_KEY_NUM_LOCK        ::ClemEngine::Key::NumLock
	#define CE_KEY_PRINT_SCREEN    ::ClemEngine::Key::PrintScreen
	#define CE_KEY_PAUSE           ::ClemEngine::Key::Pause
	#define CE_KEY_F1              ::ClemEngine::Key::F1
	#define CE_KEY_F2              ::ClemEngine::Key::F2
	#define CE_KEY_F3              ::ClemEngine::Key::F3
	#define CE_KEY_F4              ::ClemEngine::Key::F4
	#define CE_KEY_F5              ::ClemEngine::Key::F5
	#define CE_KEY_F6              ::ClemEngine::Key::F6
	#define CE_KEY_F7              ::ClemEngine::Key::F7
	#define CE_KEY_F8              ::ClemEngine::Key::F8
	#define CE_KEY_F9              ::ClemEngine::Key::F9
	#define CE_KEY_F10             ::ClemEngine::Key::F10
	#define CE_KEY_F11             ::ClemEngine::Key::F11
	#define CE_KEY_F12             ::ClemEngine::Key::F12
	#define CE_KEY_F13             ::ClemEngine::Key::F13
	#define CE_KEY_F14             ::ClemEngine::Key::F14
	#define CE_KEY_F15             ::ClemEngine::Key::F15
	#define CE_KEY_F16             ::ClemEngine::Key::F16
	#define CE_KEY_F17             ::ClemEngine::Key::F17
	#define CE_KEY_F18             ::ClemEngine::Key::F18
	#define CE_KEY_F19             ::ClemEngine::Key::F19
	#define CE_KEY_F20             ::ClemEngine::Key::F20
	#define CE_KEY_F21             ::ClemEngine::Key::F21
	#define CE_KEY_F22             ::ClemEngine::Key::F22
	#define CE_KEY_F23             ::ClemEngine::Key::F23
	#define CE_KEY_F24             ::ClemEngine::Key::F24
	#define CE_KEY_F25             ::ClemEngine::Key::F25

	/* Keypad */
	#define CE_KEY_KP_0            ::ClemEngine::Key::KP0
	#define CE_KEY_KP_1            ::ClemEngine::Key::KP1
	#define CE_KEY_KP_2            ::ClemEngine::Key::KP2
	#define CE_KEY_KP_3            ::ClemEngine::Key::KP3
	#define CE_KEY_KP_4            ::ClemEngine::Key::KP4
	#define CE_KEY_KP_5            ::ClemEngine::Key::KP5
	#define CE_KEY_KP_6            ::ClemEngine::Key::KP6
	#define CE_KEY_KP_7            ::ClemEngine::Key::KP7
	#define CE_KEY_KP_8            ::ClemEngine::Key::KP8
	#define CE_KEY_KP_9            ::ClemEngine::Key::KP9
	#define CE_KEY_KP_DECIMAL      ::ClemEngine::Key::KPDecimal
	#define CE_KEY_KP_DIVIDE       ::ClemEngine::Key::KPDivide
	#define CE_KEY_KP_MULTIPLY     ::ClemEngine::Key::KPMultiply
	#define CE_KEY_KP_SUBTRACT     ::ClemEngine::Key::KPSubtract
	#define CE_KEY_KP_ADD          ::ClemEngine::Key::KPAdd
	#define CE_KEY_KP_ENTER        ::ClemEngine::Key::KPEnter
	#define CE_KEY_KP_EQUAL        ::ClemEngine::Key::KPEqual

	#define CE_KEY_LEFT_SHIFT      ::ClemEngine::Key::LeftShift
	#define CE_KEY_LEFT_CONTROL    ::ClemEngine::Key::LeftControl
	#define CE_KEY_LEFT_ALT        ::ClemEngine::Key::LeftAlt
	#define CE_KEY_LEFT_SUPER      ::ClemEngine::Key::LeftSuper
	#define CE_KEY_RIGHT_SHIFT     ::ClemEngine::Key::RightShift
	#define CE_KEY_RIGHT_CONTROL   ::ClemEngine::Key::RightControl
	#define CE_KEY_RIGHT_ALT       ::ClemEngine::Key::RightAlt
	#define CE_KEY_RIGHT_SUPER     ::ClemEngine::Key::RightSuper
	#define CE_KEY_MENU            ::ClemEngine::Key::Menu
#endif

