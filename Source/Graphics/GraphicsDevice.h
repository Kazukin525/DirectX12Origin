#pragma once

// 描画に関する
class RTVHeap;
class GraphicsDevice
{
public:

	// 初期化
	// スワップチェインの作成にウィンドウの情報が必要のため
	bool Init(HWND hWnd, int weight, int height);

	// 更新前設定
	void Prepare();

	// スワップチェインの切り替え
	void ScreenFlip();

	// コマンドキューの同期待ち
	void WaitForCommandQueue();

private:

	// ファクトリーの作成
	bool CreateFactory();

	// デバイスの作成
	bool CreateDevice();

	// コマンドリストの作成
	bool CreateCommandList();

	// スワップチェインの作成
	// フレームバッファの表示側と描画側を切り替えるための仕組み
	bool CreateSwapchain(HWND hWnd, int width, int height);

	// スワップチェインRTVの作成
	bool CreateSwapchainRTV();

	// Fenceの作成
	bool CreateFence();

	// デバッグレイヤーを適用
	void EnableDebugLayer();

	// リソースとして引数に渡したバッファの扱いを変更する関数
	// pResource ... 指定バッファ
	// before	 ... 現在の状態
	// after	 ... 新しい状態
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

	// ID3D12Device8	...	GPUと通信し、リソースやコマンドを送信する役割。
	// IDXGIFactory6	... GPUやスワップチェーン(画面描画のバッファ)を管理。
	// IDXGISwapChain4	...	描画結果を画面に表示するためのバッファを管理。

	// ID3D12GraphicsCommandList6	... GPUに実行させる一連の命令をまとめたオブジェクト
	// ID3D12CommandAllocator		... コマンドリストに格納する命令の為のメモリを管理
	// ID3D12CommandQueue			... コマンドリストを指定した順序でGPUに転送するための仕組み

	ComPtr<ID3D12Device8>					m_pDevice		= nullptr;
	ComPtr<IDXGIFactory6>					m_pDxgiFactory	= nullptr;
	ComPtr<IDXGISwapChain4>					m_pSwapChain	= nullptr;

	ComPtr<ID3D12GraphicsCommandList6>		m_pCmdList		= nullptr;
	ComPtr<ID3D12CommandAllocator>			m_pCmdAllocator	= nullptr;
	ComPtr<ID3D12CommandQueue>				m_pCmdQueue		= nullptr;

	std::array<ComPtr<ID3D12Resource>, 2>	m_pSwapchainBuffers;
	std::unique_ptr<RTVHeap>				m_upRTVHeap		= nullptr;

	// Fence ... CommandQueueの実行同期をとるためのもの
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
