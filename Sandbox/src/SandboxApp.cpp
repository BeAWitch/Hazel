#include <Hazel.h>

class Sandbox :public Hazel::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

// 创建应用
Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}