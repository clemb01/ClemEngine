#pragma once

#include "ClemEngine/Core/Layer.h"

#include "ClemEngine/Events/ApplicationEvent.h"
#include "ClemEngine/Events/KeyEvent.h"
#include "ClemEngine/Events/MouseEvent.h"

namespace ClemEngine
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}