#pragma once

#include "ClemEngine/Layer.h"

#include "ClemEngine/Events/ApplicationEvent.h"
#include "ClemEngine/Events/KeyEvent.h"
#include "ClemEngine/Events/MouseEvent.h"

namespace ClemEngine
{
	class CLEMENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}