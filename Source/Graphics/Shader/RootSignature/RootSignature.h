#pragma once

// ���[�g�V�O�l�`�����\���������
enum class RangeType
{
	CBV, // �萔�o�b�t�@�\�r���[
	SRV, // �V�F�[�_�[���\�[�X�r���[
	UAV	 // �A���I�[�_�[�A�N�Z�X�r���[ 
};

enum class TextureAddressMode
{
	Wrap,
	Clamp
};

enum class D3D12Filter
{
	Point,
	Linear
};

// ���[�g�V�O�l�`��...�V�F�[�_�[��GPU�p�C�v���C���ԂŃ��\�[�X���o�C���h���邽�߂̐ݒ���`����\����

class RootSignature
{
public:

	// pGraphicsDevice	... �O���t�B�b�N�X�f�o�C�X�̃|�C���^
	// rangeTypes		... �����W�^�C�v���X�g
	void Create(GraphicsDevice* pGraphicsDevice, const std::vector<RangeType>& rangeTypes);

	// ���[�g�V�O�l�`���̃|�C���^
	// ID3D12RootSignature* GetRootSignature() {return m_pR}

private:

	// pRange			... �����W�̃|�C���^
	// type				... �����W�^�C�v
	// count			...	�o�^��
	void CreateRange(D3D12_DESCRIPTOR_RANGE& pRange, RangeType type, int count);

	// �T���v���̍쐬
	// pSamplerDesc		... �T���v���\�f�X�N�̃|�C���^
	// mode				... �A�h���X���[�h
	// filter			... �t�B���^�[
	// count			... �g�p�T���v���[��
	void CreateStaticSampler(D3D12_STATIC_SAMPLER_DESC& pSamplerDesc, TextureAddressMode mode,
		D3D12Filter filter, int count);

	GraphicsDevice*				m_pDevice			= nullptr;
	ComPtr<ID3DBlob>			m_pRootBlob			= nullptr;
	ComPtr<ID3D12RootSignature> m_pRootSignature	= nullptr;
};