#pragma once
// RTV(Render Target View)
// �q�[�v�̈���m�ۂ��A�r���[�̏�����������ł�������
// ���������ɑ�ʂ̃f�[�^���m�ۂ��A�r���[�������̃q�[�v�ɑ΂��ĕR�Â��Ă������o
// �X���b�v�`�F�C���ō쐬�����o�b�t�@���A�ǂ̂悤�Ɏg�����w��������̂��r���[

class RTVHeap
{
public:
	// pDevice	... �f�o�C�X�̃|�C���^
	// useCount	...	�g�p��
	bool Create(ID3D12Device* pDevice, int useCount);


	// pBuffer	... �o�b�t�@�[�̃|�C���^
	// �q�[�v�̕R�Â���ꂽ�o�^�ԍ���Ԃ�
	// RTV�̍쐬
	int CreateRTV(ID3D12Resource* pBuffer);

	// SRV�Ƃ�
	// �V�F�[�_�[�����\�[�X��e�N�X�`���A�o�b�t�@�Ȃǂ�
	// �A�N�Z�X���邽�߂̃C���^�[�t�F�[�X��񋟂��Ă�������
	
	// SRV(Shader Resource View)��GPU���̃A�h���X
	D3D12_CPU_DESCRIPTOR_HANDLE GetRTVCPUHandle(int number);
	
private:
	ID3D12Device*					m_pDevice				= nullptr;
	ComPtr<ID3D12DescriptorHeap>	m_pHeap					= nullptr;

	int								m_useCount				= 0;
	int								m_incrementSize			= 0;
	int								m_nextRegisterNumber	= 0;
};
