@echo off
set prj=
set customer=PLUTO
set optr_path=PPP
set optr_spec=NONE
set main_lcd_size=240X320
if %customer%==MTK set customer=PLUTO
set clean_opt=FALSE
set remake_opt=FALSE
set copy_opt=FALSE
set remake_plmn=FALSE
set choice=1
path ..\..\tools;..\..\..\tools;..\..\..\Tools\MSYS\bin;..\..\..\..\Tools\MSYS\bin;..\..\Tools\MinGW\bin;..\..\..\Tools\MinGW\bin;..\debug;.\debug;..\..\..\Tools;%path%;
if  not .%1==.  goto set_prj
goto menu

:set_prj
set prj=%1%
rem if not exist .\CustResource\%prj%_MMI\MMI_features_switch%prj%.h goto prj_error
if not exist .\CustResource\%customer%_MMI\MMI_features_switch%customer%.h goto prj_error
goto option

rem ************************************************************
rem ***************** Clean .o and .exe ************************
rem ************************************************************
:clean
if %clean_opt%==FALSE goto a
cd ResGenerator
rem del ..\Res_MMI\*.c
del *.o
del mtk_resgenerator.exe
cd ..

:a
if %remake_opt%==FALSE goto done
cd ResGenerator
echo MediaTek Inc. Resource Generator Script
echo Building resource for %customer%...

rem ************************************************************
rem ****************** Backup Old Resource *********************
rem ************************************************************
echo copying old Resources...
del /Y ..\custresource\BackupRes\*
mkdir ..\custresource\BackUpRes
copy ..\custresource\*.c ..\custresource\BackUpRes\.

rem ************************************************************
rem *************** Copy PLUTO Project BASE Files FIRST ********
rem ************************************************************
if not exist ..\Res_MMI\ md ..\Res_MMI\
copy ..\custresource\PLUTO_MMI\Res_MMI\*.c ..\Res_MMI\.

rem ************************************************************
rem *************** Copy Project Related Files *****************
rem ************************************************************
rem copy ..\custresource\%prj%_MMI\*.* ..\custresource\.
copy ..\custresource\%prj%_MMI\Res_MMI\*.c ..\Res_MMI\.

rem ************************************************************
rem *************** Copy MMI_features_switch.h *****************
rem ************************************************************
if %copy_opt%==FALSE goto b
copy ..\custresource\%customer%_MMI\MMI_features_switch%customer%.h ..\..\MMI\Inc\MMI_features_switch.h

:b

rem ************************************************************
rem *************** Run ResGenerator_OP.bat ********************
rem ************************************************************
if %optr_spec%==NONE goto skip_optr
call ..\..\..\%optr_path%\ResGenerator_OP.bat %optr_spec% %main_lcd_size%
:skip_optr

rem ************************************************************
rem ************** Start to Generate Resource ******************
rem ************** -Using Pixtel ResGenerator ******************
rem ************************************************************
del .\debug\*.obj

rem del .\mtk_resgenerator.exe

echo Making Resources...

if %remake_plmn%==FALSE goto skip_plmn
COPY ..\custresource\%prj%_MMI\ref_list.txt ..\custresource\ref_list.txt
COPY ..\custresource\PLUTO_MMI\plmnlist.txt ..\custresource\plmnlist.txt
COPY ..\custresource\PLUTO_MMI\PlmnEnum.tmp ..\..\MMI\MiscFramework\MiscFrameworkInc\PlmnEnum.h
COPY ..\custresource\PLUTO_MMI\PlmnName.tmp ..\..\MMI\MiscFramework\MiscFrameworkSrc\PlmnName.c
make plmncreate.exe
if not exist plmncreate.exe goto RESGEN_ERROR
plmncreate.exe
:skip_plmn

copy ..\Customize\mmicustomizer.lib .\mmicustomizer.lib
reimp mmicustomizer.lib

rem del Res_*.o
rem del FontRes.o
rem del PopulateRes.o

make mtk_resgenerator.exe
if not exist mtk_resgenerator.exe goto RESGEN_ERROR
rem ************************************************************
rem **********  Copy obj files for vendor app  *****************
rem ************************************************************
COPY bmp2ems.o ..\..\VendorApp\ResGenerator\obj\
COPY bmpLoader.o ..\..\VendorApp\ResGenerator\obj\
COPY GifLoader.o ..\..\VendorApp\ResGenerator\obj\
COPY ResBytestream.o ..\..\VendorApp\ResGenerator\obj\
COPY UCS2.o ..\..\VendorApp\ResGenerator\obj\
COPY ImageGetDimension.o ..\..\VendorApp\ResGenerator\obj\
rem // __CUSTPACK_MULTIBIN Calvin BEGIN
mtk_resgenerator.exe -g > mtk_resgenerator.log
rem // __CUSTPACK_MULTIBIN Calvin END

rem ************************************************************
rem *** Menu Tree Tool gen resource to copy back if needed *****
rem ************************************************************
copy ..\custresource\CustMenuToolRes.c ..\custresource\CustMenuRes.c

rem ************************************************************
rem ************** Start to Generate Resource ******************
rem ************************************************************

COPY FontRes.o ..\..\VendorApp\ResGenerator\obj\
COPY .\CustStrMap.c ..\custresource\%prj%_MMI\CustStrMap.c
COPY .\CustStrRes.c ..\custresource\%prj%_MMI\CustStrRes.c
COPY .\CustStrMap.c ..\custresource\CustStrMap.c
COPY .\CustStrRes.c ..\custresource\CustStrRes.c
echo clear intermediate files...

copy ..\custresource\CustENFBImgData ..\..\..\MoDIS\MoDis\CustENFBImgData
copy ..\custresource\CustENFBStrData ..\..\..\MoDIS\MoDis\CustENFBStrData

if exist ..\Res_MMI\ rd /S/Q ..\Res_MMI\
rem del .\Res*.o
rem del .\PopulateRes.o

del .\mmicustomizer.lib
echo Resource generated successfully...

rem
rem Generate the MTE image resource header file.
rem
perl mte_parse_img_usage.pl

echo --
echo Complete!!
goto done

rem ************************************************************
rem ************** Error Handling and Messages *****************
rem ************************************************************
:RESGEN_ERROR
echo Error in ResGenerating Process!!
echo Please Check again!!
exit /B 3

rem ************************************************************
rem **************** Menu To Select Project ********************
rem ************************************************************
:menu
@echo off
rem cls
rem echo MediaTek Resource Generator
rem echo. 
rem echo Please select one project to generate resource...
rem echo.
rem echo    SELECT MENU
rem echo    ==========
rem echo.
rem echo    1 - PLUTO
rem echo.
rem echo    Q - Quit
rem choice /C:1Q>nul

rem if errorlevel 23 goto done
rem if errorlevel 1 goto PLUTO:
goto PLUTO:

goto done


:PLUTO
set prj=PLUTO
goto option:


rem ************************************************************
rem **************** Menu To Select Action ********************
rem ************************************************************
:option
@echo off
set opt=
cls
echo MediaTek Resource Generator
echo. 
echo Please select one action to perform...
echo.
echo    SELECT MENU
echo    ==========
echo.
echo    1 - Remake
echo    2 - Clean then remake
echo    3 - Clean
echo    4 - Copy MMI_features_switch%customer%.h, clean, then remake
echo    5 - Plmncreate, copy MMI_features_switch%customer%.h, clean, then remake
echo.
echo    Q - Quit
rem choice /C:123Q>nul
rem if errorlevel 4 goto done:
rem if errorlevel 3 goto set_clean:
rem if errorlevel 2 goto set_clean_remake:
rem if errorlevel 1 goto set_remake:

set /p choice=Please enter your choice: 
if '%choice%'=='1' goto set_remake
if '%choice%'=='2' goto set_clean_remake
if '%choice%'=='3' goto set_clean
if '%choice%'=='4' goto set_copy_clean_remake
if '%choice%'=='5' goto set_plmn_copy_clean_remake
if '%choice%'=='q' goto done
if '%choice%'=='Q' goto done

goto done

:set_remake
set remake_opt=TRUE
goto clean
:set_clean_remake
set clean_opt=TRUE
set remake_opt=TRUE
goto clean
:set_clean
set clean_opt=TRUE
goto clean
:set_copy_clean_remake
set clean_opt=TRUE
set remake_opt=TRUE
set copy_opt=TRUE
goto clean
:set_plmn_copy_clean_remake
set clean_opt=TRUE
set remake_opt=TRUE
set copy_opt=TRUE
set remake_plmn=TRUE
goto clean

:prj_error
echo Error!!
echo Project %prj% does not exist!!

:done
cd ..
