#include "hzpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Hazel {

	Ref<VertexArray> VertexArray::Create()
	{
		// 根据类型，创建正确的VertexArray
		switch (Renderer::getAPI())
		{
		case RendererAPI::API::None:
			HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLVertexArray>();
		}

		HZ_CORE_ASSERT(false, "Unknown RenderAPI!");
		return nullptr;
	}

}