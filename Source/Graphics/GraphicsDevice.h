#pragma once

// �`��Ɋւ���
class RTVHeap;
class GraphicsDevice
{
public:

	// ������
	// �X���b�v�`�F�C���̍쐬�ɃE�B���h�E�̏�񂪕K�v�̂���
	bool Init(HWND hWnd, int weight, int height);

	// �X�V�O�ݒ�
	void Prepare();

	// �X���b�v�`�F�C���̐؂�ւ�
	void ScreenFlip();

	// �R�}���h�L���[�̓����҂�
	void WaitForCommandQueue();

private:

	// �t�@�N�g���[�̍쐬
	bool CreateFactory();

	// �f�o�C�X�̍쐬
	bool CreateDevice();

	// �R�}���h���X�g�̍쐬
	bool CreateCommandList();

	// �X���b�v�`�F�C���̍쐬
	// �t���[���o�b�t�@�̕\�����ƕ`�摤��؂�ւ��邽�߂̎d�g��
	bool CreateSwapchain(HWND hWnd, int width, int height);

	// �X���b�v�`�F�C��RTV�̍쐬
	bool CreateSwapchainRTV();

	// Fence�̍쐬
	bool CreateFence();

	// �f�o�b�O���C���[��K�p
	void EnableDebugLayer();

	// ���\�[�X�Ƃ��Ĉ����ɓn�����o�b�t�@�̈�����ύX����֐�
	// pResource ... �w��o�b�t�@
	// before	 ... ���݂̏��
	// after	 ... �V�������
	void SetResourceBarrier(ID3D12Resource* pResource,D3D12_RESOURCE_STATES before,D3D12_RESOURCE_STATES after);

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

	// ID3D12GraphicsCommandList6	... GPU�Ɏ��s�������A�̖��߂��܂Ƃ߂��I�u�W�F�N�g
	// ID3D12CommandAllocator		... �R�}���h���X�g�Ɋi�[���閽�߂ׂ̈̃��������Ǘ�
	// ID3D12CommandQueue			... �R�}���h���X�g���w�肵��������GPU�ɓ]�����邽�߂̎d�g��

	ComPtr<ID3D12Device8>					m_pDevice		= nullptr;
	ComPtr<IDXGIFactory6>					m_pDxgiFactory	= nullptr;
	ComPtr<IDXGISwapChain4>					m_pSwapChain	= nullptr;

	ComPtr<ID3D12GraphicsCommandList6>		m_pCmdList		= nullptr;
	ComPtr<ID3D12CommandAllocator>			m_pCmdAllocator	= nullptr;
	ComPtr<ID3D12CommandQueue>				m_pCmdQueue		= nullptr;

	std::array<ComPtr<ID3D12Resource>, 2>	m_pSwapchainBuffers;
	std::unique_ptr<RTVHeap>				m_upRTVHeap		= nullptr;

	// Fence ... CommandQueue�̎��s�������Ƃ邽�߂̂���
	ComPtr<ID3D12Fence>						m_pFence		= nullptr;
	UINT64									m_fenceVal		= 0;

	GraphicsDevice() {}
	~GraphicsDevice() {}
public:
	static GraphicsDevice& Instance()
	{
		static GraphicsDevice instance;
		return instance;
	}
};
