#include "Sandbox2D.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	CE_PROFILE_FUNCTION();

	m_CheckerboardTexture = ClemEngine::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	CE_PROFILE_FUNCTION();

}

void Sandbox2D::OnUpdate(ClemEngine::Timestep ts)
{
	CE_PROFILE_FUNCTION();

	m_CameraController.OnUpdate(ts);

	{
		CE_PROFILE_SCOPE("Renderer Prep");
		ClemEngine::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		ClemEngine::RenderCommand::Clear();
	}
	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		CE_PROFILE_SCOPE("Renderer Draw");
		ClemEngine::Renderer2D::BeginScene(m_CameraController.GetCamera());
		ClemEngine::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, rotation, { 0.8f, 0.2f, 0.3f, 1.0f });
		ClemEngine::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		ClemEngine::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
		ClemEngine::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f);
		ClemEngine::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckerboardTexture, 10.0f);
		ClemEngine::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	CE_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(ClemEngine::Event& e)
{
	m_CameraController.OnEvent(e);
}
