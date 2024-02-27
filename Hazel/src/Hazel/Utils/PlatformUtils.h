#pragma once

#include <string>

namespace Hazel {

	class FileDialogs
	{
	public:
		// 如果取消，返回空字符串
		static std::string OpenFile(const char* filter);
		static std::string SaveFile(const char* filter);
	};

}