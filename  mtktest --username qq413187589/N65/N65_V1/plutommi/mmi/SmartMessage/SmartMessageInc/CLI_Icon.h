/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * CLI_Icon.h
 *
 * Project:
 * --------
 * Nokia Smart Messaging
 *
 * Description:
 * ------------
 * This file defines global declaration for CLI Icon.
 *
 * Date :
 * ------
 * 18th May 2005  
 *
 * Author:  
 * --------
 * -------
 *
 ********************************************************************************/

#ifndef _MMI_CLI_ICON_H_
#define _MMI_CLI_ICON_H_

#ifdef __MMI_CLI_ICON__

/**************** Start : INCLUDE SECTION *************************/
#include "CommonNSM.h"
/**************** End   : INCLUDE SECTION *************************/

/**************** Start : DEFINE SECTION *************************/
/**************** End   : DEFINE SECTION *************************/

/**************** Start : TYPEDEFS SECTION *************************/

/*
 * Sequence as appear in actual data :
 * <ver><ota_header><OTA_DATA>
 */
typedef struct
{
    OTA_BMP_HEADER_STRUCT cli_icon_ota_bmp_header;  /* <ota_header> */
    OTA_VERSION_STRUCT cli_icon_ota_ver;            /* <ver> : CLI Icon version number */

    /* 
     * <OTA_DATA> is stored in local buffer as need 
     * only for conversion to BMP.<OTA_DATA> is converted 
     * to BMP format and Stored in global gNSMBuffer 
     */
} CLI_ICON_HEADER_STRUCT;

/**************** End   : TYPEDEFS SECTION *************************/

/**************** Start :  GLOBAL FUNCTION DECLARATION *************************/
extern void mmi_cli_icon_parse_ota_data(void);

/**************** End   :  GLOBAL FUNCTION DECLARATION *************************/

#endif /* __MMI_CLI_ICON__ */ /* _MMI_CLI_ICON__ */

#endif /* _MMI_CLI_ICON_H_ */ 

