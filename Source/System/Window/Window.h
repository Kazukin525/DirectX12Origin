#pragma once

class Window
{
public:

	// �E�B���h�E�̍쐬
	// clientWidth		...����
	// clientHeight		...�c��
	// titleName		...�^�C�g����
	// windowClassName	...�N���X��
	// returns			...�����������ǂ���

	bool Create(int clientWidth, int clientHeight, const std::wstring& titleName, const std::wstring& windowClassName);

	// �E�B���h�E���b�Z�[�W����
	// �I�����b�Z�[�W��������false������
	bool ProcessMessage();

private:
	HWND m_hWnd;		// �E�B���h�E�n���h��
};