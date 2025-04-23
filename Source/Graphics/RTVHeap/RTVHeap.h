#pragma once
// RTV(Render Target View)
// ヒープ領域を確保し、ビューの情報を書き込んでいくもの
// 初期化時に大量のデータを確保し、ビュー情報をそのヒープに対して紐づけていく感覚
// スワップチェインで作成したバッファを、どのように使うか指示をするのがビュー

class RTVHeap
{
public:
	// pDevice	... デバイスのポインタ
	// useCount	...	使用個数
	bool Create(ID3D12Device* pDevice, int useCount);


	// pBuffer	... バッファーのポインタ
	// ヒープの紐づけられた登録番号を返す
	// RTVの作成
	int CreateRTV(ID3D12Resource* pBuffer);

	// SRVとは
	// シェーダーがリソースやテクスチャ、バッファなどに
	// アクセスするためのインターフェースを提供してくれるもの
	
	// SRV(Shader Resource View)のGPU側のアドレス
	D3D12_CPU_DESCRIPTOR_HANDLE GetRTVCPUHandle(int number);
	
private:
	ID3D12Device*					m_pDevice				= nullptr;
	ComPtr<ID3D12DescriptorHeap>	m_pHeap					= nullptr;

	int								m_useCount				= 0;
	int								m_incrementSize			= 0;
	int								m_nextRegisterNumber	= 0;
};
