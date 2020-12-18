#pragma once

#include "ClemEngine.h"

class ExampleLayer : public ClemEngine::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual void OnUpdate(ClemEngine::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(ClemEngine::Event& e) override;

private:
	ClemEngine::ShaderLibrary m_ShaderLibrary;
	ClemEngine::Ref<ClemEngine::Shader> m_Shader;
	ClemEngine::Ref<ClemEngine::VertexArray> m_VertexArray;

	ClemEngine::Ref<ClemEngine::Shader> m_FlatColorShader;
	ClemEngine::Ref<ClemEngine::VertexArray> m_SquareVA;

	ClemEngine::Ref<ClemEngine::Texture2D> m_Texture, m_LogoTexture;

	ClemEngine::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};