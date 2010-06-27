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
 */
/*
 * bra_bkm.h
 *
 * Description:
 *    This file contains code to manage Bookmarks and creating the
 *    neccesary menus
 *
 */


#ifndef _bra_bkm_h
#define _bra_bkm_h

/*
 * This function initializes the bookmarks manager and reads the 
 * saved bookmarks from file.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_bkm_init (void);

/*
 * Thsi function terminates the bookmark manager and releases all 
 * resources allocated
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_bkm_destroy (void);


/*
 * This function creates and display the man bookmarks menu
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_bkm_create_bkm_menu (void);

/*
 * This function adds a new Bookmark to the list of bookmarks.
 *
 * PARAMETERS
 *
 * title     : Title of new Bookmark
 * url       : Url of new Bookmark
 *
 * RETURN    : 1 if successful, else 0
 */
int 
bra_bkm_add_new_bookmark(char* title, char* url);

int 
bra_bkm_offline_add_new_bookmark(char* title, char* url);

int 
bra_bkm_offline_add_new_bookmark_to_file(char* title, char* url);


int 
bra_bkm_get_bkm(int idx, char *title, char *url);

int 
bra_bkm_get_bkm_total_num(void);

void 
bra_bkm_create_offline_add_bookmark_form(char* url);

void
bra_bkm_create_offline_add_bookmark_form_with_title(MsfStringHandle title, char *url, int close_to_id);

int
bra_bkm_is_full(void);

void
bra_bkm_create_select_bookmark(void *sig);

#endif /*_bra_bkm_h*/

