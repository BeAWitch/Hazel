#include "hzpch.h"
#include "OrthoGraphicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Hazel {

	Hazel::OrthoGraphicCamera::OrthoGraphicCamera(float left, float right, float bottom, float top)
		:m_ProjectionMatrix(glm::ortho(left, right, bottom, top)), m_ViewMatrix(1.0f)
	{
	}

	void Hazel::OrthoGraphicCamera::ReCalculateViewMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position) *
			glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0.0f, 0.0f, 1.0f));

		// 物体相对于摄像机反向运动
		// 反转矩阵
		m_ViewMatrix = glm::inverse(transform);
	}

}
