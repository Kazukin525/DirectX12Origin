#pragma once

//============================================
// プリコンパイル済みヘッダー
// ここに書いたものは初回のみ解析されるため、コンパイル時間が高速になる。
// 全てのcppからインクルードされる必要がある。
//============================================

//============================================
// 基本
//============================================

// このライブラリをリンクする
#pragma comment(lib,"winmm.lib")

#define NOMINMAX

#include <Windows.h>
#include <iostream>
#include <cassert>

#include <wrl/client.h>

//==============================================
//STL
//==============================================

#include <map>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<array>
#include<vector>
#include<stack>
#include<list>
#include<iterator>
#include<queue>
#include<algorithm>
#include<memory>
#include<random>
#include<fstream>
#include<sstream>
#include<functional>
#include<thread>
#include<atomic>
#include<mutex>
#include<future>
#include<fileSystem>
#include<chrono>

#define _USE_MATH_DEFINES
#include <math.h>

// DirectXに必要な物
#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")

#include <d3d12.h>
#include <dxgi1_6.h>


// どこでも使いまわしたいインクルードファイル
#include "System/System.h"