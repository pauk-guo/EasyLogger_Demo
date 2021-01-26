echo on
echo copy and delete
set dllCopyFrom=.\3rd\dll\
set dllCopyToDebug=.\x64\Debug\
set dllCopyToRelease=.\x64\Release\
xcopy /s /Y /F %dllCopyFrom% %dllCopyToDebug%
xcopy /s /Y /F %dllCopyFrom% %dllCopyToRelease%
pause