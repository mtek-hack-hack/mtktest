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
 * Operator_logo.c
 *
 * Project:
 * --------
 * Nokia Smart Messaging
 *
 * Description:
 * ------------
 * This file implements Nokia Smart Operator logo.
 *
 * Date :
 * ------
 * 9th May 2005   
 *
 * Author:  
 * --------
 * -------
 * 
 *****************************************************************************/

/**************** Start : INCLUDE SECTION *************************/

#include "MMI_include.h"

#ifdef __MMI_OPERATOR_LOGO__
#include "ems.h"

#include "Operator_logo.h"

/**************** End : INCLUDE SECTION ***************************/

/**************** Start : DEFINE SECTION*************************/

/**************** End : DEFINE SECTION***************************/

/**************** Start : TYPEDEFS SECTION *************************/
/**************** End : TYPEDEFS SECTION ***************************/

/**************** Start:GLOBAL VARIABLES *************************/
extern U8 gPictureMessageError;

extern U16 RemoveZerosInBetween(U8 *pOutBuffer, U8 *pInBuffer, U16 size);
extern EMSData *GetEMSDataForView(EMSData **p, U8 force);
extern void EntryNsmPicturemsg(void);

/**************** End : GLOBAL VARIABLES *************************/

/**************** Start:LOCAL FUNCTIONS DECLARATION *************************/

static void mmi_oplogo_get_header_info(OP_LOGO_HEADER_STRUCT *ota_bmp_header, OTA_DATA_STRUCT *op_logo_ota_data);
static void mmi_op_logo_get_mcc(U16 *mcc, const BOOL ver_flag, OTA_DATA_STRUCT *op_logo_ota_data);
static void mmi_op_logo_get_mnc(U8 *mnc, OTA_DATA_STRUCT *op_logo_ota_data);
static void mmi_op_logo_skip_line_feed(OTA_DATA_STRUCT *op_logo_ota_data);

/**************** End : LOCAL FUNCTIONS DECLARATION *************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_op_logo_parse_ota_data
 * DESCRIPTION
 *  Parse operator Logo OTA data into bmp header and bmp buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_op_logo_parse_ota_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *pEms = NULL;
    OTA_DATA_STRUCT op_logo_ota_data = {NULL, 0};
    OP_LOGO_HEADER_STRUCT op_logo_header = {0};
    U32 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetEMSDataForView(&pEms, 0);

    op_logo_ota_data.OTA_data = (U8*) OslMalloc((pEms->textLength >> 1) + 1);
    ASSERT(op_logo_ota_data.OTA_data != NULL);
    memset(op_logo_ota_data.OTA_data, 0x00, ((pEms->textLength >> 1) + 1));

    temp = RemoveZerosInBetween(op_logo_ota_data.OTA_data, pEms->textBuffer, pEms->textLength);

    mmi_oplogo_get_header_info(&op_logo_header, &op_logo_ota_data);
    mmi_nsm_create_bmp_buffer(&op_logo_ota_data, &(op_logo_header.op_logo_ota_bmp_header));

    gPictureMessageError = 0;   /* Hack : MMI_NSM_PIC_SUCCESS */

    if (op_logo_ota_data.OTA_data != NULL)
    {
        OslMfree(op_logo_ota_data.OTA_data);
    }

    /* Hack : Operator logo is treated as picture message */
    EntryNsmPicturemsg();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_oplogo_get_header_info
 * DESCRIPTION
 *  Get header info for bmp image
 * PARAMETERS
 *  ota_bmp_header          [IN]        BMP header structure
 *  op_logo_ota_data        [IN]        Operator logo OTA data structure
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_oplogo_get_header_info(OP_LOGO_HEADER_STRUCT *ota_bmp_header, OTA_DATA_STRUCT *op_logo_ota_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_nsm_get_ver_no(&(ota_bmp_header->op_logo_ota_ver), op_logo_ota_data);

    mmi_op_logo_get_mcc(&(ota_bmp_header->mmc), ota_bmp_header->op_logo_ota_ver.is_ver_present, op_logo_ota_data);

    mmi_op_logo_get_mnc(&(ota_bmp_header->mnc), op_logo_ota_data);
    mmi_op_logo_skip_line_feed(op_logo_ota_data);   /* Skip only if <line-feed> character present */
    mmi_nsm_get_ota_bmp_header(&(ota_bmp_header->op_logo_ota_bmp_header), op_logo_ota_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op_logo_get_mcc
 * DESCRIPTION
 *  Get mcc number from OTA data
 * PARAMETERS
 *  mcc             [IN]        Mobile country code
 *  ver_flag        [IN]        Version flag
 *  ota             [IN]        OTA data structure
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_op_logo_get_mcc(U16 *mcc, const BOOL ver_flag, OTA_DATA_STRUCT *ota)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* 
     * MMC is in little endian BCD format filled with 0xf to make even bytes.
     * eg.   BCD little endian filled with 0xf: 42f4.
     *    Actual value in mcc : 244
     */
    U16 temp1 = 0;
    U16 temp2 = 0;
    U16 result = 0;

#if 0
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp1 = (ota->OTA_data[ota->curr_index] & 0x0F);
    temp2 = ((ota->OTA_data[ota->curr_index] >> 4) & 0x0F);
    result = ((temp1 * 10) + temp2);

    ota->curr_index += 1;

    result = ((result * 10) + (ota->OTA_data[ota->curr_index] & 0x0F));
    ota->curr_index += 1;

    *mcc = result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op_logo_get_mnc
 * DESCRIPTION
 *  Get mnc number from OTA data
 * PARAMETERS
 *  mnc     [IN]        Mobile network code
 *  ota     [IN]        OTA data structure
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_op_logo_get_mnc(U8 *mnc, OTA_DATA_STRUCT *ota)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * MNC is in little endian BCD format filled with 0xf to make even bytes.
     * eg.   BCD little endian filled with 0xf: 50.
     *    Actual value in mnc : 5
     */
    *mnc = ota->OTA_data[ota->curr_index];
    ota->curr_index += 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op_logo_skip_line_feed
 * DESCRIPTION
 *  Get OTA BMP header info
 * PARAMETERS
 *  ota     [IN]        Structure OTA data
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_op_logo_skip_line_feed(OTA_DATA_STRUCT *ota)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = ota->OTA_data[ota->curr_index];
    if (0x0a == temp)
    {
        ota->curr_index += 1;
    }
}

#endif /* __MMI_OPERATOR_LOGO__ */ 

