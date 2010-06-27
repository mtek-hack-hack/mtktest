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
 * mmi_phnset_dispchar.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Display Characteristic
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

/***************************************************************************** 
* Include
*****************************************************************************/
/*  Include: MMI header file */
#include "MMI_include.h"

#include "PhoneSetup.h"
#include "FileManagerGProt.h"
#include "fmt_def.h"
#include "WPSSProtos.h"

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern S8 *idle_screen_wallpaper_name;

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* External Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_dispchar_get_img_id
 * DESCRIPTION
 *  To get image id from NVRAM.
 * PARAMETERS
 *  nDataItemId     [IN]        Id in cache short
 *  pBuffer         [?]         
 *  data(?)         [OUT]       Data in cache short
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dispchar_get_img_id(U8 nDataItemId, U16 *pBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = *(U16*) (pBuffer);
    ReadValue(nDataItemId, &data, DS_SHORT, &error);
    switch (nDataItemId)
    {
        case NVRAM_FUNANDGAMES_SETWALLPAPER:
            if (!data || data == IMG_ID_DISPCHAR_AVATAR_WALLPAPER)
                ;
            else
                data = data - 1 + IMG_ID_PHNSET_WP_START;
            break;
        case RESTORE_DEFAULT_FUNANDGAMES_SETWALLPAPER:
            data = (data == 0) ? (data) : (data - 1 + IMG_ID_PHNSET_WP_START);
            break;
    #ifdef __MMI_SUB_WALLPAPER__
        case NVRAM_SETWALLPAPER_SUB:
            data = (data == 0) ? (data) : (data - 1 + IMG_ID_PHNSET_SUB_WP_START);
            break;
        case RESTORE_DEFAULT_SETWALLPAPER_SUB:
            data = (data == 0) ? (data) : (data - 1 + IMG_ID_PHNSET_SUB_WP_START);
            break;
    #endif /* __MMI_SUB_WALLPAPER__ */                
        case NVRAM_CURRENT_SCREENSVER_ID:
            if (!data || data == IMG_ID_DISPCHAR_AVATAR_SCREENSAVER)
                ;
            else
                data = data - 1 + IMG_ID_PHNSET_SS_START;
            break;
        case RESTORE_DEFAULT_CURRENT_SCREENSVER_ID:
            data = (data == 0) ? (data) : (data - 1 + IMG_ID_PHNSET_SS_START);
            break;
    #ifdef __MMI_POWER_ON_OFF_DISPLAY__
        case NVRAM_RESTORE_POWER_ON_DISPLAY:
            if (!data || data == IMG_ID_DISPCHAR_AVATAR_ON)
                ;
            else
                data = data - 1 + IMG_ID_PHNSET_ON_START;
            break;
        case NVRAM_CURRENT_POWER_ON_DISPLAY:
            data = (data == 0) ? (data) : (data - 1 + IMG_ID_PHNSET_ON_START);
            break;
        case NVRAM_RESTORE_POWER_OFF_DISPLAY:
            if (!data || data == IMG_ID_DISPCHAR_AVATAR_OFF)
                ;
            else
                data = data - 1 + IMG_ID_PHNSET_OFF_START;
            break;
        case NVRAM_CURRENT_POWER_OFF_DISPLAY:
            data = (data == 0) ? (data) : (data - 1 + IMG_ID_PHNSET_OFF_START);
            break;
    #endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 
        default:
            MMI_ASSERT(0);
            break;
    }

    *(U16*) (pBuffer) = data;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dispchar_set_img_id
 * DESCRIPTION
 *  To set image id to NVRAM.
 * PARAMETERS
 *  nDataItemId     [IN]        Id in cache short
 *  pBuffer         [?]         
 *  data(?)         [IN]        Data in cache short
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dispchar_set_img_id(U8 nDataItemId, U16 *pBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = *(U16*) (pBuffer);

    switch (nDataItemId)
    {
        case NVRAM_FUNANDGAMES_SETWALLPAPER:
            if (!data || data == IMG_ID_DISPCHAR_AVATAR_WALLPAPER)
                ;
            else
                data = data - IMG_ID_PHNSET_WP_START + 1;
            break;
        case RESTORE_DEFAULT_FUNANDGAMES_SETWALLPAPER:
            data = (data == 0) ? (data) : (data - IMG_ID_PHNSET_WP_START + 1);
            break;
    #ifdef __MMI_SUB_WALLPAPER__
        case NVRAM_SETWALLPAPER_SUB:
            data = (data == 0) ? (data) : (data - IMG_ID_PHNSET_SUB_WP_START + 1);
            break;
        case RESTORE_DEFAULT_SETWALLPAPER_SUB:
            data = (data == 0) ? (data) : (data - IMG_ID_PHNSET_SUB_WP_START + 1);
            break;
    #endif /* __MMI_SUB_WALLPAPER__ */
        case NVRAM_CURRENT_SCREENSVER_ID:
            if (!data || data == IMG_ID_DISPCHAR_AVATAR_SCREENSAVER)
                ;
            else
                data = data - IMG_ID_PHNSET_SS_START + 1;
            break;
        case RESTORE_DEFAULT_CURRENT_SCREENSVER_ID:
            data = (data == 0) ? (data) : (data - IMG_ID_PHNSET_SS_START + 1);
            break;
    #ifdef __MMI_POWER_ON_OFF_DISPLAY__
        case NVRAM_RESTORE_POWER_ON_DISPLAY:
            if (!data || data == IMG_ID_DISPCHAR_AVATAR_ON)
                ;
            else
                data = data - IMG_ID_PHNSET_ON_START + 1;
            break;
        case NVRAM_CURRENT_POWER_ON_DISPLAY:
            data = (data == 0) ? (data) : (data - IMG_ID_PHNSET_ON_START + 1);
            break;
        case NVRAM_RESTORE_POWER_OFF_DISPLAY:
            if (!data || data == IMG_ID_DISPCHAR_AVATAR_OFF)
                ;
            else
                data = data - IMG_ID_PHNSET_OFF_START + 1;
              break;
        case NVRAM_CURRENT_POWER_OFF_DISPLAY:
            data = (data == 0) ? (data) : (data - IMG_ID_PHNSET_OFF_START + 1);
            break;
    #endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 
        default:
            MMI_ASSERT(0);
            break;
    }

    WriteValue(nDataItemId, &data, DS_SHORT, &error);

}

/*****************************************************************************
 * FUNCTION
 *  dispchar_iswp_swflash
 * DESCRIPTION
 *  To check if wallpaper is a swflash.
 * PARAMETERS
 *  nDataItemId     [IN]        Id in cache short
 *  pBuffer         [?]         
 *  data(?)         [IN]        Data in cache short
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SWFLASH__
MMI_BOOL dispchar_iswp_swflash(void)
{
    PHNSET_TYPE_DISP type = PhnsetGetDisplayType((U16)PhnsetGetCurWallPaperIdx());

    /* add to check SWFLASH file remove or not */
    if ((type == PHNSET_TYPE_DISP_USER) && (mmi_fmgr_get_file_group(idle_screen_wallpaper_name) == FMGR_GROUP_UNKNOWN))
    {
        PhnsetWallpaperBadFileCallBack(0);
        return MMI_FALSE;
    }

	if ( type == PHNSET_TYPE_DISP_SWFLASH ||
	    (type == PHNSET_TYPE_DISP_USER && idle_screen_wallpaper_name && mmi_fmgr_get_file_group(idle_screen_wallpaper_name) == FMGR_GROUP_SWFLASH))
	    return MMI_TRUE;
    else
        return MMI_FALSE;
}
#endif /* __MMI_SWFLASH__ */

#ifdef __MMI_AVATAR__
void dispchar_get_current_avatar_id(U16 id, U32 *avatar_id,  U32 *serial_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
	U32 buffer[2];
    U32 serial_buffer[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
	switch (id)
	{
		case IMG_ID_DISPCHAR_AVATAR_WALLPAPER:
		{

			ReadValue(NVRAM_DISPCHAR_AVATAR_WPSS, (U8 *)buffer, DS_DOUBLE, &error);
            ReadValue(NVRAM_DISPCHAR_AVATAR_WPSS_SERIALNUM, (U8 *)serial_buffer, DS_DOUBLE, &error);
			*avatar_id = buffer[IMG_ID_DISPCHAR_AVATAR_WALLPAPER - IMG_ID_DISPCHAR_AVATAR_START];
            *serial_num = serial_buffer[IMG_ID_DISPCHAR_AVATAR_WALLPAPER - IMG_ID_DISPCHAR_AVATAR_START];
			break;
		}
		case IMG_ID_DISPCHAR_AVATAR_SCREENSAVER:
		{
			ReadValue(NVRAM_DISPCHAR_AVATAR_WPSS, (U8 *)buffer, DS_DOUBLE, &error);
            ReadValue(NVRAM_DISPCHAR_AVATAR_WPSS_SERIALNUM, (U8 *)serial_buffer, DS_DOUBLE, &error);
			*avatar_id = buffer[IMG_ID_DISPCHAR_AVATAR_SCREENSAVER- IMG_ID_DISPCHAR_AVATAR_START];
            *serial_num = serial_buffer[IMG_ID_DISPCHAR_AVATAR_SCREENSAVER- IMG_ID_DISPCHAR_AVATAR_START];
			break;
		}
		case IMG_ID_DISPCHAR_AVATAR_ON:
		{
			ReadValue(NARAM_DISPCHAR_AVATAR_ONOFF, (U8 *)buffer, DS_DOUBLE, &error);
            ReadValue(NVRAM_DISPCHAR_AVATAR_ONOFF_SERIALNUM, (U8 *)serial_buffer, DS_DOUBLE, &error);
			*avatar_id = buffer[IMG_ID_DISPCHAR_AVATAR_ON - IMG_ID_DISPCHAR_AVATAR_ON];
            *serial_num = serial_buffer[IMG_ID_DISPCHAR_AVATAR_ON - IMG_ID_DISPCHAR_AVATAR_ON];
			break;
		}
		case IMG_ID_DISPCHAR_AVATAR_OFF:
		{
			ReadValue(NARAM_DISPCHAR_AVATAR_ONOFF, (U8 *)buffer, DS_DOUBLE, &error);		          
		    ReadValue(NVRAM_DISPCHAR_AVATAR_ONOFF_SERIALNUM, (U8 *)serial_buffer, DS_DOUBLE, &error);      
			*avatar_id = buffer[IMG_ID_DISPCHAR_AVATAR_OFF - IMG_ID_DISPCHAR_AVATAR_ON];
            *serial_num = serial_buffer[IMG_ID_DISPCHAR_AVATAR_OFF - IMG_ID_DISPCHAR_AVATAR_ON];
			break;
		}
		default:
			*avatar_id = 0;
			break;
	}
}
#endif
