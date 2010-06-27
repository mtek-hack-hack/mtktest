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
 * NITZ.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements interface and message handler for NITZ.
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************
   FILENAME : NITZ.c
   PURPOSE     : NITZ Source File
   REMARKS     : nil
   AUTHOR      : Restructured by Gurinder
   DATE     : Restructured on Dec-01-2003
**************************************************************/
#include "MMI_include.h"
#ifndef _MMI_NITZ_C
#define _MMI_NITZ_C

#if defined(__MMI_NITZ__)

#include "NITZ.h"
#include "DateTimeGprot.h"
#include "ProtocolEvents.h"
#include "SettingGprots.h"
#include "SettingProfile.h"
#include "gpioInc.h"
#include "SettingProt.h"
#include "IdleAppDef.h"
#include "PhoneSetupGprots.h"
#include "SimDetectionDef.h"
#include "SimDetectionGexdcl.h"
#include "CallsDefs.h"
#include "GSM7BitDefaultAlphabet.h"
#ifdef __MMI_NITZ_TZ_SUPPORT__
#include "worldclock.h"
#include "app_datetime.h"
#include "DatetimeGprot.h"
#endif /* __MMI_NITZ_TZ_SUPPORT__ */ 

#ifdef  __MMI_DUAL_SIM_SINGLE_CALL__
void MTPNP_PFAL_NITZHandler(void *msg);
#endif

#ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
#include "MTPNP_AD_slave_header.h"
#include "MTPNP_PFAL_Slave_Network.h"
#endif  /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
#include "MTPNP_AD_slave_header.h"
#include "MTPNP_PFAL_Gemini_Network.h"
#endif  /* __MMI_DUAL_SIM_SINGLE_CALL__ */
/* 
 * Define
 */
#define NITZ_SIGN_BIT   0x08
#define NITZ_HIGH_BIT   0xF0
#define NITZ_LOW_BIT 0x0F
#define NITZ_TZ_BIT  0x07

#define NITZ_TIME_LEN      20*ENCODING_LENGTH
#define NITZ_MAX_ALLOW_DIFF   15
/* 
 * Typedef 
 */

/* 
 * Local Variable
 */
nitz_context_struct g_nitz_cntx;
static S16 nitzTempTZ;
#ifdef __MMI_NITZ_TZ_SUPPORT__
static S16 nitzTempDST;
#endif /* __MMI_NITZ_TZ_SUPPORT__ */ 

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
extern wgui_inline_item wgui_inline_items[];
extern MYTIME MyTime;
extern rtc_format_struct gclockData;
/* 
 * Global Function
 */
extern void PhnsetSetDT(void);
extern void EntryPhnsetTimeAndDate(void);
extern void EntryIdleScreen(void);
extern FLOAT GetTimeZone(U8 cityIndex);
extern void EntryPhnsetSetDT(void);
extern void mmi_idle_update_opname_from_nitz(void);


/*****************************************************************************
 * FUNCTION
 *  NITZHandlerInit
 * DESCRIPTION
 *  NITZ Initlization function,
 *  Set the global variable of NITZ to default and register NITZ indication handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NITZHandlerInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_DUAL_SIM_DUAL_CALL_SLAVE__)
    SetProtocolEventHandler(NITZHandler, PRT_MSG_ID_MMI_NW_TIME_ZONE_IND);
#else /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
    SetProtocolEventHandler(MTPNP_PFAL_NITZHandler, PRT_MSG_ID_MMI_NW_TIME_ZONE_IND);
#endif /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
    memset(&g_nitz_cntx, 0, sizeof(nitz_context_struct));
    g_nitz_cntx.NITZTimeZone = (S16) 0xffff;
    /* init PLMN */
    mmi_nitz_get_nitz_nw_name(NULL, g_nitz_cntx.NWShortName, MAX_NW_LEN *ENCODING_LENGTH, NULL);
#if defined(__MMI_DUAL_SIM_SINGLE_CALL__)
    SetSlaveProtocolEventHandler(MTPNP_PFAL_NITZHandler, PRT_MSG_ID_MMI_NW_TIME_ZONE_IND);
#endif

#ifdef __MMI_NITZ_TZ_SUPPORT__    
    /* init timezone */
    ReadValue(NVRAM_TIMEZONE, &(g_nitz_cntx.NITZTimeZone), DS_SHORT, &error);		
    
    /* init dst */
    ReadValue(NVRAM_SETTING_DT_DST, &(g_nitz_cntx.NITZDST), DS_BYTE, &error);
    PRINT_INFORMATION("NITZ: NITZHandlerInit: g_nitz_cntx.NITZDST = %d", g_nitz_cntx.NITZDST);
    PRINT_INFORMATION("NITZ: NITZHandlerInit: g_nitz_cntx.NITZTimeZone = %d", g_nitz_cntx.NITZTimeZone);
#endif /* __MMI_NITZ_TZ_SUPPORT__ */    
}


/*****************************************************************************
 * FUNCTION
 *  NITZHandler
 * DESCRIPTION
 *  NITZ Inidcation Handler, Thi function checks the diffrence in time zone,
 *  if diffrence is not zero, it set NITZ occurance to true and entry NITZ screen.
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NITZHandler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_time_zone_ind_struct *msgReq;
    MYTIME refTime1;
    FLOAT NetTimeZone;
    U8 updateShortNW = 0, updateFullNW = 0;
    U8 DeaultNWName[MAX_NW_LEN *ENCODING_LENGTH];
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&refTime1, 0, sizeof(MYTIME));
    mmi_nitz_get_nitz_nw_name(NULL, DeaultNWName, MAX_NW_LEN *ENCODING_LENGTH, NULL);

    if (!PhnsetGetNITZFuncStatus())
    {
        return;
    }

    msgReq = (mmi_nw_time_zone_ind_struct*) msg;

    if (msgReq->nw_time_zone_timeP)
    {
        /* compare network timezone and last recevied timezone */
        refTime1.nYear = NITZConvertTime(msgReq->nw_time_zone_time.year) + YEARFORMATE;
        refTime1.nMonth = NITZConvertTime(msgReq->nw_time_zone_time.month);
        refTime1.nDay = NITZConvertTime(msgReq->nw_time_zone_time.day);
        refTime1.nHour = NITZConvertTime(msgReq->nw_time_zone_time.hour);
        refTime1.nMin = NITZConvertTime(msgReq->nw_time_zone_time.min);
        refTime1.nSec = NITZConvertTime(msgReq->nw_time_zone_time.sec);

        nitzTempTZ = NITZGetTimeZone(msgReq->nw_time_zone_time.time_zone);
        NetTimeZone = (FLOAT) nitzTempTZ;
        NetTimeZone /= 4;

        mmi_dt_utc_to_rtc(NetTimeZone, refTime1, g_nitz_cntx.NITZTime);
        PRINT_INFORMATION("NITZ: NITZHandler:nitzTempTZ = %d", nitzTempTZ);
        PRINT_INFORMATION("NITZ: NITZHandler:g_nitz_cntx.NITZTime.nHour = %d", g_nitz_cntx.NITZTime.nHour);
        PRINT_INFORMATION("NITZ: NITZHandler:g_nitz_cntx.NITZTime.nMin = %d", g_nitz_cntx.NITZTime.nMin);
        PRINT_INFORMATION("NITZ: NITZHandler:g_nitz_cntx.NITZTime.nSec = %d", g_nitz_cntx.NITZTime.nSec);
    }
	else
	{
		memset(&g_nitz_cntx.NITZTime, 0, sizeof(MYTIME));
	}

#ifdef __MMI_NITZ_TZ_SUPPORT__
    /* Time Zone Support */
    if (msgReq->nw_time_zoneP)
    {
        g_nitz_cntx.TimeZoneP = MMI_TRUE;
        nitzTempTZ = NITZGetTimeZone(msgReq->nw_time_zone);
        PRINT_INFORMATION("NITZ: NITZHandler:nitzTempTZ = %d", nitzTempTZ);
    }
    else
    {
        g_nitz_cntx.TimeZoneP = MMI_FALSE;
    }

    /* DST Support */
    if (msgReq->nw_day_light_saving_timeP)
    {
        g_nitz_cntx.DSTP = MMI_TRUE;
        nitzTempDST = msgReq->nw_day_light_saving_time & 0x03;
        PRINT_INFORMATION("NITZ: NITZHandler:nitzTempDST = %d", nitzTempDST);
    }
    else
    {
        g_nitz_cntx.DSTP = MMI_FALSE;
        nitzTempDST = 0;
    }
    
    /* Check if time zone from NITZ is valid */
    error = mmi_wc_set_home_city_from_nitz(nitzTempTZ, MMI_WC_CHECK_HOME_CITY);            
    if (error == -1)
    {
        g_nitz_cntx.isValidTZ = MMI_FALSE;
    }
    else
    {
        g_nitz_cntx.isValidTZ = MMI_TRUE;
    }
#endif

    if (msgReq->short_nw_nameP)
    {
        updateShortNW = mmi_nitz_get_nw_name(
                            msgReq->short_nw_name_dcs,
                            msgReq->short_nw_name_len,
                            (BOOL) msgReq->short_nw_name_add_ci,
                            (S8*) g_nitz_cntx.NWShortName,
                            (S8*) msgReq->short_nw_name);
        PRINT_INFORMATION("NITZ: NITZHandler:updateShortNW = %d", updateShortNW);
    }
    else    /* no time information, return */
    {
        memset(g_nitz_cntx.NWShortName, 0, MAX_NW_LEN * ENCODING_LENGTH);
        msgReq->short_nw_name_len = 0;
    }

    if ((msgReq->short_nw_nameP == 0 || msgReq->short_nw_name_len == 0) && msgReq->full_nw_nameP)
    {
        updateFullNW = mmi_nitz_get_nw_name(
                        msgReq->full_nw_name_dcs,
                        msgReq->full_nw_name_len,
                        (BOOL) msgReq->full_nw_name_add_ci,
                        (S8*) g_nitz_cntx.NWFullName,
                        (S8*) msgReq->full_nw_name);
        PRINT_INFORMATION("NITZ: NITZHandler:updateFullNW = %d", updateFullNW);
    }
    else
    {
        memset(g_nitz_cntx.NWFullName, 0, MAX_NW_LEN * ENCODING_LENGTH);
        msgReq->full_nw_name_len = 0;
    }
    
    DTGetRTCTime(&g_nitz_cntx.RecvTime);
    PRINT_INFORMATION("NITZ: RecvTime:RecvTime.nHour = %d", g_nitz_cntx.RecvTime.nHour);
    PRINT_INFORMATION("NITZ: RecvTime:RecvTime.nMin = %d", g_nitz_cntx.RecvTime.nMin);
    PRINT_INFORMATION("NITZ: RecvTime:RecvTime.nSec = %d", g_nitz_cntx.RecvTime.nSec);
        
    /* if the nitz does not include information we support, return directly */
    if (!mmi_nitz_check_dt()
#ifdef __MMI_NITZ_TZ_SUPPORT__
        && !mmi_nitz_check_tz()
#endif 
        )
    {
        /* if short name matched, it means short name has been displayed in idle screen */
        if (updateShortNW == MMI_FALSE && updateFullNW == MMI_FALSE)
        {			
             PRINT_INFORMATION("NITZ: updateShortNW = %d", updateShortNW);
             PRINT_INFORMATION("NITZ: updateFullNW = %d", updateFullNW);
             PRINT_INFORMATION("NITZ: return 1");
            return;
        }        
        else if (msgReq->short_nw_name_len == 0 && mmi_ucs2cmp((S8*)DeaultNWName, (S8*) g_nitz_cntx.NWFullName) == 0)
        {
            PRINT_INFORMATION("NITZ: msgReq->short_nw_name_len = %d", msgReq->short_nw_name_len);
             PRINT_INFORMATION("NITZ: DeaultNWName = %s", DeaultNWName);
             PRINT_INFORMATION("NITZ: g_nitz_cntx.NWFullName = %s", g_nitz_cntx.NWFullName);
             PRINT_INFORMATION("NITZ: return 2");
            return;
        }
        else
    	{
    		 PRINT_INFORMATION("NITZ: updateShortNW = %d", updateShortNW);
             PRINT_INFORMATION("NITZ: updateFullNW = %d", updateFullNW);
             PRINT_INFORMATION("NITZ: return 3");
    		return;
    	}
    }

    PRINT_INFORMATION("NITZ: display popup");
    g_nitz_cntx.IsNITZPending = MMI_TRUE;
    if (g_idle_context.IsOnIdleScreen)
    {
		EntryIdleScreen();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_get_nw_name
 * DESCRIPTION
 *  This function is used to get NITZ network name.
 * PARAMETERS
 *  dcs         [IN]        
 *  len         [IN]        
 *  add_ci      [IN]        
 *  dstStr      [?]         
 *  srcStr      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_nitz_get_nw_name(U8 dcs, U8 len, BOOL add_ci, S8 *dstStr, S8 *srcStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *nwStr = NULL, *tmpStr, *tempStr2;
    U8 count = 0;
    U16 nwStrLen = 0, srcStr_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("NITZ: mmi_nitz_get_nw_name");
    if (len == 0)
    {
		if (mmi_ucs2strlen((S8*)dstStr) > 0)
        {
            memset(dstStr, 0, MAX_NW_LEN * ENCODING_LENGTH);
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }


    PRINT_INFORMATION("NITZ: mmi_nitz_get_nw_name, len!=0");
    switch (dcs)
    {
        case SMSAL_DEFAULT_DCS:
            srcStr_len = strlen(srcStr);
            if (srcStr_len < MAX_NW_LEN)
            {
                nwStr = (U8*)CovertStringForPlatform((U8*)srcStr, (U16)srcStr_len, (U8)SMSAL_DEFAULT_DCS, (U16*)&nwStrLen);
            }
            else
            {
                return MMI_FALSE;
            }
            break;
        case SMSAL_UCS2_DCS:
            srcStr_len = mmi_ucs2strlen(srcStr);
            if (srcStr_len < MAX_NW_LEN)
            {
                memcpy(nwStr, srcStr, srcStr_len * ENCODING_LENGTH);
            }
            else
            {
                return MMI_FALSE;
            }
            
        default:
            break;
    }
    g_nitz_cntx.AddCI = add_ci;

    /* compare PLMN name */
    tmpStr = (U8*)dstStr;
    tempStr2 = nwStr;
    while (count < MAX_NW_LEN)
    {
        count++;
        if ((*tmpStr == *tempStr2) && (*(tmpStr + 1) == *(tempStr2 + 1)))
        {
            tmpStr += 2;
            tempStr2 += 2;
        }
        else
        {
            break;
        }
    }   /* End of while */

    if (count < MAX_NW_LEN)
    {
        memcpy(dstStr, nwStr, MAX_NW_LEN * ENCODING_LENGTH);
        OslMfree(nwStr);
        return MMI_TRUE;
    }
    else
    {
        OslMfree(nwStr);
        return MMI_FALSE;
    }

}

/*****************************************************************************
 * FUNCTION
 *  EntryNitzScreen
 * DESCRIPTION
 *  Show the NITZ chnage in time popup,
 *  if NITZ happend and control is on the idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNitzScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_NITZ, ExitNitzScreen, NULL, NULL);

    ClearKeyEvents();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_NITZ);

    NITZMessageString();
    if (g_keylock_context.gKeyPadLockFlag == 0)
    {

        /* start the back light */
        TurnOnBacklight(1);

        ShowCategory7Screen(
            CHANGE_TIME_CAPTION,
            CHANGE_TIME_IMAGE,
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (U8*) g_nitz_cntx.Message,
            guiBuffer);
        playRequestedTone(GENERAL_TONE);
        SetLeftSoftkeyFunction(NITZAccept, KEY_EVENT_UP);
        SetRightSoftkeyFunction(NITZIgnore, KEY_EVENT_UP);
        SetKeyHandler(NITZIgnore, KEY_END, KEY_EVENT_DOWN);

    }
    else
    {
        ShowCategory141Screen(
            0,
            0,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (U8*) g_nitz_cntx.Message,
            0,
            NULL);
        OslMfree(g_nitz_cntx.Message);
        g_nitz_cntx.Message = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitNitzScreen
 * DESCRIPTION
 *  Exit function of NITZ screen, free memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitNitzScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_nitz_cntx.Message != NULL)
    {
        OslMfree(g_nitz_cntx.Message);
        g_nitz_cntx.Message = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  NITZIgnore
 * DESCRIPTION
 *  RSK handler of NITZ screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NITZIgnore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_nitz_cntx.IsNITZPending = FALSE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  NITZAccept
 * DESCRIPTION
 *  This API calls on pressing OK on NITZ indication screen.
 *  This API fills the time and date set screen and passes control to the same screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NITZAccept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime;
    MYTIME incTime;
    nitz_nw_name_struct nw_name; 
    S16 error;
#ifdef __MMI_NITZ_TZ_SUPPORT__
    MYTIME resultTime;
    FLOAT nitz_tz, diff_tz;    
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&currTime);
    memset(&nw_name, 0, sizeof(nitz_nw_name_struct));

    if (mmi_dt_is_valid(&g_nitz_cntx.NITZTime))
    {
        g_nitz_cntx.NITZTimeZone = nitzTempTZ;

	    memset(&incTime, 0, sizeof(MYTIME));
	    GetTimeDifference(&currTime, &g_nitz_cntx.RecvTime, &incTime);
	
	    IncrementTime(g_nitz_cntx.NITZTime, incTime, &(g_nitz_cntx.NITZTime));
    #ifdef __MMI_NITZ_TZ_SUPPORT__
        g_nitz_cntx.NITZDST = nitzTempDST;
    
        /* set time zone */        
        /* If time zone is invalid, set time zone as GMT 0 */
        if (g_nitz_cntx.isValidTZ == MMI_FALSE)
        {
            mmi_wc_set_home_city_from_nitz(0, MMI_WC_SET_HOME_CITY);
        }
        else
        {
            mmi_wc_set_home_city_from_nitz((S16) (g_nitz_cntx.NITZTimeZone - (g_nitz_cntx.NITZDST * 4)), MMI_WC_SET_HOME_CITY);
        }
        mmi_dt_set_dst((U8) g_nitz_cntx.NITZDST);
    #endif /* __MMI_NITZ_TZ_SUPPORT__ */ 
	
        SetProtocolEventHandler(mmi_nitz_time_res_rsp, HW_SET_TIME_REQ_SUCCESS);
        mmi_dt_set_rtc_dt(&g_nitz_cntx.NITZTime);
    }
#ifdef __MMI_NITZ_TZ_SUPPORT__
    else if (mmi_nitz_check_tz())
    {
        nitz_tz = (FLOAT) nitzTempTZ;
        nitz_tz /= 4;

        diff_tz = nitz_tz - nitzTempDST - g_nitz_cntx.NITZTimeZone/4;            

        /* turn DST off */
        if (applib_dt_is_dst_enabled() == MMI_TRUE && nitzTempDST == 0)
        {
            diff_tz -= nitzTempDST;
        }
        else if (applib_dt_is_dst_enabled() == MMI_FALSE && nitzTempDST == 1)
        {
            diff_tz += nitzTempDST;
        }   

        applib_dt_utc_to_rtc(diff_tz, (applib_time_struct*) & currTime, (applib_time_struct*) &resultTime);
        memcpy(&(g_nitz_cntx.NITZTime), &resultTime, sizeof(MYTIME));

        /* set time zone */
        g_nitz_cntx.NITZTimeZone = nitzTempTZ;
        g_nitz_cntx.NITZDST = nitzTempDST;
        
        /* If time zone is invalid, set time zone as GMT 0 */
        if (g_nitz_cntx.isValidTZ == MMI_FALSE)
        {
            mmi_wc_set_home_city_from_nitz(0, MMI_WC_SET_HOME_CITY);
        }
        else
        {
            mmi_wc_set_home_city_from_nitz((S16) (g_nitz_cntx.NITZTimeZone - (g_nitz_cntx.NITZDST * 4)), MMI_WC_SET_HOME_CITY);
        }
        mmi_dt_set_dst((U8) g_nitz_cntx.NITZDST);
        mmi_dt_set_rtc_dt(&g_nitz_cntx.NITZTime);
                     
    }
#endif /* __MMI_NITZ_TZ_SUPPORT__ */ 
    if (strlen((S8*) g_nitz_cntx.NWShortName) != 0)
    {
        memcpy(&(nw_name.plmn),gPLMN, MAX_PLMN_LEN_MMI);
        memcpy(&(nw_name.name), &g_nitz_cntx.NWShortName, MAX_NW_LEN *ENCODING_LENGTH);
        nw_name.add_ci = (U8) g_nitz_cntx.AddCI;
        WriteRecord(NVRAM_EF_NITZ_NW_NAME_LID, 1, &nw_name, sizeof(nitz_nw_name_struct), &error);
        
        mmi_idle_update_opname_from_nitz();
    }
    else if (strlen((S8*) g_nitz_cntx.NWFullName) != 0)
    {
        memcpy(&(nw_name.plmn),gPLMN, MAX_PLMN_LEN_MMI);    
        memcpy(&nw_name.name, &g_nitz_cntx.NWFullName, MAX_NW_LEN *ENCODING_LENGTH);
        nw_name.add_ci = (U8) g_nitz_cntx.AddCI;
        WriteRecord(NVRAM_EF_NITZ_NW_NAME_LID, 1, &nw_name, sizeof(nitz_nw_name_struct), &error);
        
        mmi_idle_update_opname_from_nitz();
    }
    else
    {
        memset(&(nw_name.plmn),0, MAX_PLMN_LEN_MMI);    
        memset(&nw_name.name, 0, MAX_NW_LEN *ENCODING_LENGTH);
        nw_name.add_ci = 0;
        WriteRecord(NVRAM_EF_NITZ_NW_NAME_LID, 1, &nw_name, sizeof(nitz_nw_name_struct), &error);
        
        mmi_idle_update_opname_from_nitz();
    }
    g_nitz_cntx.IsNITZPending = FALSE;
	GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_get_nitz_nw_name
 * DESCRIPTION
 *  This API read nitz netowrk name information from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nitz_get_nitz_nw_name(U8* plmn, U8* nwname, U8 len, BOOL* add_ci)
{
    nitz_nw_name_struct nw_name; 
    S16 error;
    
    ReadRecord(NVRAM_EF_NITZ_NW_NAME_LID, 1, &nw_name, sizeof(nitz_nw_name_struct), &error);

    if (plmn != NULL)
    {
        memcpy(plmn, nw_name.plmn, MAX_PLMN_LEN_MMI);
    }

    if (nwname != NULL)
    {
		mmi_ucs2ncpy((S8*) nwname, (S8*)nw_name.name, len);
    }

    if (add_ci != NULL)
    {
        memcpy(add_ci, &(nw_name.add_ci), sizeof(U8));    
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_write_nw_name_to_nvram
 * DESCRIPTION
 *  Write SIM2 network name into NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nitz_write_nw_name_to_nvram(U8 sim_type, nitz_nw_name_struct *nw_name)
{    
    S16 error;    
    
    WriteRecord(NVRAM_EF_NITZ_NW_NAME_LID, sim_type, nw_name, sizeof(nitz_nw_name_struct), &error);
}

#ifdef __MMI_DUAL_SIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_get_nitz_nw_name
 * DESCRIPTION
 *  This API read nitz netowrk name information from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nitz_get_nitz_nw_name_sim2(U8* plmn, U8* nwname, U8 len, BOOL* add_ci)
{
    nitz_nw_name_struct nw_name; 
    S16 error;
    
    ReadRecord(NVRAM_EF_NITZ_NW_NAME_LID, 2, &nw_name, sizeof(nitz_nw_name_struct), &error);

    if (plmn != NULL)
    {
        memcpy(plmn, nw_name.plmn, MAX_PLMN_LEN_MMI);
    }

    if (nwname != NULL)
    {
		mmi_ucs2ncpy((S8*) nwname, (S8*)nw_name.name, len);
    }

    if (add_ci != NULL)
    {
        memcpy(add_ci, &(nw_name.add_ci), sizeof(U8));    
    }
}
#endif /*__MMI_DUAL_SIM__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_check_dt
 * DESCRIPTION
 *  
 *  This function is used to check if the date/time need to be updated from NITZ.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_nitz_check_dt()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME refTime1, refTime2, incTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&incTime, 0, sizeof(MYTIME));
    memset(&refTime1, 0, sizeof(MYTIME));
    memset(&refTime2, 0, sizeof(MYTIME));

    incTime.nMin = NITZ_MAX_ALLOW_DIFF;

    IncrementTime(g_nitz_cntx.RecvTime, incTime, &refTime1);
    DecrementTime(g_nitz_cntx.RecvTime, incTime, &refTime2);

    PRINT_INFORMATION("NITZ: mmi_nitz_check_dt:refTime1.nHour = %d", refTime1.nHour);
    PRINT_INFORMATION("NITZ: mmi_nitz_check_dt:refTime1.nMin = %d", refTime1.nMin);
    PRINT_INFORMATION("NITZ: mmi_nitz_check_dt:refTime1.nSec = %d", refTime1.nSec);

    PRINT_INFORMATION("NITZ: mmi_nitz_check_dt:refTime2.nHour = %d", refTime2.nHour);
    PRINT_INFORMATION("NITZ: mmi_nitz_check_dt:refTime2.nMin = %d", refTime2.nMin);
    PRINT_INFORMATION("NITZ: mmi_nitz_check_dt:refTime2.nSec = %d", refTime2.nSec);
    if (!mmi_dt_is_valid(&g_nitz_cntx.NITZTime))
    {
        PRINT_INFORMATION("NITZ: mmi_nitz_check_dt: return 1");
        return MMI_FALSE;
    }
	else if ((CompareTime(g_nitz_cntx.NITZTime, refTime1, NULL) == TIME_LESS) &&
             (CompareTime(g_nitz_cntx.NITZTime, refTime2, NULL) == TIME_GREATER))
    {   
        /* Check if time zone field in date-time is changed */
        if (nitzTempTZ != g_nitz_cntx.NITZTimeZone && g_nitz_cntx.isValidTZ != MMI_FALSE)
        {            
            PRINT_INFORMATION("NITZ: mmi_nitz_check_dt: return 2-2");        
            return MMI_TRUE;
        }
        else
        {
            PRINT_INFORMATION("NITZ: mmi_nitz_check_dt: return 2-1");
            return MMI_FALSE;            
        }
    }
#ifdef __MMI_CHECK_DUPLICATED_NITZ__
    else if (nitzTempTZ == g_nitz_cntx.NITZTimeZone)
    {
        PRINT_INFORMATION("NITZ: mmi_nitz_check_dt: return 3");
        return MMI_FALSE;
    }
#endif    
    else
    {
        PRINT_INFORMATION("NITZ: mmi_nitz_check_dt: return 4");
        return MMI_TRUE;
    }
}
#ifdef __MMI_NITZ_TZ_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_check_tz
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_nitz_check_tz(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check time zone */
        PRINT_INFORMATION("NITZ: mmi_nitz_check_tz");
    if (g_nitz_cntx.TimeZoneP == MMI_TRUE)
    {
        PRINT_INFORMATION("NITZ: mmi_nitz_check_tz: g_nitz_cntx.NITZTimeZone = %d", g_nitz_cntx.NITZTimeZone);
        PRINT_INFORMATION("NITZ: mmi_nitz_check_tz: nitzTempTZ = %d", nitzTempTZ);
        PRINT_INFORMATION("NITZ: mmi_nitz_check_tz: g_nitz_cntx.NITZDST = %d", g_nitz_cntx.NITZDST);
        PRINT_INFORMATION("NITZ: mmi_nitz_check_tz: nitzTempDST = %d", nitzTempDST);
        /* init timezone */
        ReadValue(NVRAM_TIMEZONE, &(g_nitz_cntx.NITZTimeZone), DS_SHORT, &error);		    
        /* init dst */
        ReadValue(NVRAM_SETTING_DT_DST, &(g_nitz_cntx.NITZDST), DS_BYTE, &error);
        if ((g_nitz_cntx.NITZTimeZone + (nitzTempDST * 4)) != nitzTempTZ || nitzTempDST != g_nitz_cntx.NITZDST)
        {
            /* Check if time zone from NITZ is valid */
            if (g_nitz_cntx.isValidTZ == MMI_FALSE)
            {
                return MMI_FALSE;
            }
            else
            {
                return MMI_TRUE;
            }
        }
    }
    else if(g_nitz_cntx.DSTP == MMI_TRUE)
    {
        /* init dst */
        ReadValue(NVRAM_SETTING_DT_DST, &(g_nitz_cntx.NITZDST), DS_BYTE, &error);
        if (nitzTempDST != g_nitz_cntx.NITZDST)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}
#endif /* __MMI_NITZ_TZ_SUPPORT__ */ 

/*****************************************************************************
 * FUNCTION
 *  NITZMessageString
 * DESCRIPTION
 *  Return the new time zone string, need to be display using in IDLE screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8 *NITZMessageString(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *tmpStr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_nitz_cntx.Message == NULL)
    {
        g_nitz_cntx.Message = OslMalloc(NITZ_NOTIFY_LENGTH);
    }

    tmpStr = GetString(NITZTIMECHANGESTR);

    mmi_ucs2ncpy((S8*) g_nitz_cntx.Message, tmpStr, mmi_ucs2strlen((S8*) tmpStr));

    return g_nitz_cntx.Message;
}


/*****************************************************************************
 * FUNCTION
 *  NITZTimeZoneString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timezone        [IN]        
 *  string          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void NITZTimeZoneString(S16 timezone, S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tmpBuff[NITZ_TIME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (timezone < 0)
    {
        timezone = 0 - timezone;
        sprintf(tmpBuff, "-%02d:%02d", (timezone / 4), (timezone % 4) * 15);
    }
    else
    {
        sprintf(tmpBuff, "+%02d:%02d", (timezone / 4), (timezone % 4) * 15);
    }

    mmi_asc_to_ucs2(string, tmpBuff);
}


/*****************************************************************************
 * FUNCTION
 *  NITZConvertTime
 * DESCRIPTION
 *  Utility function require by NITZ to convert BCD Date to decimal.
 * PARAMETERS
 *  time        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 NITZConvertTime(U8 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tmp1 = 0, tmp2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp1 = time & NITZ_HIGH_BIT;
    tmp1 = tmp1 >> 4;
    tmp2 = time & NITZ_LOW_BIT;
    return tmp2 * 10 + tmp1;
}


/*****************************************************************************
 * FUNCTION
 *  NITZGetTimeZone
 * DESCRIPTION
 *  Utility function require by NITZ to convert BCD Date to decimal.
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 NITZGetTimeZone(U8 t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tmp;
    U8 NegFlag;
    S16 result;
    U8 timezone = t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp = (t & NITZ_HIGH_BIT) >> 4;

    if (t & NITZ_SIGN_BIT)  /* negative */
    {
        NegFlag = TRUE;
    }
    else    /* positive */
    {
        NegFlag = FALSE;
    }

    timezone &= NITZ_TZ_BIT;
    timezone = timezone * 10 + tmp;

    result = (S16) timezone;

    if (NegFlag)
    {
        result = 0 - result;
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_time_res_rsp
 * DESCRIPTION
 *  Response of set RTC request.
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/   
void mmi_nitz_time_res_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    RESULTSTRUCT *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (RESULTSTRUCT*) (info);

    if (resp->result == 1)
    {
    #ifdef __MTK_TARGET__
        gclockData.rtc_year = g_nitz_cntx.NITZTime.nYear- YEARFORMATE;
        gclockData.rtc_mon = g_nitz_cntx.NITZTime.nMonth;
        gclockData.rtc_day = g_nitz_cntx.NITZTime.nDay;
        gclockData.rtc_hour = g_nitz_cntx.NITZTime.nHour;
        gclockData.rtc_min = g_nitz_cntx.NITZTime.nMin;
        mmi_dt_check_rtc_time();
    #else /* __MTK_TARGET__ */ 
        MyTime.nHour = g_nitz_cntx.NITZTime.nHour;
        MyTime.nMin = g_nitz_cntx.NITZTime.nMin;
        MyTime.nYear = g_nitz_cntx.NITZTime.nYear;
        MyTime.nMonth = g_nitz_cntx.NITZTime.nMonth;
        MyTime.nDay = g_nitz_cntx.NITZTime.nDay;
        DateTimerProc();
    #endif /* __MTK_TARGET__ */ 

    
        update_mainlcd_dt_display();
        update_sublcd_dt_display();

        AlmReInitialize();

    }
}


#endif /* defined(__MMI_NITZ__) */ 

#endif /* _MMI_NITZ_C */ // #ifndef _MMI_NITZ_C
