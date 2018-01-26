#pragma once

/**
 * Copyright (c) blueback
 * Released under the MIT License
 * https://github.com/bluebackblue/brownie/blob/master/LICENSE.txt
 * http://bbbproject.sakura.ne.jp/wordpress/mitlicense
 * @brief fovehmd
*/


/** lib
*/
#if defined(ROM_32BIT)
	#error ""
#else
	#pragma comment(lib, "fovehmd/FOVE SDK 0.11.4/lib/FoveClient.lib")
#endif

