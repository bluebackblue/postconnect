#pragma once

/**
 * Copyright (c) 2016-2017 blueback
 * Released under the MIT License
 * https://github.com/bluebackblue/brownie/blob/master/LICENSE.txt
 * http://bbbproject.sakura.ne.jp/wordpress/mitlicense
 * @brief コンフィグ。
*/


/** user.h
*/
#include "./user_customize.h"


/*
	-------------------
	std atomic

		std::atomicを制御します。
	-------------------

	-------------------
	BLIB_STDATOMIC_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BLIB_STDATOMIC_ENABLE)
	#define BLIB_STDATOMIC_ENABLE							(1)
#endif


/*
	-------------------
	globalfixedallocator

		グローバル固定長アロケータを制御します。
	-------------------

	-------------------
	BLIB_GLOBALFIXEDALLOCATOR_ENABLE

		0 : オフ
		1 : オン
	-------------------

	-------------------
	BLIB_GLOBALFIXEDALLOCATOR_BLOCKSIZE

		１ブロックのバイトサイズを設定します。
	-------------------

	-------------------
	BLIB_GLOBALFIXEDALLOCATOR_BLOCKMAX

		最大ブロック数を設定します。
	-------------------
*/
#if !defined(BLIB_GLOBALFIXEDALLOCATOR_ENABLE)
	#define BLIB_GLOBALFIXEDALLOCATOR_ENABLE				(1)
#endif
#if !defined(BLIB_GLOBALFIXEDALLOCATOR_BLOCKSIZE)
	#define BLIB_GLOBALFIXEDALLOCATOR_BLOCKSIZE				(32)
#endif
#if !defined(BLIB_GLOBALFIXEDALLOCATOR_BLOCKMAX)
	#define BLIB_GLOBALFIXEDALLOCATOR_BLOCKMAX				(1 * 1024 * 1024)
#endif


/*
	-------------------
	デバッグアサートコールバック

		コールバック関数の呼び出しを制御します。
		コールバック関数内で処理をカスタマイズします。
	-------------------

	-------------------
	BLIB_DEBUGASSERT_CALLBACK_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BLIB_DEBUGASSERT_CALLBACK_ENABLE)
	#define BLIB_DEBUGASSERT_CALLBACK_ENABLE				(0)
#endif


/*
	-------------------
	デバッグブレイクコールバック

		コールバック関数の呼び出しを制御します。
		コールバック関数内で処理をカスタマイズします。
	-------------------

	-------------------
	BLIB_DEBUGBREAK_CALLBACK_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BLIB_DEBUGBREAK_CALLBACK_ENABLE)
	#define BLIB_DEBUGBREAK_CALLBACK_ENABLE					(0)
#endif


/*
	-------------------
	デバッグログコールバック

		コールバック関数の呼び出しを制御します。
		コールバック関数内で処理をカスタマイズします。
	-------------------

	-------------------
	BLIB_DEBUGLOG_CALLBACK_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BLIB_DEBUGLOG_CALLBACK_ENABLE)
	#define BLIB_DEBUGLOG_CALLBACK_ENABLE					(0)
#endif


/*
	-------------------
	filehandle

		ファイルハンドルを制御します。
	-------------------

	-------------------
	BLIB_FILEHANDLE_READWRITE_BLOCKSIZE

		読み込み時、書き込み時の１ブロックのバイトサイズを設定します。
	-------------------

	-------------------
	BLIB_FILEHANDLE_RETRYMAX

		読み込み時、書き込み時のリトライ最大回数を設定します。
	-------------------
*/
#if !defined(BLIB_FILEHANDLE_READWRITE_BLOCKSIZE)
	#define BLIB_FILEHANDLE_READWRITE_BLOCKSIZE				(4096)
#endif
#if !defined(BLIB_FILEHANDLE_RETRYMAX)
	#define BLIB_FILEHANDLE_RETRYMAX						(15)
#endif


/*
	-------------------
	std regex

		std::regexを制御します。
	-------------------

	-------------------
	BLIB_STDREGEX_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BLIB_STDREGEX_ENABLE)
	#define BLIB_STDREGEX_ENABLE							(1)
#endif


/*
	-------------------
	std mutex

		std::mutexを制御します。
	-------------------

	-------------------
	BLIB_STDMUTEX_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BLIB_STDMUTEX_ENABLE)
	#define BLIB_STDMUTEX_ENABLE							(1)
#endif


/*
	-------------------
	std move

		std::moveを制御します。
	-------------------

	-------------------
	BLIB_STDMOVE_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BLIB_STDMOVE_ENABLE)
	#define BLIB_STDMOVE_ENABLE								(1)
#endif


/*
	-------------------
	math

		計算処理を制御します。
	-------------------

	-------------------
	BLIB_MATH_SINCOSFAST_TABLESIZE

		サイン、コサイン事前計算テーブルのサイズを設定します。
		Math::sinf_fast Math::cosf_fast 内で使用します。
	-------------------
*/
#if !defined(BLIB_MATH_SINCOSFAST_TABLESIZE)
	#define BLIB_MATH_SINCOSFAST_TABLESIZE					(4096)
#endif


/*
	-------------------
	メモリーコンテナー

		メモリ確保直前にメモリーコンテナーの設定や取得を行うことで、使用アロケータのカスタマイズします。
	-------------------

	-------------------
	BLIB_MEMORYCONTAINER_ENABLE

		0 : オフ
		1 : オン
	-------------------

	-------------------
	BLIB_MEMORYCONTAINER_NESTMAX

		ネスト可能な最大値を設定します。
	-------------------

	-------------------
	BLIB_MEMORYCONTAINER_THREADLOCALSLOT

		使用するスレッドローカルスロットを設定します。
		他のスロット値と重複しないようにして下さい。
	-------------------
*/
#if !defined(BLIB_MEMORYCONTAINER_ENABLE)
	#define BLIB_MEMORYCONTAINER_ENABLE						(1)
#endif
#if !defined(BLIB_MEMORYCONTAINER_NESTMAX)
	#define BLIB_MEMORYCONTAINER_NESTMAX					(16)
#endif
#if !defined(BLIB_MEMORYCONTAINER_THREADLOCALSLOT)
	#define BLIB_MEMORYCONTAINER_THREADLOCALSLOT			(0x01)
#endif


/*
	-------------------
	std random

		std::randomを制御します。
	-------------------

	-------------------
	BLIB_STDMOVE_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BLIB_STDRANDOM_ENABLE)
	#define BLIB_STDRANDOM_ENABLE							(1)
#endif


/*
	-------------------
	std sharedptr

		std::shared_ptrを制御します。
	-------------------

	-------------------
	BLIB_STDSHAREDPTR_ENABLE

		0 : オフ
		1 : オン
	-------------------

	-------------------
	BLIB_SHAREDPTR_CACHE_ENABLE

		0 : オフ
		1 : オン

		インスタンスのポインターをキャッシュします。
		BLIB_STDSHAREDPTR_ENABLEがオフの場合にのみ機能します。
	-------------------
*/
#if !defined(BLIB_STDSHAREDPTR_ENABLE)
	#define BLIB_STDSHAREDPTR_ENABLE						(0)
#endif
#if !defined(BLIB_SHAREDPTR_CACHE_ENABLE)
	#define BLIB_SHAREDPTR_CACHE_ENABLE						(1)
#endif


/*
	-------------------
	nullptr

		nullptrの制御をします。
	-------------------

	-------------------
	BLIB_STDNULLPTR_ENABLE

		0 : オフ
		1 : オン

		オンの場合はnullptrを使用します。
		オフの場合はnullptrはNULLで定義します。
	-------------------
*/
#if !defined(BLIB_STDNULLPTR_ENABLE)
	#define BLIB_STDNULLPTR_ENABLE							(1)
#endif


/*
	-------------------
	jsonitem

		JSONファイルを解析します。
		エンコードがUTF8の場合にのみ機能します。
	-------------------

	-------------------
	BLIB_JSONITEM_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BLIB_JSONITEM_ENABLE)
	#define BLIB_JSONITEM_ENABLE							(1)
#endif


/*
	-------------------
	STACKTRACE

		スタックトレースの取得します。
	-------------------

	-------------------
	BLIB_STACKTRACE_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BLIB_STACKTRACE_ENABLE)
	#define BLIB_STACKTRACE_ENABLE								(1)
#endif


/*
	-------------------
	std thread

		std::threadを制御します。
	-------------------

	-------------------
	BLIB_STDTHREAD_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BLIB_STDTHREAD_ENABLE)
	#define BLIB_STDTHREAD_ENABLE								(1)
#endif


/*
	-------------------
	std threadlocal

		std::threadlocalを制御します。
	-------------------

	-------------------
	BLIB_STDTHREADLOCAL_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BLIB_STDTHREADLOCAL_ENABLE)
	#define BLIB_STDTHREADLOCAL_ENABLE						(1)
#endif


/*
	-------------------
	thread_local

		スレッドローカル変数を制御します。
	-------------------

	-------------------
	BLIB_THREADLOCAL_ENABLE

		0 : オフ
		1 : オン
	-------------------

	-------------------
	BLIB_THREADLOCAL_SLOTMAX

		スレッドローカルスロットの最大数を設定します。
	-------------------
*/
#if !defined(BLIB_THREADLOCAL_ENABLE)
	#define BLIB_THREADLOCAL_ENABLE							(1)
#endif
#if !defined(BLIB_THREADLOCAL_SLOTMAX)
	#define BLIB_THREADLOCAL_SLOTMAX						(32)
#endif


/*
	-------------------
	VASTRING

		可変引数文字列を制御します。
	-------------------

	-------------------
	BLIB_VASTRING_DEBUG_THREADLOCALSLOT

		VASTRING_DEBUGの処理で使用するスレッドローカルスロットを設定します。
		他のスロット値と重複しないようにして下さい。
	-------------------

	-------------------
	BLIB_VASTRING_DEBUG_SIZE

		VASTRING_DEBUGの処理で使用するバッファのバイトサイズを設定します。
	-------------------
*/
#if !defined(BLIB_VASTRING_DEBUG_THREADLOCALSLOT)
	#define BLIB_VASTRING_DEBUG_THREADLOCALSLOT				(0x00)
#endif
#if !defined(BLIB_VASTRING_DEBUG_SIZE)
	#define BLIB_VASTRING_DEBUG_SIZE						(4 * 1024)
#endif


/*
	-------------------
	std unordered_map

		std::unordered_mapを制御します。
	-------------------

	-------------------
	BLIB_STDUNORDEREDMAP_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BLIB_STDUNORDEREDMAP_ENABLE)
	#define BLIB_STDUNORDEREDMAP_ENABLE						(1)
#endif


/*
	-------------------
	std alias template

		template <typename T> usingを制御します。
	-------------------

	-------------------
	BLIB_STDALIASTEMPLATE_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BLIB_STDALIASTEMPLATE_ENABLE)
	#define BLIB_STDALIASTEMPLATE_ENABLE					(1)
#endif


/*
	-------------------
	actionbatching

		アクションのバッチ処理を制御します。
	-------------------

	-------------------
	BSYS_ACTIONBATCHING_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BSYS_ACTIONBATCHING_ENABLE)
	#define BSYS_ACTIONBATCHING_ENABLE						(0)
#endif


/*
	-------------------
	color

		色を制御します。
	-------------------

	-------------------
	BSYS_COLOR_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BSYS_COLOR_ENABLE)
	#define BSYS_COLOR_ENABLE								(0)
#endif


/*
	-------------------
	file

		ファイルを制御します。
	-------------------

	-------------------
	BSYS_FILE_ENABLE

		0 : オフ
		1 : オン	
	-------------------

	-------------------
	BSYS_FILE_PACK_ENABLE

		0 : オフ
		1 : オン

		パックファイルの作成、解析を制御します。
	-------------------

	-------------------
	BSYS_FILE_MEMORYCONTAINER

		使用するメモリーコンテナーの識別ＩＤを設定します。
	-------------------

	-------------------
	BSYS_FILE_LISTSIZE

		同時処理が可能な最大リクエスト数を設定します。
	-------------------

*/
#if !defined(BSYS_FILE_ENABLE)
	#define BSYS_FILE_ENABLE								(0)
#endif
#if !defined(BSYS_FILE_PACK_ENABLE)
	#define BSYS_FILE_PACK_ENABLE							(1)
#endif
#if !defined(BSYS_FILE_MEMORYCONTAINER)
	#define BSYS_FILE_MEMORYCONTAINER						(0x01)
#endif
#if !defined(BSYS_FILE_LISTSIZE)
	#define BSYS_FILE_LISTSIZE								(512)
#endif


/*
	-------------------
	vertex

		バーテクスを制御します。
	-------------------

	-------------------
	BSYS_VERTEX_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BSYS_VERTEX_ENABLE)
	#define BSYS_VERTEX_ENABLE								(0)
#endif


/*
	-------------------
	opengl

		OpenGLを制御します。
	-------------------

	-------------------
	BSYS_OPENGL_ENABLE

		0 : オフ
		1 : オン
	-------------------

	-------------------
	BSYS_OPENGL_DEBUG_ENABLE

		0 : オフ
		1 : オン

		デバッグ機能を制御します。
	-------------------

	-------------------
	BSYS_OPENGL_UPDATE_FPS

		ＦＰＳを設定します。
	-------------------

	-------------------
	BSYS_OPENGL_WIDTH

		ウィンドウの横幅を設定します。
	-------------------

	-------------------
	BSYS_OPENGL_HEIGHT

		ウィンドウの縦幅を設定します。
	-------------------

	-------------------
	BSYS_OPENGL_SHADERIDMAX

		ロード可能なシェーダの最大数を設定します。
	-------------------
*/
#if !defined(BSYS_OPENGL_ENABLE)
	#define BSYS_OPENGL_ENABLE								(0)
#endif
#if !defined(BSYS_OPENGL_DEBUG_ENABLE)
	#define BSYS_OPENGL_DEBUG_ENABLE						(0)
#endif
#if !defined(BSYS_OPENGL_UPDATE_FPS)
	#define BSYS_OPENGL_UPDATE_FPS							(60)
#endif
#if !defined(BSYS_OPENGL_WIDTH)
	#define BSYS_OPENGL_WIDTH								(1440)
#endif
#if !defined(BSYS_OPENGL_HEIGHT)
	#define BSYS_OPENGL_HEIGHT								(810)
#endif
#if !defined(BSYS_OPENGL_SHADERIDMAX)
	#define BSYS_OPENGL_SHADERIDMAX							(32)
#endif


/*
	-------------------
	geometry

		matrix、vector、quaternion、frustumを制御します。
	-------------------

	-------------------
	BSYS_GEOMETRY_ENABLE

		0 : オフ
		1 : オン
	-------------------

	-------------------
	BSYS_GEOMETRY_MATRIX_SINCOSFAST_ENABLE

		0 : オフ
		1 : オン

		Math::sinf_fast、Math::cisf_fastの使用を制御します。
	-------------------

	-------------------
	BSYS_GEOMETRY_PERSPECTIVE_TYPE

		0 : directx
		1 : opengl

		nearの計算方法を制御します。
	-------------------

	-------------------
	BSYS_GEOMETRY_ROWCOLUMN_TYPE

		0 : Row-major
		1 : Column-major

		Matrixの計算方法を制御します。
	-------------------

	-------------------
	BSYS_GEOMETRY_LEFTRIGHT_TYPE

		0 : 左手座標系
		1 : 右手座標系

		PerspectiveProjectionMatrix ViewMatrixの計算方法を制御します。
	-------------------
*/
#if !defined(BSYS_GEOMETRY_ENABLE)
	#define BSYS_GEOMETRY_ENABLE							(0)
#endif
#if !defined(BSYS_GEOMETRY_MATRIX_SINCOSFAST_ENABLE)
	#define BSYS_GEOMETRY_MATRIX_SINCOSFAST_ENABLE			(1)
#endif
#if !defined(BSYS_GEOMETRY_PERSPECTIVE_TYPE)
	#define BSYS_GEOMETRY_PERSPECTIVE_TYPE					(0x00)
#endif
#if !defined(BSYS_GEOMETRY_ROWCOLUMN_TYPE)
	#define BSYS_GEOMETRY_ROWCOLUMN_TYPE					(0x00)
#endif
#if !defined(BSYS_GEOMETRY_LEFTRIGHT_TYPE)
	#define BSYS_GEOMETRY_LEFTRIGHT_TYPE					(0x00)
#endif


/*
	-------------------
	fovehmd

		FOVE0を制御します。
	-------------------

	-------------------
	BSYS_FOVEHMD_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BSYS_FOVEHMD_ENABLE)
#define BSYS_FOVEHMD_ENABLE									(0)
#endif


/*
	-------------------
	window

		ウィンドウハンドルを制御します。
	-------------------

	-------------------
	BSYS_WINDOW_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BSYS_WINDOW_ENABLE)
	#define BSYS_WINDOW_ENABLE								(0)
#endif


/*
	-------------------
	d3d11
	-------------------

	-------------------
	BSYS_D3D11_ENABLE

		0 : オフ
		1 : オン
	-------------------

	-------------------
	BSYS_D3D11_DEBUG_ENABLE

		0 : オフ
		1 : オン

		デバッグ機能を制御します。
	-------------------

	-------------------
	BSYS_D3D11_FONT_DRAWTYPEMAX_S

		小フォントテクスチャーに格納可能な文字数を設定します。
	-------------------

	-------------------
	BSYS_D3D11_FONT_DRAWTYPEMAX_M

		中フォントテクスチャーに格納可能な文字数を設定します。
	-------------------

	-------------------
	BSYS_D3D11_FONT_DRAWTYPEMAX_L

		大フォントテクスチャーに格納可能な文字数を設定します。
	-------------------

	-------------------
	BSYS_D3D11_FONT_DRAWTYPEMAX_EX

		特大フォントテクスチャーに格納可能な文字数を設定します。
	-------------------

*/
#if !defined(BSYS_D3D11_ENABLE)
	#define BSYS_D3D11_ENABLE								(0)
#endif
#if !defined(BSYS_D3D11_DEBUG_ENABLE)
	#define BSYS_D3D11_DEBUG_ENABLE							(0)
#endif
#if !defined(BSYS_D3D11_FONT_DRAWTYPEMAX_S)
	#define BSYS_D3D11_FONT_DRAWTYPEMAX_S					(128)
#endif
#if !defined(BSYS_D3D11_FONT_DRAWTYPEMAX_M)
	#define BSYS_D3D11_FONT_DRAWTYPEMAX_M					(128)
#endif
#if !defined(BSYS_D3D11_FONT_DRAWTYPEMAX_L)
	#define BSYS_D3D11_FONT_DRAWTYPEMAX_L					(32)
#endif
#if !defined(BSYS_D3D11_FONT_DRAWTYPEMAX_EX)
	#define BSYS_D3D11_FONT_DRAWTYPEMAX_EX					(16)
#endif


/*
	-------------------
	mmd

		PMXファイル、VMDファイルを制御します。
	-------------------

	-------------------
	BSYS_MMD_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BSYS_MMD_ENABLE)
	#define BSYS_MMD_ENABLE									(0)
#endif


/*
	-------------------
	texture

		テクスチャーファイルを制御します。
	-------------------

	-------------------
	BSYS_TEXTURE_ENABLE

		0 : オフ
		1 : オン
	-------------------

	-------------------
	BSYS_TEXTURE_GDIPLUS_ENABLE

		0 : オフ
		1 : オン

		Gdiplusを使用します。
	-------------------
*/
#if !defined(BSYS_TEXTURE_ENABLE)
	#define BSYS_TEXTURE_ENABLE								(0)
#endif
#if !defined(BSYS_TEXTURE_GDIPLUS_ENABLE)
	#define BSYS_TEXTURE_GDIPLUS_ENABLE						(0)
#endif


/*
	-------------------
	rootsearch

		TODO:一旦削除予定
	-------------------

	-------------------
	BSYS_ROOTSEARCH_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BSYS_ROOTSEARCH_ENABLE)
	#define BSYS_ROOTSEARCH_ENABLE							(0)
#endif


/*
	-------------------
	font

		フォントファイルを制御します。
	-------------------

	-------------------
	BSYS_FONT_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BSYS_FONT_ENABLE)
	#define BSYS_FONT_ENABLE								(0)
#endif


/*
	-------------------
	pad

		入力デバイスを制御します。
	-------------------

	-------------------
	BSYS_PAD_ENABLE

		0 : オフ
		1 : オン
	-------------------	
*/
#if !defined(BSYS_PAD_ENABLE)
	#define BSYS_PAD_ENABLE									(0)
#endif


/*
	-------------------
	windowmenu

		ウィンドウのドラッグ、ボタン、テクスチャー表示を制御します。
	-------------------

	-------------------
	BSYS_WINDOWMENU_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BSYS_WINDOWMENU_ENABLE)
	#define BSYS_WINDOWMENU_ENABLE							(0)
#endif


/*
	-------------------
	winsock

		winsockを制御します。
	-------------------

	-------------------
	BSYS_WINSOCK_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BSYS_WINSOCK_ENABLE)
	#define BSYS_WINSOCK_ENABLE								(0)
#endif


/*
	-------------------
	http

		HTTP通信を制御します。
	-------------------

	-------------------
	BSYS_HTTP_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BSYS_HTTP_ENABLE)
	#define BSYS_HTTP_ENABLE								(0)
#endif
#if !defined(BSYS_HTTP_USERAGENT)
	#define BSYS_HTTP_USERAGENT								BROWNIE_VERSION_STRING
#endif



/*
	-------------------
	commandline

		コマンドライン解析を制御します。
	-------------------

	-------------------
	BSYS_COMMANDLINE_ENABLE

		0 : オフ
		1 : オン
	-------------------
*/
#if !defined(BSYS_COMMANDLINE_ENABLE)
	#define BSYS_COMMANDLINE_ENABLE							(0)
#endif

