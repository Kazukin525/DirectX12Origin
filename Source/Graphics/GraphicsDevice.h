#pragma once

// �`��Ɋւ���
class GraphicsDevice
{
public:

	// ������
	bool Init();

private:

	// �t�@�N�g���[�̍쐬
	bool CreateFactory();

	// �f�o�C�X�̍쐬
	bool CreateDevice();

	enum class GPUTier
	{
		NVIDIA,
		Amd,
		Intel,
		Arm,
		Qualcomm,
		Kind,
	};

	// ID3D12Device8	...	GPU�ƒʐM���A���\�[�X��R�}���h�𑗐M��������B
	// IDXGIFactory6	... GPU��X���b�v�`�F�[��(��ʕ`��̃o�b�t�@)���Ǘ��B
	// IDXGISwapChain4	...	�`�挋�ʂ���ʂɕ\�����邽�߂̃o�b�t�@���Ǘ��B

	ComPtr<ID3D12Device8>	m_pDevice		= nullptr;
	ComPtr<IDXGIFactory6>	m_pDxgiFactory	= nullptr;
	ComPtr<IDXGISwapChain4>	m_pSwapChain	= nullptr;

	GraphicsDevice() {}
	~GraphicsDevice() {}
public:
	static GraphicsDevice& Instance()
	{
		static GraphicsDevice instance;
		return instance;
	}
};
