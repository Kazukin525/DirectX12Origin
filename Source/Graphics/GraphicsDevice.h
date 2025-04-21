#pragma once

// 描画に関する
class GraphicsDevice
{
public:

	// 初期化
	bool Init();

private:

	// ファクトリーの作成
	bool CreateFactory();

	// デバイスの作成
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

	// ID3D12Device8	...	GPUと通信し、リソースやコマンドを送信する役割。
	// IDXGIFactory6	... GPUやスワップチェーン(画面描画のバッファ)を管理。
	// IDXGISwapChain4	...	描画結果を画面に表示するためのバッファを管理。

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
