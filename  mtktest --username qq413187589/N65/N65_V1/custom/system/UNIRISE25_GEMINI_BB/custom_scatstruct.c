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
 *   custom_scatstruct.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the scatter file dependent APIs
 *
 * Author:
 * -------
 *   system auto generator v0.05
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "kal_release.h"

#ifdef __MTK_TARGET__

extern kal_uint32 Image$$DUMMY_END$$Base;

extern kal_uint32 Image$$EXTSRAM$$ZI$$Limit;
extern kal_uint32 Image$$ROM$$Length;
extern kal_uint32 Image$$ROM2$$Length;
extern kal_uint32 Image$$ROM3$$Length;
extern kal_uint32 Image$$ROM4$$Length;
extern kal_uint32 Image$$ROM5$$Length;



/*************************************************************************
* FUNCTION
*  custom_get_MaxAvailableMemorySegment
*
* DESCRIPTION
*  Retrieve the pointer (16 Bytes aligned) and the length that unUsed memory segments
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

void custom_get_MaxAvailableMemorySegment(kal_uint32 **Return_begin_addr, kal_uint32 *Return_segment_size)
{
    kal_uint32  MaxLength;
    kal_uint32  MaxBeginAddr;
    kal_uint32  LastRegionEnd;
    kal_uint32  ThisRegionBegin;

    MaxLength = 0;

    /* Round 1 */
    ThisRegionBegin = (kal_uint32)&Image$$DUMMY_END$$Base;
    LastRegionEnd   = (kal_uint32)&Image$$EXTSRAM$$ZI$$Limit;
    LastRegionEnd   = (LastRegionEnd + 16) & 0xFFFFFFF0;
    if ((ThisRegionBegin - LastRegionEnd) > MaxLength)
    {
       MaxBeginAddr = LastRegionEnd;
       MaxLength    = ThisRegionBegin - LastRegionEnd;
    }

    
    /* Now we get the maximum segments */
    *Return_begin_addr   = (kal_uint32 *)MaxBeginAddr;
    *Return_segment_size = MaxLength;
}

/*************************************************************************
* FUNCTION
*  custom_get_1st_ROM_Length
*
* DESCRIPTION
*  Retrieve the actual length of 1st ROM (Load View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_1st_ROM_Length(void)
{
    kal_uint32 ROMLength = 0;

    ROMLength += (kal_uint32)&Image$$ROM$$Length;
    ROMLength += (kal_uint32)&Image$$ROM2$$Length;
    ROMLength += (kal_uint32)&Image$$ROM3$$Length;
    ROMLength += (kal_uint32)&Image$$ROM4$$Length;
    ROMLength += (kal_uint32)&Image$$ROM5$$Length;

    return ROMLength; 
}

/*************************************************************************
* FUNCTION
*  custom_get_2nd_ROM_Length
*
* DESCRIPTION
*  Retrieve the actual length of 2nd ROM (Load View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_2nd_ROM_Length(void)
{
    kal_uint32 ROMLength = 0;


    return ROMLength; 
}
#endif /* __MTK_TARGET__ */
