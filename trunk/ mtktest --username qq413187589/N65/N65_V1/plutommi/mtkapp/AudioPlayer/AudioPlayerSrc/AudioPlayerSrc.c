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
*  AudioPlayerMainSrc.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player main program
*
* Author:
* -------
*  Tim Chen
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
* $Revision:   1.143  $
* $Modtime:   Aug 01 2005 17:38:24  $
* $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/plutommi/MtkApp/AudioPlayer/AudioPlayerSrc/AudioPlayerSrc.c-arc  $
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
 * created by clearfsimport
 *
 * removed!
 * removed!
 * created by clearfsimport
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
 * rebase maintrunk.MAUI_MBJ on 2007-4-24 0:25:15.
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
 *    Rev 1.143   Aug 01 2005 17:40:42   mtk00563
 * Add AVZone in no sim screen
 * Resolution for 12165: [MMI][GUI]Add AVZone in no sim screen
 * 
 *    Rev 1.142   Jul 23 2005 16:21:26   mtk00798
 * add wma type & replace id3 & daf parsers
 * Resolution for 12052: [MED][AUD] replace id3 & daf parser with new parsers & add AAC+/WMA support
 * 
 *    Rev 1.141   Jun 27 2005 14:13:50   mtk00798
 * fix PC simulator compile warnings
 * 
 *    Rev 1.140   Jun 27 2005 11:58:48   mtk00798
 * change the category screen for empty list
 * 
 *    Rev 1.139   Jun 13 2005 11:40:36   mtk00798
 * add show repeat & shuffle status in play screen and show more detail info for audio file
 * Resolution for 11499: [MMI][AUDPLY] Add show repeat & shuffle status in play screen and show more detail info for audio file
 * 
 *    Rev 1.138   May 17 2005 02:21:08   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 * 
 *    Rev 1.137   Apr 18 2005 17:19:32   mtk00798
 * fix a func call prototype error for fmgr select file and path
 * 
 *    Rev 1.136   Apr 16 2005 17:08:24   mtk00798
 * change mmi_fmgr_select_path_and_enter call back func prototypes
 * Resolution for 10600: [FeatureChange][FMGR] return short file name flag to app selection
 * 
 *    Rev 1.135   Mar 27 2005 10:41:26   mtk00563
 * change for touch screen.
 * Resolution for 10404: [MMI][GUI]change for Draw Manger and Touch Screen
 * 
 *    Rev 1.134   Mar 02 2005 17:24:14   mtk00798
 * Improve single audio player & sound recorder timer update & display mechnaism
 * Resolution for 10055: [MMI][AUDPLY] & [SNDREC] Improve timer update & display mechanism
 * 
 *    Rev 1.133   16 Feb 2005 13:57:30   mtk00798
 * Forbid add to rings when it's out of DRM rights
 * Resolution for 9849: [MMI][AUDPLY] Forbid add to rings when it's out of DRM rights
 * 
 *    Rev 1.132   15 Feb 2005 15:44:46   mtk00798
 * not to consume rights when show detail
 * Resolution for 9829: [MMI][AUDPLY] Not to consume DRM rights when show the detail of a audio file
 * 
 *    Rev 1.131   15 Feb 2005 15:05:16   mtk00798
 * add audio equalizer function
 * Resolution for 9827: [MMI] & [MED] & [NVRAM] Add Audio Equalizer Feature
 * 
 *    Rev 1.130   Jan 25 2005 15:34:08   mtk00798
 * Fix a bug of potential assert when add to rings in audio player
 * Resolution for 9616: [MMI][AUDPLY] Fix a bug of potential assert when add to rings in audio player
 * 
 *    Rev 1.129   Jan 17 2005 18:36:58   mtk00798
 * Modify the handler to add files from file manager.
 * Let it be able to handle short file name correctly is possible.
 * Resolution for 9538: [MMI][PROFILES] & [AUDPLY] Modify the hander to add files from file manager, let it be able to handle short filename correctly if possible
 * 
 *    Rev 1.128   Jan 12 2005 22:37:40   mtk00798
 * add real resume function for MP3 files
 * Resolution for 9468: [MED] & [MMI] [AUDPLY] Add Real Resume Function for MP3 Files
 * 
 *    Rev 1.127   Dec 27 2004 11:18:00   mtk00798
 * Display Detail use B as unit if file size is smaller than 1KB
 * Resolution for 9275: [MMI][AUDPLY] Display Detail: if file size is smaller than 1KB, use B as file unit
 * 
 *    Rev 1.126   Dec 16 2004 11:42:36   mtk00798
 * replace AMRWB_CODEC compile option with AMRWB_DECODE
 * Resolution for 9157: [Audio] Replace AMRWB_CODEC compile option with AMRWB_DECODE and AMRWB_ENCODE
 * 
 *    Rev 1.125   Dec 13 2004 10:53:58   mtk00798
 * fix pc simulator functions & compile warnings
 * Resolution for 9065: [PC SIMULATOR] Fix Functions & Compile Warnings
 * 
 *    Rev 1.124   Dec 01 2004 10:18:40   mtk00798
 * add checking DRM before parsing id3 tag
 * Resolution for 8973: [MMI][AUDPLY] Check DRM play rights before parsing id3 tag
 * 
 *    Rev 1.123   Nov 29 2004 18:02:28   mtk00798
 * fix a bug of showing detail of mp3
 * Resolution for 8962: [MMI][AUDPLY] Fix a bug of showing mp3 detail
 * 
 *    Rev 1.122   Oct 28 2004 21:11:20   mtk00798
 * remove leave_fullscreen
 * Resolution for 8456: [MMI][AUDPLY] Adjust codes: remove leave_fullscreen
 * 
 *    Rev 1.121   Oct 07 2004 11:21:50   mtk00798
 * apply new text encoding functions
 * Resolution for 8099: [MMI]Apply New Text Encoding Mechanism for WAPADP, FILE SYSTEM, FILE MANAGER, and AUDIO PLAYER
 * 
 *    Rev 1.120   Sep 25 2004 17:09:38   mtk00798
 * add play MMF audio file support
 * 
 *    Rev 1.119   Sep 20 2004 12:08:10   mtk00563
 * Replace category 162-165 to DisplayConfirm
 * Resolution for 7731: [MMI][GUI]Replace category 162-165 to DisplayConfirm
 * 
 *    Rev 1.118   Sep 13 2004 13:10:40   mtk00798
 * Eliminate compile warning part
 * 
 *    Rev 1.117   Sep 07 2004 14:07:08   mtk00798
 * show size 0 kb when empty file
 * 
 *    Rev 1.116   Sep 04 2004 22:58:48   mtk00612
 * Change Screen ID.
 * Resolution for 7499: [MMI][Revise] Revise MultiMedia Category Screen.
 * 
 *    Rev 1.115   Sep 04 2004 17:44:18   mtk00798
 * reorganize compile options and codes to provide simple audio player for file manager when __MMI_AUDIO_PLAYER__ is not turn on
 * 
 *    Rev 1.114   Aug 30 2004 17:21:46   mtk00798
 * add entry/leave full screen
 * 
 *    Rev 1.113   Aug 27 2004 16:49:54   mtk00798
 * add slim version
 * 
 *    Rev 1.112   Aug 27 2004 09:38:18   mtk00798
 * modify add to ring to new interface in profile
 * 
 *    Rev 1.111   Aug 16 2004 19:01:58   mtk00798
 * add compile option for m4a audio type
 * 
 *    Rev 1.110   Aug 16 2004 18:55:16   mtk00798
 * add compile option for m4a audio type
 * 
 *    Rev 1.109   Aug 16 2004 16:40:24   mtk00798
 * add m4a audio type
 * 
 *    Rev 1.108   Aug 10 2004 21:28:16   mtk00798
 * (1) not to show song name in sub lcd when sub lcd is not idle
 * (2) reset highlight item in play list menu when refresh list
 * 
 *    Rev 1.107   Aug 02 2004 09:56:56   mtk00798
 * prevent from adding a file to play list in different storage than the storage that play list locates in
 * 
 *    Rev 1.106   Jul 22 2004 11:25:30   mtk00798
 * prevent from a potential error
 * 
 *    Rev 1.105   Jul 20 2004 21:00:12   mtk00798
 * adapt to MDI change
 * 
 *    Rev 1.104   Jul 20 2004 19:49:12   mtk00798
 * refine update time problem
 * 
 *    Rev 1.103   Jul 20 2004 18:07:14   mtk00798
 * increase timer update frequency and granulity
 * 
 *    Rev 1.102   Jul 19 2004 14:08:02   mtk00798
 * add a exit callback function for single play request
 * 
 *    Rev 1.101   Jul 19 2004 12:54:00   mtk00798
 * (1) Add a process screen for adding files in a folder to play list
 * (2) change to blocking mode
 * 
 *    Rev 1.100   Jul 09 2004 20:32:08   mtk00798
 * resolve issues #296, #316, #317, #318, #333 in FireFly
 * 
 *    Rev 1.99   Jul 08 2004 12:04:50   mtk00798
 * add compile option to wrap AAC and AWB file types by MT6219
 * Resolution for 6547: [MMI][AUDPLY] Add compile options to wrap AAC and AWB file types by MT6219
 * 
 *    Rev 1.98   Jul 06 2004 22:30:00   mtk00798
 * prevent from not stopping audio in some places
 * 
 *    Rev 1.97   Jul 06 2004 22:08:18   mtk00427
 * Use volume and device enum of MDI audio.
 * Resolution for 6529: [MMI][MDI] Adapt to MDI Audio interface.
 * 
 *    Rev 1.96   Jul 06 2004 18:01:56   mtk00798
 * Change LSK"OK" to RSK"Back" in single play screen
 * 
 *    Rev 1.95   Jul 05 2004 16:32:34   mtk00798
 * Add a timer for update duration for single play screen (category202screen)
 * Resolution for 6432: [MMI][AUDPLY] Fix the interrupt to single song play (from file manager) by MS cover open/close music
 * 
 *    Rev 1.94   Jul 02 2004 20:41:04   mtk00798
 * Fix the MS cover open/close music interrupt single song play
 * 
 *    Rev 1.93   Jun 29 2004 21:51:28   mtk00798
 * refine the file extention matching rule:
 * (1) if a file has a filename less than 41 chars, it will be exactly matched by its extension.
 * (2) if a file has a filename longer than 40 chars, it will be partially matched by its first 3 chars in extension
 * Resolution for 6369: [MMI][AUDPLY] Add audio file types: aif (aif, aiff, aifc), au, and snd
 * 
 *    Rev 1.92   Jun 29 2004 18:03:00   mtk00798
 * add aif, au, and snd file extension
 * 
 *    Rev 1.91   Jun 28 2004 16:12:34   mtk00798
 * update with latest file manager filter change
 * 
 *    Rev 1.90   Jun 25 2004 19:00:22   mtk00463
 * correct MMI key name 
 * Resolution for 6286: [MMI][Revise]Revise framework
 * 
 *    Rev 1.89   Jun 21 2004 14:27:32   mtk00798
 * Check if another play/record request exists before next song play timer expired to avoid preempty others' request
 * Resolution for 6231: [MMI][AUDPLY] Check if another play/record request exists before next song play timer expired to avoid preempt others' request
 * 
 *    Rev 1.88   Jun 18 2004 14:09:30   mtk00798
 * hide RSK"Back" for single play screen
 * 
 *    Rev 1.87   Jun 18 2004 14:06:10   mtk00798
 * Revise ExecuteCurrExitHandler.
 * Resolution for 6127: [MMI][Framework]Revise ExecuteCurrExitHandler.
 * 
 *    Rev 1.86   Jun 14 2004 15:14:28   mtk00798
 * prevent from replay after leaving audio player application and background play is off
 * 
 *    Rev 1.85   Jun 14 2004 12:21:58   mtk00798
 * Add a boundary check when loading items in dynamic list
 * Resolution for 6088: [MMI] Add a boundary checking for loading items in dynamic list
 * 
 *    Rev 1.84   Jun 12 2004 18:41:36   mtk00798
 * Fix subLCD display bug
 * Resolution for 6047: [MMI][AUDPLY] Fix SubLCD Display Bug
 * 
 *    Rev 1.83   Jun 09 2004 20:07:04   mtk00798
 * (1) check maximal file number, 1024, before adding a new file to play list 
 * (2) add mmi_audply_single_play function used for FileMgr
 * Resolution for 5988: (1) Check Maximal File Number 1024 before adding new file to play list (2) Add mmi_audply_single_play function used for FileMgr
 * 
 *    Rev 1.82   Jun 07 2004 11:21:22   mtk00798
 * Add Background Play settings
 * 
 *    Rev 1.81   May 31 2004 14:21:44   mtk00798
 * re-enable right arrow key for <Empty> option in the list screen
 * Resolution for 5759: Re-enable right arrow key for <Empty> option in the list screen
 * 
 *    Rev 1.80   May 28 2004 17:54:34   mtk00798
 * (1) Replace include "TextEncoding.h" with "text_encoding.h"
 * (2) re-enable right arrow key for "Play" item in option menu
 * Resolution for 5703: Re-enable right arrow key for "Play" item in option menu
 * 
 *    Rev 1.79   May 25 2004 21:57:04   mtk00798
 * Fix a bug about disable buttons in main screen when playlist is empty
 * 
 *    Rev 1.78   May 24 2004 16:48:00   mtk00526
 * Align max path/file length with file manager
 * Resolution for 5629: [MMI][Feature Change] Align max path/file length with file manager
 * 
 *    Rev 1.77   May 24 2004 13:57:46   mtk00798
 * Disable right arrow key for "Play","Add To Rings", and "Refresh List" in option screen
 * Resolution for 5612: Disable right arrow key for not to execute "Play","Add To Rings", and "Refresh List" in option screen
 * 
 *    Rev 1.76   May 18 2004 13:29:48   mtk00798
 * Fix Bug #1885 CANNON PLUS: 
 *    This is a button update bug during button press down and up, a state change overwrites the selected button value
 *    to cause button update wrong after button up.
 *    I fixed it by forcing to release button after any state change to overwrite the selected button value
 * 
 * Fix Bug #1928 CANNON PLUS:
 *    When repeat mode is "ONE", play a short file since it is too short so it keeps repeat playing and no other command can be taken.
 *    I solved it by applying pre-check button down condition whenever play completed and ready to play next song.
 *    Thus, a STOP, PREV, or NEXT button down event is processed in higher priority than play completed event.
 *    Therefore, they won't be blocked by repeating short file.
 * Resolution for 5499: Bug Fix for issue #1885 and #1928 in CANNON PLUS
 * 
 *    Rev 1.75   May 17 2004 11:47:30   mtk00798
 * Set Audio Player Volume to Profile Default Volume when restore Factory Settings
 * Resolution for 5458: Set audio player volume to profile default volume value when restore factory settings
 * 
 *    Rev 1.74   May 16 2004 18:05:56   mtk00798
 * disable right-arrow key when list is empty
 * Resolution for 5439: Disable Right-Arrow Key When Play List is Empty
 * 
 *    Rev 1.73   May 13 2004 22:47:04   mtk00798
 * add MNT support
 * Resolution for 4615: Update Audio Player v0.2
 * 
 *    Rev 1.72   May 13 2004 21:15:04   mtk00798
 * update
 * Resolution for 4615: Update Audio Player v0.2
 * 
 *    Rev 1.71   May 13 2004 09:46:26   mtk00798
 * (1) replace RTC_GetTime with kal_get_time
 * (2) handle Big5/GB2312 encoding in file short name
 * 
 *    Rev 1.70   May 10 2004 16:03:18   mtk00798
 * Fix a string compare bug for file extension
 * Resolution for 4615: Update Audio Player v0.2
 * 
 *    Rev 1.69   May 08 2004 16:41:12   mtk00798
 * change time update-period from 1 sec to 0.5 sec
 * Resolution for 5341: Change time update period from 1 sec to 0.5 sec
 * 
 *    Rev 1.68   May 07 2004 16:31:58   mtk00798
 * Remove header includings in header
 * Resolution for 5330: Remove header includings in header
 * 
 *    Rev 1.67   May 05 2004 14:35:28   mtk00798
 * Refactor codes to reduce the size of RW Data
 * 
 *    Rev 1.66   May 03 2004 13:16:02   mtk00798
 * Refactor variable names to meet naming convention
 * Resolution for 5245: Refactor variable names to meet naming convention
 * 
 *    Rev 1.65   May 01 2004 18:48:02   mtk00798
 * adjust structure for 4 bytes alignment to save SRAM
 * 
 *    Rev 1.64   Apr 30 2004 21:45:40   mtk00798
 * show playing song name in sub LCD
 * Resolution for 5203: Show playing song name in sub LCD
 * 
 *    Rev 1.63   Apr 28 2004 21:29:54   mtk00798
 * add popup "Exceed File Limit" message for over 64K bytes midi files when add to rings
 * Resolution for 5170: Popup "Exceed File Limit" message for over 64K bytes midi files when add to rings
 * 
 *    Rev 1.62   Apr 28 2004 16:13:14   mtk00798
 * fix a bug about handling fmgr call back function
 * Resolution for 4615: Update Audio Player v0.2
 * 
 *    Rev 1.61   Apr 28 2004 13:56:28   mtk00798
 * refactor codes
 * Resolution for 4615: Update Audio Player v0.2
 * 
 *    Rev 1.60   Apr 28 2004 10:39:50   mtk00798
 * (1) if play list file does not exist in audio player main screen, create a empty file (list-auto-gen OFF) or regenerate it (list-auto-gen ON)
 * (2) stop a file after background play resume if its previous state is paused
 * (3) move text (big5 or gb) to usc2 function to text_encoding.c(.h)
 * Resolution for 5165: (1) if play list file does not exist in audio player main screen, create a empty file (list-auto-gen OFF) or regenerate it (list-auto-gen ON)
 * 
 *    Rev 1.59   Apr 27 2004 14:24:54   mtk00798
 * comment out show sub LCD part
 * Resolution for 5155: Fix a Compile Error, comment out show sub LCD part
 * 
 *    Rev 1.58   Apr 26 2004 17:20:10   mtk00798
 * Fix a bug that a short song name doesn't stop scrolling after a scolled (long) song name in idle screen
 * Resolution for 5134: Fix a bug that a short song name doesn't stop scrolling after a scolled (long) song name in idle screen
 * 
 *    Rev 1.57   Apr 25 2004 19:05:04   mtk00798
 * (1) add card plug in/out handling
 * (2) adjust skin LSK, RSK drawing
 * (3) more bug fixs
 * Resolution for 5087: Add Card Plug In/Out Handling & more Bugs Fix
 * 
 *    Rev 1.56   Apr 22 2004 10:25:46   mtk00798
 * (1) hide playlist file
 * (2) refine skin layout
 * (3) add AWB file type
 * (4) add 2 more skins
 * Resolution for 5035: Hide PlayList File, Refine Skin Layout, Add AWB file type, Add 2 more skins
 * 
 *    Rev 1.55   Apr 20 2004 22:30:26   mtk00798
 * add regen list option
 * Resolution for 5020: Add Regenerate List Option
 * 
 *    Rev 1.54   Apr 20 2004 22:06:54   mtk00798
 * fix list-auto-gen bug
 * Resolution for 4615: Update Audio Player v0.2
 * 
 *    Rev 1.53   Apr 20 2004 18:47:46   mtk00798
 * eliminate all asserts
 * Resolution for 4615: Update Audio Player v0.2
 * 
 *    Rev 1.52   Apr 19 2004 17:46:24   mtk00798
 * update audio player v0.2 copyright header
 * Resolution for 4615: Update Audio Player v0.2
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_include.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif 

#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "HardwareEvents.h"
#include "Thrdosinterface.h"
#include "OSThreadInterfaceGprot.h"
#include "CallmanagementIdDef.h"
#include "Ucs2prot.h"

#include "gpioInc.h"
#include "MainMenuDef.h"
#include "FunAndGamesDefs.h"
#include "CustomCfg.h"

#include "ExtDeviceDefs.h"

#include "FileManagerGProt.h"

#include "ProfileGprots.h"
#include "UserProfilesResDef.h"
#include "SettingProfile.h"


#include "FileManagerDef.h"

#ifdef __MMI_FM_RADIO__
void mmi_fmrdo_power_on(BOOL turn_on);
#endif 

#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
#include "wgui_status_icons.h"
#ifdef __MMI_SUBLCD_MASTER_MODE__
#endif
/*add global vars*/
U16 g_mmi_sub_audply_option_highlighted_item =0;
U16 g_mmi_sub_audply_repeat_highlighted_item =0;
U16 g_mmi_sub_audply_highlighted_playlist_item = 0;
typedef void (*FuncPtr) (void);
extern void (*SUBLCD_ExitCategoryFunction) (void) ;
extern void EntrySubNewScreen(U16 scrID,FuncPtr exitfunc,FuncPtr entryfunc);

FuncPtr mmi_sub_audply_option_func[6];

/*extern global variables*/
extern GDI_HANDLE audply_skin_layer;
extern GDI_HANDLE audply_osd_layer;
extern scrolling_text audply_main_scrolling_title;
#endif
/* dependent headers for AudioPlayerXXX.h" */
#include "gui_data_types.h"
#include "mdi_datatype.h"
#include "Conversions.h"
#include "FileMgr.h"
#include "ProfileMgrGProt.h"
#include "Med_v_struct.h"

#include "aud_daf_parser.h"

#include "mdi_audio.h"
#include "AudioPlayerDef.h"
#include "AudioPlayerType.h"
#include "AudioPlayerProt.h"
#include "AudioPlayerMainScreen.h"
#include "AudioPlayerPlayList.h"

#include "Drm_gprot.h"
#ifdef __DRM_SUPPORT__
extern void mdi_audio_drm_disable_consume_count(void);
extern kal_char *DRM_get_content_ext(FS_HANDLE input, kal_wchar *path);
#endif /* __DRM_SUPPORT__ */ 
static BOOL is_multi_part_odf = FALSE;

#ifdef __MMI_SOUND_EFFECT__
#include "SettingDefs.h"
#include "SoundEffect.h"
#endif /* __MMI_SOUND_EFFECT__ */ 

#if defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
#include "SettingDefs.h"
#endif /* #if defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) */ 

/* MTK Leo add 20050301, add touch screen support for Audio Player */
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 
/* MTK Leo end */

#include "USBDeviceGprot.h"

#ifdef __MMI_AVRCP_SUPPORT__
#include "BTMMICM.h"
#include "BTMMIAVRCPGProt.h"
static U8 mmi_audply_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events key_events);
#endif /* __MMI_AVRCP_SUPPORT__ */ 

#ifdef __MMI_A2DP_SUPPORT__
#include "SimDetectionGprot.h"
#include "BTMMIScrGprots.h"
#include "av_bt.h"
#endif /* __MMI_A2DP_SUPPORT__ */

#define GET_WCHAR(x) ( (UI_character_type)( (*(x)) | ((*(x+1))<<8) ) )

/* For single play */
U8 single_play_state = STATE_IDLE;
U32 single_play_duration;
kal_uint32 single_play_time;
BOOL in_single_play_screen = FALSE;
U8 single_volume = 5;
static void (*single_play_exit_callback_func) (void) = NULL;

#ifdef __MMI_AUDIO_PLAYER__

/* detail */
U16 g_mmi_audply_detail_fields[MAX_DAF_VIEW_FIELDS];

/* settings */
UI_string_type g_mmi_audply_settings_list_auto_gen[2];
#ifndef __MMI_SLIM_AUDIO_PLAYER__
UI_string_type g_mmi_audply_settings_skin[NO_OF_SKIN];
#endif
UI_string_type g_mmi_audply_settings_repeat[3];
UI_string_type g_mmi_audply_settings_shuffle[2];
#ifndef __MMI_AUDIO_PLAYER_ON_SUBLCD__    
UI_string_type g_mmi_audply_settings_background_play[2];
#endif
//UI_string_type g_mmi_audply_settings_preferred_list[NO_OF_LIST];
#ifdef __MMI_A2DP_SUPPORT__
PS8 g_mmi_audply_settings_bt_a2dp_output[2];
#endif

#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
extern UI_string_type g_settings_audio_effects_inline1[NO_OF_SETTINGS_SOUND_EFFECTS];
extern UI_string_type g_settings_audio_effects_inline2[MAX_EQUALIZER_NUM]; /*use MAX_EQUALIZER_NUM since currently it is the largest one*/
extern S32 g_settings_selected_audio_effect;
extern S32 g_settings_current_effect_index;
extern S32 g_settings_current_audio_effect_prev;
extern S32 g_settings_current_audio_effect;
extern U16 current_audio_equalizer_index;
extern U16 current_audio_reverb_index;
extern U16 current_audio_surround_index;
#endif

#ifdef __MMI_AUDIO_EQUALIZER__
UI_string_type g_mmi_audply_settings_equalizer[MAX_EQUALIZER_NUM];
#endif 
#ifdef __MMI_AUDIO_REVERB_EFFECT__
UI_string_type g_mmi_audply_settings_reverb[MAX_AUDIO_REVERB_EFFECT_NUM];
#endif 
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
UI_string_type g_mmi_audply_settings_surround[AUD_SURROUND_TOTAL];
#endif

#ifdef __MMI_AUDIO_TIME_STRETCH__
UI_string_type g_mmi_audply_settings_speed[MDI_AUDIO_MAX_SPEED_NUM];
#endif

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
UI_string_type g_mmi_audply_settings_spectrum[3];
#endif 
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
UI_string_type g_mmi_audply_settings_lyrics[2];
#endif

static S32 selected_list_auto_gen;
static S32 selected_preferred_list;
#ifndef __MMI_SLIM_AUDIO_PLAYER__
static S32 selected_skin;
#endif
static S32 selected_repeat_mode;        /* 0: off, 1: repeat one, 2: repeat all */
static S32 selected_random_mode;        /* 0: off, 1: on */
#ifndef __MMI_AUDIO_PLAYER_ON_SUBLCD__    
static S32 selected_background_play;    /* 0: off, 1: on */
#endif
#ifdef __MMI_A2DP_SUPPORT__
static S32 selected_bt_a2dp_output;     /* -1: block, 0: off, 1: on */
#endif

#ifdef __MMI_AUDIO_TIME_STRETCH__
static S32 selected_speed_index;
#endif 
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__ 
static S32 selected_spectrum_style;
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
static S32 selected_lyrics_style;
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
extern U8 audply_spectrum_lyrics_exclusive;
#endif 
#endif /*__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__*/

static BOOL settings_done_back_to_main;

static MMI_BOOL g_mmi_audply_is_folder_empty = MMI_TRUE;

U16 g_mmi_audply_two_layer_settings_highlighted_item;
U16 g_mmi_audply_option_highlighted_item;
S16 g_mmi_audply_list_highlighted_item;

/* detail */
aud_info_struct *daf_info_p = NULL;

/* drives and paths */
UI_character_type fullfilename_temp[FMGR_MAX_PATH_LEN + 1];

/* This variable is used to avoid repeating on a short file too quick and cause a result to block other commands */
BOOL g_mmi_audply_play_completed_after_button_down;

/* indicate if audply just undergo longpressing so that the button up handler shall take different action*/
BOOL g_mmi_audply_longpressed = FALSE;
/* indicate if the state before longpress is STATE_PLAY */
BOOL g_mmi_audply_non_play_longpressed = FALSE;

extern signed char g_audply_main_selected_button;   /* defined in AudioPlayerMainScreen.c */
extern BOOL g_audply_main_selected_button_down;     /* defined in AudioPlayerMainScreen.c */
extern wgui_inline_item wgui_inline_items[];        /* wgui_inline_edit.c */
extern void (*RedrawCategoryFunction) (void);   /* defined in wgui_categories.c */

extern void ShowIdleAppSubLcd(void);

/* main control object */
audply_struct g_audply;

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
BOOL g_audply_spectrum_valid;
BOOL g_audply_spectrum_blocked = FALSE; /*indicate if spectrum is blocked bt others. EX : A2DP*/
#endif

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
/* main control object of lyric */
audply_lyric_struct audply_lyric;
BOOL lyric_reEntry; /*to prevent from drawing the same lyrics more than one time unless once it exits main screen*/
BOOL g_audply_lyrics_valid;
extern U8 PhnsetGetDefEncodingType(void);
extern BOOL lyric_parse_ok ;
#ifdef __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__
extern S8* g_mmi_lyric_str_buff ;
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
U16 g_audply_lyrics_setting_item_num ; /* indicate the item num of lyrics and spectrum to change text when they are exclusive */
U16 g_audply_spectrum_setting_item_num ;
#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 

/* for refresh list and add a folder inlcuding audio files */
static FS_HANDLE add_file_cursor = -1;
static FS_HANDLE list_data_file_handle = -1;
UI_character_type add_file_path[FMGR_MAX_PATH_LEN + 1];

BOOL g_mmi_audply_init_done = FALSE;
extern audply_skin_struct g_audply_skins[NO_OF_SKIN];   /* defined in resource_audply_skins.c */
 
U32 g_mmi_audply_seek_target_time; /*progress seeking target time*/
#ifdef __MMI_TOUCH_SCREEN__
extern S32 g_audply_progress_bar_pen_down_x_pos ;
extern S32 audply_pen_event_on_object;
#endif

U32 audio_build_cache_progress;
#ifdef __MTK_TARGET__
__align(4)
#endif /* __MTK_TARGET__ */
U8 audio_cache[BUILD_CACHE_SIZE];

/*mp3 amr aac awb are the four audio types which requires building cache to seek, so we put them 
in the frist four items for build cache deciding api to reference*/
const UI_character_type audio_file_lower_exts[][5] = 
{
#ifdef DAF_DECODE
    L"mp3",
#ifdef MUSICAM_DECODE    
    L"mp2",
#endif    
#endif 
    L"amr", 
#ifdef AAC_DECODE
    L"aac",
#endif 
#ifdef AMRWB_DECODE
    L"awb",
#endif 
#ifdef __DRM_V02__
    L"odf",
#endif
    L"wav",   
    L"mid",
    L"imy"
//    L"vm ",
#ifdef AIFF_DECODE
    ,L"aif"
    ,L"aiff"
    ,L"aifc"
#endif
#ifdef AU_DECODE
    ,L"au "
    ,L"snd"
#endif
#ifdef AAC_DECODE
        , L"m4a"
#endif 
#ifdef YAMAHA_MA3
        , L"mmf"
#endif 
#ifdef WMA_DECODE
        , L"wma"
#endif 
#if defined(__MMI_PURE_AUDIO__)
    , L"3gp"
    , L"mp4"
#endif
};
const UI_character_type audio_file_upper_exts[][5] = 
{
#ifdef DAF_DECODE
    L"MP3",
#ifdef MUSICAM_DECODE    
    L"MP2",
#endif    
#endif 
    L"AMR",
#ifdef AAC_DECODE
    L"AAC",
#endif 
#ifdef AMRWB_DECODE
    L"AWB",
#endif 
#ifdef __DRM_V02__
    L"ODF",
#endif
    L"WAV",
    L"MID",
    L"IMY"
//    L"VM ",
#ifdef AIFF_DECODE
    ,L"AIF"
    ,L"AIFF"
    ,L"AIFC"
#endif
#ifdef AU_DECODE
    ,L"AU "
    ,L"SND"
#endif
#ifdef AAC_DECODE
        , L"M4A"
#endif 
#ifdef YAMAHA_MA3
        , L"MMF"
#endif 
#ifdef WMA_DECODE
        , L"WMA"
#endif 
#if defined(__MMI_PURE_AUDIO__)
    , L"3GP"
    , L"MP4"
#endif
};
const U16 audio_file_icon_ids[] = 
{
#ifdef DAF_DECODE
    IMG_ID_AUDPLY_FILE_AUD_ICON,
#ifdef MUSICAM_DECODE
    IMG_ID_AUDPLY_FILE_AUD_ICON,
#endif
#endif
    IMG_ID_AUDPLY_FILE_AMR_ICON, 
#ifdef AAC_DECODE
    IMG_ID_AUDPLY_FILE_AAC_ICON,
#endif 
#ifdef AMRWB_DECODE
    IMG_ID_AUDPLY_FILE_AWB_ICON,
#endif 
#ifdef __DRM_V02__
    IMG_ID_FMGR_ICON_FILE_TYPE_ODF,
#endif
    IMG_ID_AUDPLY_FILE_WAV_ICON,
    IMG_ID_AUDPLY_FILE_MID_ICON,
    IMG_ID_AUDPLY_FILE_IMY_ICON
//    IMG_ID_AUDPLY_FILE_AUD_ICON, // for .VM
#ifdef AIFF_DECODE
    ,IMG_ID_AUDPLY_FILE_AIF_ICON
    ,IMG_ID_AUDPLY_FILE_AIF_ICON
    ,IMG_ID_AUDPLY_FILE_AIF_ICON
#endif
#ifdef AU_DECODE
    ,IMG_ID_AUDPLY_FILE_AU_ICON
    ,IMG_ID_AUDPLY_FILE_SND_ICON
#endif
#ifdef AAC_DECODE
  , IMG_ID_AUDPLY_FILE_M4A_ICON
#endif 
#ifdef YAMAHA_MA3
  , IMG_ID_AUDPLY_FILE_MMF_ICON
#endif 
#ifdef WMA_DECODE
  , IMG_ID_AUDPLY_FILE_WMA_ICON
#endif 
#if defined(__MMI_PURE_AUDIO__)
  ,IMG_ID_AUDPLY_FILE_3GP_ICON
  ,IMG_ID_AUDPLY_FILE_MP4_ICON
#endif
};

/* string id of option item */
static U16 option_texts[7]; /* keep option text id array here because we need to check highlight text id in mmi_audply_option_right_arrow_key */

/* for regenerate/refresh list */
BOOL need_refresh_list = FALSE;
BOOL need_reload_list = FALSE;
BOOL no_card_in_slot = FALSE;
#ifdef __DRM_V02__
static void* find_cntx = NULL;
#endif

#ifdef __MMI_MY_FAVORITE__
#define AUDPLY_AUDIO_FOLDER		FMGR_DEFAULT_FOLDER_AUDIO
#endif

static void mmi_audply_check_fmr_state(void);

#ifdef __MMI_A2DP_SUPPORT__

/* av bt */
extern kal_int32 med_util_utf8_to_ucs2(kal_uint8 *dest, kal_uint32 dest_size, kal_uint8 *src, kal_uint32 src_size);

typedef struct
{
    BOOL bt_a2dp_output;
    BOOL bt_a2dp_headset_valid;
    mmi_bt_dev_struct bt_a2dp_headset;
} mmi_audply_bt_settings_struct;

static BOOL wait_fot_bt_pwron;
static mmi_audply_bt_settings_struct bt_settings;

static mmi_bt_dev_struct *selected_bt_a2dp_headset_temp;
static UI_character_type setting_bt_a2dp_headset_name[(MMI_BT_BD_NAME_LEN+1)/2];
static void mmi_audply_sap_block_a2dp(void);
static U8 *mmi_audply_bts_inline_change_select_callback(void);
static U8 *mmi_audply_bts_inline_default_callback(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_output_to_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_audply_is_output_to_bt(void)
{
    return (mmi_bt_is_power_on(FALSE) && !mmi_bootup_get_active_flight_mode() && 
        bt_settings.bt_a2dp_output);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_bt_headset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_bt_dev_struct*
 *****************************************************************************/
mmi_bt_dev_struct *mmi_audply_get_bt_headset(void)
{
    if (bt_settings.bt_a2dp_headset_valid)
        return &bt_settings.bt_a2dp_headset;
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_read_bt_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_read_bt_settings(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ReadRecord(NVRAM_EF_AUDIO_PLAYER_BT_SETTINGS_LID, 1, (void*)&bt_settings,
        sizeof(mmi_audply_bt_settings_struct), &error);
#else
    bt_settings.bt_a2dp_output = FALSE;
    bt_settings.bt_a2dp_headset_valid = FALSE;
#endif /* __MTK_TARGET__ */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_write_bt_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_write_bt_settings(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_AUDIO_PLAYER_BT_SETTINGS_LID, 1, (void*)&bt_settings,
        sizeof(mmi_audply_bt_settings_struct), &error);
#endif /* __MTK_TARGET__ */
}
#endif /* __MMI_A2DP_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_read_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_read_settings(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_AUDPLY_LIST_AUTO_GEN, &g_audply.list_auto_gen, DS_BYTE, &error);
    ReadValue(NVRAM_AUDPLY_VOLUME, &g_audply.volume, DS_BYTE, &error);
    ReadValue(NVRAM_AUDPLY_PREFER_LIST, &g_audply.preferred_list, DS_BYTE, &error);

    if(!mmi_fmgr_is_drive_letter_valid(g_audply.preferred_list))
    {
        g_audply.preferred_list = (U8)MMI_PUBLIC_DRV;
    }
    ReadValue(NVRAM_AUDPLY_SKIN, &g_audply.skin, DS_BYTE, &error);
    ReadValue(NVRAM_AUDPLY_REPEAT, &g_audply.repeat_mode, DS_BYTE, &error);
    ReadValue(NVRAM_AUDPLY_SHUFFLE, &g_audply.random_mode, DS_BYTE, &error);
    ReadValue(NVRAM_AUDPLY_BACKGROUND_PLAY, &g_audply.background_play, DS_BYTE, &error);

#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
    if(!g_audply.background_play)
    {
        g_audply.background_play = 1;
        WriteValue(NVRAM_AUDPLY_BACKGROUND_PLAY, &g_audply.background_play, DS_BYTE, &error);
    }
#endif

#ifdef __MMI_SLIM_AUDIO_PLAYER__
    if(g_audply.skin != 0)
    {
        g_audply.skin = 0;
        WriteValue(NVRAM_AUDPLY_SKIN, &g_audply.skin, DS_BYTE, &error);
    }
#endif

#ifdef __MMI_AUDIO_TIME_STRETCH__
    ReadValue(NVRAM_AUDIO_SPEED_VALUE, &g_audply.speed, DS_SHORT, &error);
    if (g_audply.speed == 0xFFFF)
    {
        g_audply.speed = MDI_AUDIO_SPEED_NORMAL;
        WriteValue(NVRAM_AUDIO_SPEED_VALUE, &g_audply.speed, DS_SHORT, &error);
    }
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    ReadValue(NVRAM_AUDPLY_SPECTRUM_DISPLAY_STYLE, &g_audply.spectrum_style, DS_BYTE, &error);
    if (g_audply.spectrum_style > 2)    /* check does it out of range bcoz NVRAM data is incorrect or not initialized */
    {
        g_audply.spectrum_style = 1;
        WriteValue(NVRAM_AUDPLY_SPECTRUM_DISPLAY_STYLE, &g_audply.spectrum_style, DS_BYTE, &error);
    }   
#endif

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    ReadValue(NVRAM_AUDPLY_LYRICS_DISPLAY, &g_audply.lyrics_display, DS_BYTE, &error);
    if (g_audply.lyrics_display > 1)    /* check does it out of range bcoz NVRAM data is incorrect or not initialized */
    {
        g_audply.lyrics_display = 0;
        WriteValue(NVRAM_AUDPLY_LYRICS_DISPLAY, &g_audply.lyrics_display, DS_BYTE, &error);
    }    
#endif

#else /* __MTK_TARGET__ */ 
    g_audply.list_auto_gen = 1;
    g_audply.volume = 4;
    g_audply.preferred_list = (U8)MMI_PUBLIC_DRV;
    g_audply.skin = 0;
    g_audply.repeat_mode = 0;
    g_audply.random_mode = 0;
    g_audply.background_play = 1;

#ifdef __MMI_AUDIO_TIME_STRETCH__
    g_audply.speed = MDI_AUDIO_SPEED_NORMAL;
    g_audply.speed_set_times = 0;
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    g_audply.spectrum_style = 1;
#endif

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    g_audply.lyrics_display = 0;
#endif

#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_write_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_write_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_AUDPLY_LIST_AUTO_GEN, &g_audply.list_auto_gen, DS_BYTE, &error);
    WriteValue(NVRAM_AUDPLY_VOLUME, &g_audply.volume, DS_BYTE, &error);
    WriteValue(NVRAM_AUDPLY_PREFER_LIST, &g_audply.preferred_list, DS_BYTE, &error);
#ifndef __MMI_SLIM_AUDIO_PLAYER__  
    WriteValue(NVRAM_AUDPLY_SKIN, &g_audply.skin, DS_BYTE, &error);
#endif
    WriteValue(NVRAM_AUDPLY_REPEAT, &g_audply.repeat_mode, DS_BYTE, &error);
    WriteValue(NVRAM_AUDPLY_SHUFFLE, &g_audply.random_mode, DS_BYTE, &error);
#ifndef __MMI_AUDIO_PLAYER_ON_SUBLCD__    
    WriteValue(NVRAM_AUDPLY_BACKGROUND_PLAY, &g_audply.background_play, DS_BYTE, &error);
#endif

#ifdef __MMI_AUDIO_TIME_STRETCH__
    WriteValue(NVRAM_AUDIO_SPEED_VALUE, &g_audply.speed, DS_SHORT, &error);
#endif 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    WriteValue(NVRAM_AUDPLY_SPECTRUM_DISPLAY_STYLE, &g_audply.spectrum_style, DS_BYTE, &error);
#endif

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    WriteValue(NVRAM_AUDPLY_LYRICS_DISPLAY, &g_audply.lyrics_display, DS_BYTE, &error);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_audply_get_volume()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_audply_init_done)
    {
    #ifdef __MTK_TARGET__
        S16 error;

        ReadValue(NVRAM_AUDPLY_VOLUME, &g_audply.volume, DS_BYTE, &error);
    #else /* __MTK_TARGET__ */ 
        g_audply.volume = 4;
    #endif /* __MTK_TARGET__ */ 
    }

    return g_audply.volume;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_save_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume      [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_audply_save_volume(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.volume = volume;
    WriteValue(NVRAM_AUDPLY_VOLUME, &g_audply.volume, DS_BYTE, &error);

    return (error == NVRAM_WRITE_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_set_subLCD_shown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_set_subLCD_shown(BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.is_subLCD_shown = is_shown;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_delete_history_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_param        [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_audply_delete_history_hdlr(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_audply.background_play)
    {
        // There is a case that state = STATE_IDLE and need_replay = TRUE
        // and we need to prevent from replay after this function call by setting need_replay = FALSE
        g_audply.need_replay = FALSE;
        mmi_audply_stop_playing();
        g_mmi_audply_longpressed = FALSE ;
        g_mmi_audply_non_play_longpressed = FALSE ;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  InitAudioPlayerApp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitAudioPlayerApp()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(AUDIO_PLAYER_MAIN_MENUID, HighlightAudioPlayer);
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    SetHiliteHandler(MAIN_MENU_OPTION_AUDIO_PLAYER_APP, HighlightAudioPlayer);
#endif 
    g_audply.state = STATE_IDLE;
    g_audply.is_subLCD_shown = FALSE;
    mmi_audply_read_settings();

#ifdef __MMI_A2DP_SUPPORT__
    mmi_audply_read_bt_settings();
    av_bt_set_default_callback(mmi_audply_bt_open_callback);
#endif

#ifdef __MMI_AVRCP_SUPPORT__
    mmi_bt_avrcp_set_cmd_hdlr(mmi_audply_bt_avrcp_cmd_hdlr);
#endif 
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
	SetHiliteHandler(MENU_ID_SUB_AUDPLY,  HighlightSubAudioPlayer);
	g_audply.in_sub_screen = FALSE;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  HighlightAudioPlayer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightAudioPlayer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_audply_check_fmr_state, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_audply_check_fmr_state, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_check_fmr_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_audply_check_fmr_state_idle(void)
{
mmi_audply_check_fmr_state();
}
static void mmi_audply_check_fmr_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_RADIO__
    if (mmi_fmrdo_is_power_on())
    {
        DisplayConfirm(
               STR_GLOBAL_YES,
               IMG_GLOBAL_YES,
               STR_GLOBAL_NO,
               IMG_GLOBAL_NO,
               get_string(STR_ID_AUDPLY_STOP_FMR),
               IMG_GLOBAL_QUESTION,
               WARNING_TONE);

        SetLeftSoftkeyFunction(mmi_audply_entry_main, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
#endif /* __MMI_FM_RADIO__ */
    {
        mmi_audply_entry_main();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_main_button_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_update_main_button_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply_main_selected_button_down = FALSE;

    /* need to check current condition */
    if (g_audply.n_total_items == 0 && (g_audply.state == STATE_IDLE && !g_mmi_audply_longpressed))
    {
        g_audply_main_selected_button = (signed char)AUDPLY_MAIN_DISABLED;
    }
    else
    {
        switch (g_audply.state)
        {
            case STATE_IDLE:
                if (g_audply.need_restore)
                {
                    g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PAUSE;
                }
                else
                {
                    g_audply_main_selected_button = (signed char)AUDPLY_MAIN_STOP;
                }
                break;
            case STATE_PLAY:
                g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PLAY;
                break;
            case STATE_PAUSED:
                #ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
                if(g_audply.in_sub_screen)
                {
                    g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PLAY;
                }
                else
                #endif
                g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PAUSE;
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_update_main()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    audply_skin_struct *skin_p;
    FuncPtr button_press_hdlr[] = 
    {
        mmi_audply_press_play_button_down,  /* AUDPLY_MAIN_PLAY */
        mmi_audply_press_prev_button_down,  /* AUDPLY_MAIN_PREV */
        mmi_audply_press_next_button_down,  /* AUDPLY_MAIN_NEXT */
        mmi_audply_press_stop_button_down   /* AUDPLY_MAIN_STOP */
    };
    FuncPtr button_release_hdlr[] = 
    {
        mmi_audply_press_play_button_up,    /* AUDPLY_MAIN_PLAY */
        mmi_audply_press_prev_button_up,    /* AUDPLY_MAIN_PREV */
        mmi_audply_press_next_button_up,    /* AUDPLY_MAIN_NEXT */
        mmi_audply_press_stop_button_up     /* AUDPLY_MAIN_STOP */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_update_main_button_flag();

    /* show main screen */
    mmi_audply_show_mainscreen(STR_ID_AUDPLY_TITLE, STR_ID_AUDPLY_LIST, STR_GLOBAL_BACK, g_audply.skin);

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    /* re print lyric, or it will  only be written while next lyric time tag is reached. */
    if (g_audply.lyrics_display && g_audply.state != STATE_IDLE && g_audply_lyrics_valid)
    {
#ifndef __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__
        U8 new_encoding_type = PhnsetGetDefEncodingType() ;
        if(audply_lyric.lrc_encoding_chset != new_encoding_type )   
        {
            lyric_parse_ok = mmi_audply_init_lyric();
        }
#else
        lyric_parse_ok = mmi_audply_init_lyric();
#endif /* __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__ */
        mmi_audply_lyric_on_time();
    }
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 

    /* register LSK, RSK hanlders */
    SetKeyHandler(mmi_audply_entry_list, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);

    /* register play / pause, stop, prev, next button handlers */
    skin_p = &g_audply_skins[g_audply.skin];
    SetKeyHandler(button_release_hdlr[skin_p->left_key_mapping], KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(button_release_hdlr[skin_p->right_key_mapping], KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(button_release_hdlr[skin_p->up_key_mapping], KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(button_release_hdlr[skin_p->down_key_mapping], KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(button_press_hdlr[skin_p->left_key_mapping], KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(button_press_hdlr[skin_p->right_key_mapping], KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(button_press_hdlr[skin_p->up_key_mapping], KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(button_press_hdlr[skin_p->down_key_mapping], KEY_DOWN_ARROW, KEY_EVENT_DOWN);

    /*register next / prev button long press handlers*/
    if(skin_p->left_key_mapping == AUDPLY_MAIN_PREV)
    {
        SetKeyHandler(mmi_audply_press_prev_button_longpress, KEY_LEFT_ARROW, KEY_EVENT_LONG_PRESS);
    }
    else if(skin_p->right_key_mapping == AUDPLY_MAIN_PREV)
    {
        SetKeyHandler(mmi_audply_press_prev_button_longpress, KEY_RIGHT_ARROW, KEY_EVENT_LONG_PRESS);
    }
    else if(skin_p->up_key_mapping == AUDPLY_MAIN_PREV)
    {
        SetKeyHandler(mmi_audply_press_prev_button_longpress, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);
    }
    else
    {
        SetKeyHandler(mmi_audply_press_prev_button_longpress, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);
    }

    if(skin_p->left_key_mapping == AUDPLY_MAIN_NEXT)
    {
        SetKeyHandler(mmi_audply_press_next_button_longpress, KEY_LEFT_ARROW, KEY_EVENT_LONG_PRESS);
    }
    else if(skin_p->right_key_mapping == AUDPLY_MAIN_NEXT)
    {
        SetKeyHandler(mmi_audply_press_next_button_longpress, KEY_RIGHT_ARROW, KEY_EVENT_LONG_PRESS);
    }
    else if(skin_p->up_key_mapping == AUDPLY_MAIN_NEXT)
    {
        SetKeyHandler(mmi_audply_press_next_button_longpress, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);
    }
    else
    {
        SetKeyHandler(mmi_audply_press_next_button_longpress, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);
    }

#ifdef __MMI_NO_VOL_KEYS__
	// 没有音量键的处理
	#if defined(__VOL_WITH_28KEY__)
	  SetKeyHandler(mmi_audply_press_inc_volume_down, KEY_2, KEY_EVENT_DOWN);
	   SetKeyHandler(mmi_audply_press_inc_volume_up, KEY_2, KEY_EVENT_UP);
	   SetKeyHandler(mmi_audply_press_dec_volume_down, KEY_8, KEY_EVENT_DOWN);
	   SetKeyHandler(mmi_audply_press_dec_volume_up, KEY_8, KEY_EVENT_UP);		
	   
	#else	 
          SetKeyHandler(mmi_audply_press_inc_volume_down, KEY_2, KEY_EVENT_DOWN);
   	   SetKeyHandler(mmi_audply_press_inc_volume_up, KEY_2, KEY_EVENT_UP);
          SetKeyHandler(mmi_audply_press_dec_volume_down, KEY_5, KEY_EVENT_DOWN);
	   SetKeyHandler(mmi_audply_press_dec_volume_up, KEY_5, KEY_EVENT_UP);
       #endif
#else
    /* register volume inc, dec handlers */
       SetKeyHandler(mmi_audply_press_inc_volume_down, KEY_VOL_UP, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_audply_press_inc_volume_up, KEY_VOL_UP, KEY_EVENT_UP);
       SetKeyHandler(mmi_audply_press_dec_volume_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_audply_press_dec_volume_up, KEY_VOL_DOWN, KEY_EVENT_UP);
#endif

#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_register_down_handler(mmi_audply_pen_down_hdlr);
    mmi_pen_register_up_handler(mmi_audply_pen_up_hdlr);
    mmi_pen_register_move_handler(mmi_audply_pen_move_hdlr);
    mmi_pen_register_abort_handler(mmi_audply_pen_up_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    
}


#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 
extern void Process_Music_G_Sensor(void);
extern void SendMessagesMMIToOne(msg_type MSG_ID );
#endif

#if defined(HORSERACE_SUPPORT)
//Huyanwei Add It 
extern void SendMessagesMMIToTwo(msg_type MSG_ID);
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_main()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type list_name ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        

    kal_prompt_trace(MOD_MMI_MEDIA_APP,"[Audply]Entry main screen, init=%d",g_mmi_audply_init_done);
    
#ifdef __USB_IN_NORMAL_MODE__
    /* check is in mass storage mode */
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, cant use this app */
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (FS_GetDevStatus(mmi_audply_get_preferred_or_available_list(), FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
    {
        DisplayPopup(
            (PU8)GetString(GetFileSystemErrorString(FS_DEVICE_BUSY)),
            IMG_GLOBAL_ERROR,
            1,
            1000,
            (U8)ERROR_TONE);
       return;
    }
    EntryNewScreen(SCR_ID_AUDPLY_MAIN, mmi_audply_exit_main, NULL, MMI_FULL_SCREEN);

    /*alloc screen based memory*/
#ifdef __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__
    g_mmi_lyric_str_buff = mmi_frm_scrmem_alloc(AUDPLY_LYRIC_STR_BUFF_MAX_SIZE) ;
#endif
    g_audply.audio_cache_file_buf_p = mmi_frm_scrmem_alloc(BUILD_CACHE_FILE_BUF_SIZE);
    g_audply.audio_cache_proc_buf_p = mmi_frm_scrmem_alloc(BUILD_CACHE_PROC_BUF_SIZE);

    entry_full_screen();

#ifdef __MMI_FM_RADIO__
    mmi_fmrdo_power_on(FALSE);
#endif 

    /* initialization after re-power on */
    if (!g_mmi_audply_init_done)
    {
        /* register mdi background handler */
        mdi_audio_set_background_handler(MDI_BACKGROUND_APP_AUDPLY, mmi_audply_background_callback_hdlr);
        g_audply.need_restore = FALSE;
        g_audply.wait_next = FALSE;
        g_audply.need_replay = FALSE;
        g_audply.continue_playing = FALSE;
        g_audply.in_list_screen = FALSE;
        g_audply.state = STATE_IDLE;
        g_mmi_audply_play_completed_after_button_down = FALSE;
        g_audply.n_total_items = 0;
        g_audply.pick_index = -1;

        g_audply.present_list = mmi_audply_get_preferred_or_available_list();
        /*initialize cache*/
        mmi_audply_initialize_cache();
    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        lyric_reEntry = TRUE; 
    #endif 
    }

    if (g_audply.n_total_items == 0 && g_audply.state == STATE_IDLE)
    {
        g_audply.restorable = FALSE;
        g_audply.seekable = FALSE;
        g_audply.need_to_build_cache = FALSE;
    }
    
    list_name = mmi_audply_get_present_list_file();

    if (!g_mmi_audply_init_done)
    {
        if (mmi_audply_does_file_exist(list_name))
        {
            mmi_audply_regen_and_reload_playlist(FALSE, TRUE);
        }
        mmi_audply_update_main();
        g_audply.in_main_screen = TRUE;
        g_mmi_audply_init_done = TRUE;

        if (g_audply.list_auto_gen || !mmi_audply_does_file_exist(list_name))
        {
            mmi_audply_regen_and_reload_playlist(TRUE, TRUE);
        }
    }
    else
    {
        if (need_reload_list)
        {
            mmi_audply_regen_and_reload_playlist(FALSE, need_reload_list);
        }
        
        if (!mmi_audply_does_present_list_file_exist())
        {
            if (g_audply.state == STATE_IDLE)
            {
                mmi_audply_regen_and_reload_playlist(FALSE, TRUE);
            }
            else
            {
                /*
                ** when audio player playing an audio file, 
                ** and the play list file was deleted.
                ** audio player will play current file complete, 
                ** then clear the infomation of this file display in main screen.
                */
                g_audply.n_total_items = 0;
                g_audply.pick_index = -1;
            }
        }

#ifdef __DRM_SUPPORT__
        if( g_audply.n_total_items>0 && g_audply.state == STATE_IDLE && !g_audply.seekable && !g_audply.need_restore)
        {
            S8 result = 0;
            result = mmi_audply_drm_valide_right((PU16)g_audply.filefullname);
            if(result == 1)
            {
                g_audply.seekable = TRUE;
            }
            else if(result ==2)
            {
                g_audply.seekable = FALSE;
            }
        }
#endif
        mmi_audply_update_main();
        g_audply.in_main_screen = TRUE;

       	if (need_refresh_list)
        {
            mmi_audply_regen_and_reload_playlist(need_refresh_list, TRUE);
        }
        else if (no_card_in_slot)
        {
            no_card_in_slot = FALSE;
        }
    }

    
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    mmi_audply_lyric_check_backlight(1);
#endif 
    SetDelScrnIDCallbackHandler(SCR_ID_AUDPLY_MAIN, (HistoryDelCBPtr) mmi_audply_delete_history_hdlr);

#if defined(G_SENSOR_SUPPORT)
	//Huyanwei Add It 
	//Process_Music_G_Sensor();
	SendMessagesMMIToOne(MSG_ID_GSENSOR_ON);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_main()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_prompt_trace(MOD_MMI_MEDIA_APP,"[Audply]Exit main screen");

    mmi_audply_seeking_exit_main();
    mmi_audply_exit_mainscreen();
    g_audply.in_main_screen = FALSE;

    /*free screen based memory*/
#ifdef __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__
    if(g_mmi_lyric_str_buff != NULL)
    {
        mmi_frm_scrmem_free(g_mmi_lyric_str_buff);
        g_mmi_lyric_str_buff = NULL ;
    }
#endif /*__MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__*/
    if(g_audply.audio_cache_file_buf_p !=NULL)
    {
        mmi_frm_scrmem_free(g_audply.audio_cache_file_buf_p);
        g_audply.audio_cache_file_buf_p = NULL ;
    }
    if(g_audply.audio_cache_proc_buf_p!=NULL)
    {
        mmi_frm_scrmem_free(g_audply.audio_cache_proc_buf_p);
        g_audply.audio_cache_proc_buf_p = NULL ;
    }

#ifdef  __MMI_TOUCH_SCREEN__
    kal_prompt_trace(MOD_MMI_MEDIA_APP,"[Audply]Clear touch");
    ClearInputEventHandler(MMI_DEVICE_PEN);
#endif

    currHistory.scrnID = SCR_ID_AUDPLY_MAIN;
    currHistory.entryFuncPtr = mmi_audply_entry_main;
    mmi_ucs2cpy((PS8)currHistory.inputBuffer, (const PS8)L"");
    AddHistory(currHistory);

#if defined(G_SENSOR_SUPPORT)
	//Huyanwei Add It 
	//Process_Music_G_Sensor();
	SendMessagesMMIToOne(MSG_ID_GSENSOR_OFF);
#endif
	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_seeking_exit_main
 * DESCRIPTION
 *  handle the exit main action in seeking process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_seeking_exit_main()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("AudPly: seeking exit main, longpressed : %d", g_mmi_audply_longpressed);
    if(g_mmi_audply_longpressed)
    {
        StopTimer(AUDPLY_SEEKING_TIMER);

        if (g_audply.need_to_build_cache)
        {
            /*stop budild cache*/
            mdi_audio_stop_build_cache();
        }
        
        g_audply_main_selected_button_down = FALSE;
        
        if (g_audply.in_main_screen)
        {
           mmi_audply_redraw_main_buttons();
        }
        
        if(g_audply.state_before_longpress == STATE_PLAY)
        {
            g_audply.need_replay = TRUE; /*when suspend over, make it replay*/
            g_audply.need_restore = FALSE;
            g_audply.continue_playing = FALSE;
        }
        else
        {
            g_mmi_audply_non_play_longpressed = TRUE;
            g_audply.state = g_audply.state_before_longpress;
        }
        
        g_mmi_audply_longpressed = FALSE ;
    }

    // to release the two buffers cause they are using screen bassed memory
    mdi_audio_close_build_cache();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_clear_play_seconds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_clear_play_seconds()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.new_play_time = 0;
    g_audply.old_play_time = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_play_seconds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U32  the played time, the unit is MS
 *****************************************************************************/
U32 mmi_audply_get_play_seconds()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_audply.new_play_time;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_play_seconds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_update_play_seconds()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_get_progress_time(&g_audply.new_play_time); 

#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
    if(g_audply.in_sub_screen)
    {
        if(g_audply.new_play_time - g_audply.old_play_time >= 1000)
        {
        	UI_set_sub_LCD_graphics_context();
            mmi_audply_redraw_main_time();
	        UI_set_main_LCD_graphics_context();
            g_audply.old_play_time = g_audply.new_play_time ;
            g_audply.old_play_time /= 1000 ;
            g_audply.old_play_time *= 1000 ;
        }
    }
#endif
    if(g_audply.in_main_screen)
    {
        PRINT_INFORMATION("AudPly: in main screen,try to update time, new=%d, old=%d, diff=%d\n",g_audply.new_play_time ,g_audply.old_play_time,g_audply.new_play_time - g_audply.old_play_time );
        if(g_audply.new_play_time - g_audply.old_play_time >= 1000)
        {
            PRINT_INFORMATION("AudPly: in main screen,update time, diff=%d\n",g_audply.new_play_time - g_audply.old_play_time );
            mmi_audply_redraw_main_time();
            g_audply.old_play_time = g_audply.new_play_time ;
            g_audply.old_play_time /= 1000 ;
            g_audply.old_play_time *= 1000 ;
        }
    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        if (g_audply.lyrics_display && g_audply_lyrics_valid)
        {
            mmi_audply_lyric_on_time();
        }
    #endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
        mmi_audply_redraw_main_progressbar();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_timer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.state == STATE_PLAY)
    {
        mmi_audply_update_play_seconds();
        StartTimer(AUDPLY_COUNT_PLAY_TIMER, 500, mmi_audply_timer);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_progress_target_time
 * DESCRIPTION
 *  update progress bar target time after duration updated
 * PARAMETERS
 *  U32     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_update_progress_target_time(U32 old_duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_mmi_audply_seek_target_time == old_duration)
    {
        g_mmi_audply_seek_target_time = g_audply.duration;
    }
#ifdef __MMI_TOUCH_SCREEN__    
    else if(g_mmi_audply_seek_target_time != 0 ) /*target time is in between 0 and old_duration*/
    {
        g_mmi_audply_seek_target_time = mmi_audply_get_proportional_time_from_x(g_audply_progress_bar_pen_down_x_pos);
    }
#endif


}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_total_duration_by_cache
 * DESCRIPTION
 *  update total duration by cache data
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_audply_update_total_duration_by_cache()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 duration ;
    U32 old_duration = g_audply.duration ;
    BOOL result = FALSE ;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mdi_audio_build_cache_get_total_duration(&duration))
    {
        if(duration != old_duration)
        {
            g_audply.duration = duration;
            result = TRUE ;
            PRINT_INFORMATION("Audply Progress Bar: duration updated, %d!!",duration);
        }
    }

    return result ;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_fast_forward
 * DESCRIPTION
 *  handling the timer and progress bar while fast forwarding
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_fast_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 duration ;
    U32 temp_play_time ;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("Audply | Debug: fast forward.");
    if (!g_audply.seekable && g_audply.in_main_screen)
    {
        PRINT_INFORMATION("Audply | Debug: !seekable.");
#ifdef __MMI_TOUCH_SCREEN__
        mmi_audply_touch_progress_pen_up();
#endif
       mmi_audply_redraw_main_progressbar() ;
       return ;
    }

    temp_play_time = g_audply.new_play_time ;
    g_audply.new_play_time += g_audply.progress_speed ;

    if(g_audply.new_play_time > g_mmi_audply_seek_target_time)
    {
        g_audply.new_play_time = g_mmi_audply_seek_target_time ;
    }
  
    /*check if MMI progress is faster than build progress*/
    if(g_audply.need_to_build_cache)
    {
        U32 old_duration = g_audply.duration ;
        
        if(audio_build_cache_progress != 100)
        {
            if(mdi_audio_build_cache_get_cache_duration(&duration))
            {
                if( g_audply.new_play_time > duration)
                {
                    /*choose the larger one to prevent the bar from shrinking*/
                    if(temp_play_time > duration)
                    {
                        g_audply.new_play_time = temp_play_time ;
                    }
                    else
                    {
                        g_audply.new_play_time = duration ;
                    }
                        
                    PRINT_INFORMATION("Audply | Debug: fast forward progress bar run too fast.");
                }
            }
        }
        /*duration updated if TRUE*/
        if(mmi_audply_update_total_duration_by_cache())
        {
            mmi_audply_update_progress_target_time(old_duration);
            mmi_audply_determine_progress_speed();
        }
    }

    PRINT_INFORMATION("Audply | Debug: Forward Time : %d, cached time : %d",g_audply.new_play_time,duration);
    mmi_audply_redraw_main_time();
    mmi_audply_redraw_main_progressbar() ;
#if defined(MT6223P) || defined(MT6223)
    StartTimer(AUDPLY_SEEKING_TIMER, 100, mmi_audply_fast_forward);
#else
    StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_fast_forward);
#endif
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_rewind
 * DESCRIPTION
 *  handling the timer and progress bar redrawing while rewinding
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_rewind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("Audply | Debug: rewind.");
    if (!g_audply.seekable && g_audply.in_main_screen)
    {
#ifdef __MMI_TOUCH_SCREEN__
       mmi_audply_touch_progress_pen_up();
#endif
       mmi_audply_redraw_main_progressbar();
       return;
    }
    
    if (g_audply.new_play_time - g_mmi_audply_seek_target_time < g_audply.progress_speed) 
    {
        g_audply.new_play_time = g_mmi_audply_seek_target_time;
    }
    else
    {
        if (g_audply.new_play_time >= g_audply.progress_speed)
        {
            g_audply.new_play_time -= g_audply.progress_speed;   
        }       
    }

    if (g_audply.need_to_build_cache)
    {
        U32 old_duration = g_audply.duration ;

        /*duration updated if TRUE*/
        if (mmi_audply_update_total_duration_by_cache())
        {
            mmi_audply_update_progress_target_time(old_duration); 
            mmi_audply_determine_progress_speed();
        }
    }
    PRINT_INFORMATION("Audply Progress Bar: Rewind Time : %d",g_audply.new_play_time);
    mmi_audply_redraw_main_time();
    mmi_audply_redraw_main_progressbar();
#if defined(MT6223P) || defined(MT6223)
    StartTimer(AUDPLY_SEEKING_TIMER, 100, mmi_audply_rewind);
#else
    StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_rewind);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_determine_progress_speed
 * DESCRIPTION
 *  determine progress speed according to song duration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_determine_progress_speed()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_audply.duration == 0)
    { 
        g_audply.progress_speed = 0 ;
        g_audply.seekable = FALSE;
    }
    else if(g_audply.duration <= 300000) /*less than 5 mins*/
    {
        g_audply.progress_speed = 1000 ;
    }
    else if(g_audply.duration <= 600000) /*5 to 10 mins*/
    {
        g_audply.progress_speed = 2000 ;
    }
    else
    {
        g_audply.progress_speed = 4000 ;
    }
        
#if defined(MT6223P) || defined(MT6223)
    g_audply.progress_speed = 1000 ;
#endif

    PRINT_INFORMATION("Audply Progress Bar: Progress Speed : %d secs",g_audply.progress_speed/1000);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_initialize_cache
 * DESCRIPTION
 *  initialize the cache
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_initialize_cache()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset( audio_cache, 0, BUILD_CACHE_SIZE ); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_refresh_cache
 * DESCRIPTION
 *  initialize the cache and reset some values
 * PARAMETERS
 *  BOOL    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_refresh_cache(BOOL check_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*refresh the build cache values*/
    if(check_name)
    {
        if (mmi_ucs2cmp((const PS8)g_audply.filefullname, (const PS8)g_audply.prev_filefullname))
        {
            PRINT_INFORMATION("Audply Progress Bar: refresh cache");
            mdi_audio_close_build_cache();
            audio_build_cache_progress = 0 ;
            /*initialize the cache*/
            mmi_audply_initialize_cache();
            mdi_audio_reset_build_cache_variables();
            mmi_ucs2cpy((PS8)g_audply.prev_filefullname, (const PS8)g_audply.filefullname);
            g_audply.file_name_identical = TRUE ;
        }
    }
    else
    {
        PRINT_INFORMATION("Audply Progress Bar: refresh cache");
        mdi_audio_close_build_cache();
        audio_build_cache_progress = 0 ;
        /*initialize the cache*/
        mmi_audply_initialize_cache();
        mdi_audio_reset_build_cache_variables();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_determine_cache_ptr
 * DESCRIPTION
 *  return cache pointer for L1 build cache to use
 * PARAMETERS
 *  void
 * RETURNS
 *  cache_ptr
 *****************************************************************************/
U8* mmi_audply_determine_cache_ptr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_audply.need_to_build_cache)
    {
        return audio_cache ;
    }
    else
    {
        return NULL;
    }
    
}
    
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_button_canceled
 * DESCRIPTION
 *  to cancel key down action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_button_canceled()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED || g_audply_main_selected_button_down == FALSE)
    {
        return;
    }

    if(g_audply_main_selected_button == (signed char)AUDPLY_MAIN_PAUSE)
    {
        g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PLAY;
    }
    else if(g_audply_main_selected_button == (signed char)AUDPLY_MAIN_PLAY)
    {
        g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PAUSE;
    }

    g_audply_main_selected_button_down = FALSE ;
 
    /* update button display */
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    }
}


#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add it 
extern void SendMessagesMMIToOne(msg_type MSG_ID );
#endif

#if defined(HORSERACE_SUPPORT)
//Huyanwei Add It 
extern void SendMessagesMMIToTwo(msg_type MSG_ID );
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_stop_button_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_stop_button_down()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        return;
    }

    /* change selected button & update state */
    g_audply_main_selected_button = (signed char)AUDPLY_MAIN_STOP;
    g_audply_main_selected_button_down = TRUE;

    /* update button display */
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_stop_button_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_stop_button_up()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button_down && (g_audply_main_selected_button == AUDPLY_MAIN_STOP))
    {
        BOOL need_redraw_buttons = (g_audply.state == STATE_IDLE);

        /* update selected button state */
        g_audply_main_selected_button_down = FALSE;
        StopTimer(AUDPLY_SEEKING_TIMER);
        mmi_audply_stop_playing();

        g_mmi_audply_play_completed_after_button_down = FALSE;
        
        g_mmi_audply_non_play_longpressed = FALSE ;

        g_mmi_audply_longpressed = FALSE ;

        /* update button display */
        if (need_redraw_buttons && g_audply.in_main_screen)
        {
            mmi_audply_redraw_main_buttons();
        }
#if defined(HORSERACE_SUPPORT)
	//Huyanwei Add It 
	SendMessagesMMIToTwo( MSG_ID_HORSERACE_OFF );
#endif

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_play_button_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_play_button_down()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        return;
    }

    /* update selected button state */
    g_audply_main_selected_button_down = TRUE;

    if (g_audply.state == STATE_PLAY && !g_audply.wait_next)
    {
        g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PAUSE; /* change selected button */
    }
    else if (g_audply.state == STATE_PAUSED)
    {
        g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PLAY;  /* change selected button */
    }
    else    /* g_audply.state == STATE_IDLE */
    {
        g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PLAY;  /* change selected button */
    }

    /* update button display */
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_play_button_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_play_button_up()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button_down && ((g_audply_main_selected_button == AUDPLY_MAIN_PLAY) ||
                                               (g_audply_main_selected_button == AUDPLY_MAIN_PAUSE)))
    {
        /* update selected button state */
        g_audply_main_selected_button_down = FALSE;

        if(!g_mmi_audply_non_play_longpressed)
        {
            StopTimer(AUDPLY_SEEKING_TIMER);
            if (g_audply.state == STATE_PLAY && !g_audply.wait_next)
            {
                mmi_audply_pause();   /* do pause action */
#if defined(HORSERACE_SUPPORT)
		//Huyanwei Add It 
		SendMessagesMMIToTwo( MSG_ID_HORSERACE_OFF );
#endif
				
            }
            else if (g_audply.state == STATE_PAUSED)
            {
                mmi_audply_resume();  /* do resume action */
#if defined(HORSERACE_SUPPORT)
		//Huyanwei Add It 
		SendMessagesMMIToTwo( MSG_ID_HORSERACE_ON );
#endif
            }
            else    /* g_audply.state == STATE_IDLE */
            {
                mmi_audply_play();    /* do play action */
#if defined(HORSERACE_SUPPORT)
		//Huyanwei Add It 
		SendMessagesMMIToTwo( MSG_ID_HORSERACE_ON );
#endif
            }
        }
        else /*g_mmi_audply_non_play_longpressed*/
        {
            mmi_audply_play();
#if defined(HORSERACE_SUPPORT)
		//Huyanwei Add It 
		SendMessagesMMIToTwo( MSG_ID_HORSERACE_ON );
#endif
            g_mmi_audply_non_play_longpressed = FALSE ;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_prev_button_down
 * DESCRIPTION
 *  handle event previous button down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_prev_button_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        return;
    }

    /* change selected button & update state */
    g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PREV;
    g_audply_main_selected_button_down = TRUE;

    /* update button display */
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_prev_button_up
 * DESCRIPTION
 *  handle event previous button up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_prev_button_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button_down && (g_audply_main_selected_button == AUDPLY_MAIN_PREV))
    {
        if (!g_mmi_audply_longpressed)
        {
            /* update selected button state */
            g_audply_main_selected_button_down = FALSE;

            StopTimer(AUDPLY_COUNT_PLAY_TIMER);
        #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
            gui_cancel_timer(mmi_audply_scroll_lyric_handler);
        #endif 
            /* pick the prev song */
            mmi_audply_pick_playlist_prev();
            if (mmi_audply_apply_picked_file())
            {
                if (g_audply.state == STATE_PLAY || g_audply.state == STATE_PAUSED ||
                    g_mmi_audply_play_completed_after_button_down || g_audply.need_replay
        #ifdef __MMI_A2DP_SUPPORT__
                    || mmi_audply_is_wait_open_bt()
        #endif
                    )
                {
                    StopTimer(AUDPLY_DELAY_PLAY_TIMER); /* stop previous play request */
                    mmi_audply_do_stop_action();                    
                    if (g_audply.state != STATE_PAUSED)
                    {
    #ifdef __MMI_A2DP_SUPPORT__
                        /* since filename is changed, we have to stop av bt open, or the configuration might be wrong */
                        mmi_audply_bt_stop(KAL_FALSE, KAL_FALSE);
    #endif
                        StartTimer(AUDPLY_DELAY_PLAY_TIMER, 700, mmi_audply_play);    /* wait for 0.7 second to request play */
                        g_audply.wait_next = TRUE;
                        g_audply.need_restore = FALSE;
                        g_audply.continue_playing = FALSE;
                    }
                }

                mmi_audply_clear_play_seconds();
                
                /* update main title, file_index, time */
                if (g_audply.in_main_screen)
                {
                #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
                    mmi_audply_stop_scroll_lyric_and_clean_screen();
                #endif 
                    mmi_audply_redraw_main_title();
                    mmi_audply_redraw_main_file_index();
                    mmi_audply_redraw_main_time();
                    mmi_audply_redraw_main_progressbar();
                }
                else if (g_idle_context.IsOnIdleScreen) /* update idle screen */
                {
                #ifdef __GDI_MEMORY_PROFILE_2__
                    if (mmi_idle_is_allow_to_display_song_name() == MMI_TRUE)
                    {
                        idle_screen_show_network_details();
                    }
                #else /* __GDI_MEMORY_PROFILE_2__ */ 
                    RedrawCategoryFunction();
                #endif /* __GDI_MEMORY_PROFILE_2__ */ 
                }                 
            }
            else
            {
                mmi_audply_update_main_button_flag();     
            }

            g_mmi_audply_play_completed_after_button_down = FALSE;

            g_mmi_audply_non_play_longpressed = FALSE;

            /* update main buttons */
            if (g_audply.in_main_screen)
            {
                mmi_audply_redraw_main_buttons();
            }
            else if (g_audply.in_list_screen)
            {
                dynamic_list_goto_item(g_audply.pick_index);
            }
        }
        else /*g_mmi_audply_longpressed*/
        {
          /*must be set to false before mmi_audply_paly() to prevent paly fail and
            then popup screen calls exit main screen to set some values incorrectly*/
            g_mmi_audply_longpressed = FALSE;

            g_audply_main_selected_button_down = FALSE;
            
            if(g_audply.seekable)
            {
                StopTimer(AUDPLY_SEEKING_TIMER);
                PRINT_INFORMATION("Audply Progress Bar: Rewind Stop");
                
                if (g_audply.need_to_build_cache)
                {
                    /*stop budild cache*/
                    mdi_audio_stop_build_cache();
                }
                        
                if (g_audply.state_before_longpress == STATE_PLAY)
                {
                #ifdef __DRM_SUPPORT__
                    mdi_audio_drm_disable_consume_count();
                #endif /* __DRM_SUPPORT__ */
                    mmi_audply_play();
                }
                else
                {
                    g_mmi_audply_non_play_longpressed = TRUE;
                    g_audply.state = g_audply.state_before_longpress;
                }
            }
            else    /* unseekable, for user release longpress next/prev button, then reset selected button */
            {
                if (g_audply.state_before_longpress == STATE_PLAY)
                {
                    if (g_audply.state != STATE_PLAY)
                    {
                    #ifdef __DRM_SUPPORT__
                        mdi_audio_drm_disable_consume_count();
                    #endif /* __DRM_SUPPORT__ */
                        mmi_audply_play();
                    }
                    else
                    {
                        g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PLAY;      
                    }
                }
                else
                {
                    g_mmi_audply_non_play_longpressed = TRUE;
                    g_audply.state = g_audply.state_before_longpress;
                }
            }

            if (g_audply.in_main_screen)
            {
               mmi_audply_redraw_main_buttons();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_next_button_down
 * DESCRIPTION
 *  handle event next button down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_next_button_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        return;
    }

    /* change selected button & update state */
    g_audply_main_selected_button = (signed char)AUDPLY_MAIN_NEXT;
    g_audply_main_selected_button_down = TRUE;

    /* update button display */
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_next_button_up
 * DESCRIPTION
 *  handle event next button up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_next_button_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button_down && (g_audply_main_selected_button == AUDPLY_MAIN_NEXT))
    {
        if (!g_mmi_audply_longpressed)
        {
            /* update selected button state */
            g_audply_main_selected_button_down = FALSE;

            StopTimer(AUDPLY_COUNT_PLAY_TIMER);
        #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
            gui_cancel_timer(mmi_audply_scroll_lyric_handler);
        #endif 
            /* pick the next song */
            mmi_audply_pick_playlist_next();
            if (mmi_audply_apply_picked_file())
            {
                if (g_audply.state == STATE_PLAY || g_audply.state == STATE_PAUSED ||
                    g_mmi_audply_play_completed_after_button_down || g_audply.need_replay
        #ifdef __MMI_A2DP_SUPPORT__
                    || mmi_audply_is_wait_open_bt()
        #endif
                    )
                {
                    StopTimer(AUDPLY_DELAY_PLAY_TIMER);
                    mmi_audply_do_stop_action();
                    if (g_audply.state != STATE_PAUSED)
                    {
        #ifdef __MMI_A2DP_SUPPORT__
                        /* since filename is changed, we have to stop av bt open, or the configuration might be wrong */
                        mmi_audply_bt_stop(KAL_FALSE, KAL_FALSE);
        #endif
                        StartTimer(AUDPLY_DELAY_PLAY_TIMER, 700, mmi_audply_play);    /* wait for 0.7 second to request play */
                        g_audply.wait_next = TRUE;
                        g_audply.need_restore = FALSE;
                        g_audply.continue_playing = FALSE;
                    }
                }
                       
                mmi_audply_clear_play_seconds();

                /* update main title, file_index, time */
                if (g_audply.in_main_screen)
                {
                #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
                    mmi_audply_stop_scroll_lyric_and_clean_screen();
                #endif 
                    mmi_audply_redraw_main_title();
                    mmi_audply_redraw_main_file_index();
                    mmi_audply_redraw_main_time();
                    mmi_audply_redraw_main_progressbar();
                }
                else if (g_idle_context.IsOnIdleScreen) /* update idle screen */
                {
                #ifdef __GDI_MEMORY_PROFILE_2__
                    if (mmi_idle_is_allow_to_display_song_name() == MMI_TRUE)
                    {
                        idle_screen_show_network_details();
                    }
                #else /* __GDI_MEMORY_PROFILE_2__ */ 
                    RedrawCategoryFunction();
                #endif /* __GDI_MEMORY_PROFILE_2__ */ 
                }                
            }
            else
            {
                mmi_audply_update_main_button_flag();     
            }

            g_mmi_audply_play_completed_after_button_down = FALSE;

            g_mmi_audply_non_play_longpressed = FALSE;
                
            /* update main buttons */
            if (g_audply.in_main_screen)
            {
                mmi_audply_redraw_main_buttons();
            }
            else if (g_audply.in_list_screen)
            {
                dynamic_list_goto_item(g_audply.pick_index);
            }
        }
        else /*g_mmi_audply_longpressed*/
        {
            /*must be set to false before mmi_audply_paly() to prevent paly fail and
              then popup screen calls exit main screen to set some values incorrectly*/
            g_mmi_audply_longpressed = FALSE;

            /* must be set to false before mmi_audply_play() to let play_completed to pick
               next song to play*/
            g_audply_main_selected_button_down = FALSE;
            
            if (g_audply.seekable)
            {
                StopTimer(AUDPLY_SEEKING_TIMER);
                PRINT_INFORMATION("Audply Progress Bar: Forward Stop");

                if (g_audply.need_to_build_cache)
                {
                    /*stop budild cache*/
                    mdi_audio_stop_build_cache();
                }

                if (g_audply.state_before_longpress == STATE_PLAY)
                {
                #ifdef __DRM_SUPPORT__
                    mdi_audio_drm_disable_consume_count();
                #endif /* __DRM_SUPPORT__ */
                    mmi_audply_play();
                }
                else
                {
                    g_mmi_audply_non_play_longpressed = TRUE;
                    g_audply.state = g_audply.state_before_longpress;
                }
            }
            else    /* unseekable, for user release longpress next/prev button, then reset selected button */
            {
                if (g_audply.state_before_longpress == STATE_PLAY)
                {
                    if (g_audply.state != STATE_PLAY)
                    {
                    #ifdef __DRM_SUPPORT__
                        mdi_audio_drm_disable_consume_count();
                    #endif /* __DRM_SUPPORT__ */
                        mmi_audply_play();
                    }
                    else
                    {
                        g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PLAY;      
                    }
                }
                else
                {
                    g_mmi_audply_non_play_longpressed = TRUE;
                    g_audply.state = g_audply.state_before_longpress;
                }
            }

            if (g_audply.in_main_screen)
            {
               mmi_audply_redraw_main_buttons();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_next_button_longpress
 * DESCRIPTION
 *  fast forward by long press next button and seeking to that point
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_next_button_longpress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*when wait next, longpress shall do nothing*/
    if (g_audply.wait_next)
    {
        return;
    }

    /*when playing song while file name not identical (press next/prev song)
      shall do nothing too.*/
    if (!g_audply.file_name_identical && g_audply.state != STATE_IDLE)
    {
        return;
    }
        
    g_mmi_audply_longpressed = TRUE;
    g_audply.state_before_longpress = g_audply.state;
    if (!g_audply.seekable)
    {
        PRINT_INFORMATION("Audply Progress Bar: not seekable");
        return;
    }

    /*stop file even in MMI it looks like it's only paused for seeking*/
    if (g_audply.state != STATE_IDLE)
    {        
        /*sotp playing without redrawing*/
        mmi_audply_seek_stop_playing();
    }
    else
    {
        /*in case it is in idle but waiting to retore, set replay and 
        restore to false to reject from restoring*/
        g_audply.need_replay = FALSE ;
        g_audply.need_restore = FALSE ;
        g_audply.continue_playing = FALSE;
        
        /*check and refresh cache*/
        mmi_audply_refresh_cache(TRUE);
    }    

    if (g_audply.need_to_build_cache && audio_build_cache_progress < 100)
    {
        /*send message to med_v to start process*/
        mdi_audio_start_build_cache(g_audply.filefullname,
                                    audio_cache, 
                                    BUILD_CACHE_SIZE,
                                    g_audply.audio_cache_file_buf_p,
                                    BUILD_CACHE_FILE_BUF_SIZE,
                                    g_audply.audio_cache_proc_buf_p,
                                    BUILD_CACHE_PROC_BUF_SIZE,
                                    mmi_audply_build_cache_fail_callback_hdlr,
                                    &audio_build_cache_progress);        
     }

    PRINT_INFORMATION("Audply Progress Bar: Forward Start");
    StopTimer(AUDPLY_COUNT_PLAY_TIMER);
    g_mmi_audply_seek_target_time = g_audply.duration;
    StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_fast_forward);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_prev_button_longpress
 * DESCRIPTION
 *  rewind by long press prev button and seek to the point.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_prev_button_longpress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*when wait next, longpress shall do nothing*/
    if (g_audply.wait_next)
    {
        return;
    }

    if (!g_audply.file_name_identical && g_audply.state != STATE_IDLE)
    {
        return;
    }
    
    g_mmi_audply_longpressed = TRUE;
    g_audply.state_before_longpress = g_audply.state;
    if (!g_audply.seekable)
    {
        return;
    }

    /*stop file even in MMI it looks like it's only paused for seeking*/
    if (g_audply.state != STATE_IDLE)
    {
        mmi_audply_seek_stop_playing();
    }
    else
    {
        /*in case it is in idle but waiting to retore, set replay and 
        restore to false to reject from restoring*/
        g_audply.need_replay = FALSE;
        g_audply.need_restore = FALSE;
        g_audply.continue_playing = FALSE;

        /*check and refresh cache*/
        mmi_audply_refresh_cache(TRUE);
    }

    if (g_audply.need_to_build_cache && audio_build_cache_progress < 100)
    {
        /*send message to med_v to start process*/
        mdi_audio_start_build_cache((kal_wchar*)g_audply.filefullname,
                                    audio_cache, 
                                    BUILD_CACHE_SIZE,
                                    g_audply.audio_cache_file_buf_p,
                                    BUILD_CACHE_FILE_BUF_SIZE,
                                    g_audply.audio_cache_proc_buf_p,
                                    BUILD_CACHE_PROC_BUF_SIZE,
                                    mmi_audply_build_cache_fail_callback_hdlr,
                                    &audio_build_cache_progress);    
     }

    PRINT_INFORMATION("Audply Progress Bar: Rewind Start");
    StopTimer(AUDPLY_COUNT_PLAY_TIMER);
    g_mmi_audply_seek_target_time = 0;
    StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_rewind);
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_touch_progress_seeking
 * DESCRIPTION
 *  decide the touch seeking direction (fast forward/rewind)
 * PARAMETERS
 *  cor_x       [IN]    x coordinate of touch down position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_touch_progress_seeking(S16 cor_x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    S32 current_x ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    current_x =  mmi_audply_get_current_x_coordinate();
    g_mmi_audply_seek_target_time = mmi_audply_get_proportional_time_from_x(cor_x);
    /*compare x cordinate*/
    if(cor_x >= current_x)
    {
        /*fast forward*/
        PRINT_INFORMATION("Audply | Debug: touch progress - fast forward.");
        StopTimer(AUDPLY_SEEKING_TIMER);
        StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_fast_forward);
    }
    else
    {
        /*rewind*/
        PRINT_INFORMATION("Audply | Debug: touch progress - rewind.");
        StopTimer(AUDPLY_SEEKING_TIMER);
        StartTimer(AUDPLY_SEEKING_TIMER, 50, mmi_audply_rewind);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_touch_progress_hdlr
 * DESCRIPTION
 *  take care the touch progress build cache and progress bar drawing
 *  we think of touch progress the same as longpress action
 * PARAMETERS
 *  cor_x       [IN]    x coordinate of touch down position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_touch_progress_hdlr(S16 cor_x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Audply | Debug: touch progress hdlr.");
    /*while wait next, the touch progress shall do nothing*/
    if(g_audply.wait_next)
    {
        audply_pen_event_on_object = AUDPLY_PEN_NONE ;
        return;
    }

    g_mmi_audply_longpressed = TRUE ;

    /*stop file even in MMI it looks like it's only paused for seeking*/
    g_audply.state_before_longpress = g_audply.state;
    if (!g_audply.seekable)
    {
        PRINT_INFORMATION("Audply | Debug: touch progress hdlr: !seekable.");
        return;
    }
    if (g_audply.state != STATE_IDLE)
    {
        mmi_audply_seek_stop_playing();
    }
    else
    {
        /*check and refresh cache*/
        mmi_audply_refresh_cache(TRUE);
    }

    if(g_audply.need_to_build_cache && audio_build_cache_progress < 100)
    {
        /*send message to med_v to start process*/
        mdi_audio_start_build_cache((kal_wchar*)g_audply.filefullname,
                                    audio_cache, 
                                    BUILD_CACHE_SIZE,
                                    g_audply.audio_cache_file_buf_p,
                                    BUILD_CACHE_FILE_BUF_SIZE,
                                    g_audply.audio_cache_proc_buf_p,
                                    BUILD_CACHE_PROC_BUF_SIZE,
                                    mmi_audply_build_cache_fail_callback_hdlr,
                                    &audio_build_cache_progress);  
     }

    StopTimer(AUDPLY_COUNT_PLAY_TIMER);

    mmi_audply_touch_progress_seeking(cor_x);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_touch_progress_pen_up
 * DESCRIPTION
 *  handle play potion after progress pen up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_touch_progress_pen_up()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
     StopTimer(AUDPLY_SEEKING_TIMER);

    /* if it's not longpressed, it means it is blocked 
       by wait next, so pen up shall do nothing*/
    if(!g_mmi_audply_longpressed)
    {
        return;
    }
    
    PRINT_INFORMATION("Audply | Debug: Touch Progress Bar:  Stop");

   /*must be set to false before mmi_audply_paly() to prevent paly fail and
     then popup screen calls exit main screen to set some values incorrectly*/     
     g_mmi_audply_longpressed = FALSE;

    if (g_audply.seekable)
    {
        StopTimer(AUDPLY_SEEKING_TIMER);
        
        if (g_audply.need_to_build_cache)
        {        
            /*stop budild cache*/
            mdi_audio_stop_build_cache();
        }
          
        if(g_audply.state_before_longpress == STATE_PLAY)
        {
        #ifdef __DRM_SUPPORT__
            mdi_audio_drm_disable_consume_count();
        #endif /* __DRM_SUPPORT__ */
            mmi_audply_play();
        }
        else
        {
            g_mmi_audply_non_play_longpressed = TRUE;
            g_audply.state = g_audply.state_before_longpress;
        }
    }
    else    /* unseekable, for user release longpress next/prev button, then reset selected button */
    {
        if (g_audply.state_before_longpress == STATE_PLAY)
        {
            if (g_audply.state != STATE_PLAY)
            {
                PRINT_INFORMATION("Audply | Debug: replay|!seekable.");
            #ifdef __DRM_SUPPORT__
                mdi_audio_drm_disable_consume_count();
            #endif /* __DRM_SUPPORT__ */
                mmi_audply_play();
            }
            else
            {
                PRINT_INFORMATION("Audply | Debug: redraw playing icon|!seekable.");
                g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PLAY;
            }
        }
        else
        {
            g_mmi_audply_non_play_longpressed = TRUE;
            g_audply.state = g_audply.state_before_longpress;
        }
    }     
     
    if (g_audply.in_main_screen)
    {
        mmi_audply_redraw_main_buttons();
    }     
}

#endif /*__MMI_TOUCH_SCREEN__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_inc_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_inc_volume()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.volume < MDI_AUD_VOL_EX_NUM - 1)
    {
        S16 error;

        mdi_audio_set_volume(VOL_TYPE_MEDIA, MDI_AUD_VOL_EX(++g_audply.volume));
        if (g_audply.in_main_screen)
        {
            mmi_audply_redraw_main_volumebar();
        }
#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
        if(g_audply.in_sub_screen)
        {
            UI_set_sub_LCD_graphics_context();
            mmi_audply_redraw_main_volumebar();
            UI_set_main_LCD_graphics_context();
        }
 #endif    
        WriteValue(NVRAM_AUDPLY_VOLUME, &g_audply.volume, DS_BYTE, &error);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_inc_volume_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_inc_volume_down(void)
{
	mmi_audply_press_inc_volume();
	mmi_audply_redraw_main_volumectrl(1, TRUE);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_inc_volume_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_inc_volume_up(void)
{
	mmi_audply_redraw_main_volumectrl(1, FALSE);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_dec_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_dec_volume()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.volume > 0)
    {
        S16 error;

        mdi_audio_set_volume(VOL_TYPE_MEDIA, MDI_AUD_VOL_EX(--g_audply.volume));
        if (g_audply.in_main_screen)
        {
            mmi_audply_redraw_main_volumebar();
        }
#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
        if(g_audply.in_sub_screen)
        {
            UI_set_sub_LCD_graphics_context();
            mmi_audply_redraw_main_volumebar();
            UI_set_main_LCD_graphics_context();
        }
 #endif    
        WriteValue(NVRAM_AUDPLY_VOLUME, &g_audply.volume, DS_BYTE, &error);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_dec_volume_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_dec_volume_down(void)
{
	mmi_audply_press_dec_volume();
	mmi_audply_redraw_main_volumectrl(0, TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_press_dec_volume_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_press_dec_volume_up(void)
{
	mmi_audply_redraw_main_volumectrl(0, FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_check_list
 * DESCRIPTION
 *  for check user modify list data file in mass storege mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_check_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 	U8 *guiBuffer;
	FS_HANDLE list_handle;
    UI_string_type list_name;
	FMGR_FILE_INFO_STRUCT file_info;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	list_name = mmi_audply_get_present_list_file();
	list_handle = FS_Open(list_name, FS_READ_ONLY);        

	if (list_handle > FS_NO_ERROR)
	{	
		FS_GetFileSize(list_handle, &file_info.file_size);
		FS_Close(list_handle);
		if (file_info.file_size > 0)
		{
			mmi_audply_regen_and_reload_playlist(FALSE, TRUE);
		}
		else
		{
			if ((guiBuffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_PLAYLIST)) != NULL)
			{
				memset(guiBuffer, 0, sizeof(list_menu_category_history));
				guiBuffer = NULL;
			}
			mmi_audply_clear_play_seconds();
            g_audply.restorable = FALSE;
            g_audply.seekable = FALSE;
            g_audply.title[0] = 0;
            g_audply.filefullname[0] = 0;
            g_audply.buff_head = 0;
            g_audply.n_buff_items = 0;
            g_audply.n_total_items = 0;
            mmi_audply_start_playlist_at(-1);
		}
	}
	else
	{
		if ((guiBuffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_PLAYLIST)) != NULL)
		{
			memset(guiBuffer, 0, sizeof(list_menu_category_history));
			guiBuffer = NULL;
		}
		mmi_audply_clear_play_seconds();
        g_audply.restorable = FALSE;
        g_audply.seekable = FALSE;
        g_audply.title[0] = 0;
        g_audply.filefullname[0] = 0;
        g_audply.buff_head = 0;
        g_audply.n_buff_items = 0;
        g_audply.n_total_items = 0;
        mmi_audply_start_playlist_at(-1);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 title_id;
    S32 highlighted_item = 0;
    U8  total_drv_num;
    UI_string_type drv_inline_list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AUDPLY_PLAYLIST, mmi_audply_exit_list, NULL, NULL);

    g_audply.in_list_screen = TRUE;

    /* title */
    mmi_fmgr_get_full_storage_inline_list(NULL,&total_drv_num, (U32*)(&drv_inline_list_p),NULL);
    if (total_drv_num >1 && drv_inline_list_p != NULL)
    {
        title_id =
            (g_audply.present_list == (U8)MMI_PUBLIC_DRV) ? STR_ID_AUDPLY_LIST_FROM_PHONE : STR_ID_AUDPLY_LIST_FROM_CARD;
    }
    else
    {
        title_id = STR_ID_AUDPLY_PLAYLIST;
    }

    /* register highligh handler */
    RegisterHighlightHandler(mmi_audply_list_highlight_hdlr);

    if (!need_refresh_list && need_reload_list) 
    {
        mmi_audply_regen_and_reload_playlist(need_refresh_list, need_reload_list);
    }

    /* show category screen */
    if (g_audply.n_total_items == 0 || need_refresh_list || !mmi_audply_does_present_list_file_exist())
    {
        ShowCategory52Screen(
            title_id,
            GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            NULL,
            NULL,
            NULL,
            1,
            0,
            NULL);
    }
    else
    {
        /* if we delete some items and the previous highlighted item is out of boundary, set it to the last one */
        if ((guiBuffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_PLAYLIST)) != NULL)
        {
            list_menu_category_history *hist = (list_menu_category_history*) guiBuffer;

            if (hist->highlighted_item >= g_audply.n_total_items)
            {
                hist->highlighted_item = g_audply.n_total_items - 1;
            }
            else if (g_audply.pick_index >= 0)
            {
                /* for sync highlight in list screen with pick index */
            	if (g_mmi_audply_list_highlighted_item == -1)
                {
                    hist->highlighted_item = g_audply.pick_index;
                    g_mmi_audply_list_highlighted_item = g_audply.pick_index; 
                }
            }
            else
            {
                hist->highlighted_item = 0;   /* this should never happen */
            }
            
        }
        else if (g_audply.pick_index >= 0)  /* highlighted item */
        {
            highlighted_item = g_audply.pick_index;
        }
        else
        {
            highlighted_item = 0;   /* this should never happen */
        }

        ShowCategory184Screen(
            title_id,
            GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),    /* title text and icon */
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,                 /* LSK text and icon */
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,                    /* RSK text and icon */
            g_audply.n_total_items,
            mmi_audply_list_getitem,
            NULL,
            highlighted_item,
            guiBuffer);
    }

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_audply_entry_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* register left right arrow key handler */
    SetKeyHandler(mmi_audply_entry_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);


     #ifdef __MMI_NO_VOL_KEYS__
 	 //Huyanwei Modify it    //sc.wu
 	   #if defined(__VOL_WITH_28KEY__)
          SetKeyHandler(mmi_audply_press_inc_volume, KEY_2, KEY_EVENT_DOWN);
          SetKeyHandler(mmi_audply_press_dec_volume, KEY_8, KEY_EVENT_DOWN);
 	   #else
 	   SetKeyHandler(mmi_audply_press_inc_volume, KEY_2, KEY_EVENT_DOWN);
          SetKeyHandler(mmi_audply_press_dec_volume, KEY_5, KEY_EVENT_DOWN);
	   #endif
     #else
         /* register volume inc, dec handlers */
         SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
         SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
     #endif


    if (need_refresh_list || need_reload_list) 
    {
        mmi_audply_regen_and_reload_playlist(need_refresh_list, need_reload_list);
    }
    else if (no_card_in_slot)
    {
        no_card_in_slot = FALSE;
        DisplayPopup((PU8)GetString(STR_ID_AUDPLY_NO_CARD),
            IMG_GLOBAL_WARNING,
            1,
            1000,
            (U8)WARNING_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.in_list_screen = FALSE;

    currHistory.scrnID = SCR_ID_AUDPLY_PLAYLIST;
    currHistory.entryFuncPtr = mmi_audply_entry_list;
    GetCategoryHistory(currHistory.guiBuffer);
    mmi_ucs2cpy((PS8)currHistory.inputBuffer, (PS8)L"");
    AddHistory(currHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_audply_list_highlighted_item = (U16) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lookup_audio_file_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_ext        [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_lookup_audio_file_format(UI_string_type file_ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    BOOL match = TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NO_AUDIO_FILE_TYPES; i++)
    {
        match = TRUE;
        for (j = 0; j < 4; j++) /* it's is not necessary to check j < 4, but for safety */
        {
            UI_character_type file_ext_char = file_ext[j];

            if (file_ext_char != audio_file_lower_exts[i][j] 
                && file_ext_char != audio_file_upper_exts[i][j])
            {
                match = FALSE;
                break;
            }
            else if (file_ext_char == 0)    /* both are end and length less than 4 */
            {
                return i;
            }
        }
        if (match)
        {
            return i;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_list_getitem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_audply_list_getitem(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_ext_index;
    UI_character_type filename[FMGR_MAX_FILE_LEN];
    UI_character_type ext[FMGR_MAX_EXT_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get file name without ext */
    mmi_audply_playlist_get_filename(filename, item_index);

    mmi_audply_split_filename_ext(filename, str_buff, ext);
    file_ext_index = mmi_audply_lookup_audio_file_format(ext);
#ifdef __MMI_SHOW_FILE_EXT__
#if !defined(__MMI_SHOW_DAF_FILE_EXT__) && (defined(DAF_DECODE) || defined(MUSICAM_DECODE))
    if(
#if defined(DAF_DECODE)
     file_ext_index != AUDPLY_AUDIO_FILE_TYPE_DAF
#endif
#if defined(DAF_DECODE) && defined(MUSICAM_DECODE)
    &&
#endif
#if defined(MUSICAM_DECODE)
    file_ext_index != AUDPLY_AUDIO_FILE_TYPE_MP2
#endif
     )
#endif
    {
        if (ext[0] != 0)    /* if its ext is not blank */
        {
            mmi_ucs2cat((PS8)str_buff, (PS8)L".");
            mmi_ucs2cat((PS8)str_buff, (PS8)ext);
        }
    }
#endif /* __MMI_SHOW_FILE_EXT__ */ 

    /* get ext icon */
    if (file_ext_index >= 0)
    {
        *img_buff_p = (PU8) GetImage(audio_file_icon_ids[file_ext_index]);
    }
    else
    {
        *img_buff_p = (PU8) GetImage(IMG_ID_AUDPLY_FILE_UNKNOWN_ICON);
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_option()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_items;
    U16 item_icons[7];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AUDPLY_OPTION, mmi_audply_exit_option, NULL, NULL);

    /* gui buffer */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_OPTION);

    /* items */
    if (g_audply.list_auto_gen)
    {
        if (g_audply.n_total_items == 0)
        {
            /* regenerate list, settings */
            option_texts[0] = STR_ID_AUDPLY_OPTION_REGEN_LIST;
            item_icons[0] = IMG_GLOBAL_L1;
            option_texts[1] = STR_ID_AUDPLY_OPTION_SETTINGS;
            item_icons[1] = IMG_GLOBAL_L2;
            n_items = 2;
        }
        else
        {
            /* play, detail, add to rings, regenerate list, settings */
            option_texts[0] = STR_ID_AUDPLY_OPTION_PLAY;
            item_icons[0] = IMG_GLOBAL_L1;
            option_texts[1] = STR_ID_AUDPLY_OPTION_DETAIL;
            item_icons[1] = IMG_GLOBAL_L2;
            option_texts[2] = STR_ID_AUDPLY_OPTION_ADD_TO_RINGS;
            item_icons[2] = IMG_GLOBAL_L3;
            option_texts[3] = STR_ID_AUDPLY_OPTION_REGEN_LIST;
            item_icons[3] = IMG_GLOBAL_L4;
            option_texts[4] = STR_ID_AUDPLY_OPTION_SETTINGS;
            item_icons[4] = IMG_GLOBAL_L5;
            n_items = 5;
        }
    }
    else
    {
        if (g_audply.n_total_items == 0)
        {
            /* add, settings */
            option_texts[0] = STR_ID_AUDPLY_OPTION_ADD;
            item_icons[0] = IMG_GLOBAL_L1;
            option_texts[1] = STR_ID_AUDPLY_OPTION_SETTINGS;
            item_icons[1] = IMG_GLOBAL_L2;
            n_items = 2;
        }
        else
        {
            /* play, detail, add to rings, add, remove, remove all, settings */
            option_texts[0] = STR_ID_AUDPLY_OPTION_PLAY;
            item_icons[0] = IMG_GLOBAL_L1;
            option_texts[1] = STR_ID_AUDPLY_OPTION_DETAIL;
            item_icons[1] = IMG_GLOBAL_L2;
            option_texts[2] = STR_ID_AUDPLY_OPTION_ADD_TO_RINGS;
            item_icons[2] = IMG_GLOBAL_L3;
            option_texts[3] = STR_ID_AUDPLY_OPTION_ADD;
            item_icons[3] = IMG_GLOBAL_L4;
            option_texts[4] = STR_ID_AUDPLY_OPTION_REMOVE;
            item_icons[4] = IMG_GLOBAL_L5;
            option_texts[5] = STR_ID_AUDPLY_OPTION_REMOVE_ALL;
            item_icons[5] = IMG_GLOBAL_L6;
            option_texts[6] = STR_ID_AUDPLY_OPTION_SETTINGS;
            item_icons[6] = IMG_GLOBAL_L7;
            n_items = 7;
        }
    }

    /* register highligh handler */
    RegisterHighlightHandler(mmi_audply_option_highlight_hdlr);

    /* show category screen */
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),    /* title text and icon */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,                      /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        n_items,
        option_texts,
        item_icons,
        LIST_MENU,
        0,
        guiBuffer);

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_audply_option_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* register left, right key handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_option_right_arrow_key, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* register volume inc, dec handlers */

#ifdef __MMI_NO_VOL_KEYS__
// 没有音量键的处理 //sc.wu __MMI_NO_VOL_KEYS__
	#if defined(__VOL_WITH_28KEY__)
	    SetKeyHandler(mmi_audply_press_inc_volume, KEY_2, KEY_EVENT_DOWN);
	    SetKeyHandler(mmi_audply_press_dec_volume, KEY_8, KEY_EVENT_DOWN);
	#else
	    SetKeyHandler(mmi_audply_press_inc_volume, KEY_2, KEY_EVENT_DOWN);
	    SetKeyHandler(mmi_audply_press_dec_volume, KEY_5, KEY_EVENT_DOWN);
	#endif
#else
    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_option()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * history currHistory;
     * currHistory.scrnID = SCR_ID_AUDPLY_OPTION;
     * currHistory.entryFuncPtr = mmi_audply_entry_option;
     * GetCategoryHistory( currHistory.guiBuffer );
     * mmi_ucs2cpy((PS8)currHistory.inputBuffer, (const PS8)L"" );
     * AddHistory( currHistory );
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_option_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_option_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_audply_option_highlighted_item = (U16) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_option_right_arrow_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_option_right_arrow_key()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 highlighted_item_text_id = option_texts[g_mmi_audply_option_highlighted_item];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (highlighted_item_text_id != STR_ID_AUDPLY_OPTION_ADD_TO_RINGS &&
        highlighted_item_text_id != STR_ID_AUDPLY_OPTION_REGEN_LIST)
    {
        mmi_audply_option_LSK();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_option_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_option_LSK()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    void (*settings_entry_func)(void);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (AUDPLY_SETTING_ITEM_COUNT <= 10)
    {
        settings_entry_func = mmi_audply_entry_settings;
    }
    else
    {
        settings_entry_func = mmi_audply_entry_two_layers_settings;
    }

    if (g_audply.list_auto_gen)
    {
        if (g_audply.n_total_items == 0)
        {
            switch (g_mmi_audply_option_highlighted_item)
            {
                case 0: /* regenerate list */
                    mmi_audply_regen_and_reload_playlist(TRUE, TRUE);
                    /* clear play list gui buffer */
                    HistoryReplace(SCR_ID_AUDPLY_PLAYLIST, SCR_ID_AUDPLY_PLAYLIST, mmi_audply_entry_list);
                    break;
                case 1: /* settings */
                    settings_entry_func();
                    break;
            }
        }
        else
        {
            switch (g_mmi_audply_option_highlighted_item)
            {
                case 0: /* play */
                    mmi_audply_start_playlist_at(g_mmi_audply_list_highlighted_item);
                    mmi_audply_pick_playlist_at(g_mmi_audply_list_highlighted_item);
                    if (mmi_audply_apply_picked_file())
                    {
                        mmi_audply_stop_playing();
                        GoBackToHistory(SCR_ID_AUDPLY_MAIN);
                        mmi_audply_play();
                    }
			else
			{
				DisplayPopup((PU8)GetString(STR_ID_AUDPLY_OPEN_FILE_ERROR), IMG_GLOBAL_ERROR, 0, 1000, (U8) ERROR_TONE);
			}
			#if defined(HORSERACE_SUPPORT)
				//Huyanwei Add It 
				SendMessagesMMIToTwo( MSG_ID_HORSERACE_ON );
			#endif	
                    break;
                case 1: /* detail */
                    mmi_audply_entry_detail();
                    break;
                case 2: /* add to rings */
                #ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
                    PmgSetShortFileName((BOOL)
                                        (mmi_audply_playlist_get_fullfilename
                                         (fullfilename_temp, g_mmi_audply_list_highlighted_item) == 2));
                    if (!mmi_audply_does_file_exist(fullfilename_temp))
                    {
                        DisplayPopup(
                            (PU8) GetString(GetFileSystemErrorString(FS_FILE_NOT_FOUND)),
                            IMG_GLOBAL_ERROR,
                            0,
                            1000,
                            (U8) ERROR_TONE);
                    }
                    else
                #ifdef __DRM_SUPPORT__
                    if (!mmi_profiles_check_DRM_content_forwardable(fullfilename_temp))
                    {
                        DisplayPopup(
                            (PU8) GetString(STR_GLOBAL_DRM_PROHIBITED),
                            IMG_GLOBAL_WARNING,
                            0,
                            1000,
                            (U8) WARNING_TONE);
                    }
                    else
                #endif /* __DRM_SUPPORT__ */ 
                        PmgFmgrAddExtMelodyFunc((S8*) fullfilename_temp);
                #endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 
                    break;
                case 3: /* regenerate list */
                    mmi_audply_regen_and_reload_playlist(TRUE, TRUE);
                    /* clear play list gui buffer */
                    HistoryReplace(SCR_ID_AUDPLY_PLAYLIST, SCR_ID_AUDPLY_PLAYLIST, mmi_audply_entry_list);
                    break;
                case 4: /* settings */
                    settings_entry_func();
                    break;
            }
        }
    }
    else
    {
        if (g_audply.n_total_items == 0)
        {
            switch (g_mmi_audply_option_highlighted_item)
            {
                case 0: /* add */
                   {
                    UI_string_type dir_root ;
            #ifdef __MMI_FILE_MANAGER__
                    FMGR_FILTER_INIT(&filter);
                    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
                    FMGR_FILTER_SET_AUDIO(&filter);
                    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_VM);
            #if defined(__MMI_PURE_AUDIO__)
                    FMGR_FILTER_SET(&filter, FMGR_TYPE_3GP);
                    FMGR_FILTER_SET(&filter, FMGR_TYPE_MP4);
            #endif
            #ifdef __DRM_V02__
                    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
            #endif

                    /*config presnet_dir_root*/
                    dir_root = mmi_audply_get_present_list_root();
                    
                    mmi_fmgr_select_path_and_enter(
                        APP_AUDIOPLAYER,
                        FMGR_SELECT_FILE_OR_FOLDER | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE,
                        filter,
                        (PS8) dir_root,
                        (PsExtFuncPtr) mmi_audply_add_file_hdlr);
            #endif /* __MMI_FILE_MANAGER__ */ 
                    }
                    break;
                case 1: /* settings */
                    settings_entry_func();
                    break;
            }
        }
        else
        {
            switch (g_mmi_audply_option_highlighted_item)
            {
                case 0: /* play */
                    mmi_audply_start_playlist_at(g_mmi_audply_list_highlighted_item);
                    mmi_audply_pick_playlist_at(g_mmi_audply_list_highlighted_item);
                    if (mmi_audply_apply_picked_file())
                    {
                        mmi_audply_stop_playing();
                        GoBackToHistory(SCR_ID_AUDPLY_MAIN);
                        mmi_audply_play();
                    }
			#if defined(HORSERACE_SUPPORT)
				//Huyanwei Add It 
				SendMessagesMMIToTwo( MSG_ID_HORSERACE_ON );
			#endif	
                    break;
                case 1: /* detail */
                    mmi_audply_entry_detail();
                    break;
                case 2: /* add to rings */
                #ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
                    PmgSetShortFileName((BOOL)
                                        (mmi_audply_playlist_get_fullfilename
                                         (fullfilename_temp, g_mmi_audply_list_highlighted_item) == 2));
                    if (!mmi_audply_does_file_exist(fullfilename_temp))
                    {
                        DisplayPopup(
                            (PU8)GetString(GetFileSystemErrorString(FS_FILE_NOT_FOUND)),
                            IMG_GLOBAL_ERROR,
                            0,
                            1000,
                            (U8) ERROR_TONE);
                    }
                    else
                #ifdef __DRM_SUPPORT__
                    if (!mmi_profiles_check_DRM_content_forwardable(fullfilename_temp))
                    {
                        DisplayPopup(
                            (PU8) GetString(STR_GLOBAL_DRM_PROHIBITED),
                            IMG_GLOBAL_WARNING,
                            0,
                            1000,
                            (U8) WARNING_TONE);
                    }
                    else
                #endif /* __DRM_SUPPORT__ */ 
                        PmgFmgrAddExtMelodyFunc((S8*) fullfilename_temp);
                #endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 
                    break;
                case 3: /* add */
                {
                    UI_string_type dir_root ;
                #ifdef __MMI_FILE_MANAGER__
                    FMGR_FILTER_INIT(&filter);
                    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
                    FMGR_FILTER_SET_AUDIO(&filter);
                    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_VM);
                #if defined(__MMI_PURE_AUDIO__)
                    FMGR_FILTER_SET(&filter, FMGR_TYPE_3GP);
                    FMGR_FILTER_SET(&filter, FMGR_TYPE_MP4);
                #endif
                #ifdef __DRM_V02__
                    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
                #endif
                    
                    /*config presnet_dir_root*/
                    dir_root = mmi_audply_get_present_list_root();
                    
                    mmi_fmgr_select_path_and_enter(
                        APP_AUDIOPLAYER,
                        FMGR_SELECT_FILE_OR_FOLDER | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE,
                        filter,
                        (PS8) dir_root,
                        (PsExtFuncPtr) mmi_audply_add_file_hdlr);
                #endif /* __MMI_FILE_MANAGER__ */ 
                }
                    break;
                case 4: /* remove */
                    mmi_audply_entry_remove_confirm();
                    break;
                case 5: /* remove all */
                    mmi_audply_entry_remove_all_confirm();
                    break;
                case 6: /* settings */
                    settings_entry_func();
                    break;
			
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_process_add_files_in_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_process_add_files_in_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    FS_DOSDirEntry file_info;
    BOOL is_shortname;
    UI_character_type search_path[FMGR_MAX_FILE_LEN + 1];
    UI_character_type ext[FMGR_MAX_EXT_LEN + 1];
    UI_character_type filexpr_temp[FMGR_MAX_PATH_LEN + 1];
    UI_string_type list_name;
    S32 write_result;
    S32 size;
    U8 result = 0;
    S32 folder_path_len;
#ifdef __DRM_V02__
    drm_file_info_struct drm_file_info;
    PU8 ext_name_p = NULL; 
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (add_file_cursor < 0)    /* first time */
    {
        /* open list data file */
        list_name = mmi_audply_get_present_list_file();
        if ((list_data_file_handle = FS_Open(list_name, FS_READ_WRITE | FS_CREATE | FS_ATTR_HIDDEN)) < 0)
	{
	    /* open list data file failed! */
	    if (list_data_file_handle == FS_ROOT_DIR_FULL ||
                list_data_file_handle == FS_DISK_FULL ||
                list_data_file_handle == FS_READ_ONLY_ERROR)
            {
                DisplayPopup(
                    (PU8)GetString(GetFileSystemErrorString(list_data_file_handle)),
                    IMG_GLOBAL_ERROR,
                    0,
                    1000,
                    (U8) ERROR_TONE);
            }
            else
            {
                DisplayPopup(
                    (PU8)GetString(STR_ID_AUDPLY_CANNOT_UPDATE_LIST_FS_FAIL),
                    IMG_GLOBAL_ERROR,
                    0,
                    1000,
                    (U8) ERROR_TONE);                
            }
            return;
	} 
        if (FS_Seek(list_data_file_handle, g_audply.n_total_items * PLAY_LIST_RECORD_SIZE, FS_FILE_BEGIN) < 0)
        {
            /* seek list data file failed! */
            DisplayPopup(
                (PU8)GetString(STR_ID_AUDPLY_CANNOT_UPDATE_LIST_FS_FAIL),
                IMG_GLOBAL_ERROR,
                1,
                1000, 
                (U8)ERROR_TONE);                
            return;
        }
    #ifdef __DRM_V02__
        if (is_multi_part_odf)
        {
            find_cntx = DRM_get_find_cntx();
            add_file_cursor = DRM_find_firstN(
                                    find_cntx,
                                    add_file_path, 
                                    0, 
                                    0,
                                    &drm_file_info,
                                    search_path,
                                    (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH,
                                    0);

            if (add_file_cursor < FS_NO_ERROR)
            {
                /* because this memory will be free in DRM_find_firstN when DRM_find_firstN fail. */
                find_cntx = NULL;
                
                /* seek list data file failed! */
                DisplayPopup(
                    (PU8)GetString(GetFileSystemErrorString(add_file_cursor)),
                    IMG_GLOBAL_ERROR,
                    1,
                    1000, 
                    (U8)ERROR_TONE);                
                return;
            }
        }
        else
    #endif  /* __DRM_V02__ */
        {
            /* make add folder path */
            mmi_ucs2cpy((PS8)filexpr_temp, (PS8)add_file_path);
            mmi_ucs2cat((PS8)filexpr_temp, (PS8)L"*.*");
            /* FindFirst will return . */
            add_file_cursor = FS_FindFirst(filexpr_temp, 0, 0, &file_info, search_path, (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH);
    #ifdef __MTK_TARGET__
            /* FindNext will return .. */
            FS_FindNext(add_file_cursor, &file_info, search_path, (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH);
            /* if return FS_NO_MORE_FILES, it means there is really no file in it.*/
            if (FS_FindNext(add_file_cursor, &file_info, search_path, (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH) == FS_NO_MORE_FILES)
            {
                /* it is an empty folder */
                DisplayPopup(
                    (PU8)GetString(STR_GLOBAL_EMPTY),
                    IMG_GLOBAL_EMPTY,
                    0,
                    1000,
                    (U8) EMPTY_LIST_TONE);
                return;
            }
    #else	/* __MTK_TARGET__ */
            if (add_file_cursor == FS_NO_MORE_FILES)
            {
                DisplayPopup(
                    (PU8)GetString(STR_GLOBAL_EMPTY),
                    IMG_GLOBAL_EMPTY,
                    0,
                    1000,
                    (U8) EMPTY_LIST_TONE);  
                return;
            }
    #endif /* __MTK_TARGET__ */
        }
    }
    else 
    {
    #ifdef __DRM_V02__
        if (is_multi_part_odf)
        {
            if (FS_NO_ERROR != DRM_find_nextN(
                                    find_cntx,
                                    add_file_cursor, 
                                    &drm_file_info,
                                    search_path,
                                    (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH,
                                    0))
            {
                mmi_audply_process_add_files_end(0);
                return;
            }
        }
        else
    #endif /* __DRM_V02__ */
        {
            if (FS_FindNext(add_file_cursor, &file_info, search_path, (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH) != FS_NO_ERROR)
            {
                /* end add action */
                if(g_mmi_audply_is_folder_empty)
                {
                    mmi_audply_process_add_files_end(3);
                }
                else
                {
                    mmi_audply_process_add_files_end(0);
                }
                return;
            }
        }
    }

    /* add files to play list */
    folder_path_len = mmi_ucs2strlen((const PS8)add_file_path);
    i = 0;
#ifdef __DRM_V02__
    if (is_multi_part_odf)
    {
        do
        {
            mmi_audply_extract_ext(search_path, ext);
            if (mmi_audply_lookup_audio_file_format(ext) >= 0)
            {
                if (folder_path_len + mmi_ucs2strlen((const PS8)search_path) <= FMGR_MAX_PATH_LEN)
                {
                    mmi_ucs2cpy((PS8)filexpr_temp, (PS8)add_file_path);
                    mmi_ucs2cat((PS8)filexpr_temp, (const PS8)L"\\");
                    mmi_ucs2cat((PS8)filexpr_temp, (PS8)search_path);
                    MARK_LNAME(filexpr_temp);
                    if (g_audply.n_total_items >= MAX_PLAY_LIST_NUM)
                    {
                        result = 1;
                        g_mmi_audply_is_folder_empty = MMI_FALSE;
                        break;
                    }
                    else if ((write_result = FS_Write(list_data_file_handle, filexpr_temp, PLAY_LIST_RECORD_SIZE, (U32*)&size)) != FS_NO_ERROR)
                    {
                        if (write_result == FS_DISK_FULL)
                        {
                            result = 2;
                            g_mmi_audply_is_folder_empty = MMI_FALSE;
                            break;
                        }
                    }
                    else
                    {
                        g_audply.n_total_items++;
                        result = 0;
                        g_mmi_audply_is_folder_empty = MMI_FALSE;
                    }
                }
            }
  
            if ((++i) == 10)
            {
                StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 100, mmi_audply_process_add_files_in_folder);
                return;
            }
        } while (FS_NO_ERROR == DRM_find_nextN(
                                    find_cntx,
                                    add_file_cursor, 
                                    &drm_file_info,
                                    search_path,
                                    (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH,
                                    1));
    }
    else
#endif  /* __DRM_V02__ */
    {
        /* the folder is not a multi-part odf. */
        do
        {
            if ((file_info.Attributes & (FS_ATTR_DIR | FS_ATTR_VOLUME | FS_ATTR_HIDDEN | FS_ATTR_SYSTEM)) == 0)
            {
                is_shortname = ((file_info.NTReserved & FS_SFN_MATCH) != 0);
                if (is_shortname)
                {
                    for (j = 0; j < 3; j++)
                    {
                        ext[j] = (UI_character_type) file_info.Extension[j];
                    }
                    ext[j] = 0;
                }
                else
                {
                    mmi_audply_extract_ext(search_path, ext);
                }
                /* check this item whether is an odf file. */
            #ifdef __DRM_V02__
                if (!mmi_ucs2nicmp((const PS8)ext, (const PS8)L"odf", (U32)mmi_ucs2strlen((const PS8)ext)))
                {
                    if (folder_path_len + mmi_ucs2strlen((const PS8)search_path) <= FMGR_MAX_PATH_LEN)
                    {
                        mmi_ucs2cpy((PS8)filexpr_temp, (const PS8)add_file_path);
                        mmi_ucs2cat((PS8)filexpr_temp, (const PS8)search_path);

                        if (!DRM_is_archive(0, (PU16)filexpr_temp))
                        {
                            /* it is a single-part odf. */
                            ext_name_p = (PU8)DRM_get_content_ext(0, (PU16)filexpr_temp);
                            if (ext_name_p != NULL)
                            {
                                mmi_asc_n_to_ucs2((PS8)ext, (PS8)ext_name_p, strlen((const char *)ext_name_p));
                            }
                            else
                            {
                                ext[0] = 0;
                            }
                        }
                        else
                        {
                            /* it is a multi-part odf. */
                            FS_HANDLE multi_part_handle;
                            UI_character_type content_name[FMGR_MAX_FILE_LEN + 1];
                            UI_character_type temp_buffer[FMGR_MAX_PATH_LEN + 1];
                            
                            find_cntx = DRM_get_find_cntx();
                            multi_part_handle = DRM_find_firstN(
                                                        find_cntx,
                                                        filexpr_temp, 
                                                        0, 
                                                        0,
                                                        &drm_file_info,
                                                        content_name,
                                                        (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH,
                                                        0);
                            if (multi_part_handle < FS_NO_ERROR)
                            {     
                                /* because this memory will be free in DRM_find_firstN when DRM_find_firstN fail. */
                                find_cntx = NULL;
                                /* need pop up or do something for this error. */
                                DisplayPopup(
                                    (PU8)GetString(GetFileSystemErrorString(multi_part_handle)),
                                    IMG_GLOBAL_ERROR,
                                    1,
                                    1000, 
                                    (U8)ERROR_TONE);    
                                mmi_audply_process_add_files_end(9);    /* any numeral larger than 3. */
                                return;
                            }
                            else
                            {
                                do
                                {
                                    mmi_audply_extract_ext(content_name, ext);
                                    if (mmi_audply_lookup_audio_file_format(ext) >= 0)
                                    {
                                        if (mmi_ucs2strlen((const PS8)filexpr_temp) + mmi_ucs2strlen((const PS8)content_name) <= FMGR_MAX_PATH_LEN)
                                        {
                                            mmi_ucs2cpy((PS8)temp_buffer, (const PS8)filexpr_temp);
                                            mmi_ucs2cat((PS8)temp_buffer, (const PS8)L"\\");
                                            mmi_ucs2cat((PS8)temp_buffer, (PS8)content_name);
                                            MARK_LNAME(temp_buffer);
                                            if (g_audply.n_total_items >= MAX_PLAY_LIST_NUM)
                                            {
                                                DRM_find_close(find_cntx, multi_part_handle);
                                                find_cntx = NULL;
                                                mmi_audply_refresh_play_list_end(1);
                                                return;
                                            }
                                            else if ((write_result = FS_Write(list_data_file_handle, temp_buffer, PLAY_LIST_RECORD_SIZE, (U32*)&size)) != FS_NO_ERROR)
                                            {
                                                if (write_result == FS_DISK_FULL)
                                                {
                                                    DRM_find_close(find_cntx, multi_part_handle);
                                                    find_cntx = NULL;
                                                    mmi_audply_refresh_play_list_end(2);
                                                    return;
                                                }
                                            }
                                            else
                                            {
                                                g_audply.n_total_items++;
                                                result = 0;
                                                g_mmi_audply_is_folder_empty = MMI_FALSE;
                                            }
                                        }
                                    }
                                } while (FS_NO_ERROR == DRM_find_nextN(
                                    find_cntx,
                                    multi_part_handle, 
                                    &drm_file_info,
                                    content_name,
                                    (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH,
                                    1));
                            }
                            if (find_cntx)
                            {
                                DRM_find_close(find_cntx, multi_part_handle);
                                find_cntx = NULL;
                            }
                            StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 100, mmi_audply_process_add_files_in_folder);
                            return;
                        }
                    }
                }
            #endif  /* __DRM_V02__ */
                if (mmi_audply_lookup_audio_file_format(ext) >= 0)
                {
                    if (folder_path_len + mmi_ucs2strlen((const PS8)search_path) <= FMGR_MAX_PATH_LEN)
                    {
                        mmi_ucs2cpy((PS8)filexpr_temp, (PS8)add_file_path);
                        mmi_ucs2cat((PS8)filexpr_temp, (PS8)search_path);
                        if (is_shortname)
                        {
                            MARK_SNAME(filexpr_temp);
                        }
                        else
                        {
                            MARK_LNAME(filexpr_temp);
                        }
                        if (g_audply.n_total_items >= MAX_PLAY_LIST_NUM)
                        {
                            result = 1;
                            g_mmi_audply_is_folder_empty =  MMI_FALSE;
                            break;
                        }
                        else if ((write_result = FS_Write(list_data_file_handle, filexpr_temp, PLAY_LIST_RECORD_SIZE, (U32*)&size)) != FS_NO_ERROR)
                        {
                            if (write_result == FS_DISK_FULL)
                            {
                                result = 2;
                                g_mmi_audply_is_folder_empty =  MMI_FALSE;
                                break;
                            }
                        }
                        else
                        {
                            g_audply.n_total_items++;
                            result = 0;
                            g_mmi_audply_is_folder_empty = MMI_FALSE;
                        }
                    }
                }
            }
            
            if ((++i) == 10)
            {
                StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 100, mmi_audply_process_add_files_in_folder);
                return;
            }
        } while (FS_FindNext(add_file_cursor, &file_info, search_path, (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH) ==
             FS_NO_ERROR);
    }

    if (g_mmi_audply_is_folder_empty)
    {
        result = 3;
    }
    mmi_audply_process_add_files_end(result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_process_add_files_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_process_add_files_callback(void)
{
    GoBackToHistory(SCR_ID_AUDPLY_PLAYLIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_process_add_files_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_process_add_files_end(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_data_file_handle >= 0)
    {
        FS_Close(list_data_file_handle);
        list_data_file_handle = -1;
    }
    g_mmi_audply_is_folder_empty = MMI_TRUE;
    if (add_file_cursor >= 0)
    {
        /* re-initialize pick index if necessary */
        if (g_audply.pick_index < 0)
        {
            if (mmi_audply_pick_playlist() >= 0)
            {
                mmi_audply_apply_picked_file();
            }
        }
        if (!is_multi_part_odf)
        {
            FS_FindClose(add_file_cursor);
        }
    #ifdef __DRM_V02__
        else
        {
            if (find_cntx)
            {
                DRM_find_close(find_cntx, add_file_cursor);
                find_cntx = NULL;
            }
        }
    #endif
        add_file_cursor = -1;
        switch (result)
        {
            case 0:
                DisplayPopup((PU8)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, (U8)SUCCESS_TONE);
                break;
            case 1: /* list full */
                DisplayPopupCallBack((PU8)GetString(STR_ID_AUDPLY_LIST_FULL), IMG_GLOBAL_WARNING, 0, 1000, (U8)WARNING_TONE, mmi_audply_process_add_files_callback);
                break; 
            case 2: /* disk full*/
                DisplayPopupCallBack((PU8)GetString(STR_ID_AUDPLY_CANNOT_UPDATE_LIST_DISK_FULL), IMG_GLOBAL_WARNING, 0, 1000, (U8)WARNING_TONE, mmi_audply_process_add_files_callback);
                break;
            case 3: /* empty */
                DisplayPopup((PU8)GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 0, 1000, (U8)EMPTY_LIST_TONE);
                break;
        #ifdef __DRM_V02__
            case 9:
                DisplayPopup((PU8)GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
                break;
        #endif                
            default:
                break;
        }
        
        mdi_audio_resume_background_play();

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_processing_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_processing_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AUDPLY_ADD_FILES, mmi_audply_exit_processing_add, NULL, NULL);

    /* clear End key */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    /* Show searching screen */
    ShowCategory66Screen(
        STR_ID_AUDPLY_OPTION_ADD,
        0,
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) GetString(STR_ID_AUDPLY_PROCESSING),
        IMG_GLOBAL_PROGRESS,
        NULL);

    /* Set RSK to abort searching */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    add_file_cursor = -1;
    list_data_file_handle = -1;
    g_mmi_audply_is_folder_empty = KAL_TRUE;
    
    mdi_audio_suspend_background_play();
    
    StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 100, mmi_audply_process_add_files_in_folder);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_processing_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_processing_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(AUDPLY_PROCESS_ADD_FILE_TIMER);
    if (list_data_file_handle >= 0)
    {
        FS_Close(list_data_file_handle);
        list_data_file_handle = -1;
    }
    if (add_file_cursor >= 0)
    {
        /* re-initialize pick index if necessary */
        if (g_audply.pick_index < 0)
        {
            if (mmi_audply_pick_playlist() >= 0)
            {
                mmi_audply_apply_picked_file();
            }
        }
        if (!is_multi_part_odf)
        {
            FS_FindClose(add_file_cursor);
        }
    #ifdef __DRM_V02__
        else
        {
            DRM_find_close(find_cntx, add_file_cursor);
            find_cntx = NULL;
        }
    #endif       
        add_file_cursor = -1;

        mdi_audio_resume_background_play();

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_add_file_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fullPath        [?]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_add_file_hdlr(S8 *fullPath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;  /* 0: success, 1: disk full, 2: other access file error, 3: list full */
    S16 path_len = 0;
    S8 *end = fullPath;
    S8 *last_backlash;
    UI_character_type drive, code;
    UI_string_type dir_root ;
#ifdef __DRM_V02__
    PS8 ext = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fullPath == NULL)
    {
        GoBackToHistory(SCR_ID_AUDPLY_PLAYLIST);
        return;
    }

    /* check if it's in different storage than present list */
    drive = (UI_character_type) fullPath[0];

    /*config presnet_dir_root*/
    dir_root = mmi_audply_get_present_list_root();
    
    if (drive != dir_root[0])
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_AUDPLY_FILE_IN_DIFFERENT_STORAGE),
            IMG_GLOBAL_WARNING,
            0,
            1000,
            (U8) WARNING_TONE);
        return;
    }
#ifdef __DRM_V02__
    if (NULL != (ext = mmi_ucs2rchr((const PS8)fullPath, (U16)L'.')))
    {
        if (!mmi_ucs2nicmp((const PS8)ext, (const PS8)L".odf", (U32)mmi_ucs2strlen((const PS8)ext)))
        {
            if (DRM_is_archive(0, (PU16)fullPath))
            {
                is_multi_part_odf = TRUE;
            }
            else 
            {
                is_multi_part_odf = FALSE;
            }             
        }
    }
    else
    {
        is_multi_part_odf = FALSE;
    }
#else
    is_multi_part_odf = FALSE;
#endif  /* __DRM_V02__ */   
    for (last_backlash = NULL; (code = (U16) GET_WCHAR(end)) != 0; end += 2, path_len++)
    {
        if (code == L'\\')
        {
            last_backlash = end;
        }
    }
    if ((last_backlash != NULL && end - last_backlash == 2) || is_multi_part_odf)
    {
        /* folder */
        mmi_ucs2cpy((PS8)add_file_path, (const PS8)fullPath);
        mmi_audply_entry_processing_add();
        return;
    }
    else
    {
        /* file */
        if (g_audply.n_total_items >= MAX_PLAY_LIST_NUM)
        {
            DisplayPopup(
                (PU8)GetString(STR_ID_AUDPLY_LIST_FULL),
                IMG_GLOBAL_WARNING,
                0,
                1000,
                (U8)WARNING_TONE);
        }
        else
        {
            /* we are goign to mark L or S in drive char */
            if (is_short)
            {
                MARK_SNAME2(fullPath);  /* mark short name */
            }
            else
            {
                MARK_LNAME2(fullPath);  /* mark long name */
            }

            /* write the path to play list file */
            result = mmi_audply_playlist_append_one(fullPath);
            if (result == 1)
            {
                DisplayPopup(
                    (PU8)GetString(GetFileSystemErrorString(FS_DISK_FULL)),
                    IMG_GLOBAL_ERROR,
                    0,
                    1000,
                    (U8)ERROR_TONE);
            }
            else if (result == 2)
            {
                DisplayPopup(
                    (PU8)GetString(STR_ID_AUDPLY_CANNOT_UPDATE_LIST_FS_FAIL),
                    IMG_GLOBAL_ERROR,
                    0,
                    1000,
                    (U8)ERROR_TONE);            
            }
            else if (result == 0)
            {
                DisplayPopup(
                    (PU8)GetString(STR_GLOBAL_DONE), 
                    IMG_GLOBAL_ACTIVATED, 
                    1, 
                    1000, 
                    (U8)SUCCESS_TONE);
            }
            /* we should not modify the path string bcoz file manager will use it so recover drive char here */
            fullPath[0] = (S8) drive;
        }
    }

    /* re-initialize pick index if necessary */
    if (g_audply.pick_index < 0)
    {
        if (mmi_audply_pick_playlist() >= 0)
        {
            mmi_audply_apply_picked_file();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_can_delete_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fullPath        [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_audply_can_delete_folder(S8 *fullPath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 del_folder_len, play_folder_len;
    PS8 last_backlash;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(mmi_audply_is_play_activated() || g_audply.state == STATE_PAUSED))
    {
        return TRUE;
    }

	
    last_backlash = mmi_ucs2rchr((const PS8)fullPath, (U16)(L'\\'));
    if (last_backlash != NULL)
    {
        del_folder_len = mmi_ucs2strlen((const PS8)fullPath) - mmi_ucs2strlen((const PS8)last_backlash);
		if (mmi_ucs2strlen((const PS8)fullPath) != (del_folder_len + 1))
		{
			del_folder_len = mmi_ucs2strlen((const PS8)fullPath);
		}
    }
    else
    {
        del_folder_len = 0;
    }

    last_backlash = mmi_ucs2rchr((const PS8)g_audply.filefullname, (U16)(L'\\'));
    if (last_backlash != NULL)
    {
        play_folder_len = mmi_ucs2strlen((const PS8)g_audply.filefullname) - mmi_ucs2strlen((const PS8)last_backlash);
    }
    else
    {
        play_folder_len = 0;
    }

    /* check if del folder is a (sub)folder which contains the playing file */
    if (del_folder_len != 0 && del_folder_len <= play_folder_len)
    {
        if (!mmi_ucs2nicmp((const PS8)g_audply.filefullname, (const PS8)fullPath, del_folder_len))
        {
            return FALSE;
        }
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_can_delete_file
 * DESCRIPTION
 *  for FMGR to judge a file about AUDPLY whether can be deleted.
 * PARAMETERS
 *  fullPath        [IN]     
 * RETURNS
 *  BOOL            TRUE - this file can be deleted.
 *                  FALSE - this file is playing.
 *****************************************************************************/
BOOL mmi_audply_can_delete_file(S8 *fullPath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_path_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(mmi_audply_is_play_activated() || g_audply.state == STATE_PAUSED))
    {
        return TRUE;
    }
    file_path_len = mmi_ucs2strlen((const PS8)fullPath) - 1;
    if (mmi_ucs2nicmp((const PS8)g_audply.filefullname, (const PS8)fullPath, (U32)file_path_len) == 0)
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_can_delete_all_files
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fullPath        [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_audply_can_delete_all_files(S8 *fullPath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 del_folder_len, play_folder_len;
    PS8 last_backlash;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(mmi_audply_is_play_activated() || g_audply.state == STATE_PAUSED))
    {
        return TRUE;
    }

    last_backlash = mmi_ucs2rchr((const PS8)fullPath, (U16)(L'\\'));
    if (last_backlash != NULL)
    {
        del_folder_len = mmi_ucs2strlen((const PS8)fullPath) - mmi_ucs2strlen((const PS8)last_backlash) + 1;
    }
    else
    {
        del_folder_len = 0;
    }

    last_backlash = mmi_ucs2rchr((const PS8)g_audply.filefullname, (U16)(L'\\'));
    if (last_backlash != NULL)
    {
        play_folder_len = mmi_ucs2strlen((const PS8)g_audply.filefullname) - mmi_ucs2strlen((const PS8)last_backlash) + 1;
    }
    else
    {
        play_folder_len = 0;
    }

    /* check if del folder is a (sub)folder which contains the playing file */
    if (del_folder_len != 0 && del_folder_len == play_folder_len)
    {
        if (!mmi_ucs2nicmp((const PS8)g_audply.filefullname, (const PS8)fullPath, del_folder_len))
        {
            return FALSE;
        }
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_need_reinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_need_reinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type list_name;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_name = mmi_audply_get_present_list_file();
    if (!mmi_audply_does_file_exist(list_name))
    {
        g_mmi_audply_init_done = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_settings_inlineitem_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_settings_inlineitem_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_settings_inlineitem_spectrum_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_settings_inlineitem_spectrum_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    if(audply_spectrum_lyrics_exclusive)
    {
        if(index!=0)
        {
            selected_lyrics_style = 0 ; /*force lyrics been choosen as off*/
            Category57ChangeItemText(g_audply_lyrics_setting_item_num, (U8*)g_mmi_audply_settings_lyrics[0]);
            RedrawCategoryFunction();
        }
    }
#endif /*__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__*/
    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);    
}
#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_settings_inlineitem_lyrics_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_settings_inlineitem_lyrics_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if(audply_spectrum_lyrics_exclusive)
    {
        if(index!=0)
        {
            selected_spectrum_style = 0 ; /*force spectrum to be choosen as off*/
            Category57ChangeItemText(g_audply_spectrum_setting_item_num, (U8*)g_mmi_audply_settings_spectrum[0]);
            RedrawCategoryFunction();
        }
    }
#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/
    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}
#endif /*__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_show_display_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_audply_show_display_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL show = FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SLIM_AUDIO_PLAYER__    
   return TRUE;       
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__  
    if(g_audply_spectrum_valid)
    {
        show = TRUE;
    }
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    if(g_audply_lyrics_valid)
    {
        show = TRUE;
    }
#endif
    return show;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_two_layers_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_two_layers_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_items;
    U16 settings_item_icons[4];
    U16 settings_option_texts[4];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AUDPLY_SETTINGS, NULL, mmi_audply_entry_two_layers_settings, NULL);

    /* gui buffer */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_SETTINGS);

    n_items = 0;
    /* regenerate list, settings */
    settings_option_texts[n_items] = STR_ID_AUDPLY_PLAYER_SETTINGS;
    settings_item_icons[n_items] = IMG_GLOBAL_L1 + n_items;
    n_items++;

    if(mmi_audply_show_display_settings())
    {
        settings_option_texts[n_items] = STR_ID_AUDPLY_DISPLAY_SETTINGS;
        settings_item_icons[n_items] = IMG_GLOBAL_L1 + n_items;
        n_items++;
    }
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    settings_option_texts[n_items] = STR_ID_AUDPLY_SOUND_EFFECT_SETTINGS;
    settings_item_icons[n_items] = IMG_GLOBAL_L1 + n_items;
    n_items++;
#endif /*defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || defined(__MMI_AUDIO_REVERB_EFFECT__)  || defined(__MMI_AUDIO_SURROUND_EFFECT__)*/ 
#ifdef __MMI_A2DP_SUPPORT__
    settings_option_texts[n_items] = STR_ID_AUDPLY_BLUETOOTH_SETTINGS;
    settings_item_icons[n_items] = IMG_GLOBAL_L1 + n_items;
    n_items++;
#endif /*__MMI_A2DP_SUPPORT__*/
    RegisterHighlightHandler(mmi_audply_two_layer_settings_highlight_hdlr);

    /* show category screen */
    ShowCategory15Screen(
        STR_ID_AUDPLY_OPTION_SETTINGS,
        GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),    /* title text and icon */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,                      /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        n_items,
        settings_option_texts,
        settings_item_icons,
        LIST_MENU,
        0,
        guiBuffer);

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_audply_two_layer_settings_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* register left, right key handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_two_layer_settings_LSK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_two_layer_settings_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_two_layer_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_audply_two_layer_settings_highlighted_item = (U16) index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_check_two_layer_highlighted_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  U16       [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_audply_check_two_layer_highlighted_item(U16 item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(item == AUDPLY_PLAYER_SETTING)
    {
        return AUDPLY_PLAYER_SETTING;
    }
    else if (item == AUDPLY_DISPLAY_SETTING)
    {
        if(mmi_audply_show_display_settings())
        {
            return AUDPLY_DISPLAY_SETTING;
        }
        else
        {
        #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
            return AUDPLY_SOUND_EFFECT_SETTING;
        #else 
        #ifdef __MMI_A2DP_SUPPORT__
            return AUDPLY_BT_SETTING;
        #endif
        #endif
            return AUDPLY_PLAYER_SETTING;
        }
    }
    else if (item == AUDPLY_SOUND_EFFECT_SETTING)
    {
        if(mmi_audply_show_display_settings())
        {
        #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
            return AUDPLY_SOUND_EFFECT_SETTING;
        #else 
        #ifdef __MMI_A2DP_SUPPORT__
            return AUDPLY_BT_SETTING;
        #endif
        #endif
            return AUDPLY_PLAYER_SETTING;
        }
        else
        {
        #ifdef __MMI_A2DP_SUPPORT__
            return AUDPLY_BT_SETTING ;
        #endif
            return AUDPLY_PLAYER_SETTING;
        }
    }
    else
    {
    #ifdef __MMI_A2DP_SUPPORT__
        return AUDPLY_BT_SETTING ;
    #endif
        return AUDPLY_PLAYER_SETTING;        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_two_layer_settings_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_two_layer_settings_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    U16 two_layer_highlight = 0 ;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    selected_list_auto_gen = g_audply.list_auto_gen;
    mmi_fmgr_get_full_storage_inline_list(g_audply.preferred_list,NULL,NULL,(U8*)(&selected_preferred_list));
    selected_repeat_mode = g_audply.repeat_mode;
    selected_random_mode = g_audply.random_mode;
#ifndef __MMI_AUDIO_PLAYER_ON_SUBLCD__        
    selected_background_play = g_audply.background_play;
#endif
#ifndef __MMI_SLIM_AUDIO_PLAYER__    
    selected_skin = g_audply.skin;
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__  
    selected_spectrum_style = g_audply.spectrum_style;
#endif 
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    selected_lyrics_style = g_audply.lyrics_display;
#endif

#ifdef __MMI_AUDIO_TIME_STRETCH__
    selected_speed_index = (S32) mmi_audply_speed_get_index(g_audply.speed);
#endif 

    two_layer_highlight = mmi_audply_check_two_layer_highlighted_item(g_mmi_audply_two_layer_settings_highlighted_item);
    switch (two_layer_highlight)
    {
        case AUDPLY_PLAYER_SETTING: /* Player Setting*/
            mmi_audply_entry_player_settings();
            break;
        case AUDPLY_DISPLAY_SETTING: /* Display Setting */
            mmi_audply_entry_display_settings();
            break;
        case AUDPLY_SOUND_EFFECT_SETTING:
#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
                /*Sound Effect*/
            mmi_audply_entry_sound_effect_settings();
            break;
#endif /*defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)*/
        case AUDPLY_BT_SETTING: /* Bluetooth Setting */
#ifdef __MMI_A2DP_SUPPORT__
            mmi_audply_entry_bluetooth_settings();
            break;
#endif
        default:
            return;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_player_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_player_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 n_items = 0;
    S32 item_offset = 0;
    U16 inputBufferSize;
    U8  total_drv_num;
    UI_string_type drv_inline_list_p = NULL;

    MMI_ID_TYPE item_icons[] = 
    {
        IMG_ID_AUDPLY_SETTINGS_PREFER_LIST,
        0,
        IMG_ID_AUDPLY_SETTINGS_LIST_AUTO_GEN,
        0,
        IMG_ID_AUDPLY_SETTINGS_REPEAT,
        0,
        IMG_ID_AUDPLY_SETTINGS_SHUFFLE,
        0
#ifndef __MMI_AUDIO_PLAYER_ON_SUBLCD__        
        ,IMG_ID_AUDPLY_SETTINGS_BACKGROUND_PLAY
        ,0
#endif
    };
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AUDPLY_PLAYER_SETTINGS, mmi_audply_exit_player_settings, NULL, NULL);

    InitializeCategory57Screen();

    RegisterHighlightHandler(mmi_audply_player_settings_highlight_hdlr);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_PLAYER_SETTINGS);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_AUDPLY_PLAYER_SETTINGS, &inputBufferSize);

    
    /* preferred list */
    mmi_fmgr_get_full_storage_inline_list(NULL,&total_drv_num, (U32*)(&drv_inline_list_p),NULL);
    if (total_drv_num > 1 && drv_inline_list_p != NULL)
    {
        SetInlineItemCaption(&wgui_inline_items[n_items++], (PU8)GetString((U16)(STR_ID_AUDPLY_SETTINGS_PREFER_LIST)));
        SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(
            &wgui_inline_items[n_items],
            (S32)total_drv_num,
            (U8 **) drv_inline_list_p,
            &selected_preferred_list);
        item_offset = 2;
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_highlight_hdlr);
        n_items++;
    }

    /* list auto gen */
    g_mmi_audply_settings_list_auto_gen[0] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_OFF);
    g_mmi_audply_settings_list_auto_gen[1] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_ON);
    SetInlineItemCaption(&wgui_inline_items[n_items++], (PU8)GetString((U16)(STR_ID_AUDPLY_SETTINGS_LIST_AUTO_GEN)));
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[n_items],
        2,
        (U8 **) g_mmi_audply_settings_list_auto_gen,
        &selected_list_auto_gen);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_highlight_hdlr);
    n_items++;

    /* repeat */
    g_mmi_audply_settings_repeat[0] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_OFF);
    g_mmi_audply_settings_repeat[1] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_ONE);
    g_mmi_audply_settings_repeat[2] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_ALL);
    SetInlineItemCaption(&wgui_inline_items[n_items++], (PU8)GetString((U16)(STR_ID_AUDPLY_SETTINGS_REPEAT)));
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[n_items], 3, (U8 **) g_mmi_audply_settings_repeat, &selected_repeat_mode);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_highlight_hdlr);
    n_items++;

    /* shuffle */
    g_mmi_audply_settings_shuffle[0] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_OFF);
    g_mmi_audply_settings_shuffle[1] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_ON);
    SetInlineItemCaption(&wgui_inline_items[n_items++], (PU8)GetString((U16)(STR_ID_AUDPLY_SETTINGS_SHUFFLE)));
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[n_items], 2, (U8 **) g_mmi_audply_settings_shuffle, &selected_random_mode);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_highlight_hdlr);
    n_items++;

    /* background play */
#ifndef __MMI_AUDIO_PLAYER_ON_SUBLCD__        
    g_mmi_audply_settings_background_play[0] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_OFF);
    g_mmi_audply_settings_background_play[1] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_ON);
    SetInlineItemCaption(&wgui_inline_items[n_items++], (PU8)GetString((U16)(STR_ID_AUDPLY_SETTINGS_BACKGROUND_PLAY)));
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[n_items],
        2,
        (U8 **) g_mmi_audply_settings_background_play,
        &selected_background_play);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_highlight_hdlr);
    n_items++;
#endif

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, n_items * 2, inputBuffer);
    }

    /* show category screen */
    ShowCategory57Screen(
        STR_ID_AUDPLY_PLAYER_SETTINGS,
        GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),    /* title text and icon */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,                      /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        n_items,
        item_icons + 2 - item_offset,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57LeftSoftkeyFunction(mmi_audply_player_settings_done);

    DisableCategory57ScreenDone();

    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_player_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_player_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    currHistory.scrnID = SCR_ID_AUDPLY_PLAYER_SETTINGS;
    currHistory.entryFuncPtr = mmi_audply_entry_player_settings;
    GetCategoryHistory(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_player_settings_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_player_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_audply_player_settings_done);
    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_player_settings_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_player_settings_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* if we turn list auto gen ON, we need to regen the list */
    BOOL repeat_mode_changed = (selected_repeat_mode != g_audply.repeat_mode);
    BOOL random_mode_changed = (selected_random_mode != g_audply.random_mode);
    BOOL list_auto_gen_changed = (g_audply.list_auto_gen != selected_list_auto_gen); 
    BOOL prefferred_changed;
    U8 old_present_list = g_audply.present_list;
    S16 error;
    U8 play_list_drv_letter ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_audply.list_auto_gen = (U8) selected_list_auto_gen;
    mmi_fmgr_get_drive_letter_by_inline_index(selected_preferred_list, (S8*)(&play_list_drv_letter));
    prefferred_changed = (g_audply.preferred_list != play_list_drv_letter);
    g_audply.preferred_list = play_list_drv_letter;
    g_audply.repeat_mode = (U8) selected_repeat_mode;
    g_audply.random_mode = (U8) selected_random_mode;
#ifndef __MMI_AUDIO_PLAYER_ON_SUBLCD__
    g_audply.background_play = (U8) selected_background_play;
#endif

    /* save to nvram */
    WriteValue(NVRAM_AUDPLY_LIST_AUTO_GEN, &g_audply.list_auto_gen, DS_BYTE, &error);
    WriteValue(NVRAM_AUDPLY_PREFER_LIST, &g_audply.preferred_list, DS_BYTE, &error);
    WriteValue(NVRAM_AUDPLY_REPEAT, &g_audply.repeat_mode, DS_BYTE, &error);
    WriteValue(NVRAM_AUDPLY_SHUFFLE, &g_audply.random_mode, DS_BYTE, &error);
#ifndef __MMI_AUDIO_PLAYER_ON_SUBLCD__    
    WriteValue(NVRAM_AUDPLY_BACKGROUND_PLAY, &g_audply.background_play, DS_BYTE, &error);
#endif

    if (list_auto_gen_changed)
    {
        if (g_audply.list_auto_gen)
        {
            need_refresh_list = TRUE;
        }
    }
    
    if (prefferred_changed)
    {
        /* update present list */
        g_audply.present_list = mmi_audply_get_preferred_or_available_list();

        if (g_audply.present_list != old_present_list)
        {
            need_reload_list = TRUE;
        }
        /* if the present list is changed and list auto gen is ON, we need to regen the list */
        if (g_audply.list_auto_gen && need_reload_list)
        {
            need_refresh_list = TRUE;
        }
    }

    if (!need_reload_list && (repeat_mode_changed || random_mode_changed) && g_audply.pick_index >= 0)
    {
        mmi_audply_start_playlist_at(g_audply.pick_index);
        mmi_audply_pick_playlist_at(g_audply.pick_index);
    }
    if (g_audply.preferred_list == MMI_CARD_DRV &&
       !g_audply.list_auto_gen &&
        FS_GetDevStatus(g_audply.preferred_list, FS_MOUNT_STATE_ENUM) < 0)
    {
        no_card_in_slot = TRUE;
    }

    /* for sync highlight in list screen with pick index */
    g_mmi_audply_list_highlighted_item = -1;
    
    /* go back */
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_display_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_display_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 n_items = 0;
    U16 inputBufferSize;
    U16 i=0;   
    MMI_ID_TYPE item_icons[3*2] ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SLIM_AUDIO_PLAYER__    
    item_icons[i] = IMG_ID_AUDPLY_SETTINGS_SKIN ;
    item_icons[i+1]= 0 ;
    i += 2 ;
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if(g_audply_spectrum_valid)
    {
        item_icons[i] = IMG_ID_AUDPLY_SETTINGS_SPECTRUM_DISPLAY_STYLE ;
        item_icons[i+1]= 0 ;
        i += 2 ;        
    }
#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/   
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    if(g_audply_lyrics_valid)
    {
        item_icons[i] = IMG_ID_AUDPLY_SETTINGS_LYRICS_DISPLAY_STYLE ;
        item_icons[i+1]= 0 ;
        i += 2 ;        
    }
#endif /*__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__*/   

    if(i==0)
    {
        return;
    }

    EntryNewScreen(SCR_ID_AUDPLY_DISPLAY_SETTINGS, mmi_audply_exit_display_settings, NULL, NULL);

    InitializeCategory57Screen();

    RegisterHighlightHandler(mmi_audply_display_settings_highlight_hdlr);   

    guiBuffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_DISPLAY_SETTINGS);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_AUDPLY_DISPLAY_SETTINGS, &inputBufferSize);
    
    
    /* skin */
#ifndef __MMI_SLIM_AUDIO_PLAYER__    
    g_mmi_audply_settings_skin[0] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_SKIN1);
    g_mmi_audply_settings_skin[1] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_SKIN2);
    g_mmi_audply_settings_skin[2] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_SKIN3);
    SetInlineItemCaption(&wgui_inline_items[n_items++], (PU8)GetString((U16)(STR_ID_AUDPLY_SETTINGS_SKIN)));
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[n_items], NO_OF_SKIN, (U8 **) g_mmi_audply_settings_skin, &selected_skin);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_highlight_hdlr);
    n_items++;
#endif /* __MMI_SLIM_AUDIO_PLAYER__ */ 


#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if(g_audply_spectrum_valid)
    {
        g_mmi_audply_settings_spectrum[0] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_OFF);
        g_mmi_audply_settings_spectrum[1] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_SPECTRUM_DISPLAY_STYLE_1);
        g_mmi_audply_settings_spectrum[2] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_SPECTRUM_DISPLAY_STYLE_2);
        i = 3 ;
        SetInlineItemCaption(&wgui_inline_items[n_items++], (PU8)GetString((U16)(STR_ID_AUDPLY_SETTINGS_SPECTRUM_DISPLAY_STYLE)));
        SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect( 
            &wgui_inline_items[n_items],
            (S32)i,
            (U8**)g_mmi_audply_settings_spectrum,
            &selected_spectrum_style );
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_spectrum_hdlr);
        #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__     
            g_audply_spectrum_setting_item_num = n_items;
        #endif
        n_items++;
    }
#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    if(g_audply_lyrics_valid)
    {
        g_mmi_audply_settings_lyrics[0] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_OFF);
        g_mmi_audply_settings_lyrics[1] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_ON);
        i = 2 ;
        SetInlineItemCaption(&wgui_inline_items[n_items++], (PU8)GetString((U16)(STR_ID_AUDPLY_SETTINGS_LYRICS_DISPLAY)));
        SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect( 
            &wgui_inline_items[n_items],
            (S32)i,
            (U8**)g_mmi_audply_settings_lyrics,
            &selected_lyrics_style );
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_lyrics_hdlr);
        #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
            g_audply_lyrics_setting_item_num = n_items ;
        #endif
        n_items++;
    }
#endif /*__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__*/

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, n_items * 2, inputBuffer);
    }

    /* show category screen */
    ShowCategory57Screen(
        STR_ID_AUDPLY_DISPLAY_SETTINGS,
        GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),    /* title text and icon */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,                      /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        n_items,
        item_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57LeftSoftkeyFunction(mmi_audply_display_settings_done);

    DisableCategory57ScreenDone();

    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_display_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_display_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    currHistory.scrnID = SCR_ID_AUDPLY_DISPLAY_SETTINGS;
    currHistory.entryFuncPtr = mmi_audply_entry_display_settings;
    GetCategoryHistory(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_display_settings_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_display_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_audply_display_settings_done);
    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_display_settings_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_display_settings_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifndef __MMI_SLIM_AUDIO_PLAYER__
    BOOL skin_changed = (g_audply.skin != selected_skin);
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    BOOL style_changed = (selected_spectrum_style != g_audply.spectrum_style) ;
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    BOOL lyrics_changed = (selected_lyrics_style != g_audply.lyrics_display) ;
#endif

    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* apply it */
#ifndef __MMI_SLIM_AUDIO_PLAYER__    
    g_audply.skin = (U8) selected_skin;
#endif

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__ 
    if(g_audply_spectrum_valid)
    {
        g_audply.spectrum_style = (U8) selected_spectrum_style;

        if (style_changed && g_audply.state == STATE_PLAY && !g_audply_spectrum_blocked)
        {
    #ifdef __MMI_SUBLCD__
            mmi_audply_calc_spectrum(selected_spectrum_style != 0);
            if (g_idle_context.IsSubLcdOnIdleScreen == SUBLCD_ON_IDLE_NORMAL)
            {
                ShowIdleAppSubLcd();
            }
    #endif /* __MMI_SUBLCD__ */ 
        }
    }
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    if(g_audply_lyrics_valid)
    {
        g_audply.lyrics_display = (U8) selected_lyrics_style;
    }
#endif

    /* save to nvram */
#ifndef __MMI_SLIM_AUDIO_PLAYER__
    WriteValue(NVRAM_AUDPLY_SKIN, &g_audply.skin, DS_BYTE, &error);
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    WriteValue(NVRAM_AUDPLY_SPECTRUM_DISPLAY_STYLE, &g_audply.spectrum_style, DS_BYTE, &error);
#endif    
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    WriteValue(NVRAM_AUDPLY_LYRICS_DISPLAY, &g_audply.lyrics_display, DS_BYTE, &error);
#endif


    /* go back */
    settings_done_back_to_main = FALSE;
#ifndef __MMI_SLIM_AUDIO_PLAYER__
    if (skin_changed)
    {
        settings_done_back_to_main = TRUE;
    }
#endif    
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if(g_audply_spectrum_valid && style_changed)
    {
        settings_done_back_to_main = TRUE;
    }
#endif     
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    if(g_audply_lyrics_valid && lyrics_changed)
    {
        settings_done_back_to_main = TRUE;
    }        
#endif 

    /* for sync highlight in list screen with pick index */
    g_mmi_audply_list_highlighted_item = -1;


    if (settings_done_back_to_main)
    {
        GoBackToHistory(SCR_ID_AUDPLY_MAIN);
    }
    else
    {
        GoBackHistory();
    }
}

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_audio_effect_inlineitem_highlight_hdlr_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_audio_effect_inlineitem_highlight_hdlr_2(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_AUDIO_EQUALIZER__
    if (g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_EQ)
    { 
        current_audio_equalizer_index = index; 
    }
    else
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    if(g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_REVERB)
    {
        current_audio_reverb_index = index ;
    }
    else
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    if(g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_SURROUND)
    {
        current_audio_surround_index = index ;
    }
#endif

    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_audio_effect_inlineitem_highlight_hdlr_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_audio_effect_inlineitem_highlight_hdlr_1(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_settings_current_audio_effect_prev == index)
        return ;


    switch(index)
    {
        case SETTINGS_SOUND_EFFECTS_NONE:
            g_settings_current_audio_effect = index;            
            break;
            
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ:
            g_settings_current_effect_index = current_audio_equalizer_index ;
            g_settings_current_audio_effect = index;
            break;
    #endif

    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB:
            g_settings_current_effect_index = current_audio_reverb_index ;
            g_settings_current_audio_effect = index;
            break;
    #endif

    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND:
            g_settings_current_effect_index = current_audio_surround_index ;
            g_settings_current_audio_effect = index;
            break;
    #endif
    
        default:
            break;
    }


    EntryNewScreen(SCR_ID_AUDPLY_BASE,NULL,NULL,NULL);
    GoBackHistory();

    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_sound_effect_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_sound_effect_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 n_items = 0;
    U16 inputBufferSize;
    U16 i;
    U16 count = 0;
    S32 inline_num = 0;

    MMI_ID_TYPE item_icons[] = 
    {
    #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
            IMG_ID_SETTING_AUDIO_EQUALIZER,
            0,
            0,
    #endif 
    #ifdef __MMI_AUDIO_TIME_STRETCH__
             IMG_ID_AUDPLY_SETTINGS_SPEED,
             0,
    #endif 
            NO_OF_AUDIO_PLAYER_ICON
    };

#if defined(__MMI_AUDIO_EQUALIZER__) && !defined(__MMI_EDITABLE_AUDIO_EQUALIZER__)
    MMI_ID_TYPE audio_equalizer_list_strings[] = 
    {
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_1,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_2,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_3,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_4,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_5,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_6,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_7,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_8
    };
#endif /* defined(__MMI_AUDIO_EQUALIZER__) && !defined(__MMI_EDITABLE_AUDIO_EQUALIZER__) */
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    MMI_ID_TYPE audio_reverb_list_strings[] = 
    {
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET1,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET2,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET3,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET4,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET5,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET6
    };
#endif /* __MMI_AUDIO_REVERB_EFFECT__ */ 
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    MMI_ID_TYPE audio_surround_list_strings[] = 
    {
        STR_ID_SETTING_AUDIO_SURROUND_MODE1,
        STR_ID_SETTING_AUDIO_SURROUND_MODE2,
    };
#endif /* __MMI_AUDIO_SURROUND_EFFECT__ */ 

#ifdef __MMI_AUDIO_TIME_STRETCH__
    MMI_ID_TYPE audio_speed_list_strings[] = 
    {
        STR_ID_AUDPLY_SPEED_NORMAL,
        STR_ID_AUDPLY_SPEED_FAST1,
        STR_ID_AUDPLY_SPEED_FAST2,
        STR_ID_AUDPLY_SPEED_SLOW2,
        STR_ID_AUDPLY_SPEED_SLOW1
    };
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AUDPLY_SOUND_EFFECT_SETTINGS, mmi_audply_exit_sound_effect_settings, NULL, NULL);

    InitializeCategory57Screen();

    RegisterHighlightHandler(mmi_audply_sound_effect_settings_highlight_hdlr);   

    guiBuffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_SOUND_EFFECT_SETTINGS);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_AUDPLY_SOUND_EFFECT_SETTINGS, &inputBufferSize);

#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)

    if(!guiBuffer)
    {
        g_settings_current_audio_effect = g_settings_selected_audio_effect;
    #ifdef __MMI_AUDIO_EQUALIZER__
        current_audio_equalizer_index = g_settings_audio_equalizer.index;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        current_audio_reverb_index = g_mmi_aud_3d_cntx.reverb_index;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        current_audio_surround_index = g_mmi_aud_3d_cntx.surround_index;
    #endif
    }    

    switch(g_settings_current_audio_effect)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ :
            for (i = 0; i < g_settings_audio_equalizer.count; i++)
            {
            #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
                g_settings_audio_effects_inline2[i] = (UI_string_type) g_settings_audio_equalizer.setting_name[i];
            #else 
                g_settings_audio_effects_inline2[i] = (UI_string_type) GetString(audio_equalizer_list_strings[i]);
            #endif
            }
            inline_num = g_settings_audio_equalizer.count;
            g_settings_current_effect_index = current_audio_equalizer_index ;
            break;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB :
            for (i = 0; i <= MAX_AUDIO_REVERB_EFFECT_NUM; i++)
            {
                g_settings_audio_effects_inline2[i] = (UI_string_type) GetString(audio_reverb_list_strings[i]);
            }
            inline_num = MAX_AUDIO_REVERB_EFFECT_NUM ;
            g_settings_current_effect_index = current_audio_reverb_index ;
            break;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND :
            if(g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_SURROUND)
            {
                for(i = 0 ; i < AUD_SURROUND_TOTAL ; i++)
                {
                    g_settings_audio_effects_inline2[i] = (UI_string_type) GetString(audio_surround_list_strings[i]);
                }
                inline_num = AUD_SURROUND_TOTAL ;
                g_settings_current_effect_index = current_audio_surround_index ;
            }
            break;
    #endif
        default:
            break;

    }


    g_settings_audio_effects_inline1[count++] = (UI_string_type) GetString((U16)(STR_GLOBAL_OFF));
#ifdef __MMI_AUDIO_EQUALIZER__
    g_settings_audio_effects_inline1[count++] = (UI_string_type) GetString((U16)(STR_ID_SETTING_AUDIO_EQUALIZER));
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    g_settings_audio_effects_inline1[count++] = (UI_string_type) GetString((U16)(STR_ID_SETTING_AUDIO_REVERB_EFFECT));
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    g_settings_audio_effects_inline1[count] = (UI_string_type) GetString((U16)(STR_ID_SETTING_AUDIO_SURROUND_EFFECT));        
#endif
    
    SetInlineItemCaption(&wgui_inline_items[n_items++], (PU8)GetString((U16)(STR_ID_SETTING_AUDIO_EFFECT)));
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    g_settings_current_audio_effect_prev = g_settings_current_audio_effect;
    SetInlineItemSelect(
        &wgui_inline_items[n_items],
        NO_OF_SETTINGS_SOUND_EFFECTS,
        (U8 **) g_settings_audio_effects_inline1,
        &g_settings_current_audio_effect);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_audio_effect_inlineitem_highlight_hdlr_1);
    n_items++;

    if(g_settings_current_audio_effect != SETTINGS_SOUND_EFFECTS_NONE)
    {
        SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(
            &wgui_inline_items[n_items],
            inline_num,
            (U8 **) g_settings_audio_effects_inline2,
            &g_settings_current_effect_index);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_audio_effect_inlineitem_highlight_hdlr_2);
        n_items++;
    }
    else
    {
        SetInlineItemCaption(&wgui_inline_items[n_items++], (PU8)GetString((U16)(STR_GLOBAL_EMPTY)));
    }

#endif

#ifdef __MMI_AUDIO_TIME_STRETCH__
    for (i = 0; i < MDI_AUDIO_MAX_SPEED_NUM; i++)
    {
        g_mmi_audply_settings_speed[i] = (UI_string_type) GetString(audio_speed_list_strings[i]);
    }
    SetInlineItemCaption(&wgui_inline_items[n_items++], (PU8)GetString((U16)(STR_ID_AUDPLY_SPEED)));    
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[n_items],
        MDI_AUDIO_MAX_SPEED_NUM,
        (U8 **) g_mmi_audply_settings_speed,
        &selected_speed_index);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_highlight_hdlr);    
    n_items++;
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 


    /* show category screen */
    ShowCategory57Screen(
        STR_ID_AUDPLY_SOUND_EFFECT_SETTINGS,
        GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),    /* title text and icon */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,                      /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        n_items,
        item_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57LeftSoftkeyFunction(mmi_audply_sound_effect_settings_done);

    DisableCategory57ScreenDone();

    SetCategory57RightSoftkeyFunctions(mmi_audply_sound_effect_settings_back, mmi_audply_sound_effect_settings_back);

    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_sound_effect_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_sound_effect_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    currHistory.scrnID = SCR_ID_AUDPLY_SOUND_EFFECT_SETTINGS;
    currHistory.entryFuncPtr = mmi_audply_entry_sound_effect_settings;
    GetCategoryHistory(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_sound_effect_settings_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_sound_effect_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_audply_sound_effect_settings_done);
    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_sound_effect_settings_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_sound_effect_settings_confirm_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_TIME_STRETCH__
    S16 error;
#endif 
#if defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_AUDIO_TIME_STRETCH__)
    U16 prev_speed = g_audply.speed;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check format and apply change begore apply speed */
#ifdef __MMI_AUDIO_TIME_STRETCH__
#ifdef __MMI_A2DP_SUPPORT__
    /* check if need to reopen av bt */
    if (prev_speed == MDI_AUDIO_SPEED_NORMAL && prev_speed != g_audply.speed &&
        mmi_audply_is_output_to_bt() && av_bt_is_mp3_cfg())
    {
        mmi_audply_sync_bt_output();
    }
#endif /* __MMI_BT_MTK_SUPPORT__ && __MMI_A2DP_SUPPORT__ */
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

    /* apply it */

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    if(g_settings_selected_audio_effect != g_settings_current_audio_effect || 
       g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_NONE)

    {
        mmi_settings_turn_off_audio_effect();
    }

    switch(g_settings_current_audio_effect)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ :
            mmi_settings_audio_eq_apply((S16) current_audio_equalizer_index);
            break;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB :
            mmi_settings_audio_reverb_apply((U16) current_audio_reverb_index);
            break;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND :
            mmi_settings_audio_surround_apply((U16)current_audio_surround_index);
            break;
    #endif
        default :
            break;
    }

    g_settings_selected_audio_effect = g_settings_current_audio_effect;
    mmi_settings_audio_effect_write_nvram();

#endif /*__MMI_AUDIO_EQUALIZER__ || __MMI_AUDIO_REVERB_EFFECT__ || __MMI_AUDIO_SURROUND_EFFECT__*/

    /* save to nvram : the other two are done while applying*/
#ifdef __MMI_AUDIO_TIME_STRETCH__
    WriteValue(NVRAM_AUDIO_SPEED_VALUE, &g_audply.speed, DS_SHORT, &error);
#endif 

    /* for sync highlight in list screen with pick index */
    g_mmi_audply_list_highlighted_item = -1;


    DeleteScreenIfPresent(SCR_ID_AUDPLY_SOUND_EFFECT_SETTINGS);

    GoBackHistory();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_sound_effect_settings_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_sound_effect_settings_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    GoBackHistory();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_sound_effect_settings_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_sound_effect_settings_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check format and apply change begore apply speed */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    if (!mmi_audply_apply_change_in_setting((U16) selected_speed_index))
    {
        DisplayPopup((PU8) GetString(STR_ID_AUDPLY_UNSUPPORTED_SPEED), IMG_GLOBAL_ERROR, 0, 1000, (U8) ERROR_TONE);
        return;
    }
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

#ifdef __MMI_AUDIO_SURROUND_BIND_EARPHONE__
    if(g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_SURROUND)
    {
        DisplayConfirm(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            get_string(STR_ID_SETTING_AUDIO_SURROUND_PLUG_EAPHONE),
            0,
            WARNING_TONE);
        SetLeftSoftkeyFunction(mmi_audply_sound_effect_settings_confirm_done, KEY_EVENT_UP);
    }
    else
#endif /* __MMI_AUDIO_SURROUND_BIND_EARPHONE__ */
    {
        mmi_audply_sound_effect_settings_confirm_done();
    }
}


#endif /*#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_TIME_STRETCH__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) */

#ifdef __MMI_A2DP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_bts_inline_default_callback
 * DESCRIPTION
 *  callback function for setting "BT A2DP output"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 *mmi_audply_bts_inline_default_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (selected_bt_a2dp_output == -1 || selected_bt_a2dp_output == 0)
    {
        return (PU8)GetString(STR_ID_AUDPLY_SETTINGS_OFF);
    }
    else if (selected_bt_a2dp_output == 1)
    {
        return (PU8)GetString(STR_ID_AUDPLY_SETTINGS_ON);
    }
    else
    {
        selected_bt_a2dp_output = 0;
        return (PU8)GetString(STR_ID_AUDPLY_SETTINGS_OFF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_bts_inline_change_select_callback
 * DESCRIPTION
 *  callback function for setting "BT A2DP output"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 *mmi_audply_bts_inline_change_select_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (selected_bt_a2dp_output == 0)
    {
        selected_bt_a2dp_output = 1;
        return (PU8)GetString(STR_ID_AUDPLY_SETTINGS_ON);
    }
    else if (selected_bt_a2dp_output == 1)
    {
        selected_bt_a2dp_output = 0;
        return (PU8)GetString(STR_ID_AUDPLY_SETTINGS_OFF);
    }
    else if (selected_bt_a2dp_output == -1)
    {
        return (PU8)GetString(STR_ID_AUDPLY_SETTINGS_OFF);
    }
    else
    {
        selected_bt_a2dp_output = 0;
        return (PU8)GetString(STR_ID_AUDPLY_SETTINGS_OFF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_sap_block_a2dp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_sap_block_a2dp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bt_is_simap_server_activate())
    {
        DisplayPopup(
            (PU8)GetString(STR_BT_PROHIBIT_BY_SIMAP),
            IMG_GLOBAL_WARNING,
            1,
            1000,
            (U8)WARNING_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_bluetooth_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_bluetooth_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 n_items = 0;
    U16 inputBufferSize;
    mmi_bt_dev_struct *selected_bth_dev;
    MMI_ID_TYPE item_icons[] = 
    {
        IMG_PROFILES_BT,
        0,
        IMG_PROFILES_HEADSET,
        0
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AUDPLY_BLUETOOTH_SETTINGS, mmi_audply_exit_bluetooth_settings, NULL, NULL);

    InitializeCategory57Screen();

    RegisterHighlightHandler(mmi_audply_bluetooth_settings_highlight_hdlr);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_BLUETOOTH_SETTINGS);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_AUDPLY_BLUETOOTH_SETTINGS, &inputBufferSize);

    /* init setting values */
    if (inputBuffer == NULL)
    {
        /* Check SAP state */
        if (mmi_bt_is_simap_server_activate())
        {
            selected_bt_a2dp_output = -1;     
        }
        else if (bt_settings.bt_a2dp_output)
        {
            selected_bt_a2dp_output = 1;
        }
        else
        {
            selected_bt_a2dp_output = 0;
        }
        selected_bt_a2dp_headset_temp = NULL;
        selected_bth_dev = mmi_audply_get_bt_headset();
        if (selected_bth_dev == NULL)
        {
            mmi_ucs2cpy((PS8)setting_bt_a2dp_headset_name, (const PS8)GetString(STR_GLOBAL_NONE));
        }
        else
        {
            med_util_utf8_to_ucs2((kal_uint8*) setting_bt_a2dp_headset_name, MMI_BT_BD_NAME_LEN,
                (kal_uint8*) selected_bth_dev->name, MMI_BT_BD_NAME_LEN);
        }
    }
    else if (selected_bt_a2dp_headset_temp)
    {
        /* back from history */
        med_util_utf8_to_ucs2((kal_uint8*) setting_bt_a2dp_headset_name, MMI_BT_BD_NAME_LEN,
            (kal_uint8*) selected_bt_a2dp_headset_temp->name, MMI_BT_BD_NAME_LEN);
    }

    /* BT A2DP Output */
    g_mmi_audply_settings_bt_a2dp_output[0] = GetString(STR_ID_AUDPLY_SETTINGS_OFF);
    g_mmi_audply_settings_bt_a2dp_output[1] = GetString(STR_ID_AUDPLY_SETTINGS_ON);
    
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[n_items], (PU8)GetString((U16)(STR_ID_AUDPLY_SETTINGS_BT_A2DP_OUTPUT)));
    n_items++;
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemUserDefinedSelect(
        &wgui_inline_items[n_items],
        mmi_audply_bts_inline_default_callback,
        mmi_audply_bts_inline_change_select_callback,
        mmi_audply_bts_inline_change_select_callback
        );
    /*SetInlineItemSelect(&wgui_inline_items[n_items], 2, (U8 **) g_mmi_audply_settings_bt_a2dp_output,
        &selected_bt_a2dp_output);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_highlight_hdlr);*/
    

    /* BT A2DP Headset */
    n_items++;
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[n_items], (PU8)GetString((U16)(STR_ID_AUDPLY_SETTINGS_BT_A2DP_HEADSET)));
    n_items++;
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDisplayOnly(&wgui_inline_items[n_items], (U8*) setting_bt_a2dp_headset_name);    
    n_items++;

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, n_items * 2, inputBuffer);
    }

    /* show category screen */
    ShowCategory57Screen(
        STR_ID_AUDPLY_BLUETOOTH_SETTINGS,
        GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),    /* title text and icon */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,                      /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        n_items,
        item_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    DisableCategory57ScreenDone();

    /* register volume inc, dec handlers */
//    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
//    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_bluetooth_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_bluetooth_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_AUDPLY_BLUETOOTH_SETTINGS;
    h.entryFuncPtr = mmi_audply_entry_bluetooth_settings;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_bluetooth_settings_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_bluetooth_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    if (index == 3) /* select headset */
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetCategory57LeftSoftkeyFunction(mmi_audply_select_bt_a2dp_headset);
        if (selected_bt_a2dp_headset_temp)
        {
            ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
            SetCategory57RightSoftkeyFunctions(mmi_audply_bluetooth_settings_done,
                mmi_audply_bluetooth_settings_done);
        }
        else
        {
            ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
            SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
        }
    }
    else if (index == 1)
    {
        SetKeyHandler(mmi_audply_sap_block_a2dp, KEY_LEFT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_audply_sap_block_a2dp, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
        ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
        SetCategory57LeftSoftkeyFunction(mmi_audply_bluetooth_settings_done);
        SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
        ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
        SetCategory57LeftSoftkeyFunction(mmi_audply_bluetooth_settings_done);
        SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_select_bt_a2dp_headset_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dev     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_select_bt_a2dp_headset_callback(mmi_bt_dev_struct* dev)
{
    selected_bt_a2dp_headset_temp = dev;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_select_bt_a2dp_headset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_select_bt_a2dp_headset(void)
{
    if (mmi_bootup_get_active_flight_mode())
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_AUDPLY_SETTINGS_ERR_CANNOT_USE_BLUETOOTH_IN_FLIGHT_MODE),
            IMG_GLOBAL_WARNING,
            0,
            1000,
            (U8) WARNING_TONE);
    }
    else
    {
        av_bt_select_headset(mmi_audply_select_bt_a2dp_headset_callback);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_bluetooth_settings_apply_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bt_a2dp_output      [IN]
 *  back_to_main        [IN]
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_audply_bluetooth_settings_apply_change(BOOL bt_a2dp_output, BOOL back_to_main)
{
    BOOL headset_changed = FALSE;
    BOOL output_changed = FALSE;
    BOOL two_layers_settings = (AUDPLY_SETTING_ITEM_COUNT > 10);

    if (selected_bt_a2dp_headset_temp != NULL && (!bt_settings.bt_a2dp_headset_valid
        || !av_bt_cmp_bt_addr(&selected_bt_a2dp_headset_temp->bd_addr, &bt_settings.bt_a2dp_headset.bd_addr)))
    {
        /* a headset is selected from list and previous headset is invalid or bt addr are different */
        headset_changed = TRUE;
    }

    if (bt_settings.bt_a2dp_output)
    {
        if (!bt_a2dp_output)
            output_changed = TRUE;
    }
    else
    {
        if (bt_a2dp_output)
            output_changed = TRUE;
    }

    /* update current setting values & write to NVRAM */
    bt_settings.bt_a2dp_output = bt_a2dp_output;
    if (selected_bt_a2dp_headset_temp)
    {
        memcpy( &bt_settings.bt_a2dp_headset, selected_bt_a2dp_headset_temp, 
            sizeof(mmi_bt_dev_struct) );
        bt_settings.bt_a2dp_headset_valid = TRUE;
    }
    mmi_audply_write_bt_settings();

    /* apply output or headset change */
    if (output_changed)
    {
        /* switch output: OFF -> ON or ON -> OFF */
        mmi_audply_switch_bt_output();
    }
    else if(bt_a2dp_output && (headset_changed || !av_bt_is_codec_open()))
    {
        /* output is ON and change headset */
        mmi_audply_sync_bt_output();
    }


    /* for sync highlight in list screen with pick index */
    g_mmi_audply_list_highlighted_item = -1;


    /* go back history */
    if (back_to_main)
    {
        /* go back to audio player main screen */
    #if defined(__MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__) && (defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_AUDIO_EQUALIZER__))
        if (bt_a2dp_output && IsScreenPresent(SCR_ID_AUDPLY_MAIN))
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_AUDPLY_A2DP_BLOCK_EQUALIZER_SPCTRUM),
                IMG_GLOBAL_WARNING,
                0,
                1000,
                (U8) WARNING_TONE);
            DeleteNHistory(1);
        }
        else
    #elif !defined(__MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__) && (defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_AUDIO_EQUALIZER__))
        if (bt_a2dp_output && IsScreenPresent(SCR_ID_AUDPLY_MAIN))
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_AUDPLY_A2DP_BLOCK_EQUALIZER),
                IMG_GLOBAL_WARNING,
                0,
                1000,
                (U8) WARNING_TONE);
            DeleteNHistory(1);
        }
        else
    #elif defined(__MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__) && !(defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_AUDIO_EQUALIZER__))
        if( bt_a2dp_output && IsScreenPresent(SCR_ID_AUDPLY_MAIN))
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_AUDPLY_A2DP_BLOCK_SPECTRUM),
                IMG_GLOBAL_WARNING,
                0,
                1000,
                (U8) WARNING_TONE);
            DeleteNHistory(1);
        }
        else
    #endif
        {
            GoBackToHistory(SCR_ID_AUDPLY_MAIN);
        }
    }
    else if (two_layers_settings)
    {
        /* two layer settings has bluetooth settings screen */
        if (!DeleteScreenIfPresent(SCR_ID_AUDPLY_BLUETOOTH_SETTINGS))
        {
            /* there no popup or some screen on top of bluetooth settings screen */
        #if defined(__MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__) && (defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_AUDIO_EQUALIZER__))
            if (bt_a2dp_output && IsScreenPresent(SCR_ID_AUDPLY_MAIN))
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_AUDPLY_A2DP_BLOCK_EQUALIZER_SPCTRUM),
                    IMG_GLOBAL_WARNING,
                    0,
                    1000,
                    (U8) WARNING_TONE);
                DeleteNHistory(1);
            }
            else
        #endif
        #if !defined(__MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__) && (defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_AUDIO_EQUALIZER__))
            if (bt_a2dp_output && IsScreenPresent(SCR_ID_AUDPLY_MAIN))
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_AUDPLY_A2DP_BLOCK_EQUALIZER),
                    IMG_GLOBAL_WARNING,
                    0,
                    1000,
                    (U8) WARNING_TONE);
                DeleteNHistory(1);
            }
            else
        #endif
        #if defined(__MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__) && !(defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_AUDIO_EQUALIZER__))
            if(bt_a2dp_output && IsScreenPresent(SCR_ID_AUDPLY_MAIN))
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_AUDPLY_A2DP_BLOCK_SPECTRUM),
                    IMG_GLOBAL_WARNING,
                    0,
                    1000,
                    (U8) WARNING_TONE);
                DeleteNHistory(1);
            }
            else
        #endif
            {
                GoBackHistory();
            }
        }
    }
    else
    {
        /* only settings screen */
        if (!DeleteScreenIfPresent(SCR_ID_AUDPLY_SETTINGS))
        {
            /* there no popup or some screen on top of settings screen */
        #if defined(__MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__) && (defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_AUDIO_EQUALIZER__))
            if (bt_a2dp_output && IsScreenPresent(SCR_ID_AUDPLY_MAIN))
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_AUDPLY_A2DP_BLOCK_EQUALIZER_SPCTRUM),
                    IMG_GLOBAL_WARNING,
                    0,
                    1000,
                    (U8) WARNING_TONE);
                DeleteNHistory(1);
            }
            else
        #endif
        #if !defined(__MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__) && (defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_AUDIO_EQUALIZER__))
            if (bt_a2dp_output && IsScreenPresent(SCR_ID_AUDPLY_MAIN))
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_AUDPLY_A2DP_BLOCK_EQUALIZER),
                    IMG_GLOBAL_WARNING,
                    0,
                    1000,
                    (U8) WARNING_TONE);
                DeleteNHistory(1);
            }
            else
        #endif
        #if defined(__MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__) && !(defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_AUDIO_EQUALIZER__))
            if(bt_a2dp_output && IsScreenPresent(SCR_ID_AUDPLY_MAIN))
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_AUDPLY_A2DP_BLOCK_SPECTRUM),
                    IMG_GLOBAL_WARNING,
                    0,
                    1000,
                    (U8) WARNING_TONE);
                DeleteNHistory(1);
            }
            else
        #endif
            {
                GoBackHistory();
            }
        }
    }

    return headset_changed || output_changed;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_bt_delete_device_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bd_addr      [IN]    when it's NULL, means all devices
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_bt_delete_device_callback(mmi_bt_dev_addr* bd_addr)
{
    if (bt_settings.bt_a2dp_output)
    {
        /* if it's delete all, or the target device bt addr is the same with ours, then turn it off */
        if (bd_addr == NULL || av_bt_cmp_bt_addr(bd_addr, &bt_settings.bt_a2dp_headset.bd_addr))
        {
            bt_settings.bt_a2dp_output = KAL_FALSE;
            bt_settings.bt_a2dp_headset_valid = KAL_FALSE;
            mmi_audply_write_bt_settings();

            /* switch output: ON -> OFF */
            mmi_audply_switch_bt_output();
        }
    }
    else if (bt_settings.bt_a2dp_headset_valid)
    {
        /* if it's delete all, or the target device bt addr is the same with ours, then set it invalid */
        if (bd_addr == NULL || av_bt_cmp_bt_addr(bd_addr, &bt_settings.bt_a2dp_headset.bd_addr))
        {
            bt_settings.bt_a2dp_headset_valid = KAL_FALSE;
            mmi_audply_write_bt_settings();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_bt_power_off_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  success      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_bt_power_off_callback(BOOL success)
{
    if (success)
    {
        if (bt_settings.bt_a2dp_output)
        {
            bt_settings.bt_a2dp_output = KAL_FALSE;
            mmi_audply_write_bt_settings();

            /* switch output: ON -> OFF */
            mmi_audply_switch_bt_output();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_bt_power_on_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  success      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_bt_power_on_callback(BOOL success)
{
    if (wait_fot_bt_pwron)
    {
        mmi_audply_bluetooth_settings_apply_change(success, settings_done_back_to_main);
        wait_fot_bt_pwron = FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_bluetooth_settings_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_bluetooth_settings_done(void)
{
    BOOL bt_a2dp_output = (selected_bt_a2dp_output == 1);

    /* only two layers settings will invoke this function, so no need back to main */
    settings_done_back_to_main = FALSE;

    if (bt_a2dp_output && selected_bt_a2dp_headset_temp == NULL
        && !bt_settings.bt_a2dp_headset_valid)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_AUDPLY_SETTINGS_ERR_MUST_SELECT_HEADSET),
            IMG_GLOBAL_WARNING,
            0,
            1000,
            (U8) WARNING_TONE);
    }
    else if (bt_a2dp_output)
    {
        /* when BT A2DP Output is ON and BT is not power on, 
         * check if it's not in flight mode then we power on BT 
         */
        if (mmi_bootup_get_active_flight_mode())
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_AUDPLY_SETTINGS_ERR_CANNOT_USE_BLUETOOTH_IN_FLIGHT_MODE),
                IMG_GLOBAL_WARNING,
                0,
                1000,
                (U8) WARNING_TONE);
        }
        else if (!mmi_bt_is_power_on(FALSE))
        {
            mmi_bt_entry_power_switch();
            wait_fot_bt_pwron = TRUE;
        }
        else
        {
            mmi_audply_bluetooth_settings_apply_change(bt_a2dp_output, settings_done_back_to_main);
        }
    }
    else
    {
        mmi_audply_bluetooth_settings_apply_change(bt_a2dp_output, settings_done_back_to_main);
    }
}
#endif /* __MMI_A2DP_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_settings()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 i;
    U16 inputBufferSize;
    U16 n_items = 0;
    U8 total_drv_num;
    S32 inline_num = 0;
    U16 count = 0;
    UI_string_type drv_inline_list_p = NULL;
    MMI_ID_TYPE item_icons[AUDPLY_SETTING_ITEM_COUNT];
   
#if defined(__MMI_AUDIO_EQUALIZER__) && !defined(__MMI_EDITABLE_AUDIO_EQUALIZER__)
    MMI_ID_TYPE audio_equalizer_list_strings[] = 
    {
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_1,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_2,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_3,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_4,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_5,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_6,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_7,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_8
    };
#endif /* defined(__MMI_AUDIO_EQUALIZER__) && !defined(__MMI_EDITABLE_AUDIO_EQUALIZER__) */ 
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    MMI_ID_TYPE audio_reverb_list_strings[] = 
    {
        STR_GLOBAL_NONE,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET1,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET2,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET3,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET4,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET5,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET6
    };
#endif /* __MMI_AUDIO_REVERB_EFFECT__ */ 
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    MMI_ID_TYPE audio_surround_list_strings[] = 
    {
        STR_GLOBAL_OFF,
        STR_ID_SETTING_AUDIO_SURROUND_MODE1,
        STR_ID_SETTING_AUDIO_SURROUND_MODE2,
    };
#endif /* __MMI_AUDIO_SURROUND_EFFECT__ */ 
#ifdef __MMI_AUDIO_TIME_STRETCH__
    MMI_ID_TYPE audio_speed_list_strings[] = 
    {
        STR_ID_AUDPLY_SPEED_NORMAL,
        STR_ID_AUDPLY_SPEED_FAST1,
        STR_ID_AUDPLY_SPEED_FAST2,
        STR_ID_AUDPLY_SPEED_SLOW2,
        STR_ID_AUDPLY_SPEED_SLOW1
    };
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
    mmi_bt_dev_struct *selected_bth_dev;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AUDPLY_SETTINGS, mmi_audply_exit_settings, NULL, NULL);

    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_SETTINGS);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_AUDPLY_SETTINGS, &inputBufferSize);

    RegisterHighlightHandler(mmi_audply_settings_highlight_hdlr);

    if (guiBuffer == NULL)
    {
        selected_list_auto_gen = g_audply.list_auto_gen;
        mmi_fmgr_get_full_storage_inline_list(g_audply.preferred_list,NULL,NULL,(U8*)(&selected_preferred_list));
    #ifndef __MMI_SLIM_AUDIO_PLAYER__        
        selected_skin = g_audply.skin;
    #endif
        selected_repeat_mode = g_audply.repeat_mode;
        selected_random_mode = g_audply.random_mode;
    #ifndef __MMI_AUDIO_PLAYER_ON_SUBLCD__            
        selected_background_play = g_audply.background_play;
    #endif

    
    #if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
        g_settings_current_audio_effect = g_settings_selected_audio_effect;
    #ifdef __MMI_AUDIO_EQUALIZER__
        current_audio_equalizer_index = (U16)g_settings_audio_equalizer.index;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        current_audio_reverb_index = g_mmi_aud_3d_cntx.reverb_index;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        current_audio_surround_index = g_mmi_aud_3d_cntx.surround_index;
    #endif
    #endif /*__MMI_AUDIO_EQUALIZER__ || __MMI_AUDIO_REVERB_EFFECT__ || __MMI_AUDIO_SURROUND_EFFECT__*/

    #ifdef __MMI_AUDIO_TIME_STRETCH__
        selected_speed_index = (S32) mmi_audply_speed_get_index(g_audply.speed);
    #endif 

    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__  
        selected_spectrum_style = g_audply.spectrum_style;
    #endif 
    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        selected_lyrics_style = g_audply.lyrics_display;
    #endif
    #ifdef __MMI_A2DP_SUPPORT__
        /* Check SAP state */
        if (mmi_bt_is_simap_server_activate())
        {
            selected_bt_a2dp_output = -1;     
        }
        else if (bt_settings.bt_a2dp_output)
        {
            selected_bt_a2dp_output = 1;
        }
        else
        {
            selected_bt_a2dp_output = 0;
        }
        
        selected_bt_a2dp_headset_temp = NULL;
        selected_bth_dev = mmi_audply_get_bt_headset();
        if (selected_bth_dev == NULL)
        {
            mmi_ucs2cpy((PS8)setting_bt_a2dp_headset_name, (const PS8)GetString(STR_GLOBAL_NONE));
        }
        else
        {
            med_util_utf8_to_ucs2((kal_uint8*) setting_bt_a2dp_headset_name, 40,
                (kal_uint8*) selected_bth_dev->name, 32);
        }
    #endif /*  __MMI_A2DP_SUPPORT__ */
    }
#ifdef __MMI_A2DP_SUPPORT__
    else if (selected_bt_a2dp_headset_temp)
    {
        /* back from history */
        med_util_utf8_to_ucs2((kal_uint8*) setting_bt_a2dp_headset_name, 40,
            (kal_uint8*) selected_bt_a2dp_headset_temp->name, 32);
    }
#endif /* __MMI_BT_MTK_SUPPORT__ && __MMI_A2DP_SUPPORT__ */

    /* preferred list */
    mmi_fmgr_get_full_storage_inline_list(NULL,&total_drv_num, (U32*)(&drv_inline_list_p),NULL);
    if (total_drv_num >1 && drv_inline_list_p != NULL)
    {
        SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(
            &wgui_inline_items[n_items],
            (S32)total_drv_num,
            (U8 **) drv_inline_list_p,
            &selected_preferred_list);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_highlight_hdlr);
        item_icons[n_items] = IMG_ID_AUDPLY_SETTINGS_PREFER_LIST ;
        n_items++;
    }

    /* list auto gen */
    g_mmi_audply_settings_list_auto_gen[0] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_OFF);
    g_mmi_audply_settings_list_auto_gen[1] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_ON);
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[n_items],
        2,
        (U8 **) g_mmi_audply_settings_list_auto_gen,
        &selected_list_auto_gen);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_highlight_hdlr);
    item_icons[n_items] = IMG_ID_AUDPLY_SETTINGS_LIST_AUTO_GEN ;
    n_items++;

    /* skin */
#ifndef __MMI_SLIM_AUDIO_PLAYER__    
    g_mmi_audply_settings_skin[0] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_SKIN1);
    g_mmi_audply_settings_skin[1] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_SKIN2);
    g_mmi_audply_settings_skin[2] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_SKIN3);
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[n_items], NO_OF_SKIN, (U8 **) g_mmi_audply_settings_skin, &selected_skin);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_highlight_hdlr);
    item_icons[n_items] = IMG_ID_AUDPLY_SETTINGS_SKIN ;
    n_items++;
#endif /* __MMI_SLIM_AUDIO_PLAYER__ */ 

    /* repeat */
    g_mmi_audply_settings_repeat[0] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_OFF);
    g_mmi_audply_settings_repeat[1] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_ONE);
    g_mmi_audply_settings_repeat[2] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_ALL);
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[n_items], 3, (U8 **) g_mmi_audply_settings_repeat, &selected_repeat_mode);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_highlight_hdlr);
    item_icons[n_items] = IMG_ID_AUDPLY_SETTINGS_REPEAT ;
    n_items++;

    /* shuffle */
    g_mmi_audply_settings_shuffle[0] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_OFF);
    g_mmi_audply_settings_shuffle[1] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_ON);
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[n_items], 2, (U8 **) g_mmi_audply_settings_shuffle, &selected_random_mode);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_highlight_hdlr);
    item_icons[n_items] = IMG_ID_AUDPLY_SETTINGS_SHUFFLE ;
    n_items++;

    /* background play */
#ifndef __MMI_AUDIO_PLAYER_ON_SUBLCD__        
    g_mmi_audply_settings_background_play[0] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_OFF);
    g_mmi_audply_settings_background_play[1] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_ON);
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[n_items],
        2,
        (U8 **) g_mmi_audply_settings_background_play,
        &selected_background_play);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_highlight_hdlr);
    item_icons[n_items] = IMG_ID_AUDPLY_SETTINGS_BACKGROUND_PLAY ;
    n_items++;
#endif

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
    /* BT A2DP Output */
    g_mmi_audply_settings_bt_a2dp_output[0] = GetString(STR_ID_AUDPLY_SETTINGS_OFF);
    g_mmi_audply_settings_bt_a2dp_output[1] = GetString(STR_ID_AUDPLY_SETTINGS_ON);
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemUserDefinedSelect(
        &wgui_inline_items[n_items],
        mmi_audply_bts_inline_default_callback,
        mmi_audply_bts_inline_change_select_callback,
        mmi_audply_bts_inline_change_select_callback
        );
    /*SetInlineItemSelect(&wgui_inline_items[n_items], 2, (U8 **) g_mmi_audply_settings_bt_a2dp_output,
        &selected_bt_a2dp_output);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_highlight_hdlr);*/
    item_icons[n_items] = IMG_PROFILES_BT;
    n_items++;

    /* BT A2DP Headset */
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDisplayOnly(&wgui_inline_items[n_items], (U8*) setting_bt_a2dp_headset_name);
    item_icons[n_items] = IMG_PROFILES_HEADSET;
    n_items++;
#endif /* __MMI_BT_MTK_SUPPORT__ && __MMI_A2DP_SUPPORT__ */

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)


    switch(g_settings_current_audio_effect)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ :
            for (i = 0; i < g_settings_audio_equalizer.count; i++)
            {
        #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
                g_settings_audio_effects_inline2[i] = (UI_string_type) g_settings_audio_equalizer.setting_name[i];
        #else 
                g_settings_audio_effects_inline2[i] = (UI_string_type) GetString(audio_equalizer_list_strings[i]);
        #endif
            }
            inline_num = g_settings_audio_equalizer.count;
            g_settings_current_effect_index = current_audio_equalizer_index ;            
            break;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB :
            for (i = 0; i <= MAX_AUDIO_REVERB_EFFECT_NUM; i++)
            {
                g_settings_audio_effects_inline2[i] = (UI_string_type) GetString(audio_reverb_list_strings[i]);
            }
            inline_num = MAX_AUDIO_REVERB_EFFECT_NUM ;
            g_settings_current_effect_index = current_audio_reverb_index ;            
            break;
    #endif       
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND :
            for(i = 0 ; i < AUD_SURROUND_TOTAL ; i++)
            {
                g_settings_audio_effects_inline2[i] = (UI_string_type) GetString(audio_surround_list_strings[i]);
            }
            inline_num = AUD_SURROUND_TOTAL ;
            g_settings_current_effect_index = current_audio_surround_index ;            
            break;
    #endif
        default:
            break;
    }


    g_settings_audio_effects_inline1[count++] = (UI_string_type) GetString((U16)(STR_GLOBAL_OFF));
#ifdef __MMI_AUDIO_EQUALIZER__
    g_settings_audio_effects_inline1[count++] = (UI_string_type) GetString((U16)(STR_ID_SETTING_AUDIO_EQUALIZER));
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    g_settings_audio_effects_inline1[count++] = (UI_string_type) GetString((U16)(STR_ID_SETTING_AUDIO_REVERB_EFFECT));
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    g_settings_audio_effects_inline1[count] = (UI_string_type) GetString((U16)(STR_ID_SETTING_AUDIO_SURROUND_EFFECT));        
#endif

    SetInlineItemCaption(&wgui_inline_items[n_items], (PU8)GetString((U16)(STR_ID_SETTING_AUDIO_EFFECT)));
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    g_settings_current_audio_effect_prev = g_settings_current_audio_effect;
    SetInlineItemSelect(
        &wgui_inline_items[n_items],
        NO_OF_SETTINGS_SOUND_EFFECTS,
        (U8 **) g_settings_audio_effects_inline1,
        &g_settings_current_audio_effect);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_audio_effect_inlineitem_highlight_hdlr_1);
    item_icons[n_items] = IMG_ID_SETTING_AUDIO_EQUALIZER;
    n_items++;

    if(g_settings_current_audio_effect != SETTINGS_SOUND_EFFECTS_NONE)
    {
        SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(
            &wgui_inline_items[n_items],
            inline_num,
            (U8 **) g_settings_audio_effects_inline2,
            &g_settings_current_effect_index);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_audio_effect_inlineitem_highlight_hdlr_2);
        item_icons[n_items] = 0;
        n_items++;
    }
    else
    {
        SetInlineItemCaption(&wgui_inline_items[n_items], (PU8)GetString((U16)(STR_GLOBAL_EMPTY)));
        item_icons[n_items] = 0;
        n_items++;
    }
#endif /*defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)*/

#ifdef __MMI_AUDIO_TIME_STRETCH__
    for (i = 0; i < MDI_AUDIO_MAX_SPEED_NUM; i++)
    {
        g_mmi_audply_settings_speed[i] = (UI_string_type) GetString(audio_speed_list_strings[i]);
    }
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[n_items],
        MDI_AUDIO_MAX_SPEED_NUM,
        (U8 **) g_mmi_audply_settings_speed,
        &selected_speed_index);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_highlight_hdlr);    
    item_icons[n_items] = IMG_ID_AUDPLY_SETTINGS_SPEED ;
    n_items++;
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if(g_audply_spectrum_valid)
    {
        g_mmi_audply_settings_spectrum[0] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_OFF);
        g_mmi_audply_settings_spectrum[1] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_SPECTRUM_DISPLAY_STYLE_1);
        g_mmi_audply_settings_spectrum[2] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_SPECTRUM_DISPLAY_STYLE_2);
        i = 3 ;
        SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect( 
            &wgui_inline_items[n_items],
            (S32)i,
            (U8**)g_mmi_audply_settings_spectrum,
            &selected_spectrum_style );
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_spectrum_hdlr);
        #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__     
            g_audply_spectrum_setting_item_num = n_items;
        #endif
        item_icons[n_items] = IMG_ID_AUDPLY_SETTINGS_SPECTRUM_DISPLAY_STYLE ;
        n_items++;
    }
#endif /*__MMI_AUDIO_SPECTRUM_DISPLAY__*/

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    if(g_audply_lyrics_valid)
    {
        g_mmi_audply_settings_lyrics[0] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_OFF);
        g_mmi_audply_settings_lyrics[1] = (UI_string_type) GetString(STR_ID_AUDPLY_SETTINGS_ON);
        i = 2 ;
        SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect( 
            &wgui_inline_items[n_items],
            (S32)i,
            (U8**)g_mmi_audply_settings_lyrics,
            &selected_lyrics_style );
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_settings_inlineitem_lyrics_hdlr);
        #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
            g_audply_lyrics_setting_item_num = n_items ;
        #endif
        item_icons[n_items] = IMG_ID_AUDPLY_SETTINGS_LYRICS_DISPLAY_STYLE ;
        n_items++;
    }
#endif /*__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__*/

    /* show category screen */
    ShowCategory57Screen(
        STR_ID_AUDPLY_OPTION_SETTINGS,
        GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),    /* title text and icon */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,                      /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        n_items,
        item_icons, // + 1 - item_offset,
        wgui_inline_items,
        0,
        guiBuffer);

//    SetCategory57LeftSoftkeyFunction(mmi_audply_settings_LSK);

    DisableCategory57ScreenDone();


    /* register volume inc, dec handlers */
#ifdef __MMI_NO_VOL_KEYS__	//UNI@bw_20070409a 没有音量键的处理//sc.wu __MMI_NO_VOL_KEYS__
	#if defined(__VOL_WITH_28KEY__)
	    SetKeyHandler(mmi_audply_press_inc_volume, KEY_2, KEY_EVENT_DOWN);
	    SetKeyHandler(mmi_audply_press_dec_volume, KEY_8, KEY_EVENT_DOWN);
	#else
	    SetKeyHandler(mmi_audply_press_inc_volume, KEY_2, KEY_EVENT_DOWN);
	    SetKeyHandler(mmi_audply_press_dec_volume, KEY_5, KEY_EVENT_DOWN);
	#endif
#else
	    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
	    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif

    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_settings_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0 ;
#ifdef __MMI_A2DP_SUPPORT__
    U16 bt_headset_index;
#endif
    MMI_ID_TYPE item_texts[AUDPLY_SETTING_ITEM_COUNT] ;
    U8  total_drv_num;
    UI_string_type drv_inline_list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_fmgr_get_full_storage_inline_list(NULL,&total_drv_num, (U32*)(&drv_inline_list_p),NULL);
    if (total_drv_num >1 && drv_inline_list_p != NULL)
    {
        item_texts[i++] = STR_ID_AUDPLY_SETTINGS_PREFER_LIST;
    }
    
    item_texts[i++] = STR_ID_AUDPLY_SETTINGS_LIST_AUTO_GEN;
#ifndef __MMI_SLIM_AUDIO_PLAYER__    
    item_texts[i++] = STR_ID_AUDPLY_SETTINGS_SKIN;
#endif
    item_texts[i++] = STR_ID_AUDPLY_SETTINGS_REPEAT;
    item_texts[i++] = STR_ID_AUDPLY_SETTINGS_SHUFFLE;
#ifndef __MMI_AUDIO_PLAYER_ON_SUBLCD__    
    item_texts[i++] = STR_ID_AUDPLY_SETTINGS_BACKGROUND_PLAY;
#endif
#ifdef __MMI_A2DP_SUPPORT__
    item_texts[i++] = STR_ID_AUDPLY_SETTINGS_BT_A2DP_OUTPUT;
    bt_headset_index = i;
    item_texts[i++] = STR_ID_AUDPLY_SETTINGS_BT_A2DP_HEADSET;
#endif /* __MMI_A2DP_SUPPORT__ */

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    item_texts[i++] = STR_ID_AUDPLY_SOUND_EFFECT_SETTINGS;
    item_texts[i++] = STR_ID_AUDPLY_SOUND_EFFECT_SETTINGS;
#endif    

#ifdef __MMI_AUDIO_TIME_STRETCH__
    item_texts[i++] = STR_ID_AUDPLY_SPEED;
#endif

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if(g_audply_spectrum_valid)
    {
        item_texts[i++] = STR_ID_AUDPLY_SETTINGS_SPECTRUM_DISPLAY_STYLE;
    }
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    if(g_audply_lyrics_valid)
    {
        item_texts[i++] = STR_ID_AUDPLY_SETTINGS_LYRICS_DISPLAY;
    }
#endif

    ChangeTitleString((PU8) GetString(item_texts[index]));
    draw_title();

    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    
#ifdef __MMI_A2DP_SUPPORT__
    if (index == bt_headset_index) /* select headset */
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetCategory57LeftSoftkeyFunction(mmi_audply_select_bt_a2dp_headset);
        if (selected_bt_a2dp_headset_temp)
        {
            ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
            SetCategory57RightSoftkeyFunctions(mmi_audply_settings_LSK,
                mmi_audply_settings_LSK);
        }
        else
        {
            ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
            SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
        }
    }
    else if (index == (bt_headset_index - 1))
    {
        SetKeyHandler(mmi_audply_sap_block_a2dp, KEY_LEFT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_audply_sap_block_a2dp, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
        ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
        SetCategory57LeftSoftkeyFunction(mmi_audply_settings_LSK);
        SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    }
    else
#endif /* __MMI_A2DP_SUPPORT__ */
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
        ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
        SetCategory57LeftSoftkeyFunction(mmi_audply_settings_LSK);
        SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    }

    /* register volume inc, dec handlers */
#ifdef __MMI_NO_VOL_KEYS__	
	// 没有音量键的处理//sc.wu __MMI_NO_VOL_KEYS__
     //Huyanwei Modify it .Have Side Key 
    #if defined(__VOL_WITH_28KEY__)
	    SetKeyHandler(mmi_audply_press_inc_volume, KEY_2, KEY_EVENT_DOWN);
	    SetKeyHandler(mmi_audply_press_dec_volume, KEY_8, KEY_EVENT_DOWN);
     #else
	    SetKeyHandler(mmi_audply_press_inc_volume, KEY_2, KEY_EVENT_DOWN);
	    SetKeyHandler(mmi_audply_press_dec_volume, KEY_5, KEY_EVENT_DOWN);
   #endif
#else
	    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
	    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_settings()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_AUDPLY_SETTINGS;
    h.entryFuncPtr = mmi_audply_entry_settings;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_settings_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_settings_LSK()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* if we turn list auto gen ON, we need to regen the list */
    BOOL repeat_mode_changed = (selected_repeat_mode != g_audply.repeat_mode);
    BOOL random_mode_changed = (selected_random_mode != g_audply.random_mode);
#ifndef __MMI_SLIM_AUDIO_PLAYER__    
    BOOL skin_changed = (g_audply.skin != selected_skin);
#endif
    U8 old_present_list = g_audply.present_list;
    U8 play_list_drv_letter;

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    BOOL style_changed = (selected_spectrum_style != g_audply.spectrum_style) ;
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    BOOL lyrics_changed = (selected_lyrics_style != g_audply.lyrics_display) ;
#endif

#ifdef __MMI_A2DP_SUPPORT__
    BOOL bt_a2dp_output = (selected_bt_a2dp_output == 1);
    BOOL need_power_on_bt = FALSE;
    BOOL bt_a2dp_change;
#endif

#if defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_AUDIO_TIME_STRETCH__)
    U16 prev_speed = g_audply.speed;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check format and apply change begore apply speed */
#ifdef __MMI_AUDIO_TIME_STRETCH__
    if (!mmi_audply_apply_change_in_setting((U16) selected_speed_index))
    {
        DisplayPopup((PU8) GetString(STR_ID_AUDPLY_UNSUPPORTED_SPEED), IMG_GLOBAL_ERROR, 0, 1000, (U8) ERROR_TONE);
        return;
    }
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

#ifdef __MMI_AUDIO_SURROUND_BIND_EARPHONE__
    if(g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_SURROUND)
    {
        if(!mmi_gpio_is_earphone_plug_in())
        {
            DisplayPopup((PU8) GetString(STR_ID_SETTING_AUDIO_SURROUND_PLUG_EAPHONE), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
            return;
        }
    }
#endif /* __MMI_AUDIO_SURROUND_BIND_EARPHONE__ */

#ifdef __MMI_A2DP_SUPPORT__
    /* check prohibted conditions for bt settings */
    if (bt_a2dp_output && selected_bt_a2dp_headset_temp == NULL
        && !bt_settings.bt_a2dp_headset_valid)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_AUDPLY_SETTINGS_ERR_MUST_SELECT_HEADSET),
            IMG_GLOBAL_WARNING,
            0,
            1000,
            (U8) WARNING_TONE);
        return;
    }
    else if (bt_a2dp_output)
    {
        /* when BT A2DP Output is ON and BT is not power on, 
         * check if it's not in flight mode then we power on BT 
         */
        if (mmi_bootup_get_active_flight_mode())
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_AUDPLY_SETTINGS_ERR_CANNOT_USE_BLUETOOTH_IN_FLIGHT_MODE),
                IMG_GLOBAL_WARNING,
                0,
                1000,
                (U8) WARNING_TONE);
            return;
        }
        else if (!mmi_bt_is_power_on(FALSE))
        {
            need_power_on_bt = TRUE;
        }
    }
#endif /* __MMI_A2DP_SUPPORT__ */

    need_refresh_list = (selected_list_auto_gen && (g_audply.list_auto_gen != selected_list_auto_gen));
    /* apply it */
    g_audply.list_auto_gen = (U8) selected_list_auto_gen;
    mmi_fmgr_get_drive_letter_by_inline_index(selected_preferred_list, (S8*)(&play_list_drv_letter));
    g_audply.preferred_list = play_list_drv_letter;
#ifndef __MMI_SLIM_AUDIO_PLAYER__    
    g_audply.skin = (U8) selected_skin;
#endif
    g_audply.repeat_mode = (U8) selected_repeat_mode;
    g_audply.random_mode = (U8) selected_random_mode;
#ifndef __MMI_AUDIO_PLAYER_ON_SUBLCD__    
    g_audply.background_play = (U8) selected_background_play;
#endif


#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)

    if(g_settings_selected_audio_effect != g_settings_current_audio_effect || 
       g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_NONE)
    {
        mmi_settings_turn_off_audio_effect();
    }

    switch(g_settings_current_audio_effect)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ :
            mmi_settings_audio_eq_apply((S16) current_audio_equalizer_index);
            break;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB :
            mmi_settings_audio_reverb_apply(current_audio_reverb_index);
            break;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND :
            mmi_settings_audio_surround_apply_check(current_audio_surround_index);
            break;
    #endif
        default :
            break;
    }

    g_settings_selected_audio_effect = g_settings_current_audio_effect;
    mmi_settings_audio_effect_write_nvram();

#endif /* __MMI_AUDIO_EQUALIZER__ || __MMI_AUDIO_REVERB_EFFECT__ || __MMI_AUDIO_SURROUND_EFFECT__ */


#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__ 
    if(g_audply_spectrum_valid)
    {
        g_audply.spectrum_style = (U8) selected_spectrum_style;

        if (style_changed && g_audply.state == STATE_PLAY)
        {
        #ifdef __MMI_SUBLCD__
            mmi_audply_calc_spectrum(selected_spectrum_style != 0 && !g_audply_spectrum_blocked);
            if (g_idle_context.IsSubLcdOnIdleScreen == SUBLCD_ON_IDLE_NORMAL)
            {
                ShowIdleAppSubLcd();
            }
        #endif /* __MMI_SUBLCD__ */ 
        }
    }
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    if(g_audply_lyrics_valid)
    {
        g_audply.lyrics_display = (U8) selected_lyrics_style;
    }
#endif

    /* save to nvram */
    mmi_audply_write_settings();

    /* update present list */
    g_audply.present_list = mmi_audply_get_preferred_or_available_list();
    need_reload_list = (g_audply.present_list != old_present_list);

    /* if the present list is changed and list auto gen is ON, we need to regen the list */
    if (g_audply.list_auto_gen && need_reload_list)
    {
        need_refresh_list = TRUE;
    }
    if (need_refresh_list)
    {
        need_reload_list = TRUE;
    }

    if (!need_reload_list && (repeat_mode_changed || random_mode_changed) && g_audply.pick_index >= 0)
    {
        mmi_audply_start_playlist_at(g_audply.pick_index);
        mmi_audply_pick_playlist_at(g_audply.pick_index);
    }
    /* go back */
    settings_done_back_to_main = FALSE;    
#ifndef __MMI_SLIM_AUDIO_PLAYER__    
    if (skin_changed)
    {
        settings_done_back_to_main = TRUE;
    }
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if(g_audply_spectrum_valid && style_changed)
    {
        settings_done_back_to_main = TRUE;
    }
#endif     
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    if(g_audply_lyrics_valid && lyrics_changed)
    {
        settings_done_back_to_main = TRUE;
    }        
#endif 


    /* for sync highlight in list screen with pick index */
    g_mmi_audply_list_highlighted_item = -1;


#ifdef __MMI_A2DP_SUPPORT__
    if (need_power_on_bt)
    {
        mmi_bt_entry_power_switch();
        wait_fot_bt_pwron = TRUE;
    }
    else
    {
        bt_a2dp_change = mmi_audply_bluetooth_settings_apply_change(bt_a2dp_output, settings_done_back_to_main);
    #ifdef __MMI_AUDIO_TIME_STRETCH__
        /* check if need to reopen av bt */
        if (!bt_a2dp_change && prev_speed == MDI_AUDIO_SPEED_NORMAL && 
            prev_speed != g_audply.speed && mmi_audply_is_output_to_bt() && 
            av_bt_is_mp3_cfg())
        {
            mmi_audply_sync_bt_output();
        }
    #endif /* __MMI_AUDIO_TIME_STRETCH__ */
    }
#else
    if (g_audply.preferred_list == MMI_CARD_DRV &&
       !g_audply.list_auto_gen &&
        FS_GetDevStatus(g_audply.preferred_list, FS_MOUNT_STATE_ENUM) < 0)
    {
        no_card_in_slot = TRUE;
    }
    if (settings_done_back_to_main)
    {
        GoBackToHistory(SCR_ID_AUDPLY_MAIN);
    }
    else
    {
        GoBackHistory();
    }
#endif /* __MMI_A2DP_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_detail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_detail()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *fields[MAX_DAF_VIEW_FIELDS];
    U16 item_icons[MAX_DAF_VIEW_FIELDS];
    U8 *guiBuffer;
    U8 item_count = 0;
    UI_string_type buffer = fullfilename_temp;
    FS_HANDLE handle;
    BOOL ok;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AUDPLY_DETAIL, mmi_audply_exit_detail, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_DETAIL);

    mmi_audply_playlist_get_fullfilename(buffer, g_mmi_audply_list_highlighted_item);

    /*cehck if file can be open successfully*/
    if ((handle = DRM_open_file((PU16) buffer, FS_READ_ONLY, DRM_PERMISSION_PLAY)) >= FS_NO_ERROR)
    {
        DRM_close_file(handle);
    }
    else if (handle < -1)
    {
        DisplayPopup((PU8)GetString(GetFileSystemErrorString(handle)), IMG_GLOBAL_ERROR, 0, 1000, (U8) ERROR_TONE);
        DeleteUptoScrID(SCR_ID_AUDPLY_PLAYLIST);
        return;
    }
if ((daf_info_p = (aud_info_struct*)get_ctrl_buffer(sizeof(aud_info_struct))) == NULL)
    {
        PRINT_INFORMATION("Audply | Debug - mmi_audply_entry_detail, get_ctrl_buffer() failed!");
        ok = FALSE;
    }
    else if (get_aud_info(buffer, daf_info_p))
    {
        ok = TRUE;
    }
    else
    {
        ok = FALSE;
    }

    if (!ok)
    {
        DisplayPopup((PU8) GetString(STR_ID_AUDPLY_ERROR), IMG_GLOBAL_ERROR, 0, 1000, (U8) ERROR_TONE);
        DeleteUptoScrID(SCR_ID_AUDPLY_PLAYLIST);
    }
    else
    {
    #ifdef __MMI_AUDIO_PLAYER_DETAIL_SHOW_MORE_INFO__
        /* filename */
        S32 file_ext_index ;
        UI_character_type temp_ext[FMGR_MAX_EXT_LEN + 1];
        UI_character_type filename_without_ext[FMGR_MAX_FILE_LEN];
        
        mmi_audply_playlist_get_filename((UI_string_type)daf_info_p->filename, g_mmi_audply_list_highlighted_item);

    #if !defined(__MMI_SHOW_DAF_FILE_EXT__) && defined(DAF_DECODE)
        mmi_audply_split_filename_ext((UI_string_type)daf_info_p->filename, filename_without_ext, temp_ext);
        file_ext_index = mmi_audply_lookup_audio_file_format(temp_ext);
        /* hide daf but show others ext */
        if (file_ext_index == AUDPLY_AUDIO_FILE_TYPE_DAF)
        {
            mmi_ucs2cpy((PS8)daf_info_p->filename,(const PS8)filename_without_ext);    
            fields[item_count] = (S8*) daf_info_p->filename;
        }
        else
    #endif            
        {
            fields[item_count] = (S8*) daf_info_p->filename;
        }

        g_mmi_audply_detail_fields[item_count] = STR_GLOBAL_FILENAME;
        item_icons[item_count++] = IMG_ID_AUDPLY_DETAIL_FILENAME;

        /* channel */
        if (daf_info_p->channel_num != 0)
        {
            if (daf_info_p->channel_num == 1)
            {
                fields[item_count] = GetString(STR_ID_AUDPLY_DETAIL_MONO);
            }
            else
            {
                fields[item_count] = GetString(STR_ID_AUDPLY_DETAIL_STEREO);
            }
            g_mmi_audply_detail_fields[item_count] = STR_ID_AUDPLY_DETAIL_CHANNEL;
            item_icons[item_count++] = IMG_ID_AUDPLY_DETAIL_CHANNEL;
        }

        /* quality */
        if (daf_info_p->quality[0] != 0)
        {
            fields[item_count] = (S8*) daf_info_p->quality;
            g_mmi_audply_detail_fields[item_count] = STR_ID_AUDPLY_DETAIL_QUALITY;
            item_icons[item_count++] = IMG_ID_AUDPLY_DETAIL_QUALITY;
        }
    #endif /* __MMI_AUDIO_PLAYER_DETAIL_SHOW_MORE_INFO__ */ 

        /* size */
        fields[item_count] = (S8*) daf_info_p->size;
        g_mmi_audply_detail_fields[item_count] = STR_ID_AUDPLY_DETAIL_SIZE;
        item_icons[item_count++] = IMG_ID_AUDPLY_DETAIL_FILE;

        /* time */
        if (daf_info_p->duration[0] != 0)
        {
        #ifdef AAC_DECODE
            UI_character_type ext[FMGR_MAX_EXT_LEN + 1];
            mmi_audply_extract_ext((UI_string_type)daf_info_p->filename, ext);        
            if(mmi_audply_lookup_audio_file_format(ext) != AUDPLY_AUDIO_FILE_TYPE_AAC)
        #endif        
            {
                fields[item_count] = (S8*) daf_info_p->duration;
                g_mmi_audply_detail_fields[item_count] = STR_ID_AUDPLY_DETAIL_TIME;
                item_icons[item_count++] = IMG_ID_AUDPLY_DETAIL_TIME;
            }
        }

        if (daf_info_p->title[0] != 0)
        {
            fields[item_count] = (S8*) daf_info_p->title;
            g_mmi_audply_detail_fields[item_count] = STR_ID_AUDPLY_DETAIL_TITLE;
            item_icons[item_count++] = IMG_ID_AUDPLY_DETAIL_TITLE;
        }

        if (daf_info_p->artist[0] != 0)
        {
            fields[item_count] = (S8*) daf_info_p->artist;
            g_mmi_audply_detail_fields[item_count] = STR_ID_AUDPLY_DETAIL_ARTIST;
            item_icons[item_count++] = IMG_ID_AUDPLY_DETAIL_ARTIST;
        }

        if (daf_info_p->album[0] != 0)
        {
            fields[item_count] = (S8*) daf_info_p->album;
            g_mmi_audply_detail_fields[item_count] = STR_ID_AUDPLY_DETAIL_ALBUM;
            item_icons[item_count++] = IMG_ID_AUDPLY_DETAIL_ALBUM;
        }

        if (daf_info_p->genre[0] != 0)
        {
            fields[item_count] = (S8*) daf_info_p->genre;
            g_mmi_audply_detail_fields[item_count] = STR_ID_AUDPLY_DETAIL_GENRE;
            item_icons[item_count++] = IMG_ID_AUDPLY_DETAIL_GENRE;
        }

        if (daf_info_p->year[0] != 0)
        {
            fields[item_count] = (S8*) daf_info_p->year;
            g_mmi_audply_detail_fields[item_count] = STR_ID_AUDPLY_DETAIL_YEAR;
            item_icons[item_count++] = IMG_ID_AUDPLY_DETAIL_YEAR;
        }

        RegisterHighlightHandler(mmi_audply_detail_highlight_hdlr);

        ShowCategory84Screen(
            STR_ID_AUDPLY_OPTION_DETAIL,
            GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),    /* title text and icon */
            0,
            0,                                  /* LSK text and icon */
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,                    /* RSK text and icon */
            item_count,
            (U8 **) fields,
            item_icons,
            0,
            0,
            guiBuffer);

        /* SetLeftSoftkeyFunction( GoBackHistory, KEY_EVENT_UP ); */
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

        /* register volume inc, dec handlers */



#ifdef __MMI_NO_VOL_KEYS__	
	// 没有音量键的处理//sc.wu __MMI_NO_VOL_KEYS__
	#if defined(__VOL_WITH_28KEY__)
	    //Huyanwei Modify it .Have Side Key 
	    SetKeyHandler(mmi_audply_press_inc_volume, KEY_2, KEY_EVENT_DOWN);
	    SetKeyHandler(mmi_audply_press_dec_volume, KEY_8, KEY_EVENT_DOWN);
	#else
	    SetKeyHandler(mmi_audply_press_inc_volume, KEY_2, KEY_EVENT_DOWN);
	    SetKeyHandler(mmi_audply_press_dec_volume, KEY_5, KEY_EVENT_DOWN);
	#endif		
#else
	    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
	    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_detail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_detail()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (daf_info_p != NULL)
    {
        free_ctrl_buffer(daf_info_p);
        daf_info_p = NULL;
    }
    currHistory.scrnID = SCR_ID_AUDPLY_DETAIL;
    currHistory.entryFuncPtr = mmi_audply_entry_detail;
    mmi_ucs2cpy((PS8)currHistory.inputBuffer, (const PS8)L"");
    GetCategoryHistory(currHistory.guiBuffer);
    AddHistory(currHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_detail_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_detail_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeTitleString((PU8) GetString(g_mmi_audply_detail_fields[index]));
    draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_remove_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_remove_confirm()
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
        get_string(STR_ID_AUDPLY_OPTION_REMOVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_audply_remove_confirm_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_remove_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_remove_confirm()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_ID_AUDPLY_REMOVE_CONFIRM;
    currHistory.entryFuncPtr = mmi_audply_entry_remove_confirm;
    mmi_ucs2cpy((PS8)currHistory.inputBuffer, (const PS8)L"");
    AddHistory(currHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_remove_confirm_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_remove_confirm_LSK()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL need_reApply = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.pick_index == g_mmi_audply_list_highlighted_item)
    {
        mmi_audply_stop_playing();
        need_reApply = TRUE;
    }

    if (mmi_audply_playlist_remove_one(g_mmi_audply_list_highlighted_item))
    {
        if (need_reApply)
        {
            mmi_audply_apply_picked_file();
            mmi_audply_clear_play_seconds();
        }
        GoBackHistory();
    }
    else
    {
        GoBackHistory();
        DisplayPopup(
            (PU8) GetString(STR_ID_AUDPLY_CANNOT_UPDATE_LIST_FS_FAIL),
            IMG_GLOBAL_ERROR,
            0,
            1000,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_remove_all_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_remove_all_confirm()
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
        get_string(STR_ID_AUDPLY_OPTION_REMOVE_ALL_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_audply_remove_all_confirm_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_remove_all_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_remove_all_confirm()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_ID_AUDPLY_REMOVE_ALL_CONFIRM;
    currHistory.entryFuncPtr = mmi_audply_entry_remove_all_confirm;
    mmi_ucs2cpy((PS8)currHistory.inputBuffer, (const PS8)L"");
    AddHistory(currHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_remove_all_confirm_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_remove_all_confirm_LSK()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_stop_playing();
    if (mmi_audply_playlist_remove_all())
    {
        GoBackHistory();
    }
    else
    {
        GoBackHistory();
        DisplayPopup(
            (PU8) GetString(STR_ID_AUDPLY_CANNOT_UPDATE_LIST_FS_FAIL),
            IMG_GLOBAL_ERROR,
            0,
            1000,
            (U8) ERROR_TONE);
    }
}

#ifdef __MMI_AUDIO_TIME_STRETCH__


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_speed_get_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  speed       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_audply_speed_get_index(U16 speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     *   Slow2 | Slow1 | Normal | Fast1 | Fast2
     *     3           4            0           1          2
     */
    switch (speed)
    {
        case MDI_AUDIO_SPEED_SLOW1:
            index = 4;
            break;
        case MDI_AUDIO_SPEED_SLOW2:
            index = 3;
            break;
        case MDI_AUDIO_SPEED_FAST1:
            index = 1;
            break;
        case MDI_AUDIO_SPEED_FAST2:
            index = 2;
            break;
        case MDI_AUDIO_SPEED_NORMAL:
        default:
            break;
    }

    return index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_speed_get_speed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_audply_speed_get_speed(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 speed = MDI_AUDIO_SPEED_NORMAL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     *   Slow2 | Slow1 | Normal | Fast1 | Fast2
     *     3           4            0           1          2
     */
    switch (index)
    {
        case 1:
            speed = MDI_AUDIO_SPEED_FAST1;
            break;
        case 2:
            speed = MDI_AUDIO_SPEED_FAST2;
            break;
        case 3:
            speed = MDI_AUDIO_SPEED_SLOW2;
            break;
        case 4:
            speed = MDI_AUDIO_SPEED_SLOW1;
            break;
        case 0:
        default:
            break;
    }

    return speed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_apply_change_in_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_audply_apply_change_in_setting(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 new_speed;
    mdi_result set_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_speed = mmi_audply_speed_get_speed(index);

    if (g_audply.speed != new_speed)
    {
        if (g_audply.state == STATE_PLAY || g_audply.state == STATE_PAUSED)
        {
            /* Check format when change speed from normal speed */
            if ((g_audply.speed == MDI_AUDIO_SPEED_NORMAL) && (new_speed != MDI_AUDIO_SPEED_NORMAL))
            {
                if (mmi_audply_speed_check_before_play(new_speed) != MDI_AUDIO_SUCCESS)
                {
                    return FALSE;
                }
            }

            /* Set speed while playing */
            if (g_audply.state == STATE_PLAY)
            {
                set_result = mdi_audio_stretch_set_speed(new_speed);

                /* Set fail during playing, don't apply value */
                if (set_result != MDI_AUDIO_SUCCESS)
                {
                    return FALSE;
                }

                /* Only increase once if turn on in setting menu while playing */
                if (g_audply.speed_set_times == 0)
                {
                    g_audply.speed_set_times++;
                }
            }
        }

        g_audply.speed = new_speed;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_speed_set_speed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_speed_set_speed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result set_result;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_result = mdi_audio_stretch_set_speed(g_audply.speed);

    /* Restore speed to normal when set fail */
    if (set_result != MDI_AUDIO_SUCCESS)
    {
        g_audply.speed = MDI_AUDIO_SPEED_NORMAL;
        WriteValue(NVRAM_AUDIO_SPEED_VALUE, &g_audply.speed, DS_SHORT, &error);
    }

    g_audply.speed_set_times++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_speed_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_speed_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.speed_set_times == 1)
    {
        mdi_audio_stretch_close();
    }

    if (g_audply.speed_set_times > 0)
    {
        g_audply.speed_set_times--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_speed_check_before_play
 * DESCRIPTION
 *  (Note) This function shold only be called before request to play a file.
 * PARAMETERS
 *  speed       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_audply_speed_check_before_play(U16 speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = MDI_AUDIO_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check speed only when speed is not normal */
    if (speed != MDI_AUDIO_SPEED_NORMAL)
    {
        result = mdi_audio_stretch_check_file_format((void*)g_audply.filefullname);
    }

    /*in case DRM file can not open, only check for speed*/
    if(result != MDI_AUDIO_UNSUPPORTED_SPEED)
    {
        result = MDI_AUDIO_SUCCESS;
    }

    return (S32) result;
}

#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 

#ifdef __MMI_AVRCP_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_bt_avrcp_cmd_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  command         [IN]        
 *  key_press       [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_audply_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events key_events)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = MMI_AVRCP_CR_ACCEPT;
    UI_string_type list_name ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    PRINT_INFORMATION("AudPly:Entry audply_avrcp_cmd_hdlr\n");

    /* Use popup to indicate received messages */
#ifdef __MMI_AVRCP_DEBUG__
    U8 display_buffer[80];

    mmi_ucs2cpy((PS8)display_buffer, (const PS8)GetString(mmi_bt_avrcp_util_get_cmd_string(command)));
    switch (key_events)
    {
        case MMI_AVRCP_KEY_UP :
            mmi_ucs2cat((PS8)display_buffer, (const PS8)L"\n KEY UP\0");    
            break;
        case MMI_AVRCP_KEY_DOWN:
            mmi_ucs2cat((PS8)display_buffer, (const PS8)L"\n KEY DOWN\0");
            break;
        case MMI_AVRCP_KEY_CANCELED:
            mmi_ucs2cat((PS8)display_buffer, (const PS8)L"\n KEY CANCELED\0");    
            break;
        default:
            break;
    }
   
    if((command == MMI_AVRCP_POP_PLAY ||
       command == MMI_AVRCP_POP_STOP ||
       command == MMI_AVRCP_POP_PAUSE ||
       command == MMI_AVRCP_POP_FORWARD ||
       command == MMI_AVRCP_POP_BACKWARD) &&
       g_audply.in_main_screen)
    {
    	/* Do nothing */
    }
    else
    {
		DisplayPopup(display_buffer, IMG_GLOBAL_OK, 0, 1000, (U8) SUCCESS_TONE);    	
        goto avrcp_finish;
    }
#endif /* __MMI_AVRCP_DEBUG__ */
    
    if (g_idle_context.IsOnIdleScreen)
    {
    #ifdef __USB_IN_NORMAL_MODE__
        /* check is in mass storage mode */
        if (mmi_usb_is_in_mass_storage_mode())
        {
            /* phone drive is exported, cant use this app, popup message in key up */
            if(key_events == MMI_AVRCP_KEY_UP)
            {
                mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            }
            result = MMI_AVRCP_CR_REJECT;
            goto avrcp_finish;
        }
    #endif /* __USB_IN_NORMAL_MODE__ */ 

    #ifdef __MMI_FM_RADIO__
        mmi_fmrdo_power_on(FALSE);
    #endif 

        /* initialization after re-power on */
        if (!g_mmi_audply_init_done)
        {
            //mmi_audply_get_fs_info();

            /* register mdi background handler */
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_AUDPLY, mmi_audply_background_callback_hdlr);
            g_audply.need_restore = FALSE;
            g_audply.wait_next = FALSE;
            g_audply.need_replay = FALSE;
            g_audply.continue_playing = FALSE;
            g_audply.in_list_screen = FALSE;
            g_audply.state = STATE_IDLE;
            g_mmi_audply_play_completed_after_button_down = FALSE;

            g_audply.present_list = mmi_audply_get_preferred_or_available_list();
        }

        /*config present play list path*/
        list_name = mmi_audply_get_present_list_file();

        if (!g_mmi_audply_init_done || !mmi_audply_does_file_exist(list_name))
        {
            mmi_audply_regen_and_reload_playlist((BOOL) g_audply.list_auto_gen, TRUE);
        }

        if (!g_mmi_audply_init_done)
        {
            g_audply_main_selected_button_down = FALSE;
            if (g_audply.n_total_items == 0)
            {
                g_audply_main_selected_button = (signed char)AUDPLY_MAIN_DISABLED;
            }
            else
            {
                g_audply_main_selected_button = (signed char)AUDPLY_MAIN_STOP;
            }
        }
        g_mmi_audply_init_done = TRUE;

		if(!g_audply.background_play)
		{
		    result = MMI_AVRCP_CR_REJECT;
		    goto avrcp_finish;
		}
    }
    else if (!g_audply.in_main_screen && !(g_mmi_audply_init_done &&
                                           (g_audply.state == STATE_PLAY || g_audply.state == STATE_PAUSED)))
    {
        result = MMI_AVRCP_CR_REJECT;
        goto avrcp_finish;
    }

    if (key_events == MMI_AVRCP_KEY_CANCELED)
    {
        switch (command)
        {
            case MMI_AVRCP_POP_PLAY:
            case MMI_AVRCP_POP_STOP:
            case MMI_AVRCP_POP_PAUSE:
            case MMI_AVRCP_POP_FORWARD:
            case MMI_AVRCP_POP_BACKWARD:
                PRINT_INFORMATION("AudPly: AVRCP canceled\n");
                mmi_audply_press_button_canceled();
                break;
            default :
                break;
        }
        /*the return value do not mean anything in key canceled event*/
        result = MMI_AVRCP_CR_REJECT;
        goto avrcp_finish;
    }


    switch (command)
    {
        case MMI_AVRCP_POP_PLAY:
            if(g_audply.state != STATE_PLAY)
            {
                if (key_events == MMI_AVRCP_KEY_UP)
                {
                    mmi_audply_press_play_button_up();
                }
                else if(key_events == MMI_AVRCP_KEY_DOWN)
                {
                    mmi_audply_press_play_button_down();
                }
            }
            break;

        case MMI_AVRCP_POP_STOP:
            if (key_events == MMI_AVRCP_KEY_UP)
            {
                mmi_audply_press_stop_button_up();
            }
            else if(key_events == MMI_AVRCP_KEY_DOWN)
            {
                mmi_audply_press_stop_button_down();
            }
            break;

        case MMI_AVRCP_POP_PAUSE:
            if(g_audply.state == STATE_PLAY)
            {
                if (key_events == MMI_AVRCP_KEY_UP)
                {
                    mmi_audply_press_play_button_up();
                }
                else if(key_events == MMI_AVRCP_KEY_DOWN)
                {
                    mmi_audply_press_play_button_down();
                }
            }
            break;

        case MMI_AVRCP_POP_FORWARD:
            if (key_events == MMI_AVRCP_KEY_UP)
            {
                mmi_audply_press_next_button_up();
            }
            else if (key_events == MMI_AVRCP_KEY_DOWN)
            {
                mmi_audply_press_next_button_down();
            }            
            else if(key_events == MMI_AVRCP_KEY_LONGPRESS)
            {
                if(GetActiveScreenId() == SCR_ID_AUDPLY_MAIN )
                {
                    PRINT_INFORMATION("AudPly: AVRCP forward long press\n");
                    mmi_audply_press_next_button_longpress();
                }
                
            }
            else if(key_events == MMI_AVRCP_KEY_REPEAT)
            {
                PRINT_INFORMATION("AudPly: AVRCP forward repeat\n");
            }
            break;

        case MMI_AVRCP_POP_BACKWARD:
            if (key_events == MMI_AVRCP_KEY_UP)
            {
                mmi_audply_press_prev_button_up();
            }
            else if(key_events == MMI_AVRCP_KEY_DOWN)
            {
                mmi_audply_press_prev_button_down();
            }
            else if(key_events == MMI_AVRCP_KEY_LONGPRESS)
            {
                if(GetActiveScreenId() == SCR_ID_AUDPLY_MAIN )
                {
                    PRINT_INFORMATION("AudPly: AVRCP backward long press\n");
                    mmi_audply_press_prev_button_longpress();
                }
                
            }
            else if(key_events == MMI_AVRCP_KEY_REPEAT)
            {
                PRINT_INFORMATION("AudPly: AVRCP backward repeat\n");
            }
            break;

        default:
            result = MMI_AVRCP_CR_NOT_IMPLEMENT;
            break;
    }

avrcp_finish:

#ifdef __MMI_AVRCP_DEBUG__
	return MMI_AVRCP_CR_ACCEPT;
#else
	return result;
#endif
    
}

#endif /* __MMI_AVRCP_SUPPORT__ */ 

#ifdef __DRM_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_drm_consume_right
 * DESCRIPTION
 *  This function is to validate if DRM right still exists
 * PARAMETERS
 *  U16 filename    [IN]    file to be checked
 * RETURNS
 *  S8  0: not drm file, 1: drm with rights, 2: drm without rights
 *****************************************************************************/
S8 mmi_audply_drm_valide_right(U16* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    S8 result = 0 ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if((handle = DRM_open_file((U16*)filename, FS_READ_ONLY, DRM_PERMISSION_PLAY)) >= FS_NO_ERROR)
    {
        if (DRM_get_object_method(handle, NULL) == DRM_METHOD_NONE)
        {
            result = 0;
        }
        else if(DRM_validate_permission(handle, NULL, DRM_PERMISSION_PLAY))
        {   
            result = 1;
        }
        else
        {
            result = 2;
        }
        DRM_close_file(handle);
    }
    else if (handle == DRM_RESULT_NO_PERMISSION)
    {
        result = 2;
    }
    else   /* file open error, but not DRM related problem */
    {
        result = 2;
    }
    
    PRINT_INFORMATION("mmi_audply_drm_valide_right, result=%d\n", result);
    
    return result;
}

#endif /*__DRM_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_reload_play_list
 * DESCRIPTION
 *  reload play list from play list data file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_reload_play_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (need_reload_list)
    {
        need_reload_list = FALSE;
    }

    mmi_audply_init_playlist(); /* reload list */

    /* pick one and get its information then show them in main screen */
    if (mmi_audply_pick_playlist_next() >= 0)
    {
        mmi_audply_apply_picked_file();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_refresh_list
 * DESCRIPTION
 *  be call when the refresh popup catagory exit.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_refresh_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(AUDPLY_PROCESS_ADD_FILE_TIMER);
    
    kal_prompt_trace(MOD_MMI_MEDIA_APP,"[Audply]exit refresh list");    

    if (list_data_file_handle >= 0)
    {
        FS_Close(list_data_file_handle);
        list_data_file_handle = -1;
    }
    if (add_file_cursor >= 0)
    {
        /* re-initialize pick index if necessary */
        if (g_audply.pick_index < 0)
        {
            if (mmi_audply_pick_playlist() >= 0)
            {
                mmi_audply_apply_picked_file();
            }
        }
        
        FS_FindClose(add_file_cursor);
        add_file_cursor = -1;
    }
    /* this is to solve when user never enters audply, but tries to play by AVRCP first command will 
       trigger regenerate playlist when auto gen on, but the button flag will not have chance to update,
       so any button press/release command will be blocked.*/     
    mmi_audply_update_main_button_flag();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_refresh_play_list_end
 * DESCRIPTION
 *  be call when the refresh popup catagory exit.
 * PARAMETERS
 *  U8      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_refresh_play_list_end(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_data_file_handle >= 0)
    {
        FS_Close(list_data_file_handle);
        list_data_file_handle = -1;
    }
    if (add_file_cursor >= 0)
    {
        FS_FindClose(add_file_cursor);
        add_file_cursor = -1;    
        if (g_audply.n_total_items > 0)
        {
            /* re-initialize pick index if necessary */
            if (g_audply.pick_index < 0)
            {
                if (mmi_audply_pick_playlist() >= 0)
                {
                    mmi_audply_apply_picked_file();
                }
            }
            switch (result)
            {
                case 0:
                    DisplayPopup((PU8)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, (U8)SUCCESS_TONE);
                    break;
                case 1: /* list full */
                    DisplayPopup((PU8)GetString(STR_ID_AUDPLY_LIST_FULL), IMG_GLOBAL_WARNING, 0, 1000, (U8) WARNING_TONE);
                    break; 
                case 2: /* disk full*/
                    DisplayPopup((PU8)GetString(STR_ID_AUDPLY_CANNOT_UPDATE_LIST_DISK_FULL), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
                    break;
            #ifdef __DRM_V02__                    
                case 9:
                    DisplayPopup((PU8)GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_WARNING, 0, 1000, WARNING_TONE);
                    break;
            #endif
                default:
                    break;
            }
        }
        else
        {
            DisplayPopup(
                (PU8)GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                0,
                1000,
                (U8) EMPTY_LIST_TONE); 
        }
    }
    /* this is to solve when user never enters audply, but tries to play by AVRCP first command will 
       trigger regenerate playlist when auto gen on, but the button flag will not have chance to update,
       so any button press/release command will be blocked.*/ 
    mmi_audply_update_main_button_flag();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_refresh_play_list
 * DESCRIPTION
 *  when regen timer timeout, add 10 files to play list data file, 
 *  then set another timer to keep a loop until all files in folder named 
 *  "My Music" have been appended to play list data file.  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_refresh_play_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  result = 0;
    S32 i = 0, j = 0;
    S32 size;
    S32 write_result;
    BOOL is_shortname;
    
    UI_string_type dir_root;
    FS_DOSDirEntry file_info;
    
    UI_character_type search_path[FMGR_MAX_FILE_LEN];
    UI_character_type add_path[FMGR_MAX_PATH_LEN + 1];  /* save the folder path at first time */
    UI_character_type ext[FMGR_MAX_EXT_LEN + 1];
#ifdef __DRM_V02__
    drm_file_info_struct drm_file_info;
    PU8 ext_name_p = NULL; 
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dir_root = mmi_audply_get_present_list_root();
    if (add_file_cursor < 0)    /* first time */
    {
        /*config present_dir_root*/
        mmi_ucs2cpy((PS8)add_path, (const PS8)dir_root);
        mmi_ucs2cat((PS8)add_path, (const PS8)MUSIC_FOLDER);
        mmi_ucs2cat((PS8)add_path, (const PS8)L"*.*");

        /* to skip the "." and "..", repeat 3 times */
        add_file_cursor = FS_FindFirst(
                            add_path, 
                            0, 
                            0, 
                            &file_info, 
                            search_path, 
                            (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH);

#ifdef __MTK_TARGET__        
        FS_FindNext(add_file_cursor, &file_info, search_path, (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH);

        /* if return FS_NO_MORE_FILES, it means there is really no file in it.*/
        if (FS_FindNext(add_file_cursor, &file_info, search_path, 
                (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH) == FS_NO_MORE_FILES)
        {
            DisplayPopup(
                (PU8)GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                0,
                1000,
                (U8) EMPTY_LIST_TONE);  
            return;
        }
#else	/* __MTK_TARGET__ */
	if (add_file_cursor == FS_NO_MORE_FILES)
	{
            DisplayPopup(
                (PU8)GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                0,
                1000,
                (U8) EMPTY_LIST_TONE);  
            return;
	}
#endif /* __MTK_TARGET__ */
        
    }
    else if (FS_FindNext(add_file_cursor, &file_info, search_path, 
                (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH) != FS_NO_ERROR)  /* next time */
    {
        /* end refresh */
        if(g_audply.n_total_items == 0)
        {
            DisplayPopup(
                (PU8)GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                0,
                1000,
                (U8) EMPTY_LIST_TONE); 
        }
        else
        {
            DisplayPopup(
                (PU8)GetString(STR_GLOBAL_DONE), 
                IMG_GLOBAL_ACTIVATED, 
                1, 
                1000, 
                (U8)SUCCESS_TONE);
        }
        return;
    }

    /* add file path to list data file */
    do
    {
        if ((file_info.Attributes & (FS_ATTR_DIR | FS_ATTR_VOLUME | FS_ATTR_HIDDEN | FS_ATTR_SYSTEM)) == 0)
        {
            is_shortname = ((file_info.NTReserved & FS_SFN_MATCH) != 0);
            if (is_shortname)
            {
                for (j = 0; j < 3; j++)
                {
                    ext[j] = (UI_character_type)file_info.Extension[j];
                }
                ext[j] = 0;
            }
            else
            {
                mmi_audply_extract_ext(search_path, ext);
            }
            
        #ifdef __DRM_V02__
            if (!mmi_ucs2nicmp((const PS8)ext, (const PS8)L"odf", (U32)mmi_ucs2strlen((const PS8)ext)))
            {
                mmi_ucs2cpy((PS8)add_path, (const PS8)dir_root);
                mmi_ucs2cat((PS8)add_path, (const PS8)MUSIC_FOLDER);
                mmi_ucs2cat((PS8)add_path, (const PS8)search_path);
                
                if (!DRM_is_archive(0, (PU16)add_path))
                {
                    ext_name_p = (PU8)DRM_get_content_ext(0, (PU16)add_path);
                    if (ext_name_p != NULL)
                    {
                        mmi_asc_n_to_ucs2((PS8)ext, (PS8)ext_name_p, strlen((const char *)ext_name_p));
                    }
                    else
                    {
                        ext[0] = 0;
                    }
                }
                else
                {
                    FS_HANDLE multi_part_handle;
                    UI_character_type content_name[FMGR_MAX_FILE_LEN + 1];
                    UI_character_type temp_buffer[FMGR_MAX_PATH_LEN + 1];

                    find_cntx = DRM_get_find_cntx();
                    multi_part_handle = DRM_find_firstN(
                                                find_cntx,
                                                add_path, 
                                                0, 
                                                0,
                                                &drm_file_info,
                                                content_name,
                                                (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH,
                                                0);
                    if (multi_part_handle < FS_NO_ERROR)
                    {
                        /* because this memory will be free in DRM_find_firstN when DRM_find_firstN fail. */
                        find_cntx = NULL;
                        /* need pop up or do something for this error. */
                        DisplayPopup(
                        	(PU8)GetString(GetFileSystemErrorString(multi_part_handle)),
                        	IMG_GLOBAL_ERROR,
                        	0,
                        	1000,
                        	(U8)ERROR_TONE);
                        mmi_audply_refresh_play_list_end(9);    /* any numeral larger than 3. */
                        return;
                    }
                    else
                    {
                        do
                        {
                            mmi_audply_extract_ext(content_name, ext);
                            if (mmi_audply_lookup_audio_file_format(ext) >= 0)
                            {
                                if (mmi_ucs2strlen((const PS8)add_path) + mmi_ucs2strlen((const PS8)content_name) <= FMGR_MAX_PATH_LEN)
                                {
                                    mmi_ucs2cpy((PS8)temp_buffer, (const PS8)add_path);
                                    mmi_ucs2cat((PS8)temp_buffer, (const PS8)L"\\");
                                    mmi_ucs2cat((PS8)temp_buffer, (PS8)content_name);
                                    MARK_LNAME(temp_buffer);
                                    if (g_audply.n_total_items >= MAX_PLAY_LIST_NUM)
                                    {
                                        DRM_find_close(find_cntx, multi_part_handle);
                                        find_cntx = NULL;
                                        mmi_audply_refresh_play_list_end(1);
                                        return;
                                    }
                                    else if ((write_result = FS_Write(list_data_file_handle, temp_buffer, PLAY_LIST_RECORD_SIZE, (U32*)&size)) != FS_NO_ERROR)
                                    {
                                        if (write_result == FS_DISK_FULL)
                                        {
                                            DRM_find_close(find_cntx, multi_part_handle);
                                            find_cntx = NULL;
                                            mmi_audply_refresh_play_list_end(2);
                                            return;
                                        }
                                    }
                                    else
                                    {
                                        g_audply.n_total_items++;
                                        result = 0;
                                    }
                                }
                            }
                        } while (FS_NO_ERROR == DRM_find_nextN(
                                                find_cntx,
                                                multi_part_handle, 
                                                &drm_file_info,
                                                content_name,
                                                (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH,
                                                1));
                    }

                    if (find_cntx)
                    {
                        DRM_find_close(find_cntx, multi_part_handle);
                        find_cntx = NULL;
                    }
                    StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 100, mmi_audply_refresh_play_list);
                    return;
                }
            }
            
        #endif  /* __DRM_V02__ */
            if (mmi_audply_lookup_audio_file_format(ext) >= 0)
            {
                mmi_ucs2cpy((PS8)add_path, (const PS8)dir_root);
                mmi_ucs2cat((PS8)add_path, (const PS8)MUSIC_FOLDER);
                mmi_ucs2cat((PS8)add_path, (const PS8)search_path);
                
                if (is_shortname)
                {
                    MARK_SNAME(add_path);
                }
                else
                {
                    MARK_LNAME(add_path);
                }
                
                if (g_audply.n_total_items >= MAX_PLAY_LIST_NUM)
                {
                    result = 1;
                    mmi_audply_refresh_play_list_end(result);
                    return;
                }
                else if ((write_result = FS_Write(list_data_file_handle, add_path, PLAY_LIST_RECORD_SIZE, (U32*)&size)) != FS_NO_ERROR)
                {
                    if (write_result == FS_DISK_FULL)
                    {
                        result = 2;
                        mmi_audply_refresh_play_list_end(result);
                        return;
                    }
                }
                else
                {
                    g_audply.n_total_items++;
                    result = 0;
                }
            }
        }
        /* for change feature "add from multi-level folder" later
        else if (file_info.Attributes & FS_ATTR_DIR)
        {
        
        }*/
        if ((++i) == 10)
        {
            StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 100, mmi_audply_refresh_play_list);
            return;
        }
    } while (FS_FindNext(add_file_cursor, &file_info, search_path, (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH) == FS_NO_ERROR);
    
    mmi_audply_refresh_play_list_end(result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_regenerate_play_list
 * DESCRIPTION
 *  add files which got from folder named "My Music" to play list data file 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_regenerate_play_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd, folder_handle;
    UI_string_type list_name;
    UI_string_type dir_root;
    UI_character_type filexpr_temp[FMGR_MAX_PATH_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (need_refresh_list)
    {
        need_refresh_list = FALSE;
    }
    add_file_cursor = -1;
    list_data_file_handle = -1;
    /*config present_dir_root*/
    dir_root = mmi_audply_get_present_list_root();
    list_name = mmi_audply_get_present_list_file();
#ifdef __MMI_MY_FAVORITE__
    mmi_ucs2cpy((PS8)filexpr_temp, (const PS8)dir_root);
    mmi_ucs2cat((PS8)filexpr_temp, (const PS8)AUDPLY_AUDIO_FOLDER);
    if (FS_NO_ERROR > (folder_handle = FS_Open(filexpr_temp, FS_OPEN_DIR | FS_READ_ONLY)))
    {
        S32 ret = 0;
        if (FS_NO_ERROR > (ret = FS_CreateDir(filexpr_temp)))
        {
            DisplayPopup(
                (PU8)GetString(GetFileSystemErrorString(ret)),
                IMG_GLOBAL_ERROR,
                0,
                1000,
                ERROR_TONE);
            /*when FAT_ALLOC_ERROR, need to delete the file or any other FS api will fail*/            
            if(ret == FS_FAT_ALLOC_ERROR)
            {
                FS_Delete((const PU16)list_name);
            }
            return;
        }
    }
    else
    {
        FS_Close(folder_handle);
    }
#endif /* __MMI_MY_FAVORITE__ */
    mmi_ucs2cpy((PS8)filexpr_temp, (const PS8)dir_root);
    mmi_ucs2cat((PS8)filexpr_temp, (const PS8)MUSIC_FOLDER);
        
    /* check does the folder exist, create it if it's not there */
    folder_handle = FS_Open(filexpr_temp, FS_OPEN_DIR | FS_READ_ONLY);
        
    if (folder_handle < 0)
    {
        S32 ret = 0;
    	g_audply.n_total_items = 0;
        if (FS_NO_ERROR > (ret = FS_CreateDir(filexpr_temp)))
        {
            DisplayPopup(
                (PU8)GetString(GetFileSystemErrorString(ret)),
                IMG_GLOBAL_ERROR,
                0,
                1000,
                ERROR_TONE);
            /*when FAT_ALLOC_ERROR, need to delete the file or any other FS api will fail*/
            if(ret == FS_FAT_ALLOC_ERROR)
            {
                FS_Delete((const PU16)list_name);
            }
            return;
        }

        if ((fd = FS_Open(list_name, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN)) >= 0)
    	{
        	FS_Close(fd);
    	}
    	DisplayPopup(
                (PU8)GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                0,
                1000,
                (U8) EMPTY_LIST_TONE); 
    }
	else
	{
	    FS_Close(folder_handle);
	
	    /* Clear old play list data file and create new one. */
	    list_name = mmi_audply_get_present_list_file();
	    if ((list_data_file_handle = FS_Open(list_name, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN)) < 0)
	    {
        	DisplayPopup(
                (PU8)GetString(GetFileSystemErrorString((S32)list_data_file_handle)),
                IMG_GLOBAL_ERROR,
                0,
                1000,
                (U8)ERROR_TONE);
                /*when FAT_ALLOC_ERROR, need to delete the file or any other FS api will fail*/
                if(list_data_file_handle == FS_FAT_ALLOC_ERROR)
                {
                    FS_Delete((const PU16)list_name);
                }
	    }
	    else
	    {
	        g_audply.n_total_items = 0;
	        
            kal_prompt_trace(MOD_MMI_MEDIA_APP,"[Audply]regenerate_play_list, entry 66");

	        EntryNewScreen(SCR_ID_AUDPLY_REFRESH_LIST, mmi_audply_exit_refresh_list, NULL, NULL);
	
	        /* clear End key */
	        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
	        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
	
	        /* Show searching screen */
	        ShowCategory66Screen(
	            STR_ID_AUDPLY_OPTION_REGEN_LIST,
	            0,
	            0,
	            0,
	            STR_GLOBAL_CANCEL,
	            0,
	            (U8*)GetString(STR_ID_AUDPLY_PROCESSING),
	            IMG_GLOBAL_PROGRESS,
	            NULL);
	
	        /* Set RSK to abort searching */
	        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	        StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 100, mmi_audply_refresh_play_list);
	    }
	}
}


#endif /* __MMI_AUDIO_PLAYER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_single_inc_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_single_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (single_volume < MDI_AUD_VOL_NUM - 1)
    {
        mdi_audio_set_volume(VOL_TYPE_MEDIA, ++single_volume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_single_dec_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_single_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (single_volume > 0)
    {
        mdi_audio_set_volume(VOL_TYPE_MEDIA, --single_volume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_single_play_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_single_play_timer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 current_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&current_time);
    single_play_duration = current_time - single_play_time;
    StartTimer(AUDPLY_SINGLE_PLAY_TIMER, 500, mmi_audply_single_play_timer);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_play_in_melody_composer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filefullname            [IN]        Void (*exit_callback_func)(void)
 *  exit_callback_func      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_play_in_melody_composer(UI_string_type filefullname, void (*exit_callback_func) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    single_play_exit_callback_func = exit_callback_func;
    result = mmi_audply_do_single_play_action_in_meldoy_composer(filefullname);
    if (result == MDI_AUDIO_SUCCESS)
    {
        mmi_audply_entry_play_animation();
    }
    else
    {
        if (single_play_exit_callback_func != NULL)
        {
            single_play_exit_callback_func();
            single_play_exit_callback_func = NULL;
        }
        mmi_audply_display_popup(result);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_single_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filefullname            [IN]        Void (*exit_callback_func)(void)
 *  exit_callback_func      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_single_play(UI_string_type filefullname, void (*exit_callback_func) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    single_play_exit_callback_func = exit_callback_func;
    result = mmi_audply_do_single_play_action(filefullname);
    if (result == MDI_AUDIO_SUCCESS)
    {
        mmi_audply_entry_play_animation();
    }
    else
    {
        if (single_play_exit_callback_func != NULL)
        {
            single_play_exit_callback_func();
            single_play_exit_callback_func = NULL;
        }
        mmi_audply_display_popup(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_play_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_play_animation()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AUDPLY_PLAY_ANIMATION, mmi_audply_exit_play_animation, NULL, NULL);

    in_single_play_screen = TRUE;
    guiBuffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_PLAY_ANIMATION);

    if (single_play_state == STATE_IDLE)
    {
        ShowCategory223Screen(
            STR_ID_AUDPLY_TITLE,
        #ifdef __MMI_AUDIO_PLAYER__
            GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
        #else
            NULL,
        #endif
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            IMG_ID_AUDPLY_STOP_ANIMATION,
            0,
            single_play_duration,
            guiBuffer);
    }
    else
    {
        ShowCategory223Screen(
            STR_ID_AUDPLY_TITLE,
        #ifdef __MMI_AUDIO_PLAYER__
            GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
        #else
            NULL,
        #endif
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            IMG_ID_AUDPLY_PLAY_ANIMATION,
            1,
            single_play_duration,
            guiBuffer);
    }

    /* register RSK handler */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* register volume inc, dec handlers */

#ifdef __MMI_NO_VOL_KEYS__	
//没有音量键的处理//sc.wu __MMI_NO_VOL_KEYS__
	#if defined(__VOL_WITH_28KEY__)
		//Huyanwei Modify it .Have Side Key 
		 SetKeyHandler(mmi_audply_single_inc_volume, KEY_2, KEY_EVENT_DOWN);
	        SetKeyHandler(mmi_audply_single_dec_volume, KEY_8, KEY_EVENT_DOWN);
	#else
		 SetKeyHandler(mmi_audply_single_inc_volume, KEY_2, KEY_EVENT_DOWN);
	    	 SetKeyHandler(mmi_audply_single_dec_volume, KEY_5, KEY_EVENT_DOWN);
	#endif
#else
	    SetKeyHandler(mmi_audply_single_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
	    SetKeyHandler(mmi_audply_single_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif 

    SetDelScrnIDCallbackHandler(
        SCR_ID_AUDPLY_PLAY_ANIMATION,
        (HistoryDelCBPtr) mmi_audply_delete_play_animation_history_hdlr);

       #if defined(HORSERACE_SUPPORT)
		//Huyanwei Add It 
		SendMessagesMMIToTwo( MSG_ID_HORSERACE_ON );
	#endif	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_play_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_play_animation()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_ID_AUDPLY_PLAY_ANIMATION;
    currHistory.entryFuncPtr = mmi_audply_entry_play_animation;
    mmi_ucs2cpy((PS8)currHistory.inputBuffer, (const PS8)L"");
    AddHistory(currHistory);
    in_single_play_screen = FALSE;
    if (single_play_exit_callback_func!=NULL && !IsScreenPresent(SCR_ID_AUDPLY_PLAY_ANIMATION) )
    {
        single_play_exit_callback_func();
        single_play_exit_callback_func = NULL;
    }
	#if defined(HORSERACE_SUPPORT)
		//Huyanwei Add It 
		SendMessagesMMIToTwo( MSG_ID_HORSERACE_OFF );
	#endif	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_delete_play_animation_history_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param_p     [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_audply_delete_play_animation_history_hdlr(void *param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (single_play_state != STATE_IDLE)
    {
        mmi_audply_do_single_stop_action();
    }

    return FALSE;
}

#if defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) && defined(__MMI_AUDIO_PLAYER__) 
/*****************************************************************************
 * FUNCTION
 *  HighlightSubAudioPlayer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightSubAudioPlayer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler((FuncPtr)mmi_sub_audply_entry_main_key_handler, KEY_BACK, KEY_EVENT_DOWN);	
    SetKeyHandler((FuncPtr)mmi_sub_audply_entry_main_key_handler, KEY_PLAY_STOP, KEY_EVENT_DOWN);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_exit_audply_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_sub_audply_exit_audply_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.need_replay = FALSE;
    mmi_audply_stop_playing();
    EntrySubLCDMainMenu();
    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_refresh_list_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL

 *****************************************************************************/
BOOL mmi_sub_audply_refresh_list_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SUB_MAIN_MENU_SCREENID, mmi_sub_audply_refresh_list_popup, 1);
    	return TRUE;		
    }
    return FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_refresh_list_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void

 *****************************************************************************/

void mmi_sub_audply_refresh_list_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DinitSubLCDHistory();
    ShowCategory311Screen(
    (PU8)GetString(STR_ID_AUDPLY_OPTION_REGEN_LIST),
               IMG_ID_AUDPLY_SUB_SKIN_REFRESH_LIST,
                NULL);
    StartTimer(POPUP_SUBLCD, 1000,(FuncPtr)EntrySubLCDMainMenu);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_popup_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL

 *****************************************************************************/

BOOL mmi_sub_audply_popup_error_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SCR_ID_AUDPLY_MAIN_SUBLCD, mmi_sub_audply_popup_error, 1);
    	return TRUE;		
    }
    return FALSE;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_exit_popup_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL

 *****************************************************************************/
void mmi_sub_audply_exit_popup_error()
{
    StopTimer(POPUP_SUBLCD);
    stopRequestedTone(ERROR_TONE);
    GoBackSubLCDHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_popup_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL

 *****************************************************************************/
void mmi_sub_audply_popup_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory311Screen(
    (PU8)GetString(STR_ID_AUDPLY_SUB_ERROR),
                IMG_ID_AUDPLY_SUB_SKIN_ERROR,
                NULL);
    playRequestedTone(ERROR_TONE);
    StartTimer(POPUP_SUBLCD, 1000,(FuncPtr)mmi_sub_audply_exit_popup_error);

    SetKeyHandler(mmi_sub_audply_exit_popup_error,KEY_PLAY_STOP,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sub_audply_exit_popup_error,KEY_FWD,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sub_audply_exit_popup_error,KEY_BACK,KEY_EVENT_DOWN);
    SetSubLCDExitHandler(NULL);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_main_key_handler
 * DESCRIPTION
 *    
 * PARAMETERS
 * RETURNS
 *  BOOL
 *****************************************************************************/

BOOL mmi_sub_audply_entry_main_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SCR_ID_AUDPLY_MAIN_SUBLCD, mmi_sub_audply_entry_main, 1);
    	return TRUE;	
    }
    return FALSE;	
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_option_key_handler
 * DESCRIPTION
 *    
 * PARAMETERS
 * RETURNS
 *  BOOL
 *****************************************************************************/

BOOL mmi_sub_audply_entry_option_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SCR_ID_AUDPLY_OPTION_SUBLCD, mmi_sub_audply_entry_option, 1);
    	return TRUE;	
    }
    return FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_playlist_key_handler
 * DESCRIPTION
 *    
 * PARAMETERS
 * RETURNS
 *  BOOL
 *****************************************************************************/

BOOL mmi_sub_audply_entry_playlist_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SCR_ID_AUDPLY_OPTION_SUBLCD, mmi_sub_audply_entry_playlist, 1);
    	return TRUE;	
    }
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_list_key_handler
 * DESCRIPTION
 *    
 * PARAMETERS
 * RETURNS
 *  BOOL
 *****************************************************************************/

BOOL mmi_sub_audply_entry_list_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SCR_ID_AUDPLY_OPTION_SUBLCD, mmi_sub_audply_entry_playlist, 1);
    	return TRUE;	
    }
    return FALSE;

}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_repeat_setting_key_handler
 * DESCRIPTION
 *    
 * PARAMETERS
 * RETURNS
 *  BOOL
 *****************************************************************************/

BOOL mmi_sub_audply_entry_repeat_setting_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SCR_ID_AUDPLY_OPTION_SUBLCD, mmi_sub_audply_entry_repeat_setting, 1);
    	return TRUE;	
    }
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_exit_main
 * DESCRIPTION
 *   exit sub LCD audio player 
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_exit_main()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        mmi_audio_spectrum_stop_display(&g_aud_ply_spectrum_sub_lcd);
    #endif 
    gui_scrolling_text_stop(&audply_main_scrolling_title);
    UI_set_sub_LCD_graphics_context();  
    #ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_flatten_to_base(audply_skin_layer, audply_osd_layer, 0, 0);
    gdi_layer_free(audply_skin_layer);
    gdi_layer_multi_layer_disable();
    gdi_layer_set_blt_layer(audply_osd_layer, 0, 0, 0);
    #endif 
    if (!g_audply.background_play)
    {
        // There is a case that state = STATE_IDLE and need_replay = TRUE
        // and we need to prevent from replay after this function call by setting need_replay = FALSE
        g_audply.need_replay = FALSE;
        mmi_audply_stop_playing();
    }
    g_audply.in_sub_screen = FALSE;
    g_idle_context.IsSubLcdOnIdleScreen = SUBLCD_NOT_ON_IDLE;
    SubLCDHistory.entryFuncPtr = mmi_sub_audply_entry_main;
    AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_AUDPLY_MAIN_SUBLCD);
    UI_set_main_LCD_graphics_context();
  
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_main
 * DESCRIPTION
 *  entry sub LCD audio player screen
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_entry_main()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type list_name ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __USB_IN_NORMAL_MODE__
    /* check is in mass storage mode */
    if (mmi_usb_is_in_mass_storage_mode())
    {
        ExecSubLCDCurrExitHandler();
        UI_set_sub_LCD_graphics_context();
        ClearAllKeyHandler();
        mmi_sub_audply_popup_error_key_handler();
        UI_set_main_LCD_graphics_context();
        return;
    }
    #endif /* __USB_IN_NORMAL_MODE__ */ 

	ExecSubLCDCurrExitHandler();
    UI_set_sub_LCD_graphics_context();
    ClearAllKeyHandler();
	hide_status_icon_bar(2);
    
    #ifdef __MMI_FM_RADIO__
    mmi_fmrdo_power_on(FALSE);
    #endif 
    
    /* initialization after re-power on */
    if (!g_mmi_audply_init_done)
    {
        //mmi_audply_get_fs_info();
    
        /* register mdi background handler */
        mdi_audio_set_background_handler(MDI_BACKGROUND_APP_AUDPLY, mmi_audply_background_callback_hdlr);
        g_audply.need_restore = FALSE;
        g_audply.wait_next = FALSE;
        g_audply.need_replay = FALSE;
        g_audply.continue_playing = FALSE;
        g_audply.in_list_screen = FALSE;
        g_audply.state = STATE_IDLE;
        g_mmi_audply_play_completed_after_button_down = FALSE;
        g_audply.present_list = mmi_audply_get_preferred_or_available_list();
        if (g_audply.list_auto_gen)
    	{
            need_refresh_list = TRUE;
    	}
    }    
    else if (g_audply.n_total_items == 0)
    {
	g_audply.restorable = FALSE;
        g_audply.seekable = FALSE;
        g_audply.need_to_build_cache = FALSE;
    }

    list_name = mmi_audply_get_present_list_file();

    if (!g_mmi_audply_init_done)
    {
        if (mmi_audply_does_file_exist(list_name))
        {
            mmi_audply_regen_and_reload_playlist(FALSE, TRUE);
        }
        if (g_audply.list_auto_gen)
    	{
            need_refresh_list = TRUE;
    	}
    }
    g_mmi_audply_init_done = TRUE;
    g_audply.in_sub_screen = TRUE;
    g_audply.in_main_screen  = FALSE;
    mmi_sub_audply_update_main();
    SetSubLCDExitHandler(mmi_sub_audply_exit_main);   
    /* MTK Leo end */
    UI_set_main_LCD_graphics_context();
    
    SetDelScrnIDCallbackHandler(SCR_ID_AUDPLY_MAIN_SUBLCD, (HistoryDelCBPtr) mmi_sub_audply_delete_history_hdlr);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_exit_option
 * DESCRIPTION
 *  exit sub LCD audio player option screen
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_exit_option()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_context.IsSubLcdOnIdleScreen = SUBLCD_NOT_ON_IDLE;
    SubLCDHistory.entryFuncPtr = (FuncPtr)mmi_sub_audply_entry_option;
    AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_AUDPLY_OPTION_SUBLCD);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_option_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for sub LCD audio player option menu
 * PARAMETERS
 *  index		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_option_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_sub_audply_option_highlighted_item = (U16) index;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_repeat_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for sub LCD audio player repeat setting menu
 * PARAMETERS
 *  index		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_repeat_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_sub_audply_repeat_highlighted_item = (U16) index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_option
 * DESCRIPTION
 *  sub LCD audio player entry option menu
 * PARAMETERS
 *  null
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_entry_option()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_icons[6];
    S32 n_items = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();    
    UI_set_sub_LCD_graphics_context();    
    ClearAllKeyHandler();
    if(g_audply.n_total_items !=0)
    {
        option_texts[n_items] = STR_ID_AUDPLY_PLAYLIST;
        item_icons[n_items] = IMG_GLOBAL_L1;
		mmi_sub_audply_option_func[n_items] = (FuncPtr) mmi_sub_audply_entry_playlist_key_handler;			
        n_items++;

        option_texts[n_items] = STR_ID_AUDPLY_SETTINGS_REPEAT;
        item_icons[n_items] =  IMG_GLOBAL_L1+n_items;
		mmi_sub_audply_option_func[n_items]  =(FuncPtr) mmi_sub_audply_entry_repeat_setting_key_handler;		 
		n_items++;
    	if(g_audply.random_mode)			 
        {
        	option_texts[n_items] = STR_ID_AUDPLY_SETTINGS_SHUFFLE_ON;
	    }
    	else
        {
		    option_texts[n_items] = STR_ID_AUDPLY_SETTINGS_SHUFFLE_OFF;
        }
        item_icons[n_items] =  IMG_GLOBAL_L1+n_items;
		mmi_sub_audply_option_func[n_items] = mmi_sub_audply_shuffle_setting;		 
		n_items++;		 
				 
        option_texts[n_items] = STR_ID_AUDPLY_SUB_OPTION_EXIT;
        item_icons[n_items] =  IMG_GLOBAL_L1+n_items;
		mmi_sub_audply_option_func[n_items] = mmi_sub_audply_exit_audply_app;
		n_items++;
		
        RegisterHighlightHandler(mmi_sub_audply_option_highlight_hdlr);
         
        ShowCategory314Screen((U8*)get_string(STR_GLOBAL_OPTIONS), 
                                              IMG_GLOBAL_OPTIONS, 
                                              n_items, 
                                              option_texts, 
                                              item_icons, 
                                              NULL, 
                                              (S32) g_mmi_sub_audply_option_highlighted_item, 
                                              NULL);
         SetKeyHandler(mmi_sub_audply_option_lsk,KEY_BACK , KEY_EVENT_DOWN);
         SetKeyHandler(mmi_sub_audply_option_lsk,KEY_PLAY_STOP, KEY_EVENT_DOWN);
         SetKeyHandler(GoBackSubLCDHistory, KEY_FWD, KEY_EVENT_DOWN);
		  
    }
    else
    {
        mmi_sub_audply_refresh_list_key_handler();
    }
    SetSubLCDExitHandler(mmi_sub_audply_exit_option);
    UI_set_main_LCD_graphics_context();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_option_lsk
 * DESCRIPTION
 *  sub LCD audio player option's function
 * PARAMETERS
 *  null
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_option_lsk()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sub_audply_option_func[g_mmi_sub_audply_option_highlighted_item]();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_option_lsk
 * DESCRIPTION
 *  sub LCD audio player option's function
 * PARAMETERS
 *  null
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_shuffle_setting()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      	   
	if(g_audply.random_mode)
	{
		g_audply.random_mode = 0;
		selected_random_mode = 0;

	}
	else
	{
        g_audply.random_mode = 1;
		selected_random_mode =1;
	}
    WriteValue(NVRAM_AUDPLY_SHUFFLE, &g_audply.random_mode, DS_BYTE, &error);
    GoBackSubLCDHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_play_file
 * DESCRIPTION
 *  play file from playlist
 * PARAMETERS
 *  null
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_play_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_audply_start_playlist_at(g_mmi_sub_audply_highlighted_playlist_item);
    mmi_audply_pick_playlist_at(g_mmi_sub_audply_highlighted_playlist_item);
    if (mmi_audply_apply_picked_file())
    {
        mmi_audply_stop_playing();
        if(g_audply.in_sub_list_screen)
        {
            GoBackToSubLCDHistory(SCR_ID_AUDPLY_MAIN_SUBLCD);
        }
        mmi_audply_play();
        //mmi_audply_do_play_action_and_back_to_main_screen();
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_playlist
 * DESCRIPTION
 *  entry sub LCD audio player playlist
 * PARAMETERS
 *  null
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_sub_audply_entry_playlist()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title_id;
    S32 highlighted_item = 0;
    U8  total_drv_num;
    UI_string_type drv_inline_list_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ExecSubLCDCurrExitHandler();    
    UI_set_sub_LCD_graphics_context();   
    ClearAllKeyHandler();
	g_audply.in_sub_list_screen =  TRUE;

    /* title */
    mmi_fmgr_get_full_storage_inline_list(NULL,&total_drv_num, (U32*)(&drv_inline_list_p),NULL);
    if (total_drv_num >1 && drv_inline_list_p != NULL)
    {
        title_id = (g_audply.present_list == (U8)MMI_PUBLIC_DRV) ? STR_ID_AUDPLY_LIST_FROM_PHONE : STR_ID_AUDPLY_LIST_FROM_CARD;
    }
    else
    {
        title_id = STR_ID_AUDPLY_PLAYLIST;
    }

    /* register highligh handler */
    RegisterHighlightHandler(mmi_audply_list_highlight_hdlr);


    if (g_audply.pick_index >= 0)  /* highlighted item */
    {
        highlighted_item = g_audply.pick_index;
    }
    else
    {
        highlighted_item = 0;   /* this should never happen */
    }
    
    /* show category screen */
    if (g_audply.n_total_items == 0)
    {
	    ASSERT(0);
    }
    else
    {
        /* if we delete some items and the previous highlighted item is out of boundary, set it to the last one */
		ShowCategory315Screen((U8 *)get_string(title_id), 
			GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
			g_audply.n_total_items, 
			mmi_audply_list_getitem, 
			NULL, 
			(S32) highlighted_item, 
			MMI_FALSE,
			NULL, 
			NULL);

    }
    /* register LSK, RSK hanlders */

    /* register left right arrow key handler */
   SetKeyHandler(mmi_sub_audply_play_file_in_sub_playlist, KEY_BACK, KEY_EVENT_DOWN);
   SetKeyHandler(mmi_sub_audply_play_file_in_sub_playlist, KEY_PLAY_STOP, KEY_EVENT_DOWN);
   SetKeyHandler(GoBackSubLCDHistory, KEY_FWD, KEY_EVENT_DOWN);
   SetSubLCDExitHandler(mmi_sub_audply_exit_playlist); 
    /* register volume inc, dec handlers */
    UI_set_main_LCD_graphics_context();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_exit_playlist
 * DESCRIPTION
 *  exit sub LCD audio player playlist
 * PARAMETERS
 *  null
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_sub_audply_exit_playlist(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	SubLCDHistoryNode SubLCDHistory;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	g_audply.in_sub_list_screen =  FALSE;

	g_idle_context.IsSubLcdOnIdleScreen = SUBLCD_NOT_ON_IDLE;
	SubLCDHistory.entryFuncPtr = (FuncPtr)mmi_sub_audply_entry_playlist;
	AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_AUDPLY_PLAYLIST_SUBLCD);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_set_repeat
 * DESCRIPTION
 *  sub LCD audio player repeat setting
 * PARAMETERS
 *  null		
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_set_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();    
    UI_set_sub_LCD_graphics_context();  
    ClearAllKeyHandler();
    g_audply.repeat_mode = g_mmi_sub_audply_repeat_highlighted_item;
    WriteValue(NVRAM_AUDPLY_REPEAT, &g_audply.repeat_mode, DS_BYTE, &error);
    GoBackSubLCDHistory();
    UI_set_main_LCD_graphics_context();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_entry_repeat_setting
 * DESCRIPTION
 *  entry sub LCD audio player repeat setting
 * PARAMETERS
 *  null		
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_entry_repeat_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_icons[3] ;
    U16 item_texts[3];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ExecSubLCDCurrExitHandler();    
    UI_set_sub_LCD_graphics_context();
    ClearAllKeyHandler();
    //g_mmi_audply_settings_repeat[0] = STR_ID_AUDPLY_SUB_OPTION_REPEAT_OFF;
    //g_mmi_audply_settings_repeat[1] = STR_ID_AUDPLY_SUB_OPTION_REPEAT_ONCE;
    //g_mmi_audply_settings_repeat[2] = STR_ID_AUDPLY_SUB_OPTION_REPEAT_ALL;
    item_texts[0] = STR_ID_AUDPLY_SUB_OPTION_REPEAT_OFF;
    item_texts[1] = STR_ID_AUDPLY_SUB_OPTION_REPEAT_ONCE;
    item_texts[2] = STR_ID_AUDPLY_SUB_OPTION_REPEAT_ALL;
    item_icons[0] = (g_audply.repeat_mode == REPEAT_OFF) ? IMG_ID_AUDPLY_SUB_SKIN_REPEAT_SELECTED:IMG_ID_AUDPLY_SUB_SKIN_REPEAT_NOT_SELECTED;
    item_icons[1] = (g_audply.repeat_mode == REPEAT_ONE) ? IMG_ID_AUDPLY_SUB_SKIN_REPEAT_SELECTED:IMG_ID_AUDPLY_SUB_SKIN_REPEAT_NOT_SELECTED;
    item_icons[2] = (g_audply.repeat_mode == REPEAT_ALL) ? IMG_ID_AUDPLY_SUB_SKIN_REPEAT_SELECTED:IMG_ID_AUDPLY_SUB_SKIN_REPEAT_NOT_SELECTED;
    g_mmi_sub_audply_repeat_highlighted_item = (U16)g_audply.repeat_mode;
	RegisterHighlightHandler(mmi_sub_audply_repeat_highlight_hdlr);
	ShowCategory314Screen((PU8)get_string(STR_ID_AUDPLY_SETTINGS_REPEAT),
							IMG_ID_AUDPLY_SETTINGS_REPEAT, 
							3,
							item_texts, 
							item_icons, 
							NULL, 
							(S32)g_mmi_sub_audply_repeat_highlighted_item, 
							NULL);
	
	SetKeyHandler(mmi_sub_audply_set_repeat, KEY_BACK,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sub_audply_set_repeat,KEY_PLAY_STOP,KEY_EVENT_DOWN);
	SetKeyHandler(GoBackSubLCDHistory,KEY_FWD,KEY_EVENT_DOWN);
    UI_set_main_LCD_graphics_context();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_delete_history_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_param        [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_sub_audply_delete_history_hdlr(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_audply.background_play)
    {
        g_audply.need_replay = FALSE;
        mmi_audply_stop_playing();
    }
    g_audply.in_sub_screen = FALSE;
    if (need_refresh_list && g_audply.state != STATE_IDLE)
    {	
   	need_refresh_list = FALSE;
    }
    return FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_press_prev_button_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_press_prev_button_down()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        return;
    }

    /* change selected button & update state */
    g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PREV;
    g_audply_main_selected_button_down = TRUE;

    /* update button display */
    UI_set_sub_LCD_graphics_context();
    mmi_sub_audply_redraw_main_push_buttons(g_audply_main_selected_button,g_audply_main_selected_button_down);
    UI_set_main_LCD_graphics_context();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_press_prev_button_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_press_prev_button_up()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button_down && (g_audply_main_selected_button == AUDPLY_MAIN_PREV))
    {
        /* update selected button state */
        g_audply_main_selected_button_down = FALSE;
       #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        gui_cancel_timer(mmi_audply_scroll_lyric_handler);
      #endif 
        StopTimer(AUDPLY_COUNT_PLAY_TIMER);
        /* pick the prev song */
        mmi_audply_pick_playlist_prev();
        if (mmi_audply_apply_picked_file())
        {
            if (g_audply.state == STATE_PLAY || g_audply.state == STATE_PAUSED ||
                g_mmi_audply_play_completed_after_button_down || g_audply.need_replay)
            {
                StopTimer(AUDPLY_DELAY_PLAY_TIMER); /* stop previous play request */
                if(g_audply.state != STATE_PAUSED)
                {
                    
                 
                    StartTimer(AUDPLY_DELAY_PLAY_TIMER, 700, mmi_audply_play);    /* wait for 0.7 second to request play */
                    g_audply.wait_next = TRUE;
                    g_audply.need_restore = FALSE;
                    g_audply.continue_playing = FALSE;
                    
                }
                else
                {
                    mmi_audply_do_stop_action();
                    
                    g_audply_main_selected_button = AUDPLY_MAIN_PREV;//add this to slove a bug,zhongwu
                }
            }

            mmi_audply_clear_play_seconds();
            
            /* update main title, file_index, time */

                UI_set_sub_LCD_graphics_context();
                mmi_audply_redraw_main_file_index();
                mmi_audply_redraw_main_title();
                mmi_audply_redraw_main_time();
	         	UI_set_main_LCD_graphics_context();
        }

        g_mmi_audply_play_completed_after_button_down = FALSE;

        /* update main buttons */
        if(g_audply.in_sub_screen)
        {
             UI_set_sub_LCD_graphics_context();
             mmi_sub_audply_redraw_main_push_buttons(g_audply_main_selected_button,g_audply_main_selected_button_down);
     	     UI_set_main_LCD_graphics_context();
       }
        else if(g_audply.in_sub_list_screen) 
         {
            dynamic_list_goto_item(g_audply.pick_index);
        }   
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_press_next_button_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_press_next_button_down()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        return;
    }

    /* change selected button & update state */
    g_audply_main_selected_button = (signed char)AUDPLY_MAIN_NEXT;
    g_audply_main_selected_button_down = TRUE;

    /* update button display */
    UI_set_sub_LCD_graphics_context();            
    mmi_sub_audply_redraw_main_push_buttons(g_audply_main_selected_button,g_audply_main_selected_button_down);
    UI_set_main_LCD_graphics_context();  
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_press_next_button_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_press_next_button_up()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button_down && (g_audply_main_selected_button == AUDPLY_MAIN_NEXT))
    {
        /* update selected button state */
        g_audply_main_selected_button_down = FALSE;
        StopTimer(AUDPLY_COUNT_PLAY_TIMER);
    #ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
        gui_cancel_timer(mmi_audply_scroll_lyric_handler);
    #endif 
        /* pick the next song */
        mmi_audply_pick_playlist_next();
        if (mmi_audply_apply_picked_file())
        {
            if (g_audply.state == STATE_PLAY || g_audply.state == STATE_PAUSED ||
                g_mmi_audply_play_completed_after_button_down || g_audply.need_replay)
            {
                StopTimer(AUDPLY_DELAY_PLAY_TIMER);
                if(g_audply.state != STATE_PAUSED)
                {
                    StartTimer(AUDPLY_DELAY_PLAY_TIMER, 700, mmi_audply_play);    /* wait for 0.7 second to request play */
                    g_audply.wait_next = TRUE;
                    g_audply.need_restore = FALSE;
                    g_audply.continue_playing = FALSE;
                }
                else
                {
                    mmi_audply_do_stop_action();
                    
                    g_audply_main_selected_button = AUDPLY_MAIN_NEXT;//add this to slove a bug,zhongwu
                }
            }
               
            mmi_audply_clear_play_seconds();

            /* update main title, file_index, time */ 
                UI_set_sub_LCD_graphics_context();
                mmi_audply_redraw_main_file_index();
                mmi_audply_redraw_main_title();
                mmi_audply_redraw_main_time();
	            UI_set_main_LCD_graphics_context();   
        }

        g_mmi_audply_play_completed_after_button_down = FALSE;

        /* update main buttons */
        if(g_audply.in_sub_screen)
        {
            UI_set_sub_LCD_graphics_context();            
            mmi_sub_audply_redraw_main_push_buttons(g_audply_main_selected_button,g_audply_main_selected_button_down);
	        UI_set_main_LCD_graphics_context();
       }
        else if(g_audply.in_sub_list_screen)
        {
            dynamic_list_goto_item(g_audply.pick_index);
        }   
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_press_play_button_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_press_play_button_down()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
    {
        return;
    }

    /* update selected button state */
    g_audply_main_selected_button_down = TRUE;

    if (g_audply.state == STATE_PLAY && !g_audply.wait_next) 
    {
        g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PAUSE; /* change selected button */
    }
    else if (g_audply.state == STATE_PAUSED)
    {
        g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PLAY;  /* change selected button */
    }
    else    /* g_audply.state == STATE_IDLE */
    {
        g_audply_main_selected_button = (signed char)AUDPLY_MAIN_PLAY;  /* change selected button */
    }
    /* update button display */
 
    UI_set_sub_LCD_graphics_context();
    mmi_sub_audply_redraw_main_toggle_buttons(g_audply_main_selected_button,g_audply_main_selected_button_down);
    UI_set_main_LCD_graphics_context();   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_press_play_button_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_press_play_button_up()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
   if (g_audply_main_selected_button_down && ((g_audply_main_selected_button == AUDPLY_MAIN_PLAY) ||
                                               (g_audply_main_selected_button == AUDPLY_MAIN_PAUSE)))
    {
        /* update selected button state */
        g_audply_main_selected_button_down = FALSE;

        if (g_audply.state == STATE_PLAY && !g_audply.wait_next)
        {
            mmi_audply_pause();   /* do pause action */
        }
        else if (g_audply.state == STATE_PAUSED)
        {
            mmi_audply_resume();  /* do resume action */
        }
        else    /* g_audply.state == STATE_IDLE */
        {
            mmi_audply_play();    /* do play action */
        }
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_play_file_in_sub_playlist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_play_file_in_sub_playlist(void)
{
	mmi_audply_start_playlist_at(g_mmi_audply_list_highlighted_item);
	mmi_audply_pick_playlist_at(g_mmi_audply_list_highlighted_item);
	if (mmi_audply_apply_picked_file())
	{
		mmi_audply_stop_playing();
  		GoBackToSubLCDHistory(SCR_ID_AUDPLY_MAIN_SUBLCD);
		mmi_audply_play();
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_sub_update_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_update_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_update_main_button_flag();
    /* show main screen */
    mmi_audply_show_mainscreen(STR_ID_AUDPLY_TITLE, STR_ID_AUDPLY_LIST, STR_GLOBAL_BACK, g_audply.skin);

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    /* re print lyric, or it will  only be written while next lyric time tag is reached. */
    if (g_audply.lyrics_display && g_audply.state != STATE_IDLE && g_audply_lyrics_valid)
    {
    #ifndef __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__
        U8 new_encoding_type = PhnsetGetDefEncodingType() ;
        if(audply_lyric.lrc_encoding_chset != new_encoding_type )   
        {
            lyric_parse_ok = mmi_audply_init_lyric();
        }
    #else
        lyric_parse_ok = mmi_audply_init_lyric();
    #endif /* __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__ */
    }
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_audply_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_audply_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    /*KEY_PLAY_STOP KEY_FWD KEY_BACK*/
    SetKeyHandler(mmi_sub_audply_press_prev_button_down, KEY_BACK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sub_audply_press_prev_button_up, KEY_BACK, KEY_EVENT_UP);
        
    SetKeyHandler(mmi_sub_audply_press_next_button_down, KEY_FWD, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sub_audply_press_next_button_up, KEY_FWD, KEY_EVENT_UP);
        
    SetKeyHandler(mmi_sub_audply_press_play_button_down, KEY_PLAY_STOP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sub_audply_press_play_button_up, KEY_PLAY_STOP, KEY_EVENT_UP);
    SetKeyHandler(MMI_dummy_function, KEY_PLAY_STOP, KEY_EVENT_REPEAT);
		
    SetKeyHandler((FuncPtr)mmi_sub_audply_entry_option_key_handler, KEY_PLAY_STOP, KEY_EVENT_LONG_PRESS);
}
#endif /* defined(__MMI_AUDIO_PLAYER_ON_SUBLCD__) && defined(__MMI_AUDIO_PLAYER__)  */
