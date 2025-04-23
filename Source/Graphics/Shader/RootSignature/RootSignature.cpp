#include "RootSignature.h"

void RootSignature::Create(GraphicsDevice* pGraphicsDevice, const std::vector<RangeType>& rangeTypes)
{
	m_pDevice = pGraphicsDevice;

	D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc = {};
	
	// �w�肳�ꂽ���\�[�X�̎��(RangeType)�̐����擾
	int rangeCount = (int)rangeTypes.size();

	// �����W�����������[�g�p�����[�^�A�����W���쐬

	// ���[�g�V�O�l�`�����̊e���\�[�X���`���邽�߂̃p�����[�^��ێ�
	std::vector<D3D12_ROOT_PARAMETER>	rootParams(rangeCount);

	// �e���\�[�X�̃f�B�X�N���v�^�����W��ێ�
	std::vector<D3D12_DESCRIPTOR_RANGE> ranges(rangeCount);

	// SRV�̐�����SamplerDesc���쐬
	int samplerCount = 0;

	for (int i = 0; i < (int)rangeTypes.size(); ++i)
	{
		if (rangeTypes[i] == RangeType::SRV)
		{
			++samplerCount;
		}
	}

	// �w�肳�ꂽ���ɐݒ�
	samplerCount = 0;
	bool	bSampler = false;
	int		cbvCount = 0;
	int		uavCount = 0;

	// �e���\�[�X�̎�ނɉ����āA�f�B�X�N���v�^�����W���쐬
	for (int i = 0; i < rangeCount; ++i)
	{
		switch (rangeTypes[i])
		{
		case RangeType::CBV:
			CreateRange(ranges[i], RangeType::CBV, cbvCount);
			rootParams[i].ParameterType		= D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
			rootParams[i].DescriptorTable.pDescriptorRanges		= &ranges[i];
			rootParams[i].DescriptorTable.NumDescriptorRanges	= 1;
			rootParams[i].ShaderVisibility	= D3D12_SHADER_VISIBILITY_ALL;
			++cbvCount;
			break;
		case RangeType::SRV:
			CreateRange(ranges[i], RangeType::SRV, samplerCount);
			rootParams[i].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
			rootParams[i].DescriptorTable.pDescriptorRanges = &ranges[i];
			rootParams[i].DescriptorTable.NumDescriptorRanges = 1;
			rootParams[i].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;
			++samplerCount;
			bSampler = true;
			break;
		case RangeType::UAV:
			CreateRange(ranges[i], RangeType::SRV, samplerCount);
			rootParams[i].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
			rootParams[i].DescriptorTable.pDescriptorRanges = &ranges[i];
			rootParams[i].DescriptorTable.NumDescriptorRanges = 1;
			rootParams[i].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;
			++uavCount;
			break;
		default:
			break;
		}
	}

	std::array<D3D12_STATIC_SAMPLER_DESC, 4> pStaticSamplerDescs = {};

	// �T���v���\	... �e�N�X�`����ǂݍ��ލۂɎg�p�����I�u�W�F�N�g
	//					�e�N�X�`���̓ǂݍ��ݕ��@�A�e�N�X�`���̏�Ԃ𐧌�
	// 
	// �T���v���\���K�v�ȏꍇ
	// �ÓI�T���v���\���쐬���A���[�h���w�肷��
	if (bSampler)
	{
		CreateStaticSampler(pStaticSamplerDescs[0], TextureAddressMode::Wrap,	D3D12Filter::Point,  0);
		CreateStaticSampler(pStaticSamplerDescs[1], TextureAddressMode::Clamp,	D3D12Filter::Point,	 1);
		CreateStaticSampler(pStaticSamplerDescs[2], TextureAddressMode::Wrap,	D3D12Filter::Linear, 2);
		CreateStaticSampler(pStaticSamplerDescs[3], TextureAddressMode::Clamp,	D3D12Filter::Linear, 3);
	}

	rootSignatureDesc.pStaticSamplers = bSampler ? pStaticSamplerDescs.data() : nullptr;
	rootSignatureDesc.NumStaticSamplers = bSampler ? 4 : 0;
	rootSignatureDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
	rootSignatureDesc.pParameters = rootParams.data();
	rootSignatureDesc.NumParameters = (int)rangeTypes.size();

	// ���[�g�V�O�l�`���[���V���A���C�Y���A���[�g�V�O�l�`�����쐬����
	ID3DBlob* pErrorBlob = nullptr;
	auto hr = D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1_0, &m_pRootBlob, &pErrorBlob);

	if (FAILED(hr))
	{
		assert(0 && "���[�g�V�O�l�`�����������s");
	}

	hr = m_pDevice->GetDevice()->CreateRootSignature(0, m_pRootBlob->GetBufferPointer(), m_pRootBlob->GetBufferSize(), IID_PPV_ARGS(&m_pRootSignature));

	if (FAILED(hr))
	{
		assert(0 && "���[�g�V�O�l�`���쐬���s");
	}
}

void RootSignature::CreateRange(D3D12_DESCRIPTOR_RANGE& pRange, RangeType type, int count)
{
}

void RootSignature::CreateStaticSampler(D3D12_STATIC_SAMPLER_DESC& pSamplerDesc, TextureAddressMode mode, D3D12Filter filter, int count)
{
}
