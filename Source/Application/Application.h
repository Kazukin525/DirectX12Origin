#pragma once
#include "../System/Window/Window.h"

class Application
{
public:

	// �A�v���P�[�V�������s
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