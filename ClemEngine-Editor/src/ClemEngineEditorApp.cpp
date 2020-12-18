#include <ClemEngine.h>
#include <ClemEngine/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace ClemEngine
{
	class ClemEngineEditor : public Application
	{
	public:
		ClemEngineEditor()
			: Application("ClemEngine Editor")
		{
			PushLayer(new EditorLayer());
		}

		~ClemEngineEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new ClemEngineEditor();
	}
}