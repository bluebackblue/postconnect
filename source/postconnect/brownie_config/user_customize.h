#pragma once

/**
 * Copyright (c) 2016-2017 blueback
 * Released under the MIT License
 * https://github.com/bluebackblue/brownie/blob/master/LICENSE.txt
 * http://bbbproject.sakura.ne.jp/wordpress/mitlicense
 * @brief user_customize
*/


/** brownie_config.h
*/
#define					BSYS_WINSOCK_ENABLE				(1)
#define					BSYS_HTTP_ENABLE				(1)
#define					BSYS_FILE_ENABLE				(1)
#define					BSYS_ACTIONBATCHING_ENABLE		(1)
#define					BSYS_COMMANDLINE_ENABLE			(1)


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

