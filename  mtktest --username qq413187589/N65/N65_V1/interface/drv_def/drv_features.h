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
 *    drv_features.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for all driver features.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Phase out 6218/6218B.
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClaseCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#ifndef __DRV_FEATURES_H__
#define __DRV_FEATURES_H__

#if defined(MT6205B)
   #include "drv_features_6205B.h"
   /*Above is MT6205B*/
#elif defined(MT6205)
   #include "drv_features_6205.h"
   /*Above is MT6205*/
#elif defined(MT6208)
   #include "drv_features_6208.h"
   /*Above is MT6208*/
#elif defined(MT6217)
   #include "drv_features_6217.h"
   /*Above is MT6217*/
#elif defined(MT6219)
   #include "drv_features_6219.h"
   /*Above is MT6219*/
#elif defined(MT6223)
   #include "drv_features_6223.h"
   /*Above is MT6223*/
#elif defined(MT6223P)
   #include "drv_features_6223P.h"
   /*Above is MT6223P*/
#elif defined(MT6225)
   #include "drv_features_6225.h"
   /*Above is MT6225*/
#elif defined(MT6226)
   #include "drv_features_6226.h"
   /*Above is MT6226*/
#elif defined(MT6226M)
   #include "drv_features_6226M.h"
   /*Above is MT6226M*/
#elif defined(MT6227)
   #include "drv_features_6227.h"
   /*Above is MT6227*/
#elif defined(MT6227D)
   #include "drv_features_6227D.h"
   /*Above is MT6227D*/
#elif defined(MT6226D)
   #include "drv_features_6226D.h"
   /*Above is MT6226D*/
#elif defined(MT6228)
   #include "drv_features_6228.h"
   /*Above is MT6228*/
#elif defined(MT6229)
   #include "drv_features_6229.h"
   /*Above is MT6229*/
#elif defined(MT6230)
   #include "drv_features_6230.h"
   /*Above is MT6230*/
#elif defined(MT6268T)
   #include "drv_features_6268t.h"
   /*Above is MT6268T*/
#elif defined(MT6238)
   #include "drv_features_6238.h"
   /*Above is MT6238*/
#elif defined(MT6235)
   #include "drv_features_6235.h"
   /*Above is MT6235*/   
#else
   #error "The chip type is non-supported"
#endif   /*End of all chips*/

#include "drv_features_option.h"

#endif   /*End __DRV_FEATURES_H__*/
