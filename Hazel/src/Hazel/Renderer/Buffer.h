#pragma once

// buffer的抽象接口，不存有实际的数据

namespace Hazel {

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		static VertexBuffer* Create(float* vertices, uint32_t size);
	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual uint32_t getCount() const = 0;

		static IndexBuffer* Create(uint32_t* indices, uint32_t count);// 使用count，表示顶点的数量
	};
}