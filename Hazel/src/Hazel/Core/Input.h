#pragma once

// �ڲ�ͬƽ̨������ʱ����Ӧ��****Input.cpp�ļ������ӵ�Input.h������Ҫ��������.cpp�ļ���

#include "Hazel/Core/Base.h"

namespace Hazel {

	// Input��Ӧ����ȫ�ֵģ�����Ҫ�������ʵ�������Բ��þ�̬ʵ��
	class   Input
	{
	public:
		static bool IsKeyPressed(int keycode);

		static bool IsMouseButtonPressed(int button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}