#pragma once

#include "Hazel/Renderer/OrthoGraphicCamera.h"
#include "Hazel/Core/Timestep.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/MouseEvent.h"

namespace Hazel {

	class OrthoGraphicCameraController
	{
	public:
		OrthoGraphicCameraController(float aspectRatio, bool rotation = false);

		void OnUpdate(Timestep ts);
		void OnEvent(Event& e);

		OrthoGraphicCamera& GetCamera() { return m_Camera; }
		const OrthoGraphicCamera& GetCamera() const { return m_Camera; }
	private:
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	private:
		float m_AspectRatio; // ¿í¸ß±È
		float m_ZoomLevel = 1.0f; // Ëõ·Å
		OrthoGraphicCamera m_Camera;

		glm::vec3 m_CameraPosition = { 0.0f,0.0f,0.0f };
		float m_CameraTranslationSpeed = 3.0f;

		bool m_Rotation;
		float m_CameraRotation = 0.0f;
		float m_CameraRotationSpeed = 180.0f;
	};

}