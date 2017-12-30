#pragma once

/**
 * Copyright (c) 2016-2017 blueback
 * Released under the MIT License
 * https://github.com/bluebackblue/brownie/blob/master/LICENSE.txt
 * http://bbbproject.sakura.ne.jp/wordpress/mitlicense
 * @brief エントリー。
*/


/** include
*/
#include "./include.h"


/** warning push
*/
#pragma warning(push)
#pragma warning(disable:4514 4710)


/** EntryParam
*/
struct EntryParam
{
	#if(BLIB_JSONITEM_ENABLE)
	sharedptr<JsonItem> argument;
	#endif

	/** Reset
	*/
	void Reset()
	{
		#if(BLIB_JSONITEM_ENABLE)
		this->argument.reset();
		#endif
	}
};


/** GetEntryParamReference
*/
EntryParam& GetEntryParamReference();


/** warning pop
*/
#pragma warning(pop)

