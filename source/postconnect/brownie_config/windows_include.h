#pragma once

/**
 * Copyright (c) blueback
 * Released under the MIT License
 * https://github.com/bluebackblue/brownie/blob/master/LICENSE.txt
 * http://bbbproject.sakura.ne.jp/wordpress/mitlicense
 * @brief windows
*/


/** _WINSOCKAPI_
*/
//#define NOMINMAX
#define _WINSOCKAPI_


/** include
*/
#pragma warning(push)
#pragma warning(disable:4710 4820 4668)
#include <windows.h>
#pragma warning(pop)


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

