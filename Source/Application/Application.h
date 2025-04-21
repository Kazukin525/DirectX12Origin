#pragma once
#include "../System/Window/Window.h"

class Application
{
public:

	// アプリケーション実行
	void Excute();

private:

	Window m_window;

	Application() {}
public:

	static Application& Instance()
	{
		static Application instance;
		return instance;
	}
};