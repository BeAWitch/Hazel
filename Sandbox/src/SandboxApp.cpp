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

// ����Ӧ��
Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}