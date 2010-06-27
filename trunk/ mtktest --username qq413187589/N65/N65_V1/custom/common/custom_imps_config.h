/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   custom_imps_config.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains IMPS configuration macros. 
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------*/
#ifndef _CUSTOM_IMPS_CONFIG_H
#define _CUSTOM_IMPS_CONFIG_H

#ifdef __IMPS__

#define IMPS_DEFAULT_HEADER "Accept-Charset: utf-8\r\nAccept: application/vnd.wv.csp.xml, text/*,image/*,audio/*,video/*\r\nContent-Type: application/vnd.wv.csp.xml\r\nConnection: Keep-Alive\r\n"
#define IMPS_OBJECT_HEADER "Accept: */*\r\nConnection: Keep-Alive\r\n"
#ifdef IMPS_IN_LARGE_STORAGE
 /* Order: 1. Invisible NAND 2. Visible NAND 3. visible NOR 4. Invisible NOR */
#define IMPS_APP_DISK FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM)
#else
#define IMPS_APP_DISK 'Z'
#endif


#define IMPS_XML_FILE_DIRECTORY imps_directory
extern kal_uint8 imps_directory[10]; /*This is the work directory for both MMI and IMPS service*/

extern void imps_custom_work_directory(void);
#endif
#endif
