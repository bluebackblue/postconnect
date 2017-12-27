

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

		/** 受信バッファ。
		*/
		sharedptr<RingBufferBase<u8>> recvbuffer;

	public:

		/** バイナリの読み込み。
		*/
		sharedptr<NBsys::NFile::File_Object> LoaBinaryFile(const STLWString& a_filename)
		{
			std::cout << "open : " << WcharToChar(a_filename) << std::endl;

			//読み込み開始。
			sharedptr<NBsys::NFile::File_Object> t_fileobject;
			t_fileobject.reset(new NBsys::NFile::File_Object(0,a_filename,-1,nullptr,0));

			//読み込み中。
			while(t_fileobject->IsBusy() == true){
				ThreadSleep(100);
			}

			if(t_fileobject->GetErrorCode() == ErrorCode::Success){
				return t_fileobject;
			}else{
				std::cout << "error : " << WcharToChar(a_filename) << std::endl;
			}

			return nullptr;
		}

		/** ＪＳＯＮファイルの読み込み。
		*/
		sharedptr<JsonItem> LoadJsonFile(const STLWString& a_filename)
		{
			std::cout << "open : " << WcharToChar(a_filename) << std::endl;

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

				//ＪＳＯＮ解析。
				if(t_fileobject->GetLoadSize() > 0){
					return sharedptr<JsonItem>(new JsonItem(reinterpret_cast<char*>(t_fileobject->GetLoadData().get())));
				}

			}else{
				std::cout << "error : " << WcharToChar(a_filename) << std::endl;
			}

			return nullptr;
		}


		/** コンフィグの読み込み。
		*/
		bool LoadConfig()
		{
			this->app_argument = GetEntryParamReference().argument;

			this->filename_config = L"";

			//ファイル名解析。
			if(this->app_argument){
				if(this->app_argument->IsExistItem("-input") == true){
					if(this->app_argument->GetItem("-input")->GetValueType() == JsonItem::ValueType::StringData){
						this->filename_config = CharToWchar(*this->app_argument->GetItem("-input")->GetStringData().get());
					}
				}
			}

			if(this->filename_config.length() > 0){
				std::cout << "input : " << WcharToChar(this->filename_config) << std::endl;
			}else{
				std::cout << "error : input" << std::endl;
				return false;
			}

			//ＪＳＯＮファイルの読み込み。
			this->config = this->LoadJsonFile(this->filename_config);
			if(this->config){
				return true;
			}
			return false;
		}


		/** ホスト設定。
		*/
		bool SetHostFromConfig()
		{
			if(this->config){
				if(this->config->IsExistItem("host") == true){
					if(this->config->GetItem("host")->GetValueType() == JsonItem::ValueType::StringData){
						STLString t_host = *this->config->GetItem("host")->GetStringData();
						if(t_host.length() > 0){
							std::cout << "host : " << t_host << std::endl;
							this->http->SetHost(t_host);
							return true;
						}
					}
				}
			}

			std::cout << "error : host" << std::endl;
			return false;
		}


		/** ポート設定。
		*/
		bool SetPortFromConfig()
		{
			if(this->config){
				if(this->config->IsExistItem("port") == true){
					if(this->config->GetItem("port")->GetValueType() == JsonItem::ValueType::IntegerNumber){
						s32 t_port = this->config->GetItem("port")->GetInteger();
						if(t_port > 0){
							std::cout << "port : " << t_port << std::endl;
							this->http->SetPort(t_port);
							return true;
						}
					}
				}
			}

			std::cout << "error : port" << std::endl;
			return false;
		}


		/** ＵＲＬ設定。
		*/
		bool SetUrlFromConfig()
		{
			if(this->config){
				if(this->config->IsExistItem("url") == true){
					if(this->config->GetItem("url")->GetValueType() == JsonItem::ValueType::StringData){
						STLString t_url = *this->config->GetItem("url")->GetStringData();
						if(t_url.length() > 0){
							std::cout << "url : " << t_url << std::endl;
							this->http->SetUrl(t_url);
							return true;
						}
					}
				}
			}

			std::cout << "error : url" << std::endl;
			return false;
		}


		/** アプトプット取得。
		*/
		STLWString GetOutPutFromConfig()
		{
			if(this->config){
				if(this->config->GetValueType() == JsonItem::ValueType::AssociativeArray){
					if(this->config->IsExistItem("output") == true){
						if(this->config->GetItem("output")->GetValueType() == JsonItem::ValueType::StringData){
							STLWString t_output_filename;
							CharToWchar(*this->config->GetItem("output")->GetStringData(),t_output_filename);
							if(t_output_filename.length() > 0){
								std::cout << "output : " << WcharToChar(t_output_filename) << std::endl;
								return t_output_filename;
							}
						}
					}
				}
			}

			std::cout << "error : output" << std::endl;
			return L"";
		}


		/** コンテンツ数取得。
		*/
		s32 GetContentsMax()
		{
			int t_list_max = -1;
			{
				if(this->config->IsExistItem("contents") == true){
					if(this->config->GetItem("contents")->GetValueType() == JsonItem::ValueType::IndexArray){
						t_list_max = this->config->GetItem("contents")->GetListMax();
						if(t_list_max >= 0){
							std::cout << "contents : " << t_list_max << std::endl;
							return t_list_max;
						}
					}
				}
			}

			std::cout << "error : contents" << std::endl;
			return -1;
		}


		/** タイプ文字取得。
		*/
		STLString GetTypeStringFromContentsItem(const sharedptr<JsonItem>& a_jsonitem)
		{
			if(a_jsonitem){
				if(a_jsonitem->GetValueType() == JsonItem::ValueType::AssociativeArray){
					if(a_jsonitem->IsExistItem("type") == true){
						if(a_jsonitem->GetItem("type")->GetValueType() == JsonItem::ValueType::StringData){
							STLString t_type_string = *a_jsonitem->GetItem("type")->GetStringData();
							if(t_type_string.length() > 0){
								std::cout << "type : " << t_type_string << std::endl;
								return t_type_string;
							}
						}
					}
				}
			}

			std::cout << "error : type" << std::endl;
			return "";
		}


		/** パス取得。
		*/
		STLWString GetPathFromContentsItem(const sharedptr<JsonItem>& a_jsonitem)
		{
			if(a_jsonitem){
				if(a_jsonitem->GetValueType() == JsonItem::ValueType::AssociativeArray){
					if(a_jsonitem->IsExistItem("path") == true){
						if(a_jsonitem->GetItem("path")->GetValueType() == JsonItem::ValueType::StringData){
							STLWString t_path;
							CharToWchar(*a_jsonitem->GetItem("path")->GetStringData(),t_path);
							if(t_path.length() > 0){
								std::cout << "path : " << WcharToChar(t_path) << std::endl;
								return t_path;
							}
						}
					}
				}
			}

			std::cout << "error : path" << std::endl;
			return L"";
		}


		/** 名前取得。
		*/
		STLString GetNameFromContentsItem(const sharedptr<JsonItem>& a_jsonitem)
		{
			if(a_jsonitem){
				if(a_jsonitem->GetValueType() == JsonItem::ValueType::AssociativeArray){
					if(a_jsonitem->IsExistItem("name") == true){
						if(a_jsonitem->GetItem("name")->GetValueType() == JsonItem::ValueType::StringData){
							STLString t_name = *a_jsonitem->GetItem("name")->GetStringData();
							if(t_name.length() > 0){
								std::cout << "name : " << t_name << std::endl;
								return t_name;
							}
						}
					}
				}
			}

			std::cout << "error : name" << std::endl;
			return "";
		}


		/** 値取得。
		*/
		STLString GetValueFromContentsItem(const sharedptr<JsonItem>& a_jsonitem)
		{
			if(a_jsonitem){
				if(a_jsonitem->GetValueType() == JsonItem::ValueType::AssociativeArray){
					if(a_jsonitem->IsExistItem("value") == true){
						if(a_jsonitem->GetItem("value")->GetValueType() == JsonItem::ValueType::StringData){
							STLString t_value = *a_jsonitem->GetItem("value")->GetStringData();
							if(t_value.length() > 0){
								std::cout << "value : " << t_value << std::endl;
								return t_value;
							}
						}
					}
				}
			}

			std::cout << "error : value" << std::endl;
			return "";
		}


		/** ファイル名取得。
		*/
		STLString GetFileNameFromContentsItem(const sharedptr<JsonItem>& a_jsonitem)
		{
			if(a_jsonitem){
				if(a_jsonitem->GetValueType() == JsonItem::ValueType::AssociativeArray){
					if(a_jsonitem->IsExistItem("filename") == true){
						if(a_jsonitem->GetItem("filename")->GetValueType() == JsonItem::ValueType::StringData){
							STLString t_filename = *a_jsonitem->GetItem("filename")->GetStringData();
							if(t_filename.length() > 0){
								std::cout << "filename : " << t_filename << std::endl;
								return t_filename;
							}
						}
					}
				}
			}

			std::cout << "error : filename" << std::endl;
			return nullptr;
		}


		/** ＨＴＴＰ作成。
		*/
		bool CreateHttp()
		{
			this->http.reset(new NBsys::NHttp::Http());
			
			if(this->config){

				//モード設定。
				this->http->SetMode(NBsys::NHttp::Http_Mode::Post);

				//ホスト設定。
				this->SetHostFromConfig();

				//ポート設定。
				this->SetPortFromConfig();

				//ＵＲＬ設定。
				this->SetUrlFromConfig();
			}
			
			//コンテンツ作成。
			{
				s32 t_list_max = this->GetContentsMax();

				for(int ii=0;ii<t_list_max;ii++){
					sharedptr<JsonItem> t_content_item = this->config->GetItem("contents")->GetItem(ii);

					//タイプ文字取得。
					STLString t_type_string = this->GetTypeStringFromContentsItem(t_content_item);

					if(t_type_string == "binary"){

						//パス取得。
						STLWString t_path = this->GetPathFromContentsItem(t_content_item);
						if(t_path.length() <= 0){
							return false;
						}

						//名取得。
						STLString t_name = this->GetNameFromContentsItem(t_content_item);
						if(t_name.length() <= 0){
							return false;
						}

						//ファイル名取得。
						STLString t_filename = this->GetFileNameFromContentsItem(t_content_item);
						if(t_filename.length() <= 0){
							return false;
						}

						//バイナリの読み込み。
						sharedptr<NBsys::NFile::File_Object> t_fileobject = this->LoaBinaryFile(t_path);
						if(t_fileobject == nullptr){
							return false;
						}

						//コンテンツの追加。
						this->http->AddPostContent(t_name,t_filename,t_fileobject->GetLoadData(),static_cast<s32>(t_fileobject->GetLoadSize()));

					}else if(t_type_string == "param"){
						
						//名取得。
						STLString t_name = this->GetNameFromContentsItem(t_content_item);
						if(t_name.length() <= 0){
							return false;
						}

						//値取得。
						STLString t_value = this->GetValueFromContentsItem(t_content_item);
						if(t_value.length() <= 0){
							return false;
						}

						//コンテンツの追加。
						this->http->AddPostContent(t_name,t_value);

					}else{
						std::cout << "error : type" << std::endl;
						return nullptr;
					}
				}
			}

			return true;
		}


		/** 通信。
		*/
		bool Connect()
		{
			sharedptr<NBlib::FileHandle> t_out_file(new NBlib::FileHandle());
			{
				STLWString t_output_filename = this->GetOutPutFromConfig();
				if(t_output_filename.length() <= 0){
					return false;
				}
				
				if(t_out_file->WriteOpen(t_output_filename) == true){
					std::cout << "open : " << WcharToChar(t_output_filename) << std::endl;
				}else{
					std::cout << "error : " << WcharToChar(t_output_filename) << std::endl;
					return false;
				}
			}

			//通信開始。
			std::cout << "connect : start" << std::endl;
			this->recvbuffer.reset(new RingBuffer<u8,1*1024*1024,true>());
			this->http->ConnectStart(this->recvbuffer);

			//通信中。
			for(;;){
				bool t_ret = this->http->ConnectUpdate();
				if((t_ret == true)||(this->recvbuffer->GetUseSize() > 0)){
					if(this->http->IsRecvHeader()){
						//ヘッダー読み込み済み。
						s32 t_size = this->recvbuffer->GetContinuousUseSize();
						if(t_size > 0){
							//リングバッファの内容を書き込む。
							t_out_file->Write(this->recvbuffer->GetItemFromUseList(0),t_size,0);
							//リングバッファからデータを取得したことにする。
							this->recvbuffer->AddFree(t_size);
						}
					}
				}else{
					std::cout << "connect : statuscode : " << this->http->GetStatusCode() << std::endl;

					bool t_is_error = this->http->IsError();
					this->http->ConnectEnd();
					this->http.reset();

					if(t_is_error == true){
						std::cout << "connect : error : " << std::endl;
						return false;
					}else{
						std::cout << "connect : success" << std::endl;
						return true;
					}
				}
			}

			ASSERT(0);
			return false;
		}
	};


	/** App_Main
	*/
	void App_Main()
	{
		//バージョン。
		std::cout << "PostConnect 1.0.0" " " __DATE__  << std::endl;

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
					if(t_app.Connect() == true){
					}
				}
			}

			std::cout << "end" << std::endl;
		}

		//通信。終了。
		NBsys::NWinsock::EndSystem();

		//終了処理。
		NBsys::NFile::EndSystemRequest();
		NBsys::NFile::EndWaitSystem();
	}
}

