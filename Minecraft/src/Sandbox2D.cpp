#include "Sandbox2D.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

static const uint32_t s_MapWidth = 24;
static const char* s_MapTiles = 
"WWWWWWWWWWWWWWWWWWWWWWWW"
"WWWWWWDDDDDDDWWWWWWWWWWW"
"WWWWDDDDDDDDDDDDWWWWWWWW"
"WWWDDDDDDDDDDDDDDDDWWWWW"
"WWDDDDDDDDDDDDDDDDDDDWWW"
"WWDDWWWDDDDDDDDDDDDDDWWW"
"WDDDWWWDDDDDDDDDDDDDDDWW"
"WWDDDDDDDDDDDDDDDDDDWWWW"
"WWWDDDDDDDDDDDDDDDDWWWWW"
"WWWWDDDDDDDDDDDDDDWWWWWW"
"WWWWWDDDDDDDDDDDWWWWWWWW"
"WWWWWWDDDDDDDDDWWWWWWWWW"
"WWWWWWWWWDDDDWWWWWWWWWWW"
"WWWWWWWWWWWWWWWWWWWWWWWW";

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	CE_PROFILE_FUNCTION();

	m_CheckerboardTexture = ClemEngine::Texture2D::Create("assets/textures/Checkerboard.png");
	m_SpriteSheet = ClemEngine::Texture2D::Create("assets/game/textures/RPGpack_sheet_2X.png");

	m_MapWidth = s_MapWidth;
	m_MapHeight = strlen(s_MapTiles) / s_MapWidth;

	m_TextureStairs = ClemEngine::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 0, 11 }, { 128.0f, 128.0f });
	m_TextureBarrel = ClemEngine::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 9, 2 }, { 128.0f, 128.0f });

	s_TextureMap['D'] = ClemEngine::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 6, 11 }, { 128.0f, 128.0f });
	s_TextureMap['W'] = ClemEngine::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 11, 11 }, { 128.0f, 128.0f });

	m_TextureTree = ClemEngine::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 2.0f, 1.0f }, { 128.0f, 128.0f }, { 1.0f, 2.0f });

	m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
	m_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
	m_Particle.SizeBegin = 0.5f, m_Particle.SizeVariation = 0.3f, m_Particle.SizeEnd = 0.0f;
	m_Particle.LifeTime = 5.0f;
	m_Particle.Velocity = { 0.0f, 0.0f };
	m_Particle.VelocityVariation = { 3.0f, 1.0f };
	m_Particle.Position = { 0.0f, 0.0f };
}

void Sandbox2D::OnDetach()
{
	CE_PROFILE_FUNCTION();

}

void Sandbox2D::OnUpdate(ClemEngine::Timestep ts)
{
	CE_PROFILE_FUNCTION();

	m_CameraController.OnUpdate(ts);

	ClemEngine::Renderer2D::ResetStats();
	{
		CE_PROFILE_SCOPE("Renderer Prep");
		ClemEngine::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		ClemEngine::RenderCommand::Clear();
	}

#if 0
	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		CE_PROFILE_SCOPE("Renderer Draw");
		ClemEngine::Renderer2D::BeginScene(m_CameraController.GetCamera());
		ClemEngine::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(rotation), { 0.8f, 0.2f, 0.3f, 1.0f });
		ClemEngine::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		ClemEngine::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
		ClemEngine::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);
		ClemEngine::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, glm::radians(rotation), m_CheckerboardTexture, 10.0f);
		ClemEngine::Renderer2D::EndScene();

		ClemEngine::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y <= 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x <= 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
				ClemEngine::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		ClemEngine::Renderer2D::EndScene();
	}
#endif

	if (ClemEngine::Input::IsMouseButtonPressed(CE_MOUSE_BUTTON_LEFT))
	{
		auto [x, y] = ClemEngine::Input::GetMousePosition();
		auto width = ClemEngine::Application::Get().GetWindow().GetWidth();
		auto height = ClemEngine::Application::Get().GetWindow().GetHeight();

		auto bounds = m_CameraController.GetBounds();
		auto pos = m_CameraController.GetCamera().GetPosition();
		x = (x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
		y = bounds.GetHeight() * 0.5f - (y / height) * bounds.GetHeight();
		m_Particle.Position = { x + pos.x, y + pos.y };
		for (int i = 0; i < 5; i++)
			m_ParticleSystem.Emit(m_Particle);
	}

	ClemEngine::Renderer2D::BeginScene(m_CameraController.GetCamera());

	for (uint32_t y = 0; y < m_MapHeight; y++)
	{
		for (uint32_t x = 0; x < m_MapWidth; x++)
		{
			char tileType = s_MapTiles[x + y * m_MapWidth];
			ClemEngine::Ref<ClemEngine::SubTexture2D> texture;
			if (s_TextureMap.find(tileType) != s_TextureMap.end())
				texture = s_TextureMap[tileType];
			else
				texture = m_TextureBarrel;

			ClemEngine::Renderer2D::DrawQuad({ x - m_MapWidth / 2.0f, m_MapHeight - y - m_MapHeight / 2.0f, 0.1f }, { 1.0f, 1.0f }, texture);
		}
	}

	//ClemEngine::Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.1f }, { 1.0f, 1.0f }, m_TextureStairs, 1.0f, m_TintColor);
	//ClemEngine::Renderer2D::DrawQuad({ 1.0f, 0.0f, 0.1f }, { 1.0f, 1.0f }, s_TextureMap);
	//ClemEngine::Renderer2D::DrawQuad({ -1.0f, 0.0f, 0.1f }, { 1.0f, 2.0f }, m_TextureTree);
	ClemEngine::Renderer2D::EndScene();

	//m_ParticleSystem.OnUpdate(ts);
	//m_ParticleSystem.OnRender(m_CameraController.GetCamera());
}

void Sandbox2D::OnImGuiRender()
{
	CE_PROFILE_FUNCTION();

	ImGui::Begin("Settings");

	auto stats = ClemEngine::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls %d", stats.DrawCalls);
	ImGui::Text("Quads %d", stats.QuadCount);
	ImGui::Text("Vertices %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices %d", stats.GetTotalIndexCount());

	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_TintColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(ClemEngine::Event& e)
{
	m_CameraController.OnEvent(e);
}
