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
 * CommonNSM.c
 *
 * Project:
 * --------
 * Nokia Smart Messaging
 *
 * Description:
 * ------------
 * This file implements Common Function for Operator logo and CLI Icon.
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

#if defined (__MMI_OPERATOR_LOGO__) || defined(__MMI_CLI_ICON__)

#include "ems.h"
#include "CommonNSM.h"
#include "customer_ps_inc.h"
/**************** END   :  INCLUDE SECTION *************************/

/**************** START :  DEFINE SECTION *************************/
#define DEFAULT_OTA_VERSION         (0x30)
#define  MOD_BY_FOUR             (0X04)
#define BMP_HEADER_SIZE          (sizeof(BmpFileHeader_sturct)-2)
#define MMI_EXTRA_BMP_HEADER_SIZE   (6)
#define ONE_BYTE_SIZE            (8)
#define MAX_BMP_BUF_SIZE         (1024)

/**************** END   :  DEFINE SECTION *************************/

/**************** START :  TYPEDEFS SECTION *************************/
/**************** END   :  TYPEDEFS SECTION ***************************/

/**************** START :  GLOBAL VARIABLES *************************/
extern U8 gNSMBuffer[];
extern S8 g_pmsg_TextInMessage[MAX_PICTEXT_BUFF_SIZE + (TEXT_BUFF_PADDING)];

/**************** END   :  GLOBAL VARIABLES *************************/

/**************** START :  LOCAL FUNCTIONS DECLARATION *************************/
static void mmi_nsm_add_6extra_byte_for_mmi(BmpFileHeader_sturct *BmpHeader);
static void mmi_nsm_set_bmp_header_default_values(BmpFileHeader_sturct *BmpHeader);

/**************** END   :  LOCAL FUNCTIONS DECLARATION *************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_get_ver_no
 * DESCRIPTION
 *  Get version number from OTA data and convert to decimal
 * PARAMETERS
 *  ota_ver                 [?]         
 *  ota                     [IN]        OTA data structure
 *  op_logo_ota_ver(?)      [IN]        Version structure
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_nsm_get_ver_no(OTA_VERSION_STRUCT *ota_ver, OTA_DATA_STRUCT *ota)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set Operator Logo default version values */
    ota_ver->is_ver_present = FALSE;
    ota_ver->version_no = DEFAULT_OTA_VERSION;

    temp = ota->OTA_data[ota->curr_index];

    if (DEFAULT_OTA_VERSION == temp)
    {
        ota_ver->is_ver_present = TRUE;
        ota_ver->version_no = temp;
        ota->curr_index += 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_get_ota_bmp_header
 * DESCRIPTION
 *  Get OTA BMP header info
 * PARAMETERS
 *  ota_bmp_header      [IN]        BMP header structure
 *  ota                 [IN]        OTA data structure
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_nsm_get_ota_bmp_header(OTA_BMP_HEADER_STRUCT *ota_bmp_header, OTA_DATA_STRUCT *ota)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* <info-field> */
    ota_bmp_header->info_feild = ota->OTA_data[ota->curr_index];
    ota->curr_index += 1;

    /* <width> */
    ota_bmp_header->ota_image_width = ota->OTA_data[ota->curr_index];
    ota->curr_index += 1;

    /* <Height> */
    ota_bmp_header->ota_image_height = ota->OTA_data[ota->curr_index];
    ota->curr_index += 1;

    /* <color Depth> */
    ota_bmp_header->color_depth = ota->OTA_data[ota->curr_index];
    ota->curr_index += 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_create_bmp_buffer
 * DESCRIPTION
 *  Convert OTA data to BMP image data with BMP header
 * PARAMETERS
 *  ota                 [IN]        OTA data for BMP image
 *  ota_bmp_header      [IN]        OTA header for BMP
 * RETURNS
 *  U8(?)
 *****************************************************************************/
extern void mmi_nsm_create_bmp_buffer(OTA_DATA_STRUCT *ota, OTA_BMP_HEADER_STRUCT *ota_bmp_header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 width_in_bytes;
    U16 total_width = 0;
    U16 ota_bitmap_len;
    U16 ota_bitmap_index;
    U16 gnsm_index = 0;
    U8 padding_factor;
    S32 count;
    BmpFileHeader_sturct BmpHeader = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_nsm_set_bmp_header_default_values(&BmpHeader);

    width_in_bytes = ((ota_bmp_header->ota_image_width) / (ONE_BYTE_SIZE));

    /* Width should have bytes multiple of 4 */
    {
        U8 temp = 0;

        temp = width_in_bytes % MOD_BY_FOUR;
        padding_factor = 0;
        if (temp != 0)
        {
            padding_factor = MOD_BY_FOUR - temp;
        }
    }

    total_width = (width_in_bytes + padding_factor);

    /* BMP file size */
    BmpHeader.BmpBMPFileHeader.FileSize = (BMP_HEADER_SIZE + ((ota_bmp_header->ota_image_height) * (total_width)));

    /* Reset global buffer */
    memset(gNSMBuffer, 0x00, MAX_BMP_BUF_SIZE);
    memset(g_pmsg_TextInMessage, 0x00, sizeof(g_pmsg_TextInMessage));

    mmi_nsm_add_6extra_byte_for_mmi(&BmpHeader);
    gnsm_index += MMI_EXTRA_BMP_HEADER_SIZE;

    BmpHeader.BmpBMPInfoHeader.Width = ota_bmp_header->ota_image_width;
    BmpHeader.BmpBMPInfoHeader.Height = ota_bmp_header->ota_image_height;

    /* Copy BMP headers <File Header><Info Header><color> */
    memcpy((gNSMBuffer + gnsm_index), (((U8*) & BmpHeader) + 2), BMP_HEADER_SIZE);
    gnsm_index += BMP_HEADER_SIZE;

    /* 
     * Height (In pixel) for various Nokia Smart OTA Bitmaps 
     * Operator logo and CLI Icon = 14
     * Picutre Message   = 28
     */
    ota_bitmap_len = ((ota_bmp_header->ota_image_width * ota_bmp_header->ota_image_height) / (ONE_BYTE_SIZE));

    ota_bitmap_index = (ota_bitmap_len + ota->curr_index);  /* Here points to NULL in ota_data */

    /* To store OTA bitmap in reverse order in gNSMBuffer */
    for (count = (ota_bitmap_index - width_in_bytes); count >= ota->curr_index; count -= width_in_bytes)
    {
        memcpy((gNSMBuffer + gnsm_index), (ota->OTA_data + count), width_in_bytes);
        gnsm_index += (width_in_bytes + padding_factor);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_add_6extra_byte_for_mmi
 * DESCRIPTION
 *  Add six extra byte in BMP buffer for MMI support
 * PARAMETERS
 *  BmpHeader       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nsm_add_6extra_byte_for_mmi(BmpFileHeader_sturct *BmpHeader)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gnsm_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gNSMBuffer[gnsm_index] = 0x01;
    gnsm_index += 1;

    gNSMBuffer[gnsm_index] = 0x00;
    gnsm_index += 1;

    gNSMBuffer[gnsm_index] = (U8) ((BmpHeader->BmpBMPFileHeader.FileSize & 0x000000FF));
    gnsm_index += 1;

    gNSMBuffer[gnsm_index] = (U8) ((BmpHeader->BmpBMPFileHeader.FileSize & 0x0000FF00) >> 8);
    gnsm_index += 1;

    gNSMBuffer[gnsm_index] = (U8) ((BmpHeader->BmpBMPFileHeader.FileSize & 0x00FF0000) >> 16);
    gnsm_index += 1;

    gNSMBuffer[gnsm_index] = (U8) ((BmpHeader->BmpBMPFileHeader.FileSize & 0xFF000000) >> 24);
    gnsm_index += 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_set_bmp_header_default_values
 * DESCRIPTION
 *  Set default values for BMP header
 * PARAMETERS
 *  BmpHeader       [IN]        BMP header structure
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nsm_set_bmp_header_default_values(BmpFileHeader_sturct *BmpHeader)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BmpHeader->BmpBMPFileHeader.reserved = 0x0000;
    BmpHeader->BmpBMPFileHeader.Signature = (U16) 19778;
    BmpHeader->BmpBMPFileHeader.DataOffset = (U32) BMP_HEADER_SIZE;
    BmpHeader->BmpBMPInfoHeader.HeaderSize = (U32) 40;
    BmpHeader->BmpBMPInfoHeader.Bits = (U16) 1;
    BmpHeader->BmpBMPInfoHeader.Planes = (U16) 1;
    BmpHeader->BmpColors1.Blue = (U8) 255;
    BmpHeader->BmpColors1.Green = (U8) 255;
    BmpHeader->BmpColors1.Red = (U8) 255;
}

#endif /* defined (__MMI_OPERATOR_LOGO__) || defined(__MMI_CLI_ICON__) */ 

