@echo off
::设置合并后文件保存路径，如果设置的路径不存在，会自动创建
set OkDir=Z:\train\
 
::开始执行
if not exist "%OkDir%" md "%OkDir%"
set YMD=%date:~,10%
set YMD=%YMD:/=%
set YMD=%YMD:-=%
set HMS=%time:~,8%
set HMS=%HMS: =0%
set HMS=%HMS::=%
for /r %%a in (*.csv) do if /i "%%~xa"==".csv" more +1 "%%~a">>"%OkDir%\combine%HMS%.csv"
PAUSE