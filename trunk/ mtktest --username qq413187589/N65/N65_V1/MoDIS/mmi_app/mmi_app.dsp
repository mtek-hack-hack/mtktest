# Microsoft Developer Studio Project File - Name="mmi_app" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=mmi_app - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mmi_app.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mmi_app.mak" CFG="mmi_app - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mmi_app - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "mmi_app - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mmi_app - Win32 Release"
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /W2 /Od /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" 
# ADD CPP @"mmi_app.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "$(CFG)" == "mmi_app - Win32 Debug"
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /W2 /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" 
# ADD CPP @"mmi_app.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "_DEBUG"
# ADD RSC /l 0x404 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ENDIF
# Begin Target
# Name "mmi_app - Win32 Release"
# Name "mmi_app - Win32 Debug"
# Begin Source File 
SOURCE=..\..\plutommi\mmi\analogtvapp\analogtvappsrc\analogtvapp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\asyncevents\asynceventssrc\hardwareeventhandler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\asyncevents\asynceventssrc\protocoleventhandler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\athandler\athandlersrc\athandler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\callmanagement\commonfiles\commonsrc\autoredialattempt.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\callmanagement\commonfiles\commonsrc\callstructuremanagement.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\callmanagement\commonfiles\commonsrc\cmerrorhandlers.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\callmanagement\commonfiles\commonsrc\commonstubs.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\callmanagement\commonfiles\commonsrc\historyhelper.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\callmanagement\commonfiles\commonsrc\mapstructure2mmi.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\callmanagement\commonfiles\commonsrc\pscallhelper.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\callmanagement\incomingcallmanagement\incomingsrc\callmanagementincoming.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\callmanagement\outgoingcallmanagement\outgoingsrc\outgoingcallhelper.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\callmanagement\outgoingcallmanagement\outgoingsrc\outgoingcallmanagement.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\callmanagement\outgoingcallmanagement\outgoingsrc\textphonecontrol.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\calls\callssrc\callhistorypin2.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\calls\callssrc\calllog.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\calls\callssrc\callscost.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\calls\callssrc\callshistorymain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\calls\callssrc\callsreset.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\calls\callssrc\callssmscounter.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\calls\callssrc\calltimes.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\chatapp\chatappsrc\chatapp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\chatapp\chatappsrc\chatappguiinterface.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\chatapp\chatappsrc\chatappsendmsg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\cphs\cphssrc\cphsprotocolhandlers.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\cphs\cphssrc\csp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\cphs\cphssrc\infonum.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\customerservice\customerservicesrc\custserviceappmain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\datetime\datetimesrc\datetime.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\dictionary\dictsrc\dictionarymain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\ebookreader\ebooksrc\ebookframework.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\ebookreader\ebooksrc\ebooksrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\extra\extrasrc\bmi.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\extra\extrasrc\calculator.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\extra\extrasrc\calorie.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\extra\extrasrc\currencyconvertor.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\extra\extrasrc\currencyconvertore.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\extra\extrasrc\extra.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\extra\extrasrc\healthmenstural.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\extra\extrasrc\shortcuts.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\extra\extrasrc\stopwatchmultipurpose.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\extra\extrasrc\stopwatchtypical.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\extra\extrasrc\unitconvertor.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gpio\gpiosrc\generaldeviceinterface.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gpio\gpiosrc\volumehandler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gsmcallapplication\commonfiles\commonsrc\autoredialattemptex.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gsmcallapplication\commonfiles\commonsrc\callstructuremanagementex.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gsmcallapplication\commonfiles\commonsrc\cmerrorhandlersex.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gsmcallapplication\commonfiles\commonsrc\commonstubsex.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gsmcallapplication\commonfiles\commonsrc\historyhelperex.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gsmcallapplication\commonfiles\commonsrc\mapstructure2mmiex.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gsmcallapplication\commonfiles\commonsrc\pscallhelperex.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gsmcallapplication\incomingcallmanagement\incomingsrc\callmanagementincomingex.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gsmcallapplication\outgoingcallmanagement\outgoingsrc\outgoingcallhelperex.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gsmcallapplication\outgoingcallmanagement\outgoingsrc\outgoingcallmanagementex.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\gsmcallapplication\outgoingcallmanagement\outgoingsrc\textphonecontrolex.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\help\helpsrc\help.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\idlescreen\idlescreensrc\idleapp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\idlescreen\idlescreensrc\idledialpad.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\idlescreen\idlescreensrc\idlescreensaver.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\idlescreen\idlescreensrc\miscfunctions.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\idlescreen\idlescreensrc\spdi.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\mainmenu\mainmenusrc\mainmenu.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\messages\messagessrc\cellbroadcast.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\messages\messagessrc\emsmiscell.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\messages\messagessrc\messagesmiscell.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\messages\messagessrc\smsmomtguiinterface.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\messages\messagessrc\smspshandler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\messages\messagessrc\smssettingsguiinterface.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\mobileservice\mobileservicesrc\mobileserviceappmain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\nitzhandler\nitzsource\nitz.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\organizer\organizersrc\alarm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\organizer\organizersrc\alarmframework.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\organizer\organizersrc\calendar.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\organizer\organizersrc\organizer.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\organizer\organizersrc\todolist.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\organizer\organizersrc\todolistdb.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\organizer\organizersrc\worldclock.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\phonebook\phonebooksrc\phonebookcallergroups.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\phonebook\phonebooksrc\phonebookextranumber.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\phonebook\phonebooksrc\phonebookjavahandler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\phonebook\phonebooksrc\phonebookmain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\phonebook\phonebooksrc\phonebookoperatemass.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\phonebook\phonebooksrc\phonebookoperatesingle.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\phonebook\phonebooksrc\phonebooksearch.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\phonebook\phonebooksrc\phonebooksettings.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\phonebook\phonebooksrc\phonebookstubstoothers.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\profiles\profilessrc\settingprof.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\profiles\profilessrc\settingscreenprof.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\sat\satsrc\mexe.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\sat\satsrc\sat.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\sat\satsrc\service.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\sat\satsrc\simrefresh.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\barreddiallist.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\callbarring.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\callerid.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\callfixeddiallist.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\callforwarding.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\callwaiting.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\dateandtime.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\flightmode.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\grouplist.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\lineswitching.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\managecallmain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\mmi_phnset_dispchar.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\networksetup.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\networksetupdualmode.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\phnsetgpio.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\phonesetup.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\poweronoffdisplay.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\preferedinputmethodsetting.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\preferredmode.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\preferrednwks.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\prefnwksstubfromothers.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\restore.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\scheduledpoweronoff.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\screensaver.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\securitysetup.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\settingsrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\soundeffect.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\speeddial.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\userctrlplmn.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\setting\settingsrc\wallpaper.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\sfapi\src\sfapi.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\smartmessage\smartmessagesrc\cli_icon.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\smartmessage\smartmessagesrc\commonnsm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\smartmessage\smartmessagesrc\mypicture.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\smartmessage\smartmessagesrc\mytone.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\smartmessage\smartmessagesrc\operator_logo.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\smartmessage\smartmessagesrc\picturemsg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\smartmessage\smartmessagesrc\smrtringtoneconverter.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\ssc\sscsrc\sscstringhandle.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\ucm\ucmsrc\ucmacthdlr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\ucm\ucmsrc\ucminterface.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\ucm\ucmsrc\ucmmain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\ucm\ucmsrc\ucmsetting.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\ucm\ucmsrc\ucmui.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\ucm\ucmsrc\ucmutil.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\unifiedcomposer\unifiedcomposersrc\unifiedcomposermain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\unifiedcomposer\unifiedcomposersrc\unifiedcomposermiscell.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\unifiedcomposer\unifiedcomposersrc\unifiedcomposermsg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\unifiedmessage\unifiedmessagesrc\unifiedmessagemain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\unifiedmessage\unifiedmessagesrc\unifiedmessagemiscell.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\unifiedmessage\unifiedmessagesrc\unifiedmessagemsg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\unifiedmessage\unifiedmessagesrc\unifiedmessageuiinterface.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\unifiedmms\mmscommon\mmscommonsrc\mmsmemory.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\unifiedmms\mmscommon\mmscommonsrc\mmsmessagedispatch.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\unifiedmms\mmscommon\mmscommonsrc\mmsxmldecoder.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\unifiedmms\mmscommon\mmscommonsrc\mmsxmlencode.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\videocall\videocallsrc\vtacthdlr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\videocall\videocallsrc\vtcallscr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\videocall\videocallsrc\vtmain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\videocall\videocallsrc\vtutil.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\voip\voipsrc\voipcall.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\voip\voipsrc\voipinterface.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\voip\voipsrc\voipmain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\voip\voipsrc\voipmsghdlr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\voip\voipsrc\voipotapdmp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\voip\voipsrc\voipsetting.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\voip\voipsrc\voipsignal.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\voip\voipsrc\voiputil.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mmi\voip\voipsrc\voipvoice.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\devicemanagement\devicemanagementsrc\devicemanagement.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\engineermode\engineermodesrc\engineermodedevicesrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\engineermode\engineermodesrc\engineermodedummysrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\engineermode\engineermodesrc\engineermodemsghandler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\engineermode\engineermodesrc\engineermodeprofiling.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\engineermode\engineermodesrc\engineermodesocketapp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\engineermode\engineermodesrc\engineermodesocketdemoapp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\engineermode\engineermodesrc\engineermodesrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\engineermode\engineermodesrc\engineermodetracer.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\engineermode\engineermodesrc\factorymodemsgsrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\engineermode\engineermodesrc\factorymodesrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\filemgr\filemgrsrc\filemanagersrc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\filemgr\filemgrsrc\filemgr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\filemgr\filemgrsrc\filemgrcore.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\filemgr\filemgrsrc\filemgrui.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\filemgr\filemgrsrc\profilemgr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\myfavorite\myfavoritesrc\myfavorite.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\pictbridge\pictbridgesrc\pictbridgefiles.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\pictbridge\pictbridgesrc\pictbridgehandler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\pictbridge\pictbridgesrc\pictbridgemain.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\pictbridge\pictbridgesrc\pictbridgesettings.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\pictbridge\pictbridgesrc\pictbridgexml.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\rightsmgr\rightsmgrsrc\rightsmgr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\rightsmgr\rightsmgrsrc\rightsmgrgeninfo.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\rightsmgr\rightsmgrsrc\rightsmgrlistro.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\rightsmgr\rightsmgrsrc\rightsmgrsweep.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\rightsmgr\rightsmgrsrc\rightsmgrui.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\rightsmgr\rightsmgrsrc\rightsmgrwhitelist.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vobjects\vobjectsrc\vbookmark.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vobjects\vobjectsrc\vcalendar.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vobjects\vobjectsrc\vcard.c
# End Source File 
# Begin Source File 
SOURCE=..\..\plutommi\mtkapp\vobjects\vobjectsrc\vobjects.c
# End Source File 

# End Target
# End Project
