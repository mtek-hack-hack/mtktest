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
 * CommonNSM.h
 *
 * Project:
 * --------
 * Nokia Smart Messaging
 *
 * Description:
 * ------------
 * This file defines global declaration for Nokia Smart Operator logo and CLI Icon.
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
#ifndef __MMI_NSM_COMMON_DCL_H__
#define __MMI_NSM_COMMON_DCL_H__

#if defined(__MMI_OPERATOR_LOGO__) || defined(__MMI_CLI_ICON__)

/**************** START : INCLUDE SECTION *************************/
#include "MMIDataType.h"
#include "picturemsg.h"
#include "customer_ps_inc.h"
/**************** END : INCLUDE SECTION ***************************/

/**************** START : DEFINE SECTION*************************/
#define PIC_BUFF_MAX_LEN         (640)  /* 72*28 = 252 => 252*2 + Header = 518 = 640 */
#define TEXT_BUFF_PADDING        (16)
#define MAX_TEXT_LEN          (((MMI_SMS_MAX_MSG_SEG-3)>5)? (5*120):((MMI_SMS_MAX_MSG_SEG-3)*120))
#define MAX_NOKIA_HEADER_SIZE    32
#define MAX_PICTEXT_BUFF_SIZE    (MAX_TEXT_LEN*ENCODING_LENGTH) /* 120 * segments * 2 */
#define MAX_DATA_SIZE            (PIC_BUFF_MAX_LEN+MAX_PICTEXT_BUFF_SIZE+TEXT_BUFF_PADDING)

/**************** END : DEFINE SECTION*************************/

/**************** START : TYPEDEFS SECTION *************************/

typedef struct
{
    BOOL is_ver_present;
    U8 version_no;
} OTA_VERSION_STRUCT;

/* 
 * Sequence as appear in actual data : 
 * <Info-feild> <width> <Height> <Depth> 
 */
typedef struct
{
    U16 ota_image_width;    /* In pixel */
    U16 ota_image_height;   /* In pixel */
    U8 color_depth;         /* 0x01 Black & white only */
    U8 info_feild;
} OTA_BMP_HEADER_STRUCT;

typedef struct
{
    U8 *OTA_data;
    U8 curr_index;
} OTA_DATA_STRUCT;

/**************** End : TYPEDEFS SECTION ***************************/

/**************** START : GLOBAL FUNCTION DECLARATION *************************/

extern void mmi_nsm_get_ver_no(OTA_VERSION_STRUCT *version, OTA_DATA_STRUCT *ota);
extern void mmi_nsm_get_ota_bmp_header(OTA_BMP_HEADER_STRUCT *ota_bmp_header, OTA_DATA_STRUCT *ota);
extern void mmi_nsm_create_bmp_buffer(OTA_DATA_STRUCT *ota, OTA_BMP_HEADER_STRUCT *ota_bmp_header);

/**************** End : GLOBAL FUNCTION DECLARATION *************************/

#endif /* defined(__MMI_OPERATOR_LOGO__) || defined(__MMI_CLI_ICON__) */ 

#endif /* __MMI_NSM_COMMON_DCL_H__ */ 

