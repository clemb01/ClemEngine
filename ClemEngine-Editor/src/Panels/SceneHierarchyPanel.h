#pragma once

#include "ClemEngine/Core/Base.h"
#include "ClemEngine/Core/Log.h"
#include "ClemEngine/Scene/Scene.h"
#include "ClemEngine/Scene/Entity.h"

namespace ClemEngine
{
	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& context);

		void SetContext(const Ref<Scene>& context);

		void OnImGuiRender();

	private:
		void DrawEntityNode(Entity entity);

	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};
}