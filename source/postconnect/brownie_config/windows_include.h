#pragma once

/**
 * Copyright (c) 2016 blueback
 * Released under the MIT License
 * https://github.com/bluebackblue/brownie/blob/master/LICENSE
 * http://bbbproject.sakura.ne.jp/wordpress/mitlicense
 * @brief windows
*/


/** _WINSOCKAPI_
*/
//#define NOMINMAX
#define _WINSOCKAPI_


/** include
*/
#include <windows.h>


/** SetPort
*/
#if defined(SetPort)
	#undef SetPort
#endif


/** max
*/
//#if defined(max)
//	#undef max
//#endif


/** min
*/
//#if defined(max)
//	#undef max
//#endif

