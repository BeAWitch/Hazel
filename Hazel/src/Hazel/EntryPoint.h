#pragma once

//程序入口，运行应该交由引擎来控制

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	Hazel::Log::Init();
	HZ_CORE_WARN("Initialized Log!");
	int a = 5;
	HZ_INFO("Hello Var={0}",a);

	auto app = Hazel::CreateApplication();// 实际的应用
	app->Run();
	delete app;
}

#endif
