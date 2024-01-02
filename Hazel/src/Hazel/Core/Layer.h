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

		/*��ʵ�����������������ӵ���Ϸ�����ʵ��ϵͳʱ�����á�
		��OnAttach()�����У�����Խ��г�ʼ�����������ó�ʼ״̬��������Դ������ִ��������ʵ������������ʱ��Ҫ���еĲ���*/
		virtual void OnAttach() {};
		/*��ʵ����������Ϸ�����ʵ��ϵͳ�з��루�����٣�ʱ�����á�
		��OnDetach()�����У�����Խ�����Դ���ͷţ������ڴ棬����ִ��������ʵ������������ʱ��Ҫ���еĲ���*/
		virtual void OnDetach() {};
		/*ÿһ֡����ʱ������*/
		virtual void OnUpdate(Timestep ts) {};
		/*ImGui��Ⱦ*/
		virtual void OnImGuiRender() {};
		/*���ڴ����¼�*/
		virtual void OnEvent(Event& event) { };

		inline const std::string& Getname() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}
