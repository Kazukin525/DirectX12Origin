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
	if (!m_window.Create(1280, 720, L"FrameworkDX12", L"Window"))
	{
		assert(0 && "�E�B���h�E�쐬���s�B");
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