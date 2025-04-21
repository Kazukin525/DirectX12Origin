#include "Application.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// メモリリークを知らせる
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// COM... DirectXを使用するために必要な物
	// COM初期化
	CoInitializeEx(nullptr, COINIT_MULTITHREADED);

	Application::Instance().Excute();

	// COM 解放
	CoUninitialize();
	
	return 0;
}

void Application::Excute()
{
	if (!m_window.Create(1280, 720, L"FrameworkDX12", L"Window"))
	{
		assert(0 && "ウィンドウ作成失敗。");
		return;
	}

	while (true)
	{
		if (!m_window.ProcessMessage())
		{
			break;
		}
	}
}