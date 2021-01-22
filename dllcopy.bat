echo on
echo copy and delete
set dllCopyFrom=.\Dllx64\
set dllCopyToDebug=.\x64\Debug\
set dllCopyToRelease=.\x64\Release\
xcopy /s /Y /F %dllCopyFrom% %dllCopyToDebug%
xcopy /s /Y /F %dllCopyFrom% %dllCopyToRelease%
pause