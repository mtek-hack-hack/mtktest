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
 *    tone.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for tone table.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"

#define ALERT_TONE_ENABLE

#ifdef ALERT_TONE_ENABLE
const kal_uint16 MusicalNoteTable_C1[] = {
   16250,         /*    C0     */
   15294,         /*    C0#    */
   14444,         /*    D0     */
   14254,         /*    D0#    */
   13542,         /*    E0     */
   12897,         /*    F0     */
   12287,         /*    F0#    */
   11775,         /*    G0     */
   11304,         /*    G0#    */
   10943,         /*    A0     */
   10188,         /*    A0#    */
   9849,          /*    B0     */
                             
   9673,          /*    C1     */
   9104,          /*    C1#    */
   8598,          /*    D1     */
   8553,          /*    D1#    */
   7927,          /*    E1     */
   7558,          /*    F1     */
   7437,          /*    F1#    */
   6982,          /*    G1     */
   6708,          /*    G1#    */
   6220,          /*    A1     */
   6226,          /*    A1#    */
   5920,          /*    B1     */
                             
   5556,          /*    C2     */
   5234,          /*    C2#    */
   5238,          /*    D2     */
   4966,          /*    D2#    */
   4663,          /*    E2     */
   4395,          /*    F2     */
   4416,          /*    F2#    */
   4145,          /*    G2     */
   3944,          /*    G2#    */
   3693,          /*    A2     */
   3736,          /*    A2#    */
   3523,          /*    B2     */
                            
   3333,          /*    C3     */
   3140,          /*    C3#    */
   2968,          /*    D3     */
   2995,          /*    D3#    */
   2831,          /*    E3     */
   2668,          /*    F3     */
   2510,          /*    F3#    */
   2551,          /*    G3#    */
   2415,          /*    G3#    */
   2273,          /*    A3     */
   2146,          /*    A3#    */
   2033,          /*    B3     */
                            
   1916,          /*    C4     */
   1956,          /*    C4#    */
   1849,          /*    D4     */
   1742,          /*    D4#    */
   1646,          /*    E4     */
   1552,          /*    F4     */
   1464,          /*    F4#    */
   1507,          /*    G4#    */
   1424,          /*    G4#    */
   1343,          /*    A4     */
   1268,          /*    A4#    */
   1199,          /*    B4     */
                            
   1130,          /*    C5     */
   1173,          /*    C5#    */
   1107,          /*    D5     */
   1045,          /*    D5#    */
   986,           /*    E5     */
   931,           /*    F5     */
   878,           /*    F5#    */
   829,           /*    G5#    */
   870,           /*    G5#    */
   821,           /*    A5     */
   775,           /*    A5#    */
   732,           /*    B5     */
                            
   690,           /*    C6     */
   652,           /*    C6#    */
   615,           /*    D6     */
   581,           /*    D6#    */
   617,           /*    E6     */
   582,           /*    F6     */
   549,           /*    F6#    */
   518,           /*    G6#    */
   489,           /*    G6#    */
   462,           /*    A6     */
   436,           /*    A6#    */
   411,           /*    B6     */
                            
   444,           /*    C7     */
   419,           /*    C7#    */
   395,           /*    D7     */
   373,           /*    D7#    */
   352,           /*    E7     */
   332,           /*    F7     */
   314,           /*    F7#    */
   296,           /*    G7#    */
   280,           /*    G7#    */
   264,           /*    A7     */
   291,           /*    A7#    */
   274            /*    B7     */
};
   
const kal_uint16 MusicalNoteTable_C2[] = {
   25,            /*    C0     */
   25,            /*    C0#    */
   25,            /*    D0     */
   24,            /*    D0#    */
   24,            /*    E0     */
   24,            /*    F0     */
   23,            /*    F0#    */
   23,            /*    G0     */
   23,            /*    G0#    */
   22,            /*    A0     */
   22,            /*    A0#    */
   22,            /*    B0     */
                                 
   21,            /*    C1     */
   21,            /*    C1#    */
   21,            /*    D1     */
   20,            /*    D1#    */
   20,            /*    E1     */
   20,            /*    F1     */
   19,            /*    F1#    */
   19,            /*    G1     */
   19,            /*    G1#    */
   19,            /*    A1     */
   18,            /*    A1#    */
   18,            /*    B1     */
                                 
   18,            /*    C2     */
   18,            /*    C2#    */
   17,            /*    D2     */
   17,            /*    D2#    */
   17,            /*    E2     */
   17,            /*    F2     */
   16,            /*    F2#    */
   16,            /*    G2     */
   16,            /*    G2#    */
   16,            /*    A2     */
   15,            /*    A2#    */
   15,            /*    B2     */
                                 
   15,            /*    C3     */
   15,            /*    C3#    */
   15,            /*    D3     */
   14,            /*    D3#    */
   14,            /*    E3     */
   14,            /*    F3     */
   14,            /*    F3#    */
   13,            /*    G3#    */
   13,            /*    G3#    */
   13,            /*    A3     */
   13,            /*    A3#    */
   13,            /*    B3     */
                                 
   13,            /*    C4     */
   12,            /*    C4#    */
   12,            /*    D4     */
   12,            /*    D4#    */
   12,            /*    E4     */
   12,            /*    F4     */
   12,            /*    F4#    */
   11,            /*    G4#    */
   11,            /*    G4#    */
   11,            /*    A4     */
   11,            /*    A4#    */
   11,            /*    B4     */
                                 
   11,            /*    C5     */
   10,            /*    C5#    */
   10,            /*    D5     */
   10,            /*    D5#    */
   10,            /*    E5     */
   10,            /*    F5     */
   10,            /*    F5#    */
   10,            /*    G5#    */
   9,             /*    G5#    */
   9,             /*    A5     */
   9,             /*    A5#    */
   9,             /*    B5     */
                                 
   9,             /*    C6     */
   9,             /*    C6#    */
   9,             /*    D6     */
   9,             /*    D6#    */
   8,             /*    E6     */
   8,             /*    F6     */
   8,             /*    F6#    */
   8,             /*    G6#    */
   8,             /*    G6#    */
   8,             /*    A6     */
   8,             /*    A6#    */
   8,             /*    B6     */
                                 
   7,             /*    C7     */
   7,             /*    C7#    */
   7,             /*    D7     */
   7,             /*    D7#    */
   7,             /*    E7     */
   7,             /*    F7     */
   7,             /*    F7#    */
   7,             /*    G7#    */
   7,             /*    G7#    */
   7,             /*    A7     */
   6,             /*    A7#    */
   6              /*    B7     */
}; 

const kal_uint16 MusicalNoteTable_Thres[] = {
   508,           /*    C0     */
   478,           /*    C0#    */
   451,           /*    D0     */
   445,           /*    D0#    */
   423,           /*    E0     */
   403,           /*    F0     */
   384,           /*    F0#    */
   368,           /*    G0     */
   353,           /*    G0#    */
   342,           /*    A0     */
   318,           /*    A0#    */
   308,           /*    B0     */
                                 
   302,           /*    C1     */
   285,           /*    C1#    */
   269,           /*    D1     */
   267,           /*    D1#    */
   248,           /*    E1     */
   236,           /*    F1     */
   232,           /*    F1#    */
   218,           /*    G1     */
   210,           /*    G1#    */
   194,           /*    A1     */
   195,           /*    A1#    */
   185,           /*    B1     */
                                 
   174,           /*    C2     */
   164,           /*    C2#    */
   164,           /*    D2     */
   155,           /*    D2#    */
   146,           /*    E2     */
   137,           /*    F2     */
   138,           /*    F2#    */
   130,           /*    G2     */
   123,           /*    G2#    */
   115,           /*    A2     */
   117,           /*    A2#    */
   110,           /*    B2     */
                                 
   104,           /*    C3     */
   98,            /*    C3#    */
   93,            /*    D3     */
   94,            /*    D3#    */
   89,            /*    E3     */
   83,            /*    F3     */
   78,            /*    F3#    */
   80,            /*    G3#    */
   76,            /*    G3#    */
   71,            /*    A3     */
   67,            /*    A3#    */
   64,            /*    B3     */
                                 
   60,            /*    C4     */
   61,            /*    C4#    */
   58,            /*    D4     */
   54,            /*    D4#    */
   51,            /*    E4     */
   49,            /*    F4     */
   46,            /*    F4#    */
   47,            /*    G4#    */
   45,            /*    G4#    */
   42,            /*    A4     */
   40,            /*    A4#    */
   38,            /*    B4     */
                                 
   35,            /*    C5     */
   37,            /*    C5#    */
   35,            /*    D5     */
   33,            /*    D5#    */
   31,            /*    E5     */
   29,            /*    F5     */
   27,            /*    F5#    */
   26,            /*    G5#    */
   27,            /*    G5#    */
   26,            /*    A5     */
   24,            /*    A5#    */
   23,            /*    B5     */
                                 
   22,            /*    C6     */
   20,            /*    C6#    */
   19,            /*    D6     */
   18,            /*    D6#    */
   19,            /*    E6     */
   18,            /*    F6     */
   17,            /*    F6#    */
   16,            /*    G6#    */
   15,            /*    G6#    */
   14,            /*    A6     */
   14,            /*    A6#    */
   13,            /*    B6     */
                                 
   14,            /*    C7     */
   13,            /*    C7#    */
   12,            /*    D7     */
   12,            /*    D7#    */
   11,            /*    E7     */
   10,            /*    F7     */
   10,            /*    F7#    */
   9,             /*    G7#    */
   9,             /*    G7#    */
   8,             /*    A7     */
   9,             /*    A7#    */
   9              /*    B7     */
};
#endif   /*ALERT_TONE_ENABLE*/

