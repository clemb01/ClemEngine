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
	m_CheckerboardTexture = ClemEngine::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{

}

void Sandbox2D::OnUpdate(ClemEngine::Timestep ts)
{
	m_CameraController.OnUpdate(ts);

	ClemEngine::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	ClemEngine::RenderCommand::Clear();

	ClemEngine::Renderer2D::BeginScene(m_CameraController.GetCamera());

	ClemEngine::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 1.0f }, { 0.8f, 0.2f, 0.3f, 1.0f });
	ClemEngine::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 1.0f, 1.0f }, m_SquareColor);
	ClemEngine::Renderer2D::DrawQuad({ 0.2f, 0.5f, -0.1f }, { 0.5f, 0.5f }, m_CheckerboardTexture);

	ClemEngine::Renderer2D::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(ClemEngine::Event& e)
{
	m_CameraController.OnEvent(e);
}
