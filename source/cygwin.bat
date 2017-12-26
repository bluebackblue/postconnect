CALL ..\..\..\setting.bat

SET HOME=%~dp0

%CYGWIN_DRIVE%%
chdir %CYGWIN_BIN%

bash --login -i
