/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
#include "ddload.h"

typedef struct{
   int        Dsp_Start_Addr;
   const char *Array_Addr;
   int        Array_Len;
}DLL_Func;

extern const DLL_Func	dll_DAF;
extern const DLL_Func	dll_VR_NR;
extern const DLL_Func	dll_WT;
extern const DLL_Func	dll_AMR;
extern const DLL_Func	dll_AAC;
extern const DLL_Func	dll_AAC_PLUS;
extern const DLL_Func	dll_Header_Kernal;
extern const DLL_Func	dll_Audio_Header;
extern const DLL_Func	dll_AWB;
extern const DLL_Func	dll_TCH;
extern const DLL_Func	dll_VR;
extern const DLL_Func dll_AWB_PLUS;
extern const DLL_Func	pmdll_DAF;
extern const DLL_Func	pmdll_AAC;
extern const DLL_Func	pmdll_AWB;
extern const DLL_Func pmdll_AWB_PLUS;

#if DPCHIP_DDL_WMA_V2
extern const DLL_Func	dll_WMA_16OB_HighRate;
extern const DLL_Func	dll_WMA_16OB_LowRate;
extern const DLL_Func	dll_WMA_44OB;
extern const DLL_Func	dll_WMA_44QB_HighRate;
extern const DLL_Func	dll_WMA_44QB_LowRate;
extern const DLL_Func	pmdll_WMA_16OB;
extern const DLL_Func	pmdll_WMA_44OB;
extern const DLL_Func	pmdll_WMA_44QB;
extern const DLL_Func	pmdll_WMA_44OB_2;
#elif DPCHIP_DDL_WMA_V1
extern const DLL_Func	dll_WMA;
extern const DLL_Func	pmdll_WMA;
extern const DLL_Func	dll_WMA_48k;
extern const DLL_Func	pmdll_WMA_48k;
#endif

extern const DLL_Func	pmdll_SBC;
extern const DLL_Func	pmdll_WT;
extern const DLL_Func	pmdll_AECS;
extern const DLL_Func	pmdll_DAF;
extern const DLL_Func	dll_AMRSBC;
extern const DLL_Func    dll_AAC_PLUS_PS;
extern const DLL_Func    pmdll_AAC_PLUS_PS;
extern const DLL_Func     dll_AWBDEC;
extern const DLL_Func   dll_MUSICAM;
extern const DLL_Func   pmdll_MUSICAM;
extern const DLL_Func   pmdll_SBC;
extern const DLL_Func   dll_BSAC;
extern const DLL_Func   pmdll_BSAC;
