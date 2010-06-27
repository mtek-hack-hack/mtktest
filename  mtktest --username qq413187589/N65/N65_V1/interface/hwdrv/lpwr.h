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
 *    lpwr.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for low power control
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __LPWR_H__
#define __LPWR_H__

#define MAIN_MAX_MODULE    32
#define SUB_MAX_MODULE     32

typedef enum {
      LPWR_DRV0_MODULE_GROUP=0,
      LPWR_DRV1_MODULE_GROUP,
      LPWR_MM_MODULE_GROUP,
      LPWR_MAX_MODULE_GROUP
} LPWR_MODULE_GROUP;

typedef struct {
   DEVICE_ID_ENUM          module_id;
   kal_uint8               lpwr_main_sm_handle;
   kal_uint32              lpwr_sub_glb_hanlde; //central handle to maintain sub module
   kal_uint32              lpwr_sub_sleepDisable;
   void                    (*pdn_enable_ctrl_callback)(void *parameter);
   void                    (*pdn_disable_ctrl_callback)(void *parameter);
} LPWR_MAIN_STRUCT;

typedef struct {
   LPWR_MODULE_GROUP       group_id;
   kal_uint8               lpwr_group_sm_handle;   //from l1 sm module
   kal_uint8               lpwr_main_handle_cnt;        //central handle to maintain main module
   kal_uint32              lpwr_main_sleepDisable;
   LPWR_MAIN_STRUCT        main_info[MAIN_MAX_MODULE];
} LPWR_INFO_STRUCT;

typedef struct
{
   DEVICE_ID_ENUM          id;
   LPWR_MODULE_GROUP       group;
} LPWR_GROUP_MAP_STRUCT;

typedef struct
{
   LPWR_MODULE_GROUP          group_id;
   kal_uint8                  main_handle;
   DEVICE_ID_ENUM             module_id;
} LPWR_STRUCT;

#if defined(__NEW_DRVPDN_FUNCTION__)
   #define DRVPDN_ENABLE2(addr,code,pdn_id) \
      DRVPDN_Enable2(addr,code,pdn_id)
   #define DRVPDN_DISABLE2(addr,code,pdn_id) \
      DRVPDN_Disable2(addr,code,pdn_id)
#else

   #define DRVPDN_ENABLE2(addr,code,pdn_id) \
      DRVPDN_Enable(addr,code,pdn_id)
   #define DRVPDN_DISABLE2(addr,code,pdn_id) \
      DRVPDN_Disable(addr,code,pdn_id)
#endif

/*Common module*/
extern void lpwr_init(void);
extern void lpwr_module_open(LPWR_STRUCT      *lpwr_handle, 
                      DEVICE_ID_ENUM   module_id,
                      void (*pdn_enable_ctrl_callback)(void *parameter),
                      void (*pdn_disable_ctrl_callback)(void *parameter)
                      );
/*Main module*/
extern void lpwr_main_disable(LPWR_STRUCT *lpwr_handle, 
                       void        *parameter);
extern void lpwr_main_enable(LPWR_STRUCT *lpwr_handle, 
                      void        *parameter);
extern void lpwr_main_fast_disable(LPWR_STRUCT *lpwr_handle);
extern void lpwr_main_fast_enable(LPWR_STRUCT *lpwr_handle);
extern void lpwr_main_fast_disable2(LPWR_STRUCT *lpwr_handle, 
                       void        *parameter);
extern void lpwr_main_fast_enable2(LPWR_STRUCT *lpwr_handle, 
                      void        *parameter);
/*Sub module*/
extern kal_uint8 lpwr_get_sub_handle(LPWR_STRUCT *lpwr_handle);
extern void lpwr_free_sub_handle(LPWR_STRUCT *lpwr_handle, kal_uint8 sub_handle);
extern void lpwr_sub_disable(LPWR_STRUCT   *lpwr_handle, 
                      kal_uint8     sub_handle, 
                      void          (*pdn_disable_ctrl_callback)(void *parameter),
                      void          *parameter);
extern void lpwr_sub_enable(LPWR_STRUCT *lpwr_handle, 
                     kal_uint8   sub_handle,
                     void        (*pdn_enable_ctrl_callback)(void *parameter),
                     void        *parameter);
#if defined(__NEW_DRVPDN_FUNCTION__)
extern void DRVPDN_Enable2(kal_uint32 addr,kal_uint16 code,kal_uint8 handle);
extern void DRVPDN_Disable2(kal_uint32 addr,kal_uint16 code,kal_uint8 hanlde);
#endif
#endif

