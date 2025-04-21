#pragma once

class Window
{
public:

	// ウィンドウの作成
	// clientWidth		...横幅
	// clientHeight		...縦幅
	// titleName		...タイトル名
	// windowClassName	...クラス名
	// returns			...成功したかどうか

	bool Create(int clientWidth, int clientHeight, const std::wstring& titleName, const std::wstring& windowClassName);

	// ウィンドウメッセージ処理
	// 終了メッセージが来たらfalseが来る
	bool ProcessMessage();

private:
	HWND m_hWnd;		// ウィンドウハンドル
};