/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * CLI_Icon.c
 *
 * Project:
 * --------
 * Nokia Smart Messaging
 *
 * Description:
 * ------------
 * This file implements Nokia Smart CLI Icon.
 *
 * Date :
 * ------
 * 18th May 2005  
 *
 * Author:  
 * --------
 * -------
 * 
 *****************************************************************************/

/**************** START :  INCLUDE SECTION *************************/
#include "MMI_include.h"

#ifdef __MMI_CLI_ICON__

#include "ems.h"

#include "CLI_Icon.h"

/**************** END   :  INCLUDE SECTION *************************/

/*************** START  :  DEFINE SECTION *************************/

#define CLI_ICON_HEADER_SIZE  (sizeof(CLI_ICON_HEADER_STRUCT))

/**************** END   :  DEFINE SECTION *************************/

/**************** START :  TYPEDEFS SECTION *************************/
/**************** END   :  TYPEDEFS SECTION ***************************/

/**************** START :  GLOBAL VARIABLES *************************/

extern U8 gPictureMessageError;

extern U16 RemoveZerosInBetween(U8 *pOutBuffer, U8 *pInBuffer, U16 size);
extern EMSData *GetEMSDataForView(EMSData **p, U8 force);
extern void EntryNsmPicturemsg(void);

/**************** END   :  GLOBAL VARIABLES *************************/

/**************** START :  LOCAL FUNCTIONS DECLARATION *************************/

static void mmi_cli_icon_get_header_info(CLI_ICON_HEADER_STRUCT *ota_bmp_header, OTA_DATA_STRUCT *cli_icon_ota_data);

/**************** END   :  LOCAL FUNCTIONS DECLARATION *************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_cli_icon_parse_ota_data
 * DESCRIPTION
 *  Parse CLI Icon OTA data into bmp header and bmp buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_cli_icon_parse_ota_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *pEms = NULL;
    OTA_DATA_STRUCT cli_icon_ota_data = {NULL, 0};
    CLI_ICON_HEADER_STRUCT cli_icon_header = {0};
    U32 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetEMSDataForView(&pEms, 0);

    cli_icon_ota_data.OTA_data = (U8*) OslMalloc((pEms->textLength >> 1) + 1);
    ASSERT(cli_icon_ota_data.OTA_data != NULL);
    memset(cli_icon_ota_data.OTA_data, 0x00, ((pEms->textLength >> 1) + 1));

    temp = RemoveZerosInBetween(cli_icon_ota_data.OTA_data, pEms->textBuffer, pEms->textLength);

    /* Get OTA ver and BMP header info */
    mmi_cli_icon_get_header_info(&cli_icon_header, &cli_icon_ota_data);

    /* Get BMP Image data */
    mmi_nsm_create_bmp_buffer(&cli_icon_ota_data, &(cli_icon_header.cli_icon_ota_bmp_header));

    gPictureMessageError = 0;   /* Hack : MMI_NSM_PIC_SUCCESS */

    if (cli_icon_ota_data.OTA_data != NULL)
    {
        OslMfree(cli_icon_ota_data.OTA_data);
    }

    /* Hack : CLI Icon is treated as picture message */
    EntryNsmPicturemsg();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cli_icon_get_header_info
 * DESCRIPTION
 *  Get header info for bmp image
 * PARAMETERS
 *  ota_bmp_header          [IN]        BMP header structure
 *  cli_icon_ota_data       [IN]        Operator logo OTA data structure
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cli_icon_get_header_info(CLI_ICON_HEADER_STRUCT *ota_bmp_header, OTA_DATA_STRUCT *cli_icon_ota_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get OTA version */
    mmi_nsm_get_ver_no(&(ota_bmp_header->cli_icon_ota_ver), cli_icon_ota_data);

    /* Get BMP Image header info */
    mmi_nsm_get_ota_bmp_header(&(ota_bmp_header->cli_icon_ota_bmp_header), cli_icon_ota_data);
}

#endif /* __MMI_CLI_ICON__ */ 

