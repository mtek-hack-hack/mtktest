/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MT6225_NVRAMStatistic/src/fs_quota_entry_dump.c,v 1.1 2007/05/17 07:24:47 bw Exp $
*
* $Id: fs_quota_entry_dump.c,v 1.1 2007/05/17 07:24:47 bw Exp $
*
* $Date: 2007/05/17 07:24:47 $
*
* $Name: 1.1 $
*
* $Locker$
*
* $Revision: 1.1 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: fs_quota_entry_dump.c,v $
* Revision 1.1  2007/05/17 07:24:47  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * fs_quota_entry_dump.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for dump the fs quota setting
 *
 * Author:
 * -------
 * JI Huang  (mtk01077)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * ~Log$
 *
 * Sep 12 2006 mtk01077
 * [MAUI_00328857] Support Java in ASM
 * 
 *
 * Jun 20 2006 mtk01077
 * [MAUI_00204021] [FS][Custom] create a small executable program to support build time check of quota
 * 
 *
 * Jun 20 2006 mtk01077
 * [MAUI_00204021] [FS][Custom] create a small executable program to support build time check of quota
 * 
 *
 * Jun 20 2006 mtk01077
 * [MAUI_00204021] [FS][Custom] create a small executable program to support build time check of quota
 * 
 *
 * Jun 19 2006 mtk01077
 * [MAUI_00204021] [FS][Custom] create a small executable program to support build time check of quota
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#ifdef __FS_QM_SUPPORT__

#include "fs_quota.c"

/***************************************************************************** 
* Define
* Aim to pass compile, dummy function or gloabl variable here
*****************************************************************************/
kal_int32 system_boot_mode;

#ifdef _STACK_LTLCOM_H
void free_int_ilm(ilm_struct *ilm_ptr, kal_char* file_name, kal_uint32 line)
{   return;
}
#endif

void kal_get_time(kal_uint32 *ticks_ptr)
{
    return;
}

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/*****************************************************************************
* FUNCTION
*  main
* DESCRIPTION
*  main function.
* PARAMETERS
*  None
* RETURNS
*  None
*****************************************************************************/
int main()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE* outputLog;
    int   i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    outputLog = fopen("..\\..\\..\\~fs_quota_usage.log","w+");
    
    fprintf(outputLog, "gFS_ExtQuotaSet[]\n");
    fprintf(outputLog, "-----------------------------------------------------------\n");

    for (i=0; gFS_ExtQuotaSet[i].Path[0] != '\0' ; i++)
    {
       fprintf(outputLog, "{ %-20s , %5d , %10d , 0x%x , 0x%x },\n",
                gFS_ExtQuotaSet[i].Path,
                gFS_ExtQuotaSet[i].Priority,
                gFS_ExtQuotaSet[i].Qmin,
                gFS_ExtQuotaSet[i].Qmax,
                gFS_ExtQuotaSet[i].Uint);
    }

    fclose(outputLog);
    return 0;
}

#else /* __FS_QM_SUPPORT__ */
int main()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE* outputLog;
    int   i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    outputLog = fopen("..\\..\\..\\~fs_quota_usage.log","w+");
    
    fprintf(outputLog, "__FS_QM_SUPPORT__ Off\n");

    fclose(outputLog);
    return 0;
}
#endif
