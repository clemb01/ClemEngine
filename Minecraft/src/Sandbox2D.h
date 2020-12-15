#pragma once

#include "ClemEngine.h"

#include "ParticleSystem.h"

class Sandbox2D : public ClemEngine::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(ClemEngine::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(ClemEngine::Event& e) override;

private:
	ClemEngine::OrthographicCameraController m_CameraController;
	
	ClemEngine::Ref<ClemEngine::VertexArray> m_SquareVA;
	ClemEngine::Ref<ClemEngine::Shader> m_FlatColorShader;

	ClemEngine::Ref<ClemEngine::Texture2D> m_CheckerboardTexture;
	ClemEngine::Ref<ClemEngine::Texture2D> m_SpriteSheet;
	ClemEngine::Ref<ClemEngine::SubTexture2D> m_TextureStairs, m_TextureBarrel, m_TextureTree;

	glm::vec4 m_TintColor = { 1.0f, 1.0f, 1.0f, 1.0f };

	ParticleSystem m_ParticleSystem;
	ParticleProps m_Particle;

	uint32_t m_MapWidth, m_MapHeight;
	std::unordered_map<char, ClemEngine::Ref<ClemEngine::SubTexture2D>> s_TextureMap;
};
