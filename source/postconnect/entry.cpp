

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


/** NApp
*/
namespace NApp
{
	/** App_Main
	*/
	void App_Main();
}


/** include
*/
#include "./entry.h"


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

	GetEntryParamReference().argument = NBsys::NCommandLine::ConvertToJsonItem(a_argc,a_argv);

	#if(DEF_TEST_AUTO)
	{
		try{
			NTest::Test_Main();
		}catch(...){
			//DEBUGBREAK();
		}
	}
	#else
	{
		NApp::App_Main();
	}
	#endif

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

