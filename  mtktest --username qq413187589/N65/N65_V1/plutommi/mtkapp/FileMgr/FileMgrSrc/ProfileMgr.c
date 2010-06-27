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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * ProfileMgr.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__

/*  Include: MMI header file */
#include "wgui.h"
#include "CommonScreens.h"      /* Display Popup */

#include "FileMgr.h"    /* Max characters of file path will be referenced by ProfileMgr.h */
#include "ProfileMgr.h" /* Profile Magager General Include file */
#include "ProfileMgrGProt.h"    /* Profile Magager Extern Include file */
#include "PhoneBookGprot.h"     /* mmi_phb_update_delete_audio/CallerGroup */
#include "ProfileGprots.h"      /* UpdateDeleteExtMldRingTone() */

#include "mdi_datatype.h"
#include "mdi_audio.h"

/***************************************
 * Globol Variable
 ***************************************/
EXTMELODY_CONTEXT gExtMelodyCnxt;
EXTMELODY_CONTEXT *gpExtMelodyCnxt = &gExtMelodyCnxt;
DYNEXTMELODYINFO gPmgExtMelodyInfo;

static BOOL is_target_short_filename = FALSE;


/*****************************************************************************
 * FUNCTION
 *  PmgSetShortFileName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PmgSetShortFileName(BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_target_short_filename = is_short;
}

/***************************************
 * Function Body
 ***************************************/


/*****************************************************************************
 * FUNCTION
 *  PmgInitExtMelodyStruct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PmgInitExtMelodyStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError = NVRAM_READ_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_EXT_MELODY_INFO_LID, 1, &gPmgExtMelodyInfo, sizeof(gPmgExtMelodyInfo), &pError);
    if (pError == NVRAM_READ_FAIL || gPmgExtMelodyInfo.TotleNum == 0xFF || gPmgExtMelodyInfo.ValidBit == 0xFF)
    {
        memset(&gPmgExtMelodyInfo, 0, sizeof(gPmgExtMelodyInfo));
        WriteRecord(NVRAM_EF_EXT_MELODY_INFO_LID, 1, &gPmgExtMelodyInfo, sizeof(gPmgExtMelodyInfo), &pError);
    }

#if 0   /* Scan all files to see if exist */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

}


/*****************************************************************************
 * FUNCTION
 *  PmgFmgrAddExtMelodyFunc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathfileName        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PmgFmgrAddExtMelodyFunc(S8 *pathfileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PMG_ADDFILE_ERRNO err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PmgCheckImyMidFileSize(pathfileName) == PMG_ADDFILE_ERR_FILE_TOO_LARGE)
    {
        err = PMG_ADDFILE_ERR_FILE_TOO_LARGE;
    }
    else
    {
        err = PmgAddExtMelodyByPathFileName(pathfileName);
    }

    switch (err)
    {
        case PMG_ADDFILE_ERR_SUCCESS:
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
            break;
        case PMG_ADDFILE_ERR_STR_TOO_LONG:
        case PMG_ADDFILE_ERR_STRFILE_TOO_LONG:
        case PMG_ADDFILE_ERR_STRPATH_TOO_LONG:
            DisplayPopup(
                (PU8) GetString(STR_PROFILES_RING_TONE_SETUP_NAMETOOLONG),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;
        case PMG_ADDFILE_ERR_SLOT_FULL:
            DisplayPopup(
                (PU8) GetString(STR_PROFILES_RING_TONE_SETUP_LISTFULL),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;

        case PMG_ADDFILE_ERR_FILE_TOO_LARGE:
            DisplayPopup(
                (PU8) GetString(STR_PROFILES_RING_TONE_SETUP_FILETOOLARGE),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;

        case PMG_ADDFILE_ERR_DUPLICATED:
            DisplayPopup(
                (PU8) GetString(STR_PROFILES_RING_TONE_SETUP_DUPLICATED),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;

        default:
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  PmgAddExtMelodyByPathFileName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathfileName        [?]     
 * RETURNS
 *  
 *****************************************************************************/
PMG_ADDFILE_ERRNO PmgAddExtMelodyByPathFileName(S8 *pathfileName)      /* fileName is unicode */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 freeSlot = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    freeSlot = PmgFindFirstEmptySlot();
    if (freeSlot == PMG_INVAILD_SLOT)
    {
        return PMG_ADDFILE_ERR_SLOT_FULL;
    }
    else
    {
        return PmgAddExtMelodyBySlotPathFileName(pathfileName, freeSlot);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PmgReplaceExtMelodyBySlotPathFileName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathfileName        [?]         
 *  freeSlot            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
PMG_ADDFILE_ERRNO PmgReplaceExtMelodyBySlotPathFileName(S8 *pathfileName, U8 freeSlot) /* fileName is unicode */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U8 freeSlot=0; */
    S16 pError;
    U8 i;
    PMG_ADDFILE_ERRNO res = MMI_FALSE;
    DYNEXTMELODYELEM target;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(pathfileName) >= (MAX_EXT_MELODY_FULLNAME_WIDTH / ENCODING_LENGTH))
    {
        return PMG_ADDFILE_ERR_STR_TOO_LONG;
    }
    res = PmgSeparateFilePathName(
            (S8*) pathfileName,
            (S8*) target.filepath,
            sizeof(target.filepath),
            (S8*) target.filename,
            sizeof(target.filename));
    if (res != PMG_ADDFILE_ERR_SUCCESS)
    {
        return res;
    }

    /* check if it is shorname and mark it if possible */
    if (is_target_short_filename)
    {
        MARK_EXTMELODY_SHORTNAME(target.filepath);
    }

    /* Check Duplicate */
    for (i = 0; i < MAXIMUM_EXT_MELODY_NUM; i++)
    {
        if ((i != freeSlot)
            && (PmgIsEmptySlot(i) == MMI_FALSE)
            && (mmi_ucs2cmp((S8*) gPmgExtMelodyInfo.info[i].filepath, (S8*) target.filepath) == 0)
            && (mmi_ucs2cmp((S8*) gPmgExtMelodyInfo.info[i].filename, (S8*) target.filename) == 0))
        {
            return PMG_ADDFILE_ERR_DUPLICATED;
        }
    }

    mmi_ucs2cpy((S8*) gPmgExtMelodyInfo.info[freeSlot].filepath, (S8*) target.filepath);
    mmi_ucs2cpy((S8*) gPmgExtMelodyInfo.info[freeSlot].filename, (S8*) target.filename);

    PMG_ASSERT(NVRAM_EF_EXT_MELODY_INFO_SIZE == sizeof(gPmgExtMelodyInfo));
    WriteRecord(NVRAM_EF_EXT_MELODY_INFO_LID, 1, &gPmgExtMelodyInfo, sizeof(gPmgExtMelodyInfo), &pError);
    PMG_ASSERT(pError == NVRAM_WRITE_SUCCESS);

    return PMG_ADDFILE_ERR_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  PmgStrCmp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s1        [IN]         
 *  s2        [IN]        
 * RETURNS
 *  s32
 *****************************************************************************/
S32 PmgStrCmp(S8 *s1,S8 *s2)
{
	S32 c1, c2;

	while (1)
	{
        U32 cmp;
        
        c1 = (S32)(s1[0] | (s1[1]<<8));
        c2 = (S32)(s2[0] | (s2[1]<<8));
        if ((cmp = (U32)c1 ^ (U32)c2) != 0)
        {
            if (cmp != 32 || 'A'>c1 || c1>'z' || 'A'>c2 || c2>'z')
            {
                break;
            }
        }
		s2 += 2;
		s1 += 2;
		if (c1 == '\0')
			return(0);
	}

    return( c1 - c2 );
}

/*****************************************************************************
 * FUNCTION
 *  PmgAddExtMelodyBySlotPathFileName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathfileName        [?]         
 *  freeSlot            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
PMG_ADDFILE_ERRNO PmgAddExtMelodyBySlotPathFileName(S8 *pathfileName, U8 freeSlot)     /* fileName is unicode */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U8 freeSlot=0; */
    S16 pError;
    U8 i;
    PMG_ADDFILE_ERRNO res = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PmgGetExtMelodyNum() >= MAXIMUM_EXT_MELODY_NUM)
    {
        return PMG_ADDFILE_ERR_SLOT_FULL;
    }

    if (mmi_ucs2strlen(pathfileName) >= (MAX_EXT_MELODY_FULLNAME_WIDTH / ENCODING_LENGTH))
    {
        return PMG_ADDFILE_ERR_STR_TOO_LONG;
    }

    if (PmgIsEmptySlot(freeSlot) == MMI_FALSE)
    {
        return PMG_ADDFILE_ERR_SLOT_OCCUPIED;
    }

    res = PmgSeparateFilePathName(
            (S8*) pathfileName,
            (S8*) gPmgExtMelodyInfo.info[freeSlot].filepath,
            sizeof(gPmgExtMelodyInfo.info[freeSlot].filepath),
            (S8*) gPmgExtMelodyInfo.info[freeSlot].filename,
            sizeof(gPmgExtMelodyInfo.info[freeSlot].filename));

    if (res != PMG_ADDFILE_ERR_SUCCESS)
    {
        return res;
    }

    /* check if it is shorname and mark it if possible */
    if (is_target_short_filename)
    {
        MARK_EXTMELODY_SHORTNAME(gPmgExtMelodyInfo.info[freeSlot].filepath);
    }

    /* Check Duplicate */
    for (i = 0; i < MAXIMUM_EXT_MELODY_NUM; i++)
    {
        if ((i != freeSlot)
            && (PmgIsEmptySlot(i) == MMI_FALSE)
            &&
            (PmgStrCmp
             ((S8*) gPmgExtMelodyInfo.info[i].filepath, (S8*) gPmgExtMelodyInfo.info[freeSlot].filepath) == 0) &&
            (PmgStrCmp
             ((S8*) gPmgExtMelodyInfo.info[i].filename, (S8*) gPmgExtMelodyInfo.info[freeSlot].filename) == 0))
        {
            memset(gPmgExtMelodyInfo.info[freeSlot].filepath, 0, sizeof(gPmgExtMelodyInfo.info[freeSlot].filepath));
            memset(gPmgExtMelodyInfo.info[freeSlot].filename, 0, sizeof(gPmgExtMelodyInfo.info[freeSlot].filename));            
            return PMG_ADDFILE_ERR_DUPLICATED;
        }
    }

    gPmgExtMelodyInfo.info[freeSlot].id = PMG_EXT_MELODY_BEGIN + freeSlot;
    gPmgExtMelodyInfo.TotleNum++;

    PMG_BIT_ON(gPmgExtMelodyInfo.ValidBit, freeSlot);
    PMG_ASSERT(NVRAM_EF_EXT_MELODY_INFO_SIZE == sizeof(gPmgExtMelodyInfo));
    WriteRecord(NVRAM_EF_EXT_MELODY_INFO_LID, 1, &gPmgExtMelodyInfo, sizeof(gPmgExtMelodyInfo), &pError);
    PMG_ASSERT(pError == NVRAM_WRITE_SUCCESS);

    return PMG_ADDFILE_ERR_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  PmgDelExtMelodyBySlot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slot        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PmgDelExtMelodyBySlot(U8 slot) /* root function for delete */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPmgExtMelodyInfo.TotleNum > 0)
    {
        gPmgExtMelodyInfo.TotleNum--;
    }
    else
    {
        return;
    }

    /* Update phone book entries */
    mmi_phb_update_delete_audio(gPmgExtMelodyInfo.info[slot].id);
    mmi_phb_update_delete_audio_caller_group(gPmgExtMelodyInfo.info[slot].id);
    UpdateDeleteExtMldToneSetup((U16) (PMG_EXT_MELODY_BEGIN + slot));

    /* Delete solt mask */
    PMG_BIT_OFF(gPmgExtMelodyInfo.ValidBit, slot);

    /* Delete data in nvram */
    memset(&gPmgExtMelodyInfo.info[slot], 0, sizeof(gPmgExtMelodyInfo.info[slot]));
    PMG_ASSERT(NVRAM_EF_EXT_MELODY_INFO_SIZE == sizeof(gPmgExtMelodyInfo));
    WriteRecord(NVRAM_EF_EXT_MELODY_INFO_LID, 1, &gPmgExtMelodyInfo, sizeof(gPmgExtMelodyInfo), &pError);
    PMG_ASSERT(pError == NVRAM_WRITE_SUCCESS);

}


/*****************************************************************************
 * FUNCTION
 *  PmgDelExtMelodyById
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL PmgDelExtMelodyById(U16 id)   /* Finally, call PmgDelExtMelodyBySlot() */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 slot = PmgGetSlotById(id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slot == PMG_INVAILD_SLOT)
    {
        return MMI_FALSE;
    }
    else
    {
        PmgDelExtMelodyBySlot(slot);
        return MMI_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  PmgDelExtMelodyByPathFileName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathfileName        [?]     
 * RETURNS
 *  
 *****************************************************************************/
pBOOL PmgDelExtMelodyByPathFileName(S8 *pathfileName)   /* Finally, call PmgDelExtMelodyBySlot() */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 slot = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_ucs2strlen(pathfileName) >= (MAX_EXT_MELODY_FULLNAME_WIDTH / ENCODING_LENGTH))
        || (gPmgExtMelodyInfo.TotleNum == 0))
    {
        return MMI_FALSE;
    }

    slot = PmgGetSlotByPathFileName(pathfileName);
    if (slot == PMG_INVAILD_SLOT)
    {
        return MMI_FALSE;
    }
    else
    {
        PmgDelExtMelodyBySlot(slot);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  PmgFmgrDelExtMelodyFunc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathfileName        [?]         
 *  action              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL PmgFmgrDelExtMelodyFunc(S8 *pathfileName, PMG_DELFILE_ACTION action)      /* Finally, call PmgDelExtMelodyBySlot() */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL res = MMI_TRUE;
    U16 c;
    S32 len1, idx;
    S8 *path;
    BOOL shortmark = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (action)
    {
        case PMG_FMGR_DEL_CERTAIN:
            res = PmgDelExtMelodyByPathFileName(pathfileName);
            break;
        case PMG_FMGR_DEL_ALL:
        {
            U8 i;
            S8 buf[MAX_EXT_MELODY_FULLNAME_WIDTH];

            /* check deleted file path */
            if ((len1 = mmi_ucs2strlen(pathfileName)) < 2) // at least <drive>:
                break;

            /* check if the last char "\" and don't count it in length */
            idx = (len1 - 1) << 1;
            c = (U16)(pathfileName[idx] | (pathfileName[idx+1]<<8));
            if (c == L'\\')
                len1--; // skip the last "\" char
                
            for (i = 0; i < MAXIMUM_EXT_MELODY_NUM; i++)
            {
                if(IS_EXTMELODY_SHORTNAME(gPmgExtMelodyInfo.info[i].filepath))
                {
                    UNMARK_EXTMELODY_SHORTNAME(gPmgExtMelodyInfo.info[i].filepath);
                    shortmark = TRUE;
                }
                path = (S8*)gPmgExtMelodyInfo.info[i].filepath;
                if(mmi_ucs2ncmp(pathfileName, path, len1) == 0)
                {
                    PmgConstructPathFileName(
                        buf,
                        sizeof(buf),
                        (S8*) gPmgExtMelodyInfo.info[i].filepath,
                        (S8*) gPmgExtMelodyInfo.info[i].filename);
                    
                    if(FS_GetAttributes((PU16)buf) < 0 )
                    {
                        if (PmgDelExtMelodyById(gPmgExtMelodyInfo.info[i].id) == MMI_FALSE)
                        {
                            res = MMI_FALSE;
                            if(shortmark)
                            {
                                MARK_EXTMELODY_SHORTNAME(gPmgExtMelodyInfo.info[i].filepath);
                            }
                        }
                    }
                }
                else
                {
                    if(shortmark)
                    {
                        MARK_EXTMELODY_SHORTNAME(gPmgExtMelodyInfo.info[i].filepath);  
                    }
                }
            }
            break;
        }
        default:
            PMG_ASSERT(0);
            break;
    }
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  PmgGetExtMelodyInfo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ExtMelodInfo        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 PmgGetExtMelodyInfo(DYNEXTMELODYINFO **ExtMelodInfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ExtMelodInfo = &gPmgExtMelodyInfo;
    return gPmgExtMelodyInfo.TotleNum;
}


/*****************************************************************************
 * FUNCTION
 *  PmgGetExtMelodyNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 PmgGetExtMelodyNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gPmgExtMelodyInfo.TotleNum;
}


/*****************************************************************************
 * FUNCTION
 *  PmgIsIdExist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  soundId     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL PmgIsIdExist(U32 soundId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (soundId >= PMG_EXT_MELODY_BEGIN && soundId <= PMG_EXT_MELODY_END)
    {
        for (i = 0; i < MAXIMUM_EXT_MELODY_NUM; i++)
            if (gPmgExtMelodyInfo.info[i].id == soundId)
            {
                return MMI_TRUE;
            }
    }
    else
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  PmgQueryFileExistById
 * DESCRIPTION
 *  
 * PARAMETERS
 *  soundId     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL PmgQueryFileExistById(U32 soundId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (soundId >= PMG_EXT_MELODY_BEGIN && soundId <= PMG_EXT_MELODY_END)
    {
        for (i = 0; i < MAXIMUM_EXT_MELODY_NUM; i++)
            if (gPmgExtMelodyInfo.info[i].id == soundId)
            {
                return PmgQueryFileExistBySlot(i);
            }
    }
    else
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  PmgQueryFileExistBySlot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slot        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL PmgQueryFileExistBySlot(U8 slot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[MAX_EXT_MELODY_FULLNAME_WIDTH];
    FS_HANDLE h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slot > MAXIMUM_EXT_MELODY_NUM)
    {
        return MMI_FALSE;
    }

    PmgConstructPathFileName(
        buf,
        sizeof(buf),
        (S8*) gPmgExtMelodyInfo.info[slot].filepath,
        (S8*) gPmgExtMelodyInfo.info[slot].filename);
    h = FS_Open((WCHAR*)buf, FS_READ_ONLY);

    if (h > 0)
    {
        FS_Close(h);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  PmgQueryFileDRMForwardableBySlot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slot        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL PmgQueryFileDRMForwardableBySlot(U8 slot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[MAX_EXT_MELODY_FULLNAME_WIDTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slot > MAXIMUM_EXT_MELODY_NUM)
    {
        return MMI_FALSE;
    }

    PmgConstructPathFileName(
        buf,
        sizeof(buf),
        (S8*) gPmgExtMelodyInfo.info[slot].filepath,
        (S8*) gPmgExtMelodyInfo.info[slot].filename);

    return mmi_profiles_check_DRM_content_forwardable((UI_string_type)buf);

}
#endif

/*****************************************************************************
 * FUNCTION
 *  PmgGetFileExt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf     [?]     
 * RETURNS
 *  
 *****************************************************************************/
S8 *PmgGetFileExt(S8 *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 len = (U16) mmi_ucs2strlen(buf);
    S16 *pbuf = (S16*) buf;
    S16 deter = '.';

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (len > 0)
    {
        if (memcmp((pbuf + len), &deter, 2) == 0)
        {
            return (S8*) (pbuf + len + 1);
        }
        len--;
    }
    return NULL;

}


/*****************************************************************************
 * FUNCTION
 *  PmgCheckImyMidFileSize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  
 *****************************************************************************/
PMG_ADDFILE_ERRNO PmgCheckImyMidFileSize(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *file_ext_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_ext_p = PmgGetFileExt(path);
    if (mmi_ucs2ncmp(file_ext_p, (S8*) L"mid", 3) == 0 || mmi_ucs2ncmp(file_ext_p, (S8*) L"MID", 3) == 0
        || mmi_ucs2ncmp(file_ext_p, (S8*) L"imy", 3) == 0 || mmi_ucs2ncmp(file_ext_p, (S8*) L"IMY", 3) == 0)
    {
        FS_HANDLE h;
        kal_uint32 file_size = 0;   /* U32 file_size=0; */

        h = FS_Open((U16*) path, FS_READ_ONLY);
        if (h)
        {
            FS_GetFileSize(h, &file_size);
            FS_Close(h);
        }
        else
        {
            return PMG_ADDFILE_ERR_UNKNOWN;
        }

        if (file_size > mdi_audio_get_midi_size_limit() )
        {
            return PMG_ADDFILE_ERR_FILE_TOO_LARGE;
        }
    }
    return PMG_ADDFILE_ERR_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  PmgRemoveFileExt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PmgRemoveFileExt(S8 *buf)  /* Notice! This function will change the buffer context */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 len = (U16) mmi_ucs2strlen(buf);
    S16 *pbuf = (S16*) buf;
    S16 deter = '.';

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (len > 0)
    {
        if (memcmp((pbuf + len), &deter, 2) == 0)
        {
            *(pbuf + len) = 0x0000;
            break;
        }
        len--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  PmgRemoveFileDAFExt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PmgRemoveFileDAFExt(S8 *buf)   /* Notice! This function will change the buffer context */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 len = (U16) mmi_ucs2strlen(buf);
    S16 *pbuf = (S16*) buf;
    S16 deter = '.';
    S16 ExtWord_U[5];
    S16 ExtWord_L[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ExtWord_U, 0, sizeof(ExtWord_U));
    memset(ExtWord_L, 0, sizeof(ExtWord_L));
    ExtWord_U[0] = 0x002E;
    ExtWord_L[0] = 0x002E;
    ExtWord_U[1] = 0x004D;
    ExtWord_L[1] = 0x006D;
    ExtWord_U[2] = 0x0050;
    ExtWord_L[2] = 0x0070;
    ExtWord_U[3] = 0x0033;
    ExtWord_L[3] = 0x0033;
    ExtWord_U[4] = 0x0000;
    ExtWord_L[4] = 0x0000;

    while (len > 0)
    {
        if (memcmp((pbuf + len), &deter, 2) == 0)
        {
            if ((mmi_ucs2ncmp((S8*) (pbuf + len), (S8*) ExtWord_U, 4) == 0)
                || (mmi_ucs2ncmp((S8*) (pbuf + len), (S8*) ExtWord_L, 4) == 0))
            {
                *(pbuf + len) = 0x0000;
            }
            break;
        }
        len--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  PmgConstructPathFileName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf         [?]         
 *  size        [IN]        
 *  path        [?]         
 *  file        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void PmgConstructPathFileName(S8 *buf, U16 size, S8 *path, S8 *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size < MAX_EXT_MELODY_FULLNAME_WIDTH)
    {
        buf[0] = 0x0;
        buf[1] = 0x0;
        return;
    }
    mmi_ucs2cpy(buf, (S8*) path);
    mmi_ucs2cat(buf, (S8*) L"\\");
    mmi_ucs2cat(buf, (S8*) file);
    UNMARK_EXTMELODY_SHORTNAME(buf);
}


/*****************************************************************************
 * FUNCTION
 *  PmgGetSlotById
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 PmgGetSlotById(U16 Id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((Id < PMG_EXT_MELODY_BEGIN) || (Id > PMG_EXT_MELODY_BEGIN + MAXIMUM_EXT_MELODY_NUM))
    {
        return MMI_FALSE;
    }

    for (i = 0; i < MAXIMUM_EXT_MELODY_NUM; i++)
    {
        if (gPmgExtMelodyInfo.info[i].id == Id)
        {
            return i;
        }
    }

    return PMG_INVAILD_SLOT;

}


/*****************************************************************************
 * FUNCTION
 *  PmgGetSlotByPathFileName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathfileName        [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 PmgGetSlotByPathFileName(S8 *pathfileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    S8 tmpStr[MAX_EXT_MELODY_FULLNAME_WIDTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(pathfileName) >= (MAX_EXT_MELODY_FULLNAME_WIDTH))
    {
        return MMI_FALSE;
    }

    for (i = 0; i < MAXIMUM_EXT_MELODY_NUM; i++)
    {
        PmgConstructPathFileName(
            tmpStr,
            sizeof(tmpStr),
            (S8*) gPmgExtMelodyInfo.info[i].filepath,
            (S8*) gPmgExtMelodyInfo.info[i].filename);
        if (mmi_ucs2cmp(pathfileName, tmpStr) == 0)
        {
            return i;
        }
    }
    return PMG_INVAILD_SLOT;

}


/*****************************************************************************
 * FUNCTION
 *  PmgGetFilePathNameByAudioId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf         [?]         
 *  size        [IN]        
 *  AudioId     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL PmgGetFilePathNameByAudioId(S8 *buf, U16 size, U16 AudioId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size < MAX_EXT_MELODY_FULLNAME_WIDTH)
    {
        return MMI_FALSE;
    }

    memset(buf, 0, size);
    for (i = 0; i < MAXIMUM_EXT_MELODY_NUM; i++)
    {
        if (gPmgExtMelodyInfo.info[i].id == AudioId)
        {
            FS_HANDLE handle ;
            
            PmgConstructPathFileName(
                buf,
                size,
                (S8*) gPmgExtMelodyInfo.info[i].filepath,
                (S8*) gPmgExtMelodyInfo.info[i].filename);

            if ((handle = FS_Open((PU16) buf, FS_READ_ONLY)) < FS_NO_ERROR)
            {
                return MMI_FALSE;
            }
            else
            {
                FS_Close(handle);
            }
                
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  PmgGetFileNameByFilePath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathfileName        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S8 *PmgGetFileNameByFilePath(S8 *pathfileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 NameLength = (U16) mmi_ucs2strlen(pathfileName);
    S16 *UniPathName = (S16*) pathfileName;
    U16 deter = '\\';

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NameLength >= MAX_EXT_MELODY_NAME_WIDTH / ENCODING_LENGTH)
    {
        return NULL;
    }

    if ((NameLength & 0x1) == 1)
    {
        return NULL;
    }

    while (NameLength > 0)
    {
        NameLength -= 2;
        if (memcmp(UniPathName + NameLength, &deter, 2) == 0)
        {
            break;
        }
    }
    return (pathfileName + NameLength);

}


/*****************************************************************************
 * FUNCTION
 *  PmgSeparateFilePathName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathfileName        [?]         
 *  pathname            [?]         
 *  pathsize            [IN]        
 *  filename            [?]         
 *  filesize            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
PMG_ADDFILE_ERRNO PmgSeparateFilePathName(S8 *pathfileName, S8 *pathname, U16 pathsize, S8 *filename, U16 filesize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0, j = 0, StoredNameLength, NameLength;
    U16 deter = '\\';

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StoredNameLength = NameLength = (mmi_ucs2strlen(pathfileName) + 1) * ENCODING_LENGTH;

    if (NameLength >= (MAX_EXT_MELODY_FULLNAME_WIDTH))  /* Unicode byte */
    {
        return PMG_ADDFILE_ERR_STR_TOO_LONG;
    }

    if ((NameLength & 0x1) == 1)
    {
        return PMG_ADDFILE_ERR_INVAILD_NAME;
    }

    while (NameLength > 0)
    {
        NameLength -= 2;
        if (memcmp(pathfileName + NameLength, &deter, 2) == 0)
        {
            break;
        }
    }

    if (NameLength == 0)
    {
        return PMG_ADDFILE_ERR_INVAILD_NAME;
    }
    else
    {
        if (pathsize < NameLength)
        {
            return PMG_ADDFILE_ERR_STRPATH_TOO_LONG;
        }

        if (filesize < (StoredNameLength - NameLength))
        {
            return PMG_ADDFILE_ERR_STRFILE_TOO_LONG;
        }

        for (i = 0; i < StoredNameLength; i++)
        {
            if (i < (NameLength + ENCODING_LENGTH))
            {
                *(pathname + i) = *(pathfileName + i);
            }
            else
            {
                *(filename + j++) = *(pathfileName + i);    /* filename has been terminated because it is copied from pathfilename */
            }
        }
        *(pathname + NameLength) = 0x0;
        *(pathname + NameLength + 1) = 0x0;
    }

    return PMG_ADDFILE_ERR_SUCCESS;

}


/*****************************************************************************
 * FUNCTION
 *  PmgFindFirstEmptySlot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 PmgFindFirstEmptySlot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (sizeof(gPmgExtMelodyInfo.ValidBit) * 8); i++)
    {
        if (PMG_BIT_TEST(gPmgExtMelodyInfo.ValidBit, i) == 0)
        {
            break;
        }
    }
    if (i >= MAXIMUM_EXT_MELODY_NUM)
    {
        i = PMG_INVAILD_SLOT;   // i= (MAXIMUM_EXT_MELODY_NUM - 1); /* zero based */
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  PmgIsEmptySlot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slot        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL PmgIsEmptySlot(U8 slot)   /* slot is zero based */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PMG_BIT_TEST(gPmgExtMelodyInfo.ValidBit, slot) == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  PmgGetExtMelodyRange
 * DESCRIPTION
 *  
 * PARAMETERS
 *  startId     [?]     
 *  totalId     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PmgGetExtMelodyRange(U32 *startId, U32 *totalId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *startId = PMG_EXT_MELODY_BEGIN;
    *totalId = PMG_EXT_MELODY_BEGIN + MAXIMUM_EXT_MELODY_NUM;
}
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 

