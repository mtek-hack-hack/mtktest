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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

/*! \file mea_env.h
 *  Integration functions.
 */

#ifndef _MEA_ENV_H_
#define _MEA_ENV_H_

/*!\enum MeaPhLaunchResult
 */
typedef enum
{
    MEA_PB_LAUNCH_RESULT_OK,
    MEA_PB_LAUNCH_BUSY,
    MEA_PB_LAUNCH_RESULT_ERROR
}MeaPbLaunchResult;

/*!\enum MeaPhLookupResult
 *  \brief Result codes for the MEAc_pbLaunchRsp connector call.
 */
typedef enum
{
    MEA_PB_LOOKUP_RESULT_OK,
    MEA_PB_LOOKUP_RESULT_NO_HIT,
    MEA_PB_LOOKUP_RESULT_ERROR
}MeaPbLookupNameResult;

/*!\brief MeaPhAddrType
 * \brief Possible address types for the phone book
 */
typedef enum
{
    MEA_PB_TYPE_PLMN        = 0x01,   /*!< The address is a phone no */
    MEA_PB_TYPE_EMAIL       = 0x02    /*!< The address is an email address */
}MeaPbAddrType;

/******************************************************************************
 * Data-types
 *****************************************************************************/

/*! \struct MeaPhoneBookItem
 *  \brief Data-structure to provide phone book entries between the MEA and the
 *         external phone book.
 */
typedef struct MeaPbItemSt
{
    MeaPbAddrType   type;           /*!< The type of item, e.g., phone no */
    char            *name;          /*!< The name of the contact, e.g., Homer 
                                     Simpson, as a '\0' terminated UTF-8 string
                                     */
    char            *addr;          /*!< The value is dependent on the size, 
                                     e.g., if the type is; 
                                     MEA_PHONE_BOOK_TYPE_PHONE_NO, then the 
                                     value has the type: "+4670000000" 
                                     Character encoding for EMAIL and PLMN
                                     i US-ASCII with '\0' termination */
    struct MeaPbItemSt *next;       /*!< The next entry in the list or NULL */
}MeaPbItem;

/******************************************************************************
 * Prototypes
 *****************************************************************************/

void MEAc_run(void);
void MEAc_start(void);
#ifdef WAP_SUPPORT
void MEAc_startWithGeneralInserted(char *subject, char *text, MSF_BOOL isTruncated, char *addr, char *file_path);
void MEAc_startWithContentInserted(char* contentSource);
void MEAc_startWithTextInserted(char *subject, char *text, MSF_BOOL isTruncated);
#endif /* WAP_SUPPORT */
int  MEAc_wantsToRun(void);
void MEAc_kill(void);

/*! \brief This function is called as a result to the MEAa_pbLaunch adaptor
 *         call.
 *
 * A call to this function launches the MMI for the phone book. The result is
 * provided as call to the MEA
 *
 * \param result The result of the operation, see #MeaPbLaunchResult
 * \param id An identity provided in the call to #MEAa_pbLaunch
 * \param items The response data (see #MeaPhoneBookItem) or NULL if no data is
 *              provided
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL MEAc_pbLaunchRsp(MSF_UINT16 result, MSF_UINT16 id, MeaPbItem *items);

/*! \brief The response from the MEAa_pbLookupName adaptor
 *
 * Note that only one item is returned from the phone book even if there are 
 * more than one matches for the address. In this case the first match is 
 * returned.
 *
 * \param result The result of the operation, see #MeaPbLookupNameResult
 * \param instanceId An identity provided in the call to #MEAa_pbLookupName
 * \param item The response data (see #MeaPhoneBookItem) or NULL if no data is
 *             provided
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL MEAc_pbLookupNameRsp(MSF_UINT16 result, MSF_UINT16 instanceId, 
    MeaPbItem *item);

#endif


