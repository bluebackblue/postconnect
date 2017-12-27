# brownie library
C++ library

## license
MIT License
https://github.com/bluebackblue/brownie/blob/master/LICENSE.txt

## coverity scan
<a href="https://scan.coverity.com/projects/brownie">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/14637/badge.svg"/>
</a>

## auto test
自動テスト
* http://bbbproject.sakura.ne.jp/www/project_autotest/

## blib
low-level library
* https://github.com/bluebackblue/brownie/wiki/blib

## bsys
mid-level library
* https://github.com/bluebackblue/brownie/wiki/bsys

## folder structure
フォルダ構造
* brownie 「チェックアウト : https://github.com/bluebackblue/brownie」
* _ license [使用ライセンス関連ファイル]
* _ premake [ビルドツール]
* _ source
* ___ blib [低レベルライブラリ]
* ___ bsys [中レベルライブラリ]
* ___ premake.bat
* ___ project_test [テストプロジェクト]
* _____ brownie_config
* _______ brownie_config.h 「テストプロジェクト用の定義デフォルト値と説明」
* _______ user_customize.h 「テストプロジェクト用の定義カスタマイズ」
* _______ test.h 「自動テスト制御用定義」
* ___ configuration.txt 「自動テスト制御ファイル」
* ___ platform.txt 「自動テスト制御ファイル」
* ___ testdefine.txt 「自動テスト制御ファイル」
* ___ auto_test.bat 「自動テスト開始バッチ」
* sdk [blib/bsys内で使用するミドルウェアの設置場所(このリポジトリには含まれていません)]

## include path
インクルードパス
* ./brownie/source/project_test
* ./sdk
* ./sdk_32
* ./sdk_64

## link path
リンクパス
* ./sdk
* ./sdk_32
* ./sdk_64

## test project
テストプロジェクト起動までの手順
* step 1: RUN  ./brownie/source/premake.bat
* step 2: OPEN ./brownie/source/brownie.sln
* step 3: EDIT ./brownie/source/project_test/brownie_config/test.h

## brownie_config.h
テストプロジェクト用の定義デフォルト値と説明
* https://github.com/bluebackblue/brownie/blob/master/source/project_test/brownie_config/brownie_config.h

## user_customize.h
テストプロジェクト用の定義カスタマイズ
* https://github.com/bluebackblue/brownie/blob/master/source/project_test/brownie_config/user_customize.h

## test.h
自動テスト制御用定義
* https://github.com/bluebackblue/brownie/blob/master/source/project_test/brownie_config/test.h
* DEF_TEST_AUTO (1) 自動テストを実行します。
* DEF_TEST_INDEX (0) テスト番号を設定します。


