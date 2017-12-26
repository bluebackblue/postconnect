

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
	/** App
	*/
	class App
	{
	private:

		/** app_argument
		*/
		sharedptr<JsonItem> app_argument;

		/** コンフィグファイル名。
		*/
		STLWString filename_config;

		/** コンフィグ。
		*/
		sharedptr<JsonItem> config;

		/** ＨＴＴＰ。
		*/
		sharedptr<NBsys::NHttp::Http> http;

	public:

		/** バイナリの読み込み。
		*/
		sharedptr<NBsys::NFile::File_Object> LoaBinaryFile(const STLWString& a_filename)
		{
			//読み込み開始。
			sharedptr<NBsys::NFile::File_Object> t_fileobject;
			t_fileobject.reset(new NBsys::NFile::File_Object(0,a_filename,-1,nullptr,0));

			//読み込み中。
			while(t_fileobject->IsBusy() == true){
				ThreadSleep(100);
			}

			if(t_fileobject->GetErrorCode() == ErrorCode::Success){
				return t_fileobject;
			}

			return nullptr;
		}

		/** ＪＳＯＮファイルの読み込み。
		*/
		sharedptr<JsonItem> LoadJsonFile(const STLWString& a_filename)
		{
			//読み込み開始。
			sharedptr<NBsys::NFile::File_Object> t_fileobject;
			t_fileobject.reset(new NBsys::NFile::File_Object(0,a_filename,-1,nullptr,1));

			//読み込み中。
			while(t_fileobject->IsBusy() == true){
				ThreadSleep(100);
			}

			if(t_fileobject->GetErrorCode() == ErrorCode::Success){

				//コンバート。
				for(;;){
					NBsys::NFile::File_ConvertLock_ReturnType::Id t_ret = t_fileobject->ConvertLock();
					if(t_ret == NBsys::NFile::File_ConvertLock_ReturnType::Locked){
						//未コンバート => コンバート中。

						//コンバート中 => コンバート済み。
						t_fileobject->GetLoadData().get()[static_cast<s32>(t_fileobject->GetLoadSize())] = 0x00;
						t_fileobject->ConvertUnlock();

						break;
					}else if(t_ret == NBsys::NFile::File_ConvertLock_ReturnType::ConvertNow){
						//コンバート中。

						//ロックに成功していないのでアンロック不要。
					}else{
						//コンバート済み。

						//ロックに成功していないのでアンロック不要。
						break;
					}
				}

				if(t_fileobject->GetLoadSize() > 0){
					sharedptr<JsonItem> t_jsonitem(new JsonItem(reinterpret_cast<char*>(t_fileobject->GetLoadData().get())));
					return t_jsonitem;
				}
			}

			return nullptr;
		}


		/** コンフィグの読み込み。
		*/
		bool LoadConfig()
		{
			this->app_argument = GetEntryParamReference().argument;

			//ファイル名解析。
			if(this->app_argument){
				if(this->app_argument->IsExistItem("-input") == true){
					if(this->app_argument->GetItem("-input")->GetValueType() == JsonItem::ValueType::StringData){
						CharToWchar(*this->app_argument->GetItem("-input")->GetStringData().get(),this->filename_config);
					}
				}
			}

			//ＪＳＯＮファイルの読み込み。
			if(filename_config.length() > 0){
				this->config = this->LoadJsonFile(this->filename_config);
				if(this->config){
					return true;
				}
			}

			return false;
		}


		/** ＨＴＴＰ作成。
		*/
		bool CreateHttp()
		{
			this->http.reset(new NBsys::NHttp::Http());
			
			if(this->config){
				this->http->SetMode(NBsys::NHttp::Http_Mode::Post);

				if(this->config->IsExistItem("host") == true){
					if(this->config->GetItem("host")->GetValueType() == JsonItem::ValueType::StringData){
						STLString t_host = *this->config->GetItem("host")->GetStringData();
						if(t_host.length() > 0){
							this->http->SetHost(t_host);
						}
					}else{
						return nullptr;
					}
				}else{
					return nullptr;
				}

				if(this->config->IsExistItem("port") == true){
					if(this->config->GetItem("port")->GetValueType() == JsonItem::ValueType::IntegerNumber){
						s32 t_port = this->config->GetItem("port")->GetInteger();
						if(t_port > 0){
							this->http->SetPort(t_port);
						}
					}else{
						return nullptr;
					}
				}else{
					return nullptr;
				}

				if(this->config->IsExistItem("url") == true){
					if(this->config->GetItem("url")->GetValueType() == JsonItem::ValueType::StringData){
						STLString t_url = *this->config->GetItem("url")->GetStringData();
						if(t_url.length() > 0){
							this->http->SetUrl(t_url);
						}
					}else{
						return nullptr;
					}
				}else{
					return nullptr;
				}
			}
			
			//コンテンツ作成。
			{
				int t_list_max = -1;
				{
					if(this->config->IsExistItem("contents") == true){
						if(this->config->GetItem("contents")->GetValueType() == JsonItem::ValueType::AssociativeArray){
							t_list_max = this->config->GetItem("contents")->GetListMax();
						}else{
							return nullptr;
						}
					}else{
						return nullptr;
					}
				}

				for(int ii=0;ii<t_list_max;ii++){
					sharedptr< JsonItem > t_content_item = this->config->GetItem("contents")->GetItem(ii);

					STLString t_type_string;

					if(this->config->IsExistItem("type") == true){
						if(this->config->GetItem("type")->GetValueType() == JsonItem::ValueType::StringData){
							t_type_string = this->config->GetItem("type")->GetStringData();
						}else{
							return nullptr;
						}
					}else{
						return nullptr;
					}

					if(t_type_string == "binary"){

						STLWString t_path;
						STLString t_formname;
						STLString t_filename;

						if(t_content_item->IsExistItem("path") == true){
							if(t_content_item->GetValueType() == JsonItem::ValueType::StringData){
								CharToWchar(*t_content_item->GetItem("path")->GetStringData(),t_path);
								if(t_path.length() <= 0){
									return nullptr;
								}
							}else{
								return nullptr;
							}
						}else{
							return nullptr;
						}

						if(t_content_item->IsExistItem("formname") == true){
							if(t_content_item->GetValueType() == JsonItem::ValueType::StringData){
								t_formname = t_content_item->GetItem("formname")->GetStringData();
								if(t_formname.length() <= 0){
									return nullptr;
								}
							}else{
								return nullptr;
							}
						}else{
							return nullptr;
						}

						if(t_content_item->IsExistItem("filename") == true){
							if(t_content_item->GetValueType() == JsonItem::ValueType::StringData){
								t_filename = t_content_item->GetItem("filename")->GetStringData();
								if(t_filename.length() <= 0){
									return nullptr;
								}
							}else{
								return nullptr;
							}
						}else{
							return nullptr;
						}

						//バイナリの読み込み。
						sharedptr<NBsys::NFile::File_Object> t_fileobject = this->LoaBinaryFile(t_path);

						//コンテンツの追加。
						this->http->AddPostContent(t_formname,t_filename,t_fileobject->GetLoadData(),static_cast<s32>(t_fileobject->GetLoadSize()));

					}else if(t_type_string == "param"){
						
						STLString t_formname;
						STLString t_formvalue;

						if(t_content_item->IsExistItem("formname") == true){
							if(t_content_item->GetValueType() == JsonItem::ValueType::StringData){
								t_formname = t_content_item->GetItem("formname")->GetStringData();
								if(t_formname.length() <= 0){
									return nullptr;
								}
							}else{
								return nullptr;
							}
						}else{
							return nullptr;
						}

						if(t_content_item->IsExistItem("formvalue") == true){
							if(t_content_item->GetValueType() == JsonItem::ValueType::StringData){
								t_formvalue = t_content_item->GetItem("formvalue")->GetStringData();
								if(t_formvalue.length() <= 0){
									return nullptr;
								}
							}else{
								return nullptr;
							}
						}else{
							return nullptr;
						}

						//コンテンツの追加。
						this->http->AddPostContent(t_formname,t_formvalue);

					}else{

						return nullptr;

					}
				}
			}

			return true;
		}
	};


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
			App t_app;
			if(t_app.LoadConfig() == true){
				if(t_app.CreateHttp() == true){
					
				}
			}
		}

		//通信。終了。
		NBsys::NWinsock::EndSystem();

		//終了処理。
		NBsys::NFile::EndSystemRequest();
		NBsys::NFile::EndWaitSystem();
	}
}

