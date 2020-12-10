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

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

	ParticleSystem m_ParticleSystem;
	ParticleProps m_Particle;
};
