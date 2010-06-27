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

/*******************************************************************************
 * Filename:
 * ---------
 *  FileMgr.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *==============================================================================
 *******************************************************************************/

#include "MMI_include.h"

#include "ProtocolEvents.h"
#include "CommonScreens.h"

#include "wgui_datetime.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 

#include "FileMgr.h"
#include "DateTimeType.h"
#include "DateTimeGProt.h"
#include "MainMenuDef.h"
#include "GpioInc.h"
#include "IdleAppProt.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "ProfileGprots.h"
#include "PhoneSetupGprots.h"
#include "PhoneBookGprot.h"
#include "ToDoListEnum.h"
#include "AlarmDef.h"
#include "SettingProfile.h"     /* error tone */
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "fmt_struct.h"
#include "Fmt_main.h"
#include "CallManagementGProt.h"
#include "Conversions.h"
#include "MMIThemes.h"
/* Lisen 0623 */
#include "FactoryModeProt.h"
#include "mmiapi.h"

#ifdef __DRM_SUPPORT__
#include "DRM_gprot.h"
#include "wap_ps_struct.h"
#include "wapadp.h"
#include "app_mine.h"
#endif /* __DRM_SUPPORT__ */ 
#include "RightsMgrGProt.h"

#if defined (__DRM_SUPPORT__) || defined (__MMI_MMS__)
#include "wapadp.h"
#endif 

#ifdef __MMI_MESSAGES_EMS__
#include "MessagesExDcl.h"
#endif 
#ifdef __MMI_VCALENDAR__
#include "vCalendar.h"
#endif 
#ifdef __MMI_VCARD__
#include "vCard.h"
#endif 
#ifdef __MMI_VBOOKMARK__
#include "vBookmark.h"
#endif 
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
#include "ProfileMgrGProt.h"
#endif 
#ifdef __MMI_RING_COMPOSER__
#include "ComposeRingToneDefs.h"
#include "ComposeRingToneProts.h"       /* for ring tone composer */
#endif /* __MMI_RING_COMPOSER__ */ 

#ifdef __MMI_BARCODEREADER__
#include "MMI_features_barcodereader.h"
#include "barcodereaderResDef.h"
#endif

#ifdef __MMI_EBOOK_READER__
#include "EbookDefs.h"
#include "EbookProt.h"
#include "EbookGProt.h"
#include "EbookManager.h"
#endif /* __MMI_EBOOK_READER__ */ 

#ifdef __MMI_SOUND_RECORDER__
#include "SoundRecorderDef.h"
#include "SoundRecorderProt.h"
#endif /* __MMI_SOUND_RECORDER__ */ 
#ifdef __MMI_AUDIO_PLAYER__
#include "AudioPlayerDef.h"
#include "AudioPlayerPlayList.h"
#include "AudioPlayerProt.h"
#endif /* __MMI_AUDIO_PLAYER__ */ 
#ifdef __MMI_AB_REPEATER__
#include "ABRepeaterDef.h"
#include "ABRepeaterProt.h"
#endif /* __MMI_AB_REPEATER__ */ 
#ifdef __MMI_IMAGE_VIEWER__
#include "mmi_features_camera.h"
#include "ImageViewer.h"
#include "ImageViewerResDef.h"
#endif /* __MMI_IMAGE_VIEWER__ */ 
#ifdef __MMI_VIDEO_PLAYER__
#include "MMI_features_video.h"
#include "VdoPlyResDef.h"
#include "VdoPlyGprot.h"
#endif /* __MMI_VIDEO_PLAYER__ */ 
#ifdef __MMI_PHOTOEDITOR__
#include "PhotoEditorGprot.h"
#endif 

#ifdef __MMI_SLIDESHOW__
#include "SlideShowGProt.h"
#endif

#ifdef __MMI_IRDA_SUPPORT__
#include "IrdaMMIGprots.h"
#endif 
#ifdef __MMI_OPP_SUPPORT__
#include "OPPMMIGprots.h"
#endif 

#ifdef __MMI_BIP_SUPPORT__
#include "BTMMIBipGprot.h"
#endif 

#ifdef __J2ME__
#include "JavaAgencyGProt.h"
#endif 
#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif 

#ifdef __MMI_FM_RADIO_RECORD__
#include "FMRadioProt.h"
#endif 

#ifdef __MMI_BG_SOUND_EFFECT__
#include "BGSoundGProt.h"
#endif 

#ifdef __OTG_ENABLE__
#include "otg_if.h"
#endif 

#ifdef __USB_IN_NORMAL_MODE__
#include "ExtDeviceDefs.h"
#include "USBDeviceGprot.h"
#endif 

#ifdef __MMI_SWFLASH__
#include "SWFlashDef.h"
#include "SWFlashGProt.h"
#include "Mdi_swflash.h"
#endif /* __MMI_SWFLASH__ */ 

#ifdef __MMI_DOWNLOAD_AGENT__
#include "DLAgentDef.h"
#endif 

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageGProt.h"
#endif

#ifdef __MMI_UNIFIED_COMPOSER__
#include "UnifiedComposerGProt.h"
#endif /* __MMI_UNIFIED_COMPOSER__ */

#ifdef __SYNCML_SUPPORT__
#include "SyncMLGprot.h"
#include "SyncMLDef.h"
#endif 

#ifdef __MMI_CSB_BROWSER__
#include "CatScreenBrowserDefs.h"
#include "CatScreenBrowserProts.h"
#endif /* __MMI_CSB_BROWSER__ */

#include "FileManagerGProt.h"
#include "FileMgrStruct.h"
#include "FileManagerDef.h"
#include  "FunAndGamesDefs.h"

#if defined(__MMI_BROWSER_2__)
#include "BrowserMain.h"
#endif /* __MMI_BROWSER_2__ */

#if defined(__MMI_VBOOKMARK__) || defined(__MMI_BROWSER_2__)
#include "BrowserGprots.h"
#endif /* #ifdef __MMI_VBOOKMARK__ */

#if defined(__MMI_FWU_VIA_FILE__)
#ifdef __MTK_TARGET__
#include "DrvFlash.h"
#endif
#include "custom_fota.h"
#endif /* __MMI_FWU_VIA_FILE__ */

#if !defined(__FOTA_ENABLE__)
#define FMGR_TYPE_FOTA_FULL_EXT_NAME    "FOT"
#endif

#if defined(__MMI_PICT_BRIDGE_SUPPORT__)
#include "PictBridgeGProt.h"
#endif

#if defined(__MMI_BPP_SUPPORT__)
#include "imageviewer.h"
#include "BTMMICm.h"
#include "BTMMIBppGprot.h"
#endif

#ifdef __MMI_MY_FAVORITE__
#include "MyFavoriteGProt.h"
#endif

#if defined(__MMI_LANGLN__)
#include "LangLnCommon.h"
#endif /*__MMI_LANGLN__*/

#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "JBrowserMMIGprots.h"
#endif

#if defined (JATAAYU_SUPPORT) && defined (MMS_SUPPORT)
#include "JMMSGprot.h"
#endif

#ifdef __DRM_SUPPORT__
#include "RightsMgrGProt.h"
#endif

#include "SMSAPI.h"

#ifdef __MMI_MMS_BGSR_SUPPORT__
#include "MMSBGSRGprot.h"
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
extern S8 nPrintableStr[];

#ifdef __DRM_SUPPORT__
//#define __FMGR_DRM_UT__
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
S16 g_istheme_folder_created = FALSE;
S8 gtheme_folder_path[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];
S8 gtest_theme_file[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
#ifdef __MMI_SOUND_RECORDER__
extern U16 mmi_sndrec_get_menuId(void);
#endif 

static BOOL fmgr_is_network_services_available(void);
extern void mmi_fmgr_stop_decode(void);

/******************************************************************/
/* Internal Variable */
/******************************************************************/
fmgr_context_struct g_fmgr_context;
fmgr_context_struct *fmgr_p = &g_fmgr_context;

const fmgr_filter_struct fmgr_filter[FMGR_MAX_FILTER_COUNT] = 
{
    {FMGR_TYPE_BMP, "BMP"},
    {FMGR_TYPE_JPG, "JPG"},
    {FMGR_TYPE_JPEG, "JPEG"},
    {FMGR_TYPE_GIF, "GIF"},
    {FMGR_TYPE_PNG, "PNG"},
    {FMGR_TYPE_EMS, "EMS"},
    {FMGR_TYPE_ANM, "ANM"},
    {FMGR_TYPE_WBMP, "WBMP"},
    {FMGR_TYPE_WBM, "WBM"},
    {FMGR_TYPE_M3D, "M3D"},

    {FMGR_TYPE_IMY, "IMY"},
    {FMGR_TYPE_MID, "MID"},
    {FMGR_TYPE_MIDI, "MIDI"},
    {FMGR_TYPE_WAV, "WAV"},
    {FMGR_TYPE_AMR, "AMR"},
    {FMGR_TYPE_AAC, "AAC"},
    {FMGR_TYPE_DAF, "MP3"},
    {FMGR_TYPE_MP2, "MP2"},
    {FMGR_TYPE_VM, "VM"},
    {FMGR_TYPE_AWB, "AWB"},
    {FMGR_TYPE_AIF, "AIF"},
    {FMGR_TYPE_AIFF, "AIFF"},
    {FMGR_TYPE_AIFC, "AIFC"},
    {FMGR_TYPE_AU, "AU"},
    {FMGR_TYPE_SND, "SND"},
    {FMGR_TYPE_M4A, "M4A"},
    {FMGR_TYPE_MMF, "MMF"},
    {FMGR_TYPE_WMA, "WMA"},

    {FMGR_TYPE_3GP, "3GP"},
    {FMGR_TYPE_MP4, "MP4"},
    {FMGR_TYPE_MPG, "MPG"},
    {FMGR_TYPE_AVI, "AVI"},
    {FMGR_TYPE_3G2, "3G2"},

    {FMGR_TYPE_CMP, "CMP"},

    {FMGR_TYPE_JAD, "JAD"},
    {FMGR_TYPE_JAR, "JAR"},
    {FMGR_TYPE_VCF, "VCF"},
    {FMGR_TYPE_VCS, "VCS"},
    {FMGR_TYPE_LRC, "LRC"},
    {FMGR_TYPE_THEME, "MED"},
    {FMGR_TYPE_SVG, "SVG"},
    {FMGR_TYPE_EBOOK_TXT, "TXT"},
    {FMGR_TYPE_EBOOK_PDB, "PDB"},
    {FMGR_TYPE_SDP, "SDP"},
    {FMGR_TYPE_RAM, "RAM"},
    {FMGR_TYPE_DCF, "DCF"},
    {FMGR_TYPE_DM, "DM"},
    {FMGR_TYPE_WML, "WML"},
    {FMGR_TYPE_HTML, "HTML"},
    {FMGR_TYPE_HTM, "HTM"},
    {FMGR_TYPE_XHTML, "XHTML"},
    {FMGR_TYPE_FOTA_FULL, FMGR_TYPE_FOTA_FULL_EXT_NAME},

    {FMGR_TYPE_ODF, "ODF"},
    {FMGR_TYPE_ZDD, "ZDD"},
    {FMGR_TYPE_VIS, "VIS"},
    {FMGR_TYPE_IVIS, "IVIS"},
    {FMGR_TYPE_KVIS, "KVIS"},
    {FMGR_TYPE_MVIS, "MVIS"},

    {FMGR_TYPE_URL, "URL"},
    {FMGR_TYPE_VBM, "VBM"},
    {FMGR_TYPE_MBC, "MBC"}
};

/************************************************************************
* Extern Functions
************************************************************************/
#ifdef __DRM_MTK__
extern drm_rights_struct *drm_core_get_rights(FS_HANDLE input);
#endif

#ifdef __MMI_FILE_MANAGER__


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_init
 * DESCRIPTION
 *  init FMGR highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* drive options */
    SetHiliteHandler(MENU_FMGR_DRIVE_OPEN, highlight_fmgr_drive_open);
    SetHiliteHandler(MENU_FMGR_DRIVE_FORMAT, highlight_fmgr_format);
    SetHiliteHandler(MENU_FMGR_DRIVE_CHECK, highlight_fmgr_check_drive);
    SetHiliteHandler(MENU_FMGR_DRIVE_UNMOUNT, highlight_fmgr_unmount);
    SetHiliteHandler(MENU_FMGR_FOLDER_CREATE, highlight_fmgr_create_folder);

    /* select options */
    SetHiliteHandler(MENU_FMGR_SELECT_DONE, highlight_fmgr_app_select);
    SetHiliteHandler(MENU_FMGR_TREE_OPEN, highlight_fmgr_tree_open);
    SetHiliteHandler(MENU_FMGR_TREE_SELECT, highlight_fmgr_tree_copy);

    /* folder options */
    SetHiliteHandler(MENU_FMGR_GEN_OPTION_OPEN, highlight_fmgr_open);
    SetHiliteHandler(MENU_FMGR_GEN_OPTION_RENAME, highlight_fmgr_rename);
    SetHiliteHandler(MENU_FMGR_GEN_OPTION_DELETE, highlight_fmgr_delete);
    SetHiliteHandler(MENU_FMGR_GEN_OPTION_SORT, highlight_fmgr_sort);

    /* file options */
    SetHiliteHandler(MENU_FMGR_IMG_OPTION_VIEW, highlight_fmgr_view_image);
    SetHiliteHandler(MENU_FMGR_IMG_OPTION_EDIT, highlight_fmgr_edit_image);
    SetHiliteHandler(MENU_FMGR_AUD_OPTION_PLAY, highlight_fmgr_play_audio);
    SetHiliteHandler(MENU_FMGR_VID_OPTION_PLAY, highlight_fmgr_play_video);
    SetHiliteHandler(MENU_FMGR_EXE_OPTION_EXECUTE, highlight_fmgr_execute);
    SetHiliteHandler(MENU_FMGR_GEN_OPTION_FORWARD, highlight_fmgr_forward);
    SetHiliteHandler(MENU_FMGR_GEN_OPTION_DETAIL, highlight_fmgr_detail);
#if defined(__MMI_EXIF__)
    SetHiliteHandler(MENU_FMGR_GEN_OPTION_JPG_DETAIL, highlight_fmgr_jpg_detail);
#endif 
    SetHiliteHandler(MENU_FMGR_GEN_OPTION_COPY, highlight_fmgr_copy);
    SetHiliteHandler(MENU_FMGR_GEN_OPTION_MOVE, highlight_fmgr_move);
    SetHiliteHandler(MENU_FMGR_GEN_OPTION_DELETE_ALL, highlight_fmgr_delete_all_file);

#ifdef __MMI_DOWNLOAD_AGENT__
    SetHiliteHandler(MENU_FMGR_DA_OPTION_FORWARD, highlight_fmgr_da_forward);
#endif 

#ifdef __DRM_MTK__
    SetHiliteHandler(MENU_FMGR_DRM_RIGHTS_DETAIL, highlight_fmgr_drm_rights_detail);
    SetHiliteHandler(MENU_FMGR_DRM_RIGHTS_DELETE_ALL_EXPIRED, highlight_fmgr_drm_rights_delete_all_expired);
#endif

    /* sort options */
    SetHiliteHandler(MENU_FMGR_SORT_BY_NAME, highlight_fmgr_sort_by_name);
    SetHiliteHandler(MENU_FMGR_SORT_BY_TYPE, highlight_fmgr_sort_by_type);
    SetHiliteHandler(MENU_FMGR_SORT_BY_TIME, highlight_fmgr_sort_by_time);
    SetHiliteHandler(MENU_FMGR_SORT_BY_SIZE, highlight_fmgr_sort_by_size);
    SetHiliteHandler(MENU_FMGR_SORT_NONE, highlight_fmgr_sort_none);

    /* fwd options */
    SetHiliteHandler(MENU_FMGR_FWD_WALLPAPER, highlight_fmgr_to_wallpaper);
    SetHiliteHandler(MENU_FMGR_FWD_SUB_WALLPAPER, highlight_fmgr_to_sub_wallpaper);
    SetHiliteHandler(MENU_FMGR_FWD_SCREENSAVER, highlight_fmgr_to_screensaver);
    SetHiliteHandler(MENU_FMGR_FWD_POWER_ON, highlight_fmgr_to_power_on_display);
    SetHiliteHandler(MENU_FMGR_FWD_POWER_OFF, highlight_fmgr_to_power_off_display);
    SetHiliteHandler(MENU_FMGR_FWD_PHB, highlight_fmgr_to_phb);
    SetHiliteHandler(MENU_FMGR_FWD_TODOLIST, highlight_fmgr_to_todolist);
    SetHiliteHandler(MENU_FMGR_FWD_SMS, highlight_fmgr_to_sms);
    SetHiliteHandler(MENU_FMGR_FWD_MMS, highlight_fmgr_to_mms);
    SetHiliteHandler(MENU_FMGR_FWD_EMS, highlight_fmgr_to_ems);
    SetHiliteHandler(MENU_FMGR_FWD_EMAIL, highlight_fmgr_to_email);
    SetHiliteHandler(MENU_FMGR_FWD_IRDA, highlight_fmgr_to_irda);
    SetHiliteHandler(MENU_FMGR_FWD_BT, highlight_fmgr_to_bt);
    SetHiliteHandler(MENU_FMGR_FWD_PROFILE, highlight_fmgr_to_profile);
    SetHiliteHandler(MENU_FMGR_FWD_BGSOUND, highlight_fmgr_to_bgsound);

    /* Print options */
#if defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_BPP_SUPPORT__)
    SetHiliteHandler(MENU_FMGR_GEN_OPTION_PRINT, highlight_fmgr_print);

#if defined(__MMI_PICT_BRIDGE_SUPPORT__)
    SetHiliteHandler(MENU_FMGR_PRINT_PICTBRIGE, highlight_fmgr_print_to_pictbrige);
#endif

#if defined(__MMI_BPP_SUPPORT__)
    SetHiliteHandler(MENU_FMGR_PRINT_BLUETOOTH, highlight_fmgr_print_to_bluetooth);
#endif

#endif /* defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_BPP_SUPPORT__) */

    SetHiliteHandler(MENU_FMGR_INPUT_METHOD, highlight_fmgr_input_method);
    /* Added By Alok */
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    SetHiliteHandler(MENU_FMGR_ACTIVATE_THEME, highlight_fmgr_activate_theme);
    SetHiliteHandler(MENU_FMGR_THEME_DELETE, fmgr_theme_delete_highlight);
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

#ifdef __MMI_EBOOK_READER__
    SetHiliteHandler(MENU_FMGR_EBK_OPTION_OPEN, highlight_fmgr_open_ebook);
#endif 

#if defined(__MMI_BROWSER_2__)
    SetHiliteHandler(MENU_FMGR_BOOKMARK_FILE_OPEN, highlight_fmgr_goto_bookmark);
#endif

#ifdef __MMI_SWFLASH__
    SetHiliteHandler(MENU_ID_SWFLASH_OPTION_PLAY, highlight_fmgr_swflash_play);
    SetHiliteHandler(MENU_ID_SWFLASH_OPTION_INFO, highlight_fmgr_swflash_info);
    SetHiliteHandler(MENU_ID_SWFLASH_OPTION_DOWNLOAD, highlight_fmgr_swflash_download);
#endif

#if defined(__DRM_V02__)
    SetHiliteHandler(MENU_FMGR_DRM_OPTION_MUL_ODF_OPEN, highlight_fmgr_open_multi_odf);
#endif

#ifdef __MMI_VBOOKMARK__
    SetHiliteHandler(MENU_FMGR_VBOOKMARK_OPTION_GOTO, highlight_fmgr_vbookmark_goto);
    SetHiliteHandler(MENU_FMGR_VBOOKMARK_OPTION_OPEN, highlight_fmgr_vbookmark_open);
#endif /* #ifdef __MMI_VBOOKMARK__ */

#if defined (__FS_CARD_SUPPORT__)
    SetProtocolEventHandler(fmgr_msdc_plug_in_hdlr, PRT_MMI_FMGR_CARD_PLUG_IN_IND);
    SetProtocolEventHandler(fmgr_msdc_plug_out_hdlr, PRT_MMI_FMGR_CARD_PLUG_OUT_IND);
#endif /* defined (__FS_CARD_SUPPORT__) */ 
#ifdef __OTG_ENABLE__
    SetProtocolEventHandler(fmgr_otg_display_hdlr, PRT_MMI_FMGR_OTG_DISPLAY_IND);
#endif 

    fmgr_init_context();
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_init_context
 * DESCRIPTION
 *  init FMGR context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_init_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init global variable */
    memset(fmgr_p, 0, sizeof(fmgr_context_struct));
    fmgr_p->src_application = APP_FILEMANAGER;  /* idle screen and the menu one
                                                   level upper than FMGR need to
                                                   reset fmgr_p->src_application */
    ReadValue(NVRAM_EF_FMGR_SORT_OPTION_LID, &temp, DS_BYTE, &error);
    if (temp == 0xff)
    {
        fmgr_p->sort_option = FS_NO_SORT;
    }
    else
    {
        fmgr_p->sort_option = temp << 5;
    }

    fmgr_p->is_fmgr_busy = MMI_FALSE;

    fmgr_init_drive();
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_init_drive
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_init_drive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __DRM_MTK__
    S32 attr;
#endif 
    S8 drive;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->drv_count = 0;
    memset(fmgr_p->drv_list, 0, sizeof(fmgr_p->drv_list));

    /* on target */
    if (((drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        /* Normal 2 existed */
        fmgr_p->drv_count++;
        sprintf((PS8) fmgr_p->drv_list[FMGR_NOR_STORAGE], "%c:\\", drive);

    #ifdef __USB_IN_NORMAL_MODE__
        if (mmi_usb_is_in_mass_storage_mode() &&
            !mmi_usb_is_leaving_ms_mode() 
        #ifndef __USB_IN_NORMAL_MODE_IMPROVE__	
            && mmi_usb_check_path_exported((PS8) fmgr_p->drv_list[FMGR_NOR_STORAGE])
        #endif
            )
        {
            /* the storage is exported to PC */
            memset(fmgr_p->drv_list[FMGR_NOR_STORAGE], 0, sizeof(fmgr_p->drv_list[FMGR_NOR_STORAGE]));
            fmgr_p->drv_count--;

        }
    #endif /* __USB_IN_NORMAL_MODE__ */ 
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (!mmi_usb_is_in_mass_storage_mode() || mmi_usb_is_leaving_ms_mode())
#endif 
    {
        if (((drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
        {
            /* Normal 1 existed */
            fmgr_p->drv_count++;
            sprintf((PS8) fmgr_p->drv_list[FMGR_NAND_STORAGE], "%c:\\", drive);
        }
        if (((drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
        {
            /* Removable existed */
            fmgr_p->drv_count++;
            sprintf((PS8) fmgr_p->drv_list[FMGR_REMOVABLE_STORAGE], "%c:\\", drive);
        }

    #ifdef __OTG_ENABLE__
        {
            U8 i;

            for (i = 0; i < 4; i++)
            {
                if (((drive = FS_GetDrive(FS_DRIVE_V_EXTERNAL, i + 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
                {
                    /* Removable existed */
                    fmgr_p->drv_count++;
                    sprintf((PS8) fmgr_p->drv_list[FMGR_OTG_1_STORAGE + i], "%c:\\", drive);
                }
            }
        }
    #endif /* __OTG_ENABLE__ */ 

    #ifdef __SIM_PLUS__
        {
            U8 i;

            for (i=0; i<4; i++)
            {
                if (((drive = FS_GetDrive(FS_DRIVE_V_SIMPLUS, i + 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
                {
                    /* SIM plush device existed */
                    fmgr_p->drv_count++;
                    sprintf((PS8) fmgr_p->drv_list[FMGR_SIM_PLUS_1_STORAGE + i], "%c:\\", drive);
                }
            }
        }
    #endif

    #ifdef __MSDC2_SD_MMC__
        if (((drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 2, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
        {
            /* Removable existed */
            fmgr_p->drv_count++;
            sprintf((PS8) fmgr_p->drv_list[FMGR_MSDC2_SD_STORAGE], "%c:\\", drive);
        }    
    #endif
    }

#ifdef __DRM_MTK__
    FS_CreateDir(DRM_NOR_PATH);

    FS_CreateDir(DRM_RO_PATH);
    attr = FS_GetAttributes(DRM_RO_PATH);
    if (attr >= FS_NO_ERROR)
    {
        FS_SetAttributes(DRM_RO_PATH, (U8) (attr | FS_ATTR_HIDDEN));
    }

    FS_XDelete(DRM_TEMP_DECRYPTED_FOLDER, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    FS_CreateDir(DRM_TEMP_DECRYPTED_FOLDER);
    attr = FS_GetAttributes(DRM_TEMP_DECRYPTED_FOLDER);
    if (attr >= FS_NO_ERROR)
    {
        FS_SetAttributes(DRM_TEMP_DECRYPTED_FOLDER, (U8) (attr | FS_ATTR_HIDDEN));
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (!mmi_usb_is_in_mass_storage_mode() || 
        mmi_usb_is_leaving_ms_mode() ||
        !mmi_usb_is_any_exported_drive())
#endif 
    {
        fmgr_p->drv_count++;
        mmi_ucs2_to_asc((PS8) fmgr_p->drv_list[FMGR_DRM_RO_STORAGE], (PS8) DRM_RO_PATH);
    }
#endif /* __DRM_MTK__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_drive_list
 * DESCRIPTION
 *  highlight handler for drive
 * PARAMETERS
 *  hiliteID        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_drive_list(S32 hiliteID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;
    U8 sel_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->cur_index = hiliteID;
    index = fmgr_get_drive_index(hiliteID);
    if (index >= 0)
    {
        mmi_asc_to_ucs2((PS8) fmgr_p->file_path, (PS8) fmgr_p->drv_list[index]);
    }

    if (fmgr_p->src_application == APP_FILEMANAGER)
    {
        if (fmgr_p->tree_action == FMGR_ACTION_COPY || fmgr_p->tree_action == FMGR_ACTION_MOVE)
        {
        #ifdef __DRM_MTK__
            if (index == FMGR_DRM_RO_STORAGE)
            {
                ChangeLeftSoftkey(0, 0);
                ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
                SetRightSoftkeyFunction(fmgr_abort_copy_select, KEY_EVENT_UP);
            #ifdef __MMI_TOUCH_SCREEN__
                wgui_reset_list_item_selected_callback();
            #endif 
            }
            else
        #endif /* __DRM_MTK__ */ 
            {
                ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                SetKeyHandler(fmgr_set_curr_tree_and_enter, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetLeftSoftkeyFunction(entry_fmgr_drive_option, KEY_EVENT_UP);
                SetRightSoftkeyFunction(fmgr_abort_copy_select, KEY_EVENT_UP);
                /* Leo start 20050808 */
            #ifdef __MMI_TOUCH_SCREEN__
                wgui_register_list_item_selected_callback(fmgr_set_curr_tree_and_enter);
            #endif 
                /* Leo end 20050808 */
            }
        }
        else
        {
        #if defined(__DRM_MTK__)
            if (index == FMGR_DRM_RO_STORAGE)
            {
                ChangeLeftSoftkey(STR_FMGR_OPEN, 0);
                SetKeyHandler(entry_fmgr_explorer, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetLeftSoftkeyFunction(entry_fmgr_explorer, KEY_EVENT_UP);
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            #ifdef __MMI_TOUCH_SCREEN__
                wgui_register_list_item_selected_callback(entry_fmgr_explorer);
            #endif 
            }
            else
        #endif /* __DRM_MTK__ */ 
            {
                ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                SetKeyHandler(entry_fmgr_explorer, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetLeftSoftkeyFunction(entry_fmgr_drive_option, KEY_EVENT_UP);
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
                /* Leo start 20050808 */
            #ifdef __MMI_TOUCH_SCREEN__
                wgui_register_list_item_selected_callback(entry_fmgr_explorer);
            #endif 
                /* Leo end 20050808 */
            }
        }
        ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        return;
    }

#if defined(__DRM_MTK__)
    if (index == FMGR_DRM_RO_STORAGE)
    {
        /* not FMGR, can't enter DRM drive */
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
        SetRightSoftkeyFunction(fmgr_abort_app_select, KEY_EVENT_UP);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_reset_list_item_selected_callback();
    #endif 
        return;
    }
#endif /* __DRM_MTK__ */ 

    sel_type = fmgr_p->sel_type & 0x0f;
    switch (sel_type)
    {
        case FMGR_SELECT_FILE:
            ChangeLeftSoftkey(STR_FMGR_OPEN, 0);
            SetKeyHandler(entry_fmgr_explorer, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(entry_fmgr_explorer, KEY_EVENT_UP);
            /* Leo start 20050808 */
    #ifdef __MMI_TOUCH_SCREEN__
            wgui_register_list_item_selected_callback(entry_fmgr_explorer);
    #endif 
            /* Leo end 20050808 */
            break;
        case FMGR_SELECT_FILE_OR_FOLDER:
        case FMGR_SELECT_FOLDER:
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
            SetKeyHandler(entry_fmgr_explorer, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(entry_fmgr_drive_option, KEY_EVENT_UP);
            /* Leo start 20050808 */
    #ifdef __MMI_TOUCH_SCREEN__
            wgui_register_list_item_selected_callback(entry_fmgr_explorer);
    #endif 
            /* Leo end 20050808 */
            break;
        case FMGR_SELECT_BROWSE:
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
            SetKeyHandler(entry_fmgr_explorer, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(entry_fmgr_app_drive_option, KEY_EVENT_UP);
            /* Leo start 20050808 */
    #ifdef __MMI_TOUCH_SCREEN__
            wgui_register_list_item_selected_callback(entry_fmgr_explorer);
    #endif 
            /* Leo end 20050808 */
            break;
    }
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(fmgr_abort_app_select, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_get_drive_index
 * DESCRIPTION
 *  map highlight id and drive index
 * PARAMETERS
 *  hiliteID        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S8 fmgr_get_drive_index(S32 hiliteID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, count = 0, mask;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mask = fmgr_get_msdc_mask();

    for (i = 0; i < FMGR_TOTAL_STORAGE; i++)
    {
        if (fmgr_p->drv_list[i][0] != 0)
        {
            if (((i >= FMGR_REMOVABLE_STORAGE) &&
                 (mask & (0x01 << (i - FMGR_REMOVABLE_STORAGE)))) || i < FMGR_REMOVABLE_STORAGE)
            {
                count++;
            }
        }
        if (count == hiliteID + 1)
        {
            break;
        }
    }

    if (i == FMGR_TOTAL_STORAGE)
    {
        return (S8) - 1;
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_return_to_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_return_to_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_drive_open
 * DESCRIPTION
 *  highlight handler for open drive
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_drive_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(entry_fmgr_explorer, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_format
 * DESCRIPTION
 *  highlight handler for format drive
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->drive_action = FMGR_ACTION_FORMAT;
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(entry_fmgr_drive_confirm, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_check_drive
 * DESCRIPTION
 *  highlight handler for scan drive
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_check_drive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->drive_action = FMGR_ACTION_CHECK_DRIVE;
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(entry_fmgr_drive_confirm, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_unmount
 * DESCRIPTION
 *  highlight handler for unmount card
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_unmount(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->drive_action = FMGR_ACTION_UNMOUNT;
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(entry_fmgr_drive_confirm, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_node
 * DESCRIPTION
 *  highlight handler for file or folder
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_node(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    U8 sel_type;
#if defined(__DRM_V02__)
    MMI_BOOL is_multi_odf = MMI_FALSE;
    S32 file_type = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_kernel_get_file_info(index, &file_info);
    fmgr_p->cur_index = index;

    if (fmgr_p->src_application == APP_FILEMANAGER
    #ifdef __MMI_MY_FAVORITE__
        || fmgr_p->src_application == APP_MYFAVORITE
    #endif /* #ifdef __MMI_MY_FAVORITE__*/
        )
    {
    #ifdef __DRM_MTK__
        if (mmi_ucs2ncmp((PS8) fmgr_p->file_path, (PS8) DRM_RO_PATH, mmi_ucs2strlen((PS8) DRM_RO_PATH)) == 0)
        {
            /* DRM rights, back and left arrow only go back to drive list */
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            /* SetLeftSoftkeyFunction(entry_fmgr_delete_confirm, KEY_EVENT_UP); */
            SetLeftSoftkeyFunction(entry_fmgr_drm_rights_option, KEY_EVENT_UP);
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        #ifdef __MMI_TOUCH_SCREEN__
            wgui_reset_list_item_selected_callback();
        #endif 
            return;
        }
        else
    #endif /* __DRM_MTK__ */ 
    
    #ifdef __MMI_DOWNLOAD_AGENT__
        /* download agent file */
        if (fmgr_is_da_file())
        {
            /* file node */
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(entry_fmgr_file_option, KEY_EVENT_UP);
        #ifdef __MMI_TOUCH_SCREEN__
            wgui_reset_list_item_selected_callback();
        #endif 
            SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        }
        else
    #endif /* __MMI_DOWNLOAD_AGENT__ */ 

        {
            if (file_info.attribute & FS_ATTR_DIR)
            {
                /* folder node */
                if (fmgr_p->src_application == APP_FILEMANAGER)
                {
                SetLeftSoftkeyFunction(entry_fmgr_folder_option, KEY_EVENT_UP);
                }
            #ifdef __MMI_MY_FAVORITE__
                else if (fmgr_p->src_application == APP_MYFAVORITE)
                {
                    SetLeftSoftkeyFunction(entry_fmgr_folder_option, KEY_EVENT_UP);
                }
            #endif /* #ifdef __MMI_MY_FAVORITE__*/

                SetKeyHandler(fmgr_set_curr_path_and_enter, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

            #ifdef __MMI_TOUCH_SCREEN__
                wgui_register_list_item_selected_callback(fmgr_set_curr_path_and_enter);
            #endif 
                /* Leo end 20050808 */
            }
            else
            {
                /* file node */
                if (fmgr_p->src_application == APP_FILEMANAGER)
                {
                    SetLeftSoftkeyFunction(entry_fmgr_file_option, KEY_EVENT_UP);
                }
            #ifdef __MMI_MY_FAVORITE__
                else if (fmgr_p->src_application == APP_MYFAVORITE)
                {
                    SetLeftSoftkeyFunction(entry_fmgr_app_file_option, KEY_EVENT_UP);
                }
            #endif /* #ifdef __MMI_MY_FAVORITE__*/

                ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            #ifdef __MMI_TOUCH_SCREEN__
                wgui_reset_list_item_selected_callback();
            #endif 
            }
            SetKeyHandler(fmgr_back_to_parent, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetRightSoftkeyFunction(fmgr_back_to_parent, KEY_EVENT_UP);
        }
        return;
    }

    /* for other applications */
    sel_type = fmgr_p->sel_type & 0x0f;

#if defined(__DRM_V02__)

    if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_ODF))
    {
        if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
    #ifndef __MMI_SHOW_FILE_EXT__
            || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
    #endif 
            )
        {
            ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
            SetLeftSoftkeyFunction(fmgr_return_to_app, KEY_EVENT_UP);
        #ifdef __MMI_TOUCH_SCREEN__
            wgui_reset_list_item_selected_callback();
        #endif 
            return;
        }
    
        file_type = mmi_fmgr_get_drm_file_type_by_path((PS8) fmgr_p->file_path, &file_info.file_type);

        /* it is for avoid misjudge while highlight the files in the multipart ODF.
           because DRM_IS_ARCHIVE() will return true, when query a single file in the multipart ODF */
        if (file_type == FMGR_TYPE_ODF)
        {
            /* multi part ODF */
            is_multi_odf = MMI_TRUE;
        }
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    }    
#endif /* defined(__DRM_V02__) */
    
    switch (sel_type)
    {
        case FMGR_SELECT_FILE:
            /* select file */
            if (file_info.attribute & FS_ATTR_DIR)
            {
                ChangeLeftSoftkey(STR_FMGR_OPEN, 0);
                SetKeyHandler(fmgr_set_curr_path_and_enter, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetLeftSoftkeyFunction(fmgr_set_curr_path_and_enter, KEY_EVENT_UP);
                /* Leo start 20050808 */
            #ifdef __MMI_TOUCH_SCREEN__
                wgui_register_list_item_selected_callback(fmgr_set_curr_path_and_enter);
            #endif 
                /* Leo end 20050808 */
            }
            else
            {
            #if defined(__DRM_V02__)
                if ((is_multi_odf == MMI_TRUE) && !(fmgr_p->sel_type & FMGR_SELECT_ARCHIVE))
                {
                    if (fmgr_p->sel_type & FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT)
                    {
                        ChangeLeftSoftkey(0, 0);
                        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                    }
                    else
                    {
                        ChangeLeftSoftkey(STR_FMGR_OPEN, 0);
                        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                        SetLeftSoftkeyFunction(fmgr_open_mul_odf_hdlr, KEY_EVENT_UP);
                    #ifdef __MMI_TOUCH_SCREEN__
                        wgui_register_list_item_selected_callback(fmgr_open_mul_odf_hdlr);
                    #endif 
                    }
                }
                else
                {
                    if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_ODF))
                    {
                        if (!FMGR_FILTER_IS_SET(&fmgr_p->filter_type , file_type))
                        {                    
                            ChangeLeftSoftkey(0, 0);
                            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                        }
                        else
                        {
                            ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
                            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                            SetLeftSoftkeyFunction(fmgr_return_to_app, KEY_EVENT_UP);
                        #ifdef __MMI_TOUCH_SCREEN__
                            wgui_reset_list_item_selected_callback();
                        #endif 
                        }
                    }
                    else
                    {
                        ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
                        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                        SetLeftSoftkeyFunction(fmgr_return_to_app, KEY_EVENT_UP);
                    #ifdef __MMI_TOUCH_SCREEN__
                        wgui_reset_list_item_selected_callback();
                    #endif 
                    }
                }
            #else /* defined(__DRM_V02__) */
                ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
                ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetLeftSoftkeyFunction(fmgr_return_to_app, KEY_EVENT_UP);
            #ifdef __MMI_TOUCH_SCREEN__
                wgui_reset_list_item_selected_callback();
            #endif 
            
            #endif /* #if defined(__DRM_V02__) */
            }

            SetKeyHandler(fmgr_back_to_parent, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetRightSoftkeyFunction(fmgr_abort_app_select, KEY_EVENT_UP);
            break;

        case FMGR_SELECT_FOLDER:
            /* select folder to save file */
            if (file_info.attribute & FS_ATTR_DIR)
            {
                ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                SetKeyHandler(fmgr_set_curr_path_and_enter, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetLeftSoftkeyFunction(entry_fmgr_folder_option, KEY_EVENT_UP);
                /* Leo start 20050808 */
            #ifdef __MMI_TOUCH_SCREEN__
                wgui_register_list_item_selected_callback(fmgr_set_curr_path_and_enter);
            #endif 
                /* Leo end 20050808 */
            }

            SetKeyHandler(fmgr_back_to_parent, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetRightSoftkeyFunction(fmgr_abort_app_select, KEY_EVENT_UP);
    #ifdef __MMI_CSB_BROWSER__
            if(fmgr_p->src_application == APP_CSB)
            {
                ChangeLeftSoftkey(STR_ID_CSB_SET_TEXT, 0);
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
                SetLeftSoftkeyFunction(fmgr_return_to_app, KEY_EVENT_UP);
            }
    #endif /* __MMI_CSB_BROWSER__ */
            break;

        case FMGR_SELECT_FILE_OR_FOLDER:
            /* select file or folder */
            if (file_info.attribute & FS_ATTR_DIR)
            {
                /* folder node */
                ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                SetKeyHandler(fmgr_set_curr_path_and_enter, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetLeftSoftkeyFunction(entry_fmgr_folder_option, KEY_EVENT_UP);
                /* Leo start 20050808 */
            #ifdef __MMI_TOUCH_SCREEN__
                wgui_register_list_item_selected_callback(fmgr_set_curr_path_and_enter);
            #endif 
                /* Leo end 20050808 */
            }
            else
            {
            #if defined(__DRM_V02__)
                if ((is_multi_odf == MMI_TRUE) && !(fmgr_p->sel_type & FMGR_SELECT_ARCHIVE))
                {
                    if (fmgr_p->sel_type & FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT)
                    {
                        ChangeLeftSoftkey(0, 0);
                        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                    }
                    else
                    {
                        ChangeLeftSoftkey(STR_FMGR_OPEN, 0);
                        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                        SetLeftSoftkeyFunction(fmgr_open_mul_odf_hdlr, KEY_EVENT_UP);
                    #ifdef __MMI_TOUCH_SCREEN__
                        wgui_register_list_item_selected_callback(fmgr_open_mul_odf_hdlr);
                    #endif 
                    }
                }
                else
                {
                    /* file node */
                    if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_ODF))
                    {
                        if (!FMGR_FILTER_IS_SET(&fmgr_p->filter_type , file_type))
                        {
                            ChangeLeftSoftkey(0, 0);
                            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                        }
                        else
                        {
                            ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
                            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                            SetLeftSoftkeyFunction(fmgr_return_to_app, KEY_EVENT_UP);
                        #ifdef __MMI_TOUCH_SCREEN__
                            wgui_reset_list_item_selected_callback();
                        #endif 
                        }
                    }
                    else
                    {
                        ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
                        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                        SetLeftSoftkeyFunction(fmgr_return_to_app, KEY_EVENT_UP);
                    #ifdef __MMI_TOUCH_SCREEN__
                        wgui_reset_list_item_selected_callback();
                    #endif 
                    }
                }
            #else /* defined(__DRM_V02__) */

                ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
                ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetLeftSoftkeyFunction(fmgr_return_to_app, KEY_EVENT_UP);
            #ifdef __MMI_TOUCH_SCREEN__
                wgui_reset_list_item_selected_callback();
            #endif 
            
            #endif /* defined(__DRM_V02__) */
            }

            SetKeyHandler(fmgr_back_to_parent, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetRightSoftkeyFunction(fmgr_abort_app_select, KEY_EVENT_UP);
            break;

        case FMGR_SELECT_BROWSE:
            /* browse file */
            if (file_info.attribute & FS_ATTR_DIR)
            {
                /* folder node */
                ChangeLeftSoftkey(0, 0);
                /* SetLeftSoftkeyFunction(entry_fmgr_app_folder_option, KEY_EVENT_UP); */
            }
            else
            {
                /* file node */
            #if defined(__DRM_V02__)
                if ((is_multi_odf == MMI_TRUE) && !(fmgr_p->sel_type & FMGR_SELECT_ARCHIVE))
                {
                    if (fmgr_p->sel_type & FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT)
                    {
                        ChangeLeftSoftkey(0, 0);
                        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                    }
                    else
                    {
                        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                        SetLeftSoftkeyFunction(entry_fmgr_app_browse_multi_odf_menu, KEY_EVENT_UP);
                    #ifdef __MMI_TOUCH_SCREEN__
                        wgui_register_list_item_selected_callback(entry_fmgr_app_browse_multi_odf_menu);
                    #endif 
                    }
                }
                else
                {
                    if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_ODF))
                    {
                        if (!FMGR_FILTER_IS_SET(&fmgr_p->filter_type , file_type))
                        { 
                            ChangeLeftSoftkey(0, 0);
                            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                        }
                        else
                        {
                            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                            SetLeftSoftkeyFunction(entry_fmgr_app_file_option, KEY_EVENT_UP);
                        }
		    }
                    else
                    {
                        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                        SetLeftSoftkeyFunction(entry_fmgr_app_file_option, KEY_EVENT_UP);
                    }
                }
            #else /* #if defined(__DRM_V02__) */
                ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                SetLeftSoftkeyFunction(entry_fmgr_app_file_option, KEY_EVENT_UP);
            #endif /* #if defined(__DRM_V02__) */
            }

        #if defined(__DRM_V02__)
            if (SCR_FMGR_MUL_ODF_EXPLORER == GetActiveScreenId())
            {
                SetRightSoftkeyFunction(fmgr_app_mul_odf_goback_history, KEY_EVENT_UP);
            }
            else
        #endif /* #if defined(__DRM_V02__) */
            {
                ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetRightSoftkeyFunction(fmgr_abort_app_select, KEY_EVENT_UP);
            #ifdef __MMI_TOUCH_SCREEN__
                wgui_reset_list_item_selected_callback();
            #endif 
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_highlight_matrix_node
 * DESCRIPTION
 *  highlight matrix node
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_highlight_matrix_node(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    U8 sel_type;
#if defined(__DRM_V02__)
    MMI_BOOL is_multi_odf = MMI_FALSE;
    S32 file_type = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= fmgr_p->file_count)
        index = fmgr_p->file_count -1;
    mmi_fmgr_kernel_get_file_info(index, &file_info);
    fmgr_p->cur_index = index;

    /* for other applications */
    sel_type = fmgr_p->sel_type & 0x0f;

#if defined(__DRM_V02__)
    if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_ODF))
    {
        if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
    #ifndef __MMI_SHOW_FILE_EXT__
            || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
    #endif 
            )
        {
            ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
            SetLeftSoftkeyFunction(fmgr_return_to_app, KEY_EVENT_UP);
            /* Leo start 20050808 */
        #ifdef __MMI_TOUCH_SCREEN__
            wgui_reset_list_item_selected_callback();
        #endif 
            return;
        }

        file_type = mmi_fmgr_get_drm_file_type_by_path((PS8) fmgr_p->file_path, &file_info.file_type);
            
        if (file_type == FMGR_TYPE_ODF)
        {
            /* multi part ODF */
            is_multi_odf = MMI_TRUE;
        }
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);        
    }
#endif /* defined(__DRM_V02__)*/

    switch (sel_type)
    {
        case FMGR_SELECT_FILE:
            /* select file */
            if (file_info.attribute & FS_ATTR_DIR)
            {
                ChangeLeftSoftkey(STR_FMGR_OPEN, 0);
                SetLeftSoftkeyFunction(fmgr_set_curr_path_and_enter, KEY_EVENT_UP);
            }
            else
            {
            #if defined(__DRM_V02__)
                if ((is_multi_odf == MMI_TRUE) && !(fmgr_p->sel_type & FMGR_SELECT_ARCHIVE))
                {
                    if (fmgr_p->sel_type & FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT)
                    {
                        ChangeLeftSoftkey(0, 0);
                        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                    }
                    else
                    {
                        ChangeLeftSoftkey(STR_FMGR_OPEN, 0);
                        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                        SetLeftSoftkeyFunction(fmgr_open_mul_odf_hdlr, KEY_EVENT_UP);
                    #ifdef __MMI_TOUCH_SCREEN__
                        wgui_register_list_item_selected_callback(fmgr_open_mul_odf_hdlr);
                    #endif 
                    }
                }
                else
                {
                    if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_ODF))
                    {
                        if (!FMGR_FILTER_IS_SET(&fmgr_p->filter_type , file_type))
                        {          
                            ChangeLeftSoftkey(0, 0);
                            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                        }
                        else
                        {
                            ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
                            SetLeftSoftkeyFunction(fmgr_return_to_app, KEY_EVENT_UP);

                        }
                    }
                    else
                    {
                        ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
                        SetLeftSoftkeyFunction(fmgr_return_to_app, KEY_EVENT_UP);
                    }
                }
            #else /* #if defined(__DRM_V02__)*/          
                ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
                SetLeftSoftkeyFunction(fmgr_return_to_app, KEY_EVENT_UP);
            #endif /* #if defined(__DRM_V02__)*/          
            }

            SetRightSoftkeyFunction(fmgr_abort_app_select, KEY_EVENT_UP);
            break;

        case FMGR_SELECT_FOLDER:
            /* select folder to save file */
            if (file_info.attribute & FS_ATTR_DIR)
            {
                ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                SetLeftSoftkeyFunction(entry_fmgr_folder_option, KEY_EVENT_UP);
            }

            SetRightSoftkeyFunction(fmgr_abort_app_select, KEY_EVENT_UP);
            break;

        case FMGR_SELECT_FILE_OR_FOLDER:
            /* select file or folder */
            if (file_info.attribute & FS_ATTR_DIR)
            {
                ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                SetLeftSoftkeyFunction(entry_fmgr_folder_option, KEY_EVENT_UP);
            }
            else
            {
            #if defined(__DRM_V02__)
                if ((is_multi_odf == MMI_TRUE) && !(fmgr_p->sel_type & FMGR_SELECT_ARCHIVE))
                {
                    if (fmgr_p->sel_type & FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT)
                    {
                        ChangeLeftSoftkey(0, 0);
                        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                    }
                    else
                    {
                        ChangeLeftSoftkey(STR_FMGR_OPEN, 0);
                        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                        SetLeftSoftkeyFunction(fmgr_open_mul_odf_hdlr, KEY_EVENT_UP);
                    #ifdef __MMI_TOUCH_SCREEN__
                        wgui_register_list_item_selected_callback(fmgr_open_mul_odf_hdlr);
                    #endif 
                    }
                }
                else
                {
                    if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_ODF))
                    {
                        if (!FMGR_FILTER_IS_SET(&fmgr_p->filter_type , file_type))
                        {    
                            ChangeLeftSoftkey(0, 0);
                            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                        }
                        else
                        {
                            ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
                            SetLeftSoftkeyFunction(fmgr_return_to_app, KEY_EVENT_UP);
                        }
                    }
                    else
                    {
                        ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
                        SetLeftSoftkeyFunction(fmgr_return_to_app, KEY_EVENT_UP);
                    }
                }
            #else  /* #if defined(__DRM_V02__)*/        
                ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
                SetLeftSoftkeyFunction(fmgr_return_to_app, KEY_EVENT_UP);
            
            #endif /* #if defined(__DRM_V02__)*/        
            }
            SetRightSoftkeyFunction(fmgr_abort_app_select, KEY_EVENT_UP);
            break;

        case FMGR_SELECT_BROWSE:
            /* browse file */
            if (file_info.attribute & FS_ATTR_DIR)
            {
                ChangeLeftSoftkey(0, 0);
            }
            else
            {
            #if defined(__DRM_V02__)
                if ((is_multi_odf == MMI_TRUE) && !(fmgr_p->sel_type & FMGR_SELECT_ARCHIVE))
                {
                    if (fmgr_p->sel_type & FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT)
                    {
                        ChangeLeftSoftkey(0, 0);
                        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                    }
                    else
                    {
                        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                        SetLeftSoftkeyFunction(entry_fmgr_app_browse_multi_odf_menu, KEY_EVENT_UP);
                    #ifdef __MMI_TOUCH_SCREEN__
                        wgui_register_list_item_selected_callback(entry_fmgr_app_browse_multi_odf_menu);
                    #endif 
                    }
                }
                else
                {
                    if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_ODF))
                    {
                        if (!FMGR_FILTER_IS_SET(&fmgr_p->filter_type , file_type))
                        {     
                            ChangeLeftSoftkey(0, 0);
                            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                        }
                        else
                        {
                            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                            SetLeftSoftkeyFunction(entry_fmgr_app_file_option, KEY_EVENT_UP);
                        }
                    }
                    else
                    {
                        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                        SetLeftSoftkeyFunction(entry_fmgr_app_file_option, KEY_EVENT_UP);
                    }
                }
            #else /* #if defined(__DRM_V02__) */
                ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                SetLeftSoftkeyFunction(entry_fmgr_app_file_option, KEY_EVENT_UP);
            #endif /* #if defined(__DRM_V02__) */
            }
            SetRightSoftkeyFunction(fmgr_abort_app_select, KEY_EVENT_UP);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_tree_node
 * DESCRIPTION
 *  highlight handler for folder when select destination for copy or move
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_tree_node(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->cur_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_tree_open
 * DESCRIPTION
 *  highlight handler for open folder in tree explorer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_tree_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_set_curr_tree_and_enter, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_open
 * DESCRIPTION
 *  highlight handler for open folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_set_curr_path_and_enter, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_create_folder
 * DESCRIPTION
 *  highlight handler for create folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_create_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_create_folder_hdlr, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_app_select
 * DESCRIPTION
 *  highlight handler for select folder by app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_app_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_return_to_app, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_folder_done
 * DESCRIPTION
 *  highlight handler for confirm create folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_folder_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_create_folder, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_view_image
 * DESCRIPTION
 *  highlight handler for view image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_view_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fmgr_view_image_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_view_image_hdlr, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(fmgr_view_image_hdlr);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_edit_image
 * DESCRIPTION
 *  highlight handler for edit image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_edit_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fmgr_edit_image_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_edit_image_hdlr, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(fmgr_edit_image_hdlr);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_play_audio
 * DESCRIPTION
 *  highlight handler for play audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_play_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fmgr_play_audio_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_play_audio_hdlr, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(fmgr_play_audio_hdlr);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_play_video
 * DESCRIPTION
 *  highlight handler for play video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_play_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fmgr_play_video_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_play_video_hdlr, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(fmgr_play_video_hdlr);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_execute
 * DESCRIPTION
 *  highlight handler for install java
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_execute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_execute_hdlr, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_sort
 * DESCRIPTION
 *  highlight handler for sort
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_sort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(entry_fmgr_sort_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(entry_fmgr_sort_option, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(entry_fmgr_sort_option);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_forward
 * DESCRIPTION
 *  highlight handler for forward file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(entry_fmgr_forward_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(entry_fmgr_forward_option, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(entry_fmgr_forward_option);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_detail
 * DESCRIPTION
 *  highlight handler for display detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(entry_fmgr_detail, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(entry_fmgr_detail, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(entry_fmgr_detail);
#endif 
}


#ifdef __DRM_MTK__
/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_drm_rights_detail
 * DESCRIPTION
 *  highlight handler for drm rights detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_drm_rights_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(entry_fmgr_rights_detail, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(entry_fmgr_rights_detail, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(entry_fmgr_rights_detail);
#endif 
}
#endif /* __DRM_MTK__ */

#if defined(__MMI_EXIF__)


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_jpg_detail
 * DESCRIPTION
 *  highlight handler for display jpg exif detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_jpg_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(entry_fmgr_jpg_detail, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(entry_fmgr_jpg_detail, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(entry_fmgr_jpg_detail);
#endif 
}
#endif /* defined(__MMI_EXIF__) */ 


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_rename
 * DESCRIPTION
 *  highlight handler for rename file or folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_rename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fmgr_rename_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_rename_hdlr, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(fmgr_rename_hdlr);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_rename_done
 * DESCRIPTION
 *  highlight handler for confrim rename
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_rename_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_rename, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_delete
 * DESCRIPTION
 *  highlight handler for delete file or folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->delete_all = FMGR_DELETE_SINGLE;
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(entry_fmgr_delete_confirm, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_delete_all_file
 * DESCRIPTION
 *  highlight handler for delete all files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_delete_all_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->delete_all = FMGR_DELETE_ALL;
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(entry_fmgr_delete_confirm, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}

/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_drm_rights_delete_all_expired
 * DESCRIPTION
 *  highlight handler for drm rights delete all expired
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_drm_rights_delete_all_expired(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->delete_all = FMGR_DELETE_ALL_EXPIRED;
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(entry_fmgr_delete_confirm, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_copy
 * DESCRIPTION
 *  highlight handler for copy file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_copy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_copy_hdlr, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_move
 * DESCRIPTION
 *  highlight handler for move file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_move(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_move_hdlr, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_tree_copy
 * DESCRIPTION
 *  highlight handler for confrim copy to a selected destination folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_tree_copy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_copy, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_sort_by_name
 * DESCRIPTION
 *  highlight handler for sort by name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_sort_by_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->sort_option = FS_SORT_NAME;
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_sort_by_type
 * DESCRIPTION
 *  highlight handler for sort by type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_sort_by_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->sort_option = FS_SORT_TYPE;
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_sort_by_time
 * DESCRIPTION
 *  highlight handler for sort by time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_sort_by_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->sort_option = FS_SORT_TIME;
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_sort_by_size
 * DESCRIPTION
 *  highlight handler for sort by size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_sort_by_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->sort_option = FS_SORT_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_sort_none
 * DESCRIPTION
 *  highlight handler for no sort
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_sort_none(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->sort_option = FS_NO_SORT;
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_to_wallpaper
 * DESCRIPTION
 *  highlight handler for forward to wallpaper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_to_wallpaper(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_FWD_WALLPAPER;
    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_to_sub_wallpaper
 * DESCRIPTION
 *  highlight handler for forward to wallpaper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_to_sub_wallpaper(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_FWD_SUB_WALLPAPER;
    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_to_screensaver
 * DESCRIPTION
 *  highlight handler for forward to screen saver
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_to_screensaver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_FWD_SCREENSAVER;
    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_to_power_on_display
 * DESCRIPTION
 *  highlight handler for forward to screen saver
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_to_power_on_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_FWD_POWER_ON;
    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_to_power_off_display
 * DESCRIPTION
 *  highlight handler for forward to screen saver
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_to_power_off_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_FWD_POWER_OFF;
    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_to_phb
 * DESCRIPTION
 *  highlight handler for forward to phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_to_phb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_FWD_PHONEBOOK;
    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_to_todolist
 * DESCRIPTION
 *  highlight handler for forward to to do list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_to_todolist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_FWD_TODOLIST;
    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_to_sms
 * DESCRIPTION
 *  highlight handler for forward to sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_to_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_FWD_SMS;
    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_to_ems
 * DESCRIPTION
 *  highlight handler for forward to ems
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_to_ems(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_FWD_EMS;
    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_to_mms
 * DESCRIPTION
 *  highlight handler for forward to mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_to_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_FWD_MMS;
    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_to_email
 * DESCRIPTION
 *  highlight handler for forward to email
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_to_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_FWD_EMAIL;
    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_to_irda
 * DESCRIPTION
 *  highlight handler for forward to irda
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_to_irda(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_FWD_IRDA;
    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_to_bt
 * DESCRIPTION
 *  highlight handler for forward to irda
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_to_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_FWD_BT;
    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_to_profile
 * DESCRIPTION
 *  highlight handler for forward to profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_to_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_FWD_PROFILE;
    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_to_bgsound
 * DESCRIPTION
 *  highlight handler for forward to background sound
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_to_bgsound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_FWD_BGSOUND;
    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
}


#if defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_BPP_SUPPORT__)

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void fmgr_prepare_print_option(fmgr_filter_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_PICT_BRIDGE_SUPPORT__)
    if(type == FMGR_TYPE_JPG || type == FMGR_TYPE_JPEG)
    {
        mmi_frm_unhide_menu_item(MENU_FMGR_PRINT_PICTBRIGE);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_FMGR_PRINT_PICTBRIGE);
    }
#endif

#if defined(__MMI_BPP_SUPPORT__)

    /* allow print when
     *   1. not in flight mode
     */
    if (!mmi_bootup_get_active_flight_mode())
    {
        mmi_frm_unhide_menu_item(MENU_FMGR_PRINT_BLUETOOTH);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_FMGR_PRINT_BLUETOOTH);
    }
    
#endif

    if (GetNumOfChild_Ext(MENU_FMGR_GEN_OPTION_PRINT))
    {
        mmi_frm_unhide_menu_item(MENU_FMGR_GEN_OPTION_PRINT);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_FMGR_GEN_OPTION_PRINT);
    }
}

/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_print
 * DESCRIPTION
 *  highlight handler for print 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_print(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(entry_fmgr_print_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(entry_fmgr_print_option, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(entry_fmgr_print_option);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_print_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_print_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    U16 nNumofItem;
    U8 *guiBuffer;
    U16 nStrItemList[20];
    U16 imageId = 0;
    MMI_BOOL allow_print = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_check_file_present() < FMGR_NO_ERROR)
    {
        return;
    }

    /* show menu according to file type */
    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

#ifdef __DRM_SUPPORT__

    if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == TRUE
#ifndef __MMI_SHOW_FILE_EXT__
        && mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == TRUE
#endif 
        )
    {
        FS_HANDLE handle;
        handle = DRM_open_file((PU16) fmgr_p->file_path, FS_READ_ONLY, DRM_PERMISSION_PRINT);
        if (handle > FS_NO_ERROR)
        {
            allow_print = DRM_validate_permission(handle, NULL, DRM_PERMISSION_PRINT);
       #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* if 0 */
            /* non DRM file, can forward to anywhere */
            DRM_close_file(handle);

            if (allow_print == MMI_FALSE)
            {
                DisplayPopup((U8*) GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
                mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
                return;
            }
    
        }
        else
        {
            /* open file fail */
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            return;
        }    
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    }
#endif /* __DRM_SUPPORT__ */ 

    fmgr_prepare_print_option(mmi_fmgr_get_file_type_by_filename(file_info.file_name));

    nNumofItem = GetNumOfChild_Ext(MENU_FMGR_GEN_OPTION_PRINT);
    if (nNumofItem == 0)
    {
        DisplayPopup((U8*) GetString(STR_FMGR_INVALID_FORMAT), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
        return;
    }

    EntryNewScreen(SCR_FMGR_PRINT_OPTION, NULL, entry_fmgr_print_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_PRINT_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    GetSequenceStringIds_Ext(MENU_FMGR_GEN_OPTION_PRINT, nStrItemList);
    SetParentHandler(MENU_FMGR_GEN_OPTION_PRINT);

    imageId = fmgr_get_app_title_icon_id();

#ifdef __MMI_BPP_SUPPORT__
    if (mmi_imgview_is_printing())
    {
        mmi_imgview_cancel_printing();
    }
#endif

    ShowCategory15Screen(
        STR_ID_FMGR_PRINT,
        imageId,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;

}


#endif /* defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_BPP_SUPPORT__)*/


#if defined(__MMI_PICT_BRIDGE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_print_to_pictbrige
 * DESCRIPTION
 *  highlight handler for print to picture brige
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_print_to_pictbrige(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_PRINT_TO_PICTBRIGE;
    SetLeftSoftkeyFunction(fmgr_print_to_pictbrige, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_print_to_pictbrige
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_print_to_pictbrige(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOAD_AGENT__
    /* download agent file */
    if (fmgr_is_da_file())
    {
        FS_HANDLE handle;

        /* Check if file exists or not */
        handle = FS_Open((PU16) fmgr_p->da_file_path, FS_READ_ONLY);
        if (handle > FS_NO_ERROR)
        {
        	FS_Close(handle);
        }
        else
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION);
            return;
        }
        
        mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->da_file_path);

    #if defined(__DRM_V02__)        
        {
            S32 file_type = 0;
            
        file_type = mmi_fmgr_get_drm_file_type_by_path((PS8) fmgr_p->file_path, &file_info.file_type);
            
        if (file_type == FMGR_TYPE_ODF)
        {
            /* multi part ODF */
            mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
    
            if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
        #ifndef __MMI_SHOW_FILE_EXT__
                || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
        #endif 
                )
                return;
        }
        }
    #else
        mmi_fmgr_get_file_type((PS8) fmgr_p->da_file_path, &file_info.file_type);
    #endif /* defined(__DRM_V02__) */
    
        file_info.is_short = FALSE;
    }
    /* non download agent file */
    else
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
    {
        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

        if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
    #ifndef __MMI_SHOW_FILE_EXT__
            || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
    #endif 
            )
            return;

        DeleteUptoScrID(SCR_FMGR_EXPLORER);
    }

    mmi_pict_print_file_forward_from_fmgr((PS8) fmgr_p->file_path, &file_info.file_type, (int)file_info.is_short);

    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    DeleteScreenIfPresent(SCR_FMGR_PRINT_OPTION);
}

#endif /* (__MMI_PICT_BRIDGE_SUPPORT__) */


#if defined(__MMI_BPP_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_print_to_bluetooth
 * DESCRIPTION
 *  highlight handler for print to bluetooth BPP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_print_to_bluetooth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_PRINT_TO_BLUETOOTH;
    SetLeftSoftkeyFunction(fmgr_print_to_bluetooth, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_print_to_bluetooth
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_print_to_bluetooth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

        if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
    #ifndef __MMI_SHOW_FILE_EXT__
            || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
    #endif 
            )
            return;

        DeleteUptoScrID(SCR_FMGR_EXPLORER);
    mmi_imgview_bpp_print_file ((PS8) fmgr_p->file_path, file_info.is_short);

    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    DeleteScreenIfPresent(SCR_FMGR_PRINT_OPTION);
}

#endif /* __MMI_BPP_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_input_method
 * DESCRIPTION
 *  highlight handler for change input method in editor option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* SetInputMethodAndDoneCaptionIcon(IMG_SCR_PBOOK_CAPTION); */
//    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}

#if defined (__FS_CARD_SUPPORT__)

/*****************************************************************************
 * FUNCTION
 *  fmgr_msdc_plug_in_hdlr
 * DESCRIPTION
 *  msdc plug in message handler
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_msdc_plug_in_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_mmi_card_plug_in_ind_struct *msg_ptr;
    U8 popup_flag;

    /* Lisen 0623 */
    mmi_fmt_get_msdc_status_rsp_strcut card_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (fmt_mmi_card_plug_in_ind_struct*) info;

    /* Lisen 0623 */
    card_status.present = MMI_TRUE;
    card_status.type = msg_ptr->type;
    FM_MemoryCardResponseHandler(&card_status);

    if (mmi_bootup_is_in_power_on_period() == MMI_FALSE)
    {
        TurnOnBacklight(1);
        /* Application who wanna stop popup has to intercept related messages and set the flag */
        popup_flag = GetInterruptPopupDisplay();
        if ((popup_flag & POPUP_DSPL_ON) != 0)
        {
            DisplayPopup((PU8) GetString(STR_FMGR_REMOVABLE_PLUGIN), IMG_GLOBAL_INFO, 0, 1000, AUX_TONE);
        }

    #ifdef __MMI_AUDIO_PLAYER__
        mmi_audply_msdc_plug_in_hdlr(TRUE);
    #endif 
    #ifdef __MMI_JATAAYU_BRW_OFFLINE_PAGES__
        mmi_brw_msdc_plug_in_hdlr();
    #endif
        return;
    }
#ifdef __MMI_AUDIO_PLAYER__
    mmi_audply_msdc_plug_in_hdlr(FALSE);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_msdc_plug_out_hdlr
 * DESCRIPTION
 *  msdc plug out message handler
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_msdc_plug_out_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Lisen 0623 */
    mmi_fmt_get_msdc_status_rsp_strcut card_status;
    U16 marker_screen = 0, start_screen = 0, end_screen = 0;
    U8 popup_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Lisen 0623 */
    card_status.present = MMI_FALSE;
    FM_MemoryCardResponseHandler(&card_status);

    if (mmi_bootup_is_in_power_on_period() == MMI_FALSE)
    {
        U16 strId;
        fmt_mmi_msdc_ind_struct *msg_ptr;

        TurnOnBacklight(1);
        msg_ptr = (fmt_mmi_msdc_ind_struct*) info;
        if (msg_ptr->cause == FS_NO_ERROR || msg_ptr->cause == FS_MSDC_NOT_PRESENT)
        {
            strId = STR_FMGR_REMOVABLE_PLUGOUT;
        }
        else
        {
            strId = GetFileSystemErrorString(msg_ptr->cause);
        }

        /* Application who wanna stop popup has to intercept related messages and set the flag */
        popup_flag = GetInterruptPopupDisplay();
        if ((popup_flag & POPUP_DSPL_ON) != 0)
        {
            DisplayPopup((PU8) GetString(strId), IMG_GLOBAL_INFO, 0, 1000, AUX_TONE);
        }

    #ifdef __MMI_AUDIO_PLAYER__
        mmi_audply_msdc_plug_out_hdlr(TRUE);
    #endif 
    }
    else
    {
    #ifdef __MMI_AUDIO_PLAYER__
        mmi_audply_msdc_plug_out_hdlr(FALSE);
    #endif 
    }

#ifdef __MMI_BG_SOUND_EFFECT__
    mmi_bgsnd_util_setup_sd_plug_out_hdlr();
    mmi_bgsnd_util_calling_sd_plug_out_hdlr();
#endif /* __MMI_BG_SOUND_EFFECT__ */ 

#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_uc_sd_plug_out_hdlr();
#endif /* __MMI_UNIFIED_COMPOSER__ */

#ifdef __MMI_BPP_SUPPORT__
        mmi_bt_bpp_plug_out_hdlr();
#endif /* __MMI_BPP_SUPPORT__ */

#ifdef __MMI_LANGLN__
    mmi_langln_card_plug_out_hdlr();
#endif /*__MMI_LANGLN__*/

#ifdef __MMI_SWFLASH__
        mmi_swflash_card_plug_out_hdlr();
#endif

#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
        mmi_brw_sd_plug_out_hdlr();
#endif

#if defined (JATAAYU_SUPPORT) && defined (MMS_SUPPORT)
        mmi_jmms_sd_plug_out_hdlr();
#endif

#if defined(__MMI_BROWSER_2__)
        mmi_brw_memory_card_plug_out_hdlr();
#endif /* (__MMI_BROWSER_2__) */

#ifdef __MMI_THEMES_V2_SUPPORT__
        mmi_thm_card_plug_out_hdlr();
#endif

    /* Reset hash table */
    memset(fmgr_p->parent_idx_hash_table, 0, sizeof(fmgr_p->parent_idx_hash_table));

    if (isInCall() == TRUE)
    {
        marker_screen = GetCmMarkerScrnID();
    }
    else if (AlmIsTonePlaying() == TRUE)
    {
    #if defined(__MMI_TODOLIST__)
        if (IsScreenPresent(SCR_TDL_REMINDER))
        {
            marker_screen = SCR_TDL_REMINDER;
        }
        else
        {
            marker_screen = SCR_ID_ALM_INDICATION;
        }
    #else /* defined(__MMI_TODOLIST__) */ 
        marker_screen = SCR_ID_ALM_INDICATION;
    #endif /* defined(__MMI_TODOLIST__) */ 
    }
    if (marker_screen != 0)
    {
        GetPreviousScrnIdOf(marker_screen, &end_screen);
    }

    switch (fmgr_p->src_application)
    {
        case APP_FILEMANAGER:
            /* currently in FileMgr application,
               go back to root after display pop up */
            if (end_screen == 0)
            {
                DeleteUptoScrID(SCR_FMGR_MAIN);
            }
            else
            {
            	 U16 tmp;
            	 
                GetNextScrnIdOf(SCR_FMGR_MAIN, &start_screen);
                GetPreviousScrnIdOf(end_screen, &tmp);
                if (tmp != start_screen && start_screen != 0 && start_screen != marker_screen)
                DeleteBetweenScreen(start_screen, end_screen);
            }
            break;
        case APP_PHONEBOOK:
        case APP_PHONESETUP:
            break;

        #ifdef __MMI_SOUND_RECORDER__
        case APP_SOUNDRECORDER:
            if (end_screen == 0)
            {
                DeleteUptoScrID(SCR_FMGR_EXPLORER);
            }
            else
            {
                //GetNextScrnIdOf(SCR_FMGR_EXPLORER, &start_screen);
                if (IsScreenPresent(SCR_FMGR_EXPLORER) && SCR_FMGR_EXPLORER != marker_screen)
                DeleteBetweenScreen(SCR_FMGR_EXPLORER, end_screen);
            }
            break;
        #endif /* __MMI_SOUND_RECORDER__ */ 

        #ifdef __MMI_AB_REPEATER__
        case APP_ABREPEATER:
            if (end_screen == 0)
            {
                DeleteUptoScrID(SCR_FMGR_EXPLORER);
            }
            else
            {
                //GetNextScrnIdOf(SCR_FMGR_EXPLORER, &start_screen);
                if (IsScreenPresent(SCR_FMGR_EXPLORER) && SCR_FMGR_EXPLORER != marker_screen)
                DeleteBetweenScreen(SCR_FMGR_EXPLORER, end_screen);
            }
            break;
        #endif /* __MMI_AB_REPEATER__ */ 

        #ifdef __MMI_IMAGE_VIEWER__
        case APP_IMAGEVIEWER:
            if (end_screen == 0)
            {
                DeleteUptoScrID(SCR_ID_IMGVIEW_APP);
            }
            else
            {
                //GetNextScrnIdOf(SCR_ID_IMGVIEW_APP, &start_screen);
                if (IsScreenPresent(SCR_ID_IMGVIEW_APP) && SCR_ID_IMGVIEW_APP != marker_screen)
                DeleteBetweenScreen(SCR_ID_IMGVIEW_APP, end_screen);
            }
            break;
        #endif /* __MMI_IMAGE_VIEWER__ */ 

        #ifdef __MMI_VIDEO_PLAYER__
        case APP_VDOPLY:
            if (end_screen == 0)
            {
                DeleteUptoScrID(SCR_ID_VDOPLY_APP);
            }
            else
            {
                //GetNextScrnIdOf(SCR_ID_VDOPLY_APP, &start_screen);
                if (IsScreenPresent(SCR_ID_VDOPLY_APP) && SCR_ID_VDOPLY_APP != marker_screen)
                DeleteBetweenScreen(SCR_ID_VDOPLY_APP, end_screen);
            }
            break;
        #endif /* __MMI_VIDEO_PLAYER__ */ 

#ifdef __MMI_SWFLASH__
        case APP_SWFLASH:
            if (end_screen == 0)
            {
                DeleteUptoScrID(SCR_ID_SWFLASH_APP);
            }
            else
            {
                //GetNextScrnIdOf(SCR_SWFLASH_APP, &start_screen);
                if (IsScreenPresent(SCR_ID_SWFLASH_APP) && SCR_ID_SWFLASH_APP != marker_screen)
                DeleteBetweenScreen(SCR_ID_SWFLASH_APP, end_screen);
            }
            break;
#endif /* __MMI_SWFLASH__ */ 
		#ifdef __MMI_EBOOK_READER__
        case APP_EBOOK:
            if (end_screen == 0)
            {
                DeleteUptoScrID(EBOOK_BOOKSHELF_SCREENID);
            }
            else
            {
                if (IsScreenPresent(EBOOK_BOOKSHELF_SCREENID) && EBOOK_BOOKSHELF_SCREENID != marker_screen)
                DeleteBetweenScreen(EBOOK_BOOKSHELF_SCREENID, end_screen);
            }
            break;
        #endif /* __MMI_EBOOK_READER__ */ 
        #ifdef __MMI_EMAIL__
        case APP_EMAIL:
            if (end_screen == 0)
            {
                DeleteUptoScrID(SCR_FMGR_MAIN);
            }
            else
            {
                if (IsScreenPresent(SCR_FMGR_EXPLORER) && SCR_FMGR_EXPLORER != marker_screen)
                    DeleteBetweenScreen(SCR_FMGR_EXPLORER, end_screen);
            }
            break;
        #endif /* #ifdef __MMI_EMAIL__ */       
        #ifdef __MMI_FM_RADIO_RECORD__
        case APP_FMRDO:
            if (end_screen == 0)
            {
                DeleteUptoScrID(SCR_FMGR_EXPLORER);
            }
            else
            {
                //GetNextScrnIdOf(SCR_FMGR_EXPLORER, &start_screen);
                if (IsScreenPresent(SCR_FMGR_EXPLORER) && SCR_FMGR_EXPLORER != marker_screen)
                DeleteBetweenScreen(SCR_FMGR_EXPLORER, end_screen);
            }
            break;
        #endif /* __MMI_FM_RADIO_RECORD__ */  
        default:
            /* not on FileMgr screen, don't do anything */
            break;
    }
}
#endif /* defined (__FS_CARD_SUPPORT__) */ 

#ifdef __OTG_ENABLE__


/*****************************************************************************
 * FUNCTION
 *  fmgr_otg_display_hdlr
 * DESCRIPTION
 *  msdc plug in message handler
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_otg_display_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    otg_display_struct *msg_ptr;
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (otg_display_struct*) info;
    switch (msg_ptr->type)
    {
        case OTG_DISPLAY_MSG_UN_SUPPORT:
            str_id = STR_FMGR_OTG_UNSUPPORT;
            break;
        case OTG_DISPLAY_MSG_CONNECTING:
            str_id = STR_FMGR_OTG_CONNECTING;
            break;
        case OTG_DISPLAY_MSG_STOP_CONNECTING:
            str_id = STR_FMGR_OTG_STOP_CONNECTING;
            break;
        case OTG_DISPLAY_MSG_NO_RESPONSE:
            str_id = STR_FMGR_OTG_NO_RESPONSE;
            break;
        case OTG_DISPLAY_MSG_HNP_PROCESS:
            str_id = STR_FMGR_OTG_HNP_PROCESS;
            break;
        case OTG_DISPLAY_MSG_HNP_STOP:
            str_id = STR_FMGR_OTG_HNP_STOP;
            break;
        default:
            break;
    }

    if (str_id != 0 && mmi_bootup_is_in_power_on_period() == MMI_FALSE)
    {
        TurnOnBacklight(1);
        DisplayPopup((PU8) GetString(str_id), IMG_GLOBAL_INFO, 0, 1000, WARNING_TONE);
        return;
    }
}

#endif /* __OTG_ENABLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  fmgr_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->src_application = APP_FILEMANAGER;
    FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
    fmgr_p->tree_action = FMGR_ACTION_NONE;
#ifdef __MMI_DOWNLOAD_AGENT__
    memset(fmgr_p->da_file_path, 0, sizeof(fmgr_p->da_file_path));
#endif 

    memset(fmgr_p->parent_idx_hash_table, 0, sizeof(fmgr_p->parent_idx_hash_table));

    entry_fmgr_main();
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, drv_idx;
    U8 *guiBuffer;
    U16 drive_count, lsk_str = 0, lsk_img = 0, imageId = 0, titleId = STR_FMGR_TITLE;
    pBOOL thick_style = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        drive_count = 0; 
        guiBuffer = NULL; 
        thick_style = FALSE; 
        EntryNewScreen(SCR_FMGR_MAIN, NULL, entry_fmgr_main, NULL); 
        goto _draw_drive; 
        return;
    }
    
    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_MAIN);

    /* init active explorer as default explorer */
    fmgr_p->active_explorer_screen = SCR_FMGR_EXPLORER;

    fmgr_p->cache_end_idx = 0;
    fmgr_p->cache_start_idx = 0;
    memset((PU8) fmgr_p->file_cache, 0, sizeof(FMGR_FILE_INFO_STRUCT) * FMGR_CACHE_ENTRY_COUNT);

#if 0
#if defined(MT6223P)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* if 0 */

    if (fmgr_is_msdc_present() == FALSE)
    {
        PRINT_INFORMATION("No Card\n");
    }

    if (fmgr_p->drv_count == 0)
    {
        PRINT_INFORMATION("No Drive\n");
    #ifdef __USB_IN_NORMAL_MODE__
        if (mmi_usb_is_in_mass_storage_mode())
        {
            DisplayPopup((PU8) GetString(STR_ID_USB_MODE_EXPORTED_WARNING), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
        }
        else
    #endif /* __USB_IN_NORMAL_MODE__ */ 
            DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 0, 1000, EMPTY_LIST_TONE);
        if (fmgr_p->src_application != APP_FILEMANAGER)
        {
            fmgr_abort_app_select();
        }
        return;
    }

    for (i = 0; i < FMGR_TOTAL_STORAGE && fmgr_p->drv_list[i][0] != 0; i++)
    {
        if (FS_GetDevStatus(fmgr_p->drv_list[i][0], FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
        {
            DisplayPopup((PU8) GetString(FMGR_FS_DEVICE_BUSY_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            if (fmgr_p->src_application != APP_FILEMANAGER)
            {
                fmgr_abort_app_select();
            }
            return;
        }
    }

    EntryNewScreen(SCR_FMGR_MAIN, NULL, entry_fmgr_main, NULL);

    RegisterHighlightHandler(highlight_fmgr_drive_list);

    if (fmgr_p->src_application == APP_FILEMANAGER)
    {
        if (fmgr_p->tree_action == FMGR_ACTION_COPY)
        {
            thick_style = TRUE;
            titleId = STR_FMGR_COPY;
        }
        else if (fmgr_p->tree_action == FMGR_ACTION_MOVE)
        {
            thick_style = TRUE;
            titleId = STR_FMGR_MOVE;
        }
    }
    else
    {
        if ((fmgr_p->src_application == APP_IMAGEVIEWER) || (fmgr_p->src_application == APP_VDOPLY))
        {
            thick_style = TRUE;
        }
    }

    DeleteScreenIfPresent(SCR_FMGR_TREE_EXPLORER);
    DeleteScreenIfPresent(SCR_FMGR_FILE_OPTION);
    if (fmgr_p->tree_action == FMGR_ACTION_NONE)
    {
        DeleteScreenIfPresent(SCR_FMGR_EXPLORER);
    }

    /* get actual drive count */
    drive_count = 0;

    for (i = 0; i < fmgr_p->drv_count; i++)
    {
        drv_idx = fmgr_get_drive_index(i);

        if (drv_idx >= FMGR_REMOVABLE_STORAGE)
        {
            /* test if card is actually present */
            drive_count += fmgr_is_msdc_present();
            break;
        }
        else
        {
            drive_count++;
        }
    }

    if (drive_count > 0)
    {
        lsk_str = STR_GLOBAL_OPTIONS;
        lsk_img = IMG_GLOBAL_OPTIONS;
    }

_draw_drive: 
    imageId = fmgr_get_app_title_icon_id();

    if (thick_style == TRUE)
    {
        ShowCategory213Screen(
            titleId,
            imageId,            /* title */
            lsk_str,
            lsk_img,            /* lsk */
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,    /* rsk */
            drive_count,
            mmi_fmgr_draw_drv_menuitem_callback,
            mmi_fmgr_hide_drv_menuitem_callback,
            0,                  /* hiligth item idx */
            CAT213_ARROW_ALL,
            (U8*) guiBuffer);
    }
    else
    {
        ShowCategory212Screen(
            titleId,
            imageId,            /* title */
            lsk_str,
            lsk_img,            /* lsk */
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,    /* rsk */
            drive_count,
            mmi_fmgr_get_drv_item_callback,
            mmi_fmgr_get_drv_hint_callback,
            mmi_fmgr_draw_drv_info_callback,
            mmi_fmgr_hide_drv_info_callback,
            2,                  /* info box row count */
            0,                  /* info bg img id */
            0,
            (U8*) guiBuffer);
    }

    if (drive_count == 0)
    {
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_drive_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_drive_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem, iconId;
    U16 nStrItemList[20];
    U16 scrId = SCR_FMGR_DRIVE_OPTION;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_GetDevStatus(fmgr_p->file_path[0], FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
    {
        DisplayPopup((PU8) GetString(FMGR_FS_DEVICE_BUSY_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_reset_list_item_selected_callback();
    #endif 
        return;
    }

    mmi_frm_unhide_menu_item(MENU_FMGR_DRIVE_FORMAT);
    
    if (fmgr_p->src_application == APP_FILEMANAGER)
    {
        if (fmgr_p->tree_action == FMGR_ACTION_COPY || fmgr_p->tree_action == FMGR_ACTION_MOVE)
        {
            scrId = SCR_FMGR_TREE_DRIVE_OPTION;
            nNumofItem = GetNumOfChild(MITEM_FMGR_TREE_OPTIONS);
            GetSequenceStringIds(MITEM_FMGR_TREE_OPTIONS, nStrItemList);
            SetParentHandler(MITEM_FMGR_TREE_OPTIONS);
        }
        else
        {
            nNumofItem = GetNumOfChild(MITEM_FMGR_DRIVE_OPTIONS);
            GetSequenceStringIds(MITEM_FMGR_DRIVE_OPTIONS, nStrItemList);
            SetParentHandler(MITEM_FMGR_DRIVE_OPTIONS);

        #ifndef __MSDC_NOT_SUPPORT_HOT_PLUG__
            switch (fmgr_get_drive_index(fmgr_p->cur_index))
            {
                case FMGR_NAND_STORAGE:
                    /* highlight NAND Drive, hide unmount option */
                    nNumofItem--;
                    break;
                case FMGR_NOR_STORAGE:
                    /* highli NOR Drive, hide unmount option */
                    nNumofItem--;
                    break;
                case FMGR_REMOVABLE_STORAGE:
                    /* highlight removable drive */
                    break;
            #ifdef __SIM_PLUS__
                case FMGR_SIM_PLUS_1_STORAGE:
                case FMGR_SIM_PLUS_2_STORAGE:
                case FMGR_SIM_PLUS_3_STORAGE:
                case FMGR_SIM_PLUS_4_STORAGE:            
                    /* highlight SIM+ Drive, hide unmount option */
                    nNumofItem--;
                    /* hide format option */
                    mmi_frm_hide_menu_item(MENU_FMGR_DRIVE_FORMAT);
                    nNumofItem--;
                    break;
            #endif /* __SIM_PLUS__ */
            #ifdef __MSDC2_SD_MMC__
                case FMGR_MSDC2_SD_STORAGE:
                    /* highlight removable drive */
                    break;
            #endif
                default:
                    /* wrong index, hide unmount option */
                    nNumofItem--;
                    break;
            }
        #endif /* __MSDC_NOT_SUPPORT_HOT_PLUG__ */ 
        }
    }
    else
    {
        /* other app for select */
        nNumofItem = GetNumOfChild(MITEM_FMGR_APP_DRIVE_OPTIONS);
        GetSequenceStringIds(MITEM_FMGR_APP_DRIVE_OPTIONS, nStrItemList);
        SetParentHandler(MITEM_FMGR_APP_DRIVE_OPTIONS);
    }

    EntryNewScreen(scrId, NULL, entry_fmgr_drive_option, NULL);

    guiBuffer = GetCurrGuiBuffer(scrId);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    iconId = fmgr_get_app_title_icon_id();

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        iconId,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_drive_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_drive_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 stringId;
    S8 index;
    U8 str[100];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (fmgr_p->drive_action)
    {
        case FMGR_ACTION_FORMAT:
            index = fmgr_get_drive_index(fmgr_p->cur_index);
            if (index == FMGR_REMOVABLE_STORAGE)
            {
                stringId = STR_FMGR_FORMAT;
            }
            else
            {
            #if (!defined(APP_STORAGE_IN_SYS_DRV)) && defined(__MMI_EMAIL__)
                stringId = STR_FMGR_FORMAT_CONFIRM;
            #else 
                stringId = STR_FMGR_FORMAT;
            #endif 
            }
            break;
        case FMGR_ACTION_CHECK_DRIVE:
            stringId = STR_FMGR_CHECK_DRIVE;
            break;
        case FMGR_ACTION_UNMOUNT:
            stringId = STR_FMGR_UNMOUNT;
            break;
        default:
            return;
    }


    mmi_ucs2cpy((PS8) str, (PS8) get_string(stringId));
    mmi_ucs2cat((PS8) str, (PS8) get_string(STR_ID_FMGR_QUESTION_MARK));

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU16) str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(fmgr_drive_action_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_drive_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_drive_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 stringId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(0);

    switch (fmgr_p->drive_action)
    {
        case FMGR_ACTION_FORMAT:
            stringId = STR_FMGR_FORMATING;
            break;
        case FMGR_ACTION_CHECK_DRIVE:
            stringId = STR_FMGR_CHECK_DRIVE;
            break;
        case FMGR_ACTION_UNMOUNT:
            stringId = STR_FMGR_UNMOUNTING;
            break;
        default:
            return;
    }

    EntryNewScreen(SCR_FMGR_DRIVE_ANIMATION, exit_fmgr_drive_animation, NULL, NULL);

    ShowCategory66Screen(
        STR_FMGR_TITLE,
        GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID),
        0,
        0,
        0,
        0,
        (PU8) GetString(stringId),
        IMG_GLOBAL_PROGRESS,
        NULL);

    ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    //mmi_frm_set_interrupt_event_handler(fmgr_drvop_incoming_call_interrupt_hdlr,NULL,MSG_ID_MMI_VOIP_CALL_RING_IND);
    //mmi_frm_set_interrupt_event_handler(fmgr_drvop_incoming_call_interrupt_hdlr,NULL,MSG_ID_MMI_CC_CALL_RING_IND);
	mmi_frm_block_interrupt_event_handler(MMI_FRM_INT_VOIP_CALL_RING | MMI_FRM_INT_CC_CALL_RING, 
		fmgr_drvop_incoming_call_interrupt_hdlr, 
		NULL);

    if (!IsScreenPresent(SCR_FMGR_DRIVE_ANIMATION))
    {
        DeleteUptoScrID(SCR_FMGR_MAIN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  exit_fmgr_drive_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_fmgr_drive_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() == FALSE)
    {
        /* pop up interrupt => add to history */
        history currHistory;
        S16 nHistory = 0;

        currHistory.scrnID = SCR_FMGR_DRIVE_ANIMATION;
        currHistory.entryFuncPtr = entry_fmgr_drive_animation;
        mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
        AddHistory(currHistory);
    }
#ifdef __FS_CHECKDRIVE_SUPPORT__
    else
    {
        /* interrupt by Call => abort check drive */
        if (fmgr_p->drive_action == FMGR_ACTION_CHECK_DRIVE)
        {
            FS_Abort(FS_ABORT_CHECK_DRIVE);
            FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
            fmgr_p->tree_action = FMGR_ACTION_NONE;
            fmgr_p->enter_folder = TRUE;
        }
    }
    
    /* un-hook msg */
    //SetInterruptEventHandler(NULL,NULL,MSG_ID_MMI_VOIP_CALL_RING_IND);
    //SetInterruptEventHandler(NULL,NULL,MSG_ID_MMI_CC_CALL_RING_IND);
	mmi_frm_clear_interrupt_event_handler(MMI_FRM_INT_VOIP_CALL_RING | MMI_FRM_INT_CC_CALL_RING);
#endif /* __FS_CHECKDRIVE_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_create_folder_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_create_folder_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(fmgr_p->new_file_name, 0, sizeof(fmgr_p->new_file_name));
    entry_fmgr_filename_editor();
    SetHiliteHandler(MENU_FMGR_EDITOR_DONE, highlight_fmgr_folder_done);
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_explorer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_explorer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 highlightId = 0;
    U16 count, iconId;
    U8 arrow_display;

#ifdef __MMI_IMAGE_VIEWER__
    U16 imgview_style;
    S32 box_width;
    S32 box_height;
#endif /* __MMI_IMAGE_VIEWER__ */ 

#ifdef __MMI_MY_FAVORITE__
    S8 my_favorite_path[30];
    S8 drv[4];
    U16 mf_title;
    U16 mf_icon;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        count = 0; 
        EntryNewScreen(SCR_FMGR_EXPLORER, exit_fmgr_explorer, NULL, NULL); 
        guiBuffer = NULL; 
        goto _draw_menu; 
        return;
    }

    if (FS_GetDevStatus(fmgr_p->file_path[0], FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
    {
        DisplayPopup((PU8) GetString(FMGR_FS_DEVICE_BUSY_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_reset_list_item_selected_callback();
    #endif 
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
        DeleteScreenIfPresent(SCR_FMGR_FOLDER_OPTION);
        DeleteScreenIfPresent(SCR_FMGR_DRIVE_OPTION);
        return;
    }

    if (fmgr_p->src_application != APP_FILEMANAGER &&
        (GetExitScrnID() == SCR_FMGR_MUL_ODF_EXPLORER ||
         ((mmi_ucs2ncmp((PS8)fmgr_p->file_path + ((mmi_ucs2strlen((PS8)fmgr_p->file_path)-4)<<1), (PS8)L".odf", 4) == 0) ||
          (mmi_ucs2ncmp((PS8)fmgr_p->file_path + ((mmi_ucs2strlen((PS8)fmgr_p->file_path)-4)<<1), (PS8)L".ODF", 4) == 0))))
    {
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    }

    mmi_fmgr_kernel_init((PS8) fmgr_p->file_path, fmgr_p->filter_type, &count);

#ifdef __MMI_MY_FAVORITE__
    /* check if src app = My favorite, when back to root, then go to my favorite main screen */
    if((fmgr_p->src_application == APP_MYFAVORITE) &&
        (fmgr_p->parent_name[0] != 0 || fmgr_p->parent_name[1] != 0))
    {
        sprintf(drv, "%c:\\", (S8) MMI_PUBLIC_DRV);
        mmi_asc_to_ucs2((S8*) my_favorite_path, drv);

        /* check back to root: path = drive:\\ */
        if (mmi_ucs2cmp((PS8) fmgr_p->file_path,(const PS8) my_favorite_path) == 0)
        {
            DeleteScreenIfPresent(SCR_FMGR_EXPLORER);
            memset(fmgr_p->parent_name, 0, sizeof(fmgr_p->parent_name));

            /* go to my favorite main screen */
            mmi_my_favorite_back_to_main();

            /* reset fmgr context */
            fmgr_reset_app_select();
            return;
        }   
    }
#endif

    /* browse type do not pop up empty */
    if (count == 0)
    {
    #ifdef __MMI_MY_FAVORITE__
        /* check if src_app = my_favorite && current file path = sw_flash path,
           if yes, not pop-up empty. because the first menu/item in it is a link, not a file/folder,
           it shouldn't pop-up empty and goback parent. */
        mmi_my_favorite_get_swflash_folder_path(my_favorite_path);
        if((fmgr_p->src_application == APP_MYFAVORITE) && !(mmi_ucs2cmp((PS8)fmgr_p->file_path, (const PS8) my_favorite_path)))
        {
            ; /* no nothing */
        }
        else
    #endif 
        {
        if (fmgr_p->src_application == APP_FILEMANAGER ||
    #if defined(__MMI_IRDA_SUPPORT__) || defined(__MMI_OPP_SUPPORT__) 
            fmgr_p->src_application == APP_EXTDEVICE ||
    #endif 
    #ifdef __MMI_FTS_SUPPORT__
            fmgr_p->src_application == APP_FTP ||
    #endif 
    #ifdef __MMI_BIP_SUPPORT__
            fmgr_p->src_application == APP_BIP ||
    #endif 
    #ifdef __MMI_FM_RADIO_RECORD__
            fmgr_p->src_application == APP_FMRDO ||
    #endif 
    #ifdef __MMI_SWFLASH__
            fmgr_p->src_application == APP_SWFLASH ||
    #endif
       #ifdef __MMI_MY_FAVORITE__
               fmgr_p->src_application == APP_MYFAVORITE ||
       #endif

               (fmgr_p->src_application != APP_FILEMANAGER && 
           #ifdef __MMI_MY_FAVORITE__
                   fmgr_p->src_application != APP_MYFAVORITE &&   /* regard MY_FAVORITE different from other app */
           #endif
                   !(fmgr_p->sel_type & FMGR_SELECT_BROWSE))
                )
            {
                mmi_ucs2_to_asc((PS8) nPrintableStr, (PS8) fmgr_p->file_path);
                PRINT_INFORMATION("entry explorer fail: %s", nPrintableStr);
                mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
	        if (CheckIsBackHistory() && 
                    ((fmgr_p->parent_name[0] != 0 || fmgr_p->parent_name[1] != 0)) )
                {
                    EntryNewScreen(SCR_FMGR_EXPLORER, exit_fmgr_explorer, NULL, NULL);					
                }

               if ((fmgr_p->src_application != APP_FILEMANAGER) && 
           #ifdef __MMI_MY_FAVORITE__
                   (fmgr_p->src_application != APP_MYFAVORITE) &&  /* regard MY_FAVORITE different from other app */
           #endif
                   ((fmgr_p->sel_type & FMGR_SELECT_REPEAT)==0))
		{
                    DisplayPopupCallBack((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 0, 1000, EMPTY_LIST_TONE, fmgr_abort_app_select);
                }
	        else
		{
		    DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 0, 1000, EMPTY_LIST_TONE);
		}
                DeleteScreenIfPresent(SCR_FMGR_FOLDER_OPTION);
                DeleteScreenIfPresent(SCR_FMGR_DRIVE_OPTION);
                ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
                fmgr_p->enter_folder = FALSE;
            #ifdef __MMI_TOUCH_SCREEN__
                wgui_reset_list_item_selected_callback();
            #endif 
                return;
            }
        }
    }

    EntryNewScreen(SCR_FMGR_EXPLORER, exit_fmgr_explorer, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_EXPLORER);

    if (fmgr_p->enter_folder == TRUE)
    {
        /* enter explorer screen by user selection, not go back history after interrupt */
        fmgr_p->enter_folder = FALSE;
        fmgr_p->cur_index = 0;
        DeleteUptoScrID(SCR_FMGR_EXPLORER);

        /* enter explorer screen by user selection shall always highlight first item */
        guiBuffer = NULL;
    }
    if (GetCurrScrnId() == SCR_FMGR_DRIVE_OPTION)
    {
        DeleteScreenIfPresent(SCR_FMGR_DRIVE_OPTION);
    }

    if (fmgr_p->parent_name[0] != 0 || fmgr_p->parent_name[1] != 0)
    {
        highlightId = fmgr_get_parent_highlight_id();

#ifdef __MMI_MY_FAVORITE__
        /* check if src_app = my_favorite && current file path = sw_flash path,
           Because the default first menu/item int it is a link, the index should +1 */

        mmi_my_favorite_get_swflash_folder_path(my_favorite_path);
        if(!mmi_ucs2cmp((PS8)fmgr_p->file_path, (const PS8) my_favorite_path) && (fmgr_p->src_application == APP_MYFAVORITE))
        {
            highlightId++;
        }
#endif   

        memset(fmgr_p->parent_name, 0, sizeof(fmgr_p->parent_name));
        guiBuffer = NULL;
    }

#ifdef __MMI_MY_FAVORITE__

    if(fmgr_p->src_application == APP_MYFAVORITE)
    {
        /* check if src_app = my_favorite && current file path = sw_flash path,
           Because the default first menu/item int it is a link, it will handle the node under some condition. 
           register its own highlight handler */
           
        mmi_my_favorite_get_swflash_folder_path(my_favorite_path);
        if(!mmi_ucs2cmp((PS8)fmgr_p->file_path, (const PS8) my_favorite_path))
        {
            RegisterHighlightHandler(mmi_my_favorite_swflash_highlight_hdlr);
        }
        else
        {
            RegisterHighlightHandler(highlight_fmgr_node);
        }
    }
    else
#endif /* __MMI_MY_FAVORITE__ */
    {
        RegisterHighlightHandler(highlight_fmgr_node);
    }

    if (fmgr_p->cur_index >= fmgr_p->file_count)
    {
        fmgr_p->cur_index = 0;
    }
    
_draw_menu: 

   /****************************************************************************
   * Display Menu                                                              
   *
   * 1. File Manager    : Use standard list menu with info box. 
   * 2. Image Viewer    : Use thick list menu.
   * 3. Video Player    : Use thick list menu.
   *****************************************************************************/
    /* detemine display arrow type */
    /* if is browse mode, only display up and down arrow */

    if ((fmgr_p->sel_type & 0x0f) == FMGR_SELECT_BROWSE)
    {
        arrow_display = CAT213_ARROW_UP | CAT213_ARROW_DOWN;
    }
    else
    {
        arrow_display = CAT213_ARROW_ALL;
    }

    iconId = fmgr_get_app_title_icon_id();

    switch (fmgr_p->src_application)
    {
    #ifdef __MMI_IMAGE_VIEWER__
        case APP_IMAGEVIEWER:
        {
            GetCategory214BoxSize(FMGR_MATRIX_ROW_NUM, FMGR_MATRIX_COLUMN_NUM, &box_width, &box_height);

            /* create image cache */
            mmi_fmgr_create_thumb_image_cache((box_width > box_height) ? box_width : box_height);

        #ifdef __MMI_IMAGEVIEWER_ADV__
            mmi_imgadv_reset_app();
        #endif 

            imgview_style = mmi_imgview_get_view_style();
            if (imgview_style == IMGVIEW_VIEW_STYLE_LIST)
            {
                /* list image viewer */
                ShowCategory213Screen(
                    STR_ID_IMGVIEW_NAME,
                    iconId,             /* title */
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    count,
                    mmi_fmgr_draw_file_menuitem_callback,
                    mmi_fmgr_hide_file_menuitem_callback,
                    fmgr_p->cur_index,  /* hiligth item idx */
                    arrow_display,
                    (U8*) NULL);
            }
            else if (imgview_style == IMGVIEW_VIEW_STYLE_MATRIX)
            {
                /* matrix image view */
                RegisterHighlightHandler(mmi_fmgr_highlight_matrix_node);
                ShowCategory214Screen(
                    STR_ID_IMGVIEW_NAME,
                    iconId,
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    count,                              /* num of item */
                    mmi_fmgr_draw_file_matrix_callback, /* draw image callback */
                    mmi_fmgr_hide_file_matrix_callback, /* hide image callback */
                    FMGR_MATRIX_ROW_NUM,                                  /* number per row */
                    FMGR_MATRIX_COLUMN_NUM,                                  /* number per col */
                    fmgr_p->cur_index,                  /* hilighted item */
                    (U8*) NULL);
            }
            else
            {
                MMI_ASSERT(0);
            }

            if (count == 0)
            {
                SetRightSoftkeyFunction(mmi_imgview_exit_from_fmgr_emptry_folder, KEY_EVENT_UP);
                SetLeftSoftkeyFunction(entry_fmgr_app_empty_folder_option, KEY_EVENT_UP);
            }
        }
            break;
    #endif /* __MMI_IMAGE_VIEWER__ */ 

    #ifdef __MMI_VIDEO_PLAYER__
        case APP_VDOPLY:
        {

            /* create image cache */
            mmi_fmgr_create_thumb_image_cache(MMI_thick_menuitem_height);

        #if defined(__VDOREC_FEATURE_STORAGE__) || defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__)

            ShowCategory213Screen(
                STR_ID_VDOPLY_APP_NAME,
                iconId,             /* title */
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS, /* lsk */
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,    /* rsk */
                count,
                mmi_fmgr_draw_file_menuitem_callback,
                mmi_fmgr_hide_file_menuitem_callback,
                fmgr_p->cur_index,  /* hiligth item idx */
                arrow_display,
                (U8*) NULL);

            if (count == 0)
            {
                SetRightSoftkeyFunction(mmi_vdoply_exit_from_fmgr_emptry_folder, KEY_EVENT_UP);
                SetLeftSoftkeyFunction(entry_fmgr_app_empty_folder_option, KEY_EVENT_UP);
            }

        #else /* defined(__VDOREC_FEATURE_STORAGE__) || defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__) */ 
            ShowCategory213Screen(
                STR_ID_VDOPLY_APP_NAME,
                iconId,             /* title */
                0,
                0,                  /* lsk */
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,    /* rsk */
                count,
                mmi_fmgr_draw_file_menuitem_callback,
                mmi_fmgr_hide_file_menuitem_callback,
                fmgr_p->cur_index,  /* hiligth item idx */
                arrow_display,
                (U8*) NULL);

            if (count == 0)
            {
                SetRightSoftkeyFunction(mmi_vdoply_exit_from_fmgr_emptry_folder, KEY_EVENT_UP);
            }

        #endif /* defined(__VDOREC_FEATURE_STORAGE__) || defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__) */ 
        }
            break;
    #endif /* __MMI_VIDEO_PLAYER__ */ 

    #ifdef __MMI_RING_COMPOSER__
        case APP_RINGTONECOMPOSER:
        {

            /* create image cache */
            mmi_fmgr_create_thumb_image_cache(MMI_MENUITEM_HEIGHT * 2);

            if (count > 0)
            {
                ShowCategory212Screen(
                    STR_COMPOSER_RINGTONE_LIST,
                    iconId,
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    count,
                    mmi_fmgr_get_file_item_callback,
                    mmi_fmgr_get_file_hint_callback,
                    mmi_fmgr_draw_file_info_callback,
                    mmi_fmgr_hide_file_info_callback,
                    2,                  /* info box row count */
                    0,                  /* info bg img id */
                    fmgr_p->cur_index,                  /* hiligth item idx */
                    (U8*) guiBuffer);
            }
            else
            {
                ShowCategory213Screen(
                    STR_COMPOSER_RINGTONE_LIST,
                    iconId,
                    STR_COMPOSER_RINGTONE_ADD,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    0,
                    mmi_fmgr_draw_file_menuitem_callback,
                    mmi_fmgr_hide_file_menuitem_callback,
                    0,                  /* hiligth item idx */
                    0,
                    (U8*) guiBuffer);

                SetLeftSoftkeyFunction(RngcExecAdd, KEY_EVENT_UP);
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            }
        }
            break;
    #endif /* __MMI_RING_COMPOSER__ */ 

#ifdef __MMI_BARCODEREADER__
        case APP_BARCODEREADER:
            mmi_fmgr_create_thumb_image_cache(MMI_MENUITEM_HEIGHT * 2);
            if (count > 0)
            {
                ShowCategory212Screen(
                    STR_ID_BARCODEREADER_APP_NAME,
                    GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    count,
                    mmi_fmgr_get_file_item_callback,
                    mmi_fmgr_get_file_hint_callback,
                    mmi_fmgr_draw_file_info_callback,
                    mmi_fmgr_hide_file_info_callback,
                    2,                  /* info box row count */
                    0,                  /* info bg img id */
                    0,                  /* hiligth item idx */
                    (U8*) guiBuffer);
                
            }
            else
            {
                ShowCategory213Screen(
                    STR_ID_BARCODEREADER_APP_NAME,
                    GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
                    0,
                    0, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    0,
                    mmi_fmgr_draw_file_menuitem_callback,
                    mmi_fmgr_hide_file_menuitem_callback,
                    0,                  /* hiligth item idx */
                    0,
                    (U8*) guiBuffer);
                SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            }
            break;
#endif /*__MMI_BARCODEREADER__*/

    #ifdef __MMI_EBOOK_READER__
        case APP_EBOOK:
        {

            /* create image cache */
            mmi_fmgr_create_thumb_image_cache(MMI_MENUITEM_HEIGHT * 2);

            if (count > 0)
            {
                ShowCategory212Screen(
                    EBOOK_TITLE_BOOKSHELF,
                    GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    count,
                    ebr_get_file_item_callback,
                    mmi_fmgr_get_file_hint_callback,
                    mmi_fmgr_draw_file_info_callback,
                    mmi_fmgr_hide_file_info_callback,
                    2,                  /* info box row count */
                    0,                  /* info bg img id */
                    0,                  /* hiligth item idx */
                    (U8*) guiBuffer);

            }
            else
            {
                ShowCategory213Screen(
                    EBOOK_TITLE_BOOKSHELF,
                    GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    0,
                    mmi_fmgr_draw_file_menuitem_callback,
                    mmi_fmgr_hide_file_menuitem_callback,
                    0,                  /* hiligth item idx */
                    0,
                    (U8*) guiBuffer);
                SetLeftSoftkeyFunction(ebr_show_limit_book_shelf_option, KEY_EVENT_UP);
                SetRightSoftkeyFunction(ebr_book_fmgr_empty_list_callback, KEY_EVENT_UP);
            }

        }
            break;
    #endif /* __MMI_EBOOK_READER__ */ /* __MMI_RING_COMPOSER__ */

    #ifdef __MMI_SOUND_RECORDER__
        case APP_SOUNDRECORDER:
        {
            if (count > 0)
            {
                /* create image cache */
                mmi_fmgr_create_thumb_image_cache(MMI_MENUITEM_HEIGHT * 2);

                ShowCategory212Screen(
            #ifdef __MMI_SOUND_RECORDER_STYLE_X__
                                         STR_ID_SNDREC_LIST,
            #else 
                                         STR_ID_SNDREC_MAIN,
            #endif 
                                         iconId,    /* title   */
                                         STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS,        /* lsk */
                                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,      /* rsk */
                                         count, mmi_fmgr_get_file_item_callback, mmi_fmgr_get_file_hint_callback, mmi_fmgr_draw_file_info_callback, mmi_fmgr_hide_file_info_callback, 2,        /* info box row count */
                                         0,         /* info bg img id */
                                         0,         /* hiligth item idx */
                                         (U8*) guiBuffer);
            }
            else
            {

                /* create image cache */
                mmi_fmgr_create_thumb_image_cache(MMI_thick_menuitem_height);

                ShowCategory213Screen(
            #ifdef __MMI_SOUND_RECORDER_STYLE_X__
                                         STR_ID_SNDREC_LIST,
            #else 
                                         STR_ID_SNDREC_MAIN,
            #endif 
                                         iconId,    /* title   */
                                         STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS,        /* lsk */
                                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,      /* rsk */
                                         0, mmi_fmgr_draw_file_menuitem_callback, mmi_fmgr_hide_file_menuitem_callback, 0,      /* hiligth item idx */
                                         0, (U8*) guiBuffer);
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
                SetLeftSoftkeyFunction(entry_fmgr_app_empty_folder_option, KEY_EVENT_UP);
            }
        }
            break;
    #endif /* __MMI_SOUND_RECORDER__ */ 
    #ifdef __MMI_AB_REPEATER__
        case APP_ABREPEATER:
        {
            if (count > 0)
            {
                /* create image cache */
                mmi_fmgr_create_thumb_image_cache(MMI_MENUITEM_HEIGHT * 2);

                ShowCategory212Screen(
                    STR_ID_ABREPEAT_TITLE,
                    iconId,             /* title   */
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    count,
                    mmi_fmgr_get_file_item_callback,
                    mmi_fmgr_get_file_hint_callback,
                    mmi_fmgr_draw_file_info_callback,
                    mmi_fmgr_hide_file_info_callback,
                    2,                  /* info box row count */
                    0,                  /* info bg img id */
                    0,                  /* hiligth item idx */
                    (U8*) guiBuffer);
            }
            else
            {

                /* create image cache */
                mmi_fmgr_create_thumb_image_cache(MMI_thick_menuitem_height);

                ShowCategory213Screen(
                    STR_ID_ABREPEAT_TITLE,
                    iconId,             /* title   */
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    0,
                    mmi_fmgr_draw_file_menuitem_callback,
                    mmi_fmgr_hide_file_menuitem_callback,
                    0,                  /* hiligth item idx */
                    0,
                    (U8*) guiBuffer);
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
                SetLeftSoftkeyFunction(entry_fmgr_app_empty_folder_option, KEY_EVENT_UP);
            }
        }
            break;
    #endif /* __MMI_AB_REPEATER__ */ 

    #ifdef __MMI_SWFLASH__
        case APP_SWFLASH:
        {
            /* create image cache */
            mmi_fmgr_create_thumb_image_cache(MMI_MENUITEM_HEIGHT * 2);
        
            ShowCategory212Screen(
                STR_ID_SWFLASH_APP,
                iconId,             /* title   */
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS, /* lsk */
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,    /* rsk */
                count,
                mmi_fmgr_get_file_item_callback,
                mmi_fmgr_get_file_hint_callback,
                mmi_fmgr_draw_file_info_callback,
                mmi_fmgr_hide_file_info_callback,
                2,         /* info box row count */
                0,         /* info bg img id */
                0,         /* hiligth item idx */
                (U8*) guiBuffer);
        
            //if (count == 0)
            //{
              //  SetRightSoftkeyFunction(mmi_vdoply_exit_from_fmgr_emptry_folder, KEY_EVENT_UP);
                //SetLeftSoftkeyFunction(entry_fmgr_app_empty_folder_option, KEY_EVENT_UP);
            //}
        }
            break;
#endif /* __MMI_SWFLASH__ */ 
#ifdef __MMI_CSB_BROWSER__
        case APP_CSB:
        {

	    /* create image cache */
            mmi_fmgr_create_thumb_image_cache(MMI_MENUITEM_HEIGHT * 2);

            ShowCategory213Screen(
                    STR_ID_CSB_TEXT,
                    iconId,             /* title */
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    count,
                    mmi_fmgr_draw_file_menuitem_callback,
                    mmi_fmgr_hide_file_menuitem_callback,
                    fmgr_p->cur_index,  /* hiligth item idx */
                    arrow_display,
                    (U8*) NULL);

			if (count == 0)
            {
				ChangeLeftSoftkey(0, 0);
				SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
                SetRightSoftkeyFunction(mmi_csb_exit_from_fmgr_empty_folder, KEY_EVENT_UP);
            }
        }
        break;
#endif /* __MMI_CSB_BROWSER__ */

#ifdef __MMI_MY_FAVORITE__
        case APP_MYFAVORITE:
        {
            if(!mmi_my_favorite_get_folder_resource((PS8)fmgr_p->file_path, &mf_title, &mf_icon))
            {
                MMI_ASSERT(0);
            }

            /* check if src_app = my_favorite && current file path = sw_flash path,
               because the first menu/item in it is a link, not a file/folder,
               its get_menu_item_callback should be differnt from FMGR/normal condition. */
            mmi_my_favorite_get_swflash_folder_path(my_favorite_path);
            if(!mmi_ucs2cmp((PS8)fmgr_p->file_path, (const PS8) my_favorite_path))
            {
                count += mmi_my_favorite_swflash_waplink_count();

                ShowCategory185Screen(
                   mf_title, 
                   mf_icon, 
                   STR_GLOBAL_OPTIONS, 
                   IMG_GLOBAL_OPTIONS, 
                   STR_GLOBAL_BACK, 
                   IMG_GLOBAL_BACK, 
                   count, 
                   mmi_my_favorite_swflash_get_item_callback, 
                   mmi_fmgr_get_file_hint_callback, 
                   highlightId,
                   KAL_TRUE,
                   NULL,
                   (U8*) guiBuffer);

            
            }
            else
            {
                ShowCategory185Screen(
                       mf_title, 
                       mf_icon, 
                       STR_GLOBAL_OPTIONS, 
                       IMG_GLOBAL_OPTIONS, 
                       STR_GLOBAL_BACK, 
                       IMG_GLOBAL_BACK, 
                       count, 
                       mmi_fmgr_get_file_item_callback, 
                       mmi_fmgr_get_file_hint_callback, 
                       highlightId,
                       KAL_TRUE,
                       NULL,
                       (U8*) guiBuffer);
            }
        }
            break;
#endif /* __MMI_MY_FAVORITE__ */

        case APP_FILEMANAGER:
        default:    /* others */
        {

            /* create image cache */
            mmi_fmgr_create_thumb_image_cache(MMI_MENUITEM_HEIGHT * 2);

            ShowCategory212Screen(
                STR_FMGR_TITLE,
                iconId,             /* title */
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS, /* lsk */
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,    /* rsk */
                count,
                mmi_fmgr_get_file_item_callback,
                mmi_fmgr_get_file_hint_callback,
                mmi_fmgr_draw_file_info_callback,
                mmi_fmgr_hide_file_info_callback,
                2,                  /* info box row count */
                0,                  /* info bg img id */
                highlightId,        /* hiligth item idx */
                (U8*) guiBuffer);
        }

            break;
    }
   /*****************************************************************************/

    /* key handlers are set in highlight_fmgr_node */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  exit_fmgr_explorer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_fmgr_explorer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_free_thumb_image_cache();

    StopTimer(FMGR_AUDIO_TIMER);
    if (fmgr_p->audio_state == TRUE)
    {
        fmgr_p->audio_state = FALSE;
        mdi_audio_stop_file();
    }

    /* for app select file, after return callback, no need to add explorer into history */
    if ((fmgr_p->file_path[0] != 0) && IsScreenPresent(SCR_FMGR_EXPLORER) == FALSE)
    {
        history currHistory;
        S16 nHistory = 0;

        currHistory.scrnID = SCR_FMGR_EXPLORER;
        currHistory.entryFuncPtr = entry_fmgr_explorer;
        mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
        AddHistory(currHistory);
    }
    else
    {
        U8 *guiBuffer;

        guiBuffer = GetCurrGuiBuffer(SCR_FMGR_EXPLORER);
        GetCategoryHistory(guiBuffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_folder_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_folder_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[20];
    U16 nNumofItem;
    U16 menuId, iconId;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FMGR_FOLDER_OPTION, NULL, entry_fmgr_folder_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_FOLDER_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    if (fmgr_p->src_application == APP_FILEMANAGER
    #ifdef __MMI_MY_FAVORITE__
        || fmgr_p->src_application == APP_MYFAVORITE 
    #endif
        )
    {
        menuId = MITEM_FMGR_FOLDER_OPTIONS;
    }
#ifdef __MMI_FTS_SUPPORT__
    else if (fmgr_p->src_application == APP_FTP)
    {
        menuId = MENU_CONN_FTP_SHARED_FOLDER;
    }
#endif /* __MMI_FTS_SUPPORT__ */ 
#ifdef __MMI_BIP_SUPPORT__
    else if (fmgr_p->src_application == APP_BIP)
    {
        menuId = MENU_CONN_BIP_SHARED_FOLDER;
    }
#endif /* __MMI_BIP_SUPPORT__ */
    else
    {
        /* other app for select */
        menuId = MITEM_FMGR_APP_FOLDER_OPTIONS;
    }

    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);
    SetParentHandler(menuId);

    iconId = fmgr_get_app_title_icon_id();

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        iconId,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_file_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_file_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    U16 nStrItemList[20];
    U16 parentId;
    U16 nNumofItem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* only APP_FILEMANAGER will enter file option,
       other app for select will not have file option menu,
       other app for browse will enter app file option */

    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

    if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
#ifndef __MMI_SHOW_FILE_EXT__
        || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
#endif 
        )
        return;
    else
    {
    #if defined(__DRM_V02__)
        if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_ODF))
        {
            mmi_fmgr_get_drm_file_type_by_path((PS8) fmgr_p->file_path, &file_info.file_type);
        }
    #endif
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    }

    EntryNewScreen(SCR_FMGR_FILE_OPTION, exit_fmgr_file_option, entry_fmgr_file_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_FILE_OPTION);

    parentId = fmgr_get_file_option_menu(&file_info);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild_Ext(parentId);
    GetSequenceStringIds_Ext(parentId, nStrItemList);
    SetParentHandler(parentId);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  exit_fmgr_file_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_fmgr_file_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_unhide_menu_item(MENU_FMGR_DA_OPTION_FORWARD);
    mmi_frm_unhide_menu_item(MENU_FMGR_GEN_OPTION_FORWARD);
    mmi_frm_unhide_menu_item(MENU_FMGR_IMG_OPTION_EDIT);
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_sort_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_sort_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U8 *guiBuffer;
    U16 nNumofItem, iconId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_is_parent_present() == FALSE)
    {
        DisplayPopup((PU8) GetString(FMGR_FS_PATH_NOT_FOUND_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);

        /* go back to root, reload file manager */
        if (fmgr_p->src_application == APP_FILEMANAGER)
        {
            fmgr_adjust_history(SCR_FMGR_MAIN);
        }
        else
        {
            fmgr_adjust_history(0);
        }
        /* fmgr_return_to_app(); */
        return;
    }

    EntryNewScreen(SCR_FMGR_SORT_OPTION, exit_fmgr_sort_option, entry_fmgr_sort_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_SORT_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(MENU_FMGR_GEN_OPTION_SORT);
    GetSequenceStringIds(MENU_FMGR_GEN_OPTION_SORT, nStrItemList);
    SetParentHandler(MENU_FMGR_GEN_OPTION_SORT);
    iconId = fmgr_get_app_title_icon_id();

    ShowCategory15Screen(
        STR_FMGR_SORT,
        iconId,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(fmgr_sort, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  exit_fmgr_sort_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_fmgr_sort_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_EF_FMGR_SORT_OPTION_LID, &temp, DS_BYTE, &error);
    if (temp == 0xff)
    {
        fmgr_p->sort_option = FS_NO_SORT;
    }
    else
    {
        fmgr_p->sort_option = temp << 5;
    }
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_forward_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_forward_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    U16 nStrItemList[20];
    U16 parentId, imageId = 0;
    U16 nNumofItem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_check_file_present() < FMGR_NO_ERROR)
    {
        return;
    }

    /* show menu according to file type */
    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

#if defined(__DRM_V02__)
    if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
#ifndef __MMI_SHOW_FILE_EXT__
        || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
#endif 
        )
        return;
    else
    {
        if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_ODF))
        {
            mmi_fmgr_get_drm_file_type_by_path((PS8) fmgr_p->file_path, &file_info.file_type);
        }        
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    }
#endif /* defined(__DRM_V02__) */

    parentId = fmgr_get_forward_option_menu(&file_info, NULL);
    if (parentId == 0)
    {
        mmi_frm_unhide_menu_item(MENU_FMGR_FWD_MMS);
        DisplayPopup((U8*) GetString(STR_ID_FMGR_NO_FORWARD_OPTION), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        return;
    }

    fmgr_check_sub_forward_option(&file_info);

#ifdef __SYNCML_SUPPORT__
    if ((FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_VCF) && mmi_syncml_is_phb_sync_now()) ||
        (FMGR_FILTER_IS_SET(&file_info.file_type,FMGR_TYPE_VCS) && mmi_syncml_is_tdl_sync_now()))
    {
        mmi_frm_unhide_menu_item(MENU_FMGR_FWD_MMS);
        DisplayPopup((U8*) GetString(STR_ID_SYNC_CODE_FORBIDDEN), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
        return;
    }    
#endif /* __SYNCML_SUPPORT__ */

#if 0
#ifdef __MMI_MESSAGES_EMS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MESSAGES_EMS__ */ 
/* under construction !*/
#ifdef __MMI_UNIFIED_COMPOSER__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UNIFIED_COMPOSER__ */
/* under construction !*/
#ifdef __MMI_BG_SOUND_EFFECT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_BG_SOUND_EFFECT__ */ 
/* under construction !*/
#ifdef M3D_MMI_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* if 0 */

    nNumofItem = GetNumOfChild_Ext(parentId);

    if (nNumofItem == 0)
    {
	DisplayPopup((U8*) GetString(STR_ID_FMGR_NO_FORWARD_OPTION), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
        fmgr_unhide_fwd_app_menu();
        return;
    }

    EntryNewScreen(SCR_FMGR_FORWARD_OPTION, exit_fmgr_forward_option, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_FORWARD_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    GetSequenceStringIds_Ext(parentId, nStrItemList);
    SetParentHandler(parentId);

    imageId = fmgr_get_app_title_icon_id();

    ShowCategory15Screen(
        STR_FMGR_FORWARD,
        imageId,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  exit_fmgr_forward_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_fmgr_forward_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_MMS);
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_EMS);
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_SMS);
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_BGSOUND);
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_POWER_ON);
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_POWER_OFF);
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_PHB);
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_SUB_WALLPAPER);

    if (fmgr_p->tree_action != FMGR_ACTION_NONE)
    {
        history currHistory;
        S16 nHistory = 0;

        fmgr_p->tree_action = FMGR_ACTION_NONE;

        currHistory.scrnID = SCR_FMGR_FORWARD_OPTION;
        currHistory.entryFuncPtr = entry_fmgr_forward_option;
        mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
        AddHistory(currHistory);
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_check_sub_forward_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_check_sub_forward_option(FMGR_FILE_INFO_STRUCT *file_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_MESSAGES_EMS__
    if ((!FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_IMY) &&
        !FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_EMS) &&
        !FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_ANM)) ||
        (!mmi_bootup_is_sim_valid()))
    {
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_EMS);
    }
    if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_EMS))
    {
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_WALLPAPER);
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_SUB_WALLPAPER);
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_SCREENSAVER);
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_POWER_ON);
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_POWER_OFF);
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_PHB);        
    }
#endif /* __MMI_MESSAGES_EMS__ */ 

    if (mmi_frm_sms_is_hide_send_sms_menu_item()==MMI_TRUE)
    {
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_SMS);    
    }

#ifdef __MMI_UNIFIED_COMPOSER__ 
    if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_IMY) ||
        FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_EMS) ||
        FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_ANM))
    {
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_EMS);
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */

#ifdef __MMI_BG_SOUND_EFFECT__
    if (!FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_WAV))
    {
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_BGSOUND);
    }
#endif /* __MMI_BG_SOUND_EFFECT__ */ 

#ifdef M3D_MMI_SUPPORT
    if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_M3D))
    {
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_SUB_WALLPAPER);
    }
#endif

    return;
}


#if defined(__MMI_EXIF__)


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_jpg_detail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_jpg_detail(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    S8 UCS2_buf[128];
    S32 length;
    U8 *guiBuffer, *info;
    gdi_image_jpeg_exif_info_struct exif_info;
    GDI_RESULT result = GDI_SUCCEED;
    S16 count = 0;
    U16 iconId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define PRINT_EXIF_INFO(__a__,__A__)                          \
   do{                                                           \
      length = strlen((PS8)exif_info.##__a__##);                 \
      if(length>0)                                               \
      {                                                          \
         mmi_ucs2cat((PS8)info, (PS8)GetString(##__A__##)); \
         mmi_ucs2cat ((PS8)info, (PS8)L":\n");              \
         mmi_asc_to_ucs2(UCS2_buf,(PS8)exif_info.##__a__##);\
         mmi_ucs2cat ((PS8)info,(PS8)UCS2_buf);             \
         mmi_ucs2cat ((PS8)info, (PS8)L"\n");               \
         count++;                                                \
      }                                                          \
   }while(0);

    EntryNewScreen(SCR_FMGR_JPG_DETAIL, NULL, entry_fmgr_jpg_detail, NULL);

    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_JPG_DETAIL);

    info = (PU8) subMenuData;

    /* get the full path of the file */
    mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name);
#ifndef __MMI_SHOW_FILE_EXT__
    mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext);
#endif 
    result = gdi_image_jpeg_get_exif_info(fmgr_p->file_path, &exif_info);

    mmi_ucs2cpy((PS8) info, (PS8) L"");

    if (result != GDI_FAILED)
    {
    #ifdef __MMI_EXIF_MAKE__
        PRINT_EXIF_INFO(make, STR_ID_FMGR_EXIF_MAKE);
    #endif 
    #ifdef __MMI_EXIF_MODEL__
        PRINT_EXIF_INFO(model, STR_ID_FMGR_EXIF_MODEL);
    #endif 
    #ifdef __MMI_EXIF_ORIENTATION__
        PRINT_EXIF_INFO(orientation, STR_ID_FMGR_EXIF_ORIENTATION);
    #endif 
    #ifdef __MMI_EXIF_X_RESOLUTION__
        PRINT_EXIF_INFO(x_resolution, STR_ID_FMGR_EXIF_X_RESOLUTION);
    #endif 
    #ifdef __MMI_EXIF_Y_RESOLUTION__
        PRINT_EXIF_INFO(y_resolution, STR_ID_FMGR_EXIF_Y_RESOLUTION);
    #endif 
    #ifdef __MMI_EXIF_RESOLUTION_UNIT__
        PRINT_EXIF_INFO(resolution_unit, STR_ID_FMGR_EXIF_RESOLUTION_UNIT);
    #endif 
    #ifdef __MMI_EXIF_SOFTWARE__
        PRINT_EXIF_INFO(software, STR_ID_FMGR_EXIF_SOFTWARE);
    #endif 
    #ifdef __MMI_EXIF_DATE_TIME__
        PRINT_EXIF_INFO(date_time, STR_ID_FMGR_EXIF_DATE_TIME);
    #endif 
    #ifdef __MMI_EXIF_YCBCR_POSITIONING__
        PRINT_EXIF_INFO(ycbcr_positioning, STR_ID_FMGR_EXIF_YCBCR_POSITIONING);
    #endif 
    #ifdef __MMI_EXIF_EXIF_IFD__
        PRINT_EXIF_INFO(exif_ifd, STR_ID_FMGR_EXIF_EXIF_IFD);
    #endif 
    #ifdef __MMI_EXIF_EXPOSURE_TIME__
        PRINT_EXIF_INFO(exposure_time, STR_ID_FMGR_EXIF_EXPOSURE_TIME);
    #endif 
    #ifdef __MMI_EXIF_FNUMBER__
        PRINT_EXIF_INFO(fnumber, STR_ID_FMGR_EXIF_FNUMBER);
    #endif 
    #ifdef __MMI_EXIF_EXPOSURE_PROGRAM__
        PRINT_EXIF_INFO(exposure_program, STR_ID_FMGR_EXIF_EXPOSURE_PROGRAM);
    #endif 
    #ifdef __MMI_EXIF_ISO_SPEED_RATINGS__
        PRINT_EXIF_INFO(iso_speed_ratings, STR_ID_FMGR_EXIF_ISO_SPEED_RATINGS);
    #endif 
    #ifdef __MMI_EXIF_EXIF_VERSION__
        PRINT_EXIF_INFO(exif_version, STR_ID_FMGR_EXIF_EXIF_VERSION);
    #endif 
    #ifdef __MMI_EXIF_DATE_TIME_ORIGINAL__
        PRINT_EXIF_INFO(date_time_original, STR_ID_FMGR_EXIF_DATE_TIME_ORIGINAL);
    #endif 
    #ifdef __MMI_EXIF_DATE_TIME_DIGITIZED__
        PRINT_EXIF_INFO(date_time_digitized, STR_ID_FMGR_EXIF_DATE_TIME_DIGITIZED);
    #endif 
    #ifdef __MMI_EXIF_COMPONENTS_CONFIG__
        PRINT_EXIF_INFO(components_config, STR_ID_FMGR_EXIF_COMPONENTS_CONFIG);
    #endif 
    #ifdef __MMI_EXIF_EXPOSURE_BIAS_VALUE__
        PRINT_EXIF_INFO(exposure_bias_value, STR_ID_FMGR_EXIF_EXPOSURE_BIAS_VALUE);
    #endif 
    #ifdef __MMI_EXIF_METERING_MODE__
        PRINT_EXIF_INFO(metering_mode, STR_ID_FMGR_EXIF_METERING_MODE);
    #endif 
    #ifdef __MMI_EXIF_LIGHT_SOURCE__
        PRINT_EXIF_INFO(light_source, STR_ID_FMGR_EXIF_LIGHT_SOURCE);
    #endif 
    #ifdef __MMI_EXIF_FLASH__
        PRINT_EXIF_INFO(flash, STR_ID_FMGR_EXIF_FLASH);
    #endif 
    #ifdef __MMI_EXIF_MAKER_NOTE__
        PRINT_EXIF_INFO(maker_note, STR_ID_FMGR_EXIF_MAKER_NOTE);
    #endif 
    #ifdef __MMI_EXIF_FLASHPIX_VERSION__
        PRINT_EXIF_INFO(flashpix_version, STR_ID_FMGR_EXIF_FLASHPIX_VERSION);
    #endif 
    #ifdef __MMI_EXIF_COLOR_SPACE__
        PRINT_EXIF_INFO(color_space, STR_ID_FMGR_EXIF_COLOR_SPACE);
    #endif 
    #ifdef __MMI_EXIF_PIXEL_X_DIMENSION__
        PRINT_EXIF_INFO(pixel_x_dimension, STR_ID_FMGR_EXIF_PIXEL_X_DIMENSION);
    #endif 
    #ifdef __MMI_EXIF_PIXEL_Y_DIMENSION__
        PRINT_EXIF_INFO(pixel_y_dimension, STR_ID_FMGR_EXIF_PIXEL_Y_DIMENSION);
    #endif 
    #ifdef __MMI_EXIF_EXPOSURE_MODE__
        PRINT_EXIF_INFO(exposure_mode, STR_ID_FMGR_EXIF_EXPOSURE_MODE);
    #endif 
    #ifdef __MMI_EXIF_DIGITAL_ZOOM_RATIO__
        PRINT_EXIF_INFO(digital_zoom_ratio, STR_ID_FMGR_EXIF_DIGITAL_ZOOM_RATIO);
    #endif 
    #ifdef __MMI_EXIF_SCENE_CAPTURE_TYPE__
        PRINT_EXIF_INFO(scene_capture_type, STR_ID_FMGR_EXIF_SCENE_CAPTURE_TYPE);
    #endif 
    }

    if (count == 0)
    {
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_ID_FMGR_EXIF_NO_INFORMATION));
    }

    /* reset */
    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);

    if (fmgr_p->src_application == APP_IMAGEVIEWER)
    {
        iconId = GetRootTitleIcon(MENU_ID_IMGVIEW_APP);
    }
    else
    {
        iconId = GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID);
    }

    ShowCategory74Screen(
        STR_FMGR_VIEW_IMG_JPG_DETAIL,
        iconId,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) subMenuData,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* defined(__MMI_EXIF__) */ 

#ifdef __DRM_SUPPORT__

#ifdef __DRM_MTK__


/*****************************************************************************
 * FUNCTION
 *  fmgr_populate_drm_info_aux
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rights          [?]         
 *  permission      [IN]        
 *  data            [?]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL fmgr_populate_drm_info_aux(drm_rights_struct *rights, U8 permission, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = FALSE;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_populate_drm_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  permission      [IN]        
 *  data            [?]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL fmgr_populate_drm_info(U32 handle, U8 permission, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_rights_struct *rights;
    FS_HANDLE input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    input = handle;
    rights = drm_core_get_rights(input);

    return fmgr_populate_drm_info_aux(rights, permission, data);
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_drm_rights_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_drm_rights_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U8 *guiBuffer;
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FMGR_DRM_RIGHTS_OPTION, NULL, entry_fmgr_drm_rights_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_DRM_RIGHTS_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(MITEM_FMGR_DRM_RIGHTS_OPTIONS);
    GetSequenceStringIds(MITEM_FMGR_DRM_RIGHTS_OPTIONS, nStrItemList);
    SetParentHandler(MITEM_FMGR_DRM_RIGHTS_OPTIONS);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
}

/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_rights_detail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_rights_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    U8 *guiBuffer;
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_RIGHTS_DETAIL);

    EntryNewScreen(SCR_FMGR_RIGHTS_DETAIL, NULL, entry_fmgr_rights_detail, NULL);

    memset(subMenuData, 0x00, sizeof(subMenuData));
    
    mmi_rmgr_populate_drm_info_aux(NULL, DRM_PERMISSION_ALL, (PU8)subMenuData, fmgr_p->cur_index);
        
    ShowCategory74Screen(
        STR_FMGR_DETAIL,
        GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) subMenuData,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_delete_all_expired_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_delete_all_expired_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_is_parent_present() == FALSE)
    {
        DisplayPopup((PU8) GetString(FMGR_FS_PATH_NOT_FOUND_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);

        /* go back to root, reload file manager */
        if (fmgr_p->src_application == APP_FILEMANAGER)
        {
            fmgr_adjust_history(SCR_FMGR_MAIN);
        }
        return;
    }

    mmi_fmgr_send_delete_expired_ro_req((PU8) fmgr_p->file_path, fmgr_delete_rsp_hdlr);

    /* Set fmgr is busy flag */
    fmgr_p->is_fmgr_busy = MMI_TRUE;    
    
    entry_fmgr_delete_animation();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_send_delete_expired_ro_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]        
 *  type            [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_send_delete_expired_ro_req(PU8 path, PsFuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_FMT;
    Message.oslMsgId = MSG_ID_MMI_FMT_DELETE_RO_REQ;

    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetProtocolEventHandler(callback, MSG_ID_MMI_FMT_DELETE_RO_RSP);

    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}

#else /* __DRM_MTK__ */


/*****************************************************************************
 * FUNCTION
 *  fmgr_populate_drm_info_aux
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rights          [?]         
 *  permission      [IN]        
 *  data            [?]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL fmgr_populate_drm_info_aux(FS_HANDLE input, drm_constraint_struct *cons, U8 permission, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = FALSE;
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__DRM_V02__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__DRM_V02__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_populate_drm_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  permission      [IN]        
 *  data            [?]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL fmgr_populate_drm_info(U32 handle, U8 permission, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_constraint_struct cons;
    FS_HANDLE input;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    input = handle;
    ret = DRM_get_constraint(input, NULL, permission, &cons);
    if (ret == 0)
        return fmgr_populate_drm_info_aux(input, &cons, permission, data);
    else
        return FALSE;
}


#if defined(__DRM_V02__)
/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_open_multi_odf
 * DESCRIPTION
 *  Highlight function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_open_multi_odf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fmgr_open_mul_odf_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_open_mul_odf_hdlr, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(fmgr_open_mul_odf_hdlr);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  fmgr_open_mul_odf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_open_mul_odf_hdlr(void)
{
    /*---------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOAD_AGENT__
    /* download agent file */
    if (fmgr_is_da_file())
    {
        FS_HANDLE handle;
        /* Check if file exists or not */
        handle = FS_Open((PU16) fmgr_p->da_file_path, FS_READ_ONLY);
        if (handle > FS_NO_ERROR)
        {
        	FS_Close(handle);
        }
        else
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION);
            return;
        }
        mmi_fmgr_get_file_type((PS8) fmgr_p->da_file_path, &file_info.file_type);
        mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->da_file_path);
        file_info.is_short = FALSE;

    }
    /* non download agent file */
    else
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
    {
        if (fmgr_check_file_present() < FMGR_NO_ERROR)
        {
            return;
        }

        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

        if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
    #ifndef __MMI_SHOW_FILE_EXT__
            || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
    #endif 
        )
            return;
    }

#if 0
#if defined(MT6223P)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MT6223P */
#endif /* if 0 */

    fmgr_p->enter_folder = TRUE;
    entry_fmgr_mul_odf_explorer();

    DeleteScreenIfPresent(SCR_FMGR_APP_MUL_ODF_OPTION);
    
//    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);

}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_mul_odf_explorer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_mul_odf_explorer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 highlightId = 0;
    U16 count, iconId;
    U8 arrow_display;
    
#ifdef __MMI_IMAGE_VIEWER__
    U16 imgview_style;
    S32 box_width;
    S32 box_height;
#endif /* __MMI_IMAGE_VIEWER__ */ 

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_fmgr_mul_odf_kernel_init((PS8) fmgr_p->file_path, fmgr_p->filter_type, &count);


    /* browse type do not pop up empty */
    if (count == 0)
    {
        if (fmgr_p->src_application == APP_FILEMANAGER ||
    #if defined(__MMI_IRDA_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)
            fmgr_p->src_application == APP_EXTDEVICE ||
    #endif 
    #ifdef __MMI_FTS_SUPPORT__
            fmgr_p->src_application == APP_FTP ||
    #endif 
    #ifdef __MMI_BIP_SUPPORT__
            fmgr_p->src_application == APP_BIP ||
    #endif 
    #ifdef __MMI_FM_RADIO_RECORD__
            fmgr_p->src_application == APP_FMRDO ||
    #endif 
    #ifdef __MMI_SWFLASH__
            fmgr_p->src_application == APP_SWFLASH ||
    #endif
            (fmgr_p->src_application != APP_FILEMANAGER && fmgr_p->sel_type != FMGR_SELECT_BROWSE))
        {
            mmi_ucs2_to_asc((PS8) nPrintableStr, (PS8) fmgr_p->file_path);
            PRINT_INFORMATION("entry multi odf explorer fail: %s", nPrintableStr);
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);

            if ((fmgr_p->src_application != APP_FILEMANAGER) && ((fmgr_p->sel_type & FMGR_SELECT_REPEAT)==0))
			{
                DisplayPopupCallBack((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 0, 1000, EMPTY_LIST_TONE, fmgr_abort_app_select);
            }
			else
			{
				DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 0, 1000, EMPTY_LIST_TONE);
			}
            DeleteScreenIfPresent(SCR_FMGR_FILE_OPTION);
            DeleteScreenIfPresent(SCR_FMGR_FOLDER_OPTION);
            DeleteScreenIfPresent(SCR_FMGR_DRIVE_OPTION);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
            fmgr_p->enter_folder = FALSE;
        #ifdef __MMI_TOUCH_SCREEN__
            wgui_reset_list_item_selected_callback();
        #endif 
            return;
        }
    }

    EntryNewScreen(SCR_FMGR_MUL_ODF_EXPLORER, exit_fmgr_mul_odf_explorer, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_MUL_ODF_EXPLORER);

    RegisterHighlightHandler(highlight_fmgr_node);

    if ((fmgr_p->sel_type & 0x0f) == FMGR_SELECT_BROWSE)
    {
        arrow_display = CAT213_ARROW_UP | CAT213_ARROW_DOWN;
    }
    else
    {
        arrow_display = CAT213_ARROW_ALL;
    }

    iconId = fmgr_get_app_title_icon_id();

    if (fmgr_p->enter_folder == TRUE)
    {
        /* enter explorer screen by user selection, not go back history after interrupt */
        fmgr_p->enter_folder = FALSE;
        fmgr_p->cur_index = 0;
    }

    if (fmgr_p->cur_index >= fmgr_p->file_count)
    {
        fmgr_p->cur_index = 0;
    }

    switch (fmgr_p->src_application)
    {
    #ifdef __MMI_IMAGE_VIEWER__
        case APP_IMAGEVIEWER:
        {
            GetCategory214BoxSize(FMGR_MATRIX_ROW_NUM, FMGR_MATRIX_COLUMN_NUM, &box_width, &box_height);

            /* create image cache */
            mmi_fmgr_create_thumb_image_cache((box_width > box_height) ? box_width : box_height);

        #ifdef __MMI_IMAGEVIEWER_ADV__
            mmi_imgadv_reset_app();
        #endif 

            imgview_style = mmi_imgview_get_view_style();
            if (imgview_style == IMGVIEW_VIEW_STYLE_LIST)
            {
                /* list image viewer */
                ShowCategory213Screen(
                    STR_ID_IMGVIEW_NAME,
                    iconId,             /* title */
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    count,
                    mmi_fmgr_draw_file_menuitem_callback,
                    mmi_fmgr_hide_file_menuitem_callback,
                    fmgr_p->cur_index,  /* hiligth item idx */
                    arrow_display,
                    (U8*) NULL);
            }
            else if (imgview_style == IMGVIEW_VIEW_STYLE_MATRIX)
            {
                /* matrix image view */
                RegisterHighlightHandler(mmi_fmgr_highlight_matrix_node);
                ShowCategory214Screen(
                    STR_ID_IMGVIEW_NAME,
                    iconId,
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    count,                              /* num of item */
                    mmi_fmgr_draw_file_matrix_callback, /* draw image callback */
                    mmi_fmgr_hide_file_matrix_callback, /* hide image callback */
                    FMGR_MATRIX_ROW_NUM,                                  /* number per row */
                    FMGR_MATRIX_COLUMN_NUM,                                  /* number per col */
                    fmgr_p->cur_index,                  /* hilighted item */
                    (U8*) NULL);
            }
            else
            {
                MMI_ASSERT(0);
            }

            if (count == 0)
            {
                SetRightSoftkeyFunction(mmi_imgview_exit_from_fmgr_emptry_folder, KEY_EVENT_UP);
                SetLeftSoftkeyFunction(entry_fmgr_app_empty_folder_option, KEY_EVENT_UP);
            }
        }
            break;
    #endif /* __MMI_IMAGE_VIEWER__ */ 

    #ifdef __MMI_VIDEO_PLAYER__
        case APP_VDOPLY:
        {

            /* create image cache */
            mmi_fmgr_create_thumb_image_cache(MMI_thick_menuitem_height);

        #if defined(__VDOREC_FEATURE_STORAGE__) || defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__)

            ShowCategory213Screen(
                STR_ID_VDOPLY_APP_NAME,
                iconId,             /* title */
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS, /* lsk */
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,    /* rsk */
                count,
                mmi_fmgr_draw_file_menuitem_callback,
                mmi_fmgr_hide_file_menuitem_callback,
                fmgr_p->cur_index,  /* hiligth item idx */
                arrow_display,
                (U8*) NULL);

            if (count == 0)
            {
                SetRightSoftkeyFunction(mmi_vdoply_exit_from_fmgr_emptry_folder, KEY_EVENT_UP);
                SetLeftSoftkeyFunction(entry_fmgr_app_empty_folder_option, KEY_EVENT_UP);
            }

        #else /* defined(__VDOREC_FEATURE_STORAGE__) || defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__) */ 
            ShowCategory213Screen(
                STR_ID_VDOPLY_APP_NAME,
                iconId,             /* title */
                0,
                0,                  /* lsk */
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,    /* rsk */
                count,
                mmi_fmgr_draw_file_menuitem_callback,
                mmi_fmgr_hide_file_menuitem_callback,
                fmgr_p->cur_index,  /* hiligth item idx */
                arrow_display,
                (U8*) NULL);

            if (count == 0)
            {
                SetRightSoftkeyFunction(mmi_vdoply_exit_from_fmgr_emptry_folder, KEY_EVENT_UP);
            }

        #endif /* defined(__VDOREC_FEATURE_STORAGE__) || defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__) */ 
        }
            break;
    #endif /* __MMI_VIDEO_PLAYER__ */ 

    #ifdef __MMI_RING_COMPOSER__
        case APP_RINGTONECOMPOSER:
        {

            /* create image cache */
            mmi_fmgr_create_thumb_image_cache(MMI_MENUITEM_HEIGHT * 2);

            if (count > 0)
            {
                ShowCategory212Screen(
                    STR_COMPOSER_RINGTONE_LIST,
                    iconId,
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    count,
                    mmi_fmgr_get_file_item_callback,
                    mmi_fmgr_get_file_hint_callback,
                    mmi_fmgr_draw_file_info_callback,
                    mmi_fmgr_hide_file_info_callback,
                    2,                  /* info box row count */
                    0,                  /* info bg img id */
                    fmgr_p->cur_index,                  /* hiligth item idx */
                    (U8*) guiBuffer);
            }
            else
            {
                ShowCategory213Screen(
                    STR_COMPOSER_RINGTONE_LIST,
                    iconId,
                    STR_COMPOSER_RINGTONE_ADD,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    0,
                    mmi_fmgr_draw_file_menuitem_callback,
                    mmi_fmgr_hide_file_menuitem_callback,
                    0,                  /* hiligth item idx */
                    0,
                    (U8*) guiBuffer);

                SetLeftSoftkeyFunction(RngcExecAdd, KEY_EVENT_UP);
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            }
        }
            break;
    #endif /* __MMI_RING_COMPOSER__ */ 

    #ifdef __MMI_EBOOK_READER__
        case APP_EBOOK:
        {

            /* create image cache */
            mmi_fmgr_create_thumb_image_cache(MMI_MENUITEM_HEIGHT * 2);

            if (count > 0)
            {
                ShowCategory212Screen(
                    EBOOK_TITLE_BOOKSHELF,
                    GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    count,
                    ebr_get_file_item_callback,
                    mmi_fmgr_get_file_hint_callback,
                    mmi_fmgr_draw_file_info_callback,
                    mmi_fmgr_hide_file_info_callback,
                    2,                  /* info box row count */
                    0,                  /* info bg img id */
                    0,                  /* hiligth item idx */
                    (U8*) guiBuffer);

            }
            else
            {
                ShowCategory213Screen(
                    EBOOK_TITLE_BOOKSHELF,
                    GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    0,
                    mmi_fmgr_draw_file_menuitem_callback,
                    mmi_fmgr_hide_file_menuitem_callback,
                    0,                  /* hiligth item idx */
                    0,
                    (U8*) guiBuffer);
                SetLeftSoftkeyFunction(ebr_show_limit_book_shelf_option, KEY_EVENT_UP);
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

            }

        }
            break;
    #endif /* __MMI_EBOOK_READER__ */ /* __MMI_RING_COMPOSER__ */

    #ifdef __MMI_SOUND_RECORDER__
        case APP_SOUNDRECORDER:
        {
            if (count > 0)
            {
                /* create image cache */
                mmi_fmgr_create_thumb_image_cache(MMI_MENUITEM_HEIGHT * 2);

                ShowCategory212Screen(
            #ifdef __MMI_SOUND_RECORDER_STYLE_X__
                                         STR_ID_SNDREC_LIST,
            #else 
                                         STR_ID_SNDREC_MAIN,
            #endif 
                                         iconId,    /* title   */
                                         STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS,        /* lsk */
                                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,      /* rsk */
                                         count, mmi_fmgr_get_file_item_callback, mmi_fmgr_get_file_hint_callback, mmi_fmgr_draw_file_info_callback, mmi_fmgr_hide_file_info_callback, 2,        /* info box row count */
                                         0,         /* info bg img id */
                                         0,         /* hiligth item idx */
                                         (U8*) guiBuffer);
            }
            else
            {

                /* create image cache */
                mmi_fmgr_create_thumb_image_cache(MMI_thick_menuitem_height);

                ShowCategory213Screen(
            #ifdef __MMI_SOUND_RECORDER_STYLE_X__
                                         STR_ID_SNDREC_LIST,
            #else 
                                         STR_ID_SNDREC_MAIN,
            #endif 
                                         iconId,    /* title   */
                                         STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS,        /* lsk */
                                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,      /* rsk */
                                         0, mmi_fmgr_draw_file_menuitem_callback, mmi_fmgr_hide_file_menuitem_callback, 0,      /* hiligth item idx */
                                         0, (U8*) guiBuffer);
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
                SetLeftSoftkeyFunction(entry_fmgr_app_empty_folder_option, KEY_EVENT_UP);
            }
        }
            break;
    #endif /* __MMI_SOUND_RECORDER__ */ 
    #ifdef __MMI_AB_REPEATER__
        case APP_ABREPEATER:
        {
            if (count > 0)
            {
                /* create image cache */
                mmi_fmgr_create_thumb_image_cache(MMI_MENUITEM_HEIGHT * 2);

                ShowCategory212Screen(
                    STR_ID_ABREPEAT_TITLE,
                    iconId,             /* title   */
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    count,
                    mmi_fmgr_get_file_item_callback,
                    mmi_fmgr_get_file_hint_callback,
                    mmi_fmgr_draw_file_info_callback,
                    mmi_fmgr_hide_file_info_callback,
                    2,                  /* info box row count */
                    0,                  /* info bg img id */
                    0,                  /* hiligth item idx */
                    (U8*) guiBuffer);
            }
            else
            {

                /* create image cache */
                mmi_fmgr_create_thumb_image_cache(MMI_thick_menuitem_height);

                ShowCategory213Screen(
                    STR_ID_ABREPEAT_TITLE,
                    iconId,             /* title   */
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS, /* lsk */
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,    /* rsk */
                    0,
                    mmi_fmgr_draw_file_menuitem_callback,
                    mmi_fmgr_hide_file_menuitem_callback,
                    0,                  /* hiligth item idx */
                    0,
                    (U8*) guiBuffer);
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
                SetLeftSoftkeyFunction(entry_fmgr_app_empty_folder_option, KEY_EVENT_UP);
            }
        }
            break;
    #endif /* __MMI_AB_REPEATER__ */ 

    #ifdef __MMI_SWFLASH__
        case APP_SWFLASH:
        {
            /* create image cache */
            mmi_fmgr_create_thumb_image_cache(MMI_MENUITEM_HEIGHT * 2);
        
            ShowCategory212Screen(
                STR_ID_SWFLASH_APP,
                iconId,             /* title   */
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS, /* lsk */
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,    /* rsk */
                count,
                mmi_fmgr_get_file_item_callback,
                mmi_fmgr_get_file_hint_callback,
                mmi_fmgr_draw_file_info_callback,
                mmi_fmgr_hide_file_info_callback,
                2,         /* info box row count */
                0,         /* info bg img id */
                0,         /* hiligth item idx */
                (U8*) guiBuffer);
        
            //if (count == 0)
            //{
            //    SetRightSoftkeyFunction(mmi_vdoply_exit_from_fmgr_emptry_folder, KEY_EVENT_UP);
              //  SetLeftSoftkeyFunction(entry_fmgr_app_empty_folder_option, KEY_EVENT_UP);
            //}
        }
            break;
#endif /* __MMI_SWFLASH__ */ 

        case APP_FILEMANAGER:
        default:    /* others */
        {

            /* create image cache */
            mmi_fmgr_create_thumb_image_cache(MMI_MENUITEM_HEIGHT * 2);

            ShowCategory212Screen(
                STR_FMGR_TITLE,
                iconId,             /* title */
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS, /* lsk */
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,    /* rsk */
                count,
                mmi_fmgr_get_file_item_callback,
                mmi_fmgr_get_file_hint_callback,
                mmi_fmgr_draw_file_info_callback,
                mmi_fmgr_hide_file_info_callback,
                2,                  /* info box row count */
                0,                  /* info bg img id */
                highlightId,        /* hiligth item idx */
                (U8*) guiBuffer);
        }

            break;
    }
    /*****************************************************************************/
   
    /* key handlers are set in highlight_fmgr_node */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  exit_fmgr_mul_odf_explorer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_fmgr_mul_odf_explorer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_fmgr_free_thumb_image_cache();

    StopTimer(FMGR_AUDIO_TIMER);
    if (fmgr_p->audio_state == TRUE)
    {
        fmgr_p->audio_state = FALSE;
        mdi_audio_stop_file();
    }

    currHistory.scrnID = SCR_FMGR_MUL_ODF_EXPLORER;
    currHistory.entryFuncPtr = entry_fmgr_mul_odf_explorer;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(currHistory.guiBuffer);
    AddHistory(currHistory);

}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_app_browse_multi_odf_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_app_browse_multi_odf_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U16 nNumofItem;
    U16 menuId, iconId;
    U8 *guiBuffer;
//    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FMGR_APP_MUL_ODF_OPTION, NULL, entry_fmgr_app_browse_multi_odf_menu, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_APP_MUL_ODF_OPTION);

    menuId = fmgr_get_app_browse_multi_odf_menu();

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild_Ext(menuId);
    GetSequenceStringIds_Ext(menuId, nStrItemList);
    SetParentHandler(menuId);
    iconId = fmgr_get_app_title_icon_id();

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        iconId,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  fmgr_get_app_browse_multi_odf_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 fmgr_get_app_browse_multi_odf_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 menuId=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (fmgr_p->src_application)
    {
#if 0
    #ifdef __MMI_AB_REPEATER__
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_AB_REPEATER__ */ 
    #ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SWFLASH__ */ 
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_IMAGE_VIEWER__
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_IMAGE_VIEWER__ */ /* __MMI_CAEMRA__ */
        #ifdef __MMI_VIDEO_PLAYER__
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_VIDEO_PLAYER__ */ 
/* under construction !*/
        #ifdef __MMI_SOUND_RECORDER__
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_SOUND_RECORDER__ */ 
        #ifdef __MMI_EBOOK_READER__
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_EBOOK_READER__ */ 
#endif 
        default:
            menuId = MENU_FMGR_APP_DRM_ODF_TYPE_OPTIONS;
            break;
    }
    return menuId;
}



/*****************************************************************************
 * FUNCTION
 *  fmgr_app_mul_odf_goback_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_app_mul_odf_goback_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    GoBackHistory();
}

#endif /* #if defined(__DRM_V02__) */

#endif /* __DRM_MTK__ */
#endif /* __DRM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  fmgr_extract_drm_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void fmgr_extract_drm_content(void)
{
#ifdef __FMGR_DRM_UT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 *dec_buf = (U8 *)get_ctrl_buffer(2048);
	FS_HANDLE handle, output;
	U32 size, len;
	U8 *tmp_path = NULL;
    FMGR_FILE_INFO_STRUCT file_info;
    U8 perm = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

    mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name);

    handle = DRM_open_file((PU16) fmgr_p->file_path, FS_READ_ONLY, perm);
    if (handle > FS_NO_ERROR)
    {
        if (FMGR_FILTER_IS_SET_AUDIO(&file_info.file_type) ||
        	FMGR_FILTER_IS_SET_VIDEO(&file_info.file_type))
        {
            perm = DRM_PERMISSION_PLAY;
        }
        else if (FMGR_FILTER_IS_SET_IMAGE(&file_info.file_type))
        {
            perm = DRM_PERMISSION_DISPLAY;
        }
    #ifdef __J2ME__
        else if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JAR) ||
                 FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JAD))
        {
            perm = DRM_PERMISSION_EXECUTE;
        }
    #endif /* __J2ME__ */ 
        
    	
    	{	
    		U8 str_len = mmi_ucs2strlen(fmgr_p->file_path);
    		tmp_path = (U8 *)get_ctrl_buffer(str_len * 2);
    		memset(tmp_path, 0, str_len * 2);
    		DRM_file_size(handle, &size);
    	        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    		mmi_ucs2cpy((PS8)tmp_path, fmgr_p->file_path);
    		mmi_ucs2cat((PS8)tmp_path, (PS8)L"tmp.");
    		mmi_ucs2cat((PS8)tmp_path, file_info.file_ext);
    		
			output = FS_Open((U16 *)tmp_path, FS_CREATE_ALWAYS);
    		do
    		{
				kal_int32 ret;

    			DRM_read_file(handle, dec_buf, 2048, &len);
    			ret = FS_Write(output, dec_buf, len, &len);
    			ASSERT(ret >= 0);
    			if(size <= len)
    			    break;
    			
    				size -= len;
    		}while (size > 0);
    		
    		FS_Close(output);
    		free_ctrl_buffer(dec_buf);
    		free_ctrl_buffer(tmp_path);
    	}
    }
    
    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_process_drm_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void fmgr_process_drm_content(void)
{
#ifdef __FMGR_DRM_UT__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

        if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == TRUE
#ifndef __MMI_SHOW_FILE_EXT__
            && mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == TRUE
#endif 
            )
        ;
    if (mmi_ucs2ncmp (file_info.file_ext, (PS8)L"DM", 2) == 0)
        DRM_process_file((U8*)DRM_MIMETYPE_MESSAGE, (PU16)fmgr_p->file_path, FALSE);
    else if (mmi_ucs2ncmp (file_info.file_ext, (PS8)L"DCF", 3) == 0)
        DRM_process_file((U8*)DRM_MIMETYPE_CONTENT, (PU16)fmgr_p->file_path, FALSE);
    else if (mmi_ucs2ncmp (file_info.file_ext, (PS8)L"DRC", 3) == 0)
        DRM_process_file((U8*)DRM_MIMETYPE_RIGHTS_WB, (PU16)fmgr_p->file_path, FALSE);
    else if (mmi_ucs2ncmp (file_info.file_ext, (PS8)L"DR", 2) == 0)
        DRM_process_file((U8*)DRM_MIMETYPE_RIGHTS, (PU16)fmgr_p->file_path, FALSE);
    else
   
    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
#endif
}




/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_detail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_detail(void)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL need_activate = FALSE;
#endif /* __DRM_SUPPORT__ */ 
    FMGR_FILE_INFO_STRUCT file_info;
    S8 buffer[32];
    U32 file_size;

    /* U8*  description[10]; */
    U8 *guiBuffer, *info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FMGR_DETAIL, NULL, entry_fmgr_detail, NULL);

    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_DETAIL);

    info = (PU8) subMenuData;

    mmi_ucs2cpy((PS8) info, (PS8) GetString(STR_ID_FMGR_FILE_DATE));
    mmi_ucs2cat((PS8) info, (PS8) L"\n");
    date_string(&file_info.time, (PU16) & info[mmi_ucs2strlen((PS8) info) << 1], DT_IDLE_SCREEN);
    mmi_ucs2cat((PS8) info, (PS8) L"\n");

    mmi_ucs2cat((PS8) info, (PS8) GetString(STR_ID_FMGR_FILE_SIZE));
    mmi_ucs2cat((PS8) info, (PS8) L"\n");
    if (file_info.file_size > 1024 * 1024)
    {
        file_size = file_info.file_size / 1024;
        sprintf(buffer, "%d.%dM", (U16) (file_size / 1024), (U16) ((file_size % 1024) / 103));
    }
    else if (file_info.file_size > 1024)
    {
        sprintf(buffer, "%d.%dK", (U16) (file_info.file_size / 1024), (U16) ((file_info.file_size % 1024) / 103));
    }
    else    /* less than 1024 */
    {
        sprintf(buffer, "%dB", (U16) (file_info.file_size));
    }
    mmi_asc_to_ucs2((PS8) & info[mmi_ucs2strlen((PS8) info) << 1], (PS8) buffer);
    mmi_ucs2cat((PS8) info, (PS8) L"\n");

#ifdef __DRM_SUPPORT__
    if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == TRUE
#ifndef __MMI_SHOW_FILE_EXT__
        && mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == TRUE
#endif 
        )
    {
        
        U8 perm = 0;

        if (FMGR_FILTER_IS_SET_AUDIO(&file_info.file_type) ||
        	FMGR_FILTER_IS_SET_VIDEO(&file_info.file_type))
        {
            perm = DRM_PERMISSION_PLAY;
        }
        else if (FMGR_FILTER_IS_SET_IMAGE(&file_info.file_type))
        {
            perm = DRM_PERMISSION_DISPLAY;
        }
    #ifdef __J2ME__
        else if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JAR) ||
                 FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JAD))
        {
            perm = DRM_PERMISSION_EXECUTE;
        }
    #endif /* __J2ME__ */ 

        need_activate = mmi_rmgr_populate_drm_info((kal_wchar *)fmgr_p->file_path, DRM_PERMISSION_ALL, info);
    
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    }
#endif /* __DRM_SUPPORT__ */ 

#if 0
#ifdef __DRM_SUPPORT__
/* under construction !*/
#ifdef __FLIGHT_MODE_SUPPORT__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __DRM_SUPPORT__ */ 
/* under construction !*/
#endif /* if 0 */

        ShowCategory74Screen(
            STR_FMGR_DETAIL,
            GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) subMenuData,
            MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
            guiBuffer);

    SetKeyHandler(fmgr_extract_drm_content, KEY_VOL_UP, KEY_EVENT_DOWN);
    fmgr_process_drm_content();

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_rename_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_rename_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    PS8 ext_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
    mmi_ucs2cpy((PS8) fmgr_p->new_file_name, (PS8) file_info.file_name);

    /* rename file: old name in fmgr_p->old_file_path */
    mmi_ucs2cpy((PS8) fmgr_p->old_file_path, (PS8) fmgr_p->file_path);
#if defined(__DRM_V02__)  
    if ( (mmi_ucs2ncmp((PS8)fmgr_p->old_file_path+ ((mmi_ucs2strlen((PS8)fmgr_p->old_file_path)-4)<<1), (PS8)L".odf", 4) == 0) ||
         (mmi_ucs2ncmp((PS8)fmgr_p->old_file_path+ ((mmi_ucs2strlen((PS8)fmgr_p->old_file_path)-4)<<1), (PS8)L".ODF", 4) == 0))
    
    {
        mmi_ucs2cat(fmgr_p->old_file_path, (PS8)L"\\");
    }
#endif /* DRM_V02 */
    mmi_ucs2cat((PS8) fmgr_p->old_file_path, (PS8) file_info.file_name);
#ifndef __MMI_SHOW_FILE_EXT__
    mmi_ucs2cat((PS8) fmgr_p->old_file_path, (PS8) file_info.file_ext);
#endif
    fmgr_p->ext_name = NULL;

#if defined(__DRM_V02__)
    {
        FMGR_FILTER file_type;

        mmi_fmgr_get_file_type(fmgr_p->old_file_path, &file_type);
        if (DRM_is_archive(0, (PU16)fmgr_p->old_file_path) && (!FMGR_FILTER_IS_SET(&file_type, FMGR_TYPE_ODF)))
        {
            DisplayPopup((PU8)GetString(STR_GLOBAL_INVALID),
                     IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            return;
        }
    }
#endif

#ifdef __MMI_SHOW_FILE_EXT__
    if (!(file_info.attribute & FS_ATTR_DIR))
    {
        ext_name = mmi_fmgr_extract_ext_file_name((PS8) fmgr_p->new_file_name);

        /* rename file should keep original extension filename in fmgr_p->ext_name
           and append after user input new name */
        if (ext_name != NULL)
        {
            *(ext_name - 2) = 0;
            fmgr_p->ext_name = mmi_fmgr_extract_ext_file_name((PS8) fmgr_p->old_file_path);
        }
        else
	{
            fmgr_p->ext_name = NULL;
	}
    }
#endif /* __MMI_SHOW_FILE_EXT__ */ 

    if (file_info.is_short)
    {
        U8 temp[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];

        /* rename short name file should pass converted short name to editor,
           so that the display will be the same as in File Manager */
        mmi_ucs2cpy((S8*) temp, (S8*) fmgr_p->new_file_name);
        mmi_chset_mixed_text_to_ucs2_str(
            (U8*) fmgr_p->new_file_name,
            (MAX_SUBMENU_CHARACTERS - 1) * ENCODING_LENGTH,
            (U8*) temp,
            (mmi_chset_enum) PhnsetGetDefEncodingType());
    }
    entry_fmgr_filename_editor();
    SetHiliteHandler(MENU_FMGR_EDITOR_DONE, highlight_fmgr_rename_done);
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_filename_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_filename_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 length = FMGR_MAX_FILE_LEN;
    U16 iconId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FMGR_FILENAME_EDITOR, NULL, entry_fmgr_filename_editor, NULL);

    if (IsScreenPresent(SCR_FMGR_FOLDER_OPTION) ||
        IsScreenPresent(SCR_FMGR_APP_FOLDER_OPTION) ||
        IsScreenPresent(SCR_FMGR_TREE_OPTION) ||
        IsScreenPresent(SCR_FMGR_FILE_OPTION) || IsScreenPresent(SCR_FMGR_APP_FILE_OPTION))
    {
        /* create under folder or rename, check folder present or not */
        /* create under drive no need to check drive present */
        U8 flag = fmgr_check_file_present();

        if (flag < FMGR_NO_ERROR)
        {
            return;
        }
        if (flag == FMGR_FILE)
        {
            length -= 5;
        }
    }

    if (mmi_ucs2strlen((PS8) fmgr_p->new_file_name) >= length)
    {
        memset(&fmgr_p->new_file_name[(length - 1) << 1], 0, sizeof(fmgr_p->new_file_name) - ((length - 1) << 1));
    }

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_FILENAME_EDITOR);
    iconId = fmgr_get_app_title_icon_id();

    ShowCategory5Screen(
        STR_GLOBAL_EDIT,
        iconId,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (INPUT_TYPE_ALPHANUMERIC_UPPERCASE),
        (PU8) fmgr_p->new_file_name,
        length,
        guiBuffer);

    SetLeftSoftkeyFunction(entry_fmgr_editor_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_editor_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_editor_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U8 *guiBuffer;
    U16 nNumofItem, imageId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FMGR_EDITOR_OPTION, NULL, entry_fmgr_editor_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_EDITOR_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(MITEM_FMGR_EDITOR_OPTION);
    GetSequenceStringIds(MITEM_FMGR_EDITOR_OPTION, nStrItemList);
    SetParentHandler(MITEM_FMGR_EDITOR_OPTION);

    imageId = fmgr_get_app_title_icon_id();

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        imageId,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    RegisterInputMethodScreenCloseFunction(fmgr_return_to_editor);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_delete_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_delete_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str[100];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_check_file_present() < FMGR_NO_ERROR)
    {
        return;
    }

    memset(str, 0, sizeof(str));
    if (fmgr_p->delete_all == FMGR_DELETE_ALL)
    {
        mmi_ucs2cpy((PS8) str, (PS8) get_string(STR_FMGR_DELETE_ALL));
    }
    else if (fmgr_p->delete_all == FMGR_DELETE_ALL_EXPIRED)
    {
        mmi_ucs2cpy((PS8) str, (PS8) get_string(STR_FMGR_DRM_RIGHT_DELETE_ALL_EXPIRED));
    }
    else
    {
        FMGR_FILE_INFO_STRUCT file_info;

        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
        mmi_ucs2cpy((PS8) str, (PS8) get_string(STR_GLOBAL_DELETE));
        mmi_ucs2cat((PS8) str, (PS8) L" ");
        if (file_info.is_short)
        {
            U16 len;

        #ifndef __MMI_SHOW_DAF_FILE_EXT__
            if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_DAF) ||
                FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_MP2))
            {
                PS8 ext_name;

                ext_name = mmi_fmgr_extract_ext_file_name((PS8) file_info.file_name);

                /* rename file should keep original extension filename in fmgr_p->ext_name
                   and append after user input new name */
                if (ext_name != NULL)
                {
                    *(ext_name - 2) = 0;
                }
            }
        #endif

            len = mmi_ucs2strlen((PS8) str) << 1;
            mmi_chset_mixed_text_to_ucs2_str(
                (U8*) & str[len],
                (MAX_SUBMENU_CHARACTERS - 1) * ENCODING_LENGTH,
                (U8*) file_info.file_name,
                PhnsetGetDefEncodingType());
        }
        else
        {
        #ifndef __MMI_SHOW_DAF_FILE_EXT__
            if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_DAF) ||
                FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_MP2))
            {
                PS8 ext_name;

                ext_name = mmi_fmgr_extract_ext_file_name((PS8) file_info.file_name);

                /* rename file should keep original extension filename in fmgr_p->ext_name
                   and append after user input new name */
                if (ext_name != NULL)
                {
                    *(ext_name - 2) = 0;
                }
            }
        #endif 

            mmi_ucs2cat((PS8) str, (PS8) file_info.file_name);
        }
    }

    mmi_ucs2cat((PS8) str, (PS8) get_string(STR_ID_FMGR_QUESTION_MARK));

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU16) str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    if (fmgr_p->delete_all == FMGR_DELETE_ALL)
    {
        SetLeftSoftkeyFunction(fmgr_delete_all_file, KEY_EVENT_UP);
    }
#ifdef __DRM_MTK__
    else if (fmgr_p->delete_all == FMGR_DELETE_ALL_EXPIRED)
    {
        SetLeftSoftkeyFunction(fmgr_delete_all_expired_file, KEY_EVENT_UP);
    }
#endif /* __DRM_MTK__ */
    else
    {
        SetLeftSoftkeyFunction(fmgr_delete, KEY_EVENT_UP);
    }
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_app_drive_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_app_drive_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U16 nNumofItem;
    U16 menuId, iconId;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FMGR_APP_DRIVE_OPTION, NULL, entry_fmgr_app_drive_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_APP_DRIVE_OPTION);

    switch (fmgr_p->src_application)
    {
    #ifdef __MMI_FTS_SUPPORT__
        case APP_FTP:
            menuId = MENU_CONN_FTP_SHARED_FOLDER;
            break;
    #endif /* __MMI_FTS_SUPPORT__ */ 
    #ifdef __MMI_BIP_SUPPORT__
        case APP_BIP:
            menuId = MENU_CONN_BIP_SHARED_FOLDER;
            break;
    #endif /* __MMI_BIP_SUPPORT__ */ 
    
        default:
            menuId = MITEM_FMGR_APP_TYPE_OPTIONS;
            break;
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);
    SetParentHandler(menuId);
    iconId = fmgr_get_app_title_icon_id();

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        iconId,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_app_folder_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_app_folder_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U16 nNumofItem;
    U16 menuId, iconId;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FMGR_APP_FOLDER_OPTION, NULL, entry_fmgr_app_folder_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_APP_FOLDER_OPTION);

    switch (fmgr_p->src_application)
    {
        default:
            menuId = MITEM_FMGR_APP_TYPE_OPTIONS;
            break;
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);
    SetParentHandler(menuId);
    iconId = fmgr_get_app_title_icon_id();

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        iconId,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_app_empty_folder_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_app_empty_folder_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U16 nNumofItem;
    U16 menuId = 0, iconId;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FMGR_APP_EMPTY_FOLDER_OPTION, NULL, entry_fmgr_app_empty_folder_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_APP_EMPTY_FOLDER_OPTION);

    switch (fmgr_p->src_application)
    {
    #ifdef __MMI_IMAGE_VIEWER__
        case APP_IMAGEVIEWER:
            menuId = MENU_ID_IMGVIEW_EMPTY_FOLDER_OPTION;
            break;
    #endif /* __MMI_IMAGE_VIEWER__ */ /* __MMI_CAEMRA__ */

    #ifdef __MMI_VIDEO_PLAYER__
        case APP_VDOPLY:
            menuId = MENU_ID_VDOPLY_EMPTY_FOLDER_OPTION;
            break;
    #endif /* __MMI_VIDEO_PLAYER__ */ 

    #ifdef __MMI_SOUND_RECORDER__
        case APP_SOUNDRECORDER:
    #ifdef MT6205B
            menuId = MENU_ID_SNDREC_OPTION_4;
    #else 
            menuId = MENU_ID_SNDREC_OPTION_1;
    #endif 
            break;
    #endif /* __MMI_SOUND_RECORDER__ */ 

    #ifdef __MMI_AB_REPEATER__
        case APP_ABREPEATER:
            menuId = MENU_ID_AB_REPEAT_EMPTY_FOLDER_OPTION;
            break;
    #endif /* __MMI_AB_REPEATER__ */ 

    #ifdef __MMI_SWFLASH__
        case APP_SWFLASH:
            menuId = MENU_ID_SWFLASH_EMPTY_FOLDER_OPTION;
            break;
    #endif /* __MMI_SWFLASH__ */ 

        default:
            ASSERT(0);
            break;
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(menuId);
    GetSequenceStringIds(menuId, nStrItemList);
    SetParentHandler(menuId);
    iconId = fmgr_get_app_title_icon_id();

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        iconId,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_app_file_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_app_file_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U16 nNumofItem;
    U16 menuId, iconId;
    U8 *guiBuffer;
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FMGR_APP_FILE_OPTION, exit_fmgr_app_file_option, entry_fmgr_app_file_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_APP_FILE_OPTION);

    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

    if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
#ifndef __MMI_SHOW_FILE_EXT__
        || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
#endif 
        )
        return;
    else
    {
    #if defined(__DRM_V02__)
        if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_ODF))
        {
            mmi_fmgr_get_drm_file_type_by_path((PS8) fmgr_p->file_path, &file_info.file_type);
        }
    #endif
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    }

    menuId = fmgr_get_app_file_option_menu(&file_info);

    switch (fmgr_p->src_application)
    {
    #ifdef __MMI_AB_REPEATER__
        case APP_ABREPEATER:
            menuId = MENU_ID_AB_REPEATER_OPTION;
            break;
    #endif /* __MMI_AB_REPEATER__ */ 
    #ifdef __MMI_SWFLASH__
        case APP_SWFLASH:
            /* menuId = mmi_swflash_get_menuId(file_info.file_name); */
            break;
    #endif /* __MMI_SWFLASH__ */ 
        case APP_RINGTONECOMPOSER:
            menuId = MENU_COMP_RINGTONE_COMP_SELMENU_1;
            break;

    #ifdef __MMI_IMAGE_VIEWER__
        case APP_IMAGEVIEWER:
    #if defined(__MMI_EXIF__)       /* turn off exif until W06.13 */
            if ((FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPG) == FALSE &&
                 FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPEG) == FALSE))
            {
                mmi_frm_hide_menu_item(MENU_FMGR_GEN_OPTION_JPG_DETAIL);
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_FMGR_GEN_OPTION_JPG_DETAIL);
            }
    #else /* defined(__MMI_EXIF__) */ 
            mmi_frm_hide_menu_item(MENU_FMGR_GEN_OPTION_JPG_DETAIL);
    #endif /* defined(__MMI_EXIF__) */ 

            if (menuId == MITEM_FMGR_APP_IMG_TYPE_OPTIONS)
            {
                menuId = MENU_ID_IMGVIEW_FILE_OPTION;
            }
            else
            {
                menuId = MENU_ID_IMGVIEW_FILE_OPTION_NO_SIM;
            }
            break;
    #endif /* __MMI_IMAGE_VIEWER__ */ /* __MMI_CAEMRA__ */

        #ifdef __MMI_VIDEO_PLAYER__
        case APP_VDOPLY:
            if (menuId == MITEM_FMGR_APP_VID_TYPE_OPTIONS)
            {
                BOOL is_drm;
                U16 forward;

                /* check if can foward or not */
                forward = fmgr_get_forward_option_menu(&file_info, &is_drm);
                if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
                {
                    /* cant foward */
                    menuId = MENU_ID_VDOPLY_FILE_OPTION_NO_SIM;
                }
                else
                {
                    if (GetNumOfChild_Ext(forward) == 0)
                    {
                        /* have foward menu, but no child menu, hide also */
                        menuId = MENU_ID_VDOPLY_FILE_OPTION_NO_SIM;
                    }
                    else
                    {
                        menuId = MENU_ID_VDOPLY_FILE_OPTION;
                    }
                }

            }
            else
            {
                menuId = MENU_ID_VDOPLY_FILE_OPTION_NO_SIM;
            }
            mmi_frm_unhide_menu_item(MENU_FMGR_FWD_MMS);
            break;
        #endif /* __MMI_VIDEO_PLAYER__ */ 

        #ifdef __MMI_SOUND_RECORDER__
        case APP_SOUNDRECORDER:
            menuId = mmi_sndrec_get_menuId();
            break;
        #endif /* __MMI_SOUND_RECORDER__ */ 
        #ifdef __MMI_EBOOK_READER__
        case APP_EBOOK:
            menuId = mmi_ebook_get_menuId();
            break;
        #endif /* __MMI_EBOOK_READER__ */ 
        default:
            break;
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild_Ext(menuId);
    GetSequenceStringIds_Ext(menuId, nStrItemList);
    SetParentHandler(menuId);
    iconId = fmgr_get_app_title_icon_id();

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        iconId,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  exit_fmgr_app_file_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_fmgr_app_file_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_unhide_menu_item(MENU_FMGR_GEN_OPTION_FORWARD);
}


#ifdef __MMI_DOWNLOAD_AGENT__


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_da_forward
 * DESCRIPTION
 *  highlight handler for forward file from download agent
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_da_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(entry_fmgr_da_forward_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(entry_fmgr_da_forward_option, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(entry_fmgr_da_forward_option);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_receive_da_file
 * DESCRIPTION
 *  receive file from download agent
 * PARAMETERS
 *  mime_type           [IN]        
 *  mime_subtype        [IN]        
 *  action              [IN]        
 *  file_path           [IN]        
 *  url                 [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_receive_da_file(S32 session_id, S32 mime_type, S32 mime_subtype, S32 action, PU16 file_path, PS8 url, PS8 mime_type_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prevent re-entry */
    if (fmgr_p->src_application == APP_FILEMANAGER
#ifdef __MMI_MY_FAVORITE__
        || fmgr_p->src_application == APP_MYFAVORITE
    #endif /* #ifdef __MMI_MY_FAVORITE__*/
		)
    {
        fmgr_adjust_history(SCR_FMGR_MAIN);
    }
    else
    {
        fmgr_remove_all_screen();
    }
    
    /* keep file info in FMGR context */
    mmi_ucs2cpy((PS8) fmgr_p->da_file_path, (PS8) file_path);
    fmgr_p->src_application = APP_FILEMANAGER;

    FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);

    entry_fmgr_da_file_option();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_is_da_file
 * DESCRIPTION
 *  check if is in download agent
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL fmgr_is_da_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_p->da_file_path[0] == 0 && fmgr_p->da_file_path[1] == 0)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_get_da_forward_option_menu
 * DESCRIPTION
 *  get forward option menu for the file from download agent
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S16 fmgr_get_da_forward_option_menu(S8* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER file_type;

#ifdef __DRM_SUPPORT__
    U8 drm_forward = FMGR_DRM_FWD_APP_FWD_OUT;  /* 0: can't forward at all, 
                                                   1: can forward to app, can't forward off device, 
                                                   2: can't forward to app, can forward off device,
                                                   3: can forward to app and off device */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drm_forward = fmgr_check_drm_forward(filepath, NULL);
    PRINT_INFORMATION("*** fmgr_get_da_forward_option_menu, rule=%d\n", drm_forward);
    if (drm_forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT || drm_forward == FMGR_DRM_NO_FWD_APP_FWD_OUT)
    {
        return 0;
    }
#endif /* __DRM_SUPPORT__ */ 

    mmi_fmgr_get_file_type(filepath, &file_type);

    if (FMGR_FILTER_IS_SET_IMAGE(&file_type))
    {
        return MENU_FMGR_DA_FWD_OPTION_IMG;
    }
    else if (FMGR_FILTER_IS_SET_AUDIO(&file_type))
    {
        return MENU_FMGR_DA_FWD_OPTION_AUD;
    }
#ifdef __MMI_VIDEO_PLAYER__
    else if (FMGR_FILTER_IS_SET_VIDEO(&file_type))
    {
        
    #ifdef __MMI_VIDEO_STREAM__
        if (FMGR_FILTER_IS_SET(&file_type, FMGR_TYPE_RAM) || 
            FMGR_FILTER_IS_SET(&file_type, FMGR_TYPE_SDP))
        {
            return 0;
        }
    #endif /* __MMI_VIDEO_STREAM__ */

        return MENU_FMGR_DA_FWD_OPTION_VID;
    }
#endif /* __MMI_VIDEO_PLAYER__ */ 
#ifdef __MMI_VCALENDAR__
    else if (FMGR_FILTER_IS_SET(&file_type, FMGR_TYPE_VCS))
    {
        return MENU_FMGR_DA_FWD_OPTION_VCAL;
    }
#endif /* __MMI_VCALENDAR__ */ 
#ifdef __MMI_VCARD__
    else if (FMGR_FILTER_IS_SET(&file_type, FMGR_TYPE_VCF))
    {
        return MENU_FMGR_DA_FWD_OPTION_VCARD;
    }
#endif /* __MMI_VCARD__ */ 
#ifdef __MMI_SWFLASH__ 
    else if ((FMGR_FILTER_IS_SET(&file_type,FMGR_TYPE_VIS))
 			 ||(FMGR_FILTER_IS_SET(&file_type,FMGR_TYPE_IVIS))
			 ||(FMGR_FILTER_IS_SET(&file_type,FMGR_TYPE_KVIS))
			 ||(FMGR_FILTER_IS_SET(&file_type,FMGR_TYPE_MVIS)))
    {
        return MENU_FMGR_FWD_OPTION_MFH;
    }
#endif
    else
    {
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_get_da_file_option_menu
 * DESCRIPTION
 *  get file option menu for file from download agent
 * PARAMETERS
 *  file_type       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
S16 fmgr_get_da_file_option_menu(S8* filepath, FMGR_FILTER *file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FMGR_FILTER_IS_SET_IMAGE(file_type))
    {
        return MITEM_FMGR_DA_IMG_TYPE_OPTIONS;
    }
    else if (FMGR_FILTER_IS_SET_AUDIO(file_type))
    {
        return MITEM_FMGR_DA_AUD_TYPE_OPTIONS;
    }
#ifdef __MMI_VIDEO_PLAYER__
    else if (FMGR_FILTER_IS_SET_VIDEO(file_type))
    {
        return MITEM_FMGR_DA_VID_TYPE_OPTIONS;
    }
#endif /* __MMI_VIDEO_PLAYER__ */ 
#if (defined ( __J2ME__ ) && !defined (__MMI_FMGR_DISABLE_JAVA_INSTALL__))
    else if (FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_JAD) || FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_JAR))
    {
        return MITEM_FMGR_DA_EXE_TYPE_OPTIONS;
    }
#endif /* (defined ( __J2ME__ ) && !defined (__MMI_FMGR_DISABLE_JAVA_INSTALL__)) */ 
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    else if (FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_THEME))
    {
        return MITEM_FMGR_DA_THM_TYPE_OPTIONS;
    }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
#ifdef __MMI_EBOOK_READER__
    else if (FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_EBOOK_TXT) ||
             FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_EBOOK_PDB))
    {
        return MITEM_FMGR_DA_EBK_TYPE_OPTIONS;
    }
#endif /* __MMI_EBOOK_READER__ */
#ifdef __MMI_BARCODEREADER__
    else if (FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_MBC))
    {
        return MITEM_FMGR_DA_QRV_TYPE_OPTIONS;
    }
#endif /* __MMI_BARCODEREADER__ */
#if defined(__DRM_V02__)
    else if (FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_ODF))
    {
        return MENU_FMGR_DA_MULTI_ODF_TYPE_OPTIONS;
    }
#endif /* #if defined(__DRM_V02__) */
#ifdef __MMI_SWFLASH__
   else if ((FMGR_FILTER_IS_SET(file_type,FMGR_TYPE_VIS))
			 ||(FMGR_FILTER_IS_SET(file_type,FMGR_TYPE_IVIS))
			 ||(FMGR_FILTER_IS_SET(file_type,FMGR_TYPE_KVIS))
			 ||(FMGR_FILTER_IS_SET(file_type,FMGR_TYPE_MVIS)))
   {
        S32 ret;
        U32 total_len = 0;
        U32 current_len = 0;
        U32 category = 0;
    
        ret = mdi_swflash_check_download_file((U16*) filepath, &total_len, &current_len, &category);
            
        if (ret == 0)
        {
            return MENU_ID_SWFLASH_DA;
        }
        else
        {
            return -1;
        }
   }
#endif
    else
    {
        return fmgr_get_da_forward_option_menu(filepath);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_da_file_option
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  S32     return  if > 0  ==> menu_id
 *                  if == 0 ==> no option
 *                  if < 0  ==> FS or DRM error
 *****************************************************************************/
S32 mmi_fmgr_get_da_file_option(S8* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER file_type;
    S32         menu_id;
    S16         fwd_menu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get menu id */
#if defined(__DRM_V02__)
    menu_id = mmi_fmgr_get_drm_file_type_by_path(filepath, &file_type);
#else
    menu_id = mmi_fmgr_get_file_type(filepath, &file_type);
#endif

    if (menu_id == FS_FILE_NOT_FOUND)
        return FS_FILE_NOT_FOUND;

    menu_id = fmgr_get_da_file_option_menu(filepath, &file_type);
    if(menu_id == 0)
    {
#if defined(__DRM_SUPPORT__)        
        return DRM_RESULT_NO_PERMISSION;
#else
        return 0;
#endif
    }
    else if(menu_id < 0)
    {
        return 0;
    }

    mmi_frm_unhide_menu_item(MENU_FMGR_DA_OPTION_FORWARD);
    fwd_menu = fmgr_get_da_forward_option_menu(filepath);
    if(fwd_menu <= 0)
    {
        mmi_frm_hide_menu_item(MENU_FMGR_DA_OPTION_FORWARD);
    }
    else
    {
        fmgr_hide_fwd_app_menu(&file_type);
        if(GetNumOfChild_Ext(fwd_menu) == 0)
            mmi_frm_hide_menu_item(MENU_FMGR_DA_OPTION_FORWARD);
    }
    
    if (!GetNumOfChild_Ext(menu_id))
        return 0;

    return menu_id;
}

/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_da_file_option
 * DESCRIPTION
 *  entry file option menu for file from download agent
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_da_file_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U16 nNumofItem;
    U16 iconId;
    U8 *guiBuffer;
    S32 menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    menu_id = mmi_fmgr_get_da_file_option(fmgr_p->da_file_path);

    if(menu_id < 0)
    {
        switch(menu_id)
        {
#if defined(__DRM_SUPPORT__)        
        case DRM_RESULT_NO_PERMISSION:
            DisplayPopup((PU8) GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
            break;
#endif

        default:
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(menu_id)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            break;
        }
        return;
    }
    else if(menu_id == 0)
    {
        /* should not happen */
        DisplayPopup((PU8) GetString(STR_ID_FMGR_NO_SUITABLE_APP), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        return;        
    }
    
    nNumofItem = GetNumOfChild_Ext((U16)menu_id);
    if (nNumofItem == 0)
    {
        /* should not happen */
        DisplayPopup((PU8) GetString(STR_ID_FMGR_NO_SUITABLE_APP), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        return;
    }

    EntryNewScreen(SCR_FMGR_DA_FILE_OPTION, exit_fmgr_da_file_option, entry_fmgr_da_file_option, NULL);

    SetDelScrnIDCallbackHandler(SCR_FMGR_DA_FILE_OPTION, (HistoryDelCBPtr) delete_fmgr_da_file_option_cb);
    
    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_DA_FILE_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    GetSequenceStringIds_Ext(menu_id, nStrItemList);
    SetParentHandler(menu_id);
    iconId = GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        iconId,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_da_file_option
 * DESCRIPTION
 *  entry file option menu for file from download agent
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8 delete_fmgr_da_file_option_cb(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(fmgr_p->da_file_path, 0, sizeof(fmgr_p->da_file_path));
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  exit_fmgr_da_file_option
 * DESCRIPTION
 *  exit file option menu for file from download agent
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_fmgr_da_file_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_unhide_menu_item(MENU_FMGR_DA_OPTION_FORWARD);
    fmgr_unhide_fwd_app_menu();
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_da_forward_option
 * DESCRIPTION
 *  entry forward option menu for file from download agent
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_da_forward_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER file_type;
    U16 nStrItemList[10];
    U16 nNumofItem;
    S16 menuId;
    U16 iconId;
    U8 *guiBuffer;
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = FS_Open((PU16) fmgr_p->da_file_path, FS_READ_ONLY);
    if (handle > FS_NO_ERROR)
    {
    	FS_Close(handle);
    }
    else
    {
        DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION);
        return;
    }

    EntryNewScreen(SCR_FMGR_DA_FORWARD_OPTION, fmgr_unhide_fwd_app_menu, entry_fmgr_da_forward_option, NULL);

    /* get menu id */
    menuId = fmgr_get_da_forward_option_menu(fmgr_p->da_file_path);
//    ASSERT(menuId > 0);

    mmi_fmgr_get_file_type(fmgr_p->da_file_path, &file_type);
    fmgr_hide_fwd_app_menu(&file_type);
    nNumofItem = GetNumOfChild_Ext(menuId);
    ASSERT(nNumofItem > 0);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_DA_FORWARD_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    GetSequenceStringIds_Ext(menuId, nStrItemList);
    SetParentHandler(menuId);
    iconId = GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        iconId,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(fmgr_forward_to_app, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif /* __MMI_DOWNLOAD_AGENT__ */ 


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_tree_explorer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_tree_explorer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 count, titleId;
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    mmi_fmgr_kernel_init((PS8) fmgr_p->file_path, filter, &count);

    if (count == 0)
    {
        mmi_ucs2_to_asc((PS8) nPrintableStr, (PS8) fmgr_p->file_path);
        PRINT_INFORMATION("entry tree explorer fail: %s", nPrintableStr);
        /* copy file d:\a.jpg when d:\ has no folder, show drive list instead of pop up empty */
        if (GetExitScrnID() == SCR_FMGR_FILE_OPTION && mmi_ucs2strlen((PS8)fmgr_p->file_path) == 3)
        {
            fmgr_p->cur_index = 0;
            entry_fmgr_main();
            return;
        }

        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
        if (GetExitScrnID() != SCR_FMGR_TREE_EXPLORER && !IsScreenPresent(SCR_FMGR_TREE_EXPLORER)
        	   && mmi_ucs2strlen((PS8)fmgr_p->file_path) > 3)
				EntryNewScreen(SCR_FMGR_TREE_EXPLORER, exit_fmgr_tree_explorer, NULL, NULL);					
        DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 0, 1000, EMPTY_LIST_TONE);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
        DeleteScreenIfPresent(SCR_FMGR_TREE_OPTION);
        DeleteScreenIfPresent(SCR_FMGR_DRIVE_OPTION);
        fmgr_p->enter_folder = FALSE;
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_reset_list_item_selected_callback();
    #endif 
        return;
    }

    EntryNewScreen(SCR_FMGR_TREE_EXPLORER, exit_fmgr_tree_explorer, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_TREE_EXPLORER);

    if (fmgr_p->enter_folder == TRUE)
    {
        /* enter tree explorer screen by user selection, not go back history after interrupt */
        fmgr_p->enter_folder = FALSE;
            fmgr_p->cur_index = 0;

        DeleteUptoScrID(SCR_FMGR_TREE_EXPLORER);
        /* enter tree explorer screen by user selection shall always highlight first item */
        guiBuffer = NULL;
    }

    if (fmgr_p->parent_name[0] != 0 || fmgr_p->parent_name[1] != 0)
    {
        fmgr_p->cur_index = fmgr_get_parent_highlight_id();
        memset(fmgr_p->parent_name, 0, sizeof(fmgr_p->parent_name));
        guiBuffer = NULL;
    }

    if (GetCurrScrnId() == SCR_FMGR_TREE_DRIVE_OPTION)
    {
        DeleteScreenIfPresent(SCR_FMGR_TREE_DRIVE_OPTION);
    }

    if (fmgr_p->tree_action == FMGR_ACTION_COPY)
    {
        titleId = STR_FMGR_COPY;
    }
    else
    {
        titleId = STR_FMGR_MOVE;
    }

    RegisterHighlightHandler(highlight_fmgr_tree_node);

    ShowCategory213Screen(
        titleId,
        GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID),   /* title         */
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,                             /* lsk         */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                                /* rsk         */
        count,
        mmi_fmgr_draw_file_menuitem_callback,
        mmi_fmgr_hide_file_menuitem_callback,
        fmgr_p->cur_index,                              /* hiligth item idx */
        CAT213_ARROW_ALL,
        guiBuffer);

    SetKeyHandler(fmgr_back_to_tree_parent, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(entry_fmgr_tree_option, KEY_EVENT_UP);
    SetKeyHandler(fmgr_set_curr_tree_and_enter, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(fmgr_back_to_tree_parent, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback_all(fmgr_set_curr_tree_and_enter);
#endif 
    return;

}


/*****************************************************************************
 * FUNCTION
 *  exit_fmgr_tree_explorer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_fmgr_tree_explorer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_FMGR_TREE_EXPLORER) == FALSE)
    {
        history currHistory;
        S16 nHistory = 0;

        currHistory.scrnID = SCR_FMGR_TREE_EXPLORER;
        currHistory.entryFuncPtr = entry_fmgr_tree_explorer;
        mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
        AddHistory(currHistory);
    }
    else
    {
        U8 *guiBuffer;

        guiBuffer = GetCurrGuiBuffer(SCR_FMGR_TREE_EXPLORER);
        GetCategoryHistory(guiBuffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_tree_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_tree_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U8 *guiBuffer;
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FMGR_TREE_OPTION, NULL, entry_fmgr_tree_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_TREE_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(MITEM_FMGR_TREE_OPTIONS);
    GetSequenceStringIds(MITEM_FMGR_TREE_OPTIONS, nStrItemList);
    SetParentHandler(MITEM_FMGR_TREE_OPTIONS);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_hide_fwd_app_menu
 * DESCRIPTION
 *  hide forward to application menu when no SIM case
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_hide_fwd_app_menu(FMGR_FILTER *file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* no Idle, can't forward to display setting */
    if (!IsScreenPresent(IDLE_SCREEN_ID))
    {
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_WALLPAPER);
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_SUB_WALLPAPER);
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_SCREENSAVER);
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_POWER_ON);
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_POWER_OFF);
    }
#ifdef __MMI_BG_SOUND_EFFECT__
    if (!FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_WAV))
    {
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_BGSOUND);
    }
#endif /* __MMI_BG_SOUND_EFFECT__ */ 
    
#ifdef M3D_MMI_SUPPORT
    if (FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_M3D))
    {
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_SUB_WALLPAPER);
    }
#endif

#ifdef __MMI_MESSAGES_EMS__
    if (FMGR_FILTER_IS_SET(file_type, FMGR_TYPE_EMS))
    {
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_WALLPAPER);
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_SUB_WALLPAPER);
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_SCREENSAVER);
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_POWER_ON);
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_POWER_OFF);
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_PHB);        
    }
#endif

}


/*****************************************************************************
 * FUNCTION
 *  fmgr_unhide_fwd_app_menu
 * DESCRIPTION
 *  unhide forward to application menu when no SIM case
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_unhide_fwd_app_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_WALLPAPER);
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_SUB_WALLPAPER);
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_SCREENSAVER);
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_POWER_ON);
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_POWER_OFF);
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_PHB);
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_BGSOUND);
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_EMS);
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_MMS);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_get_forward_option_menu
 * DESCRIPTION
 *  get forward option menu id for highlighted file
 * PARAMETERS
 *  file_info       [?]     
 *  is_drm          [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U16 fmgr_get_forward_option_menu(FMGR_FILE_INFO_STRUCT *file_info, BOOL *is_drm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 forward = FMGR_DRM_FWD_APP_FWD_OUT;      /* 0: can't forward at all, 
                                                   1: can forward to app, can't forward off device, 
                                                   2: can't forward to app, can forward off device,
                                                   3: can forward to app and off device */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__
    forward = fmgr_get_drm_forward_rule(file_info, is_drm);
    PRINT_INFORMATION("*** fmgr_get_forward_option_menu, rule=%d, is_drm=%d\n", forward, is_drm);
    if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
    {
        return 0;
    }
#else /* __DRM_SUPPORT__ */ 
    if (is_drm != NULL)
    {
        *is_drm = FALSE;
    }
#endif /* __DRM_SUPPORT__ */ 

#if defined(MMS_SUPPORT)
    if (wap_content_is_mms_forward((char*)file_info->file_name) == MMI_FALSE)
    {
        mmi_frm_hide_menu_item(MENU_FMGR_FWD_MMS);
    }
#endif /* MMS_SUPPORT */

    /* no SIM or flight mode can't forward out */
    if (fmgr_is_network_services_available() == MMI_FALSE
#ifdef __FLIGHT_MODE_SUPPORT__
        || mmi_bootup_get_active_flight_mode() != 0
#endif 
        )
    {
        if (forward == FMGR_DRM_FWD_APP_FWD_OUT)
        {
            forward = FMGR_DRM_FWD_APP_NO_FWD_OUT;
        }
        if (forward == FMGR_DRM_NO_FWD_APP_FWD_OUT)
        {
            forward = FMGR_DRM_NO_FWD_APP_NO_FWD_OUT;
        }
    }

    if (FMGR_FILTER_IS_SET_IMAGE(&file_info->file_type))
    {
        /* can forward to wallpaper, screensaver, phonebook...etc. */
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            return 0;
        }
        /* no Idle can only forward to PHB */
        if (!IsScreenPresent(IDLE_SCREEN_ID))
        {
            return MENU_FMGR_FWD_OPTION_VCARD_NO_SIM;
        }
        if (forward == FMGR_DRM_FWD_APP_NO_FWD_OUT)
        {
            return MENU_FMGR_FWD_OPTION_IMG_DRM;
        }
        if (forward == FMGR_DRM_NO_FWD_APP_FWD_OUT)
        {
            return MENU_FMGR_FWD_OPTION_GEN;
        }
        return MENU_FMGR_FWD_OPTION_IMG;
    }
    else if (FMGR_FILTER_IS_SET_AUDIO(&file_info->file_type))
    {
        /* can forward to profile...etc. */
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            return 0;
        }
        if (forward == FMGR_DRM_FWD_APP_NO_FWD_OUT)
        {
            return MENU_FMGR_FWD_OPTION_AUD_NO_SIM;
        }
        if (forward == FMGR_DRM_NO_FWD_APP_FWD_OUT)
        {
            return MENU_FMGR_FWD_OPTION_GEN;
        }
        return MENU_FMGR_FWD_OPTION_AUD;
    }
#ifdef __MMI_VIDEO_PLAYER__
    else if (FMGR_FILTER_IS_SET_VIDEO(&file_info->file_type))
    {
        /* can forward to app */
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            return 0;
        }
        /* no Idle can only forward to PHB */
        if (!IsScreenPresent(IDLE_SCREEN_ID))
        {
            return MENU_FMGR_FWD_OPTION_VID_NO_SIM;
        }
        if (forward == FMGR_DRM_FWD_APP_NO_FWD_OUT)
        {
            return MENU_FMGR_FWD_OPTION_VID_NO_FWD_OUT;
        }
        if (forward == FMGR_DRM_NO_FWD_APP_FWD_OUT)
        {
            return MENU_FMGR_FWD_OPTION_GEN;
        }
        return MENU_FMGR_FWD_OPTION_VID;
    }
#endif /* __MMI_VIDEO_PLAYER__ */ 
#ifdef __MMI_VCALENDAR__
    else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_VCS))
    {
        /* can forward to todolist */
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            return 0;
        }
        if (forward == FMGR_DRM_FWD_APP_NO_FWD_OUT)
        {
            return MENU_FMGR_FWD_OPTION_VCAL_NO_SIM;
        }
        return MENU_FMGR_FWD_OPTION_VCAL;
    }
#endif /* __MMI_VCALENDAR__ */ 
#ifdef __MMI_VCARD__
    else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_VCF))
    {
        /* can forward to phonebook */
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            return 0;
        }
        if (forward == FMGR_DRM_FWD_APP_NO_FWD_OUT)
        {
            return MENU_FMGR_FWD_OPTION_VCARD_NO_SIM;
        }
        return MENU_FMGR_FWD_OPTION_VCARD;
    }
#endif /* __MMI_VCARD__ */ 
#ifdef __MMI_SWFLASH__
    else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_VIS)||
             FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_IVIS)||
             FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_KVIS)||
             FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_MVIS))
    {
        if (fmgr_is_network_services_available() == MMI_FALSE)
        {
            return MENU_FMGR_FWD_OPTION_VID_NO_SIM;
        }
        else
        {
            return MENU_FMGR_FWD_OPTION_MFH;
        }
    }
    else if(FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_CMP))
    {
        /* unrecognized file type, can only forward off device */
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT || forward == FMGR_DRM_FWD_APP_NO_FWD_OUT)
        {
            return 0;
        }

        return MENU_FMGR_FWD_OPTION_GEN;
    }
#endif /* __MMI_SWFLASH__ */ 
    else
    {
        /* unrecognized file type, can only forward off device */
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT || forward == FMGR_DRM_FWD_APP_NO_FWD_OUT)
        {
            return 0;
        }

        return MENU_FMGR_FWD_OPTION_GEN;
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_get_file_option_menu
 * DESCRIPTION
 *  get file option menu id for highlighted file
 * PARAMETERS
 *  file_info       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U16 fmgr_get_file_option_menu(FMGR_FILE_INFO_STRUCT *file_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 forward;
    BOOL is_drm = FALSE;
    MMI_BOOL is_in_mul_odf = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    forward = fmgr_get_forward_option_menu(file_info, &is_drm);

    if ((forward != FMGR_DRM_NO_FWD_APP_NO_FWD_OUT) && (GetNumOfChild_Ext(forward) == 0))
    {
        forward = FMGR_DRM_NO_FWD_APP_NO_FWD_OUT;
    }

    if (forward != FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
    {
        fmgr_check_sub_forward_option(file_info);
        if (GetNumOfChild_Ext(forward) == 0 )
        {
            mmi_frm_hide_menu_item(MENU_FMGR_GEN_OPTION_FORWARD);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_FMGR_GEN_OPTION_FORWARD);
        }
        fmgr_unhide_fwd_app_menu();
    }

    if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
    {
        mmi_frm_hide_menu_item(MENU_FMGR_GEN_OPTION_FORWARD);     
        mmi_frm_hide_menu_item(MENU_FMGR_DA_OPTION_FORWARD);
    }    

#if defined(__DRM_V02__)
    is_in_mul_odf = DRM_is_archive(0, (PU16)fmgr_p->file_path);
#endif

    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_MMS);

    if (FMGR_FILTER_IS_SET_IMAGE(&file_info->file_type))
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            mmi_frm_hide_menu_item(MENU_FMGR_GEN_OPTION_FORWARD);       /* view only */
            mmi_frm_hide_menu_item(MENU_FMGR_DA_OPTION_FORWARD);
        }
        /* else */
        {
        #ifdef __MMI_PHOTOEDITOR__
            if ((is_drm == TRUE) ||
                (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_JPG) == FALSE &&
                 FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_JPEG) == FALSE))
            {
                mmi_frm_hide_menu_item(MENU_FMGR_IMG_OPTION_EDIT);
            }
        #endif /* __MMI_PHOTOEDITOR__ */ 
        #if defined(__MMI_BPP_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__)
            fmgr_prepare_print_option(mmi_fmgr_get_file_type_by_filename(file_info->file_name));
        #endif /* defined(__MMI_BPP_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__) */
        
        #if defined(__MMI_EXIF__)       /* turn off exif until W06.13 */
            if ((FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_JPG) == FALSE &&
                 FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_JPEG) == FALSE))
            {
                mmi_frm_hide_menu_item(MENU_FMGR_GEN_OPTION_JPG_DETAIL);
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_FMGR_GEN_OPTION_JPG_DETAIL);
            }
        #else /* defined(__MMI_EXIF__) */ 
            mmi_frm_hide_menu_item(MENU_FMGR_GEN_OPTION_JPG_DETAIL);
        #endif /* defined(__MMI_EXIF__) */ 
        }
        if (is_in_mul_odf == MMI_TRUE)
        {
            return MITEM_FMGR_MUL_ODF_IMG_TYPE_OPTIONS;
        }
        else
        {
            return MITEM_FMGR_JPG_IMG_TYPE_OPTIONS;
        }
    }
    else if (FMGR_FILTER_IS_SET_AUDIO(&file_info->file_type))
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
        #if defined(__DRM_V02__)
            if (is_in_mul_odf == MMI_TRUE)
            {
                return MITEM_FMGR_MUL_ODF_AUD_TYPE_NO_SIM_OPTIONS;  /* play only */
            }
            else
        #endif /* #if defined(__DRM_V02__) */
            {
                return MITEM_FMGR_AUD_TYPE_NO_FWD_OPTIONS;  /* play only */
            }
        }
        else
        {
        #if defined(__DRM_V02__)
            if (is_in_mul_odf == MMI_TRUE)
            {
                return MITEM_FMGR_MUL_ODF_AUD_TYPE_OPTIONS;
            }
            else
        #endif /* #if defined(__DRM_V02__) */
            {
                return MITEM_FMGR_AUD_TYPE_OPTIONS; /* play + forward */
            }
        }
    }
#ifdef __MMI_VIDEO_PLAYER__
    else if (FMGR_FILTER_IS_SET_VIDEO(&file_info->file_type))
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
        #if defined(__DRM_V02__)
            if (is_in_mul_odf == MMI_TRUE)
            {
                return MITEM_FMGR_MUL_ODF_VID_TYPE_NO_SIM_OPTIONS;  /* play only */
            }
            else
        #endif /* #if defined(__DRM_V02__) */
            {
                return MITEM_FMGR_VID_TYPE_NO_SIM_OPTIONS;  /* play only */
            }
        }
        else
        {
        #if defined(__DRM_V02__)
            if (is_in_mul_odf == MMI_TRUE)
            {
                return MITEM_FMGR_MUL_ODF_VID_TYPE_OPTIONS;
            }
            else
        #endif /* #if defined(__DRM_V02__) */
            {
                return MITEM_FMGR_VID_TYPE_OPTIONS; /* play + forward */
            }
        }
    }
#ifdef __MMI_VIDEO_STREAM__
    else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_SDP) ||
             FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_RAM))
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            return MITEM_FMGR_VID_TYPE_NO_SIM_OPTIONS;  /* play only */
        }
        else
        {
            return MITEM_FMGR_VID_TYPE_OPTIONS; /* play + forward */
        }
    }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAYER__ */ 
#if (defined ( __J2ME__ ) && !defined (__MMI_FMGR_DISABLE_JAVA_INSTALL__))
    else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_JAD) ||
             FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_JAR))
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            if (is_in_mul_odf == MMI_TRUE)
            {
                return MITEM_FMGR_MUL_ODF_EXE_TYPE_NO_SIM_OPTIONS;
            }
            else
            {
                return MITEM_FMGR_EXE_TYPE_NO_SIM_OPTIONS;  /* exe only */
            }
        }
        else
        {
            if (is_in_mul_odf == MMI_TRUE)
            {
                return MITEM_FMGR_MUL_ODF_EXE_TYPE_OPTIONS;
            }
            else
            {
                return MITEM_FMGR_EXE_TYPE_OPTIONS; /* exe + forward */
            }
        }
    }
#endif /* (defined ( __J2ME__ ) && !defined (__MMI_FMGR_DISABLE_JAVA_INSTALL__)) */ 
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_THEME))
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            if (is_in_mul_odf == MMI_TRUE)
            {
                return MITEM_FMGR_MUL_ODF_THM_TYPE_NO_SIM_OPTIONS;
            }
            else
            {
                return MITEM_FMGR_THEME_TYPE_OPTIONS;   /* view only */
            }
        }
        else
        {
            if (is_in_mul_odf == MMI_TRUE)
            {
                return MITEM_FMGR_MUL_ODF_THM_TYPE_OPTIONS;
            }
            else
            {
                return MITEM_FMGR_THEME_TYPE_OPTIONS;   /* view + forward */
            }
        }
    }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
#ifdef __MMI_BARCODEREADER__
    else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_MBC))
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            return MENU_ID_BARCODEREADER_FILE_OPTION_NO_SIM;/* view only */
        }
        else
        {
            return MENU_ID_BARCODEREADER_FILE_OPTION;   /* view + forward */
        }
    }
#endif
#ifdef __MMI_EBOOK_READER__
    else if ((FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_EBOOK_TXT)) ||
        (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_EBOOK_PDB)))
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            if (is_in_mul_odf == MMI_TRUE)
            {
                return MITEM_FMGR_MUL_ODF_EBK_TYPE_NO_SIM_OPTIONS;
	    }
	    else
	    {
                return MITEM_FMGR_EBOOK_NO_FWD_TYPE_OPTIONS;  /* no forward */
            }
        }
        else
	{
            if (is_in_mul_odf == MMI_TRUE)
            {
                return MITEM_FMGR_MUL_ODF_EBK_TYPE_OPTIONS;
            }
            else
            {
                return MITEM_FMGR_EBOOK_TYPE_OPTIONS;   /* view + forward */
            }
        }
    }
#endif /* __MMI_EBOOK_READER__ */ 
#if defined(__MMI_BROWSER_2__)
    else if ((FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_WML)) ||
        (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_HTML)) ||
        (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_HTM))  ||
        (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_XHTML)))
    {
        if ((fmgr_is_network_services_available() == MMI_FALSE) ||
            (mmi_bootup_get_active_flight_mode()==MMI_TRUE) )
        {
            mmi_frm_hide_menu_item(MENU_FMGR_BOOKMARK_FILE_OPEN);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_FMGR_BOOKMARK_FILE_OPEN);
        }
	if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
			return MENU_FMGR_BOOKMARK_FILE_TYPE_NO_SIM_OPTIONS;  /* no forward */
		}
		else
		{
            return MENU_FMGR_BOOKMARK_FILE_TYPE_OPTIONS;   /* view + forward */
        }
    }
#endif
#ifdef __MMI_SWFLASH__
   else if ((FMGR_FILTER_IS_SET(&file_info->file_type,FMGR_TYPE_CMP))
	        ||(FMGR_FILTER_IS_SET(&file_info->file_type,FMGR_TYPE_VIS))
			 ||(FMGR_FILTER_IS_SET(&file_info->file_type,FMGR_TYPE_ZDD))
			 ||(FMGR_FILTER_IS_SET(&file_info->file_type,FMGR_TYPE_IVIS))
			 ||(FMGR_FILTER_IS_SET(&file_info->file_type,FMGR_TYPE_KVIS))
			 ||(FMGR_FILTER_IS_SET(&file_info->file_type,FMGR_TYPE_MVIS)))
   {
        FMGR_FILE_INFO_STRUCT file_info;
        S8 full_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH + ENCODING_LENGTH]; 
        
        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
	    mmi_ucs2cpy(full_path,fmgr_p->file_path); 
        mmi_ucs2cat(full_path, (PS8) file_info.file_name);
        
      	if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
	    return mmi_swflash_get_menuId(full_path,&file_info,MMI_FALSE,fmgr_p->src_application);  /* no forward, */
	}
	else
	{
            return mmi_swflash_get_menuId(full_path,&file_info,MMI_TRUE,fmgr_p->src_application);  /* view + forward */
	}
   }
#endif /* __MMI_SWFLASH__ */
#ifdef __MMI_VBOOKMARK__
    else if ((FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_URL)) ||
        (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_VBM)))
    {
        if ((fmgr_is_network_services_available() == MMI_FALSE) ||
            (mmi_bootup_get_active_flight_mode()==MMI_TRUE) )
        {
            mmi_frm_hide_menu_item(MENU_FMGR_VBOOKMARK_OPTION_GOTO);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_FMGR_VBOOKMARK_OPTION_GOTO);
        }
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
			return MENU_FMGR_VBOOKMARK_NO_FWD_TYPE_OPTIONS;  /* no forward */
		}
		else
		{
            return MENU_FMGR_VBOOKMARK_TYPE_OPTIONS;   /* view + forward */
        }
    }
#endif /* #ifdef __MMI_VBOOKMARK__ */
#ifdef __MMI_VCARD__
    else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_VCF))
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            if (is_in_mul_odf == MMI_TRUE)
            {
                return MITEM_FMGR_MUL_ODF_GEN_TYPE_OPTIONS;  
            }
            else
            {
                return MITEM_FMGR_GEN_TYPE_NO_SIM_OPTIONS;  /* no forward */
            }
        }
        else
        {
            if (is_in_mul_odf == MMI_TRUE)
            {
                return MITEM_FMGR_MUL_ODF_GEN_TYPE_OPTIONS; 
            }
            else
            {
                return MITEM_FMGR_GEN_TYPE_OPTIONS; /* forward only */
            }
        }
    }
#endif /* __MMI_VCARD__ */
#if defined(__DRM_V02__)
    else if ((FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_ODF)) &&
             (!FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_UNKNOW)))
    {
	if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            return MENU_FMGR_DRM_ODF_NO_FWD_TYPE_OPTIONS;  /* no forward */
	}
	else
	{
            return MENU_FMGR_DRM_ODF_TYPE_OPTIONS;   /* view + forward */
        }
    }
#endif /* defined(__DRM_V02__) */
    else
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            if (is_in_mul_odf == MMI_TRUE)
            {
                return MITEM_FMGR_MUL_ODF_GEN_TYPE_OPTIONS;  
            }
            else
            {
                return MITEM_FMGR_GEN_TYPE_NO_SIM_OPTIONS;  /* no forward */
            }
        }
        else
        {
            if (is_in_mul_odf == MMI_TRUE)
            {
                return MITEM_FMGR_MUL_ODF_GEN_TYPE_OPTIONS; 
            }
            else
            {
                return MITEM_FMGR_GEN_TYPE_OPTIONS; /* forward only */
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_get_app_file_option_menu
 * DESCRIPTION
 *  get file option menu id for highlighted file
 * PARAMETERS
 *  file_info       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U16 fmgr_get_app_file_option_menu(FMGR_FILE_INFO_STRUCT *file_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 forward;
    BOOL is_drm = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    forward = fmgr_get_forward_option_menu(file_info, &is_drm);

    if ((forward != FMGR_DRM_NO_FWD_APP_NO_FWD_OUT) && (GetNumOfChild_Ext(forward) == 0))
    {
        forward = FMGR_DRM_NO_FWD_APP_NO_FWD_OUT;
    }

    if (forward != FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
    {
        fmgr_check_sub_forward_option(file_info);
        if (GetNumOfChild_Ext(forward) == 0 )
        {
            mmi_frm_hide_menu_item(MENU_FMGR_GEN_OPTION_FORWARD);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_FMGR_GEN_OPTION_FORWARD);
        }
        fmgr_unhide_fwd_app_menu();
    }
    
    mmi_frm_unhide_menu_item(MENU_FMGR_FWD_MMS);

#if defined(__MMI_BPP_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__)
    fmgr_prepare_print_option(mmi_fmgr_get_file_type_by_filename(file_info->file_name));
#endif

    if (FMGR_FILTER_IS_SET_IMAGE(&file_info->file_type))
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            return MITEM_FMGR_DRM_IMG_TYPE_OPTIONS; /* view only */
        }
        else
        {
            return MITEM_FMGR_APP_IMG_TYPE_OPTIONS; /* view + forward */
        }
    }
    else if (FMGR_FILTER_IS_SET_AUDIO(&file_info->file_type))
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            return MITEM_FMGR_DRM_AUD_TYPE_OPTIONS; /* play only */
        }
        else
        {
            return MITEM_FMGR_APP_AUD_TYPE_OPTIONS; /* play + forward */
        }
    }
#ifdef __MMI_VIDEO_PLAYER__
    else if (FMGR_FILTER_IS_SET_VIDEO(&file_info->file_type))
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            return MITEM_FMGR_DRM_VID_TYPE_OPTIONS; /* play only */
        }
        else
        {
            return MITEM_FMGR_APP_VID_TYPE_OPTIONS; /* play + forward */
        }
    }
#ifdef __MMI_VIDEO_STREAM__
    else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_RAM) || 
             FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_SDP))
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            return MITEM_FMGR_DRM_VID_TYPE_OPTIONS; /* play only */
        }
        else
        {
            return MITEM_FMGR_APP_VID_TYPE_OPTIONS; /* play + forward */
        }
    }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAYER__ */ 
#if (defined ( __J2ME__ ) && !defined (__MMI_FMGR_DISABLE_JAVA_INSTALL__))
    else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_JAD) ||
             FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_JAR))
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            return MITEM_FMGR_DRM_EXE_TYPE_OPTIONS; /* exe only */
        }
        else
        {
            return MITEM_FMGR_APP_EXE_TYPE_OPTIONS; /* exe + forward */
        }
    }
#endif /* (defined ( __J2ME__ ) && !defined (__MMI_FMGR_DISABLE_JAVA_INSTALL__)) */ 
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_THEME))
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            return MITEM_FMGR_APP_THEME_TYPE_OPTIONS;   /* view only */
        }
        else
        {
            return MITEM_FMGR_APP_THEME_TYPE_OPTIONS;   /* view + forward */
        }
    }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
#ifdef __MMI_BARCODEREADER__
    else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_MBC))
    {
#ifndef __MMI_BARCODEREADER_OPERATOR1__
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            return MENU_ID_BARCODEREADER_FILE_OPTION_NO_SIM;/* view only */
        }
        else
        {
            return MENU_ID_BARCODEREADER_FILE_OPTION;   /* view + forward */
        }
#else
        return MENU_ID_BARCODEREADER_FILE_LIST;
#endif
    }
#endif
#ifdef __MMI_EBOOK_READER__
    else if ((FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_EBOOK_TXT)) ||
        (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_EBOOK_PDB)))
    {
		if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
			return MITEM_FMGR_APP_EBOOK_NO_FWD_TYPE_OPTIONS;  /* no forward */
		}
		else
		{
            return MITEM_FMGR_APP_EBOOK_TYPE_OPTIONS;   /* view + forward */
        }
    }
#endif /* __MMI_EBOOK_READER__ */ 
#ifdef __MMI_SWFLASH__
	else if ((FMGR_FILTER_IS_SET(&file_info->file_type,FMGR_TYPE_CMP))
		||(FMGR_FILTER_IS_SET(&file_info->file_type,FMGR_TYPE_VIS))
		||(FMGR_FILTER_IS_SET(&file_info->file_type,FMGR_TYPE_ZDD))
		||(FMGR_FILTER_IS_SET(&file_info->file_type,FMGR_TYPE_IVIS))
		||(FMGR_FILTER_IS_SET(&file_info->file_type,FMGR_TYPE_KVIS))
		||(FMGR_FILTER_IS_SET(&file_info->file_type,FMGR_TYPE_MVIS)))
	{
            FMGR_FILE_INFO_STRUCT file_info;
            S8 full_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH + ENCODING_LENGTH]; 
        
            mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
   	    mmi_ucs2cpy(full_path,fmgr_p->file_path); 
            mmi_ucs2cat(full_path, (PS8) file_info.file_name);
        
	    if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
            {
	        return mmi_swflash_get_menuId(full_path,&file_info,MMI_FALSE,fmgr_p->src_application);  /* no forward, */
    	    }
	    else
	    {
	        return mmi_swflash_get_menuId(full_path,&file_info,MMI_TRUE,fmgr_p->src_application);  /* view + forward */
            }
	}
#endif
    else
    {
        if (forward == FMGR_DRM_NO_FWD_APP_NO_FWD_OUT)
        {
            return MITEM_FMGR_DRM_GEN_TYPE_OPTIONS; /* no forward */
        }
        else
        {
            return MITEM_FMGR_APP_TYPE_OPTIONS; /* forward only */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_view_image_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_view_image_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    U16 iconId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOAD_AGENT__
    /* download agent file */
    if (fmgr_is_da_file())
    {
        FS_HANDLE handle;

        /* Check if file exists or not */
        handle = FS_Open((PU16) fmgr_p->da_file_path, FS_READ_ONLY);
        if (handle > FS_NO_ERROR)
        {
        	FS_Close(handle);
        }
        else
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION);
            return;
        }
        
        mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->da_file_path);

    #if defined(__DRM_V02__)        
        {
            S32 file_type = 0;

        file_type = mmi_fmgr_get_drm_file_type_by_path((PS8) fmgr_p->file_path, &file_info.file_type);
            
        if (file_type == FMGR_TYPE_ODF)
        {
            /* multi part ODF */
            mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
    
            if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
        #ifndef __MMI_SHOW_FILE_EXT__
                || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
        #endif 
                )
                return;
        }
        }
    #else
        mmi_fmgr_get_file_type((PS8) fmgr_p->da_file_path, &file_info.file_type);
    #endif

        file_info.is_short = FALSE;
    }
    /* non download agent file */
    else
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
    {
        if (fmgr_check_file_present() < FMGR_NO_ERROR)
        {
            return;
        }

        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

        if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
    #ifndef __MMI_SHOW_FILE_EXT__
            || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
    #endif 
            )
            return;
    }


#ifdef __DRM_SUPPORT__
    {
        S32 result;

        result = fmgr_check_drm_rights(NULL, DRM_PERMISSION_DISPLAY);
        if (result == FMGR_DRM_NO_PERMISSION)
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
            DeleteScreenIfPresent(SCR_ID_FMGR_VIEW_IMAGE);
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            return;
        }
        else if (result == FMGR_DRM_REQUEST_RIGHTS)
        {
            entry_fmgr_request_rights_confirm();
            DeleteScreenIfPresent(SCR_ID_FMGR_VIEW_IMAGE);
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            return;
        }
        else if (result < 0 )
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(result)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_ID_FMGR_VIEW_IMAGE);
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            return;
        }
    }
#endif /* __DRM_SUPPORT__ */ 

    iconId = fmgr_get_app_title_icon_id();
    mmi_imgview_view_image_hdlr(fmgr_p->file_path,file_info.is_short,file_info.file_type, iconId);

    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_edit_image_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_edit_image_hdlr(void)
{
#ifdef __MMI_PHOTOEDITOR__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_check_file_present() < FMGR_NO_ERROR)
    {
        return;
    }

    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

    if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
#ifndef __MMI_SHOW_FILE_EXT__
        || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
#endif 
        )
        return;

    /* hook to photo art application */
    mmi_phoart_entry_from_fmgr(fmgr_p->file_path, file_info.is_short);

    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
#endif /* __MMI_PHOTOEDITOR__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_play_audio_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_play_audio_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL silent, preview = TRUE;
    U16 scrId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SILENT_MEETING_PROFILE__
    silent = IsSilentModeActivated() || IsMeetingModeActivated();
#else 
    silent = IsSilentModeActivated();
#endif 

    scrId = GetExitScrnID();
    if (scrId == SCR_FMGR_FILE_OPTION || scrId == SCR_FMGR_APP_FILE_OPTION || scrId == SCR_FMGR_DA_FILE_OPTION)
    {
        preview = FALSE;
    }

#ifdef __MMI_DOWNLOAD_AGENT__
    /* download agent file */
    if (fmgr_is_da_file())
    {
        FS_HANDLE handle;
        FMGR_FILE_INFO_STRUCT file_info;

        /* Check if file exists or not */
        handle = FS_Open((PU16) fmgr_p->da_file_path, FS_READ_ONLY);
        if (handle > FS_NO_ERROR)
        {
        	FS_Close(handle);
        }
        else
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION);
            return;
        }
        
        mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->da_file_path);

    #if defined(__DRM_V02__)        
        {
            S32 file_type = 0;

        file_type = mmi_fmgr_get_drm_file_type_by_path((PS8) fmgr_p->file_path, &file_info.file_type);
            
        if (file_type == FMGR_TYPE_ODF)
        {
            /* multi part ODF */
            mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
    
            if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
        #ifndef __MMI_SHOW_FILE_EXT__
                || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
        #endif 
                )
                return;
        }
        }
    #else
        mmi_fmgr_get_file_type((PS8) fmgr_p->da_file_path, &file_info.file_type);
    #endif /* defined(__DRM_V02__)  */

        file_info.is_short = FALSE;
    }
    /* non download agent file */
    else
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
    {
        FMGR_FILE_INFO_STRUCT file_info;

        if (fmgr_check_file_present() < FMGR_NO_ERROR)
        {
            return;
        }

        /* pass file name to audio player
           hook audio player func */
        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
        if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
    #ifndef __MMI_SHOW_FILE_EXT__
            || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
    #endif 
            )
            return;
    }

#ifdef __DRM_SUPPORT__
    if (!(preview && silent))
    {
        S32 result;

        result = fmgr_check_drm_rights(NULL, DRM_PERMISSION_PLAY);
        if (result == FMGR_DRM_NO_PERMISSION)
        {
            if ((fmgr_p->src_application != APP_FILEMANAGER) && (preview))
            { 
                mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
                return;
            }
            DisplayPopup((PU8) GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            return;
        }
        else if (result == FMGR_DRM_REQUEST_RIGHTS)
        {
            if ((fmgr_p->src_application != APP_FILEMANAGER) && (preview))
            { 
                mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
                return;
            }
            entry_fmgr_request_rights_confirm();
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            return;
        }
        else if (result < 0 )
        {
            if ((fmgr_p->src_application != APP_FILEMANAGER) && (preview))
            { 
                mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
                return;
            }
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(result)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            return;
        }
    }
#endif /* __DRM_SUPPORT__ */ 

    if (!preview)
    {
        mmi_audply_single_play((PU16) fmgr_p->file_path, NULL);
    }
    else if (!silent)
    {
        fmgr_p->audio_state = TRUE;
    #ifndef __MMI_AUDIO_PLAYER__
        mdi_audio_play_file((PU16) fmgr_p->file_path, DEVICE_AUDIO_PLAY_INFINITE, NULL, NULL);
    #else /* __MMI_AUDIO_PLAYER__ */ 
        mdi_audio_play_file_with_vol_path(
            (PU16) fmgr_p->file_path,
            DEVICE_AUDIO_PLAY_INFINITE,
            NULL,
            NULL,
            GetRingVolumeLevel(),
            MDI_DEVICE_SPEAKER2);
    #endif /* __MMI_AUDIO_PLAYER__ */ 
    }
    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_play_video_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_play_video_hdlr(void)
{
#ifdef __MMI_VIDEO_PLAYER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__
    S32 result;
#endif
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOAD_AGENT__
    /* download agent file */
    if (fmgr_is_da_file())
    {
        FS_HANDLE handle;

        /* Check if file exists or not */
        handle = FS_Open((PU16) fmgr_p->da_file_path, FS_READ_ONLY);
        if (handle > FS_NO_ERROR)
        {
        	FS_Close(handle);
        }
        else
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION);
            return;
        }
        
        mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->da_file_path);

     #if defined(__DRM_V02__)        
        {
            S32 file_type = 0;

        file_type = mmi_fmgr_get_drm_file_type_by_path((PS8) fmgr_p->file_path, &file_info.file_type);
            
        if (file_type == FMGR_TYPE_ODF)
        {
            /* multi part ODF */
            mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
    
            if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
        #ifndef __MMI_SHOW_FILE_EXT__
                || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
        #endif 
                )
                return;
        }
         }
     #else
        mmi_fmgr_get_file_type((PS8) fmgr_p->da_file_path, &file_info.file_type);
     #endif /* defined(__DRM_V02__) */
 
        file_info.is_short = FALSE;
    }
    /* non download agent file */
    else
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
    {
        if (fmgr_check_file_present() < FMGR_NO_ERROR)
        {
            return;
        }

        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
        if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
    #ifndef __MMI_SHOW_FILE_EXT__
            || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
    #endif 
            )
            return;
    }

#ifdef __DRM_SUPPORT__
    result = fmgr_check_drm_rights(NULL, DRM_PERMISSION_PLAY);
    if (result == FMGR_DRM_NO_PERMISSION)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
        return;
    }
    else if (result == FMGR_DRM_REQUEST_RIGHTS)
    {
        entry_fmgr_request_rights_confirm();
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
        return;
    }
    else if (result < 0)
    {
        DisplayPopup((PU8) GetString(GetFileSystemErrorString(result)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
        return;
    }
#endif /* __DRM_SUPPORT__ */ 

    /* compare extension */
#ifdef __MMI_VIDEO_STREAM__  
    if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_SDP))
    {
        mmi_vdoply_entry_player_screen_from_sdp_file((PS8)fmgr_p->file_path, file_info.is_short); 
    }
    else if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_RAM))
    {
        mmi_vdoply_entry_player_screen_from_ram_file((PS8)fmgr_p->file_path, file_info.is_short);        
    }
    else
    {
        /* other video type */
        mmi_vdoply_entry_player_screen_from_file((PS8)fmgr_p->file_path, file_info.is_short);
    }
#else /* __MMI_VIDEO_STREAM__ */  
    mmi_vdoply_entry_player_screen_from_file((PS8)fmgr_p->file_path, file_info.is_short);
#endif /* __MMI_VIDEO_STREAM__ */  
    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
#endif /* __MMI_VIDEO_PLAYER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_execute_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_execute_hdlr(void)
{
#ifdef __J2ME__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_check_file_present() < FMGR_NO_ERROR)
    {
        return;
    }

    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
    if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
#ifndef __MMI_SHOW_FILE_EXT__
        || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
#endif 
        )
        return;

#ifdef __DRM_SUPPORT__
    {
        S32 result;

        result = fmgr_check_drm_rights(NULL, DRM_PERMISSION_EXECUTE);
        if (result == FMGR_DRM_NO_PERMISSION)
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            return;
        }
        else if (result == FMGR_DRM_REQUEST_RIGHTS)
        {
            entry_fmgr_request_rights_confirm();
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            return;
        }
        else if (result < 0)
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(result)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            return;            
        }
    }
#endif /* __DRM_SUPPORT__ */ 

    mmi_java_local_install_content_routing((kal_uint8*) fmgr_p->file_path);
    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    /* pass file name to java
       hook java func */
#endif /* __J2ME__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_drive_action_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_drive_action_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = fmgr_get_drive_index(fmgr_p->cur_index);

    switch (fmgr_p->drive_action)
    {
        case FMGR_ACTION_FORMAT:

        #if defined(__MMI_BPP_SUPPORT__)
            if (mmi_bt_bpp_can_format_drive((PS8)fmgr_p->file_path) == MMI_FALSE)
            {
                DisplayPopup((PU8)GetString(FMGR_FS_ACCESS_DENIED_TEXT),
                         IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
                return;
            }
        #endif /* #if defined(__MMI_BPP_SUPPORT__) */

        #ifdef __MMI_THEMES_V2_SUPPORT__
            mmi_thm_activate_dflt_sys_theme();
        #endif /* __MMI_THEMES_V2_SUPPORT__ */


        #ifdef __MMI_AUDIO_PLAYER__
            mdi_audio_suspend_background_play();
        #endif
            fmgr_send_format_req((U8) fmgr_p->drv_list[index][0], FS_FORMAT_HIGH, (PsFuncPtr) fmgr_drive_rsp_hdlr);
            break;
        case FMGR_ACTION_CHECK_DRIVE:
            fmgr_send_check_drive_req((U8) fmgr_p->drv_list[index][0], (PsFuncPtr) fmgr_drive_rsp_hdlr);
            break;
        case FMGR_ACTION_UNMOUNT:
            fmgr_send_unmount_req((U8) fmgr_p->drv_list[index][0], FS_NONBLOCK_MODE, (PsFuncPtr) fmgr_drive_rsp_hdlr);
            break;
        default:
            return;
    }
    
    /* Set fmgr is busy flag */
    fmgr_p->is_fmgr_busy = MMI_TRUE;    
    
    entry_fmgr_drive_animation();
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_copy_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_copy_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_COPY;
    fmgr_aux_copy_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_move_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->tree_action = FMGR_ACTION_MOVE;
    fmgr_aux_copy_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_aux_copy_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_aux_copy_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    S32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_check_file_present() < FMGR_NO_ERROR)
    {
        fmgr_p->enter_folder = FALSE;
        FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
        fmgr_p->tree_action = FMGR_ACTION_NONE;
        return;
    }

    /* copy file */
    /* set default copy path */
    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

    mmi_ucs2cat((PS8) fmgr_p->file_path, (PS8) file_info.file_name);
#ifndef __MMI_SHOW_FILE_EXT__
    mmi_ucs2cat((PS8) fmgr_p->file_path, (PS8) file_info.file_ext);
#endif 

    #ifdef __MMI_AUDIO_PLAYER__
        if (mmi_audply_can_delete_file((PS8)fmgr_p->file_path) == MMI_FALSE)
        {
            DisplayPopup((PU8)GetString(FMGR_FS_ACCESS_DENIED_TEXT),
                          IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            mmi_fmgr_remove_last_dir((PS8)fmgr_p->file_path);
            fmgr_p->tree_action = FMGR_ACTION_NONE;
            return;
        }
    #endif /* __MMI_AUDIO_PLAYER__ */

    mmi_ucs2cpy((PS8) fmgr_p->old_file_path, (PS8) fmgr_p->file_path);

    /* short file name src file should be renamed to long file name */
#if 0
#ifdef MMI_ON_HARDWARE_P
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* if 0 */
/* under construction !*/
#endif /* MMI_ON_HARDWARE_P */ 
#endif /* if 0 */

    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);

    while (mmi_ucs2strlen((PS8) fmgr_p->file_path) >= 3)
    {
        count = FS_Count((PU16) fmgr_p->file_path, FS_DIR_TYPE | FS_FILTER_SYSTEM_ATTR | FS_FILTER_HIDDEN_ATTR, NULL, 0);
        if (count < 0)
        {
            mmi_ucs2_to_asc((PS8) nPrintableStr, (PS8) fmgr_p->file_path);
            PRINT_INFORMATION("copy fail: %s", nPrintableStr);

            DisplayPopup((PU8) GetString(GetFileSystemErrorString(count)), IMG_GLOBAL_EMPTY, 0, 1000, ERROR_TONE);
            return;
        }
        else if (count == 0)
        {
            if (mmi_ucs2strlen((PS8) fmgr_p->file_path) == 3)
            {
                /* no folder under drive */
      		fmgr_p->cur_index = 0;
                entry_fmgr_main();
                return;
            }
            else
            {
                mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            }
        }
        else
        {
      	/* select dest folder from the first */
      	fmgr_p->cur_index = 0;
            break;
        }
    }
    entry_fmgr_tree_explorer();
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_abort_copy_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_abort_copy_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->enter_folder = FALSE;
    FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
    fmgr_p->tree_action = FMGR_ACTION_NONE;
    mmi_fmgr_remove_last_dir((PS8) fmgr_p->old_file_path);
    mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->old_file_path);
    GoBackToHistory(SCR_FMGR_EXPLORER);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_set_curr_path_and_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_set_curr_path_and_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

    if (mmi_ucs2cmp((PS8) file_info.file_name, (PS8) L".") == 0)
    {
        return;
    }

    if (mmi_ucs2cmp((PS8) file_info.file_name, (PS8) L"..") == 0)
    {
        fmgr_back_to_parent();
        return;
    }

    if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE ||
        mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) L"\\") == FALSE)
    {
        return;
    }

    if ((fmgr_p->src_application != APP_FILEMANAGER) &&
        (fmgr_p->sel_type == FMGR_SELECT_FOLDER) &&
        (FS_Count((PU16) fmgr_p->file_path, FS_DIR_TYPE | FS_FILTER_SYSTEM_ATTR | FS_FILTER_HIDDEN_ATTR, NULL, 0)) == 0)
    {
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);

        DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 0, 1000, EMPTY_LIST_TONE);
        DeleteUptoScrID(SCR_FMGR_EXPLORER);
        return;
    }

    if (mmi_ucs2strlen((PS8) fmgr_p->file_path) + 3 >= FMGR_MAX_PATH_LEN)
    {
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
        DisplayPopup((PU8) GetString(FMGR_FS_PATH_OVER_LEN_ERROR_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteUptoScrID(SCR_FMGR_EXPLORER);
        return;
    }
    fmgr_p->enter_folder = TRUE;

#if 0
#if defined(MT6223P)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MT6223P */
#endif /* if 0 */

    entry_fmgr_explorer();
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_back_to_parent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_back_to_parent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 ptr;
#ifdef __MMI_MY_FAVORITE__
    S8 my_favorite_path[30];
    S8 drv[4];
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((PS8) fmgr_p->file_path) <= 3)
    {
    #ifdef __MMI_MY_FAVORITE__
        if (fmgr_p->src_application == APP_MYFAVORITE)
        {
            /* check path = root, should go back to my favorite main screen */
            DeleteScreenIfPresent(SCR_FMGR_EXPLORER);
            memset(fmgr_p->parent_name, 0, sizeof(fmgr_p->parent_name));
            mmi_my_favorite_back_to_main();
            return;
        }
    #endif

        if (IsScreenPresent(SCR_FMGR_MAIN))
        {
            GoBackToHistory(SCR_FMGR_MAIN);
        }
        else
        {
            entry_fmgr_main();
        }
        return;
    }

    /* remove last level of folder, find last back slash character in the path string */
    fmgr_p->enter_folder = TRUE;
    ptr = mmi_fmgr_extract_file_name((PS8) fmgr_p->file_path);
    if (ptr != NULL)
    {
        S32 end;

        end = mmi_ucs2strlen(ptr) - 1;
        if (ptr[end << 1] == '\\' && ptr[(end << 1) + 1] == 0)
        {
            ptr[end << 1] = 0;
        }
        mmi_ucs2cpy((PS8) fmgr_p->parent_name, ptr);
        ptr[0] = 0;
        ptr[1] = 0;
    }
    else
    {
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    }

#ifdef __MMI_MY_FAVORITE__
    if (fmgr_p->src_application == APP_MYFAVORITE)
    {
        /* check path = root, should go back to my favorite main screen */
        
        sprintf(drv, "%c:\\", (S8) MMI_PUBLIC_DRV);
        mmi_asc_to_ucs2((S8*) my_favorite_path, drv);

        if (!mmi_ucs2cmp((PS8) fmgr_p->file_path,(const PS8) my_favorite_path))
        {
            DeleteScreenIfPresent(SCR_FMGR_EXPLORER);
            memset(fmgr_p->parent_name, 0, sizeof(fmgr_p->parent_name));
            mmi_my_favorite_back_to_main();
            return;
        }
    }
#endif
    if (IsScreenPresent(SCR_FMGR_EXPLORER))
    {
        GoBackToHistory(SCR_FMGR_EXPLORER);
    }
    else
    {
        entry_fmgr_explorer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_set_curr_tree_and_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_set_curr_tree_and_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetExitScrnID() != SCR_FMGR_TREE_DRIVE_OPTION &&
    	GetExitScrnID() != SCR_FMGR_MAIN)
    {
        FMGR_FILE_INFO_STRUCT file_info;

        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

        if (mmi_ucs2cmp((PS8) file_info.file_name, (PS8) L".") == 0)
        {
            return;
        }

        if (mmi_ucs2cmp((PS8) file_info.file_name, (PS8) L"..") == 0)
        {
            fmgr_back_to_tree_parent();
            return;
        }

        if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE ||
            mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) L"\\") == FALSE)
        {
            mmi_ucs2cpy((S8*) fmgr_p->file_path, (S8*) fmgr_p->old_file_path);
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
            fmgr_p->tree_action = FMGR_ACTION_NONE;
            fmgr_p->enter_folder = FALSE;
            DeleteUptoScrID(SCR_FMGR_EXPLORER);
            return;
        }

        if (FS_Count((PU16) fmgr_p->file_path, FS_DIR_TYPE | FS_FILTER_SYSTEM_ATTR, NULL, 0) == 0)
        {
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 0, 1000, EMPTY_LIST_TONE);
            DeleteUptoScrID(SCR_FMGR_TREE_EXPLORER);
            return;
        }

        if (mmi_ucs2strlen((PS8) fmgr_p->file_path) + 3 > FMGR_MAX_PATH_LEN)
        {
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            DisplayPopup((PU8) GetString(FMGR_FS_PATH_OVER_LEN_ERROR_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteUptoScrID(SCR_FMGR_TREE_EXPLORER);
            return;
        }
    }

    fmgr_p->enter_folder = TRUE;
    entry_fmgr_tree_explorer();
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_back_to_tree_parent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_back_to_tree_parent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((PS8) fmgr_p->file_path) <= 3)
    {
        DeleteUptoScrID(SCR_FMGR_EXPLORER);
        entry_fmgr_main();
        return;
    }

    fmgr_p->enter_folder = TRUE;
    ptr = mmi_fmgr_extract_file_name((PS8) fmgr_p->file_path);
    if (ptr != NULL)
    {
        S32 end;

        end = mmi_ucs2strlen(ptr) - 1;
        if (ptr[end << 1] == '\\' && ptr[(end << 1) + 1] == 0)
        {
            ptr[end << 1] = 0;
        }
        mmi_ucs2cpy((PS8) fmgr_p->parent_name, ptr);
        ptr[0] = 0;
        ptr[1] = 0;
    }
    else
    {
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    }

    if (IsScreenPresent(SCR_FMGR_TREE_EXPLORER))
    {
        GoBackToHistory(SCR_FMGR_TREE_EXPLORER);
    }
    else
    {
        entry_fmgr_tree_explorer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_create_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_create_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    S32 fs_ret, len;
    S8 *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = mmi_fmgr_skip_space((PS8) fmgr_p->new_file_name);
    len = mmi_ucs2strlen(ptr);

    if (len == 0 || ptr[0] == '.')
    {
        if (ptr[0] == '.')
        {
            DisplayPopup((PU8) GetString(FMGR_FS_INVALID_FILENAME_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_FMGR_EMPTY_FILENAME), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        }
        DeleteScreenIfPresent(SCR_FMGR_FILENAME_EDITOR);
        DeleteScreenIfPresent(SCR_FMGR_EDITOR_OPTION);
        return;
    }

    if ( !mmi_fmgr_is_filename_valid( (S8*)fmgr_p->new_file_name ))
    {
        DisplayPopup((PU8) GetString(FMGR_FS_INVALID_FILENAME_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteScreenIfPresent(SCR_FMGR_FILENAME_EDITOR);
        DeleteScreenIfPresent(SCR_FMGR_EDITOR_OPTION);
        return;
    }

    /* new file name can't contain '/' or '\' */
    while (len > 0)
    {
        len--;
        if ((ptr[len << 1] == '/' && ptr[(len << 1) + 1] == 0) || (ptr[len << 1] == '\\' && ptr[(len << 1) + 1] == 0))
        {
            DisplayPopup((PU8) GetString(FMGR_FS_INVALID_FILENAME_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_FILENAME_EDITOR);
            DeleteScreenIfPresent(SCR_FMGR_EDITOR_OPTION);
            return;
        }
    }

    if (IsScreenPresent(SCR_FMGR_FOLDER_OPTION) || IsScreenPresent(SCR_FMGR_APP_FOLDER_OPTION)
        || (IsScreenPresent(SCR_FMGR_TREE_OPTION) && IsScreenPresent(SCR_FMGR_EXPLORER)))
    {
        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

        if (fmgr_check_file_present() < FMGR_NO_ERROR)
        {
            return;
        }

        /* create folder under drive no need to append current folder name */
        if (!(file_info.file_name[0] == 0 && file_info.file_name[1] == 0) &&
            (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE ||
             mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) L"\\") == FALSE))
        {
            DeleteScreenIfPresent(SCR_FMGR_EDITOR_OPTION);
            return;
        }
    }

    if (mmi_ucs2strlen((PS8) fmgr_p->file_path) + mmi_ucs2strlen(ptr) + 1 >= FMGR_MAX_PATH_LEN - 11)
    {
        DisplayPopup((PU8) GetString(FMGR_FS_PATH_OVER_LEN_ERROR_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteScreenIfPresent(SCR_FMGR_EDITOR_OPTION);
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
        return;
    }

    // There is no need to SetCurrentDir before create

//    fs_ret = FS_SetCurrentDir((PU16) fmgr_p->file_path);
//    if (fs_ret == FS_NO_ERROR)
    {
        mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) ptr);
        fs_ret = FS_CreateDir((PU16) fmgr_p->file_path);
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);

        if (fs_ret == FS_NO_ERROR)
        {
            /* success */
            fmgr_p->enter_folder = TRUE;
            if (fmgr_p->tree_action == FMGR_ACTION_NONE)
            {
        #if 0
            #if defined(MT6223P)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* MT6223P */
        #endif /* if 0 */

                if (IsScreenPresent(fmgr_p->active_explorer_screen))
                {
                    GoBackToHistory(fmgr_p->active_explorer_screen);
                }
                else
                {
                    /* create folder under drive */
                    entry_fmgr_explorer();
                    DeleteScreenIfPresent(SCR_FMGR_DRIVE_OPTION);
                    DeleteScreenIfPresent(SCR_FMGR_FILENAME_EDITOR);
                    DeleteScreenIfPresent(SCR_FMGR_EDITOR_OPTION);
                }
            }
            else
            {
                /* create folder when copy, move */
                if (IsScreenPresent(SCR_FMGR_TREE_EXPLORER))
                {
                    GoBackToHistory(SCR_FMGR_TREE_EXPLORER);
                }
                else
                {
                    /* create folder under drive */
                    entry_fmgr_tree_explorer();
                    DeleteScreenIfPresent(SCR_FMGR_DRIVE_OPTION);
                    DeleteScreenIfPresent(SCR_FMGR_TREE_DRIVE_OPTION);
                    DeleteScreenIfPresent(SCR_FMGR_FILENAME_EDITOR);
                    DeleteScreenIfPresent(SCR_FMGR_EDITOR_OPTION);
                }
            }
            return;
        }
    }
    /* fail */
    mmi_ucs2_to_asc((PS8) nPrintableStr, (PS8) fmgr_p->file_path);
    PRINT_INFORMATION("create folder fail under: %s", nPrintableStr);

    DisplayPopup((PU8) GetString(GetFileSystemErrorString(fs_ret)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
    DeleteScreenIfPresent(SCR_FMGR_FILENAME_EDITOR);
    DeleteScreenIfPresent(SCR_FMGR_EDITOR_OPTION);
    if (IsScreenPresent(SCR_FMGR_FOLDER_OPTION) || IsScreenPresent(SCR_FMGR_APP_FOLDER_OPTION) ||
        IsScreenPresent(SCR_FMGR_TREE_OPTION))
    {
        mmi_fmgr_remove_last_dir(fmgr_p->file_path);
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_rename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_rename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    S32 fs_ret, len;
    U16 max_len = FMGR_MAX_PATH_LEN;
    S8 *ptr;
    U8  result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((result = fmgr_check_file_present()) < FMGR_NO_ERROR)
    {
        return;
    }

#ifdef __MMI_AUDIO_PLAYER__
    else if (result == FMGR_FOLDER)
    {
        if (mmi_audply_can_delete_folder((PS8)fmgr_p->old_file_path) == MMI_FALSE)
        {
            DisplayPopup((PU8)GetString(FMGR_FS_ACCESS_DENIED_TEXT),
                     IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_FILENAME_EDITOR);
            DeleteScreenIfPresent(SCR_FMGR_EDITOR_OPTION);
            return;
        }
    }
    else if (result == FMGR_FILE)
    {
        if (mmi_audply_can_delete_file((PS8)fmgr_p->old_file_path) == MMI_FALSE)
        {
            DisplayPopup((PU8)GetString(FMGR_FS_ACCESS_DENIED_TEXT),
                     IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_FILENAME_EDITOR);
            DeleteScreenIfPresent(SCR_FMGR_EDITOR_OPTION);
            return;
        }
    }
#endif /* __MMI_AUDIO_PLAYER__ */

    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

    /* rename file: old name in fmgr_p->old_file_path, new name in fmgr_p->file_path */

    ptr = mmi_fmgr_skip_space((PS8) fmgr_p->new_file_name);
    len = mmi_ucs2strlen(ptr);
    if (len == 0)
    {
        DisplayPopup((PU8) GetString(STR_FMGR_EMPTY_FILENAME), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteScreenIfPresent(SCR_FMGR_FILENAME_EDITOR);
        DeleteScreenIfPresent(SCR_FMGR_EDITOR_OPTION);
        return;
    }
    if ((len == 1) && (ptr[0] == '.') && (ptr[1] == 0))
    {
        DisplayPopup((PU8) GetString(FMGR_FS_INVALID_FILENAME_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteScreenIfPresent(SCR_FMGR_FILENAME_EDITOR);
        DeleteScreenIfPresent(SCR_FMGR_EDITOR_OPTION);
        return;
    }

    /* new file name can't contain '/' or '\' */
    while (len > 0)
    {
        len--;
        if ((ptr[len << 1] == '/' && ptr[(len << 1) + 1] == 0) || (ptr[len << 1] == '\\' && ptr[(len << 1) + 1] == 0))
        {
            DisplayPopup((PU8) GetString(FMGR_FS_INVALID_FILENAME_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_FILENAME_EDITOR);
            DeleteScreenIfPresent(SCR_FMGR_EDITOR_OPTION);
            return;
        }
    }

    /* rename folder need more restrict length */
    if (file_info.attribute & FS_ATTR_DIR)
    {
        max_len -= 11;
    }

    if (mmi_ucs2strlen((PS8) fmgr_p->file_path) + mmi_ucs2strlen((PS8) ptr) + 1
#ifdef __MMI_SHOW_FILE_EXT__
        + mmi_ucs2strlen((PS8) fmgr_p->ext_name)
#else 
        + mmi_ucs2strlen((PS8) file_info.file_ext)
#endif 
        >= max_len)
    {
        DisplayPopup((PU8) GetString(FMGR_FS_PATH_OVER_LEN_ERROR_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteScreenIfPresent(SCR_FMGR_EDITOR_OPTION);
        return;
    }

    mmi_ucs2cat((PS8) fmgr_p->file_path, (PS8) ptr);

    /* restore '.' in file name */
    if (!(file_info.attribute & FS_ATTR_DIR))
    {
    #ifdef __MMI_SHOW_FILE_EXT__
        if (mmi_ucs2strlen((PS8) fmgr_p->ext_name) > 0)
        {
            mmi_ucs2cat((PS8) fmgr_p->file_path, (PS8) L".");
            mmi_ucs2cat((PS8) fmgr_p->file_path, fmgr_p->ext_name);
        }
    #else /* __MMI_SHOW_FILE_EXT__ */ 
        if (mmi_ucs2strlen((PS8) file_info.file_ext) > 0)
        {
            mmi_ucs2cat((PS8) fmgr_p->file_path, (PS8) file_info.file_ext);
        }
    #endif /* __MMI_SHOW_FILE_EXT__ */ 
    }

    fs_ret = FS_Rename((PU16) fmgr_p->old_file_path, (PU16) fmgr_p->file_path);

    if (fs_ret == FS_NO_ERROR)
    {
        /* success */

        if (mmi_ucs2cmp((PS8) fmgr_p->old_file_path, (PS8) fmgr_p->file_path) != 0)
        {
            /* if the file name is the same, it doesn't need to notify application */
            if (file_info.attribute & FS_ATTR_DIR)
            {
                if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) L"\\") == TRUE &&
                    mmi_fmgr_append_file_name((PS8) fmgr_p->old_file_path, (PS8) L"\\") == TRUE)
                {
                #ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
                    PmgFmgrDelExtMelodyFunc((PS8)fmgr_p->old_file_path, PMG_FMGR_DEL_ALL);
                #endif

                #ifdef __MMI_AUDIO_PLAYER__        
                    mmi_audply_update_list_hdlr((const PS8)fmgr_p->old_file_path, 
                        (const PS8)fmgr_p->file_path, AUDPLY_ACTION_RENAME, (BOOL)(file_info.attribute & FS_ATTR_DIR));
                #endif
                }
                mmi_fmgr_remove_last_dir((PS8)fmgr_p->old_file_path);
            }
            else
            {
            #ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
                PmgFmgrDelExtMelodyFunc((PS8)fmgr_p->old_file_path, PMG_FMGR_DEL_CERTAIN);
            #endif
            
            #ifdef __MMI_AUDIO_PLAYER__        
                mmi_audply_update_list_hdlr((const PS8)fmgr_p->old_file_path, 
                    (const PS8)fmgr_p->file_path, AUDPLY_ACTION_RENAME, (BOOL)(file_info.attribute & FS_ATTR_DIR));
            #endif            
            }
        }

        mmi_fmgr_remove_last_dir((PS8)fmgr_p->file_path);  

        fmgr_p->enter_folder = TRUE;
        GoBackToHistory(fmgr_p->active_explorer_screen);
    }
    else
    {
        /* fail */
        mmi_fmgr_remove_last_dir((PS8)fmgr_p->file_path);   	  
      
        mmi_ucs2_to_asc((PS8) nPrintableStr, (PS8) fmgr_p->old_file_path);
        PRINT_INFORMATION("rename fail: %s", nPrintableStr);

        DisplayPopup((PU8) GetString(GetFileSystemErrorString(fs_ret)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteScreenIfPresent(SCR_FMGR_FILENAME_EDITOR);
        DeleteScreenIfPresent(SCR_FMGR_EDITOR_OPTION);
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    U8 flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flag = fmgr_check_file_present();

    if (flag <= FMGR_NO_ERROR)
    {
        return;
    }

    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
#if 0   /* def __DRM_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /* delete file */
    if (flag == FMGR_FOLDER)
    {
        mmi_ucs2cat((PS8) fmgr_p->file_path, (PS8) file_info.file_name);
        mmi_ucs2cat((PS8) fmgr_p->file_path, (PS8) L"\\");

    #ifdef __MMI_AUDIO_PLAYER__
        if (mmi_audply_can_delete_folder((PS8)fmgr_p->file_path) == MMI_FALSE)
        {
            DisplayPopup((PU8)GetString(FMGR_FS_ACCESS_DENIED_TEXT),
                     IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            mmi_fmgr_remove_last_dir((PS8)fmgr_p->file_path);
            return;
        }
        else
    #endif
        {
        #ifdef __MMI_AUDIO_PLAYER__
            mdi_audio_suspend_background_play(); 
        #endif
            fmgr_p->delete_all = FMGR_DELETE_FOLDER;

            mmi_fmgr_send_delete_req((PU8) fmgr_p->file_path, FS_RECURSIVE_TYPE, fmgr_delete_rsp_hdlr);
        }
    }
    else
    {
    #if defined(__DRM_V02__)  
        if ( (mmi_ucs2ncmp((PS8)fmgr_p->file_path+ ((mmi_ucs2strlen((PS8)fmgr_p->file_path)-4)<<1), (PS8)L".odf", 4) == 0) ||
             (mmi_ucs2ncmp((PS8)fmgr_p->file_path+ ((mmi_ucs2strlen((PS8)fmgr_p->file_path)-4)<<1), (PS8)L".ODF", 4) == 0))
        
        {
            mmi_ucs2cat(fmgr_p->file_path, (PS8)L"\\");
        }
    #endif /* DRM_V02 */
    
        mmi_ucs2cat((PS8) fmgr_p->file_path, (PS8) file_info.file_name);
    #ifndef __MMI_SHOW_FILE_EXT__
        mmi_ucs2cat((PS8) fmgr_p->file_path, (PS8) file_info.file_ext);
    #endif 

    #if defined(__DRM_V02__)
        {
            FMGR_FILTER file_type;
        
            mmi_fmgr_get_file_type(fmgr_p->file_path, &file_type);
            if (DRM_is_archive(0, (PU16)fmgr_p->file_path) && (!FMGR_FILTER_IS_SET(&file_type, FMGR_TYPE_ODF)))
            {
                DisplayPopup((PU8)GetString(STR_GLOBAL_INVALID),
                         IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
                return;
            }
        }
    #endif

    #ifdef __MMI_AUDIO_PLAYER__
        if (mmi_audply_can_delete_file((PS8)fmgr_p->file_path) == MMI_FALSE)
        {
            DisplayPopup((PU8)GetString(FMGR_FS_ACCESS_DENIED_TEXT),
                          IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            mmi_fmgr_remove_last_dir((PS8)fmgr_p->file_path);
            return;
        }
        else
    #endif /* __MMI_AUDIO_PLAYER__ */
        {
    #ifdef __MMI_AUDIO_PLAYER__
	    mdi_audio_suspend_background_play();
    #endif
            mmi_fmgr_send_delete_req((PU8) fmgr_p->file_path, FS_FILE_TYPE, fmgr_delete_rsp_hdlr);
        }
    }

    /* Set fmgr is busy flag */
    fmgr_p->is_fmgr_busy = MMI_TRUE;    

    entry_fmgr_delete_animation();

}


/*****************************************************************************
 * FUNCTION
 *  fmgr_delete_all_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_delete_all_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_is_parent_present() == FALSE)
    {
        DisplayPopup((PU8) GetString(FMGR_FS_PATH_NOT_FOUND_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);

        /* go back to root, reload file manager */
        if (fmgr_p->src_application == APP_FILEMANAGER)
        {
            fmgr_adjust_history(SCR_FMGR_MAIN);
        }
        else
        {
            fmgr_adjust_history(0);
        }
        return;
    }

#if defined(__DRM_V02__)
    {
        FMGR_FILTER file_type;
        FMGR_FILE_INFO_STRUCT file_info;
        
        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
        
        if ( (mmi_ucs2ncmp((PS8)fmgr_p->file_path+ ((mmi_ucs2strlen((PS8)fmgr_p->file_path)-4)<<1), (PS8)L".odf", 4) == 0) ||
             (mmi_ucs2ncmp((PS8)fmgr_p->file_path+ ((mmi_ucs2strlen((PS8)fmgr_p->file_path)-4)<<1), (PS8)L".ODF", 4) == 0))
        {
            mmi_ucs2cat(fmgr_p->file_path, (PS8)L"\\");
        }
    
        mmi_ucs2cat((PS8) fmgr_p->file_path, (PS8) file_info.file_name);

        mmi_fmgr_get_file_type(fmgr_p->file_path, &file_type);
        if (DRM_is_archive(0, (PU16)fmgr_p->file_path) && (!FMGR_FILTER_IS_SET(&file_type, FMGR_TYPE_ODF)))
        {
            DisplayPopup((PU8)GetString(STR_GLOBAL_INVALID),
                     IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            mmi_fmgr_remove_last_dir((PS8)fmgr_p->file_path);
            return;
        }
        mmi_fmgr_remove_last_dir((PS8)fmgr_p->file_path);
    }
#endif

#ifdef __MMI_AUDIO_PLAYER__
    if (mmi_audply_can_delete_all_files((PS8)fmgr_p->file_path) == MMI_FALSE)
    {
        DisplayPopup((PU8)GetString(FMGR_FS_ACCESS_DENIED_TEXT),
                 IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        return;
    }
    else
#endif
    {
    #ifdef __MMI_AUDIO_PLAYER__
        mdi_audio_suspend_background_play(); 
    #endif
        /* delete files including drm file + rights */
        mmi_fmgr_send_delete_req((PU8) fmgr_p->file_path, FS_DIR_TYPE, fmgr_delete_rsp_hdlr);
    }

    /* Set fmgr is busy flag */
    fmgr_p->is_fmgr_busy = MMI_TRUE;    

    entry_fmgr_delete_animation();
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_delete_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_delete_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 iconId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(0);

    EntryNewScreen(SCR_FMGR_DELETE_ANIMATION, exit_fmgr_delete_animation, NULL, NULL);

    iconId = fmgr_get_app_title_icon_id();
    
    ShowCategory66Screen(
        STR_GLOBAL_DELETE,
        iconId,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_FMGR_DELETING),
        IMG_GLOBAL_DELETED,
        NULL);

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    if (!IsScreenPresent(SCR_FMGR_DELETE_ANIMATION))
    {
        DeleteUptoScrID(fmgr_p->active_explorer_screen);
    }

    SetDelScrnIDCallbackHandler(SCR_FMGR_DELETE_ANIMATION, (HistoryDelCBPtr) fmgr_delete_animation_callback);
}


/*****************************************************************************
 * FUNCTION
 *  exit_fmgr_delete_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_fmgr_delete_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() == FALSE)
    {
        /* pop up interrupt => add to history */
        history currHistory;
        S16 nHistory = 0;

        currHistory.scrnID = SCR_FMGR_DELETE_ANIMATION;
        currHistory.entryFuncPtr = entry_fmgr_delete_animation;
        mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
        AddHistory(currHistory);
    }
    else
    {
        /* interrupt by Call => abort XDelete */
        if (fmgr_p->delete_all == FMGR_DELETE_FOLDER ||
            (fmgr_p->delete_all == FMGR_DELETE_ALL && FMGR_FILTER_IS_SET(&fmgr_p->delete_filter_type, FMGR_TYPE_ALL)))
        {
            FS_Abort(FS_ABORT_XDELETE);
            fmgr_p->cur_index = 0;
            /* if (fmgr_p->delete_all != FMGR_DELETE_ALL)
               mmi_fmgr_remove_last_dir((PS8)fmgr_p->file_path);
               fmgr_p->delete_all = FMGR_DELETE_NONE;
               fmgr_p->enter_folder = TRUE; */
        }
        else if (fmgr_p->delete_all == FMGR_DELETE_ALL)
        {
            fmt_abort_copy();
            fmgr_p->cur_index = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_delete_animation_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 fmgr_delete_animation_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_p->delete_all == FMGR_DELETE_NONE)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_send_delete_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]        
 *  type            [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_send_delete_req(PU8 path, U32 type, PsFuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_fmt_delete_req_strcut *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_FMT;
    Message.oslMsgId = PRT_MMI_FMGR_DELETE_REQ;

    ClearInputEventHandler(MMI_DEVICE_ALL);

//    SetProtocolEventHandler(callback, PRT_MMI_FMGR_DELETE_RSP);
    SetProtocolEventHandler(fmgr_delete_rsp_center_hdlr, PRT_MMI_FMGR_DELETE_RSP);

    msgReq = (mmi_fmt_delete_req_strcut*) OslConstructDataPtr(sizeof(mmi_fmt_delete_req_strcut));

    msgReq->type = type;
    msgReq->path = path;

    msgReq->callback = (void*)callback;

    if (type == FS_DIR_TYPE && fmgr_p->src_application != APP_FILEMANAGER)
    {
        fmgr_p->delete_filter_type = fmgr_p->filter_type;
        FMGR_FILTER_CLEAR(&fmgr_p->delete_filter_type, FMGR_TYPE_FOLDER);
        msgReq->filter = &fmgr_p->delete_filter_type;
        /* msgReq->filter = fmgr_p->filter_type & (~FMGR_TYPE_FOLDER); */
    }
    else
    {
        FMGR_FILTER_INIT(&fmgr_p->delete_filter_type);
        FMGR_FILTER_SET_ALL(&fmgr_p->delete_filter_type);

        msgReq->filter = &fmgr_p->delete_filter_type;
    }

    Message.oslDataPtr = (oslParaType*) msgReq;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_delete_rsp_center_hdlr
 * DESCRIPTION
 *  delete rsp message center handler
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_delete_rsp_center_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_delete_rsp_strcut *msgPtr;
    //PsFuncPtr callback;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgPtr = (mmi_fmt_delete_rsp_strcut*) info;

    if (msgPtr->callback)
    {
        ((PsFuncPtr)(msgPtr->callback))(info);
        //callback = (PsFuncPtr)msgPtr->callback;
        //callback(info);
    }

}


/*****************************************************************************
 * FUNCTION
 *  fmgr_delete_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_delete_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_delete_rsp_strcut *msgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOffBacklight();
    SetDelScrnIDCallbackHandler (SCR_FMGR_DELETE_ANIMATION, (HistoryDelCBPtr)NULL);	

    fmgr_p->is_fmgr_busy = MMI_FALSE;

#ifdef __MMI_AUDIO_PLAYER__
    if (isInCall() == MMI_FALSE)
    {
        mdi_audio_resume_background_play();
    }
#endif 

    msgPtr = (mmi_fmt_delete_rsp_strcut*) info;

    if (msgPtr->result >= FS_NO_ERROR)
    {
        {
        #ifdef __MMI_AUDIO_PLAYER__        
            mmi_audply_update_list_hdlr((const PS8)fmgr_p->file_path, NULL, AUDPLY_ACTION_DELETE, (BOOL)(fmgr_p->delete_all != FMGR_DELETE_SINGLE));
        #endif
        }

        /* success */
    #ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
        if (fmgr_p->delete_all == FMGR_DELETE_SINGLE)
        {
            PmgFmgrDelExtMelodyFunc((PS8) fmgr_p->file_path, PMG_FMGR_DEL_CERTAIN);
        }
        else
        {
            PmgFmgrDelExtMelodyFunc((PS8) fmgr_p->file_path, PMG_FMGR_DEL_ALL);
        }
    #endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 

        if (isInCall() == TRUE && GetExitScrnID() != SCR_FMGR_DELETE_ANIMATION)
        {
            DeleteScreenIfPresent(SCR_FMGR_DELETE_ANIMATION);
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 0, 1000, SUCCESS_TONE);
            DeleteScreenIfPresent(SCR_FMGR_DELETE_ANIMATION);
        }
    }
    else
    {
        /* fail */
        mmi_ucs2_to_asc((PS8) nPrintableStr, (PS8) fmgr_p->file_path);
        PRINT_INFORMATION("delete fail: %s", nPrintableStr);

        if (isInCall() == TRUE && GetExitScrnID() != SCR_FMGR_DELETE_ANIMATION)
        {
            DeleteScreenIfPresent(SCR_FMGR_DELETE_ANIMATION);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(GetFileSystemErrorString(msgPtr->result)),
                IMG_GLOBAL_ERROR,
                0,
                1000,
                ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_DELETE_ANIMATION);
        }
        /* Notify audio player delete folder/all fail. 
           It means some files in this folder are deleted, but some aren't. */
        if (fmgr_p->delete_all == FMGR_DELETE_ALL || fmgr_p->delete_all == FMGR_DELETE_FOLDER)
        {
        #ifdef __MMI_AUDIO_PLAYER__        
            mmi_audply_update_list_hdlr((const PS8)fmgr_p->file_path, NULL, AUDPLY_ACTION_DELETE_FAIL, TRUE);
        #endif
        }
    }
#if defined(__DRM_MTK__)
    if (mmi_ucs2ncmp((PS8) fmgr_p->file_path, (PS8) DRM_RO_PATH, mmi_ucs2strlen((PS8) DRM_RO_PATH)) == 0)
    {
        if (fmgr_p->delete_all == FMGR_DELETE_ALL_EXPIRED)
        {
            if (FS_Count((PU16) fmgr_p->file_path, FS_DIR_TYPE | FS_FILE_TYPE | FS_FILTER_SYSTEM_ATTR, NULL, 0) > 0)
            {
                /* move selection to first */
                fmgr_p->cur_index = 0;
                fmgr_p->enter_folder = TRUE;
            }
        }
        else
        {
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
         
            /* move selection up one step */
            if (fmgr_p->cur_index > 0)
			{
                fmgr_p->cur_index--;
			}
			fmgr_p->enter_folder = FALSE;
        }
    }
    else
#endif /* __DRM_MTK__ */ 
    {
        if (fmgr_p->delete_all != FMGR_DELETE_ALL)
        {
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            /* move selection up one step */
            // to sync fmgr & other app's behavior: after delete cur-index doesn't change.
            //if (fmgr_p->cur_index > 0)
            //{
            //    fmgr_p->cur_index--;
            //}
            fmgr_p->enter_folder = FALSE;
        }
        else
        {
            /* delete all files with folder left */
            if (FS_Count((PU16) fmgr_p->file_path, FS_DIR_TYPE | FS_FILTER_SYSTEM_ATTR, NULL, 0) > 0)
            {
                /* move selection to first */
                fmgr_p->cur_index = 0;
                fmgr_p->enter_folder = TRUE;
            }
        }
    }

    if (( (fmgr_p->src_application == APP_FILEMANAGER || fmgr_p->src_application == APP_MYFAVORITE)&&
         FS_Count((PU16) fmgr_p->file_path, FS_DIR_TYPE | FS_FILE_TYPE | FS_FILTER_SYSTEM_ATTR | FS_FILTER_HIDDEN_ATTR , NULL, 0) == 0) ||
        (fmgr_p->src_application != APP_FILEMANAGER &&
         (fmgr_p->sel_type & FMGR_SELECT_FOLDER) &&
         FS_Count((PU16) fmgr_p->file_path, FS_DIR_TYPE | FS_FILTER_SYSTEM_ATTR, NULL, 0) == 0))
    {
    #ifdef __DRM_MTK__
        if (mmi_ucs2ncmp((PS8) fmgr_p->file_path, (PS8) DRM_RO_PATH, mmi_ucs2strlen((PS8) DRM_RO_PATH)) == 0)
        {
            DeleteScreenIfPresent(SCR_FMGR_EXPLORER);
        }
        else
    #endif /* __DRM_MTK__ */ 
        if (mmi_ucs2strlen((PS8) fmgr_p->file_path) <= 3)
        {
            DeleteScreenIfPresent(SCR_FMGR_EXPLORER);
        }
        else
	      {
            PS8 ptr;
        #ifdef __MMI_MY_FAVORITE__
            S8 my_favorite_path[30];
        #endif

        #ifdef __MMI_MY_FAVORITE__
            mmi_my_favorite_get_swflash_folder_path(my_favorite_path);
            if((fmgr_p->src_application == APP_MYFAVORITE) && !(mmi_ucs2cmp((PS8)fmgr_p->file_path, (const PS8) my_favorite_path)))
            {
                ; /* no nothing */
            }
            else
        #endif
            {
                ptr = mmi_fmgr_extract_file_name((PS8) fmgr_p->file_path);
                if (ptr != NULL)
	              {
                    S32 end;

                    end = mmi_ucs2strlen(ptr) - 1;
                    if (ptr[end << 1] == '\\' && ptr[(end << 1) + 1] == 0)
		                {
                        ptr[end << 1] = 0;
		                }
                    mmi_ucs2cpy((PS8) fmgr_p->parent_name, ptr);
	              }
                mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            }
	      }
        /* move selection to first */
        fmgr_p->cur_index = 0;

    #ifdef __MMI_MY_FAVORITE__
        if (mmi_ucs2strlen((PS8) fmgr_p->file_path) <= 3)
        {
            if (fmgr_p->src_application == APP_MYFAVORITE)
            {
                /* check path = root, should go back to my favorite main screen */
                DeleteScreenIfPresent(SCR_FMGR_EXPLORER);
            }
        }
    #endif
    }

    fmgr_p->delete_all = FMGR_DELETE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_copy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_copy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    S8 *temp;
    U16 scrnId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrnId = GetExitScrnID();
    if (scrnId != SCR_FMGR_DRIVE_OPTION && scrnId != SCR_FMGR_TREE_DRIVE_OPTION && scrnId != SCR_FMGR_MAIN)
    {
        /* copy to drive no need to append current folder name */
        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

        if (!(file_info.file_name[0] == 0 && file_info.file_name[1] == 0) &&
            (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE ||
             mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) L"\\") == FALSE))
        {
            DeleteScreenIfPresent(SCR_FMGR_TREE_OPTION);
            return;
        }
    }

    if (fmt_get_abort_copy() == TRUE)
    {
        /* stil copying, busy */
        DisplayPopup((PU8) GetString(FMGR_FS_DEVICE_BUSY_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
        DeleteUptoScrID(fmgr_p->active_explorer_screen);
        FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
        fmgr_p->tree_action = FMGR_ACTION_NONE;
        return;
    }

    /* copy file */
    temp = mmi_fmgr_extract_file_name((PS8) fmgr_p->old_file_path);
    if (mmi_ucs2strlen((PS8) fmgr_p->file_path) + mmi_ucs2strlen(temp) >= FMGR_MAX_PATH_LEN)
    {
        DisplayPopup((PU8) GetString(FMGR_FS_PATH_OVER_LEN_ERROR_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteScreenIfPresent(SCR_FMGR_TREE_OPTION);
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
        return;
    }
    temp = mmi_fmgr_skip_space(temp);
    mmi_ucs2cat((PS8) fmgr_p->file_path, (PS8) temp);

    if (mmi_ucs2cmp((PS8) fmgr_p->old_file_path, (PS8) fmgr_p->file_path) == 0)
    {
        /* can't copy, move to same folder */
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
        FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
        fmgr_p->tree_action = FMGR_ACTION_NONE;
        DisplayPopup((PU8) GetString(FMGR_FS_FILE_EXISTS_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
    #if 0
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
        DeleteUptoScrID(fmgr_p->active_explorer_screen);
        return;
    }
#ifdef __MMI_AUDIO_PLAYER__
    else if (mmi_audply_can_delete_file((PS8)fmgr_p->old_file_path) == MMI_FALSE 
                && fmgr_p->tree_action == FMGR_ACTION_MOVE)
    {
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
        FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
        fmgr_p->tree_action = FMGR_ACTION_NONE;
        DisplayPopup((PU8)GetString(FMGR_FS_ACCESS_DENIED_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteUptoScrID(fmgr_p->active_explorer_screen);
        return;
    }
#endif

    entry_fmgr_copy_animation();

    /* display animation screen */
    mmi_fmgr_send_copy_req(
        fmgr_p->tree_action,
        (PU8) fmgr_p->old_file_path,
        (PU8) fmgr_p->file_path,
        (PsFuncPtr) fmgr_copy_rsp_hdlr);
    
    /* clear end key handler */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    
    
    /* Set fmgr is busy flag */
    fmgr_p->is_fmgr_busy = MMI_TRUE;    

    return;
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_copy_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_copy_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 stringId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(0);

#ifdef __MMI_AUDIO_PLAYER__
    mdi_audio_suspend_background_play();
#endif 

    if (fmgr_p->tree_action == FMGR_ACTION_COPY)
    {
        stringId = STR_FMGR_COPYING;
    }
    else if (fmgr_p->tree_action == FMGR_ACTION_MOVE)
    {
        stringId = STR_FMGR_MOVING;
    }
    else
    {
        return;
    }

    EntryNewScreen(SCR_FMGR_COPY_ANIMATION, exit_fmgr_copy_animation, NULL, NULL);

    ShowCategory66Screen(
        STR_FMGR_TITLE,
        GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID),
        0,
        0,
        0,
        0,
        (PU8) GetString(stringId),
        IMG_GLOBAL_PROGRESS,
        NULL);

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    if (!IsScreenPresent(SCR_FMGR_COPY_ANIMATION))
    {
        DeleteUptoScrID(fmgr_p->active_explorer_screen);
        DeleteScreenIfPresent(SCR_FMGR_TREE_OPTION);
        DeleteScreenIfPresent(SCR_FMGR_TREE_DRIVE_OPTION);
    }
}


/*****************************************************************************
 * FUNCTION
 *  exit_fmgr_copy_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_fmgr_copy_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (POPUP_SCREENID == GetActiveScreenId())
    {
        /* pop up interrupt => add to history */
        history currHistory;
        S16 nHistory = 0;

        currHistory.scrnID = SCR_FMGR_COPY_ANIMATION;
        currHistory.entryFuncPtr = entry_fmgr_copy_animation;
        mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
        AddHistory(currHistory);
    }
    else
    {
        /* interrupt by Call => abort copy */
        if (fmgr_p->tree_action == FMGR_ACTION_COPY || fmgr_p->tree_action == FMGR_ACTION_MOVE)
        {
            fmt_abort_copy();
            FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
            fmgr_p->tree_action = FMGR_ACTION_NONE;
            fmgr_p->enter_folder = TRUE;

            /* aborted => go back to source folder */
            mmi_ucs2cpy((S8*) fmgr_p->file_path, (S8*) fmgr_p->old_file_path);
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            DeleteScreenIfPresent(SCR_FMGR_COPY_ANIMATION);            
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_send_copy_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  action          [IN]        
 *  src_file        [IN]        
 *  dest_file       [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_send_copy_req(U8 action, PU8 src_file, PU8 dest_file, PsFuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_fmt_copy_req_strcut *msgReq;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_FMT;
    Message.oslMsgId = PRT_MMI_FMGR_COPY_REQ;

    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetProtocolEventHandler(callback, PRT_MMI_FMGR_COPY_RSP);

    msgReq = (mmi_fmt_copy_req_strcut*) OslConstructDataPtr(sizeof(mmi_fmt_copy_req_strcut));

    if (action == FMGR_ACTION_COPY)
    {
        msgReq->action = FMT_COPY;
    }
    else
    {
        msgReq->action = FMT_MOVE;
    }
    msgReq->src_file = src_file;

    ASSERT(mmi_ucs2strlen((PS8) dest_file) < 260);
    mmi_ucs2cpy((PS8) msgReq->dest_file, (PS8) dest_file);

    Message.oslDataPtr = (oslParaType*) msgReq;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_send_abort_copy_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  action          [IN]        
 *  src_file        [IN]        
 *  dest_file       [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_send_abort_copy_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmt_abort_copy();
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_copy_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_copy_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_copy_rsp_strcut *msgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgPtr = (mmi_fmt_copy_rsp_strcut*) info;

    TurnOffBacklight();

    fmgr_p->is_fmgr_busy = MMI_FALSE;

    if (isInCall() == TRUE && GetExitScrnID() != SCR_FMGR_COPY_ANIMATION)
    {
//        if (msgPtr->result == FS_ABORTED_ERROR)
//        {
//            /* aborted => go back to source folder */
//            mmi_ucs2cpy((S8*) fmgr_p->file_path, (S8*) fmgr_p->old_file_path);
//        }
//        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);

        FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
        fmgr_p->tree_action = FMGR_ACTION_NONE;
        fmgr_p->enter_folder = TRUE;
        DeleteScreenIfPresent(SCR_FMGR_COPY_ANIMATION);
        return;
    }

#ifdef __MMI_AUDIO_PLAYER__
    if (isInCall() == MMI_FALSE)
    {    
        mdi_audio_resume_background_play();
    }
#endif 

    if (msgPtr->result >= 0)
    {
        /* success */
    #ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
        if (fmgr_p->tree_action == FMGR_ACTION_MOVE)
        {
            PmgFmgrDelExtMelodyFunc((PS8) fmgr_p->old_file_path, PMG_FMGR_DEL_CERTAIN);
        }
    #endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 

    #ifdef __MMI_AUDIO_PLAYER__        
      	if (fmgr_p->tree_action == FMGR_ACTION_MOVE)
      	{
            if (mmi_ucs2ncmp(fmgr_p->old_file_path, fmgr_p->file_path ,3)==0)
            {
                mmi_audply_update_list_hdlr((const PS8)fmgr_p->old_file_path, (const PS8)fmgr_p->file_path, AUDPLY_ACTION_MOVE, FALSE);
            }
            else
            {
                mmi_audply_update_list_hdlr((const PS8)fmgr_p->old_file_path, NULL, AUDPLY_ACTION_DELETE, FALSE);   
            }
        }
        else if (fmgr_p->tree_action == FMGR_ACTION_COPY)
        {
            mmi_audply_update_list_hdlr((const PS8)fmgr_p->old_file_path, (const PS8)fmgr_p->file_path, AUDPLY_ACTION_COPY, FALSE);
        }
    #endif

        /* Reset hash table */
        memset(fmgr_p->parent_idx_hash_table, 0, sizeof(fmgr_p->parent_idx_hash_table));

        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, 1000, SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_FMGR_COPY_ANIMATION);
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
        FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
        fmgr_p->tree_action = FMGR_ACTION_NONE;
        fmgr_p->enter_folder = TRUE;
    }
    else
    {
        /* fail */
        mmi_ucs2_to_asc((PS8) nPrintableStr, (PS8) fmgr_p->file_path);
        PRINT_INFORMATION("copy rsp fail: %s", nPrintableStr);

        FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
        fmgr_p->tree_action = FMGR_ACTION_NONE;
        fmgr_p->enter_folder = FALSE;

        if (msgPtr->result == FS_ABORTED_ERROR)
        {
//          if (IsScreenPresent(fmgr_p->active_explorer_screen))
//          {
//              GoBackToHistory(fmgr_p->active_explorer_screen);
//          }
        }
        else
        {
        	   mmi_ucs2cpy((S8*) fmgr_p->file_path, (S8*) fmgr_p->old_file_path);
        	   mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
        
            DisplayPopup(
                (PU8) GetString(GetFileSystemErrorString(msgPtr->result)),
                IMG_GLOBAL_ERROR,
                0,
                1000,
                ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_COPY_ANIMATION);
            DeleteScreenIfPresent(SCR_FMGR_TREE_EXPLORER);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_send_format_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drive           [IN]        
 *  level           [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_send_format_req(U8 drive, U32 level, PsFuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_fmt_format_req_strcut *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_FMT;
    Message.oslMsgId = PRT_MMI_FMGR_FORMAT_REQ;

    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetProtocolEventHandler(callback, PRT_MMI_FMGR_FORMAT_RSP);

    msgReq = (mmi_fmt_format_req_strcut*) OslConstructDataPtr(sizeof(mmi_fmt_format_req_strcut));

    msgReq->level = level;
    msgReq->drive = drive;

    Message.oslDataPtr = (oslParaType*) msgReq;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_drive_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_drive_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_format_rsp_strcut *msgPtr;
    U8 action;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgPtr = (mmi_fmt_format_rsp_strcut*) info;

    fmgr_p->is_fmgr_busy = MMI_FALSE;

    if (isInCall() == TRUE && GetExitScrnID() != SCR_FMGR_DRIVE_ANIMATION
        && fmgr_p->drive_action == FMGR_ACTION_CHECK_DRIVE)
    {
        FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
        fmgr_p->tree_action = FMGR_ACTION_NONE;
        fmgr_p->enter_folder = TRUE;
        fmgr_p->drive_action = FMGR_ACTION_NONE;
        DeleteScreenIfPresent(SCR_FMGR_DRIVE_ANIMATION);
        return;
    }

    TurnOffBacklight();

    action = fmgr_p->drive_action;

    fmgr_p->enter_folder = TRUE;
    FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
    fmgr_p->tree_action = FMGR_ACTION_NONE;
    fmgr_p->drive_action = FMGR_ACTION_NONE;

    if (isInCall() == TRUE && GetExitScrnID() != SCR_FMGR_DRIVE_ANIMATION)
    {
        DeleteScreenIfPresent(SCR_FMGR_DRIVE_ANIMATION);
        return;
    }

    if (msgPtr->result >= 0)
    {
        S8 drive_index;

        drive_index = fmgr_get_drive_index(fmgr_p->cur_index);
            
        if (action == FMGR_ACTION_FORMAT)
        {
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

            U8 themetype;

            themetype = mmi_tm_get_curr_theme_type();

            if ((themetype == THEME_TYPE_DOWNLOADED_PHONE) &&
                ((drive_index == FMGR_NAND_STORAGE) || (drive_index == FMGR_NOR_STORAGE)))
            {
                ActivateDefaultTheme();
            }
            else if ((themetype == THEME_TYPE_DOWNLOADED_CARD) && (drive_index == FMGR_REMOVABLE_STORAGE))
            {
                ActivateDefaultTheme();
            }
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */  
    #ifdef __MMI_EMAIL__
            if ((drive_index == FMGR_NAND_STORAGE) || (drive_index == FMGR_NOR_STORAGE))
            {
                mmi_email_fmgr_reset_status_icon();
            }
    #endif
    #ifdef __MMI_AUDIO_PLAYER__
            if (isInCall() == MMI_FALSE)
            {
                mdi_audio_resume_background_play();
            }
            mmi_audply_need_reinit();
    #endif
    
    #ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__      	
            {
                S8 buf[10];

                mmi_asc_to_ucs2((PS8)buf, (PS8) fmgr_p->drv_list[drive_index]);

                PmgFmgrDelExtMelodyFunc((PS8)buf, PMG_FMGR_DEL_ALL);
            }
    #endif
#ifdef __MMI_MMS_BGSR_SUPPORT__
            mmi_mms_bgsr_change_msg_notify(0, MMI_MMS_BGSR_OP_FORMAT, 0, NULL);
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
        }
        /* success */
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, 1000, SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_FMGR_DRIVE_ANIMATION);
        if(action == FMGR_ACTION_UNMOUNT)
        {
        #ifdef __MMI_AUDIO_PLAYER__
            /* Notify audio player msdc is plug-out */
            mmi_audply_msdc_plug_out_hdlr(TRUE);
        #endif
        #ifdef __MMI_UNIFIED_COMPOSER__
            mmi_uc_sd_plug_out_hdlr();
        #endif /* __MMI_UNIFIED_COMPOSER__ */
        
            fmgr_p->drv_count--;
            memset(fmgr_p->drv_list[drive_index], 0, sizeof(fmgr_p->drv_list[drive_index]));
        }
    }
    else
    {
        /* fail */
        U16 stringId;

        if (msgPtr->result == FS_TIMEOUT)
            /* if file open => can't format */
        {
            stringId = FMGR_FS_LOCK_MUTEX_FAIL_TEXT;
        }
        else
        {
            stringId = GetFileSystemErrorString(msgPtr->result);
        }

        DisplayPopup((PU8) GetString(stringId), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteScreenIfPresent(SCR_FMGR_DRIVE_ANIMATION);
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_send_check_drive_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drive           [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_send_check_drive_req(U8 drive, PsFuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_fmt_check_drive_req_strcut *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_FMT;
    Message.oslMsgId = PRT_MMI_FMGR_CHECK_DRIVE_REQ;

    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetProtocolEventHandler(callback, PRT_MMI_FMGR_CHECK_DRIVE_RSP);

    //SetInterruptEventHandler(fmgr_drvop_incoming_call_interrupt_hdlr,NULL,MSG_ID_MMI_VOIP_CALL_RING_IND);
    //SetInterruptEventHandler(fmgr_drvop_incoming_call_interrupt_hdlr,NULL,MSG_ID_MMI_CC_CALL_RING_IND);
	mmi_frm_block_interrupt_event_handler(MMI_FRM_INT_VOIP_CALL_RING | MMI_FRM_INT_CC_CALL_RING, 
		fmgr_drvop_incoming_call_interrupt_hdlr, 
		NULL);

    msgReq = (mmi_fmt_check_drive_req_strcut*) OslConstructDataPtr(sizeof(mmi_fmt_check_drive_req_strcut));

    msgReq->drive = drive;

    Message.oslDataPtr = (oslParaType*) msgReq;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_drvop_incoming_call_interrupt_hdlr
 * DESCRIPTION
 *  incoming call interrput handler
 * PARAMETERS
 *  inMsg       [IN]        Message pointer
 * RETURNS
 *  U8
 *****************************************************************************/
U8 fmgr_drvop_incoming_call_interrupt_hdlr(mmi_frm_int_event_type event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to execute drive animation exist function */
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
    
    return FALSE;   /* return FALSE will process default handler */
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_send_unmount_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 *  mode            [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_send_unmount_req(U8 index, U32 mode, PsFuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_fmt_unmount_req_strcut *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_FMT;
    Message.oslMsgId = PRT_MMI_FMGR_UNMOUNT_REQ;

    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetProtocolEventHandler(callback, PRT_MMI_FMGR_UNMOUNT_RSP);

    msgReq = (mmi_fmt_unmount_req_strcut*) OslConstructDataPtr(sizeof(mmi_fmt_unmount_req_strcut));

    msgReq->index = index;
    msgReq->mode = mode;

    Message.oslDataPtr = (oslParaType*) msgReq;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_sort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_sort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* write to nvram */
    temp = fmgr_p->sort_option >> 5;
    if (fmgr_p->sort_option == FS_SORT_NAME || fmgr_p->sort_option == FS_SORT_SIZE ||
        fmgr_p->sort_option == FS_SORT_TIME || fmgr_p->sort_option == FS_SORT_TYPE || fmgr_p->sort_option == FS_NO_SORT)
    {
        WriteValue(NVRAM_EF_FMGR_SORT_OPTION_LID, &temp, DS_BYTE, &error);
        /* Reset hash table */
        memset(fmgr_p->parent_idx_hash_table, 0, sizeof(fmgr_p->parent_idx_hash_table));
    }
    fmgr_p->enter_folder = TRUE;
    GoBackToHistory(fmgr_p->active_explorer_screen);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_forward_to_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_forward_to_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOAD_AGENT__
    /* download agent file */
    if (fmgr_is_da_file())
    {
        UI_character_type filename[FMGR_MAX_FILE_LEN];
        FS_DOSDirEntry fs_info;
        FS_HANDLE fd_cursor;
        FS_HANDLE handle;

        /* Check if file exists or not */
        handle = FS_Open((PU16) fmgr_p->da_file_path, FS_READ_ONLY);
        if (handle > FS_NO_ERROR)
        {
        	FS_Close(handle);
        }
        else
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION);
            return;
        }
        
        mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->da_file_path);

     #if defined(__DRM_V02__)        
        {
            S32 file_type = 0;

        file_type = mmi_fmgr_get_drm_file_type_by_path((PS8) fmgr_p->file_path, &file_info.file_type);
            
        if (file_type == FMGR_TYPE_ODF)
        {
            /* multi part ODF */
            mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
    
            if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
        #ifndef __MMI_SHOW_FILE_EXT__
                || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
        #endif 
                )
                return;
        }
         }
     #else
         mmi_fmgr_get_file_type((PS8) fmgr_p->da_file_path, &file_info.file_type);
     #endif /* defined(__DRM_V02__) */
 
//        file_info.is_short = FALSE;
        if ( (fd_cursor = FS_FindFirst((PU16)fmgr_p->file_path, 0, 0, &fs_info, filename, (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH)) >= 0)
        {
            file_info.is_short = ((fs_info.NTReserved & FS_SFN_MATCH) != 0);
            FS_FindClose(fd_cursor);
        }
        else
        {
            return;
        }
    }
    /* non download agent file */
    else
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
    {
        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

        if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
    #ifndef __MMI_SHOW_FILE_EXT__
            || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
    #endif 
            )
            return;

        DeleteUptoScrID(SCR_FMGR_EXPLORER);
    }

    switch (fmgr_p->tree_action)
    {
        case FMGR_ACTION_FWD_WALLPAPER:
            /* pass file name to Wallpaper */
            /* hook Wallpaper func */
            PhnsetWallpaperForwardFromFmgr((PS8) fmgr_p->file_path, &file_info.file_type, (int)file_info.is_short);
            break;

        #ifdef __MMI_SUB_WALLPAPER__
        case FMGR_ACTION_FWD_SUB_WALLPAPER:
            /* pass file name to sub Wallpaper */
            /* hook sub Wallpaper func */
            PhnsetSubWallpaperForwardFromFmgr((PS8) fmgr_p->file_path, &file_info.file_type, (int)file_info.is_short);
            break;
        #endif /* __MMI_SUB_WALLPAPER__ */ 

        case FMGR_ACTION_FWD_SCREENSAVER:
            /* pass file name to Screen Saver */
            /* hook Screen Saver func */
            PhnsetScrSvrForwardFromFmgr((PS8) fmgr_p->file_path, &file_info.file_type, (int)file_info.is_short);
            break;

        #ifdef __MMI_POWER_ON_OFF_DISPLAY__
        case FMGR_ACTION_FWD_POWER_ON:
        case FMGR_ACTION_FWD_POWER_OFF:
            PhnsetPwrOnOffForwardFromFmgr((PS8) fmgr_p->file_path, &file_info.file_type, fmgr_p->tree_action, (int)file_info.is_short);
            break;
        #endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 

        #ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
        case FMGR_ACTION_FWD_PROFILE:
            /* pass file name to Profile */
            /* hook Profile func */
            PmgSetShortFileName(file_info.is_short);    /* let PMGR know whether it's short filename */
            PmgFmgrAddExtMelodyFunc((PS8) fmgr_p->file_path);
            break;
        #endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 

        #ifdef __MMI_BG_SOUND_EFFECT__
        case FMGR_ACTION_FWD_BGSOUND:
            mmi_bgsnd_fmgr_from_file_mgr((PS8) fmgr_p->file_path, file_info.is_short);
            break;
        #endif /* __MMI_BG_SOUND_EFFECT__ */ 

        case FMGR_ACTION_FWD_PHONEBOOK:
            /* pass file name to PHB */
#if 0
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_FTC_SUPPORT__
/* under construction !*/
        #endif 
        #ifdef __MMI_BIP_SUPPORT__
/* under construction !*/
        #endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* if 0 */
            /* hook PHB func */
        #ifdef __MMI_VCARD__
            if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_VCF))
            {
                mmi_vcard_recv_from_file_mgr((PS8) fmgr_p->file_path);
            }
            else
        #endif /* __MMI_VCARD__ */ 
                mmi_phb_fmgr_from_file_mgr((PS8) fmgr_p->file_path);
            break;

        #ifdef __MMI_VCALENDAR__
        case FMGR_ACTION_FWD_TODOLIST:
            /* pass file name to To do list */
            /* hook to do list func */
            mmi_vclndr_fmgr_recv((PS8) fmgr_p->file_path);
            break;
        #endif /* __MMI_VCALENDAR__ */ 
        case FMGR_ACTION_FWD_SMS:
            /* pass file name to SMS */
            /* hook SMS func */
        #ifdef __MMI_VCARD__
            if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_VCF))
            {
                mmi_vcard_fmgr_sms_forward((PS8) fmgr_p->file_path);
                break;
            }
        #endif /* __MMI_VCARD__ */ 
        #ifdef __MMI_VCALENDAR__
            if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_VCS))
            {
                mmi_vclndr_fmgr_sms_forward((PS8) fmgr_p->file_path);
                break;
            }
        #endif /* __MMI_VCALENDAR__ */ 
        #ifdef __MMI_VBOOKMARK__
            if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_URL) || 
            	  FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_VBM))
            {
                mmi_vbkm_fmgr_sms_forward((PS8) fmgr_p->file_path);
                break;
            }
        #endif /* __MMI_VBOOKMARK__ */ 
            break;

        #ifdef __MMI_MESSAGES_EMS__
        case FMGR_ACTION_FWD_EMS:
            /* pass file name to EMS */
            if ((fmgr_p->src_application != APP_FILEMANAGER) &&
                (fmgr_p->src_application != APP_IMAGEVIEWER) && (fmgr_p->src_application != APP_VDOPLY) &&
        #ifdef __MMI_FTC_SUPPORT__
                (fmgr_p->src_application != APP_FTP) &&
        #endif 
        #ifdef __MMI_BIP_SUPPORT__
                (fmgr_p->src_application != APP_BIP) &&
        #endif 
        #ifdef __MMI_RING_COMPOSER__
                (fmgr_p->src_application != APP_RINGTONECOMPOSER) &&
        #endif
                (fmgr_p->sel_type & FMGR_SELECT_BROWSE))
            {
                /* fwd from browser app to transport app: 
                   needs to delete history for browser app and add marker for it */
                fmgr_adjust_history(SCR_FMGR_EXPLORER);
                DeleteScreenIfPresent(SCR_FMGR_EXPLORER);
                fmgr_add_marker_for_app(fmgr_p->src_application);
            }

            /* hook EMS func */
            if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_IMY))
            {
                mmi_ems_fm_send_by_ems((PS8) fmgr_p->file_path, EMS_OBJECT_MY_MELODY_STATE);
            }
            else if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_ANM))
            {
                mmi_ems_fm_send_by_ems((PS8) fmgr_p->file_path, EMS_OBJECT_MY_ANIMATION_STATE);
            }
            else if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_EMS))
            {
                mmi_ems_fm_send_by_ems((PS8) fmgr_p->file_path, EMS_OBJECT_MY_PICTURE_STATE);
            }
            else
            {
                DisplayPopup((PU8) GetString(STR_FMGR_INVALID_EMS_FORMAT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            }
            break;
        #endif /* __MMI_MESSAGES_EMS__ */ 

        #ifdef __MMI_EMAIL__
        case FMGR_ACTION_FWD_EMAIL:
            /* pass file name to Email */
#if 0
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_FTC_SUPPORT__
/* under construction !*/
        #endif 
        #ifdef __MMI_SOUND_RECORDER__
/* under construction !*/
        #endif
        #ifdef __MMI_RING_COMPOSER__
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            /* hook Email func */
            mmi_email_fmgr_send((PS8) fmgr_p->file_path, file_info.is_short);
            break;
        #endif /* __MMI_EMAIL__ */ 

        #ifdef __MMI_MMS__
        case FMGR_ACTION_FWD_MMS:
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_FTC_SUPPORT__
/* under construction !*/
        #endif 
        #ifdef __MMI_BIP_SUPPORT__
/* under construction !*/
        #endif 
        #ifdef __MMI_SOUND_RECORDER__
/* under construction !*/
        #endif
        #ifdef __MMI_RING_COMPOSER__
/* under construction !*/
        #endif
        #ifdef __MMI_FTC_SUPPORT__
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* if 0 */
            /* hook MMS func */
            mms_content_insert_hdlr((PS8) fmgr_p->file_path);
            break;
        #endif /* __MMI_MMS__ */ 

        #ifdef __MMI_IRDA_SUPPORT__
        case FMGR_ACTION_FWD_IRDA:
            if (MMI_IRDA_ERR_SUCCESS == mmi_irda_send_file_obj((PS8) fmgr_p->file_path, mmi_irda_fmgr_forward_to_irda_callback))
            {
                mmi_irda_entry_fmgr_fwd();  /* Renamed by PMT PANKAJ */
            }
            break;
        #endif /* __MMI_IRDA_SUPPORT__ */ 

        #if (defined __MMI_OPP_SUPPORT__) || (defined __MMI_BIP_SUPPORT__)
        case FMGR_ACTION_FWD_BT:
        #if (!defined __MMI_BIP_SUPPORT__)
            
            if (MMI_OPP_ERR_SUCCESS == mmi_opp_discovery_device((PS8) fmgr_p->file_path, mmi_opp_fmgr_forward_to_opp_callback))
            {
                mmi_opp_entry_opp_device_discovery();
            }
        #else
            mmi_bt_send_file_through_BT((PS8) fmgr_p->file_path, NULL);
        #endif
            break;
        #endif /* __MMI_OPP_SUPPORT__ || (defined __MMI_BIP_SUPPORT__) */ 

        default:
            DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_AVAILABLE), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            break;
    }
    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    fmgr_p->tree_action = FMGR_ACTION_NONE;
    DeleteScreenIfPresent(SCR_FMGR_FORWARD_OPTION);
    DeleteScreenIfPresent(SCR_FMGR_DA_FORWARD_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_dummy_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_dummy_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);

    StartTimer(FMGR_SCR_TIMER, 1, GoBackHistory);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_add_marker_for_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_add_marker_for_app(U8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history scr101;
    U16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) scr101.inputBuffer, (PS8) & nHistory);
    scr101.scrnID = FMGR_SCR_MARKER;
    switch (app_id)
    {
    #ifdef __MMI_RING_COMPOSER__
        case APP_RINGTONECOMPOSER:
            scr101.entryFuncPtr = EntryRngcApp;
            break;
    #endif /* __MMI_RING_COMPOSER__ */ 
    #ifdef __MMI_VIDEO_PLAYER__
        case APP_VDOPLY:
            return;
            scr101.entryFuncPtr = mmi_vdoply_entry_app;
            break;
    #endif /* __MMI_VIDEO_PLAYER__ */ 
    #ifdef __MMI_IMAGE_VIEWER__
        case APP_IMAGEVIEWER:
            return;
            scr101.entryFuncPtr = mmi_imgview_entry_app;
            break;
    #endif /* __MMI_IMAGE_VIEWER__ */ 
    #ifdef __MMI_SOUND_RECORDER__
        case APP_SOUNDRECORDER:
            scr101.entryFuncPtr = mmi_sndrec_entry_main;
            break;
    #endif /* __MMI_SOUND_RECORDER__ */ 
    #ifdef __MMI_AB_REPEATER__
        case APP_ABREPEATER:
            scr101.entryFuncPtr = mmi_abrepeat_entry_list;
            break;
    #endif /* __MMI_AB_REPEATER__ */ 
    #if defined(__MMI_IRDA_SUPPORT__) || defined(__MMI_OPP_SUPPORT__) || defined(__MMI_BIP_SUPPORT__)
        case APP_EXTDEVICE:
            scr101.entryFuncPtr = entry_fmgr_explorer;
            break;
    #endif /* defined(__MMI_IRDA_SUPPORT__) || defined(__MMI_OPP_SUPPORT__) */ 
    #ifdef __MMI_FM_RADIO_RECORD__
        case APP_FMRDO:
            scr101.entryFuncPtr = entry_fmgr_explorer;
            break;
    #endif /* __MMI_FM_RADIO_RECORD__ */ 
    #ifdef __MMI_SWFLASH__
        case APP_SWFLASH:
            scr101.entryFuncPtr = entry_fmgr_explorer;
            break;
    #endif /* __MMI_SWFLASH__ */ 
        default:
            scr101.entryFuncPtr = fmgr_dummy_function;
            break;
    }
    AddHistory(scr101);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_select_path_and_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id          [IN]        
 *  sel_type        [IN]        
 *  filter          [IN]        
 *  start_path      [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_select_path_and_enter(U8 app_id, U8 sel_type, FMGR_FILTER filter, PS8 start_path, PsExtFuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_GetDevStatus(start_path[0], FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
    {
        DisplayPopup((PU8) GetString(FMGR_FS_DEVICE_BUSY_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        /* callback(NULL); */
        return;
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_ucs2cmp((PS8) start_path, (PS8) L"root") != 0)
    {
        if (mmi_usb_is_in_mass_storage_mode() 
    #ifndef __USB_IN_NORMAL_MODE_IMPROVE__	
            && mmi_usb_check_path_exported(start_path)
    #endif
            )            
    {
        DisplayPopup((PU8) GetString(STR_ID_USB_MODE_EXPORTED_WARNING), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
        return;
    }
    }
    else
    {
    	  if (fmgr_p->drv_count == 0 && mmi_usb_is_in_mass_storage_mode())
        {
            PRINT_INFORMATION("No Drive\n");
            DisplayPopup((PU8) GetString(STR_ID_USB_MODE_EXPORTED_WARNING), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
        #if defined(OBIGO_Q03C)
            if (app_id == APP_WAP)
            {
                /* Since WAP APP design property, should notify it to abort this operation. */
                fmgr_p->app_callback = callback;
                fmgr_abort_app_select();
            }
        #endif /* #if defined(OBIGO_Q03C) */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (fmgr_p->src_application == APP_FILEMANAGER
#ifdef __MMI_MY_FAVORITE__
        || fmgr_p->src_application == APP_MYFAVORITE
    #endif /* #ifdef __MMI_MY_FAVORITE__*/
		)
    {
        fmgr_adjust_history(SCR_FMGR_MAIN);
    }
    else
    {
        fmgr_remove_all_screen();

        /* when non-imageviewer app re_entering filemgr, delete imageviewer related screen */
    #ifdef __MMI_IMAGE_VIEWER__
        mmi_imgview_remove_screen_if_present(app_id);
    #endif 
    #ifdef __MMI_SLIDESHOW__
        /* when re_entering filemgr, delete slidshow related screen if the app is not slideshow */
        mmi_slidshow_exit_display_screens(app_id);
    #endif  /* __MMI_SLIDESHOW__ */
    }

#ifdef __MMI_DOWNLOAD_AGENT__
    memset(fmgr_p->da_file_path, 0, sizeof(fmgr_p->da_file_path));
#endif 

    /* for other application to enter file manager with a starting path */
    fmgr_p->src_application = app_id;
    fmgr_p->sel_type = sel_type;
    fmgr_p->app_callback = callback;
    fmgr_p->filter_type = filter;
    fmgr_p->tree_action = FMGR_ACTION_NONE;
    fmgr_p->cur_index = 0;
    fmgr_p->cache_end_idx = 0;
    fmgr_p->cache_start_idx = 0;

    memset((PU8) fmgr_p->file_cache, 0, sizeof(FMGR_FILE_INFO_STRUCT) * FMGR_CACHE_ENTRY_COUNT);
    memset(fmgr_p->parent_idx_hash_table, 0, sizeof(fmgr_p->parent_idx_hash_table));

#if 0 
#if defined(MT6223P)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MT6223P */
#endif /* if 0 */

    switch (app_id)
    {
        default:
        {
            BOOL add_marker = TRUE;

            fmgr_p->active_explorer_screen = SCR_FMGR_EXPLORER;

            /* init FMGR */
            if (mmi_ucs2cmp((PS8) start_path, (PS8) L"root") == 0)
            {
		        DeleteScreenIfPresent(SCR_FMGR_MAIN);
                entry_fmgr_main();
            }
            else
            {
                mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) start_path);
                entry_fmgr_explorer();
            }
            /* don't add marker after abort */
            if ( (app_id == fmgr_p->src_application) && (fmgr_p->src_application != APP_MYFAVORITE) &&
            	 add_marker == TRUE &&
                (sel_type &
                 (FMGR_SELECT_FILE | FMGR_SELECT_FILE_SET | FMGR_SELECT_FOLDER | FMGR_SELECT_FILE_OR_FOLDER)))
            {
                fmgr_add_marker_for_app(app_id);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_return_to_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_return_to_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_p->sel_type == FMGR_SELECT_FOLDER && fmgr_p->file_path[0] == MMI_CARD_DRV)
    {
        FS_DiskInfo disk_info;
        U8 path[10];

        /* check write protection */
        kal_wsprintf((PU16) path, "%c:\\", fmgr_p->file_path[0]);
        FS_GetDiskInfo((PU16) path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        if (disk_info.WriteProtect)
        {
            DisplayPopup((PU8) GetString(FMGR_FS_WRITE_PROTECTION_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            /* DeleteScreenIfPresent(SCR_FMGR_FOLDER_OPTION); */
            fmgr_abort_app_select();
            return;
        }
    }

    /* return from drive option menu => select drive, no need to get file info */
    memset(&file_info, 0, sizeof(FMGR_FILE_INFO_STRUCT));
    if (GetExitScrnID() != SCR_FMGR_DRIVE_OPTION)
    {
        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
    }

#ifdef __DRM_SUPPORT__
    if ((fmgr_p->sel_type & FMGR_SELECT_FILE) &&
        mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == TRUE
#ifndef __MMI_SHOW_FILE_EXT__
        && mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == TRUE
#endif 
        )
    {
        S32 result;

        result = fmgr_select_drm_file();
        if (result < FS_NO_ERROR)
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(result)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            return;
        }
        else if (result == FALSE)
        {
            if (fmgr_p->sel_type & FMGR_SELECT_REPEAT)
            {
                DisplayPopup((U8*) GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
            }
            else
            {
                DisplayPopupCallBack((U8*) GetString(STR_GLOBAL_DRM_PROHIBITED), 
                                     IMG_GLOBAL_WARNING, 
                                     1,
                                     1000, 
                                     WARNING_TONE, 
                                     fmgr_abort_app_select);

                /* DeleteScreenIfPresent(SCR_FMGR_FILE_OPTION); */
            }
            return;
        }
    }
#endif /* __DRM_SUPPORT__ */ 

#ifdef __SYNCML_SUPPORT__
    if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_VCF)||
        FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_VCS))
    {
        if (mmi_syncml_is_phb_sync_now())
        {
            if (fmgr_p->sel_type & FMGR_SELECT_REPEAT)
            {
                DisplayPopup((U8*) GetString(STR_ID_SYNC_PLEASE_WAIT), IMG_GLOBAL_WARNING, 0, 1000, ERROR_TONE);
            }
            else
            {
                DisplayPopupCallBack((U8*) GetString(STR_ID_SYNC_PLEASE_WAIT), 
                                     IMG_GLOBAL_WARNING, 
                                     1,
                                     1000, 
                                     ERROR_TONE, 
                                     fmgr_abort_app_select);
            }
            return;
        }
    }
#endif /* __SYNCML_SUPPORT__ */

    mmi_fmgr_stop_decode();

    if (GetExitScrnID() != SCR_FMGR_DRIVE_OPTION)
    {
        S32 len;

        len = mmi_ucs2strlen((PS8)fmgr_p->file_path)
            + mmi_ucs2strlen((PS8)file_info.file_name);
        if(file_info.attribute & FS_ATTR_DIR)
            len ++;
    #ifndef __MMI_SHOW_FILE_EXT__
        else
            len += mmi_ucs2strlen((PS8)file_info.file_ext);
    #endif

        if(len > FMGR_MAX_PATH_LEN)
        {
//            MMI_TRACE(MMI_COMMON_TRC_G1_FMGR, TRC_MMI_FMGR_APPEND_FILE_NAME_TOO_LONG);

            if (fmgr_p->sel_type & FMGR_SELECT_REPEAT)
            {
                DisplayPopup((U8*) GetString(FMGR_FS_PATH_OVER_LEN_ERROR_TEXT), 
                                 IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            }
            else
            {
                DisplayPopupCallBack((U8*) GetString(FMGR_FS_PATH_OVER_LEN_ERROR_TEXT), 
                                 IMG_GLOBAL_ERROR, 
                                 1,
                                 1000, 
                                 ERROR_TONE, 
                                 fmgr_abort_app_select);
            }
            return;
        }
    
        /* pass path back to other application */
        if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE)
        {
            ASSERT(0);
        }
        if ((file_info.attribute & FS_ATTR_DIR) &&
            mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) L"\\") == FALSE)
        {
            ASSERT(0);
        }
    #ifndef __MMI_SHOW_FILE_EXT__
        else
        {
            if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE)
            {
                ASSERT(0);
            }
        }
    #endif /* __MMI_SHOW_FILE_EXT__ */ 
    
        fmgr_p->app_callback((PU16) fmgr_p->file_path, file_info.is_short);
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);        
    }
    else
    {
        fmgr_p->app_callback((PU16) fmgr_p->file_path, file_info.is_short);
    }

    DeleteScreenIfPresent(SCR_FMGR_FOLDER_OPTION);
    if ((fmgr_p->sel_type & FMGR_SELECT_REPEAT) == 0)
    {
        DeleteUptoScrID(FMGR_SCR_MARKER);
        DeleteScreenIfPresent(FMGR_SCR_MARKER);
        fmgr_reset_app_select();
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_abort_app_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_abort_app_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_p->app_callback)
    {
        //if ((fmgr_p->sel_type & FMGR_SELECT_REPEAT)==0)
        //{
            DeleteUptoScrID(FMGR_SCR_MARKER);
            DeleteScreenIfPresent(FMGR_SCR_MARKER);
        //}
        fmgr_p->app_callback(NULL, 0);
        fmgr_reset_app_select();
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_reset_app_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_reset_app_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* de-init FMGR */

    if (fmgr_p->sel_type & FMGR_SELECT_REPEAT)
    {
        DeleteUptoScrID(FMGR_SCR_MARKER);
        DeleteScreenIfPresent(FMGR_SCR_MARKER);
    }

    fmgr_p->src_application = APP_FILEMANAGER;
    fmgr_p->sel_type = 0;
    fmgr_p->app_callback = NULL;
    FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
    fmgr_p->cache_end_idx = 0;
    fmgr_p->cache_start_idx = 0;
    fmgr_p->cur_index = 0;
    memset((PU8) fmgr_p->file_path, 0, sizeof(fmgr_p->file_path));
    memset((PU8) fmgr_p->file_cache, 0, sizeof(FMGR_FILE_INFO_STRUCT) * FMGR_CACHE_ENTRY_COUNT);

}


/*****************************************************************************
 * FUNCTION
 *  fmgr_exe_app_call_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL fmgr_exe_app_call_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
#if defined(__DRM_V02__)  
    S32 file_type = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* return from drive option menu => select drive, no need to get file info */
    if (GetExitScrnID() != SCR_FMGR_DRIVE_OPTION)
    {
        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
    }

#ifdef __DRM_SUPPORT__
    if ((fmgr_p->sel_type & FMGR_SELECT_FILE) &&
        mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == TRUE
#ifndef __MMI_SHOW_FILE_EXT__
        && mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == TRUE
#endif 
        )
    {
        S32 result;

        result = fmgr_select_drm_file();
        if (result < FS_NO_ERROR)
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(result)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        }
        else if (result == FALSE)
        {
            DisplayPopup((U8*) GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
            if (!(fmgr_p->sel_type & FMGR_SELECT_REPEAT))
            {
                fmgr_abort_app_select();
            }
            return FALSE;
        }
    }
#endif /* __DRM_SUPPORT__ */ 

    DeleteUptoScrID(FMGR_SCR_MARKER);
    DeleteScreenIfPresent(FMGR_SCR_MARKER);

    if (GetExitScrnID() != SCR_FMGR_DRIVE_OPTION)
    {
        pBOOL exceed = FALSE;
        
        /* pass path back to other application */
        if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE)
        {
            exceed = TRUE;
        }
        if ((file_info.attribute & FS_ATTR_DIR) &&
            mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) L"\\") == FALSE)
        {
            exceed = TRUE;
        }
    #ifndef __MMI_SHOW_FILE_EXT__
        else
        {
            if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE)
            {
                exceed = TRUE;
            }
        }
    #endif /* __MMI_SHOW_FILE_EXT__ */ 

    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifndef __MMI_SHOW_FILE_EXT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SHOW_FILE_EXT__ */ 
#endif /* if 0 */

        fmgr_p->app_callback((PU16) fmgr_p->file_path, file_info.is_short);

    #if defined(__DRM_V02__)  
        file_type = mmi_fmgr_get_drm_file_type_by_path((PS8) fmgr_p->file_path, &file_info.file_type);
    #endif

    #if defined(__DRM_V02__)
        if (fmgr_p->src_application != APP_FILEMANAGER 
            && ( DRM_is_archive(0, (PU16)fmgr_p->file_path) && file_type != FMGR_TYPE_ODF)
        )
        {
            /* if in multi part odf, remove the last object name, 
               to keep the file_path validate */
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
        }
    #else
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    #endif /* __DRM_V02__ */
    }
    else
    {
        fmgr_p->app_callback((PU16) fmgr_p->file_path, file_info.is_short);
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_adjust_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  marker      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_adjust_history(S32 marker)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrnId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (marker == 0)
    {
        /* delete all fmgr screens in history and return to other app */
        if (DeleteUptoScrID(SCR_FMGR_MAIN) == ST_FAILURE)
        {
            DeleteUptoScrID(fmgr_p->active_explorer_screen);
        }
        /* fmgr_return_to_app(); */
        return;
    }

    scrnId = GetCurrScrnId();
    if (scrnId > FMGR_SCR_BASE && scrnId < FMGR_SCR_END)
    {
        DeleteUptoScrID((U16) marker);
    }
    else
    {
        for (scrnId = FMGR_SCR_BASE; scrnId <= FMGR_SCR_MARKER; scrnId++)
            if (scrnId != SCR_FMGR_MAIN)
            {
                DeleteScreenIfPresent(scrnId);
            }
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_remove_all_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_remove_all_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrnId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (scrnId = FMGR_SCR_BASE; scrnId <= FMGR_SCR_MARKER; scrnId++)
    {
        DeleteScreenIfPresent(scrnId);
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_set_sort_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sort        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_set_sort_option(U16 sort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmgr_p->sort_option = sort;
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_get_sort_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sort        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_get_sort_option(U16 *sort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *sort = fmgr_p->sort_option;
}

#ifdef __DRM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  fmgr_select_drm_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 fmgr_select_drm_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    BOOL set_as = TRUE;
    BOOL fwd_to = TRUE;
    MMI_BOOL status;
    drm_method_enum method;
    drm_constraint_struct play;
    U8 permission = DRM_PERMISSION_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = DRM_open_file((PU16) fmgr_p->file_path, FS_READ_ONLY, DRM_PERMISSION_NONE);
    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);

    if (handle >= FS_NO_ERROR)
    {
        permission = DRM_get_permission(DRM_get_content_type(handle, NULL), 0);
    
        status = DRM_validate_permission(handle, NULL, permission);
        method = DRM_get_object_method(handle, NULL);
        
        if (method != DRM_METHOD_NONE && status == MMI_TRUE)
        {
            /* DRM file */
            /* DRM file can't be edit */
            if (fmgr_p->src_application == APP_PHOEDT ||
                 fmgr_p->src_application == APP_FMRDO ||
                 fmgr_p->src_application == APP_FMSCHEDULEREC)
            {
            	  DRM_close_file(handle);
                 return FALSE;
            }
            DRM_get_constraint(handle, NULL, permission, &play);
//            DRM_get_constraint(handle, NULL, DRM_PERMISSION_DISPLAY, &display);
            if (method & DRM_METHOD_SEPARATE_DELIVERY)
            {
                if (method & DRM_METHOD_FORWARD_LOCK)
                {
                    fwd_to = FALSE; /* can't forward */
                }
                if (!(status && play.type == DRM_CONSTRAINT_NONE))
                {
                    set_as = FALSE; /* can't set as ringtine wallpaper */
                }
            }
            else if (method & DRM_METHOD_V2)
            {
                if (!(status && play.type == DRM_CONSTRAINT_NONE))
                {
                    set_as = FALSE; /* can't set as ringtine wallpaper */
                }
            }
            else
            {
                fwd_to = FALSE; /* can't forward */
                if (status == DRM_STATUS_RIGHTS_PRESENT && play.type != DRM_CONSTRAINT_NONE)
                {
                    set_as = FALSE; /* can't set as ringtone wallpaper */
                }
            }
            DRM_close_file(handle);
        }
        else if (method != DRM_METHOD_NONE && status == MMI_FALSE)
        {
            set_as = FALSE;
            if (method & DRM_METHOD_SEPARATE_DELIVERY)
            {
                if (method & DRM_METHOD_FORWARD_LOCK)
                {
                    fwd_to = FALSE; /* can't forward */
                }
            }
            else if (!(method & DRM_METHOD_V2))
            {
                fwd_to = FALSE;
            }
            DRM_close_file(handle);
        }
        else
        {
            DRM_close_file(handle);
        }
    }
    else if (handle == FS_ERROR_RESERVED)
    {
        return FALSE;
    }
    else
    {
        /* can't open file */
        return handle;
    }
    if (((fmgr_p->src_application == APP_PROFILES ||
          fmgr_p->src_application == APP_PHONEBOOK ||
          fmgr_p->src_application == APP_SETTINGS ||
          fmgr_p->src_application == APP_BGSOUND ||
          fmgr_p->src_application == APP_SLIDESHOW ||
          (fmgr_p->src_application == APP_EMAIL && fmgr_p->sel_type & FMGR_SELECT_FILE_SET))
         && set_as == FALSE) ||
        ((fmgr_p->src_application == APP_WAP ||
          fmgr_p->src_application == APP_MESSAGES ||
          (fmgr_p->src_application == APP_EMAIL && !(fmgr_p->sel_type & FMGR_SELECT_FILE_SET)) ||
          (fmgr_p->src_application == APP_IMPS && fmgr_p->sel_type & FMGR_SELECT_FILE)) 
          && fwd_to == FALSE))
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_check_drm_rights
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_info       [?]         
 *  permission      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 fmgr_check_drm_rights(FMGR_FILE_INFO_STRUCT *file_info, U8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    S32 ok_flag = FMGR_DRM_GRANT_PERMISSION;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_info != NULL)
    {
        if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info->file_name) == FALSE
    #ifndef __MMI_SHOW_FILE_EXT__
            || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info->file_ext) == FALSE
    #endif 
            )
            return FMGR_DRM_NO_PERMISSION;
    }

    handle = DRM_open_file((PU16) fmgr_p->file_path, FS_READ_ONLY, permission);
    if (handle >= FS_NO_ERROR)
    {
        U8 method = DRM_get_object_method(handle, NULL);
        if (method != DRM_METHOD_NONE)
        {
            /* DRM file */
            if (DRM_validate_permission(handle, NULL, permission) == MMI_FALSE)
            {
                if ((method & DRM_METHOD_SEPARATE_DELIVERY)|| (method & DRM_METHOD_V2))
                {
                    U32 size = sizeof(fmgr_p->rights_issuer);
                    /* request rights from server */
                    ok_flag = FMGR_DRM_REQUEST_RIGHTS;
                    memset(fmgr_p->rights_issuer, 0, sizeof(fmgr_p->rights_issuer));
                    if(FS_NO_ERROR > DRM_get_rights_issuer(handle, fmgr_p->rights_issuer, &size))
                    {
                        ok_flag = FMGR_DRM_NO_PERMISSION;
                    }
                }
                else
                {
                    ok_flag = FMGR_DRM_NO_PERMISSION;
                }
            }
//            else if (file_info == NULL && ( (!(permission & DRM_PERMISSION_EXECUTE)) && (!(permission & DRM_PERMISSION_PLAY))))
//            {
//                /* show thumbnail won't consume rights */
//                /* java will be consumed when play, not install */
//                DRM_consume_rights(handle, permission, NULL);
//            }
        }
        DRM_close_file(handle);
    }
    else
    {
        /* return error code */
        ok_flag = handle;
    }

    if (file_info != NULL)
    {
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    }

    return ok_flag;
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_check_drm_forward
 * DESCRIPTION
 *  get forward rule of input file path
 * PARAMETERS
 *  file_path       [IN]        
 *  is_drm          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
U8 fmgr_check_drm_forward(PS8 file_path, BOOL *is_drm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    U8 fwd_flag = FMGR_DRM_FWD_APP_FWD_OUT;
    U8 permission = DRM_PERMISSION_NONE;
    U8 method = DRM_METHOD_NONE;
    FMGR_FILTER file_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = DRM_open_file((PU16) file_path, FS_READ_ONLY, DRM_PERMISSION_NONE);
    if (handle > FS_NO_ERROR)
    {
        if ((method = DRM_get_object_method(handle, NULL)) != DRM_METHOD_NONE)
        {
            if (is_drm != NULL)
            {
                *is_drm = TRUE;
            }

            mmi_fmgr_get_file_type(file_path, &file_type);

            permission = DRM_get_permission(DRM_get_content_type(handle, NULL), 0);

            if (method & DRM_METHOD_SEPARATE_DELIVERY)
            {
                if (DRM_validate_permission(handle, NULL, permission))
                {
                    drm_constraint_struct play; //, display;
                    
                    DRM_get_constraint(handle, NULL, permission, &play);
                    //DRM_get_constraint(handle, NULL, DRM_PERMISSION_DISPLAY, &display);

                    if (method & DRM_METHOD_FORWARD_LOCK)
                    {
                        if (play.type == DRM_CONSTRAINT_NONE)
                        {
                            fwd_flag = FMGR_DRM_FWD_APP_NO_FWD_OUT;      /* can forward, can't set as ringtine wallpaper */
                        }
                        else
                        {
                            fwd_flag = FMGR_DRM_NO_FWD_APP_NO_FWD_OUT; 
                        }
                    }
                    else
                    {
                        if (play.type == DRM_CONSTRAINT_NONE)
                        {
                            fwd_flag = FMGR_DRM_FWD_APP_FWD_OUT; /* can forward, can't set as ringtone wallpaper */
                        }
                        else
                        {
                            fwd_flag = FMGR_DRM_NO_FWD_APP_FWD_OUT; /* can forward, can't set as ringtone wallpaper */
                        }
                    }
                }
                else
                {
                    if (method & DRM_METHOD_FORWARD_LOCK)
                    {
                        fwd_flag = FMGR_DRM_NO_FWD_APP_NO_FWD_OUT;
                    }
                    else
                    {
                        fwd_flag = FMGR_DRM_NO_FWD_APP_FWD_OUT;
                    }
                }
            }
        #if defined(__DRM_V02__)
            else if (method & DRM_METHOD_V2)
            {
                if (DRM_validate_permission(handle, NULL, permission))
                {
                    drm_constraint_struct play;//, display;
                    
                    DRM_get_constraint(handle, NULL, permission, &play);
//                    DRM_get_constraint(handle, NULL, DRM_PERMISSION_DISPLAY, &display);

                    if (play.type == DRM_CONSTRAINT_NONE)
                    {
                        if (DRM_is_archive(handle, NULL) && (!FMGR_FILTER_IS_SET(&file_type, FMGR_TYPE_ODF)))
                        {
                            fwd_flag = FMGR_DRM_FWD_APP_NO_FWD_OUT; /* not an archieve */
                        }
                        else
                        {
                            fwd_flag = FMGR_DRM_FWD_APP_FWD_OUT; /* can forward, can't set as ringtone wallpaper */
                        }
                    }
                    else
                    {
                        if (DRM_is_archive(handle, NULL) && (!FMGR_FILTER_IS_SET(&file_type, FMGR_TYPE_ODF)))
                        {
                            fwd_flag = FMGR_DRM_NO_FWD_APP_NO_FWD_OUT;
                        }
                        else
                        {
                            fwd_flag = FMGR_DRM_NO_FWD_APP_FWD_OUT;
                        }
                    }
                }
                else
                {
                    if (DRM_is_archive(handle, NULL) && (!FMGR_FILTER_IS_SET(&file_type, FMGR_TYPE_ODF)))
                    {
                        fwd_flag = FMGR_DRM_NO_FWD_APP_NO_FWD_OUT;
                    }
                    else
                    {
 		        fwd_flag = FMGR_DRM_NO_FWD_APP_FWD_OUT;
                    }
                }
            }
        #endif /* #if defined(__DRM_V02__) */
            else if (method & DRM_METHOD_COMBINED_DELIVERY)
            {
                if (DRM_validate_permission(handle, NULL, permission))
                {
                    drm_constraint_struct play; //, display;
                   
                    DRM_get_constraint(handle, NULL, permission, &play);
                    //DRM_get_constraint(handle, NULL, DRM_PERMISSION_DISPLAY, &display);

                    if (play.type == DRM_CONSTRAINT_NONE)
                    {
                        fwd_flag = FMGR_DRM_FWD_APP_NO_FWD_OUT; /* can't forward, can set as ringtone wallpaper */
                    }
                    else
                    {
                        fwd_flag = FMGR_DRM_NO_FWD_APP_NO_FWD_OUT; /* can't forward, can set as ringtone wallpaper */
                    }
                }
                else
                {
                    fwd_flag = FMGR_DRM_NO_FWD_APP_NO_FWD_OUT;  /* can't forward, can't set as ringtine wallpaper */
                }
            }
            else
            {
                if (DRM_validate_permission(handle, NULL, permission))
                {
                    drm_constraint_struct play;
                   
                    DRM_get_constraint(handle, NULL, permission, &play);
                    //DRM_get_constraint(handle, NULL, DRM_PERMISSION_DISPLAY, &display);

                    if (play.type == DRM_CONSTRAINT_NONE)
                    {
                        fwd_flag = FMGR_DRM_FWD_APP_NO_FWD_OUT; /* can't forward, can set as ringtone wallpaper */
            }
                    else
                    {
                        fwd_flag = FMGR_DRM_NO_FWD_APP_NO_FWD_OUT; /* can't forward, can set as ringtone wallpaper */
                    }
                }
                else
                {
                
                    fwd_flag = FMGR_DRM_NO_FWD_APP_NO_FWD_OUT;  /* can't forward, can't set as ringtine wallpaper */
                }
            }
        }
        /* non DRM file, can forward to anywhere */
        DRM_close_file(handle);
    }
    else
    {
        /* open file fail */
        fwd_flag = FMGR_DRM_NO_FWD_APP_NO_FWD_OUT;
        /* CD or FL without right */
        //if (handle == FS_ERROR_RESERVED && is_drm != NULL)
	if ((handle < FS_MINIMUM_ERROR_CODE) && is_drm != NULL)
        {
            *is_drm = TRUE;
        }
    }

    /* If in flight mode, not allow to forward out */
    if (mmi_bootup_get_active_flight_mode()==MMI_TRUE)
    {
        if (fwd_flag == FMGR_DRM_NO_FWD_APP_FWD_OUT )
        {
            fwd_flag = FMGR_DRM_NO_FWD_APP_NO_FWD_OUT; /* can't forward, can't set as ringtone wallpaper */
        }
        else if (fwd_flag == FMGR_DRM_FWD_APP_FWD_OUT)
        {
            fwd_flag = FMGR_DRM_FWD_APP_NO_FWD_OUT; /* can't forward, can set as ringtone wallpaper */
        }
    }    

    return fwd_flag;
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_get_drm_forward_rule
 * DESCRIPTION
 *  get forward rule of highlighted file
 * PARAMETERS
 *  file_info       [?]     
 *  is_drm          [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 fmgr_get_drm_forward_rule(FMGR_FILE_INFO_STRUCT *file_info, BOOL *is_drm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 fwd_flag = FMGR_DRM_NO_FWD_APP_NO_FWD_OUT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_drm != NULL)
    {
        *is_drm = FALSE;
    }
    if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info->file_name) == TRUE
#ifndef __MMI_SHOW_FILE_EXT__
        && mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info->file_ext) == TRUE
#endif 
        )
    {
        fwd_flag = fmgr_check_drm_forward(fmgr_p->file_path, is_drm);
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    }
    return fwd_flag;
}


/*****************************************************************************
 * FUNCTION
 *  entry_fmgr_request_rights_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_fmgr_request_rights_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_is_network_services_available() == MMI_FALSE
#ifdef __FLIGHT_MODE_SUPPORT__
        || mmi_bootup_get_active_flight_mode() != 0
#endif 
        )
    {
    	  DisplayPopup((PU8) GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
        return;
    }
    
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU16) GetString(STR_FMGR_REQ_RIGHTS),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    DeleteScreenIfPresent(SCR_FMGR_DETAIL);
    /*DeleteScreenIfPresent(SCR_FMGR_FILE_OPTION);*/
    SetLeftSoftkeyFunction(fmgr_send_rights_request_ext, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __FLIGHT_MODE_SUPPORT__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  fmgr_send_rights_request
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_send_rights_request(void)
{
#ifdef WAP_SUPPORT	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[MAX_LINE_LENGTH * ENCODING_LENGTH] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_ucs2(temp, fmgr_p->rights_issuer, strlen((const char *)fmgr_p->rights_issuer));
    wap_start_browser(WAP_BROWSER_GOTO_URL, (const kal_uint8*)temp);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_send_rights_request_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_send_rights_request_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_V02__
    {
        FMGR_FILE_INFO_STRUCT file_info;

    #ifdef __MMI_DOWNLOAD_AGENT__
        /* download agent file + check if in a multipart odf */
        if (fmgr_is_da_file() && !(IsScreenPresent(SCR_FMGR_MUL_ODF_EXPLORER)))
        {
            mmi_fmgr_get_file_type((PS8) fmgr_p->da_file_path, &file_info.file_type);
            mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->da_file_path);
        }
        /* non download agent file */
        else
    #endif /* __MMI_DOWNLOAD_AGENT__ */ 
    	  {
            mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

            if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
    #ifndef __MMI_SHOW_FILE_EXT__
                && mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
    #endif
             )
            {
                return;
            }
        }
        mmi_drm_activate_file(fmgr_p->file_path);

	mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
    }
#else /* __DRM_V02__ */

    fmgr_send_rights_request();

#endif /* __DRM_V02__ */
}

#endif /* __DRM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  fmgr_check_file_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 fmgr_check_file_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    S8 temp[FMGR_MAX_FILE_LEN * ENCODING_LENGTH] = {0};
    FS_HANDLE handle;
    S32 fs_ret;
    U16 index;
    U8 flag = FMGR_NOT_EXIST;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__DRM_V02__)
    if (mmi_ucs2ncmp((PS8)fmgr_p->file_path + ((mmi_ucs2strlen((PS8)fmgr_p->file_path)-4)<<1), (PS8)L".odf", 4) == 0)
    {
        flag = FMGR_FILE;
    }
    else
#endif /* defined(__DRM_V02__) */
    {
        index = mmi_ucs2strlen((PS8) fmgr_p->file_path) * 2;
        memset((PS8) fmgr_p->file_path + index, 0, FMGR_MAX_PATH_LEN * ENCODING_LENGTH - index);

        fs_ret = FS_SetCurrentDir((PU16) fmgr_p->file_path);

        if (fs_ret < 0)
        {
            handle = fs_ret;
        }
        else
        {
            mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

            if (file_info.attribute & FS_ATTR_DIR)
            {
                /* is folder */
    //            handle = FS_Open((PU16) file_info.file_name, FS_OPEN_DIR | FS_READ_ONLY);
                handle = FS_GetAttributes((PU16) file_info.file_name);

                flag = FMGR_FOLDER;
            }
            else
            {
                /* is file */
                mmi_ucs2cpy((PS8) temp, (PS8) file_info.file_name);
            #ifndef __MMI_SHOW_FILE_EXT__
                mmi_ucs2cat((PS8) temp, (PS8) file_info.file_ext);
            #endif 
    //            handle = FS_Open((PU16) temp, FS_READ_ONLY);
                handle = FS_GetAttributes((PU16) temp);
                flag = FMGR_FILE;
            }
        }
        
        {
            // SetCurrentDir back to root dir
            S8 buf[4*ENCODING_LENGTH];
            mmi_ucs2ncpy((S8*)buf, (S8*)fmgr_p->file_path, 3);
            FS_SetCurrentDir((PU16) buf);
        }

        if (handle < 0)
        {
            mmi_ucs2_to_asc((PS8) nPrintableStr, (PS8) temp);
            PRINT_INFORMATION("check file present: %d, %s", nPrintableStr);

            flag = FMGR_NOT_EXIST;
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            /* go back to root, reload file manager */
            if (fmgr_p->src_application == APP_FILEMANAGER)
            {
                if (handle==FS_ACCESS_DENIED)
                {
                    DeleteUptoScrID(SCR_FMGR_EXPLORER);
                }
                else
	        {
                    fmgr_adjust_history(SCR_FMGR_MAIN);
                }
            }
            else
            {
                fmgr_adjust_history(0);
            }
        }
    }
    return flag;
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_is_parent_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL fmgr_is_parent_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = FS_Open((PU16) fmgr_p->file_path, FS_OPEN_DIR | FS_READ_ONLY);
    mmi_ucs2_to_asc((PS8) nPrintableStr, (PS8) fmgr_p->file_path);

    if (handle > 0)
    {
        FS_Close(handle);
        return TRUE;
    }
    else
    {
        PRINT_INFORMATION("parent not present: %s", nPrintableStr);
        return FALSE;
    }
}

#endif /* __MMI_FILE_MANAGER__ */ 


/*****************************************************************************
 * FUNCTION
 *  fmgr_get_app_title_icon_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 fmgr_get_app_title_icon_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 iconId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (fmgr_p->src_application)
    {
    #ifdef __MMI_IMAGE_VIEWER__
        case APP_IMAGEVIEWER:
            iconId = GetRootTitleIcon(MENU_ID_IMGVIEW_APP);
            break;
        case APP_CAMERA:
            iconId = GetRootTitleIcon(MENU_ID_CAMERA_APP);
            break;
    #endif /* __MMI_IMAGE_VIEWER__ */ 
    #ifdef __MMI_RING_COMPOSER__
        case APP_RINGTONECOMPOSER:
            iconId = GetRootTitleIcon(MENU3103_RINGTONE_COMPOSER);
            break;
    #endif /* __MMI_RING_COMPOSER__ */ 

    #ifdef __MMI_PHOTOEDITOR__
        case APP_PHOEDT:
            iconId = GetRootTitleIcon(MENU_ID_PHOEDT_APP);
            break;
    #endif /* __MMI_PHOTOEDITOR__ */ 

    #ifdef __MMI_SOUND_RECORDER__
        case APP_SOUNDRECORDER:
            iconId = GetRootTitleIcon(MENU_ID_SNDREC_MAIN);
            break;
    #endif /* __MMI_SOUND_RECORDER__ */ 
    #ifdef __MMI_AB_REPEATER__
        case APP_ABREPEATER:
            iconId = GetRootTitleIcon(MENU_ID_AB_REPEATER_MAIN);
            break;
    #endif /* __MMI_AB_REPEATER__ */ 
    #ifdef __MMI_AUDIO_PLAYER__
        case APP_AUDIOPLAYER:
            iconId = GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID);
            break;
    #endif /* __MMI_AUDIO_PLAYER__ */ 
    #ifdef __MMI_VIDEO_PLAYER__
        case APP_VDOPLY:
        case APP_VDOREC:
    #ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
            iconId = GetRootTitleIcon(MENU_ID_VDOPLY_APP);
    #else 
            iconId = GetRootTitleIcon(MENU_ID_VDOPLY_APP);
    #endif 
            break;
    #endif /* __MMI_VIDEO_PLAYER__ */ 
    #ifdef __MMI_EMAIL__
        case APP_EMAIL:
            iconId = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);
            break;
    #endif /* __MMI_EMAIL__ */ 
         case APP_WAP:
         case APP_DOWNLOADAGENT:
	     iconId = GetRootTitleIcon(SERVICES_WAP_MENU_ID);
             break;
    #ifdef __MMI_TODOLIST__
        case APP_TODOLIST:
            iconId = GetRootTitleIcon(ORGANIZER_TODOLIST_MENU);
            break;
    #endif /* __MMI_TODOLIST__ */ 

    #if defined(__MMI_IRDA_SUPPORT__) || defined(__MMI_OPP_SUPPORT__) || defined(__MMI_BIP_SUPPORT__)
        case APP_EXTDEVICE:
            iconId = GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID);
            break;
    #endif /* defined(__MMI_IRDA_SUPPORT__) || defined(__MMI_OPP_SUPPORT__) */ 
    #ifdef __MMI_IMPS__
        case APP_IMPS:
            iconId = GetRootTitleIcon(MENU_ID_IMPS_MAIN);
            break;
    #endif /* __MMI_IMPS__ */ 
        case APP_PHONEBOOK:
            iconId = GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID);
            break;
        case APP_SETTINGS:
            iconId = GetRootTitleIcon(MAIN_MENU_SETTINGS_MENUID);
            break;
        case APP_MESSAGES:
            iconId = GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID);
            break;
        case APP_PROFILES:
            iconId = GetRootTitleIcon(MAIN_MENU_PROFILES_MENUID);
            break;
        case APP_FILEMANAGER:
            iconId = GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID);
            break;
    #ifdef __MMI_FTS_SUPPORT__
        case APP_FTP:
            iconId = GetRootTitleIcon(MENU_CONN_FTP_SETTING);
            break;
    #endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_BIP_SUPPORT__
        case APP_BIP:
            iconId = GetRootTitleIcon(MENU_CONN_BIP_SETTING);
            break;
#endif /* __MMI_BIP_SUPPORT__ */ 
    #ifdef __MMI_EBOOK_READER__
        case APP_EBOOK:
            iconId = GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID);
            break;
    #endif /* __MMI_EBOOK_READER__ */ 
    #ifdef __MMI_MY_FAVORITE__
        case APP_MYFAVORITE:
        {
            if(!mmi_my_favorite_get_folder_resource((PS8)fmgr_p->file_path, NULL, &iconId))
            {
                ASSERT(0);
            }
            break;
        }
    #endif /* __MMI_MY_FAVORITE__ */
    #ifdef __MMI_VIDEO_EDITOR__
        case APP_VDOEDT:
            iconId = GetRootTitleIcon (MENU_ID_VDOEDT_APP);
            break;
    #endif /* __MMI_VIDEO_EDITOR__*/ 
    #ifdef __MMI_FM_RADIO__
        case APP_FMRDO:
            iconId = GetRootTitleIcon(MENU_ID_FMRDO_MAIN);
            break;
    #endif /* __MMI_FM_RADIO__ */
    #ifdef __MMI_FM_RADIO_SCHEDULE_REC__
        case APP_FMSCHEDULEREC:
            iconId = GetRootTitleIcon(MENU_ID_FMSR_MAIN);
            break;
    #endif /* __MMI_FM_RADIO_SCHEDULE_REC__ */
    #ifdef __MMI_SLIDESHOW__
        case APP_SLIDESHOW:
               iconId = GetRootTitleIcon(MENU_ID_SLIDSHOW_APP);
               break;
    #endif /* __MMI_SLIDESHOW__ */
    #ifdef __J2ME__
        case APP_JAVA:
               iconId = mmi_java_get_title_icon();
               break;
    #endif
    #ifdef __MMI_BARCODEREADER__
        case APP_BARCODEREADER:
            iconId = GetRootTitleIcon(MENU_ID_BARCODEREADER_APP);
            break;
    #endif /* __MMI_BARCODEREADER__ */ 
    #ifdef __MMI_GAME__
        case APP_GAMES:
            iconId = GetRootTitleIcon(MENU_ID_MOTION_APP);
            break;
    #endif /* __MMI_GAME__ */ 
    #if defined(__MMI_LANGLN__)    
        case APP_LANGLN:
            iconId = GetRootTitleIcon(MENU_ID_LANGLN);
            break;
    #endif /* defined(__MMI_LANGLN__) */
    #ifdef __MMI_BG_SOUND_EFFECT__
        case APP_BGSOUND:
        #ifdef __UCM_SUPPORT__ 
            iconId = GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING);
        #else
            iconId = GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT);
        #endif
            break;
    #endif /* __MMI_BG_SOUND_EFFECT__ */
    #if defined(JATAAYU_SUPPORT) && defined(MMS_SUPPORT)
        case APP_JATAAYU_MMS:
            iconId = GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID);
            break;
    #endif
    #ifdef __MMI_RMGR__
        case APP_RMGR:
            iconId = GetRootTitleIcon(MENU_ID_RMGR);
            break;
    #endif /* __MMI_RMGR__ */
        default:
            iconId = 0;
            break;
    }
    return iconId;
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_is_msdc_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 fmgr_is_msdc_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U8 count = 0, i;

    for (i = FMGR_REMOVABLE_STORAGE; i < FMGR_TOTAL_STORAGE; i++)
    {
        if (FS_GetDevStatus(fmgr_p->drv_list[i][0], FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
        {
        #if defined(MT6223P)
            if (FS_GetDevStatus(fmgr_p->drv_list[i][0],  FS_CARD_BATCHCOUNT_STATE_ENUM)==FS_NO_ERROR)
        #endif
            {
                count++;
            }
        }
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_get_msdc_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 fmgr_get_msdc_mask(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U8 count = 0, i;

    for (i = FMGR_REMOVABLE_STORAGE; i < FMGR_TOTAL_STORAGE; i++)
    {
        if (FS_GetDevStatus(fmgr_p->drv_list[i][0], FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
        {
            count |= (0x01 << (i - FMGR_REMOVABLE_STORAGE));
        }
    }
    return count;
}

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_activate_theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_activate_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fmgr_Activate_theme, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_Activate_theme, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_Activate_theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_Activate_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Changes for Themes download through WAP */
#define THEME_PATH_LEN 30
    U8 theme_activated = 0;
    PS8 theme_file_name;
    S8 theme_path[THEME_PATH_LEN];  /* FMGR_DEFAULT_FOLDER_THEMES * 2(unicode) len plus 4 */
     FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOAD_AGENT__
    /* download agent file */
    if (fmgr_is_da_file())
    {
        FS_HANDLE handle;

        /* Check if file exists or not */
        handle = FS_Open((PU16) fmgr_p->da_file_path, FS_READ_ONLY);
        if (handle > FS_NO_ERROR)
        {
        	FS_Close(handle);
        }
        else
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION);
            return;
        }
        
        mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->da_file_path);

    #if defined(__DRM_V02__)        
        {
            S32 file_type = 0;
 
        file_type = mmi_fmgr_get_drm_file_type_by_path((PS8) fmgr_p->file_path, &file_info.file_type);
            
        if (file_type == FMGR_TYPE_ODF)
        {
            /* multi part ODF */
            mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
    
            if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
        #ifndef __MMI_SHOW_FILE_EXT__
                || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
        #endif 
                )
                return;
        }
        }
     #else   
         mmi_fmgr_get_file_type((PS8) fmgr_p->da_file_path, &file_info.file_type);
     #endif /* defined(__DRM_V02__) */
        file_info.is_short = FALSE;
        
        memset(theme_path, 0, THEME_PATH_LEN);
        theme_file_name = mmi_fmgr_extract_file_name((PS8) fmgr_p->file_path);
        memcpy(theme_path, fmgr_p->file_path, (S32) theme_file_name - (S32) fmgr_p->file_path);
        theme_activated = mmi_activatetheme_frmfilemanager((PS8) theme_path, (PS8) theme_file_name , FALSE );
        //theme_activated = mmi_activatetheme_frmfilemanager((PS8) theme_path, (PS8) theme_file_name);
    }
    /* non download agent file */
    else
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
    {
    if (fmgr_check_file_present() < FMGR_NO_ERROR)
    {
        return;
    }
        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
        theme_activated = mmi_activatetheme_frmfilemanager(fmgr_p->file_path, (PS8) file_info.file_name, file_info.is_short);
        //theme_activated = mmi_activatetheme_frmfilemanager(fmgr_p->file_path, (PS8) file_info.file_name);
    }

    switch (theme_activated)
    {
        case 0:
            fmgr_display_themepopUp();
            break;
        case 1:
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_display_themepopUp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_display_themepopUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_FMGR_THEME_INCORRECT_LOCATION),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(fmgr_move_theme_file, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_move_theme_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_move_theme_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char name[20];
    FMGR_FILE_INFO_STRUCT file_info;
    S32 create_result;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) name, (PS8) FMGR_DEFAULT_FOLDER_THEMES);

    fmgr_p->tree_action = FMGR_ACTION_MOVE;
    if (fmgr_check_file_present() < FMGR_NO_ERROR)
    {
        fmgr_p->enter_folder = FALSE;
        FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
        fmgr_p->tree_action = FMGR_ACTION_NONE;
        return;
    }

    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

    mmi_ucs2cat((PS8) fmgr_p->file_path, (PS8) file_info.file_name);
#ifndef __MMI_SHOW_FILE_EXT__
    mmi_ucs2cat((PS8) fmgr_p->file_path, (PS8) file_info.file_ext);
#endif 

    mmi_ucs2cpy((PS8) fmgr_p->old_file_path, (PS8) fmgr_p->file_path);

    /* short file name src file should be renamed to long file name */
    if (file_info.is_short == TRUE)
    {
        PS8 temp, temp1;

        temp = mmi_fmgr_extract_file_name((PS8) fmgr_p->file_path);
        temp1 = mmi_fmgr_extract_file_name((PS8) fmgr_p->old_file_path);
        mmi_chset_mixed_text_to_ucs2_str(
            (U8*) temp1,
            (MAX_SUBMENU_CHARACTERS - 1) * ENCODING_LENGTH,
            (U8*) temp,
            PhnsetGetDefEncodingType());
        FS_Rename((PU16) fmgr_p->file_path, (PU16) fmgr_p->old_file_path);
    }
    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);

    while (mmi_ucs2strlen((PS8) fmgr_p->file_path) >= 3)
    {

        if (mmi_ucs2strlen((PS8) fmgr_p->file_path) == 3)
        {

            break;
        }
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);

    }

    mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, name);

    file_handle = FS_Open((kal_uint16*) fmgr_p->file_path, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        create_result = 0;
    }
    else
    {
        create_result = FS_CreateDir((PU16) fmgr_p->file_path);

        if (create_result < FS_NO_ERROR)
        {
            DisplayPopup((PU8)GetString(GetFileSystemErrorString(create_result)),
                     IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
	    fmgr_p->tree_action = FMGR_ACTION_NONE;
            mmi_ucs2cpy((S8*) fmgr_p->file_path, (S8*) fmgr_p->old_file_path);
            mmi_fmgr_remove_last_dir((PS8)fmgr_p->file_path);
            return ;
        }
        
        mmi_ucs2cpy((PS8) gtheme_folder_path, (PS8) fmgr_p->file_path);
        g_istheme_folder_created = TRUE;
    }

    if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == TRUE)
    {
        /* mmi_fmgr_append_file_name((PS8)fmgr_p->file_path, (PS8)file_info.file_ext); */
        
        if (file_info.is_short)
        {
            U8 temp[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];
            PS8 temp1;

            temp1 = mmi_fmgr_extract_file_name((PS8) fmgr_p->file_path);
            mmi_ucs2cpy((S8*) temp, (S8*) temp1);
            
            mmi_chset_mixed_text_to_ucs2_str(
                (U8*) temp1,
                (MAX_SUBMENU_CHARACTERS - 1) * ENCODING_LENGTH,
                (U8*) temp,
                (mmi_chset_enum) PhnsetGetDefEncodingType());
        }
        
        mmi_fmgr_send_copy_req(
            fmgr_p->tree_action,
            (PU8) fmgr_p->old_file_path,
            (PU8) fmgr_p->file_path,
            (PsFuncPtr) fmgr_theme_move_rsp);

        /* Set fmgr is busy flag */
        fmgr_p->is_fmgr_busy = MMI_TRUE;    
    
        entry_fmgr_copy_animation();
    }

}


/*****************************************************************************
 * FUNCTION
 *  fmgr_theme_move_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_theme_move_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 flag;
    FMGR_FILE_INFO_STRUCT file_info;
	mmi_fmt_copy_rsp_strcut *msgPtr;
	msgPtr = (mmi_fmt_copy_rsp_strcut *)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOffBacklight();

    fmgr_p->is_fmgr_busy = MMI_FALSE;
    
    if (isInCall() == TRUE && GetExitScrnID() != SCR_FMGR_COPY_ANIMATION)
    {
        if (msgPtr->result == FS_ABORTED_ERROR)
        {
            /* aborted => go back to source folder */
            mmi_ucs2cpy((S8*)fmgr_p->file_path, (S8*)fmgr_p->old_file_path);
        }

        mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->old_file_path );

        mmi_fmgr_remove_last_dir((PS8)fmgr_p->file_path);
	FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
	fmgr_p->tree_action = FMGR_ACTION_NONE;
	fmgr_p->enter_folder = TRUE;
	DeleteScreenIfPresent(SCR_FMGR_COPY_ANIMATION);
	return;
    }
#ifdef __MMI_AUDIO_PLAYER__
	mdi_audio_resume_background_play();
#endif
	if (msgPtr->result >= 0)
    {
      /* success */
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__      	
      	if (fmgr_p->tree_action == FMGR_ACTION_MOVE)
      		PmgFmgrDelExtMelodyFunc((PS8)fmgr_p->old_file_path, PMG_FMGR_DEL_CERTAIN);
#endif
		mmi_fmgr_remove_last_dir((PS8)fmgr_p->file_path);
		FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
		fmgr_p->tree_action = FMGR_ACTION_NONE;
		fmgr_p->enter_folder = TRUE;   
                mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
                flag=mmi_activatetheme_frmfilemanager(fmgr_p->file_path,file_info.file_name, file_info.is_short); 
      	        //flag=mmi_activatetheme_frmfilemanager(fmgr_p->file_path,file_info.file_name); 
   		g_istheme_folder_created=FALSE;
		DeleteScreenIfPresent(SCR_FMGR_COPY_ANIMATION);

            mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->old_file_path );
            mmi_fmgr_remove_last_dir((PS8)fmgr_p->file_path);
            mmi_fmgr_copy_new_file_path_after_app_move((PS8) fmgr_p->file_path);
	}
	else
	{
		/* fail */
		mmi_ucs2_to_asc((PS8)nPrintableStr, (PS8)fmgr_p->file_path);
		PRINT_INFORMATION("copy rsp fail: %s", nPrintableStr);

		mmi_ucs2cpy((S8*)fmgr_p->file_path, (S8*)fmgr_p->old_file_path);
		mmi_fmgr_remove_last_dir((PS8)fmgr_p->file_path);
		FMGR_FILTER_SET_ALL(&fmgr_p->filter_type);
		fmgr_p->tree_action = FMGR_ACTION_NONE;
		fmgr_p->enter_folder = FALSE;

		if (msgPtr->result == FS_ABORTED_ERROR)
		{
			if (IsScreenPresent(fmgr_p->active_explorer_screen))
				GoBackToHistory(fmgr_p->active_explorer_screen);
		}
		else
		{
			DisplayPopup((PU8)GetString(GetFileSystemErrorString(msgPtr->result)),
                     IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
			DeleteScreenIfPresent(SCR_FMGR_COPY_ANIMATION);      
    }
		if(g_istheme_folder_created==TRUE) 
		{
			mmi_fmgr_remove_last_dir((PS8)fmgr_p->file_path);
			fmgr_p->delete_all = FMGR_DELETE_FOLDER;
			mmi_fmgr_send_delete_req((PU8)gtheme_folder_path,FS_RECURSIVE_TYPE, theme_folder_delete_rsp_hdlr);
    g_istheme_folder_created = FALSE;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_theme_delete_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_theme_delete_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(fmgr_display_theme_delte_popUp, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_theme_single_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_theme_single_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    S16 flag, status;
    S32 error_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flag = fmgr_check_file_present();

    if (flag <= FMGR_NO_ERROR)
    {
        return;
    }

    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
    flag = check_file_location(fmgr_p->file_path);
    if (flag)
    {

        status = mmi_tm_delete_theme_from_fmgr(flag, (PU8) file_info.file_name, &error_type);

        switch (status)
        {
            case THEME_ERROR_SUCCESS:
                DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, 1000, SUCCESS_TONE);
                break;
            case THEME_ERROR_ALREADY_ACTIVATED:
                DisplayPopup((PU8) get_string(FMGR_FS_ACCESS_DENIED_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
                break;
            default:
                DisplayPopup(
                    (PU8) GetString(GetFileSystemErrorString(error_type)),
                    IMG_GLOBAL_ERROR,
                    TRUE,
                    1000,
                    ERROR_TONE);
                break;

        }
        if (FS_Count((PU16) fmgr_p->file_path, FS_DIR_TYPE | FS_FILE_TYPE | FS_FILTER_SYSTEM_ATTR, NULL, 0) == 0)
        {
            mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
        }

	fmgr_p->enter_folder = FALSE;
        DeleteScreenIfPresent(SCR_FMGR_FILE_OPTION);
    }
    else
    {

        //mmi_ucs2cpy((PS8)name,(PS8)file_info.file_name);
        // mmi_fmgr_append_file_name((PSstr_global_8)name, (PS8)file_info.file_ext);
        //activeflag=is_mmi_theme_file_active(name);
        //if(activeflag)                     
        //   fmgr_display_theme_delte_popUp();
        //else
        fmgr_p->delete_all = FMGR_DELETE_SINGLE;
        fmgr_delete();

    }

}


/*****************************************************************************
 * FUNCTION
 *  fmgr_display_theme_delte_popUp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_display_theme_delte_popUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	U8 str[(FMGR_MAX_FILE_LEN+FMGR_MAX_EXT_LEN+1)*ENCODING_LENGTH+18];//Name len + Extension Lenght * Encoding Lenght + 18 (len of Delete)
	FMGR_FILE_INFO_STRUCT file_info;

	memset (str, 0, sizeof(str));
	mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
	mmi_ucs2cpy ((PS8)str, (PS8)get_string(STR_GLOBAL_DELETE));
	mmi_ucs2cat ((PS8)str, (PS8)L" ");
	if (file_info.is_short)
	{
		U16 len;
		len = mmi_ucs2strlen ((PS8)str) << 1;
	   	mmi_chset_mixed_text_to_ucs2_str( (U8*)&str[len], (MAX_SUBMENU_CHARACTERS-1) * ENCODING_LENGTH, 
	   		(U8*)file_info.file_name, PhnsetGetDefEncodingType() );
	}
	else
	{
		mmi_ucs2cat ((PS8)str, (PS8)file_info.file_name);
#ifndef __MMI_SHOW_FILE_EXT__
		mmi_ucs2cat((PS8)str, (PS8)file_info.file_ext);
#endif		
	}
	
	
	DisplayConfirm(
			STR_GLOBAL_YES,IMG_GLOBAL_YES,
			STR_GLOBAL_NO,IMG_GLOBAL_NO,
			(PU16)str, IMG_GLOBAL_QUESTION, WARNING_TONE);
	SetLeftSoftkeyFunction(fmgr_theme_single_delete, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_activatetheme_frmfilemanager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]        
 *  filename        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
 U8 mmi_activatetheme_frmfilemanager(PS8 path, PS8 filename , MMI_BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* char name1[40],name[100]; */
    int flag = 0, status = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flag = check_file_location(path);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* if 0 */

    switch (flag)
    {
        case THEME_TYPE_DOWNLOADED_PHONE:
            status = mmi_tm_activate_theme_from_fmgr(THEME_TYPE_DOWNLOADED_PHONE, (PU8) filename, is_short);
            //status = mmi_tm_activate_theme_from_fmgr(THEME_TYPE_DOWNLOADED_PHONE, (PU8) filename);
            break;
        case THEME_TYPE_DOWNLOADED_CARD:
            status = mmi_tm_activate_theme_from_fmgr(THEME_TYPE_DOWNLOADED_CARD, (PU8) filename, is_short);
            //status = mmi_tm_activate_theme_from_fmgr(THEME_TYPE_DOWNLOADED_CARD, (PU8) filename);
            break;
    }
    if (flag)
    {
        mmi_tm_handle_theme_activation_error_status((U16) status);
    }

    return flag;
}


/*****************************************************************************
 * FUNCTION
 *  is_mmi_theme_file_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 is_mmi_theme_file_active(PS8 file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_ucs2cmp(gtest_theme_file, file_name))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_storage_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S16 get_storage_type(PS8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_ucs2ncmp(path, "C:\\", 3))
    {
        return THEME_TYPE_DOWNLOADED_PHONE;
    }
    else if (!mmi_ucs2ncmp(path, "D:\\", 3))
    {
        return THEME_TYPE_DOWNLOADED_CARD;
    }
    else
    {
        return -1;
    }
}

extern int toupper(int);


/*****************************************************************************
 * FUNCTION
 *  check_file_location
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 check_file_location(PS8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_UCS2[FMGR_PATH_BUFFER_SIZE];
    S8 buf_UCS21[FMGR_PATH_BUFFER_SIZE];
    S8 ascii_path[FMGR_PATH_BUFFER_SIZE];

    // #ifdef MMI_ON_HARDWARE_P
    S8 drive;
    S16 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // #endif

    mmi_ucs2_to_asc(ascii_path, path);
    while (ascii_path[len] != '\0')
    {
        ascii_path[len] = (char)toupper(ascii_path[len]);
        len++;
    }

    if (((drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM)) >= 'A') && (drive <= 'Z'))
    {
        sprintf((PS8) buf_UCS2, "%c:\\", drive);

        //mmi_asc_to_ucs2(buf_UCS2,root);
        //mmi_ucs2cat((PS8)buf_UCS2, (PS8)MMI_PHONE_THEME);
        strcat(buf_UCS2, MMI_THEME_LOCATION);
    }
    if (((drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        /* Removable existed */

        sprintf((PS8) buf_UCS21, "%c:\\", drive);

        /* mmi_asc_to_ucs2(buf_UCS21,MMI_CARD_THEME); */
        strcat(buf_UCS21, MMI_THEME_LOCATION);
    }

    /* if(!mmi_ucs2cmp(path,buf_UCS2))
       return THEME_TYPE_DOWNLOADED_PHONE;
       else if (!mmi_ucs2cmp(path,buf_UCS21))
       return THEME_TYPE_DOWNLOADED_CARD;
       else return 0; */

    if (!strcmp(ascii_path, buf_UCS2))
    {
        return THEME_TYPE_DOWNLOADED_PHONE;
    }
    else if (!strcmp(ascii_path, buf_UCS21))
    {
        return THEME_TYPE_DOWNLOADED_CARD;
    }
    else
    {
        return 0;
    }

}


/*****************************************************************************
 * FUNCTION
 *  theme_folder_delete_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void theme_folder_delete_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_istheme_folder_created = FALSE;

    fmgr_p->is_fmgr_busy = MMI_FALSE;
}

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

#ifdef __MMI_EBOOK_READER__


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_open_ebook
 * DESCRIPTION
 *  Highlight function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_open_ebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fmgr_open_ebook_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_open_ebook_hdlr, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback(fmgr_open_ebook_hdlr);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_open_ebook_hdlr
 * DESCRIPTION
 *  Open book
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_open_ebook_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOAD_AGENT__
    /* download agent file */
    if (fmgr_is_da_file())
    {
     	PS8 file_name;
        FS_HANDLE handle;

        /* Check if file exists or not */
        handle = FS_Open((PU16) fmgr_p->da_file_path, FS_READ_ONLY);
        if (handle > FS_NO_ERROR)
        {
        	FS_Close(handle);
        }
        else
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION);
            return;
        }

        mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->da_file_path);

     #if defined(__DRM_V02__)        
        {
            S32 file_type = 0;

        file_type = mmi_fmgr_get_drm_file_type_by_path((PS8) fmgr_p->file_path, &file_info.file_type);
            
        if (file_type == FMGR_TYPE_ODF)
        {
            /* multi part ODF */
            mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
    
            if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
        #ifndef __MMI_SHOW_FILE_EXT__
                || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
        #endif 
                )
                return;
        }
         }
     #else
         mmi_fmgr_get_file_type((PS8) fmgr_p->da_file_path, &file_info.file_type);
     #endif /* defined(__DRM_V02__) */

        
        file_name = mmi_fmgr_extract_file_name((PS8) fmgr_p->file_path);
        mmi_ucs2cpy ((PS8)file_info.file_name, file_name);
        mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
        file_info.is_short = FALSE;
    }
    /* non download agent file */
    else
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
    {
        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
        if (fmgr_check_file_present() < FMGR_NO_ERROR)
        {
            return;
        }
    }

	 ebr_frm_open_book_from_file_manager((S8*)file_info.file_name,(S8*)fmgr_p->file_path,file_info.is_short);
}
#endif /* __MMI_EBOOK_READER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_copy_new_file_path_after_app_move
 * DESCRIPTION
 *  Copy the new path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_copy_new_file_path_after_app_move(S8* new_file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    U16 file_count;
    PS8 ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8)fmgr_p->file_path,(PS8)new_file_path);

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_ALL(&filter);
    mmi_fmgr_kernel_init((PS8)fmgr_p->file_path, filter, &file_count);
    
    /* check the file count of the original path is not empty. 
       if it is empty, then the behavior is the same as back_to_parent.
       Otherwise fmgr will go back to drive screen, it is not trivial for user */
    if ((file_count<1) && (fmgr_p->src_application == APP_FILEMANAGER || fmgr_p->src_application == APP_MYFAVORITE))
    {
        ptr = mmi_fmgr_extract_file_name((PS8) fmgr_p->file_path);
        if (ptr != NULL)
	{
            S32 end;

            end = mmi_ucs2strlen(ptr) - 1;
            if (ptr[end << 1] == '\\' && ptr[(end << 1) + 1] == 0)
	    {
                ptr[end << 1] = 0;
	    }
            mmi_ucs2cpy((PS8) fmgr_p->parent_name, ptr);
            ptr[0] = 0;
            ptr[1] = 0;
        }
    }

	fmgr_p->cur_index = 0;
	fmgr_p->tree_action = FMGR_ACTION_NONE;
    fmgr_p->enter_folder = TRUE;
}


#if defined(__MMI_BROWSER_2__)
/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_goto_bookmark
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_goto_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fmgr_goto_bookmark_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_goto_bookmark_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_goto_bookmark_hdlr
 * DESCRIPTION
 *  Open book
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_goto_bookmark_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_check_file_present() < FMGR_NO_ERROR)
    {
        return;
    }

    mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);

    if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
    #ifndef __MMI_SHOW_FILE_EXT__
            || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
    #endif 
            )
            return;

    mmi_brw_open_file_from_fmgr((S8*)fmgr_p->file_path,file_info.is_short);

    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
}

#endif /* (__MMI_BROWSER_2__) */


#ifdef __MMI_SWFLASH__      


/*****************************************************************************
 * FUNCTION
 *  fmgr_play_swflash_hdlr
 * DESCRIPTION
 *  get the file full path and play swflash works
  * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_play_swflash_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOAD_AGENT__
    /* download agent file */
    if (fmgr_is_da_file())
    {
        FS_HANDLE handle;
        /* Check if file exists or not */
        handle = FS_Open((PU16) fmgr_p->da_file_path, FS_READ_ONLY);
        if (handle > FS_NO_ERROR)
        {
        	FS_Close(handle);
        }
        else
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION);
            return;
        }
        mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->da_file_path);

        mmi_swflash_set_file_full_path(fmgr_p->file_path,NULL);
    }
    /* non download agent file */
    else
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
    {
        if (fmgr_check_file_present() < FMGR_NO_ERROR)
        {
            return;
        }
        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
	mmi_swflash_set_file_full_path(fmgr_p->file_path,file_info.file_name);
    }
    mmi_swflash_option_play_entry_screen();     
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_download_swflash_hdlr
 * DESCRIPTION
 * get the file full path and resume download
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_download_swflash_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOAD_AGENT__
    /* download agent file */
    if (fmgr_is_da_file())
    {
        FS_HANDLE handle;
        /* Check if file exists or not */
        handle = FS_Open((PU16) fmgr_p->da_file_path, FS_READ_ONLY);
        if (handle > FS_NO_ERROR)
        {
        	FS_Close(handle);
        }
        else
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION);
            return;
        }
        mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->da_file_path);

        mmi_swflash_set_file_full_path(fmgr_p->file_path,NULL);
    }
    /* non download agent file */
    else
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
    {
        if (fmgr_check_file_present() < FMGR_NO_ERROR)
        {
            return;
        }
        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
	mmi_swflash_set_file_full_path(fmgr_p->file_path,file_info.file_name);
    }
    mmi_swflash_option_download();     
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_info_swflash_hdlr
 * DESCRIPTION
 *  get the file full path and view its attribute
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_info_swflash_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOAD_AGENT__
    /* download agent file */
    if (fmgr_is_da_file())
    {
        FS_HANDLE handle;
        /* Check if file exists or not */
        handle = FS_Open((PU16) fmgr_p->da_file_path, FS_READ_ONLY);
        if (handle > FS_NO_ERROR)
        {
        	FS_Close(handle);
        }
        else
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION);
            return;
        }
        mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->da_file_path);

        mmi_swflash_set_file_full_path(fmgr_p->file_path, NULL);
    }
    /* non download agent file */
    else
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
    {
        if (fmgr_check_file_present() < FMGR_NO_ERROR)
        {
           return;
        }
        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
	mmi_swflash_set_file_full_path(fmgr_p->file_path,file_info.file_name);
    }
    mmi_swflash_option_info_entry_screen();     
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_swflash_info
 * DESCRIPTION
 *   Highlight function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_swflash_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fmgr_info_swflash_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_info_swflash_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_swflash_play
 * DESCRIPTION
 *   Highlight function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_swflash_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fmgr_play_swflash_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_play_swflash_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_swflash_download
 * DESCRIPTION
 *   Highlight function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_swflash_download(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fmgr_download_swflash_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_download_swflash_hdlr, KEY_EVENT_UP);
}

#endif /* __MMI_SWFLASH__ */ 

#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_vbookmark_goto
 * DESCRIPTION
 *   Highlight function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_vbookmark_goto(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fmgr_vbookmark_goto_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_vbookmark_goto_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_vbookmark_goto_hdlr
 * DESCRIPTION
 *  Open book
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_vbookmark_goto_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_DOWNLOAD_AGENT__
    /* download agent file */
    if (fmgr_is_da_file())
    {
        FS_HANDLE handle;
        /* Check if file exists or not */
        handle = FS_Open((PU16) fmgr_p->da_file_path, FS_READ_ONLY);
        if (handle > FS_NO_ERROR)
        {
        	FS_Close(handle);
        }
        else
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION);
            return;
        }
        mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->da_file_path);
        file_info.is_short = FALSE;
    }
    /* non download agent file */
    else
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
    {
        if (fmgr_check_file_present() < FMGR_NO_ERROR)
        {
            return;
        }

        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
        if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
    #ifndef __MMI_SHOW_FILE_EXT__
            || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
    #endif 
            )
            return;
    }

    mmi_brw_bookmarks_goto_from_fmgr((PS8) fmgr_p->file_path, file_info.is_short);
    
    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);

}



/*****************************************************************************
 * FUNCTION
 *  highlight_fmgr_vbookmark_open
 * DESCRIPTION
 *   Highlight function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_fmgr_vbookmark_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fmgr_vbookmark_open_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(fmgr_vbookmark_open_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_vbookmark_open_hdlr
 * DESCRIPTION
 *  Open book
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_vbookmark_open_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_DOWNLOAD_AGENT__
    /* download agent file */
    if (fmgr_is_da_file())
    {
        FS_HANDLE handle;
        /* Check if file exists or not */
        handle = FS_Open((PU16) fmgr_p->da_file_path, FS_READ_ONLY);
        if (handle > FS_NO_ERROR)
        {
        	FS_Close(handle);
        }
        else
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION);
            return;
        }
        mmi_ucs2cpy((PS8) fmgr_p->file_path, (PS8) fmgr_p->da_file_path);
        file_info.is_short = FALSE;
    }
    /* non download agent file */
    else
#endif /* __MMI_DOWNLOAD_AGENT__ */ 
    {
        if (fmgr_check_file_present() < FMGR_NO_ERROR)
        {
            return;
        }

        mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &file_info);
        if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_name) == FALSE
    #ifndef __MMI_SHOW_FILE_EXT__
            || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info.file_ext) == FALSE
    #endif 
            )
            return;
    }

    mmi_brw_bookmarks_open_from_fmgr((PS8) fmgr_p->file_path, file_info.is_short);
    
    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);

}
#endif /* #ifdef __MMI_VBOOKMARK__ */

static BOOL fmgr_is_network_services_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    E_MTPNP_AD_SIMCARD_USABLE_SIDE state;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    state = MTPNP_AD_Get_UsableSide();
    if(state == MTPNP_AD_SIMCARD1_USABLE ||
        state == MTPNP_AD_SIMCARD2_USABLE ||
        state == MTPNP_AD_DUALSIM_USABLE)
    {
        return TRUE;
    }
#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() > 0)
    {
        return TRUE;
    }
#endif 
    return FALSE;

#else /* __MMI_DUAL_SIM_SINGLE_CALL__ */

    return mmi_bootup_is_network_service_available();

#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
}

