CALL ..\..\..\setting.bat

FOR /F %%C IN (configuration.txt) DO (
	FOR /F %%P IN (platform.txt) DO (
		@REM �r���h�B
		%MSBUILD% postconnect.vcxproj /t:rebuild /p:Configuration=%%C;Platform=%%P

		@REM �ړ��B
		move .\bin\%%P\%%C\postconnect.exe postconnect_%%P_%%C.exe
	)
)