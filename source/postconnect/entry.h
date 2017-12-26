#pragma once

/**
 * Copyright (c) 2016 blueback
 * Released under the MIT License
 * https://github.com/bluebackblue/brownie/blob/master/LICENSE.txt
 * http://bbbproject.sakura.ne.jp/wordpress/mitlicense
 * @brief エントリー。
*/


/** include
*/
#include "./include.h"


/** include
*/
#if defined(PLATFORM_VCWIN)
	#include <brownie_config/windows_include.h>
#endif


/** EntryParam
*/
struct EntryParam
{
	#if defined(PLATFORM_VCWIN)

	HINSTANCE	hinstance;

	#endif
};


/** GetEntryParamReference
*/
EntryParam& GetEntryParamReference();

