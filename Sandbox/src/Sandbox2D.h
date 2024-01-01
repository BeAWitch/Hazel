#pragma once

#include <Hazel.h>

#include "ParticleSystem.h"

class Sandbox2D :public Hazel::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual void OnUpdate(Hazel::Timestep ts) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(Hazel::Event& event) override;
private:
	Hazel::OrthographicCameraController m_CameraController;

	// Temp
	Hazel::Ref<Hazel::VertexArray> m_SquareVA;
	Hazel::Ref<Hazel::Shader> m_FlatColorShader;
	Hazel::Ref<Hazel::SubTexture2D> m_TextureStairs, m_TextureBarrel, m_TextureTree;

	Hazel::Ref<Hazel::Texture2D> m_ChernoLogoTexture;
	Hazel::Ref<Hazel::Texture2D> m_SpriteSheet;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

	ParticleProps m_Particle;
	ParticleSystem m_ParticleSystem;

	uint32_t m_MapWidth = 0, m_MapHeight = 0;
	std::unordered_map<char, Hazel::Ref<Hazel::SubTexture2D>> s_TextureMap;
};