#pragma once

#include "RenderCommand.h"

#include "OrthoGraphicCamera.h"
#include "Shader.h"

namespace Hazel {
	
	class Renderer
	{
	public:
		static void Init();

		static void BeginScene(OrthoGraphicCamera& camera);
		static void EndScene();

		static void Submit(const Ref<Shader>& shader, 
					const Ref<VertexArray>& vertexArray,
					const glm::mat4& transform = glm::mat4(1.0f)
					);

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