#include "Sandbox2D.h"

Sandbox2D::Sandbox2D()
	:Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	m_SquareVA = Hazel::VertexArray::Create();

	float squareVertices[3 * 4] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	// VB
	Hazel::Ref<Hazel::VertexBuffer> m_SquareVB;
	m_SquareVB.reset(Hazel::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

	Hazel::BufferLayout squareLayout = {
		{Hazel::ShaderDataType::Float3, "a_Position"}
	};
	m_SquareVB->SetLayout(squareLayout);
	m_SquareVA->AddVertexBuffer(m_SquareVB);

	uint32_t squareIndices[6] = { 0, 1, 2, 0, 2, 3 };

	// IB
	Hazel::Ref<Hazel::IndexBuffer> m_SquareIB;
	m_SquareIB.reset(Hazel::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
	m_SquareVA->SetIndexBuffer(m_SquareIB);

	m_FlatColorShader = Hazel::Shader::Create("assets/shaders/FlatColor.glsl");
}

void Sandbox2D::OnDetach()
{
	
}

void Sandbox2D::OnUpdate(Hazel::Timestep ts)
{
	m_CameraController.OnUpdate(ts);

	Hazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Hazel::RenderCommand::Clear();

	Hazel::Renderer::BeginScene(m_CameraController.GetCamera());

	std::dynamic_pointer_cast<Hazel::OpenGLShader>(m_FlatColorShader)->Bind();
	std::dynamic_pointer_cast<Hazel::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

	m_FlatColorShader->Bind();
	Hazel::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

	Hazel::Renderer::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor)); // ͨ��ImGui������ɫ
	ImGui::End();
}

void Sandbox2D::OnEvent(Hazel::Event& event)
{
	m_CameraController.OnEvent(event);
}
