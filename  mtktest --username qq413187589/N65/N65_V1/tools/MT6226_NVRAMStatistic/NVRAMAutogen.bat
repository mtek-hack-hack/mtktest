@echo off
path ..\..\tools;..\..\..\tools;..\..\..\Tools\MSYS\bin;..\..\..\..\Tools\MSYS\bin;..\..\Tools\MinGW\bin;..\..\..\Tools\MinGW\bin;..\debug;.\debug;..\..\..\Tools;%path%;
if  .%1==.  goto NVRAM_AUTO_GEN_ERROR_2:

cd Tools\NVRAMStatistic\src

rem ************************************************************
rem ************* Start to Generate NVRAM Info *****************
rem ************************************************************
echo Generate NVRAM Information...

echo Delete *.o
if exist ..\debug\nvram_auto_gen.o del ..\debug\nvram_auto_gen.o
if exist ..\debug\nvram_data_items.o del ..\debug\nvram_data_items.o
if exist ..\debug\nvram_common_config.o del ..\debug\nvram_common_config.o
if exist ..\debug\nvram_user_config.o del ..\debug\nvram_user_config.o

echo Delete ..\..\..\build\%1\log\nvram_gen.log
if exist ..\..\..\build\%1\log\nvram_gen.log del ..\..\..\build\%1\log\nvram_gen.log
echo Make nvram_auto_gen.exe
..\..\MSYS\bin\make nvram_auto_gen.exe 2> ..\..\..\build\%1\log\nvram_gen.log
if not exist ..\debug\nvram_auto_gen.exe goto NVRAM_AUTO_GEN_ERROR_1:
nvram_auto_gen.exe

rem ************************************************************
rem ************* Start to Generate FS QUOTA   *****************
rem ************************************************************
echo Generate FS Quota Entry Information...

echo Delete *.o
if exist ..\debug\fs_quota_entry_dump.o del ..\debug\fs_quota_entry_dump.o

echo Delete ..\..\..\build\%1\log\fs_quota_entry_dump.log
if exist ..\..\..\build\%1\log\fs_quota_entry_dump.log del ..\..\..\build\%1\log\fs_quota_entry_dump.log
echo Make fs_quota_entry_dump.exe
..\..\MSYS\bin\make fs_quota_entry_dump.exe 2> ..\..\..\build\%1\log\fs_quota_entry_dump.log
if not exist ..\debug\fs_quota_entry_dump.exe goto FS_QUOTA_GEN_ERROR_1:
fs_quota_entry_dump.exe

rem ************************************************************
rem ************* Both Procedure finished      *****************
rem ************************************************************
cd ..\..\..\

echo --
echo Complete!!
goto done

rem ************************************************************
rem ************** Error Handling and Messages *****************
rem ************************************************************
:NVRAM_AUTO_GEN_ERROR_1
cd ..\..\..\
:NVRAM_AUTO_GEN_ERROR_2
echo Error in NVRAM Generating Process!!
echo Please Check nvram_gen.log!!
type .\build\%1\log\nvram_gen.log
exit 3

:FS_QUOTA_GEN_ERROR_1
cd ..\..\..\
echo Error in FS_QUOTA Generating Process!!
echo Please Check fs_quota_entry_dump.log!!
type .\build\%1\log\fs_quota_entry_dump.log
exit 3

:done
