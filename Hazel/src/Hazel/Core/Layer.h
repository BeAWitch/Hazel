#pragma once

#include "Base.h"
#include "Hazel/Core/Timestep.h"
#include "Hazel/Events/Event.h"

namespace Hazel {

	class HAZEL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		/*在实体或组件被创建并附加到游戏对象或实体系统时被调用。
		在OnAttach()函数中，你可以进行初始化操作，设置初始状态，分配资源，或者执行其他在实体或组件被创建时需要进行的操作*/
		virtual void OnAttach() {};
		/*在实体或组件从游戏对象或实体系统中分离（或销毁）时被调用。
		在OnDetach()函数中，你可以进行资源的释放，清理内存，或者执行其他在实体或组件被销毁时需要进行的操作*/
		virtual void OnDetach() {};
		/*每一帧更新时被调用*/
		virtual void OnUpdate(Timestep ts) {};
		/*ImGui渲染*/
		virtual void OnImGuiRender() {};
		/*用于处理事件*/
		virtual void OnEvent(Event& event) { };

		inline const std::string& Getname() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}
