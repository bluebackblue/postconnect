CALL ..\..\..\setting.bat

FOR /F %%C IN (configuration.txt) DO (
	FOR /F %%P IN (platform.txt) DO (
		@REM ビルド。
		%MSBUILD% postconnect.vcxproj /t:rebuild /p:Configuration=%%C;Platform=%%P

		@REM 移動。
		move .\bin\%%P\%%C\postconnect.exe postconnect_%%P_%%C.exe
	)
)
