#pragma once

#include "Core.h"

#include "Window.h"
#include "ClemEngine/LayerStack.h"
#include "ClemEngine/Events/Event.h"
#include "ClemEngine/Events/ApplicationEvent.h"

#include "ClemEngine/ImGui/ImGuiLayer.h"

#include "ClemEngine/Renderer/Shader.h"
#include "ClemEngine/Renderer/Buffer.h"
#include "ClemEngine/Renderer/VertexArray.h"

namespace ClemEngine 
{
	class CLEMENGINE_API Application
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

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}