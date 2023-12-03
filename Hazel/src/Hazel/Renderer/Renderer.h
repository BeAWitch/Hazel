#pragma once

#include "RenderCommand.h"

#include "OrthoGraphicCamera.h"
#include "Shader.h"

namespace Hazel {
	
	class Renderer
	{
	public:
		static void BeginScene(OrthoGraphicCamera& camera);
		static void EndScene();

		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);

		inline static RendererAPI::API getAPI() { return RendererAPI::getAPI(); }
	private:
		struct SceneData
		{
			glm::mat4 ViewMatrix;
			glm::mat4 ProjectionMatrix;
		};
		static SceneData* m_SceneData;
	};

}