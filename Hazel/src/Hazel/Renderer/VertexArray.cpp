#include "hzpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Hazel {

	VertexArray* VertexArray::Create()
	{
		// �������ͣ�������ȷ��VertexArray
		switch (Renderer::getAPI())
		{
		case RendererAPI::None:
			HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::OpenGL:
			return new OpenGLVertexArray();
		}

		HZ_CORE_ASSERT(false, "Unknown RenderAPI!");
		return nullptr;
	}

}