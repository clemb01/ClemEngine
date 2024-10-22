#pragma once

#include "ClemEngine/Core/Base.h"

#include "ClemEngine/Core/Window.h"
#include "ClemEngine/Core/LayerStack.h"
#include "ClemEngine/Events/Event.h"
#include "ClemEngine/Events/ApplicationEvent.h"

#include "ClemEngine/Core/TimeStep.h"

#include "ClemEngine/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace ClemEngine 
{
	class Application
	{
	public:
		Application(const std::string& name = "ClemEngine App");
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		static Application& Get() { return *s_Instance; }
		Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

	private:
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		Timestep m_Timestep;
		float m_LastFrameTime = 0.0f;

		friend int ::main(int argc, char** argv);
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}