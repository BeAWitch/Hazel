#pragma once

// 在不同平台上运行时，对应的****Input.cpp文件会链接到Input.h，不需要单独创建.cpp文件。

#include "Hazel/Core/Base.h"

namespace Hazel {

	// Input类应该是全局的，不需要创建多个实例，所以采用静态实现
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