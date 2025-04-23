#include "Application.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ���������[�N��m�点��
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// COM... DirectX���g�p���邽�߂ɕK�v�ȕ�
	// COM������
	CoInitializeEx(nullptr, COINIT_MULTITHREADED);

	Application::Instance().Excute();

	// COM ���
	CoUninitialize();
	
	return 0;
}

void Application::Excute()
{
	static const int width	= 1280;
	static const int height = 720;

	if (m_window.Create(width, height, L"FrameworkDX12", L"Window") == false)
	{
		assert(0 && "�E�B���h�E�쐬���s�B");
		return;
	}

	if (GraphicsDevice::Instance().Init(m_window.GetWndHandle(), width, height) == false)
	{
		assert(0 && "�O���t�B�b�N�f�o�C�X���������s");
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