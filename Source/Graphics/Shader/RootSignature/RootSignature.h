#pragma once

// ルートシグネチャを構成するもの
enum class RangeType
{
	CBV, // 定数バッファ―ビュー
	SRV, // シェーダーリソースビュー
	UAV	 // アンオーダーアクセスビュー 
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

// ルートシグネチャ...シェーダーとGPUパイプライン間でリソースをバインドするための設定を定義する構造体

class RootSignature
{
public:

	// pGraphicsDevice	... グラフィックスデバイスのポインタ
	// rangeTypes		... レンジタイプリスト
	void Create(GraphicsDevice* pGraphicsDevice, const std::vector<RangeType>& rangeTypes);

	// ルートシグネチャのポインタ
	// ID3D12RootSignature* GetRootSignature() {return m_pR}

private:

	// pRange			... レンジのポインタ
	// type				... レンジタイプ
	// count			...	登録数
	void CreateRange(D3D12_DESCRIPTOR_RANGE& pRange, RangeType type, int count);

	// サンプラの作成
	// pSamplerDesc		... サンプラ―デスクのポインタ
	// mode				... アドレスモード
	// filter			... フィルター
	// count			... 使用サンプラー数
	void CreateStaticSampler(D3D12_STATIC_SAMPLER_DESC& pSamplerDesc, TextureAddressMode mode,
		D3D12Filter filter, int count);

	GraphicsDevice*				m_pDevice			= nullptr;
	ComPtr<ID3DBlob>			m_pRootBlob			= nullptr;
	ComPtr<ID3D12RootSignature> m_pRootSignature	= nullptr;
};