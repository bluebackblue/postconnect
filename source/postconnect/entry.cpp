

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


/** include
*/
#if defined(PLATFORM_VCWIN)
	#include <brownie_config/windows_include.h>
#endif


/** include
*/
#include "./entry.h"


/** warning

4710 : この関数はインライン展開のために選択されましたが、コンパイラはインライン展開を実行しませんでした。

*/
#pragma warning(disable:4710)


/** NTest
*/
namespace NApp
{
	/** App_Main
	*/
	void App_Main();
}


/** GetEntryParamReference
*/
EntryParam& GetEntryParamReference()
{
	static EntryParam s_entryparam;
	return s_entryparam;
}


/** s_leakcheck
*/
#if defined(ROM_DEVELOP) || defined(ROM_DEEPDEBUG) || defined(ROM_FULLDEBUG)
static bool s_leakcheck = false;
#endif


/** warning

4710 : この関数はインライン展開のために選択されましたが、コンパイラはインライン展開を実行しませんでした。

*/
#pragma warning(disable:4710)


/** Main
*/
#if defined(PLATFORM_VCWIN)
void main(int a_argc,char** a_argv)
#elif defined(PLATFORM_GNUCWIN)
int main(int a_argc,char** a_argv)
#endif
{
	#if defined(PLATFORM_VCWIN)
	#if defined(ROM_DEVELOP) || defined(ROM_DEEPDEBUG) || defined(ROM_FULLDEBUG)
	if(s_leakcheck == false){
		s_leakcheck = true;
		::_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF|_CRTDBG_ALLOC_MEM_DF);
	}
	#endif
	#endif

	sharedptr<Blib> t_blib;
	if(NBlib::IsBootInitialize() == false){
		t_blib = NBlib::BootInitialize();
	}

	#if(BSYS_COMMANDLINE_ENABLE)
	GetEntryParamReference().argument = NBsys::NCommandLine::ConvertToJsonItem(a_argc,a_argv);
	#else
	UNUSED(a_argc);
	UNUSED(a_argv);
	#endif

	NApp::App_Main();

	GetEntryParamReference().Reset();

	#if defined(PLATFORM_GNUCWIN)
	return 0;
	#endif
}


/** WinMain
*/
#if defined(PLATFORM_VCWIN)
int WINAPI WinMain(_In_ HINSTANCE /*a_hinstance*/,_In_opt_ HINSTANCE /*a_prev_hinstance*/,_In_ LPSTR /*a_commandline*/,_In_ int /*a_cmdshow*/)
{
	#if defined(ROM_DEVELOP) || defined(ROM_DEEPDEBUG) || defined(ROM_FULLDEBUG)
	if(s_leakcheck == false){
		s_leakcheck = true;
		::_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF|_CRTDBG_ALLOC_MEM_DF);
	}
	#endif

	sharedptr<Blib> t_blib;
	if(NBlib::IsBootInitialize() == false){
		t_blib = NBlib::BootInitialize();
	}

	main(__argc,__argv);

	GetEntryParamReference().Reset();

	return 0;
}
#endif

