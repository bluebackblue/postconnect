#pragma once

/**
 * Copyright (c) 2016 blueback
 * Released under the MIT License
 * https://github.com/bluebackblue/brownie/blob/master/LICENSE
 * http://bbbproject.sakura.ne.jp/wordpress/mitlicense
 * @brief user_customize
*/


/** include

	test.h

	DEF_TEST_AUTO	: 自動テストを実行します。
	DEF_TEST_INDEX	: テスト番号を設定します。

*/
#if(0)
#include "./test.h"
#endif


/** brownie_config.h
*/
#define					BSYS_WINSOCK_ENABLE				(1)
#define					BSYS_HTTP_ENABLE				(1)
#define					BSYS_FILE_ENABLE				(1)
#define					BSYS_ACTIONBATCHING_ENABLE		(1)


/** メモリリークチェック。
*/
#if defined(PLATFORM_VCWIN) && (0)
#if defined(ROM_DEVELOP) || defined(ROM_DEEPDEBUG) || defined(ROM_FULLDEBUG)

	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
	#define custom_new new(_NORMAL_BLOCK,__FILE__,__LINE__)
	#define new custom_new

#endif
#endif

