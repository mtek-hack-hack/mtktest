@echo off
echo    1 - new
echo    2 - remake
echo    3 - plutommi
echo    4 - mtkapp
echo    5 - custom
echo    6 - remakeresource
echo    7 - media

set /p choice=Please enter your choice: 
if '%choice%'=='1' goto set_new
if '%choice%'=='2' goto set_remake
if '%choice%'=='3' goto set_remake_plutommi
if '%choice%'=='4' goto set_remake_mtkapp
if '%choice%'=='5' goto set_remake_custom
if '%choice%'=='6' goto set_remake_res
if '%choice%'=='7' goto set_remake_qq


goto done2

:set_new
call make custom=UNIRISE25_GEMINI  gprs new
goto done

:set_remake
call make custom=UNIRISE25_GEMINI  gprs remake
goto done

:set_remake_plutommi
call make custom=UNIRISE25_GEMINI  gprs remake plutommi
goto done

:set_remake_mtkapp
call make custom=UNIRISE25_GEMINI  gprs remake drv
goto done

:set_remake_custom
call make custom=UNIRISE25_GEMINI  gprs r custom 
goto done

:set_remake_res
cd plutommi\Customer
call remakeresource
cd ..
cd ..
goto done2

:set_remake_qq
call make custom=UNIRISE25_GEMINI  gprs remake media
goto done

:done
rem copy .\build\SKYWORTH25_06B\SKYWORTH25_06B_PCB01_gprs_MT6225_S00.MAUI_06B_W07_12.bin  D:\MyDocuments\work\FlashTool_v2.6.1014\download.bin /B /V /Y

:done2
