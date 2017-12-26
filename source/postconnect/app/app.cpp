

/**
 * Copyright (c) 2016 blueback
 * Released under the MIT License
 * https://github.com/bluebackblue/brownie/blob/master/LICENSE.txt
 * http://bbbproject.sakura.ne.jp/wordpress/mitlicense
 * @brief テスト。
*/


/** include
*/
#include "../entry.h"


/** NApp
*/
namespace NApp
{
	/** App_Main
	*/
	void App_Main()
	{
		//バージョン。
		std::cout << "PostConnect 1.0.0" " " __DATE__ << std::endl;

		//ライブラリバージョン。
		std::cout << BROWNIE_VERSION_STRING << std::endl;
		
		//ファイルシステム起動。
		NBsys::NFile::StartSystem(1);
		NBsys::NFile::SetRoot(0,L"./");

		//通信。開始。
		NBsys::NWinsock::StartSystem();

		{
			
		}

		//通信。終了。
		NBsys::NWinsock::EndSystem();

		//終了処理。
		NBsys::NFile::EndSystemRequest();
		NBsys::NFile::EndWaitSystem();

		return;
	}


}

