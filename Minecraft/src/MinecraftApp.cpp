#include <ClemEngine.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ExampleLayer : public ClemEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_CameraController(1280.0f / 720.0f)
	{
		m_VertexArray.reset(ClemEngine::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f
		};

		ClemEngine::Ref<ClemEngine::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(ClemEngine::VertexBuffer::Create(vertices, sizeof(vertices)));

		ClemEngine::BufferLayout layout = {
			{ ClemEngine::ShaderDataType::Float3, "a_Position" },
			{ ClemEngine::ShaderDataType::Float4, "a_Color" },
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };

		ClemEngine::Ref<ClemEngine::IndexBuffer> indexBuffer;
		indexBuffer.reset(ClemEngine::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(ClemEngine::VertexArray::Create());

		float squareVertices[4 * 5] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		ClemEngine::Ref<ClemEngine::VertexBuffer> squareVB;
		squareVB.reset(ClemEngine::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

		squareVB->SetLayout({
			{ ClemEngine::ShaderDataType::Float3, "a_Position" },
			{ ClemEngine::ShaderDataType::Float2, "a_TexCoord" }
			});

		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };

		ClemEngine::Ref<ClemEngine::IndexBuffer> squareIB;
		squareIB.reset(ClemEngine::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color; 
			}
		)";

		m_Shader = ClemEngine::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

		std::string flatColorShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			void main()
			{
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string flatColorShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			uniform vec3 u_Color;

			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";

		m_FlatColorShader = ClemEngine::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		m_Texture = ClemEngine::Texture2D::Create("assets/textures/Checkerboard.png");
		m_LogoTexture = ClemEngine::Texture2D::Create("assets/textures/ChernoLogo.png");

		std::dynamic_pointer_cast<ClemEngine::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<ClemEngine::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate(ClemEngine::Timestep ts) override
	{
		m_CameraController.OnUpdate(ts);

		ClemEngine::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		ClemEngine::RenderCommand::Clear();

		ClemEngine::Renderer::BeginScene(m_CameraController.GetCamera());

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<ClemEngine::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<ClemEngine::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;

				ClemEngine::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		auto textureShader = m_ShaderLibrary.Get("Texture");

		m_Texture->Bind();
		ClemEngine::Renderer::Submit(textureShader, m_SquareVA,  glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		
		m_LogoTexture->Bind();
		ClemEngine::Renderer::Submit(textureShader, m_SquareVA,glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		// Triangle
		//ClemEngine::Renderer::Submit(m_Shader, m_VertexArray);

		ClemEngine::Renderer::EndScene();
	}
	
	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	void OnEvent(ClemEngine::Event& e) override
	{
		m_CameraController.OnEvent(e);
	}

private :
	ClemEngine::ShaderLibrary m_ShaderLibrary;
	ClemEngine::Ref<ClemEngine::Shader> m_Shader;
	ClemEngine::Ref<ClemEngine::VertexArray> m_VertexArray;

	ClemEngine::Ref<ClemEngine::Shader> m_FlatColorShader;
	ClemEngine::Ref<ClemEngine::VertexArray> m_SquareVA;

	ClemEngine::Ref<ClemEngine::Texture2D> m_Texture, m_LogoTexture;

	ClemEngine::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class MinecraftApp : public ClemEngine::Application
{
public:
	MinecraftApp()
	{
		PushLayer(new ExampleLayer());
	}

	~MinecraftApp()
	{

	}
};

ClemEngine::Application* ClemEngine::CreateApplication()
{
	return new MinecraftApp();
}