@echo off
setlocal

:: 设置Qt的路径
set QT_PATH=D:\Soft\QT\5.14.2\msvc2017_64\bin

:: 设置输出目录
set OUTPUT_DIR=D:\test_dll\QTWidgetAndLib\out\build

:: 调用windeployqt
"%QT_PATH%\windeployqt.exe" "%OUTPUT_DIR%"

endlocal