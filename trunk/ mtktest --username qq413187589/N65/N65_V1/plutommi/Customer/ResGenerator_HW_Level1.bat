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
set prj=
path ..\..\tools;..\..\..\tools;..\..\..\Tools\MSYS\bin;..\..\..\..\Tools\MSYS\bin;..\..\Tools\MinGW\bin;..\..\..\Tools\MinGW\bin;..\debug;.\debug;..\..\..\Tools;%path%;

echo MediaTek Inc. Resource Generator Script
echo Building resource ...
cd plutommi\Customer\ResGenerator

rem ************************************************************
rem ************** Start to Generate Resource ******************
rem ************** -Using Pixtel ResGenerator ******************
rem ************************************************************
echo Making Resources...
mtk_resgenerator.exe -g -x > mtk_resgenerator.log

rem ************************************************************
rem *** Menu Tree Tool gen resource to copy back if needed *****
rem ************************************************************
copy ..\custresource\CustMenuToolRes.c ..\custresource\CustMenuRes.c

rem ************************************************************
rem ************** Start to Generate Resource ******************
rem ******** -Generate MultiLanguage String Resource ***********
rem ************************************************************
rem ReadExcel ref_list.txt
COPY .\CustStrMap.c ..\custresource\CustStrMap.c
COPY .\CustStrRes.c ..\custresource\CustStrRes.c

rem
rem Generate the MTE image resource header file.
rem
perl mte_parse_img_usage.pl

echo --
echo Complete!!
exit
