rem
rem  Copyright Statement:
rem  --------------------
rem  This software is protected by Copyright and the information contained
rem  herein is confidential. The software may not be copied and the information
rem  contained herein may not be used or disclosed except with the written
rem  permission of MediaTek Inc. (C) 2005
rem
rem  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
rem  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
rem  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
rem  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
rem  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
rem  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
rem  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
rem  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
rem  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
rem  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
rem  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
rem  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
rem
rem  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
rem  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
rem  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
rem  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
rem  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
rem
rem  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
rem  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
rem  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
rem  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
rem  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
rem
@echo off
if  not .%1==.  goto a:
goto menu:

:a:
echo on
xcopy ..\..\make\plutommi\%2_MMI\*.* %1\make\plutommi\%3_MMI\*.* /s
xcopy ..\..\plutommi\Customer\CustResource\%2_MMI\*.* %1\plutommi\Customer\CustResource\%3_MMI\*.* 
xcopy ..\..\plutommi\Customer\Images\%2\*.* %1\plutommi\Customer\Images\%3\*.* /s

rem ************************************************************
rem *************** Remove files we don't copy *****************
rem ************************************************************
del  %1\plutommi\Customer\CustResource\%3_MMI\Res_MMI\*.* /Q
del %1\plutommi\Customer\CustResource\%3_MMI\MMI_features_camera.h 
del %1\plutommi\Customer\CustResource\%3_MMI\MMI_features_video.h 
del %1\plutommi\Customer\CustResource\%3_MMI\resource_camera_skins.h 
del %1\plutommi\Customer\CustResource\%3_MMI\resource_camera_skins.c 
del %1\plutommi\Customer\CustResource\%3_MMI\resource_video_skins.h 
del %1\plutommi\Customer\CustResource\%3_MMI\resource_video_skins.c 
del %1\plutommi\Customer\CustResource\%3_MMI\resource_audply_skins.c 
del %1\plutommi\Customer\CustResource\%3_MMI\resource_fmradio_skins.c 
del %1\plutommi\Customer\CustResource\%3_MMI\ref_list.txt 

ren %1\plutommi\Customer\CustResource\%3_MMI\CustMiscData%2.c CustMiscData%3.c
ren %1\plutommi\Customer\CustResource\%3_MMI\CustResDef%2.h CustResDef%3.h
ren %1\plutommi\Customer\CustResource\%3_MMI\MMI_features%2.h MMI_features%3.h
ren %1\plutommi\Customer\CustResource\%3_MMI\Gui_Setting%2.h Gui_Setting%3.h
perl str_replace_at_file.pl %1\plutommi\Customer\CustResource\%3_MMI\CustResDef%3.h %2 %3

goto end:


:menu:
@echo off
echo    ---------------- Readme -----------------
echo    %0 "Parameter 1" "Parameter 2" "Parameter 3"
echo    "Parameter 1": dest folder 
echo    "Parameter 2": source MMI name (PLUTO, CHICAGO, ...etc)
echo    "Parameter 3": dest MMI name (SHANGHAI_2080, SHANGHAI_2084, ...etc)

:end: