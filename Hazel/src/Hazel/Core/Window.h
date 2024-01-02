#pragma once

#include "hzpch.h"

#include "Hazel/Core/Base.h"
#include "Hazel/Events/Event.h"

namespace Hazel {

	//窗口属性
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Hazel Engine",
					unsigned int width = 1280,
					unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{

		}
	};

	class HAZEL_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window(){}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// 窗口属性
		// 设置回调函数
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		// 设置垂直同步
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		// 使用void类型的指针，是为了不用GLFW时也能适配
		virtual void* GetNativeWindow() const = 0;

		//需在每个平台中实现
		static Window* Create(const WindowProps& props = WindowProps());
	};
}