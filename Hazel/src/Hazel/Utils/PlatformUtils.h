#pragma once

#include <string>

namespace Hazel {

	class FileDialogs
	{
	public:
		// ���ȡ�������ؿ��ַ���
		static std::string OpenFile(const char* filter);
		static std::string SaveFile(const char* filter);
	};

}