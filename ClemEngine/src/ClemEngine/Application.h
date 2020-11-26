#pragma once

#include "Core.h"

#include "Window.h"
#include "ClemEngine/LayerStack.h"
#include "ClemEngine/Events/Event.h"
#include "ClemEngine/Events/ApplicationEvent.h"

#include "ClemEngine/Core/TimeStep.h"

#include "ClemEngine/ImGui/ImGuiLayer.h"

namespace ClemEngine 
{
	class Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		Timestep m_Timestep;
		float m_LastFrameTime = 0.0f;

		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}