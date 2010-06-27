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
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
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
 * bra_ofln.h
 *
 */

#ifndef _bra_ofln_h
#define _bra_ofln_h

/*
 * This function creates and display the offline page menu
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_ofln_create_ofln_menu (void);

/*
 * This function is used to set the offile mode
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_ofln_set_offline_mode(MSF_BOOL b);

/*
 * This function return if the offline mode is true or not
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
int 
bra_ofln_offline_mode(void);

/*
 * This function is used to reset the offile state
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_ofln_reset_offline_state(void);

/*
 * This function return if it is in loading offline page state
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
int
bra_ofln_loading_offline_page(void);

/*
 * This function is the callback function of saving offline page done
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_ofln_saving_offline_done(MSF_BOOL success);

/*
 * This function called when brs not found the offline page
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
int
bra_ofln_page_not_found(void *p);

/*
 * This function called to find whether there exists pages to be deleted
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
int
bra_ofln_page_has_page_to_delete(void);

/*
 * This function called to delete offline pages when there exists page to be delete 
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_ofln_page_delete_pending_page(void);

#endif /*_bra_ofln_h*/

