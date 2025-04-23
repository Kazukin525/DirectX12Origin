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
	static const int width	= 1280;
	static const int height = 720;

	if (m_window.Create(width, height, L"FrameworkDX12", L"Window") == false)
	{
		assert(0 && "ウィンドウ作成失敗。");
		return;
	}

	if (GraphicsDevice::Instance().Init(m_window.GetWndHandle(), width, height) == false)
	{
		assert(0 && "グラフィックデバイス初期化失敗");
		return;
	}

	while (true)
	{
		if (!m_window.ProcessMessage())
		{
			break;
			
		}

		GraphicsDevice::Instance().Prepare();

		GraphicsDevice::Instance().ScreenFlip();
	}
}