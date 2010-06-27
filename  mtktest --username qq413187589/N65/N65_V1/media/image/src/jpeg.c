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
 *   jpeg.c
 *
 * Project:
 * --------
 *    Maui
 *
 * Description:
 * ------------
 *   jpeg codec driver code
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
 * Handle return_code carefully.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Fix the error handling of jpeg_decode_process.
 *
 * removed!
 * removed!
 * Check the resizer, img processor and img DMA status before closing them.
 *
 * removed!
 * removed!
 * Fix the sanity check failure.
 * The config_pixel_resizer() will also open the resizer.
 *
 * removed!
 * removed!
 * If resizer is not opened, we need not to close it.
 *
 * removed!
 * removed!
 * Check the jpeg_file_handle.
 * If jpeg_file_handle is NULL, the JPEG file comes from memory (RAM/ROM). In this case, we donot clean the garbage data.
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *    Rev 1.77   Aug 18 2005 17:30:12   mtk00548
 * Modify for sanity test fail case.
 *
 *    Rev 1.76   Aug 16 2005 16:10:44   mtk00548
 * Remove compile error.
 *
 *    Rev 1.75   Aug 15 2005 13:17:36   mtk00548
 * Modify JPEG decoder driver for progressive JPEG file support.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.74   Jul 22 2005 12:05:42   mtk00548
 * Turn the clock of JPEG codec on for MT6217/18B/19/26/27 when decode one jpeg file.
 *
 *    Rev 1.73   Jul 18 2005 15:00:20   mtk00548
 * Modify for JPEG codec power up and power down procedure.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.72   Jul 11 2005 11:14:38   mtk00548
 * Modify the Exif thumbnail decode function
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.71   Jul 07 2005 15:35:14   mtk00548
 * 1. Modify the thumbnail decode feature.
 * 2. Restart the JPEG decoder if the end of JPEG file is very close to break point.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 * Resolution for 11857: [JPEG][Bug fix] Fix the problem of JPEG decode fail when the break point is very close to JPEG file end.
 *
 *    Rev 1.70   Jul 05 2005 13:20:04   mtk00548
 * Add MT6228, MT6229 compiler option to remove the compiler error of MT6219.
 *
 *    Rev 1.69   Jul 05 2005 09:16:50   mtk00548
 * Modify for Basic load.
 *
 *    Rev 1.68   Jul 05 2005 09:05:04   mtk00548
 * Remove compiler errors
 *
 *    Rev 1.67   Jul 04 2005 19:00:28   mtk00548
 * Modify Exif file parse procedure.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.66   Jul 04 2005 09:34:04   mtk00548
 * Add thumbnail decode of JFIF and Exif stadnard.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.65   Jun 24 2005 20:58:38   mtk00548
 * Modify JPEG codec driver.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.64   Jun 20 2005 17:30:30   mtk00548
 * Remove the memory init and deinit function in JPEG codec driver for MT6228 and MT6229.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.63   Jun 13 2005 17:18:06   mtk00548
 * Modify MT6228 JPEG codec driver codes.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.62   Jun 06 2005 13:49:40   mtk00548
 * Add MT6228 JPEG codec driver codes.
 * Resolution for 11375: [6228 Drv][Add driver] Add MT6228 JPEG codec, LCD, G2D, Image data path and TV output driver codes
 *
 *    Rev 1.61   May 17 2005 00:58:30   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.60   May 10 2005 21:02:18   mtk00548
 * Extend the break point when decode one JPEG file.
 * Resolution for 11006: [JPEG][Bug fix] Fix the problem of JPEG decoder will assert break point interrupt prior to EOF interrupt
 *
 *    Rev 1.59   May 10 2005 15:11:08   mtk00548
 * Modify the condition to start MJPEG playback functio.
 *
 *    Rev 1.58   May 10 2005 15:06:46   mtk00548
 * Modify the condition to start MJPEG playback functio.
 * Resolution for 10917: [MJPEG][Bug fix] Fix the problem of LCD update contention from MMI and Media task
 *
 *    Rev 1.57   May 03 2005 21:40:28   mtk00548
 * Wait LCM update completely when start M-JPEG playback function to prevent LCD update contention.
 * Resolution for 10917: [MJPEG][Bug fix] Fix the problem of LCD update contention from MMI and Media task
 *
 *    Rev 1.56   Apr 14 2005 22:24:06   mtk00548
 * Add JPEG file size to prevent the EOI (FFD9) marker located on the breakpoint for JPEG decoder.
 * Resolution for 10381: [JPEG][Bug fix] Fix the JPEG decoder hardware error and software judgement error problem
 *
 *    Rev 1.55   Apr 11 2005 19:03:46   mtk00548
 * Modify JPEG decoder process for avoiding 0xFF followed by EOI (FFD9) marker.
 * Resolution for 10381: [JPEG][Bug fix] Fix the JPEG decoder hardware error and software judgement error problem
 *
 *    Rev 1.54   Apr 08 2005 22:22:04   mtk00548
 * Reset JPEG decoder and resizer before close the image data path of JPEG file decode.
 * Resolution for 10533: [JPEG][Bug fix] Fix the problem that the color of decoded image is incorrect
 *
 *    Rev 1.53   Mar 23 2005 22:10:56   mtk00548
 * 1. Correct the process for overflow error case.
 * 2. Clear the data after EOI as 0.
 * Resolution for 10381: [JPEG][Bug fix] Fix the JPEG decoder hardware error and software judgement error problem
 *
 *    Rev 1.52   Feb 25 2005 21:58:02   mtk00548
 * Modify the JPEG file offset for JPEG decoder.
 * Resolution for 10002: [JPEG][Bug fix] Fix the bug that JPEG file parser will fail for some special JPEG file pattern
 *
 *    Rev 1.51   Feb 17 2005 13:46:48   mtk00548
 * Modify the line buffer number of resizer when enlarge the image.
 * Resolution for 9861: [JPEG][Bug fix] Modify the assignment of line buffer number for image resizer
 *
 *    Rev 1.50   Jan 31 2005 14:53:00   mtk00548
 * 1. Modify the JPEG decoder end marker process procedure.
 * 2. Check the JPEG file that is Y component only and with restart marker and think it as an invalid file due to the JPEG decoder hardware does not suppot such JPEG file.
 * Resolution for 9701: [JPEG decoder][Bug fix] Modify the JPEG decoder procedure to prevent the system hang when decode one damaged JPEG file.
 *
 *    Rev 1.49   Jan 20 2005 10:08:28   mtk00548
 * Remove one JPEG decoder decode fail case to prevent making wrong decision that result in the JPEG file becomes "invalid"
 * Resolution for 9557: [JPEG][Bug fix] Fix the bug that JPEG decoder will make wrong decision when decode some JPEG file
 *
 *    Rev 1.48   Jan 18 2005 00:49:06   BM
 * append new line in W05.04
 *
 *    Rev 1.47   Jan 13 2005 18:55:10   mtk00548
 * Release the resource of image data path before return error code for JPEG re-decode.
 *
 *    Rev 1.46   Dec 22 2004 09:07:38   mtk00548
 * Modifiy JPEG decode procedure to check if JPEG decoder hardware is down or not.
 * Resolution for 9237: [JPEG decoder][Modification] Add some adjustment to avoid JPE G decoder hardware bug
 *
 *    Rev 1.45   Dec 17 2004 21:56:14   mtk00548
 * Set MT6217 resizer's H/V ratio and residual when decode one JPEG file.
 * Resolution for 9186: [JPEG decoder] Solve MT6217 JPEG decoder can not work problem
 *
 *    Rev 1.44   Nov 29 2004 18:31:14   mtk00548
 * Modify lcd frame buffer update scenario during MJPEG playback.
 * Resolution for 8956: [ExtCam][Bug fix] Fix the bug of external cmaer module video clip function.
 *
 *    Rev 1.43   Nov 22 2004 16:50:32   mtk00548
 * Remove compiler error
 *
 *    Rev 1.42   Nov 19 2004 23:14:28   mtk00548
 * Stop JPEG decoder after JPEG decode completely in MJPEG playback function.
 * Resolution for 8719: [JPEG][Add Feature] Add video playback interface
 *
 *    Rev 1.41   Nov 16 2004 12:37:34   mtk00548
 * Remove compiler error
 *
 *    Rev 1.40   Nov 12 2004 20:55:00   mtk00548
 * 1. Modify JPEG file read through DRM file system.
 * 2. Add MJPEG playback interface
 * Resolution for 8718: [JPEG][Modify] Add DRM interface for JPEG decoder
 * Resolution for 8719: [JPEG][Add Feature] Add video playback interface
 *
 *    Rev 1.39   Nov 08 2004 17:30:38   mtk00548
 * Add assert for JPEG encode to check if the gray/color mode does not assign.
 * Resolution for 8652: [JPEG][Modify] Add JPEG encode gray/color mode check
 *
 *    Rev 1.38   Nov 05 2004 20:32:54   mtk00548
 * 1. Modify image buffer size check for JPEG decode with image clip function.
 * 2. Add buffer size check for image resize function.
 * Resolution for 8482: [JPEG] [Add Feature] Add JPEG decoder image clip function
 *
 *    Rev 1.37   Nov 03 2004 09:12:52   mtk00548
 * Add image resize function
 * Resolution for 8557: [Resizer][Add Feature] Add Image resize function
 *
 *    Rev 1.36   Oct 29 2004 18:53:16   mtk00548
 * Add JPEG decoder image clip function.
 * Resolution for 8482: [JPEG] [Add Feature] Add JPEG decoder image clip function
 *
 *    Rev 1.35   Oct 22 2004 10:40:52   mtk00548
 * Modify the calculation equation for JPEG decoder image resize.
 * Resolution for 8355: [JPEG][Bug fix] do not resize the image if the display width/height is equal to image width/height
 *
 *    Rev 1.34   Oct 12 2004 12:24:04   mtk00548
 * Reset JPEG encoder/decoder before turn on/off the power of JPEG codec.
 * Resolution for 8157: [JPEG][Bug fix] Return correct value when the JPEG encode out of buffer
 *
 *    Rev 1.33   Oct 11 2004 09:51:58   mtk00548
 * Return 0 if JPEG encoder buffer is overflow.
 * Resolution for 8157: [JPEG][Bug fix] Return correct value when the JPEG encode out of buffer
 *
 *    Rev 1.32   Oct 01 2004 18:16:56   mtk00548
 * Add MT6217 resizer codes
 * Resolution for 7990: [JPEG] Add supporting of MT6217
 *
 *    Rev 1.31   Sep 29 2004 20:22:40   mtk00548
 * Turn of the power of DCT hardware after snapshot operation complete.
 * Resolution for 7944: [JPEG] Turn on DCT hardware after snapshot complete
 *
 *    Rev 1.30   Sep 03 2004 16:48:30   mtk00548
 * Remove compiler warning
 *
 *    Rev 1.29   Aug 27 2004 16:36:56   mtk00548
 * Remove compile warnings.
 *
 *    Rev 1.28   Aug 18 2004 11:49:08   mtk00548
 * Add codes to check the size of Huffman table and Q table to avoid bad JPEG file damages the buffer.
 * Resolution for 224: Assert fail: (((kal_uint32)start_ptr&0x03)==0)&&(visual_mem.ext_ram_init==KAL_FALSE) visual_comm.c 90 - MED
 * Resolution for 230: Assert fail: 0 m12100.c 4546 -
 * Resolution for 232: Assert fail: I < 20 pcm.c 460 - MED
 * Resolution for 234: Assert fail: t!=NULL med_ext_smalloc.c 219 - MED
 *
 *    Rev 1.27   Aug 06 2004 19:01:08   mtk00548
 * 1. Disable all interrupt during the period when turn on/off the power of JPEG codec to prevent contention issue.
 * 2. Add snap shot JPEG encode function.
 *
 *    Rev 1.26   Jul 30 2004 20:17:54   mtk00548
 * Modify setting of JPEG encoder stop address
 *
 *    Rev 1.25   Jul 27 2004 20:18:44   mtk00548
 * Modify MT6219 JPEG decoder multi-run function
 * Resolution for 6809: [JPEG][Modify] Change JPEG decoder single run to multi-run decode
 *
 *    Rev 1.24   Jul 22 2004 14:39:32   mtk00548
 * Modify the JPEG decode procedure for multi-run JPEG decode.
 * Resolution for 6809: [JPEG][Modify] Change JPEG decoder single run to multi-run decode
 *
 *    Rev 1.23   Jul 16 2004 20:06:58   mtk00548
 * Call JPEG decoder callback function when Resizer interrupt occurs no matter JPEG decoder completely or not.
 * Resolution for 122: ImageViewer-The JPG icon display blank, but the JPG file "snoopytyping_1024x768.jpg" display normal
 *
 *    Rev 1.22   Jul 12 2004 13:38:16   mtk00481
 * add compile option for MNT simulator
 *
 *    Rev 1.21   Jul 02 2004 12:13:38   mtk00548
 * Modify JPEG encoder process type error.
 *
 *    Rev 1.20   Jul 02 2004 11:41:58   mtk00548
 * Increase one dummy line at the buttom of JPEG file when MMI get the decoded image size after resizer
 * Resolution for 2820: MMS_Extra underline displaya in a JPG
 *
 *    Rev 1.19   Jun 25 2004 18:14:14   mtk00548
 * 1. Increase one dummy line at the buttom of JPEG file when decode one JPEG file with dummy lines.
 * 2. Modify JPEG encode process to return JPEG file size after JPEG encode process complete.
 * Resolution for 2820: MMS_Extra underline displaya in a JPG
 *
 *    Rev 1.18   Jun 03 2004 15:05:36   mtk00548
 * 1. Disable L1 sleep mode when JPEG codec is running
 * 2. Check JPEG dcoder status when resizer HISR occurs to return the correct error code when  JPEG decoder fail but resizer success.
 * Resolution for 2451: File Manager-Can't show file of .jpg format
 *
 *    Rev 1.17   May 31 2004 19:02:34   mtk00548
 * Add ISP_SUPPORT compiler option to excludes image sensor
 * correlated codes
 *
 *    Rev 1.16   May 28 2004 16:34:14   mtk00548
 * Modify JPEG error handling code
 *
 *    Rev 1.15   May 26 2004 19:47:46   mtk00548
 * Remove compile error for MT6219
 *
 *    Rev 1.14   May 26 2004 15:35:34   mtk00548
 * 1. Add JPEG file parsing error return code
 * 2. Release all resources for JPEG decode process if any error occurs
 * Resolution for 2083: [1]Assert Fail:(((kal_uint32)start_pt visual_comm.c 111
 *
 *    Rev 1.13   May 24 2004 16:42:56   mtk00548
 * Include some headers files for video_glb.h
 *
 *    Rev 1.12   May 20 2004 10:16:58   mtk00548
 * Remove MPEG4 module power on codes.
 *
 *    Rev 1.11   May 14 2004 20:37:52   mtk00548
 * Unmask video correlated codes
 *
 *    Rev 1.10   May 13 2004 08:46:56   mtk00548
 * 1. Temporary remove video related code because video file still not check in.
 * 2. Modify the JPEG file parsing error due to substration overflow.
 *
 *    Rev 1.9   May 07 2004 20:14:56   mtk00548
 * Reset DCT before JPEG codec operation.
 *
 *    Rev 1.8   Apr 30 2004 15:34:10   mtk00548
 * Return error if memory assigned for JPEG decoder not enough.
 * Resolution for 1437: Assert fail: 0 visual_comm.c 116 - MED
 *
 *    Rev 1.7   Apr 26 2004 16:55:14   mtk00548
 * Change MT6219 JPEG decoder interrupt trigger method from LEVEL trigger to EDGE trigger.
 *
 *    Rev 1.6   Apr 22 2004 17:58:30   mtk00548
 * 1. Power on DCT during JPEG codec operation in MT6219.
 * 2. Change JPEG deocder interrupt from level trigger to edge trigger.
 *
 *    Rev 1.5   Apr 12 2004 15:47:36   mtk00548
 * Remove the compile option, MEDIA_TASK_INTEGRATION.
 *
 *    Rev 1.4   Apr 08 2004 13:36:16   mtk00548
 * Change the timing of JPEG codec power on and off for power saving.
 *
 *    Rev 1.3   Mar 31 2004 17:51:54   mtk00548
 * Add scale up judgement by image_height
 *
 *    Rev 1.2   Mar 26 2004 17:04:34   mtk00548
 * Remove the compile error
 *
 *    Rev 1.1   Mar 26 2004 16:37:42   mtk00548
 * Modify the resizer working memory size.
 *
 *    Rev 1.0   Mar 25 2004 11:36:36   admin
 * Initial revision.
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#include "reg_base.h"
#include "IntrCtrl.h"
#include "drv_comm.h"
#include "drvpdn.h"
#include "lcd_if.h"
#include "jpeg.h"
#include "visualhisr.h"
#include "visual_comm.h"
#include "fat_fs.h"
#include "drm_gprot.h"
//#if (defined(DRV_JPG_DATA_PATH_19_SERIES)||defined(DRV_JPG_DATA_PATH_28_SERIES))
#if (defined(DRV_JPG_DATA_PATH_19_SERIES)||defined(DRV_JPG_DATA_PATH_28_SERIES))
#include "resizer.h"
#include "isp_if.h"
#include "imgproc.h"
#include "img_comm.h"
#include "imgdma.h"
#include "fsal.h"
#include "mp4_parser.h"
#include "l1audio.h"
#include "rtc_sw.h"
#include "video_file_creator.h"
#include "bmd.h"
#include "video_enc_glb.h"
#include "video_dec_glb.h"
#include "video_glb.h"
#endif
/*
#if (defined(JPEG_DRV_V3))
#include "tv_out.h"
#endif
Scott, what this for? */

#if (defined(WEBCAM_SUPPORT))
#include "usbvideo_cam_if.h"
#endif
#if (defined(EXIF_SUPPORT))
#include "exif.h"
#endif

#if (defined(DRV_JPG_DEC_SUPPORT) || defined(DRV_JPG_ENC_SUPPORT))

#if (defined(DRV_JPG_HW_ENC_SUPPORT) && defined(ISP_SUPPORT))
extern kal_eventgrpid camera_isp_event_id;
extern camera_capture_jpeg_struct isp_capture_jpeg_data;
#endif

kal_bool jpeg_file_without_eoi;
kal_uint8 times_of_total_mcu_num=1;
kal_bool jpeg_thumbnail_mode=KAL_FALSE;
kal_bool jpeg_decode_break=KAL_FALSE;
kal_bool jpeg_decode_wait_event=KAL_FALSE;
kal_bool jpeg_decode_next_block=KAL_FALSE;


#if defined(DRV_JPG_DEC_19_SERIES)
static kal_uint32 _img_resizer_opened   = 0;
static kal_uint32 _img_processor_opened = 0;
static kal_uint32 _img_dma_opened       = 0;
#elif defined(DRV_JPG_DEC_28_SERIES)
static kal_uint32 _idp_opened = 0;
#endif


#ifndef __MAUI_BASIC__
extern kal_uint8 L1SM_GetHandle(void);
extern void L1SM_SleepEnable(kal_uint8 handle);
extern void L1SM_SleepDisable(kal_uint8 handle);
kal_uint8   jpeg_codec_sleep_mode_handler=0xFF;
#endif

jpeg_parameter_struct jpeg_file_para,jpeg_thumb_para;

jpeg_decode_process_struct jpeg_decode_config_data;

kal_uint16 jpeg_file_resize_width;
kal_uint16 jpeg_file_resize_height;
volatile kal_uint8 jpeg_decoder_decode_result;
kal_uint32 jpeg_decode_int_mem_size=0;
kal_uint32 jpeg_decode_ext_mem_size=0;
kal_uint32 jpeg_file_offset=0;

/* Log DRM READ Error */
kal_uint32 jpeg_drm_read_error_count=0;
kal_uint32 jpeg_drm_seek_error_count=0;
kal_uint32 jpeg_driver_status=0;

kal_uint8 jpeg_decoder_return_code;
volatile JPEG_DECODER_STATE_ENUM jpeg_decoder_operation_state=JPEG_DECODER_IDLE_STATE;

#if (defined(DRV_JPG_DATA_PATH_17_SERIES))
volatile kal_uint8 jpeg_file_resizer_result;
#endif

volatile kal_uint8 jpeg_video_play_flag;
lcd_frame_update_struct jpeg_video_play_lcd_data;
extern kal_uint8 jpeg_video_play_lcd_id;

kal_eventgrpid jpeg_codec_event_id=NULL;

#if (defined(DRV_JPG_HW_ENC_SUPPORT))
volatile JPEG_ENCODER_STATE_ENUM jpeg_encoder_operation_state=JPEG_ENCODER_IDLE_STATE;
kal_uint8 jpeg_encoder_encode_result=0;
jpeg_encode_process_struct jpeg_encode_config_data;
#endif

#if (defined(DRV_RGB_RESIZE_SUPPORT))
resize_struct thumbnail_resize_data;
#endif

#if (defined(DRV_JPG_RESIZE_SUPPORT))
jpeg_file_resize_struct jpeg_resize_config_data;
#endif

#if (defined(DRV_JPG_DATA_PATH_28_SERIES))
extern volatile kal_bool wait_last_capture_frame;  //Scott, what this for?
#endif
/* bear */

#if (!defined(__MTK_TARGET__))
kal_uint8 y_channel[640*480];
kal_uint8 u_channel[320*240];
kal_uint8 v_channel[320*240];
//kal_uint8 jpeg_sw_intmem[JPEG_SW_ENC_REQUIRED_INT_MEM_SIZE];
#endif

void jpeg_codec_power_up(void)
{
#if (defined(DRV_JPG_HW_DEC_SUPPORT) || defined(DRV_JPG_HW_ENC_SUPPORT))
   kal_uint32 save_irq_mask;

   #if (defined(DRV_JPG_DATA_PATH_17_SERIES))
   save_irq_mask=SaveAndSetIRQMask();
   DRV_Reg(DRVPDN_CON0_CLR) = DRVPDN_CON0_JPEG; // Power on JPEG decoder
   DRV_Reg(DRVPDN_CON0_CLR) = DRVPDN_CON0_RESZ; // Power on Resizer
   RestoreIRQMask(save_irq_mask);
   #elif (defined(DRV_JPG_DATA_PATH_19_SERIES)||defined(DRV_JPG_DATA_PATH_28_SERIES))
   save_irq_mask=SaveAndSetIRQMask();
   DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_JPEG; //Power on JPEG codec
   DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_DCT;     //power on DCT
   RestoreIRQMask(save_irq_mask);
   #if (defined(DRV_JPG_DEC_19_SERIES)||defined(DRV_JPG_ENC_19_SERIES))
   mp4_reset();
   #endif
   #endif

   #ifdef DRV_JPG_HW_ENC_SUPPORT
   RESET_JPEG_ENCODER;
   #endif

   #ifdef DRV_JPG_HW_DEC_SUPPORT
   RESET_JPEG_DECODER;
   #endif

   #ifndef __MAUI_BASIC__
   L1SM_SleepDisable(jpeg_codec_sleep_mode_handler);
   #endif   /* __MAUI_BASIC__ */

#endif //DRV_JPG_HW_DEC_SUPPORT, DRV_JPG_HW_ENC_SUPPORT
}

void jpeg_codec_power_down(void)
{
#if (defined(DRV_JPG_HW_DEC_SUPPORT) || defined(DRV_JPG_HW_ENC_SUPPORT))
   kal_uint32 save_irq_mask;

   #if (defined(DRV_JPG_DATA_PATH_17_SERIES))
   save_irq_mask=SaveAndSetIRQMask();
   DRV_Reg(DRVPDN_CON0_SET)= DRVPDN_CON0_JPEG;  /* Power on JPEG decoder */
   DRV_Reg(DRVPDN_CON0_SET)= DRVPDN_CON0_RESZ;  /* Power on Resizer */
   RestoreIRQMask(save_irq_mask);
   #elif (defined(DRV_JPG_DATA_PATH_19_SERIES)||defined(DRV_JPG_DATA_PATH_28_SERIES))
   save_irq_mask=SaveAndSetIRQMask();
   DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_JPEG; /* Power on JPEG codec */
   DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_DCT;     /* power on DCT */
   jpeg_encoder_operation_state=JPEG_ENCODER_STANDBY_STATE;/*reset state*/
   RestoreIRQMask(save_irq_mask);
   #if (defined(DRV_JPG_DEC_19_SERIES)||defined(DRV_JPG_ENC_19_SERIES))
   mp4_reset();
   #endif
#endif

   #if (defined(DRV_JPG_HW_DEC_SUPPORT))
   RESET_JPEG_DECODER;
   #endif

   #if (defined(DRV_JPG_HW_ENC_SUPPORT))
   RESET_JPEG_ENCODER;
   #endif

#ifndef __MAUI_BASIC__
   L1SM_SleepEnable(jpeg_codec_sleep_mode_handler);
#endif   /* __MAUI_BASIC__ */
 #endif
}

#if (defined(DRV_JPG_DEC_17_SERIES)||defined(DRV_JPG_DEC_19_SERIES)||defined(DRV_JPG_ENC_19_SERIES))
/*************************************************************************
* FUNCTION
*     jpeg_LISR
*
* DESCRIPTION
*     jpeg decoder LISR entry
*
* PARAMETERS
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void jpeg_LISR(void)
{
   unsigned int int_status;
 #if(defined(DRV_JPG_DEC_17_SERIES) || defined(DRV_JPG_DEC_19_SERIES))
   if (jpeg_decoder_operation_state==JPEG_DECODER_DECODING_STATE)
   {  /* jpeg decoder interrupt */
      IRQMask(IRQ_JPEG_CODE);

      int_status=DRV_Reg32(JPEG_DECODER_INT_STATUS_REG);
      if (int_status & JPEG_INT_STATUS_MASK)
      {  /* JPEG decoder interrupt */
         if (int_status & JPEG_INT_STATUS_FILE_OVERFLOW_BIT)
            jpeg_decoder_decode_result|=JPEG_DECODE_FILE_OVERFLOW;

         if (int_status & JPEG_INT_STATUS_BREAKPOINT_BIT)
            jpeg_decoder_decode_result|=JPEG_DECODE_BREAK;

         if (int_status & JPEG_INT_STATUS_EOF_BIT)
            jpeg_decoder_decode_result|=JPEG_DECODE_COMPLETE;

         visual_active_hisr(VISUAL_JPEG_DEC_HISR_ID);
      }
      else
         IRQUnmask(IRQ_JPEG_CODE);
   }
 #endif

 #if (defined(DRV_JPG_ENC_19_SERIES))
   if (jpeg_encoder_operation_state==JPEG_ENCODER_ENCODING_STATE)
   {  /* jpeg encoder interrupt */
      IRQMask(IRQ_JPEG_CODE);
      int_status =DRV_Reg32(JPEG_ENCODER_INT_STATUS_REG);
      if (int_status!=0)
      {
      REG_JPEG_ENCODER_INT_STATUS=0;

      if (int_status & JPEG_ENCODER_DONE_INT_STATUS)
         jpeg_encoder_encode_result |= JPEG_ENCODE_DONE;

      if (int_status & JPEG_ENCODER_STALL_INT_STATUS)
         jpeg_encoder_encode_result |= JPEG_ENCODE_STALL;

      visual_active_hisr(VISUAL_JPEG_ENC_HISR_ID);
   }
      else
      {
         IRQUnmask(IRQ_JPEG_CODE);
      }
   }
#endif   /* MT6219, MT6226, MT6227 */
}  /* jpeg_LISR() */
#endif

#if (defined(DRV_JPG_DEC_28_SERIES))
/*************************************************************************
* FUNCTION
*     jpeg_dec_LISR
*
* DESCRIPTION
*     jpeg decoder LISR entry
*
* PARAMETERS
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void jpeg_dec_LISR(void)
{
   unsigned int int_status;

   if (jpeg_decoder_operation_state==JPEG_DECODER_DECODING_STATE)
   {  /* jpeg decoder interrupt */
      IRQMask(IRQ_JPEG_DEC_CODE);
      int_status=DRV_Reg32(JPEG_DECODER_INT_STATUS_REG);
      if (int_status & JPEG_INT_STATUS_MASK)
      {  /* JPEG decoder interrupt */
         if (int_status & JPEG_INT_STATUS_FILE_OVERFLOW_BIT)
            jpeg_decoder_decode_result|=JPEG_DECODE_FILE_OVERFLOW;

         if (int_status & JPEG_INT_STATUS_BREAKPOINT_BIT)
            jpeg_decoder_decode_result|=JPEG_DECODE_BREAK;

         if (int_status & JPEG_INT_STATUS_EOF_BIT)
            jpeg_decoder_decode_result|=JPEG_DECODE_COMPLETE;

         visual_active_hisr(VISUAL_JPEG_DEC_HISR_ID);
      }
      else
         IRQUnmask(IRQ_JPEG_DEC_CODE);
   }
}
#endif

#if (defined(DRV_JPG_ENC_28_SERIES))
void jpeg_enc_LISR(void)
{
   unsigned int int_status;

   IRQMask(IRQ_JPEG_ENC_CODE);
   int_status =DRV_Reg32(JPEG_ENCODER_INT_STATUS_REG);

   if (int_status!=0)
   {
      if (isp_operation_state==ISP_CAPTURE_JPEG_STATE)
      {  /* jpeg encoder interrupt */
         REG_JPEG_ENCODER_INT_STATUS=0;

         if (int_status & JPEG_ENCODER_DONE_INT_STATUS)
         {
            if (current_captured_file_number & 0x01)
            {
               camera_capture_jpeg_config_data.jpeg_file_info->jpeg_file_address[++current_captured_file_number]=REG_JPEG_ENCODER_DMA_ADDR2;
            }
            else
            {
               camera_capture_jpeg_config_data.jpeg_file_info->jpeg_file_address[++current_captured_file_number]=REG_JPEG_ENCODER_DMA_ADDR;
            }

            jpeg_encoder_encode_result |= JPEG_ENCODE_DONE;
            visual_active_hisr(VISUAL_JPEG_ENC_HISR_ID);
         }
         else if (int_status & JPEG_ENCODER_STALL1_INT_STATUS)
         {
            jpeg_encoder_encode_result |= JPEG_ENCODE_STALL;
            visual_active_hisr(VISUAL_JPEG_ENC_HISR_ID);
         }
      }
      else if (jpeg_encoder_operation_state==JPEG_ENCODER_ENCODING_STATE)
      {
         REG_JPEG_ENCODER_INT_STATUS=0;

         if (int_status & JPEG_ENCODER_DONE_INT_STATUS)
            jpeg_encoder_encode_result |= JPEG_ENCODE_DONE;

         if (int_status & JPEG_ENCODER_STALL_INT_STATUS)
            jpeg_encoder_encode_result |= JPEG_ENCODE_STALL;

         visual_active_hisr(VISUAL_JPEG_ENC_HISR_ID);
      }
   }
   else
   {
      IRQUnmask(IRQ_JPEG_ENC_CODE);
   }
}  /* jpeg_enc_LISR() */
#endif   /* MT6228, MT6229*/

/*************************************************************************
* FUNCTION
*     jpeg_decoder_HISR
*
* DESCRIPTION
*     jpeg decoder HISR entry
*
* PARAMETERS
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void jpeg_decoder_HISR(void)
{
#if (defined(DRV_JPG_HW_DEC_SUPPORT))
   kal_uint8 *jpg_ptr;
   kal_uint32 temp_address[6];
   kal_uint8 jpeg_decoder_flag=KAL_FALSE;
   volatile kal_uint16 i;

   if (jpeg_decoder_operation_state == JPEG_DECODER_DECODING_STATE)
   {
      if (jpeg_decoder_decode_result & JPEG_DECODE_FILE_OVERFLOW)
      {
         jpeg_decoder_operation_state=JPEG_DECODER_STANDBY_STATE;

         if (jpeg_decode_wait_event==KAL_TRUE)
         {
            jpeg_decoder_return_code=JPEG_DECODE_DECODER_OVERFLOW_FAIL;
            kal_set_eg_events(jpeg_codec_event_id,JPEG_DECODE_BREAK_INT_EVENT,KAL_OR);
         }
         else
         {
            if (jpeg_decode_config_data.jpeg_decode_cb!=NULL)
               jpeg_decode_config_data.jpeg_decode_cb(JPEG_DECODE_DECODER_OVERFLOW_FAIL);
         }
#if (defined(DRV_JPG_DEC_17_SERIES)||defined(DRV_JPG_DEC_19_SERIES))
         IRQUnmask(IRQ_JPEG_CODE);
#elif (defined(DRV_JPG_DEC_28_SERIES))
         IRQUnmask(IRQ_JPEG_DEC_CODE);
#endif
         return;
      }

      if (jpeg_decoder_decode_result & JPEG_DECODE_COMPLETE)
      {
         if (jpeg_file_para.jpg_progressive==KAL_TRUE)
         {
            if (jpeg_file_para.progressive_decode_times!=0)
            {
               temp_address[0]=REG_JPEG_DECODER_TABLE_ADDR;
               temp_address[1]=REG_JPEG_DECODER_COMP0_PROG_START_ADDR;
               temp_address[2]=REG_JPEG_DECODER_COMP1_PROG_START_ADDR;
               temp_address[3]=REG_JPEG_DECODER_COMP2_PROG_START_ADDR;
               temp_address[4]=REG_JPEG_DECODER_FILE_SIZE;
               temp_address[5]=REG_JEPG_DECODER_STOP_ADDR;
               RESET_JPEG_DECODER;
               REG_JPEG_DECODER_CTRL=jpeg_file_para.jpeg_decoder_ctrl_reg;
               REG_JPEG_DECODER_JPEG_FILE_START_ADDR = jpeg_decode_config_data.jpeg_file_buffer_address;
               REG_JPEG_DECODER_TABLE_ADDR = temp_address[0];
               REG_JPEG_DECODER_COMP0_PROG_START_ADDR = temp_address[1];
               REG_JPEG_DECODER_COMP1_PROG_START_ADDR = temp_address[2];
               REG_JPEG_DECODER_COMP2_PROG_START_ADDR = temp_address[3];
               REG_JPEG_DECODER_FILE_SIZE=temp_address[4];
               REG_JEPG_DECODER_STOP_ADDR=temp_address[5];

               REG_JEPG_DECODER_INTERLEAVE_FIRST_MCU_INDEX+=jpeg_file_para.interleave_mcu_increament_index;
               REG_JEPG_DECODER_INTERLEAVE_LAST_MCU_INDEX+=jpeg_file_para.interleave_mcu_increament_index;
               REG_JEPG_DECODER_COMP0_FIRST_MCU_INDEX+=jpeg_file_para.non_interleav_mcu_increament_index_y;
               REG_JEPG_DECODER_COMP0_LAST_MCU_INDEX+=jpeg_file_para.non_interleav_mcu_increament_index_y;
               REG_JEPG_DECODER_COMP1_FIRST_MCU_INDEX+=jpeg_file_para.non_interleav_mcu_increament_index_u;
               REG_JEPG_DECODER_COMP1_LAST_MCU_INDEX+=jpeg_file_para.non_interleav_mcu_increament_index_u;
               REG_JEPG_DECODER_COMP2_FIRST_MCU_INDEX+=jpeg_file_para.non_interleav_mcu_increament_index_v;
               REG_JEPG_DECODER_COMP2_LAST_MCU_INDEX+=jpeg_file_para.non_interleav_mcu_increament_index_v;
               jpeg_file_para.progressive_decode_times--;
               jpeg_decoder_decode_result=0;
               if ((jpeg_file_offset==jpeg_file_para.thumbnail_offset)&&
                   ((jpeg_decode_config_data.jpeg_file_buffer_size-16)<jpeg_decode_config_data.jpeg_file_size))
                     {
                  if (jpeg_decode_config_data.jpeg_decode_cb!=NULL)
                     jpeg_decode_config_data.jpeg_decode_cb(JPEG_DECODE_DECODING);
                     }
               else
                     {
         #if (defined(DRV_JPG_DEC_17_SERIES)||defined(DRV_JPG_DEC_19_SERIES))
               IRQUnmask(IRQ_JPEG_CODE);
         #elif (defined(DRV_JPG_DEC_28_SERIES))
               IRQUnmask(IRQ_JPEG_DEC_CODE);
         #endif
               START_JPEG_DECODER;
            }
            }
            else
               jpeg_decoder_flag=KAL_TRUE;
         }
         else
            jpeg_decoder_flag=KAL_TRUE;
#if (defined(DRV_JPG_DATA_PATH_17_SERIES))
         if (jpeg_decoder_flag==KAL_TRUE)
         {
            if (jpeg_file_resizer_result==JPEG_RESIZER_COMPLETE)
            {
               jpeg_decoder_operation_state = JPEG_DECODER_STANDBY_STATE;

               if (jpeg_decode_config_data.jpeg_decode_cb!=NULL)
                  jpeg_decode_config_data.jpeg_decode_cb(JPEG_DECODE_SUCCESS);

            }
            else if (jpeg_file_resizer_result==JPEG_RESIZER_FAIL)
            {
               jpeg_decoder_operation_state = JPEG_DECODER_STANDBY_STATE;

               if (jpeg_decode_config_data.jpeg_decode_cb!=NULL)
                  jpeg_decode_config_data.jpeg_decode_cb(JPEG_DECODE_RESIZER_FAIL);
            }
         }
#endif

#if (defined(DRV_JPG_DEC_17_SERIES)||defined(DRV_JPG_DEC_19_SERIES))
         IRQUnmask(IRQ_JPEG_CODE);
#elif (defined(DRV_JPG_DEC_28_SERIES))
         IRQUnmask(IRQ_JPEG_DEC_CODE);
#endif
         return ;
      }
      else if (jpeg_decoder_decode_result & JPEG_DECODE_BREAK)
      {
         if (jpeg_decode_wait_event==KAL_TRUE)
         {
            kal_set_eg_events(jpeg_codec_event_id,JPEG_DECODE_BREAK_INT_EVENT,KAL_OR);
         }
         else
         {
            if (jpeg_decode_next_block==KAL_TRUE)
            {
               if (jpeg_decode_config_data.jpeg_decode_cb!=NULL)
                  jpeg_decode_config_data.jpeg_decode_cb(JPEG_DECODE_DECODING);
            }
            else
            {
               if (jpeg_decode_break==KAL_TRUE)
               {  /* trigger the JPEG decoder again */
                  jpg_ptr=(kal_uint8 *) (REG_JEPG_DECODER_STOP_ADDR-16);
                  for (i=0;i<16;i++)
                  {
                     *(jpg_ptr+i)=0;
                  }
                  jpeg_decode_break=KAL_FALSE;
                  REG_JPEG_DECODER_JPEG_FILE_START_ADDR=REG_JEPG_DECODER_STOP_ADDR-16;
               }
               else
               {
                  jpeg_decoder_operation_state=JPEG_DECODER_STANDBY_STATE;
                  if (jpeg_decode_config_data.jpeg_decode_cb!=NULL)
                     jpeg_decode_config_data.jpeg_decode_cb(JPEG_DECODE_DECODER_BREAK_FAIL);
               }
            }
         }
   #if (defined(DRV_JPG_DEC_17_SERIES)||defined(DRV_JPG_DEC_19_SERIES))
            IRQUnmask(IRQ_JPEG_CODE);
   #elif (defined(DRV_JPG_DEC_28_SERIES))
            IRQUnmask(IRQ_JPEG_DEC_CODE);
   #endif
         return;
      }
   }
   #if (defined(DRV_JPG_DEC_17_SERIES)||defined(DRV_JPG_DEC_19_SERIES))
      IRQUnmask(IRQ_JPEG_CODE);
   #elif (defined(DRV_JPG_DEC_28_SERIES))
      IRQUnmask(IRQ_JPEG_DEC_CODE);
   #endif

#endif //DRV_JPG_HW_DEC_SUPPORT
}  /* jpeg_decoder_HISR() */


/*************************************************************************
* FUNCTION
*     jpeg_encoder_HISR
*
* DESCRIPTION
*     jpeg encoder HISR entry
*
* PARAMETERS
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void jpeg_encoder_HISR(void)
{
#if defined(DRV_JPG_HW_ENC_SUPPORT)

#if defined(DRV_JPG_ENC_19_SERIES) || defined(DRV_JPG_ENC_28_SERIES)

   if (isp_operation_state == ISP_CAPTURE_JPEG_STATE) {

   #if defined(DRV_JPG_ENC_19_SERIES) && defined(ISP_SUPPORT)
      kal_set_eg_events(camera_isp_event_id,CAMERA_JPEG_ENCODE_EVENT,KAL_OR);
   #endif   /// #if defined(DRV_JPG_ENC_19_SERIES) && defined(ISP_SUPPORT)

   #if defined(DRV_JPG_ENC_28_SERIES)
      if ((jpeg_encoder_encode_result & JPEG_ENCODE_STALL) &&
          (REG_JPEG_ENCODER_DMA_ADDR >= REG_JPEG_ENCODER_STOP_ADDR)) {
         if (camera_capture_jpeg_config_data.cam_capture_jpeg_cb) {
            camera_capture_jpeg_config_data.cam_capture_jpeg_cb(JPEG_ENCODE_BUFFER_FULL);
         }

      #if defined(DRV_JPG_DATA_PATH_28_SERIES)
         wait_last_capture_frame = KAL_FALSE;
      #endif
      }

      if (jpeg_encoder_encode_result & JPEG_ENCODE_DONE) {
         camera_capture_jpeg_config_data.jpeg_file_info->jpeg_file_size[current_captured_file_number - 1] =
         camera_capture_jpeg_config_data.jpeg_file_info->jpeg_file_address[current_captured_file_number] -
         camera_capture_jpeg_config_data.jpeg_file_info->jpeg_file_address[current_captured_file_number - 1];

         if (camera_capture_jpeg_config_data.cam_capture_jpeg_cb) {
            camera_capture_jpeg_config_data.cam_capture_jpeg_cb(current_captured_file_number);
         }

      #if defined(DRV_JPG_DATA_PATH_28_SERIES)
         wait_last_capture_frame = KAL_FALSE;
      #endif
      }
   #endif   /// #if defined(DRV_JPG_ENC_28_SERIES)
   }

#if defined(WEBCAM_SUPPORT)
   else if((usbvideo_cam_operation_state == USBVIDEO_CAM_PREVIEW_CHECK_STATE) ||
           (usbvideo_cam_operation_state == USBVIDEO_CAM_CAPTURE_STATE))
   {  /* For WEBCAM MT6228+TG sync AE/AWB frame ready and jpeg encode interrupt sync */
      usbvideo_camera_jpeg_flag = KAL_TRUE;
      usbvideo_camera_frame_ready();
   }
#endif

   else if (jpeg_encoder_operation_state == JPEG_ENCODER_ENCODING_STATE) {
      kal_set_eg_events(jpeg_codec_event_id,JPEG_ENCODE_INT_EVENT,KAL_OR);

#if defined(DRV_JPG_ENC_28_SERIES)
      /* for JPEG reisze process */
      if (jpeg_decode_wait_event == KAL_TRUE) {
         jpeg_decoder_operation_state=JPEG_DECODER_STANDBY_STATE;
         jpeg_decoder_return_code=JPEG_DECODE_SUCCESS;
         kal_set_eg_events(jpeg_codec_event_id,JPEG_DECODE_BREAK_INT_EVENT,KAL_OR);
      }
#endif
   }

#if (defined(DRV_JPG_ENC_19_SERIES))
   IRQUnmask(IRQ_JPEG_CODE);
#elif (defined(DRV_JPG_ENC_28_SERIES))
   IRQUnmask(IRQ_JPEG_ENC_CODE);
#endif

#endif   /// #if defined(DRV_JPG_ENC_19_SERIES) || defined(DRV_JPG_ENC_28_SERIES)
#endif   /// #if defined(DRV_JPG_HW_ENC_SUPPORT)
}




/*************************************************************************
* FUNCTION
*     jpeg_decode_cb_HISR
*
* DESCRIPTION
*     jpeg decoder HISR callback  entry
*
* PARAMETERS
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if (defined(DRV_JPG_DEC_19_SERIES)||defined(DRV_JPG_DEC_28_SERIES))
void jpeg_decode_cb_HISR(void)
{
   if (jpeg_decoder_operation_state==JPEG_DECODER_DECODING_STATE)
   {
      if (jpeg_decoder_decode_result & JPEG_DECODE_COMPLETE)
      {
         jpeg_decoder_operation_state=JPEG_DECODER_STANDBY_STATE;
         if (jpeg_decode_wait_event==KAL_TRUE)
         {
            jpeg_decoder_return_code=JPEG_DECODE_SUCCESS;
            kal_set_eg_events(jpeg_codec_event_id,JPEG_DECODE_BREAK_INT_EVENT,KAL_OR);
      }
      else
      {
         if (jpeg_decode_config_data.jpeg_decode_cb!=NULL)
            jpeg_decode_config_data.jpeg_decode_cb(JPEG_DECODE_SUCCESS);
         }
      }
      else
      {
         jpeg_decoder_operation_state=JPEG_DECODER_STANDBY_STATE;
         if (jpeg_decode_wait_event==KAL_TRUE)
         {
               jpeg_decoder_return_code=JPEG_DECODE_SUCCESS;
            kal_set_eg_events(jpeg_codec_event_id,JPEG_DECODE_BREAK_INT_EVENT,KAL_OR);
            /* prevent wait event dead lock */
         }
         else
         {
            if (jpeg_decode_config_data.jpeg_decode_cb!=NULL)
            {
               if (jpeg_decoder_decode_result & JPEG_DECODE_FILE_OVERFLOW)
                  jpeg_decode_config_data.jpeg_decode_cb(JPEG_DECODE_DECODER_OVERFLOW_FAIL);
               else
                  jpeg_decode_config_data.jpeg_decode_cb(JPEG_DECODE_SUCCESS);
            }
         }
      }
   }
}
#endif

/*************************************************************************
* FUNCTION
*     resizer_LISR
*
* DESCRIPTION
*     resizer LISR entry
*
* PARAMETERS
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if (defined(DRV_JPG_DATA_PATH_17_SERIES))
void resizer_LISR(void)
{
   kal_uint32 int_status;

   IRQMask(IRQ_RESZ_CODE);
#if (defined(MT6218B))
      int_status=REG_RESIZER_YUV2RGB_INT_STATUS;

      if (int_status & RESIZER_YUV2RGB_INT_STATUS_BIT)
         jpeg_file_resizer_result=JPEG_RESIZER_COMPLETE;
      else
         jpeg_file_resizer_result=JPEG_RESIZER_FAIL;
#elif (defined(MT6217))
   int_status=REG_RESIZER_INT_STATUS;

   if (int_status & RESIZER_YUV2RGB_INT_STATUS_BIT)
      jpeg_file_resizer_result=JPEG_RESIZER_COMPLETE;
   else
      jpeg_file_resizer_result=JPEG_RESIZER_FAIL;
#endif
      visual_active_hisr(VISUAL_RESIZER_HISR_ID);
}  /* resizer_LISR() */
#endif
/*************************************************************************
* FUNCTION
*     resizer_HISR
*
* DESCRIPTION
*     resizer HISR entry
*
* PARAMETERS
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if (defined(DRV_JPG_DATA_PATH_17_SERIES))
void resizer_HISR(void)
{
   if (jpeg_decoder_operation_state == JPEG_DECODER_DECODING_STATE)
   {
      if (jpeg_decoder_decode_result & JPEG_DECODE_COMPLETE)
      {
         jpeg_decoder_operation_state = JPEG_DECODER_STANDBY_STATE;
         if (jpeg_file_resizer_result==JPEG_RESIZER_COMPLETE)
         {
            if (jpeg_decode_config_data.jpeg_decode_cb!=NULL)
               jpeg_decode_config_data.jpeg_decode_cb(JPEG_DECODE_SUCCESS);
         }
         else if (jpeg_file_resizer_result==JPEG_RESIZER_FAIL)
         {
            if (jpeg_decode_config_data.jpeg_decode_cb!=NULL)
               jpeg_decode_config_data.jpeg_decode_cb(JPEG_DECODE_RESIZER_FAIL);
         }
      }
      else
      {
         jpeg_decoder_operation_state = JPEG_DECODER_STANDBY_STATE;
         if (jpeg_file_resizer_result==JPEG_RESIZER_COMPLETE)
         {
         #if (defined(MT6218B))
            if ((!IS_FINE_RESIZE_BUSY) && (!IS_YUV2RGB_BUSY))
         #elif (defined(MT6217))
            if (!IS_YUV2RGB_BUSY)
         #endif
            {
               if (jpeg_decode_config_data.jpeg_decode_cb!=NULL)
                     jpeg_decode_config_data.jpeg_decode_cb(JPEG_DECODE_SUCCESS);
            }
            else
            {
               if (jpeg_decode_config_data.jpeg_decode_cb!=NULL)
                  jpeg_decode_config_data.jpeg_decode_cb(JPEG_DECODE_RESIZER_FAIL);
            }
         }
         else
         {
            if (jpeg_decode_config_data.jpeg_decode_cb!=NULL)
               jpeg_decode_config_data.jpeg_decode_cb(JPEG_DECODE_RESIZER_FAIL);
         }
      }
   }
   IRQUnmask(IRQ_RESZ_CODE);
}  /* resizer_HISR() */
#endif

/*************************************************************************
* FUNCTION
*     jpeg_codec_init
*
* DESCRIPTION
*     This function power on the jpeg decoder and resizer and init the stack timer
*     for jpeg deocder and resizer
*
* PARAMETERS
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void jpeg_codec_init(void)
{
#if (defined(DRV_JPG_HW_DEC_SUPPORT)||defined(DRV_JPG_HW_ENC_SUPPORT))
   if (jpeg_codec_event_id==NULL)
      jpeg_codec_event_id=kal_create_event_group("JPEG_EVT");

#if (defined(DRV_JPG_DEC_17_SERIES))
   IRQ_Register_LISR(IRQ_JPEG_CODE, jpeg_LISR,"JPEG codec ISR");
   IRQ_Register_LISR(IRQ_RESZ_CODE, resizer_LISR,"Resizer ISR");

   VISUAL_Register_HISR(VISUAL_JPEG_DEC_HISR_ID,jpeg_decoder_HISR);
   IRQUnmask(IRQ_JPEG_CODE);

   VISUAL_Register_HISR(VISUAL_RESIZER_HISR_ID,resizer_HISR);
   IRQSensitivity(IRQ_RESZ_CODE,LEVEL_SENSITIVE);
   IRQUnmask(IRQ_RESZ_CODE);

   jpeg_decoder_operation_state = JPEG_DECODER_STANDBY_STATE;
#endif

#if (defined(DRV_JPG_DEC_19_SERIES) || defined(DRV_JPG_ENC_19_SERIES))
   #if (defined(DRV_JPG_DEC_19_SERIES))
   jpeg_decoder_operation_state=JPEG_DECODER_STANDBY_STATE;
   VISUAL_Register_HISR(VISUAL_JPEG_DEC_HISR_ID,jpeg_decoder_HISR);
   VISUAL_Register_HISR(VISUAL_JPEG_DEC_CB_HISR_ID,jpeg_decode_cb_HISR);
   #endif

   #if (defined(DRV_JPG_ENC_19_SERIES))
   jpeg_encoder_operation_state=JPEG_ENCODER_STANDBY_STATE;
   VISUAL_Register_HISR(VISUAL_JPEG_ENC_HISR_ID,jpeg_encoder_HISR);
   #endif
   IRQ_Register_LISR(IRQ_JPEG_CODE, jpeg_LISR,"JPEG codec ISR");
   IRQUnmask(IRQ_JPEG_CODE);
#endif

#if (defined(DRV_JPG_DEC_28_SERIES))
   jpeg_decoder_operation_state=JPEG_DECODER_STANDBY_STATE;
   IRQ_Register_LISR(IRQ_JPEG_DEC_CODE, jpeg_dec_LISR,"JPEG decode ISR");
   VISUAL_Register_HISR(VISUAL_JPEG_DEC_HISR_ID,jpeg_decoder_HISR);
   VISUAL_Register_HISR(VISUAL_JPEG_DEC_CB_HISR_ID,jpeg_decode_cb_HISR);
   IRQUnmask(IRQ_JPEG_DEC_CODE);
#endif

#if (defined(DRV_JPG_ENC_28_SERIES))
   jpeg_encoder_operation_state=JPEG_ENCODER_STANDBY_STATE;
   IRQ_Register_LISR(IRQ_JPEG_ENC_CODE, jpeg_enc_LISR,"JPEG encode ISR");
   VISUAL_Register_HISR(VISUAL_JPEG_ENC_HISR_ID,jpeg_encoder_HISR);
   IRQUnmask(IRQ_JPEG_ENC_CODE);
#endif

#ifndef __MAUI_BASIC__
   if (jpeg_codec_sleep_mode_handler==0xFF)
      jpeg_codec_sleep_mode_handler = L1SM_GetHandle();
#endif /* __MAUI_BASIC__ */

#endif
}  /* jpeg_codec_init() */

kal_uint32 jpeg_decode_time_estimate(void)
{
#if (defined(DRV_JPG_HW_DEC_SUPPORT))
   kal_uint32 decode_time;

   #if (defined(DRV_JPG_DEC_28_SERIES))
   if (jpeg_file_para.jpg_progressive == KAL_TRUE)
   {
      decode_time = ((300 * jpeg_file_para.jpg_decode_width * jpeg_file_para.jpg_decode_height)/1000000 +
                     (jpeg_decode_config_data.jpeg_file_size /2000 + 10))* jpeg_file_para.progressive_decode_times;
   }
   else
   {
      decode_time = ((300 * jpeg_file_para.jpg_decode_width * jpeg_file_para.jpg_decode_height)/1000000 +
                     (jpeg_decode_config_data.jpeg_file_size /2000 + 10));
   }
#else
   if (jpeg_file_para.jpg_progressive==KAL_TRUE)
   {
      decode_time = ((1000 * jpeg_file_para.jpg_decode_width * jpeg_file_para.jpg_decode_height)/1000000 +
                     (jpeg_decode_config_data.jpeg_file_size /2000 + 10))* jpeg_file_para.progressive_decode_times;
   }
   else
   {
      decode_time = ((1000 * jpeg_file_para.jpg_decode_width * jpeg_file_para.jpg_decode_height)/1000000 +
                     (jpeg_decode_config_data.jpeg_file_size /2000 + 10));
   }
#endif
   if (decode_time<1000)
      decode_time=1000;
   return decode_time;
#else
   return -1;
#endif
}

/*************************************************************************
* FUNCTION
*     jpeg_codec_deinit
*
* DESCRIPTION
*     This function power down the jpeg codec and resizer (for MT6218B).
*
* PARAMETERS
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void jpeg_codec_deinit(void)
{
#if (defined(DRV_JPG_HW_DEC_SUPPORT))
   jpeg_decoder_operation_state = JPEG_DECODER_IDLE_STATE;
   #if(defined(DRV_JPG_DEC_17_SERIES))
   IRQMask(IRQ_JPEG_CODE);
   IRQMask(IRQ_RESZ_CODE);
   #elif(defined(DRV_JPG_DEC_19_SERIES))
   IRQMask(IRQ_JPEG_CODE);
   #elif(defined(DRV_JPG_DEC_28_SERIES))
   IRQMask(IRQ_JPEG_DEC_CODE);
   #endif
#endif

#if (defined(DRV_JPG_HW_ENC_SUPPORT))
   jpeg_encoder_operation_state=JPEG_ENCODER_IDLE_STATE;
   #if (defined(DRV_JPG_ENC_19_SERIES))
   IRQMask(IRQ_JPEG_CODE);
   #elif (defined(JPEG_DDRV_JPG_ENC_28_SERIESRV_V3))
   IRQMask(IRQ_JPEG_ENC_CODE);
#endif
#endif
}  /* jpeg_codec_deinit() */

/*************************************************************************
* FUNCTION
*     parse_exif
*
* DESCRIPTION
*     This function parse the EXIF in a JPEG file.
*
* PARAMETERS
*     jpeg_file_handle  the file handler of JPEG file, 0 stands for the
*                       JPEG stream is in buffer already.
*     jpg_file_ptr      the start address pointer for the parsed jpeg file
*     jpeg_file_offset  the EXIF data offset from the head of JPEG file or JPEG stream
*     exif_size         size of the EXIF data stream
*
* RETURNS
*     0           the EXIF data stream parsing success
*     not 0          the EXIF data stream parsing fail
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int32 parse_exif(kal_uint32 jpeg_file_handle, kal_uint8 *jpg_file_ptr, kal_uint32 jpeg_file_buffer_size,
                    kal_uint32 jpg_file_offset,kal_uint32 exif_size,kal_uint16 *exif_file_offset)
{
   kal_uint32 index,exif_offset;
   kal_uint32 fs_read_size;
   kal_uint8 endian_flag,num_of_required_tag,num_of_current_tag,num_of_parsed_tag=0;
   kal_uint16 num_of_ifd_tag, first_ifd_offset,tag_id,tag_value=0,tag_count,tag_type=0;

   if (jpeg_file_handle!=0)
   {
      index=0;
      jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpg_file_offset, FS_FILE_BEGIN);
      jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, 512, &fs_read_size);
   }
   else
   {
      index=jpg_file_offset;
   }
   exif_offset=jpg_file_offset;

   /* parse TIFF header */
   if ((jpg_file_ptr[index]==0x49) && (jpg_file_ptr[index+1]==0x49))
   {
      endian_flag=0; /* little endian */
      if ((jpg_file_ptr[index+2]!=0x2A)||(jpg_file_ptr[index+3]!=0x00))
         return -1;
      index+=((jpg_file_ptr[index+7]<<24)|(jpg_file_ptr[index+6]<<16)|(jpg_file_ptr[index+5]<<8)|
              jpg_file_ptr[index+4]);
   }
   else if ((jpg_file_ptr[index+0]==0x4D) && (jpg_file_ptr[index+1]==0x4D))
   {
      endian_flag=1; /* big endian */
      if ((jpg_file_ptr[index+3]!=0x2A)||(jpg_file_ptr[index+2]!=0x00))
         return -1;
      index+=((jpg_file_ptr[index+4]<<24)|(jpg_file_ptr[index+5]<<16)|(jpg_file_ptr[index+6]<<8)|
              jpg_file_ptr[index+7]);
   }
   else
      return -1;

   /* find the 1st IFD pointer */
   if (endian_flag==0)
   {
      num_of_ifd_tag=(jpg_file_ptr[index+1]<<8)|(jpg_file_ptr[index]);
      index+=(num_of_ifd_tag*12+2);
      first_ifd_offset = ((jpg_file_ptr[index+3]<<24)|(jpg_file_ptr[index+2]<<16)|(jpg_file_ptr[index+1]<<8)|
              jpg_file_ptr[index]);
   }
   else
   {
      num_of_ifd_tag=(jpg_file_ptr[index]<<8)|(jpg_file_ptr[index+1]);
      index+=(num_of_ifd_tag*12+2);
      first_ifd_offset=((jpg_file_ptr[index]<<24)|(jpg_file_ptr[index+1]<<16)|(jpg_file_ptr[index+2]<<8)|
              jpg_file_ptr[index+3]);
   }

   if (first_ifd_offset==0)
      return -1;

   index=exif_offset+first_ifd_offset;
   if (jpeg_file_handle!=0)
   {
      jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, index, FS_FILE_BEGIN);
      jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, 512, &fs_read_size);
      index=0;
   }

   if (endian_flag==0)
   {
      num_of_ifd_tag=(jpg_file_ptr[index+1]<<8)|(jpg_file_ptr[index]);
   }
   else
   {
      num_of_ifd_tag=(jpg_file_ptr[index]<<8)|(jpg_file_ptr[index+1]);
   }

   index+=2;
   num_of_required_tag=5;
   num_of_current_tag=0;

   do
   {
      if (endian_flag==0)
      {
         tag_id=(jpg_file_ptr[index+1]<<8)|(jpg_file_ptr[index]);
         tag_type=(jpg_file_ptr[index+3]<<8)|(jpg_file_ptr[index+2]);
         tag_count=((jpg_file_ptr[index+7]<<24)|(jpg_file_ptr[index+6]<<16)|
                    (jpg_file_ptr[index+5]<<8)|jpg_file_ptr[index+4]);
         if (tag_type==EXIF_TAG_TYPE_SHORT)
         {
            tag_value=(jpg_file_ptr[index+9]<<8)|(jpg_file_ptr[index+8]);
         }
         else if (tag_type==EXIF_TAG_TYPE_LONG)
         {
            tag_value=((jpg_file_ptr[index+11]<<24)|(jpg_file_ptr[index+10]<<16)|
                       (jpg_file_ptr[index+9]<<8)|jpg_file_ptr[index+8]);
         }
      }
      else
      {
         tag_id=(jpg_file_ptr[index]<<8)|(jpg_file_ptr[index+1]);
         tag_type=(jpg_file_ptr[index+2]<<8)|(jpg_file_ptr[index+3]);
         tag_count=((jpg_file_ptr[index+4]<<24)|(jpg_file_ptr[index+5]<<16)|
                    (jpg_file_ptr[index+6]<<8)|jpg_file_ptr[index+7]);
         if (tag_type==EXIF_TAG_TYPE_SHORT)
         {
            tag_value=(jpg_file_ptr[index+8]<<8)|(jpg_file_ptr[index+9]);
         }
         else if (tag_type==EXIF_TAG_TYPE_LONG)
         {
            tag_value=((jpg_file_ptr[index+8]<<24)|(jpg_file_ptr[index+9]<<16)|
                       (jpg_file_ptr[index+10]<<8)|jpg_file_ptr[index+11]);
         }
      }

      switch (tag_id)
      {
         case EXIF_TAG_COMPRESSION:
            if (tag_value==EXIF_JPEG_COMPRESSED)
            {
               num_of_required_tag=2;
               jpeg_thumb_para.jfif_mode= EXIF_MODE_JPEG;
            }
            num_of_current_tag++;
         break;
         case EXIF_TAG_IMAGE_WIDTH:
            jpeg_thumb_para.jpg_width=tag_value;
            num_of_current_tag++;
         break;
         case EXIF_TAG_IMAGE_HEIGHT:
            jpeg_thumb_para.jpg_height=tag_value;
            num_of_current_tag++;
         break;
         case EXIF_TAG_PIXEL_COMPOSITION:
            if (tag_value==EXIF_NON_COMPRESSED_RGB)
               jpeg_thumb_para.jfif_mode= EXIF_MODE_RGB;
            else  /* do not support YCbCr format thumbnail */
               return -1;
            num_of_current_tag++;
         break;
         case EXIF_TAG_STRIP_OFFSET:
         case EXIF_TAG_JPEG_SOI_OFFSET:
            *exif_file_offset=tag_value;
            num_of_current_tag++;
         break;
         default:
         break;
      }
      index+=12;
      num_of_parsed_tag++;
   }  while ((num_of_required_tag!=num_of_current_tag) && (num_of_ifd_tag>num_of_parsed_tag));

   if (num_of_required_tag==num_of_current_tag)
      return 0;
   else
      return -1;
}  /* parse_exif()*/

/*************************************************************************
* FUNCTION
*     parse_jpeg_thumbnail
*
* DESCRIPTION
*     This function parse the parameters of compressed type thumbnail of a JPEG file.
*
* PARAMETERS
*     jpeg_file_handle  the file handler of the parsed jpeg file
*     jpg_file_ptr      the start address pointer of the parsed jpeg file or
*                       the buffer pointer for temporary JPEG data buffer
*     jpeg_file_buffer_size    the size of the parsed jpeg file or JPEG data buffer
*     jpg_file_offset   the data offset from the beginning of the JPEG file.
*     thumbnail_size    the size of the thumbnail data
*
* RETURNS
*     0        if the compressed thumbnail data parse correctly.
*     not 0    if the compressed thumbnail data parse failed.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int32 parse_jpeg_thumbnail(kal_uint32 jpeg_file_handle, kal_uint8 *jpg_file_ptr, kal_uint32 jpeg_file_buffer_size,
                              kal_uint32 jpg_file_offset,kal_uint32 thumbnail_size)
{
   kal_uint8 byte,jpg_byte1,jpg_byte2;
   kal_uint32 index,index_offset;
   kal_uint16 marker_length;
   kal_uint32 jpeg_file_index=0;
   kal_uint32 fs_read_size;
   kal_uint8 i;
   kal_uint8 parse_end_flag=0;
   kal_uint32 huffman_q_table_size=0;
   kal_uint8 restart_marker_flag=0;
   index=0;

   if (jpeg_file_handle!=0)
   {
      jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpg_file_offset, FS_FILE_BEGIN);
      jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, 512, &fs_read_size);
   }else{
      index=jpg_file_offset;
   }

   jpg_byte1=jpg_file_ptr[index++];
   jpg_byte2=jpg_file_ptr[index++];
   jpeg_file_index=jpg_file_offset+2;

   jpeg_thumb_para.jpg_height=0xFFFF;
   jpeg_thumb_para.jpg_width=0xFFFF;
   jpeg_thumb_para.thumbnail_offset=0;
   jpeg_thumb_para.jpg_progressive=KAL_FALSE;

   if ((jpg_byte1==0xFF) && (jpg_byte2==0xD8))
   {
      do
      {
         if (jpeg_file_handle!=0)
         {
            if (jpeg_file_index>=(thumbnail_size+jpg_file_offset))
               break;
         }
         else
         {
            if (index>=jpeg_file_buffer_size)
               break;
         }

         do
         {
            byte=jpg_file_ptr[index++];
            if (jpeg_file_handle!=0)
            {
               jpeg_file_index++;
               if (index>=(fs_read_size-30))
               {
                  index=0;
                  jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, 512, &fs_read_size);
               }
            }
         } while (byte!=0xFF);
         jpg_byte1=0xFF;
         jpg_byte2=jpg_file_ptr[index++];

         if (jpeg_file_handle!=0)
         {
            jpeg_file_index++;
            if (index>=(fs_read_size-30))
            {
               index=0;
               jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, 512, &fs_read_size);
            }
         }
         switch (jpg_byte2)
         {
            case JPEG_MARKER_SOF0:
            case JPEG_MARKER_SOF2:
               if (jpg_byte2==JPEG_MARKER_SOF2)
               {
                  return -1;
               }
               marker_length=(jpg_file_ptr[index++]<<8);
               marker_length += (int) (jpg_file_ptr[index++]-2);
               jpeg_thumb_para.jpg_precision=jpg_file_ptr[index++];
               jpeg_thumb_para.jpg_height=(jpg_file_ptr[index++]<<8);
               jpeg_thumb_para.jpg_height|=jpg_file_ptr[index++];
               jpeg_thumb_para.jpg_width=(jpg_file_ptr[index++]<<8);
               jpeg_thumb_para.jpg_width|=jpg_file_ptr[index++];
               jpeg_thumb_para.number_of_component=jpg_file_ptr[index++];
               jpeg_thumb_para.component_id1=jpg_file_ptr[index++];
               jpeg_thumb_para.y_h_sample_factor=(jpg_file_ptr[index]&0xF0)>>4;
               jpeg_thumb_para.y_v_sample_factor=jpg_file_ptr[index++]&0x0F;
               jpeg_thumb_para.q_table_id1=jpg_file_ptr[index++];
               jpeg_file_index+=11;

               if (jpeg_thumb_para.number_of_component>=2)
               {
                  jpeg_thumb_para.component_id2=jpg_file_ptr[index++];
                  jpeg_thumb_para.u_h_sample_factor=(jpg_file_ptr[index]&0xF0)>>4;
                  jpeg_thumb_para.u_v_sample_factor=jpg_file_ptr[index++]&0x0F;
                  jpeg_thumb_para.q_table_id2=jpg_file_ptr[index++];
                  jpeg_file_index+=3;

                  if (jpeg_thumb_para.number_of_component>=3)
                  {
                     jpeg_thumb_para.component_id3=jpg_file_ptr[index++];
                     jpeg_thumb_para.v_h_sample_factor=(jpg_file_ptr[index]&0xF0)>>4;
                     jpeg_thumb_para.v_v_sample_factor=jpg_file_ptr[index++]&0x0F;
                     jpeg_thumb_para.q_table_id3=jpg_file_ptr[index++];
                     jpeg_file_index+=3;
                  }
                  else
                  {
                     jpeg_thumb_para.component_id3=0;
                     jpeg_thumb_para.v_h_sample_factor=0;
                     jpeg_thumb_para.v_v_sample_factor=0;
                     jpeg_thumb_para.q_table_id3=0;
                  }
               }
               else
               {
                  jpeg_thumb_para.component_id2=0;
                  jpeg_thumb_para.u_h_sample_factor=0;
                  jpeg_thumb_para.u_v_sample_factor=0;
                  jpeg_thumb_para.q_table_id2=0;
                  jpeg_thumb_para.component_id3=0;
                  jpeg_thumb_para.v_h_sample_factor=0;
                  jpeg_thumb_para.v_v_sample_factor=0;
                  jpeg_thumb_para.q_table_id3=0;
               }
               parse_end_flag|=0x01;
            break;
            case JPEG_MARKER_SOS:
               jpg_byte2=0xD9;
            break;
            case 0xC8:
            case 0x00:
            break;
            case JPEG_MARKER_DQT:
            case JPEG_MARKER_DHT:
               if (jpeg_thumb_para.thumbnail_offset==0)  /* set thumbnail_offset when first time met DQT or DHT */
               {
                  if (jpeg_file_handle!=0) /*for two mode input(file and buffer)*/
                  jpeg_thumb_para.thumbnail_offset=jpeg_file_index-jpg_file_offset-2;
                  else
                  jpeg_thumb_para.thumbnail_offset=index-jpg_file_offset-2;
               }


               index_offset=(jpg_file_ptr[index++]<<8);
               index_offset += (int) (jpg_file_ptr[index++]-2);
               huffman_q_table_size+=index_offset;
               index+=index_offset;
               if (jpeg_file_handle!=0)
               {
                  jpeg_file_index+=(index_offset+2);
               }
               if (jpg_byte2==JPEG_MARKER_DQT)
                  parse_end_flag|=0x02;
               else
                  parse_end_flag|=0x04;
               /* make sure DQT,DHT and SOF are read or table size overflow*/
               if (huffman_q_table_size>=0x800)
                  jpg_byte2=0xD9;
            break;
            default:
               if ((jpg_byte2==JPEG_MARKER_SOF1) || (jpg_byte2==JPEG_MARKER_DNL)||
                  ((jpg_byte2>=JPEG_MARKER_SOF3) && (jpg_byte2<=JPEG_MARKER_SOF15))||
                  (jpg_byte2==JPEG_MARKER_DRI) || (jpg_byte2==JPEG_MARKER_DHP) ||
                  (jpg_byte2==JPEG_MARKER_EXP) || (jpg_byte2==JPEG_MARKER_COM) ||
                  ((jpg_byte2>=JPEG_MARKER_APP0) && (jpg_byte2<=JPEG_MARKER_APP15)))
               {
                  index_offset=(jpg_file_ptr[index++]<<8);
                  index_offset += (int) (jpg_file_ptr[index++]-2);
                  index+=index_offset;
                  if (jpeg_file_handle!=0)
                  {
                     jpeg_file_index+=(index_offset+2);
                     if (index>=(fs_read_size-30))
                     {
                        index=0;

                        jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_index, FS_FILE_BEGIN);
                        jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, 512, &fs_read_size);
                     }
                  }
                  if (jpg_byte2==JPEG_MARKER_DRI)
                     restart_marker_flag=1;
               }
            break;
         }
      } while (!((jpg_byte1==0xFF) && (jpg_byte2==0xD9)));
   }
   else
      return -1;

   if ((jpeg_thumb_para.y_h_sample_factor * jpeg_thumb_para.y_v_sample_factor +
        jpeg_thumb_para.u_h_sample_factor * jpeg_thumb_para.u_v_sample_factor +
        jpeg_thumb_para.v_h_sample_factor * jpeg_thumb_para.v_v_sample_factor)>10)
   {
      return -1;
   }

   if (jpeg_file_handle!=0)
   {
      jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, (thumbnail_size+jpg_file_offset-20),FS_FILE_BEGIN);
      jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr,20, &fs_read_size);
      for (i=1;i<20;i++)
      {
         jpg_byte2=jpg_file_ptr[fs_read_size-i];
         if (jpg_byte2==0xD9)
         {
            jpg_byte1=jpg_file_ptr[fs_read_size-i-1];
            if (jpg_byte1==0xFF)
               break;
         }
      }
      if (i==20)
         jpeg_file_without_eoi=KAL_TRUE;
      else
         jpeg_file_without_eoi=KAL_FALSE;
   }
   else
   {
      for (i=1;i<20;i++)
      {
         jpg_byte2=jpg_file_ptr[thumbnail_size+jpg_file_offset-i];
         if (jpg_byte2==0xD9)
         {
            jpg_byte1=jpg_file_ptr[thumbnail_size+jpg_file_offset-i-1];
            if (jpg_byte1==0xFF)
               break;
         }
      }
      if (i==20)
         jpeg_file_without_eoi=KAL_TRUE;
      else
         jpeg_file_without_eoi=KAL_FALSE;
   }

   if ((huffman_q_table_size>=0x800)||(parse_end_flag!=0x07))
   {
      return -1;
   }
#if (defined(MT6219)||defined(MT6217)) /* hardware issue */
   if ((restart_marker_flag==1) && (jpeg_thumb_para.y_h_sample_factor==1)&&
       (jpeg_thumb_para.y_v_sample_factor==1)&&(jpeg_thumb_para.u_h_sample_factor==0)&&
       (jpeg_thumb_para.u_v_sample_factor==0)&&(jpeg_thumb_para.v_h_sample_factor==0)&&
       (jpeg_thumb_para.v_v_sample_factor==0))
      return -1;
#endif

   if (jpeg_thumb_para.y_h_sample_factor>jpeg_thumb_para.u_h_sample_factor)
   {
      if (jpeg_thumb_para.y_h_sample_factor > jpeg_thumb_para.v_h_sample_factor)
         jpeg_thumb_para.max_h_sample_factor=jpeg_thumb_para.y_h_sample_factor;
      else
         jpeg_thumb_para.max_h_sample_factor=jpeg_thumb_para.v_h_sample_factor;
   }
   else
   {
      if (jpeg_thumb_para.u_h_sample_factor > jpeg_thumb_para.v_h_sample_factor)
         jpeg_thumb_para.max_h_sample_factor=jpeg_thumb_para.u_h_sample_factor;
      else
         jpeg_thumb_para.max_h_sample_factor=jpeg_thumb_para.v_h_sample_factor;
   }

   if (jpeg_thumb_para.y_v_sample_factor>jpeg_thumb_para.u_v_sample_factor)
   {
      if (jpeg_thumb_para.y_v_sample_factor > jpeg_thumb_para.v_v_sample_factor)
         jpeg_thumb_para.max_v_sample_factor=jpeg_thumb_para.y_v_sample_factor;
      else
         jpeg_thumb_para.max_v_sample_factor=jpeg_thumb_para.v_v_sample_factor;
   }
   else
   {
      if (jpeg_thumb_para.u_v_sample_factor > jpeg_thumb_para.v_v_sample_factor)
         jpeg_thumb_para.max_v_sample_factor=jpeg_thumb_para.u_v_sample_factor;
      else
         jpeg_thumb_para.max_v_sample_factor=jpeg_thumb_para.v_v_sample_factor;
   }

   if (jpeg_thumb_para.y_h_sample_factor==1)
   {
      if (jpeg_thumb_para.jpg_width & 0x07)
         jpeg_thumb_para.jpg_decode_width=((jpeg_thumb_para.jpg_width+8)>>3)<<3;
      else
         jpeg_thumb_para.jpg_decode_width=jpeg_thumb_para.jpg_width;
   }
   else if (jpeg_thumb_para.y_h_sample_factor==2)
   {
      if (jpeg_thumb_para.jpg_width & 0x0F)
         jpeg_thumb_para.jpg_decode_width=((jpeg_thumb_para.jpg_width+16)>>4)<<4;
      else
         jpeg_thumb_para.jpg_decode_width=jpeg_thumb_para.jpg_width;
   }
   else if (jpeg_thumb_para.y_h_sample_factor==4)
   {
      if (jpeg_thumb_para.jpg_width & 0x1F)
         jpeg_thumb_para.jpg_decode_width=((jpeg_thumb_para.jpg_width+32)>>5)<<5;
      else
         jpeg_thumb_para.jpg_decode_width=jpeg_thumb_para.jpg_width;
   }

   if (jpeg_thumb_para.y_v_sample_factor==1)
   {
      if (jpeg_thumb_para.jpg_height & 0x07)
         jpeg_thumb_para.jpg_decode_height=((jpeg_thumb_para.jpg_height+8)>>3)<<3;
      else
         jpeg_thumb_para.jpg_decode_height=jpeg_thumb_para.jpg_height;
   }
   else if (jpeg_thumb_para.y_v_sample_factor==2)
   {
      if (jpeg_thumb_para.jpg_height & 0x0F)
         jpeg_thumb_para.jpg_decode_height=((jpeg_thumb_para.jpg_height+16)>>4)<<4;
      else
         jpeg_thumb_para.jpg_decode_height=jpeg_thumb_para.jpg_height;
   }
   else if (jpeg_thumb_para.y_v_sample_factor==4)
   {
      if (jpeg_thumb_para.jpg_height & 0x1F)
         jpeg_thumb_para.jpg_decode_height=((jpeg_thumb_para.jpg_height+32)>>5)<<5;
      else
         jpeg_thumb_para.jpg_decode_height=jpeg_thumb_para.jpg_height;
   }

   return 0;
}  /* parse_jpeg_thumbnail() */

/*************************************************************************
* FUNCTION
*     parse_jpeg_file
*
* DESCRIPTION
*     This function parse the JPEG file parameters of a JPEG file.
*
* PARAMETERS
*     jpeg_file_handle  the file handler of the parsed jpeg file
*     jpg_file_ptr      the start address pointer of the parsed jpeg file or
*                       the buffer pointer for temporary JPEG data buffer
*     jpeg_file_buffer_size    the size of the parsed jpeg file or JPEG data buffer
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int32 parse_jpeg_file(kal_uint32 jpeg_file_handle, kal_uint8 *jpg_file_ptr,
                     kal_uint32 jpeg_file_buffer_size)
{
   kal_uint8 byte,jpg_byte1,jpg_byte2;
   kal_uint32 index,index_offset,index_temp;
   kal_uint16 thumbnail_size, exif_size,exif_offset;
   kal_uint16 marker_length;
   kal_uint32 jpeg_file_index=0;
   kal_uint32 jpeg_file_size;
   kal_uint32 fs_read_size;
   kal_uint8 i;
   kal_uint8 parse_end_flag=0;
   kal_uint32 huffman_q_table_size=0;
   kal_uint8 restart_marker_flag=0;

   /* Used to check SOS marker*/
   kal_uint8 sos_num_of_comp=0;

   index=0;
   if (jpeg_file_handle!=0)
   {
      DRM_file_size((FS_HANDLE) jpeg_file_handle, &jpeg_file_size);
      jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, 0, FS_FILE_BEGIN);
      jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, 512, &fs_read_size);
      jpeg_file_index+=2;
   }

   jpeg_file_para.jpg_height=0xFFFF;
   jpeg_file_para.jpg_width=0xFFFF;
   jpeg_file_para.thumbnail_offset=0xffffffff;
   jpeg_file_para.jfif_mode=NO_THUMBNAIL_MODE;
   jpeg_file_para.jpg_progressive=KAL_FALSE;

   jpeg_thumb_para.jfif_mode=NO_THUMBNAIL_MODE;

   jpg_byte1=jpg_file_ptr[index++];
   jpg_byte2=jpg_file_ptr[index++];

   if (jpeg_file_handle!=0)
   {
      if ((jpg_byte1!=0xFF) || (jpg_byte2!=0xD8))
         return 0;
   }
   else
      index-=2;
// if ((jpg_byte1==0xFF) && (jpg_byte2==0xD8))
   {
      do
      {
         if (jpeg_file_handle!=0)
         {
            if (jpeg_file_index>=jpeg_file_size)
            break;
         }
         else
         {
            if (index>=jpeg_file_buffer_size)
               break;
         }

         do
         {
            byte=jpg_file_ptr[index++];
            if (jpeg_file_handle!=0)
            {
               jpeg_file_index++;
               if (jpeg_file_index>=jpeg_file_size)
               break;
               if (index>=(fs_read_size-30))
               {
                  index=0;
                  jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_index, FS_FILE_BEGIN);
                  jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, 512, &fs_read_size);
               }
            }else{
               if (index>=jpeg_file_buffer_size)
                  break;
            }
         } while (byte!=0xFF);
         if (byte!=0xFF)
            break;
         jpg_byte1=0xFF;
         do
         {
            jpg_byte2=jpg_file_ptr[index++];

            if (jpeg_file_handle!=0)
            {
               jpeg_file_index++;
               if (jpeg_file_index>=jpeg_file_size)
               break;
               if (index>=(fs_read_size-30))
               {
                  index=0;
                  jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_index, FS_FILE_BEGIN);
                  jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, 512, &fs_read_size);
               }
            }else{
               if (index>=jpeg_file_buffer_size)
               break;
            }
         } while (jpg_byte2==0xFF);
         if (jpg_byte2==0xFF)
            break;
         switch (jpg_byte2)
         {
            case JPEG_MARKER_SOF0:
            case JPEG_MARKER_SOF2:
               if (jpg_byte2==JPEG_MARKER_SOF2)
               {
                  jpeg_file_para.jpg_progressive=KAL_TRUE;
               }
               if (jpeg_file_handle!=0)
               {
//                index=0;
//                jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_index, FS_FILE_BEGIN);
//                jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, 512, &fs_read_size);
               }

               marker_length=(jpg_file_ptr[index++]<<8);
               marker_length += (int) (jpg_file_ptr[index++]-2);
               jpeg_file_para.jpg_precision=jpg_file_ptr[index++];
               jpeg_file_para.jpg_height=(jpg_file_ptr[index++]<<8);
               jpeg_file_para.jpg_height|=jpg_file_ptr[index++];
               jpeg_file_para.jpg_width=(jpg_file_ptr[index++]<<8);
               jpeg_file_para.jpg_width|=jpg_file_ptr[index++];
               jpeg_file_para.number_of_component=jpg_file_ptr[index++];
               jpeg_file_para.component_id1=jpg_file_ptr[index++];
               jpeg_file_para.y_h_sample_factor=(jpg_file_ptr[index]&0xF0)>>4;
               jpeg_file_para.y_v_sample_factor=jpg_file_ptr[index++]&0x0F;
               jpeg_file_para.q_table_id1=jpg_file_ptr[index++];
               jpeg_file_index+=11;

               if (jpeg_file_para.number_of_component>=2)
               {
                  jpeg_file_para.component_id2=jpg_file_ptr[index++];
                  jpeg_file_para.u_h_sample_factor=(jpg_file_ptr[index]&0xF0)>>4;
                  jpeg_file_para.u_v_sample_factor=jpg_file_ptr[index++]&0x0F;
                  jpeg_file_para.q_table_id2=jpg_file_ptr[index++];
                  jpeg_file_index+=3;

                  if (jpeg_file_para.number_of_component>=3)
                  {
                     jpeg_file_para.component_id3=jpg_file_ptr[index++];
                     jpeg_file_para.v_h_sample_factor=(jpg_file_ptr[index]&0xF0)>>4;
                     jpeg_file_para.v_v_sample_factor=jpg_file_ptr[index++]&0x0F;
                     jpeg_file_para.q_table_id3=jpg_file_ptr[index++];
                     jpeg_file_index+=3;
                  }
                  else
                  {
                     jpeg_file_para.component_id3=0;
                     jpeg_file_para.v_h_sample_factor=0;
                     jpeg_file_para.v_v_sample_factor=0;
                     jpeg_file_para.q_table_id3=0;
                  }
               }
               else
               {
                  jpeg_file_para.component_id2=0;
                  jpeg_file_para.u_h_sample_factor=0;
                  jpeg_file_para.u_v_sample_factor=0;
                  jpeg_file_para.q_table_id2=0;
                  jpeg_file_para.component_id3=0;
                  jpeg_file_para.v_h_sample_factor=0;
                  jpeg_file_para.v_v_sample_factor=0;
                  jpeg_file_para.q_table_id3=0;
               }
               parse_end_flag|=0x01;

            break;
            case JPEG_MARKER_SOS:
            sos_num_of_comp=jpg_file_ptr[index+2];

               jpg_byte2=0xD9;
            break;
            case 0xC8:
            case 0x00:
            break;
            case JPEG_MARKER_DRI:
               if (jpeg_file_para.thumbnail_offset==0)
               {
                  if(jpeg_file_handle!=0)
                  jpeg_file_para.thumbnail_offset=jpeg_file_index-2;
                  else
                  jpeg_file_para.thumbnail_offset=index-2;
               }
               if (jpg_byte2==JPEG_MARKER_DRI)
                  restart_marker_flag=1;
            break;
            case JPEG_MARKER_DQT:
            case JPEG_MARKER_DHT:
               if (jpeg_file_para.thumbnail_offset==0xffffffff)
               {
                if(jpeg_file_handle!=0)
                  jpeg_file_para.thumbnail_offset=jpeg_file_index-2;
                else
                 jpeg_file_para.thumbnail_offset=index-2;
               }

               index_offset=(jpg_file_ptr[index++]<<8);
               index_offset += (int) (jpg_file_ptr[index++]-2);
               huffman_q_table_size+=index_offset;
               index+=index_offset;
               if (jpeg_file_handle!=0)
               {
                  jpeg_file_index+=(index_offset+2);
                  index=0;
                  jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_index, FS_FILE_BEGIN);
                  jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, 512, &fs_read_size);
               }
               if (jpg_byte2==JPEG_MARKER_DQT)
                  parse_end_flag|=0x02;
               else
                  parse_end_flag|=0x04;
               /* make sure DQT,DHT and SOF are read or table size overflow*/
               if (huffman_q_table_size>=0x800)
                  jpg_byte2=0xD9;
            break;
            case JPEG_MARKER_APP0:
               if (jpeg_thumbnail_mode==KAL_TRUE && jpeg_thumb_para.jfif_mode== NO_THUMBNAIL_MODE)
               {
                   index_temp = index;
                  // keep the buffer index for restore it. this is because the original version
                  // disable input way in memory buffer.
                  //if (jpeg_file_handle!=0)
                  {
                     thumbnail_size=(jpg_file_ptr[index++]<<8);
                     thumbnail_size += (int) (jpg_file_ptr[index++]-2);

                     /* check JFIF ID */
                     if ((jpg_file_ptr[index]=='J') && (jpg_file_ptr[index+1]=='F') &&
                         (jpg_file_ptr[index+2]=='I') && (jpg_file_ptr[index+3]=='F') &&
                         (jpg_file_ptr[index+4]==0))
                     {  /* JFIF format */
                     #if (defined(DRV_RGB_RESIZE_SUPPORT))
                        index+=12;
                        jpeg_thumb_para.jpg_width=jpg_file_ptr[index++];
                        jpeg_thumb_para.jpg_height=jpg_file_ptr[index++];
                        if ((jpeg_thumb_para.jpg_width!=0)&&(jpeg_thumb_para.jpg_height!=0))
                        {
                           if(jpeg_file_handle!=0)
                           jpeg_thumb_para.thumbnail_offset=jpeg_file_index+16;
                           else
                           jpeg_thumb_para.thumbnail_offset=index;
                           jpeg_thumb_para.thumbnail_size=jpeg_thumb_para.jpg_width * jpeg_thumb_para.jpg_height*3;
                           //jpeg_file_index+=16;
                           jpeg_thumb_para.jfif_mode= JFIF_MODE_RGB;
                           //return ;
                        }
                     #endif
                     }
                     else if ((jpg_file_ptr[index]=='J') && (jpg_file_ptr[index+1]=='F') &&
                              (jpg_file_ptr[index+2]=='X') && (jpg_file_ptr[index+3]=='X') &&
                              (jpg_file_ptr[index+4]==0))
                     {  /* JFIF extension */
                        index+=5;
                        if (jpg_file_ptr[index]==0x13)
                        {
                        #if (defined(DRV_RGB_RESIZE_SUPPORT))
                           index++;
                           jpeg_thumb_para.jpg_width=jpg_file_ptr[index++];
                           jpeg_thumb_para.jpg_height=jpg_file_ptr[index++];
                           if ((jpeg_thumb_para.jpg_width!=0)&&(jpeg_thumb_para.jpg_height!=0))
                           {
                              //jpeg_file_index+=10;
                              jpeg_thumb_para.jfif_mode= JFIF_EXTENSION_MODE_RGB;
                              if(jpeg_file_handle != 0)
                              jpeg_thumb_para.thumbnail_offset=jpeg_file_index+10;
                              else
                              jpeg_thumb_para.thumbnail_offset = index;
                              jpeg_thumb_para.thumbnail_size=jpeg_thumb_para.jpg_width * jpeg_thumb_para.jpg_height*3;
                              //return;
                           }
                        #endif
                        }
                        else if (jpg_file_ptr[index]==0x10)
                        {
                           kal_uint32 real_index=0;
                           // real_index keep the information that jpeg_file index or memory buffer
                           index++;
                           //jpeg_file_index+=8;
                           if(jpeg_file_handle!=0)
                              real_index = jpeg_file_index+8;
                           else
                              real_index = index;
                           if (parse_jpeg_thumbnail(jpeg_file_handle,jpg_file_ptr, jpeg_file_buffer_size,
                                                    real_index,(thumbnail_size-6))==0)
                           {
                              jpeg_thumb_para.jfif_mode= JFIF_EXTENSION_MODE_JPEG;
                              jpeg_thumb_para.thumbnail_size=thumbnail_size-6;
                              jpeg_thumb_para.thumbnail_offset+=(real_index);

                              //return ;
                           }
                           else
                           {
                              //jpeg_file_index-=8;
                              jpeg_thumb_para.jfif_mode= NO_THUMBNAIL_MODE;
                           }
                        }
                     }
                  }
                  if (jpeg_file_handle == 0)
                  index = index_temp;
               }
               //if (jpeg_thumbnail_mode==KAL_TRUE)
               //{
                  if (jpeg_file_handle!=0)
                  {
                     index=0;
                     jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_index, FS_FILE_BEGIN);
                     jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, 512, &fs_read_size);
                  }
               //}

               index_offset=(jpg_file_ptr[index++]<<8);
               index_offset += (int) (jpg_file_ptr[index++]-2);
               index+=index_offset;

               if (jpeg_file_handle!=0)
               {
                  jpeg_file_index+=(index_offset+2);
                  if (index>=(fs_read_size-30))
                  {
                     index=0;
                     jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_index, FS_FILE_BEGIN);
                     jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, 512, &fs_read_size);
                  }
               }
            break;
            case JPEG_MARKER_APP1:  /* Exif format */
               index_temp=index;
               if (jpeg_thumbnail_mode==KAL_TRUE && jpeg_thumb_para.jfif_mode== NO_THUMBNAIL_MODE)
               {
                  exif_size=(jpg_file_ptr[index_temp++]<<8);
                  exif_size += (int) (jpg_file_ptr[index_temp++]-2);

                  /* check JFIF ID */
                  if ((jpg_file_ptr[index_temp++]=='E') && (jpg_file_ptr[index_temp++]=='x') &&
                      (jpg_file_ptr[index_temp++]=='i') && (jpg_file_ptr[index_temp++]=='f') &&
                      (jpg_file_ptr[index_temp++]==0) && (jpg_file_ptr[index_temp++]==0))
                  {  /* Exif format */
                     kal_uint32 real_index=0;
                     if (jpeg_file_handle!=0)
                        real_index = jpeg_file_index+8;
                     else
                        real_index = index_temp;
                     // real_index keep the information that jpeg_file index or memory buffer
                     //  index. There are two input ways that file_handle or buffer in jpeg.
                     //jpeg_file_index+=8;
                     if (parse_exif(jpeg_file_handle,jpg_file_ptr,jpeg_file_buffer_size,
                                    real_index,exif_size,&exif_offset)==0)
                     {
                        //jpeg_file_index+=exif_offset;
                        if (jpeg_thumb_para.jfif_mode==EXIF_MODE_JPEG)
                        {
                           if (parse_jpeg_thumbnail(jpeg_file_handle,jpg_file_ptr, jpeg_file_buffer_size,
                                                    real_index+exif_offset,(exif_size-exif_offset))==0)
                           {
                              jpeg_thumb_para.thumbnail_size=exif_size-jpeg_thumb_para.thumbnail_offset-exif_offset-6;
                              jpeg_thumb_para.thumbnail_offset+=(real_index+exif_offset);
                              //return ;
                           }
                           else
                            jpeg_thumb_para.jfif_mode= NO_THUMBNAIL_MODE;
                        }
                        else if (jpeg_thumb_para.jfif_mode==EXIF_MODE_RGB)
                        {
                           jpeg_thumb_para.thumbnail_offset=real_index+exif_offset;
                           jpeg_thumb_para.thumbnail_size=jpeg_thumb_para.jpg_width * jpeg_thumb_para.jpg_height*3;
                           //return ;
                        }
                        else
                         jpeg_thumb_para.jfif_mode= NO_THUMBNAIL_MODE;
                           //jpeg_file_index-=(8+exif_offset);
                     }
                     else
                      jpeg_thumb_para.jfif_mode= NO_THUMBNAIL_MODE;
                        //jpeg_file_index-=8;
                  }
               }

               //if (jpeg_thumbnail_mode==KAL_TRUE)
               //{
                  if (jpeg_file_handle!=0)
                  {
                     index=0;
                     jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_index, FS_FILE_BEGIN);
                     jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, 512, &fs_read_size);
                  }
               //}

               index_offset=(jpg_file_ptr[index++]<<8);
               index_offset += (int) (jpg_file_ptr[index++]-2);
               index+=index_offset; //Move index out of APP1

               if (jpeg_file_handle!=0)
               {
                  jpeg_file_index+=(index_offset+2);
                  if (index>=(fs_read_size-30))
                  {
                     index=0;
                     jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_index, FS_FILE_BEGIN);
                     jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, 512, &fs_read_size);
                  }
               }
            break;
            default:
               if ((jpg_byte2==JPEG_MARKER_SOF1) || (jpg_byte2==JPEG_MARKER_DNL)||
                  ((jpg_byte2>=JPEG_MARKER_SOF3) && (jpg_byte2<=JPEG_MARKER_SOF15))||
                  (jpg_byte2==JPEG_MARKER_DHP) ||
                  (jpg_byte2==JPEG_MARKER_EXP) || (jpg_byte2==JPEG_MARKER_COM) ||
                  ((jpg_byte2>=JPEG_MARKER_APP2) && (jpg_byte2<=JPEG_MARKER_APP15)))
               {
                  index_offset=(jpg_file_ptr[index++]<<8);
                  index_offset += (int) (jpg_file_ptr[index++]-2);
                  index+=index_offset;
                  if (jpeg_file_handle!=0)
                  {
                     jpeg_file_index+=(index_offset+2);
                     if (index>=(fs_read_size-30))
                     {
                        index=0;
                        jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_index, FS_FILE_BEGIN);
                        jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, 512, &fs_read_size);
                     }
                  }
               }
            break;
         }
      } while (!((jpg_byte1==0xFF) && (jpg_byte2==0xD9)));
   }
// else
// {
//    jpeg_file_para.jpg_height=0xFFFF;
//    jpeg_file_para.jpg_width=0xFFFF;
//    return;
// }

   /* Check the consistency between thmbnail and origonal image */

#if (defined(DRV_RGB_RESIZE_SUPPORT))
   if(jpeg_thumb_para.jfif_mode==JFIF_MODE_RGB ||
      jpeg_thumb_para.jfif_mode==JFIF_EXTENSION_MODE_RGB ||
      jpeg_thumb_para.jfif_mode==EXIF_MODE_RGB)
   {
    //for skip the case when jpeg_file_buffer_size != thumbnail_size
    if(jpeg_decode_config_data.jpeg_file_buffer_size<jpeg_file_para.thumbnail_size)
    {
      jpeg_thumb_para.jfif_mode = NO_THUMBNAIL_MODE;
    }else
    // Image orientation test
    if((jpeg_file_para.jpg_width>jpeg_file_para.jpg_height && jpeg_thumb_para.jpg_width>jpeg_thumb_para.jpg_height) ||
       (jpeg_file_para.jpg_width<=jpeg_file_para.jpg_height && jpeg_thumb_para.jpg_width<=jpeg_thumb_para.jpg_height))
    {
     jpeg_file_para.thumbnail_offset=jpeg_thumb_para.thumbnail_offset;
     jpeg_file_para.thumbnail_size=jpeg_thumb_para.thumbnail_size;
     jpeg_file_para.jpg_width=jpeg_thumb_para.jpg_width;
     jpeg_file_para.jpg_height=jpeg_thumb_para.jpg_height;
     jpeg_file_para.jfif_mode=jpeg_thumb_para.jfif_mode;

     return 0;
    }
   }
   else
#endif
    if(jpeg_thumb_para.jfif_mode==JFIF_EXTENSION_MODE_JPEG ||
      jpeg_thumb_para.jfif_mode==EXIF_MODE_JPEG)
   {
    // Image orientation test
    if((jpeg_file_para.jpg_width>jpeg_file_para.jpg_height && jpeg_thumb_para.jpg_width>jpeg_thumb_para.jpg_height) ||
       (jpeg_file_para.jpg_width<=jpeg_file_para.jpg_height && jpeg_thumb_para.jpg_width<=jpeg_thumb_para.jpg_height))
    {
   jpeg_file_para.jpg_progressive=jpeg_thumb_para.jpg_progressive;
   jpeg_file_para.jpg_width=jpeg_thumb_para.jpg_width;
   jpeg_file_para.jpg_height=jpeg_thumb_para.jpg_height;
   jpeg_file_para.jpg_decode_width=jpeg_thumb_para.jpg_decode_width;
   jpeg_file_para.jpg_decode_height=jpeg_thumb_para.jpg_decode_height;
   jpeg_file_para.jpg_precision=jpeg_thumb_para.jpg_precision;
   jpeg_file_para.number_of_component=jpeg_thumb_para.number_of_component;
   jpeg_file_para.y_h_sample_factor=jpeg_thumb_para.y_h_sample_factor;
   jpeg_file_para.y_v_sample_factor=jpeg_thumb_para.y_v_sample_factor;
   jpeg_file_para.u_h_sample_factor=jpeg_thumb_para.u_h_sample_factor;
   jpeg_file_para.u_v_sample_factor=jpeg_thumb_para.u_v_sample_factor;
   jpeg_file_para.v_h_sample_factor=jpeg_thumb_para.v_h_sample_factor;
   jpeg_file_para.v_v_sample_factor=jpeg_thumb_para.v_v_sample_factor;
   jpeg_file_para.max_h_sample_factor=jpeg_thumb_para.max_h_sample_factor;
   jpeg_file_para.max_v_sample_factor=jpeg_thumb_para.max_v_sample_factor;
   jpeg_file_para.component_id1=jpeg_thumb_para.component_id1;
   jpeg_file_para.component_id2=jpeg_thumb_para.component_id2;
   jpeg_file_para.component_id3=jpeg_thumb_para.component_id3;
   jpeg_file_para.q_table_id1=jpeg_thumb_para.q_table_id1;
   jpeg_file_para.q_table_id2=jpeg_thumb_para.q_table_id2;
   jpeg_file_para.q_table_id3=jpeg_thumb_para.q_table_id3;
   //jpeg_file_para.progressive_decode_times=jpeg_thumb_para.progressive_decode_times;
   //jpeg_file_para.interleave_mcu_increament_index=jpeg_thumb_para.interleave_mcu_increament_index;
   //jpeg_file_para.non_interleav_mcu_increament_index_y=jpeg_thumb_para.non_interleav_mcu_increament_index_y;
   //jpeg_file_para.non_interleav_mcu_increament_index_u=jpeg_thumb_para.non_interleav_mcu_increament_index_u;
   //jpeg_file_para.non_interleav_mcu_increament_index_v=jpeg_thumb_para.non_interleav_mcu_increament_index_v;
   jpeg_file_para.thumbnail_offset=jpeg_thumb_para.thumbnail_offset;
   //jpeg_file_para.jpeg_decoder_ctrl_reg=jpeg_thumb_para.jpeg_decoder_ctrl_reg;
   jpeg_file_para.reset_jpeg_file_size=jpeg_thumb_para.reset_jpeg_file_size;
   jpeg_file_para.jfif_mode=jpeg_thumb_para.jfif_mode;
   jpeg_file_para.thumbnail_size=jpeg_thumb_para.thumbnail_size;

     return 0;
   }


   }

   /* Spec. definition */
   if (jpeg_file_para.number_of_component == 1) {
      jpeg_file_para.y_v_sample_factor = 1;
      jpeg_file_para.y_h_sample_factor = 1;
   }
   /* currently don't support CMYK format */
   if (jpeg_file_para.number_of_component == 4) {
      jpeg_file_para.jpg_height = 0xFFFF;
      jpeg_file_para.jpg_width = 0xFFFF;
      return 0;
   }

   /* Check SOS header */
   if(sos_num_of_comp > jpeg_file_para.number_of_component) {
      jpeg_file_para.jpg_height=0xFFFF;
      jpeg_file_para.jpg_width=0xFFFF;
      return 0;
   }

   if ((jpeg_file_para.jpg_progressive == KAL_TRUE)&& (jpeg_file_para.y_v_sample_factor == 4)) {
      jpeg_file_para.jpg_height = 0xFFFF;
      jpeg_file_para.jpg_width = 0xFFFF;
      return 0;
   }

   if ((jpeg_file_para.y_h_sample_factor * jpeg_file_para.y_v_sample_factor +
        jpeg_file_para.u_h_sample_factor * jpeg_file_para.u_v_sample_factor +
        jpeg_file_para.v_h_sample_factor * jpeg_file_para.v_v_sample_factor) > 10) {
      jpeg_file_para.jpg_height = 0xFFFF;
      jpeg_file_para.jpg_width = 0xFFFF;
      return 0;
   }

   if (jpeg_file_handle) {
      jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, (jpeg_file_size-100),FS_FILE_BEGIN);
      jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr,100, &fs_read_size);

      for (i = 1; i < 100; i++) {
         jpg_byte2 = jpg_file_ptr[fs_read_size - i];
         if (jpg_byte2 == 0xD9) {
            jpg_byte1 = jpg_file_ptr[fs_read_size - i - 1];
            if (jpg_byte1 == 0xFF) {
               break;
            }
         }
      }
      if (i == 100) {
         jpeg_file_without_eoi = KAL_TRUE;
      } else {
         jpeg_file_without_eoi = KAL_FALSE;
      }
   } else {
      for (i = 1; i < 100; i++) {
         jpg_byte2 = jpg_file_ptr[jpeg_file_buffer_size - i];
         if (jpg_byte2 == 0xD9) {
            jpg_byte1 = jpg_file_ptr[jpeg_file_buffer_size - i - 1];
            if (jpg_byte1 == 0xFF) {
               break;
            }
         }
      }
      if (i == 100) {
         jpeg_file_without_eoi = KAL_TRUE;
      } else {
         jpeg_file_without_eoi = KAL_FALSE;
      }
   }

   if ((huffman_q_table_size>=0x800)||(parse_end_flag!=0x07))
   {
      jpeg_file_para.jpg_height=0xFFFF;
      jpeg_file_para.jpg_width=0xFFFF;
      return 0;
   }
#if (defined(MT6219)||defined(MT6217)) /* hardware issue */
   if ((restart_marker_flag==1) && (jpeg_file_para.y_h_sample_factor==1)&&
       (jpeg_file_para.y_v_sample_factor==1)&&(jpeg_file_para.u_h_sample_factor==0)&&
       (jpeg_file_para.u_v_sample_factor==0)&&(jpeg_file_para.v_h_sample_factor==0)&&
       (jpeg_file_para.v_v_sample_factor==0))
   {
      jpeg_file_para.jpg_width=0xFFFF;
      jpeg_file_para.jpg_height=0xFFFF;
      return 0;
   }
#endif

   if ((jpeg_file_para.jpg_height!=0xFFFF)&&(jpeg_file_para.jpg_width!=0xFFFF))
   {
   if (jpeg_file_para.y_h_sample_factor>jpeg_file_para.u_h_sample_factor)
   {
      if (jpeg_file_para.y_h_sample_factor > jpeg_file_para.v_h_sample_factor)
         jpeg_file_para.max_h_sample_factor=jpeg_file_para.y_h_sample_factor;
      else
         jpeg_file_para.max_h_sample_factor=jpeg_file_para.v_h_sample_factor;
   }
   else
   {
      if (jpeg_file_para.u_h_sample_factor > jpeg_file_para.v_h_sample_factor)
         jpeg_file_para.max_h_sample_factor=jpeg_file_para.u_h_sample_factor;
      else
         jpeg_file_para.max_h_sample_factor=jpeg_file_para.v_h_sample_factor;
   }

   if (jpeg_file_para.y_v_sample_factor>jpeg_file_para.u_v_sample_factor)
   {
      if (jpeg_file_para.y_v_sample_factor > jpeg_file_para.v_v_sample_factor)
         jpeg_file_para.max_v_sample_factor=jpeg_file_para.y_v_sample_factor;
      else
         jpeg_file_para.max_v_sample_factor=jpeg_file_para.v_v_sample_factor;
   }
   else
   {
      if (jpeg_file_para.u_v_sample_factor > jpeg_file_para.v_v_sample_factor)
         jpeg_file_para.max_v_sample_factor=jpeg_file_para.u_v_sample_factor;
      else
         jpeg_file_para.max_v_sample_factor=jpeg_file_para.v_v_sample_factor;
   }

   if (jpeg_file_para.y_h_sample_factor==1)
   {
      if (jpeg_file_para.jpg_width & 0x07)
         jpeg_file_para.jpg_decode_width=((jpeg_file_para.jpg_width+8)>>3)<<3;
      else
         jpeg_file_para.jpg_decode_width=jpeg_file_para.jpg_width;
   }
   else if (jpeg_file_para.y_h_sample_factor==2)
   {
      if (jpeg_file_para.jpg_width & 0x0F)
         jpeg_file_para.jpg_decode_width=((jpeg_file_para.jpg_width+16)>>4)<<4;
      else
         jpeg_file_para.jpg_decode_width=jpeg_file_para.jpg_width;
   }
   else if (jpeg_file_para.y_h_sample_factor==4)
   {
      if (jpeg_file_para.jpg_width & 0x1F)
         jpeg_file_para.jpg_decode_width=((jpeg_file_para.jpg_width+32)>>5)<<5;
      else
         jpeg_file_para.jpg_decode_width=jpeg_file_para.jpg_width;
   }

   if (jpeg_file_para.y_v_sample_factor==1)
   {
      if (jpeg_file_para.jpg_height & 0x07)
         jpeg_file_para.jpg_decode_height=((jpeg_file_para.jpg_height+8)>>3)<<3;
      else
         jpeg_file_para.jpg_decode_height=jpeg_file_para.jpg_height;
   }
   else if (jpeg_file_para.y_v_sample_factor==2)
   {
      if (jpeg_file_para.jpg_height & 0x0F)
         jpeg_file_para.jpg_decode_height=((jpeg_file_para.jpg_height+16)>>4)<<4;
      else
         jpeg_file_para.jpg_decode_height=jpeg_file_para.jpg_height;
   }
   else if (jpeg_file_para.y_v_sample_factor==4)
   {
      if (jpeg_file_para.jpg_height & 0x1F)
         jpeg_file_para.jpg_decode_height=((jpeg_file_para.jpg_height+32)>>5)<<5;
      else
         jpeg_file_para.jpg_decode_height=jpeg_file_para.jpg_height;
   }
   }
return 0;
}  /* parse_jpeg_file() */

/*************************************************************************
* FUNCTION
*     get_jpeg_file_size
*
* DESCRIPTION
*     This function returns the image width and height of a JPEG file.
*
* PARAMETERS
*     jpg_file_start_address: jpeg file start address of a JPEG file
*     file_size             : JPEG file size
* RETURNS
*     image_width   the source image width of JPEG file
*     image_height  the source image height of JPEG file
*
* GLOBALS AFFECTED
*
*************************************************************************/
void get_jpeg_file_size(kal_uint32 jpg_file_handle,kal_uint32 jpg_file_start_address,
                        kal_uint32 jpg_file_buffer_size,kal_uint16 *image_width,
                        kal_uint16 *image_height)
{
   jpeg_thumbnail_mode=KAL_FALSE;
   parse_jpeg_file(jpg_file_handle, (kal_uint8 *) jpg_file_start_address, jpg_file_buffer_size);
   *image_width=jpeg_file_para.jpg_width;
   *image_height=jpeg_file_para.jpg_height;

}  /* get_jpeg_file_size() */

/*************************************************************************
* FUNCTION
*     get_jpeg_resize_size
*
* DESCRIPTION
*     This function calculate and return the actually wdith and height after resize.
*
* PARAMETERS
*     *jpg_file_ptr  jpeg file pointer that points to the start of a JPEG file
*     file_size      JPEG file size
*     display_width  desired width that MMI would like for display after resize
*     display_height desired height that MMI would like for display after resize
* RETURNS
*     resize_width   the actually width after resize that include the pad boundary (right)
*     resize_height  the actually height after resize that include the pad boundary (bottom)
*
* GLOBALS AFFECTED
*
*************************************************************************/
void get_jpeg_resize_size(kal_uint32 jpg_file_handle,kal_uint32 jpg_file_start_address,
                          kal_uint32 jpg_file_buffer_size,
                          kal_uint16 *display_width, kal_uint16 *display_height,
                          kal_uint16 *resize_width, kal_uint16 *resize_height)
{
   kal_uint16 src_width, src_height;
   kal_uint16 image_width, image_height;

   if (*display_width == 0 && *display_height == 0) {
      jpeg_thumbnail_mode = KAL_FALSE;
   } else {
      if ((*display_width < 64) && (*display_height < 64)) {
         jpeg_thumbnail_mode = KAL_TRUE;
      } else {
         jpeg_thumbnail_mode = KAL_FALSE;
      }
   }

#if defined(DRV_JPG_DEC_17_SERIES)
   parse_jpeg_file(jpg_file_handle, (kal_uint8 *) jpg_file_start_address, jpg_file_buffer_size);

   if(*display_width == 0 && *display_height == 0) {
      *display_width  = jpeg_file_para.jpg_width;
      *display_height = jpeg_file_para.jpg_height;
   }

   src_width    = jpeg_file_para.jpg_decode_width;
   src_height   = jpeg_file_para.jpg_decode_height;
   image_width  = jpeg_file_para.jpg_width;
   image_height = jpeg_file_para.jpg_height;

   if ((image_width != src_width) && (*display_width != image_width)) {
      *resize_width = src_width * (*display_width) / image_width + 1;
   } else {
      *resize_width = src_width * (*display_width) / image_width;
   }

   if ((image_height != src_height) && (*display_height != image_height)) {
      *resize_height = src_height * (*display_height) / image_height + 1;
   } else {
      *resize_height = src_height * (*display_height) / image_height;
   }

   if ((*resize_width == 0) && (*resize_height == 0)) {
      *resize_width  = src_width;
      *resize_height = src_height;
   }
#elif (defined(DRV_JPG_DEC_19_SERIES)||defined(DRV_JPG_DEC_28_SERIES)||defined(DRV_JPG_SW_DEC_SUPPORT))
   if((*display_width == 0) && (*display_height == 0)) {
      parse_jpeg_file(jpg_file_handle, (kal_uint8 *) jpg_file_start_address, jpg_file_buffer_size);
      *display_width = jpeg_file_para.jpg_width;
      *display_height = jpeg_file_para.jpg_height;
   }
   *resize_width  = *display_width;
   *resize_height = *display_height;
#endif
}  /* get_jpeg_resize_size() */

/*************************************************************************
* FUNCTION
*     config_jpeg_decoder
*
* DESCRIPTION
*     This function config the JPEG deocder hardware.
*
* PARAMETERS
*     jpeg_file_start_address    the start address of a jpeg file
*     jpeg_file_size             the size of a jpeg file
* RETURNS
*     0 :   if jpeg decoder configuration complete
*  others : if jpeg deocder configuration fail
* GLOBALS AFFECTED
*
*************************************************************************/
#if (defined(DRV_JPG_HW_DEC_SUPPORT))
kal_uint8 config_jpeg_decoder(kal_uint32 jpeg_file_start_address, kal_uint32 jpeg_file_size)
{
   kal_uint32 mcu_num_per_mcu_row;
   kal_uint32 total_mcu_num,num_of_mcu_row;
   kal_uint8 max_h_sample_factor, max_v_sample_factor;
   kal_uint8 j,num_of_dummy_mcu;
   kal_uint16 i;
   kal_uint32 comp_mcu_number,comp_block_number;
   kal_uint8 comp_h_bits,comp_v_bits,num_of_dummy_x_bits;
   kal_uint32 temp_addr;
   kal_uint16 num_of_line_buffer;
   kal_uint32 mem_size;
   kal_uint8 dummy_bits;
   kal_uint16 du_num_ratio_y,du_num_ratio_u,du_num_ratio_v;
   volatile kal_uint32 *ptr;

   max_h_sample_factor=jpeg_file_para.max_h_sample_factor;
   max_v_sample_factor=jpeg_file_para.max_v_sample_factor;

   /* Used to solve 4-byte boundary between FFD9 & FFDB */
   if((jpeg_file_start_address & 0x03) && //not 4-byte align
      (jpeg_file_start_address >jpeg_decode_config_data.jpeg_file_buffer_address+2) && // within jpeg file buffer
      *((kal_uint8*)(jpeg_file_start_address-2)) == 0xFF && *((kal_uint8*)(jpeg_file_start_address-1)) == 0xD9)//thumbnai EOI
   {
    *((kal_uint8*)(jpeg_file_start_address-2))=0x00;
    *((kal_uint8*)(jpeg_file_start_address-1))=0x00;
   }

   RESET_JPEG_DECODER;

   REG_JPEG_DECODER_JPEG_FILE_START_ADDR = jpeg_file_start_address;

   jpeg_decode_ext_mem_size+=0x1000;
   if (jpeg_decode_ext_mem_size>jpeg_decode_config_data.extmem_size)
      return (JPEG_DECODE_EXT_BUFFER_NOT_ENOUGH);

   if (!extmem_is_buffer_available(0x1000)) //protect extmem buffer from alter
      {  return JPEG_DECODE_EXT_BUFFER_NOT_ENOUGH;
      }

   temp_addr=(kal_uint32) extmem_get_buffer(0x1000);
   /* the jpeg table buffer should be 2K boundary and minimum size is 2K bytes */
   temp_addr+=0x800;
   REG_JPEG_DECODER_TABLE_ADDR = (temp_addr&0xFFFFF800);
   ptr = ((volatile unsigned int *) (temp_addr&0xFFFFF800));
   for (i=0;i<0x200;i++)
      *(ptr+i)=0;

   SET_JPEG_SAMPLE_FACTOR_H1(jpeg_file_para.y_h_sample_factor);
   SET_JPEG_SAMPLE_FACTOR_V1(jpeg_file_para.y_v_sample_factor);
   if (jpeg_file_para.u_h_sample_factor)
   {
       SET_JPEG_SAMPLE_FACTOR_H2(jpeg_file_para.u_h_sample_factor);
       SET_JPEG_SAMPLE_FACTOR_V2(jpeg_file_para.u_v_sample_factor);
   }
   else
   {
      SET_JPEG_SAMPLE_FACTOR_H2(3);
      SET_JPEG_SAMPLE_FACTOR_V2(3);
   }

   if (jpeg_file_para.v_h_sample_factor)
   {
      SET_JPEG_SAMPLE_FACTOR_H3(jpeg_file_para.v_h_sample_factor);
      SET_JPEG_SAMPLE_FACTOR_V3(jpeg_file_para.v_v_sample_factor);
   }
   else
   {
      SET_JPEG_SAMPLE_FACTOR_H3(3);
      SET_JPEG_SAMPLE_FACTOR_V3(3);
   }
   SET_JPEG_COMPONENT1_ID(jpeg_file_para.component_id1);
   SET_JPEG_COMPONENT2_ID(jpeg_file_para.component_id2);
   SET_JPEG_COMPONENT3_ID(jpeg_file_para.component_id3);

   total_mcu_num=((jpeg_file_para.jpg_decode_width * jpeg_file_para.jpg_decode_height)>>6)/
                  max_h_sample_factor/max_v_sample_factor;
   REG_JPEG_DECODER_TOTAL_MCU_NUMBER=(total_mcu_num-1);

   mcu_num_per_mcu_row=(jpeg_file_para.jpg_decode_width/max_h_sample_factor)>>3;

   REG_JPEG_DECODER_MCU_NUMBER_PER_MCU_ROW = mcu_num_per_mcu_row;

   num_of_dummy_x_bits=jpeg_file_para.jpg_decode_width-jpeg_file_para.jpg_width;
   num_of_dummy_mcu=(num_of_dummy_x_bits * jpeg_file_para.y_h_sample_factor/max_h_sample_factor)>>3;
   SET_JPEG_COMP0_DUMMY_BLOCKS_PER_MCU_ROW(num_of_dummy_mcu);
   SET_JPEG_COMP0_BLOCKS_PER_MCU_ROW(mcu_num_per_mcu_row*jpeg_file_para.y_h_sample_factor);

   comp_h_bits=(max_h_sample_factor/jpeg_file_para.y_h_sample_factor)<<3;
   comp_v_bits=(max_v_sample_factor/jpeg_file_para.y_v_sample_factor)<<3;
   if (jpeg_file_para.jpg_width%comp_h_bits)
      comp_block_number = (jpeg_file_para.jpg_width+comp_h_bits)/comp_h_bits;
   else
      comp_block_number=jpeg_file_para.jpg_width/comp_h_bits;
   if (jpeg_file_para.jpg_height%comp_h_bits)
      comp_block_number *= ((jpeg_file_para.jpg_height+comp_v_bits)/comp_v_bits);
   else
      comp_block_number *= (jpeg_file_para.jpg_height/comp_v_bits);
   REG_JPEG_DECODER_COMP0_DATA_UNIT_NUMBER=comp_block_number-1;

   if (jpeg_file_para.number_of_component>=2)
   {
      num_of_dummy_mcu=(num_of_dummy_x_bits * jpeg_file_para.u_h_sample_factor/max_h_sample_factor)>>3;
      SET_JPEG_COMP1_DUMMY_BLOCKS_PER_MCU_ROW(num_of_dummy_mcu);
      SET_JPEG_COMP1_BLOCKS_PER_MCU_ROW(mcu_num_per_mcu_row*jpeg_file_para.u_h_sample_factor);

      comp_h_bits=(max_h_sample_factor/jpeg_file_para.u_h_sample_factor)<<3;
      comp_v_bits=(max_v_sample_factor/jpeg_file_para.u_v_sample_factor)<<3;
      if (jpeg_file_para.jpg_width%comp_h_bits)
         comp_mcu_number = (jpeg_file_para.jpg_width+comp_h_bits)/comp_h_bits;
      else
         comp_mcu_number=jpeg_file_para.jpg_width/comp_h_bits;
      if (jpeg_file_para.jpg_height%comp_h_bits)
         comp_mcu_number *= ((jpeg_file_para.jpg_height+comp_v_bits)/comp_v_bits);
      else
         comp_mcu_number *= (jpeg_file_para.jpg_height/comp_v_bits);
      REG_JPEG_DECODER_COMP1_DATA_UNIT_NUMBER=comp_mcu_number-1;
   }

   if (jpeg_file_para.number_of_component>=3)
   {
      num_of_dummy_mcu=(num_of_dummy_x_bits * jpeg_file_para.v_h_sample_factor/max_h_sample_factor)>>3;
      SET_JPEG_COMP2_DUMMY_BLOCKS_PER_MCU_ROW(num_of_dummy_mcu);
      SET_JPEG_COMP2_BLOCKS_PER_MCU_ROW(mcu_num_per_mcu_row*jpeg_file_para.v_h_sample_factor);

      comp_h_bits=(max_h_sample_factor/jpeg_file_para.v_h_sample_factor)<<3;
      comp_v_bits=(max_v_sample_factor/jpeg_file_para.v_v_sample_factor)<<3;
      if (jpeg_file_para.jpg_width%comp_h_bits)
         comp_mcu_number = (jpeg_file_para.jpg_width+comp_h_bits)/comp_h_bits;
      else
         comp_mcu_number=jpeg_file_para.jpg_width/comp_h_bits;
      if (jpeg_file_para.jpg_height%comp_h_bits)
         comp_mcu_number *= ((jpeg_file_para.jpg_height+comp_v_bits)/comp_v_bits);
      else
         comp_mcu_number *= (jpeg_file_para.jpg_height/comp_v_bits);
      REG_JPEG_DECODER_COMP2_DATA_UNIT_NUMBER=comp_mcu_number-1;
   }

   if (jpeg_file_para.jpg_progressive)
   {
      SET_JPEG_PROGRESSIVE_MODE;
   }
   else
   {
      SET_JPEG_BASELINE_MODE;
   }

   if ((jpeg_file_para.jpg_progressive==KAL_TRUE) && (jpeg_file_para.number_of_component==1))
   {
      if ((jpeg_file_para.y_h_sample_factor*jpeg_file_para.y_v_sample_factor)==1)
      {
         if ((mcu_num_per_mcu_row%3)==0)
            times_of_total_mcu_num=3;
         else if ((mcu_num_per_mcu_row%4)==0)
            times_of_total_mcu_num=4;
         else if ((mcu_num_per_mcu_row%5)==0)
            times_of_total_mcu_num=5;
         else if ((mcu_num_per_mcu_row%7)==0)
            times_of_total_mcu_num=7;
         else
            times_of_total_mcu_num=4;
      }
      else if ((jpeg_file_para.y_h_sample_factor*jpeg_file_para.y_v_sample_factor)==2)
         times_of_total_mcu_num=2;
      else if ((jpeg_file_para.y_h_sample_factor*jpeg_file_para.y_v_sample_factor)==4)
         times_of_total_mcu_num=1;

      mcu_num_per_mcu_row*=times_of_total_mcu_num;
      if ((total_mcu_num%mcu_num_per_mcu_row)==0)
         num_of_mcu_row = total_mcu_num/mcu_num_per_mcu_row;
      else
         num_of_mcu_row = total_mcu_num/mcu_num_per_mcu_row+1;

      if ((total_mcu_num/times_of_total_mcu_num)==0)
         REG_JPEG_DECODER_TOTAL_MCU_NUMBER=total_mcu_num/times_of_total_mcu_num;
      else
      REG_JPEG_DECODER_TOTAL_MCU_NUMBER=(total_mcu_num/times_of_total_mcu_num+1);
      for (i=0;i<(times_of_total_mcu_num*jpeg_file_para.y_h_sample_factor*jpeg_file_para.y_v_sample_factor);i++)
      {
         SET_JPEG_CATEGORY_COMPONENT_ID(i,JPEG_CTRL_CATEGORY_COMPONENT1);
      }
   }
   else
   {
      for (i=0;i<(jpeg_file_para.y_h_sample_factor*jpeg_file_para.y_v_sample_factor);i++)
      {
         SET_JPEG_CATEGORY_COMPONENT_ID(i,JPEG_CTRL_CATEGORY_COMPONENT1);
      }
   j=i;
   for (;i<(j+jpeg_file_para.u_h_sample_factor*jpeg_file_para.u_v_sample_factor);i++)
   {
      SET_JPEG_CATEGORY_COMPONENT_ID(i,JPEG_CTRL_CATEGORY_COMPONENT2);
   }
   j=i;

   for (;i<(j+jpeg_file_para.v_h_sample_factor*jpeg_file_para.v_v_sample_factor);i++)
   {
      SET_JPEG_CATEGORY_COMPONENT_ID(i,JPEG_CTRL_CATEGORY_COMPONENT3);
   }
   for (;i<10;i++)
   {
      SET_JPEG_CATEGORY_COMPONENT_ID(i,JPEG_CTRL_CATEGORY_UNUSED);
   }
   }

   if (jpeg_decode_config_data.rest_jpeg_file_size==0)
      REG_JEPG_DECODER_STOP_ADDR=(jpeg_file_start_address + jpeg_file_size +0x10)&0xFFFFFFFC;
   else
      REG_JEPG_DECODER_STOP_ADDR=(jpeg_file_start_address + jpeg_file_size);

   REG_JPEG_DECODER_FILE_SIZE=(jpeg_decode_config_data.jpeg_file_size+0x10)&0xFFFFFFFC;

   SET_JPEG_COMPONENT1_Q_TABLE(jpeg_file_para.q_table_id1);
   SET_JPEG_COMPONENT2_Q_TABLE(jpeg_file_para.q_table_id2);
   SET_JPEG_COMPONENT3_Q_TABLE(jpeg_file_para.q_table_id3);
   jpeg_file_para.jpeg_decoder_ctrl_reg=REG_JPEG_DECODER_CTRL;

   if ((jpeg_decode_config_data.extmem_size-jpeg_decode_ext_mem_size)>64)
      mem_size=jpeg_decode_config_data.extmem_size-jpeg_decode_ext_mem_size-64;
   else
      mem_size=0;
   dummy_bits=jpeg_file_para.jpg_decode_width-jpeg_file_para.jpg_width;
   if (jpeg_file_para.jpg_progressive==KAL_TRUE)
   {  /* progressive mode */
      if (jpeg_file_para.number_of_component==1)
      {
         num_of_line_buffer=(mem_size/2/(mcu_num_per_mcu_row*(jpeg_file_para.y_h_sample_factor<<3)*
                             (jpeg_file_para.y_v_sample_factor<<3)))*(jpeg_file_para.y_v_sample_factor<<3)*
                             times_of_total_mcu_num;

         if ((jpeg_file_para.y_v_sample_factor*times_of_total_mcu_num)==1)
            num_of_line_buffer &= 0xFFF8;
         else if ((jpeg_file_para.y_v_sample_factor*times_of_total_mcu_num)==2)
            num_of_line_buffer &= 0xFFF0;
         else if ((jpeg_file_para.y_v_sample_factor*times_of_total_mcu_num)==4)
            num_of_line_buffer &= 0xFFE0;
         else
            num_of_line_buffer &= 0xFFE0;

         if (num_of_line_buffer==0)
            return (JPEG_DECODE_EXT_BUFFER_NOT_ENOUGH);

         if ((jpeg_file_para.jpg_decode_height%num_of_line_buffer)==0)
            jpeg_file_para.progressive_decode_times=jpeg_file_para.jpg_decode_height/num_of_line_buffer-1;
         else if (jpeg_file_para.jpg_decode_height>=num_of_line_buffer)
            jpeg_file_para.progressive_decode_times=jpeg_file_para.jpg_decode_height/num_of_line_buffer;
         else
            jpeg_file_para.progressive_decode_times=0;

         jpeg_file_para.interleave_mcu_increament_index=((num_of_line_buffer*jpeg_file_para.jpg_decode_width)>>6)/
                                                         jpeg_file_para.max_h_sample_factor/jpeg_file_para.max_v_sample_factor/times_of_total_mcu_num;
         jpeg_file_para.non_interleav_mcu_increament_index_y=((num_of_line_buffer*jpeg_file_para.jpg_decode_width)>>6)*
                                                              jpeg_file_para.y_h_sample_factor*jpeg_file_para.y_v_sample_factor/
                                                              jpeg_file_para.max_h_sample_factor/jpeg_file_para.max_v_sample_factor;
         jpeg_file_para.non_interleav_mcu_increament_index_y-=((num_of_line_buffer>>3)*((dummy_bits*jpeg_file_para.y_h_sample_factor/
                                                               jpeg_file_para.max_h_sample_factor)>>3));

            if (!extmem_is_buffer_available(mem_size)) //protect extmem buffer from alter.
            {   return JPEG_DECODE_EXT_BUFFER_NOT_ENOUGH;}

         REG_JPEG_DECODER_COMP0_PROG_START_ADDR = (kal_uint32) extmem_get_buffer(mem_size);
         REG_JEPG_DECODER_INTERLEAVE_FIRST_MCU_INDEX=0;
         REG_JEPG_DECODER_INTERLEAVE_LAST_MCU_INDEX=jpeg_file_para.interleave_mcu_increament_index-1;
         REG_JEPG_DECODER_COMP0_FIRST_MCU_INDEX=0;
         REG_JEPG_DECODER_COMP0_LAST_MCU_INDEX=jpeg_file_para.non_interleav_mcu_increament_index_y-1;
      }
      else
      {
         du_num_ratio_y=jpeg_file_para.y_h_sample_factor*jpeg_file_para.y_v_sample_factor;
         du_num_ratio_u=jpeg_file_para.u_h_sample_factor*jpeg_file_para.u_v_sample_factor;
         du_num_ratio_v=jpeg_file_para.v_h_sample_factor*jpeg_file_para.v_v_sample_factor;

         num_of_line_buffer=(mem_size*(jpeg_file_para.max_h_sample_factor*jpeg_file_para.max_v_sample_factor)/
                             (du_num_ratio_y+du_num_ratio_u+du_num_ratio_v)/2/(mcu_num_per_mcu_row*(jpeg_file_para.max_h_sample_factor<<3)*
                             (jpeg_file_para.max_v_sample_factor<<3)))*(jpeg_file_para.max_v_sample_factor<<3);

         if (jpeg_file_para.y_v_sample_factor==1)
            num_of_line_buffer &= 0xFFF8;
         else if (jpeg_file_para.y_v_sample_factor==2)
            num_of_line_buffer &= 0xFFF0;
         else if (jpeg_file_para.y_v_sample_factor==4)
            num_of_line_buffer &= 0xFFE0;

         if (num_of_line_buffer==0)
            return (JPEG_DECODE_EXT_BUFFER_NOT_ENOUGH);

         if ((jpeg_file_para.jpg_decode_height%num_of_line_buffer)==0)
            jpeg_file_para.progressive_decode_times=jpeg_file_para.jpg_decode_height/num_of_line_buffer-1;
         else if (jpeg_file_para.jpg_decode_height>=num_of_line_buffer)
            jpeg_file_para.progressive_decode_times=jpeg_file_para.jpg_decode_height/num_of_line_buffer;
         else
            jpeg_file_para.progressive_decode_times=0;

         jpeg_file_para.interleave_mcu_increament_index=((num_of_line_buffer*jpeg_file_para.jpg_decode_width)>>6)/
                                                         jpeg_file_para.max_h_sample_factor/jpeg_file_para.max_v_sample_factor;
         jpeg_file_para.non_interleav_mcu_increament_index_y=((num_of_line_buffer*jpeg_file_para.jpg_decode_width)>>6)*
                                                              jpeg_file_para.y_h_sample_factor*jpeg_file_para.y_v_sample_factor/
                                                              jpeg_file_para.max_h_sample_factor/jpeg_file_para.max_v_sample_factor;
         jpeg_file_para.non_interleav_mcu_increament_index_y-=((num_of_line_buffer>>3)*((dummy_bits*jpeg_file_para.y_h_sample_factor/
                                                               jpeg_file_para.max_h_sample_factor)>>3));
         jpeg_file_para.non_interleav_mcu_increament_index_u=((num_of_line_buffer*jpeg_file_para.jpg_decode_width)>>6)*
                                                              jpeg_file_para.u_h_sample_factor*jpeg_file_para.u_v_sample_factor/
                                                              jpeg_file_para.max_h_sample_factor/jpeg_file_para.max_v_sample_factor;
         jpeg_file_para.non_interleav_mcu_increament_index_u-=((num_of_line_buffer>>3)*((dummy_bits*jpeg_file_para.u_h_sample_factor/
                                                               jpeg_file_para.max_h_sample_factor)>>3));
         jpeg_file_para.non_interleav_mcu_increament_index_v=((num_of_line_buffer*jpeg_file_para.jpg_decode_width)>>6)*
                                                              jpeg_file_para.v_h_sample_factor*jpeg_file_para.v_v_sample_factor/
                                                              jpeg_file_para.max_h_sample_factor/jpeg_file_para.max_v_sample_factor;
         jpeg_file_para.non_interleav_mcu_increament_index_v-=((num_of_line_buffer>>3)*((dummy_bits*jpeg_file_para.v_h_sample_factor/
                                                               jpeg_file_para.max_h_sample_factor)>>3));

          if (!extmem_is_buffer_available(mem_size*du_num_ratio_y/(du_num_ratio_y+du_num_ratio_u+du_num_ratio_v))) //protect extmem buffer from alter.
             {return JPEG_DECODE_EXT_BUFFER_NOT_ENOUGH;}

         REG_JPEG_DECODER_COMP0_PROG_START_ADDR = (kal_uint32) extmem_get_buffer(mem_size*du_num_ratio_y/
                                                   (du_num_ratio_y+du_num_ratio_u+du_num_ratio_v));
          if (!extmem_is_buffer_available(mem_size*du_num_ratio_u/(du_num_ratio_y+du_num_ratio_u+du_num_ratio_v))) //protect extmem buffer from alter.
             {return (JPEG_DECODE_EXT_BUFFER_NOT_ENOUGH);}

         REG_JPEG_DECODER_COMP1_PROG_START_ADDR = (kal_uint32) extmem_get_buffer(mem_size*du_num_ratio_u/
                                                   (du_num_ratio_y+du_num_ratio_u+du_num_ratio_v));
          if (!extmem_is_buffer_available(mem_size*du_num_ratio_v/(du_num_ratio_y+du_num_ratio_u+du_num_ratio_v))) //protect extmem buffer from alter.
             {return (JPEG_DECODE_EXT_BUFFER_NOT_ENOUGH);}

         REG_JPEG_DECODER_COMP2_PROG_START_ADDR = (kal_uint32) extmem_get_buffer(mem_size*du_num_ratio_v/
                                                   (du_num_ratio_y+du_num_ratio_u+du_num_ratio_v));

         REG_JEPG_DECODER_INTERLEAVE_FIRST_MCU_INDEX=0;
         REG_JEPG_DECODER_INTERLEAVE_LAST_MCU_INDEX=jpeg_file_para.interleave_mcu_increament_index-1;
         REG_JEPG_DECODER_COMP0_FIRST_MCU_INDEX=0;
         REG_JEPG_DECODER_COMP0_LAST_MCU_INDEX=jpeg_file_para.non_interleav_mcu_increament_index_y-1;
         REG_JEPG_DECODER_COMP1_FIRST_MCU_INDEX=0;
         REG_JEPG_DECODER_COMP1_LAST_MCU_INDEX=jpeg_file_para.non_interleav_mcu_increament_index_u-1;
         REG_JEPG_DECODER_COMP2_FIRST_MCU_INDEX=0;
         REG_JEPG_DECODER_COMP2_LAST_MCU_INDEX=jpeg_file_para.non_interleav_mcu_increament_index_v-1;
      }
   }

   START_JPEG_DECODER;

   return 0;
}  /* config_jpeg_decoder() */
#endif

#if (defined(DRV_JPG_DATA_PATH_17_SERIES) || defined(DRV_JPG_DATA_PATH_19_SERIES))
/*************************************************************************
* FUNCTION
*     config_block_resizer
*
* DESCRIPTION
*     This function config the resizer hardware.
*
* PARAMETERS
*     target_address    the buffer address that for image output
*     display_width     the visable image width
*     display_height    the visable iamge height
* RETURNS
*     0     :  if jpeg decoder configuration complete
*  others   :  if jpeg deocder configuration fail
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 config_block_resizer(kal_uint16 *target_width, kal_uint16 *target_height)
{
#if (defined(DRV_JPG_DATA_PATH_19_SERIES))
   RESZ_DCB_STRUCT resizer_dcb;
   RESZ_BLK_CFG_STRUCT resizer_cfg;
#endif
   kal_uint16 max_resizer_width,max_resizer_height;
   kal_uint32 target_address, target_buffer_size;
   kal_uint16 display_width, display_height;
   kal_uint16 src_width, src_height,image_width,image_height;

   target_address=jpeg_decode_config_data.image_buffer_address;
   target_buffer_size=jpeg_decode_config_data.image_buffer_size;
   display_width=jpeg_decode_config_data.image_width;
   display_height=jpeg_decode_config_data.image_height;

   /* reset resizer */
   src_width=jpeg_file_para.jpg_decode_width;
   src_height=jpeg_file_para.jpg_decode_height;
   image_width=jpeg_file_para.jpg_width;
   image_height=jpeg_file_para.jpg_height;
   if ((image_width!=src_width)&&(display_width!=image_width))
      *target_width=(src_width*display_width/image_width) + 1;
   else
   *target_width=src_width*display_width/image_width;
   if ((image_height!=src_height)&&(display_height!=image_height))
      *target_height=(src_height*display_height/image_height)+1;
   else
      *target_height=(src_height*display_height/image_height);
   if ((*target_width==0) && (*target_height==0))
   {
      *target_width=src_width;
      *target_height=src_height;
   }

#if (defined(DRV_IMG_CLIP_SUPPORT))
   if ((((jpeg_decode_config_data.image_clip_x2-jpeg_decode_config_data.image_clip_x1+1)*
         (jpeg_decode_config_data.image_clip_y2-jpeg_decode_config_data.image_clip_y1+1))<<1)>target_buffer_size)
      return (JPEG_DECODE_TARGET_BUFFER_NOT_ENOUGH);
#else
      if ((((*target_width) * (*target_height))<<1) > target_buffer_size)
       return (JPEG_DECODE_TARGET_BUFFER_NOT_ENOUGH);
#endif

   if(((*target_width)*3 < 2047) || ((*target_height)*3<2047))
   {
   max_resizer_width=(*target_width)*3;
   max_resizer_height=(*target_height)*3;
   }
   else if(((*target_width)*2 < 2047) || ((*target_height)*2<2047))
   {
    max_resizer_width=(*target_width)*2;
    max_resizer_height=(*target_height)*2;
   }
   else
   {
    max_resizer_width=(*target_width);
    max_resizer_height=(*target_height);
   }

#if (defined(DRV_JPG_DATA_PATH_17_SERIES))
   RESET_RESIZER;

   if ((src_width<max_resizer_width) &&
      (src_height<max_resizer_height))
   {
      SET_RESIZER_BLOCK_CS_FACTOR(BLOCK_CS_1_1);
   }
   else if ((src_width<(max_resizer_width<<1)) &&
            (src_height<(max_resizer_height<<1)))
   {
      SET_RESIZER_BLOCK_CS_FACTOR(BLOCK_CS_1_4);
      src_width>>=1;
      src_height>>=1;
   }
   else if ((src_width<(max_resizer_width<<2)) &&
            (src_height<(max_resizer_height<<2)))
   {
      SET_RESIZER_BLOCK_CS_FACTOR(BLOCK_CS_1_16);
      src_width>>=2;
      src_height>>=2;
   }
   else
   {
      SET_RESIZER_BLOCK_CS_FACTOR(BLOCK_CS_1_64);
      src_width>>=3;
      src_height>>=3;
   }
   if (src_width>2047)
      return (JPEG_DECODE_SRC_WIDHT_TOO_LARGE_FAIL);
   if (src_height>2047)
      return (JPEG_DECODE_SRC_HEIGHT_TOO_LARGE_FAIL);
   if ((*target_width)>2047)
      return (JPEG_DECODE_TARGET_WIDTH_TOO_LARGE_FAIL);
   if ((*target_height)>2047)
      return (JPEG_DECODE_TARGET_HEIGHT_TOO_LARGE_FAIL);

   SET_RESIZER_SRC_SIZE(src_width,src_height);
   SET_RESIZER_TARGET_SIZE(*target_width,*target_height);
#if (defined(MT6217))
   if (((kal_uint32)src_width) == ((kal_uint32)(*target_width)))
      REG_RESIZER_H_RATIO = (1<<21);
   else
      REG_RESIZER_H_RATIO=(kal_uint32) (((1<<21)/((kal_uint32)(*target_width)))*((kal_uint32)src_width));
   if (((kal_uint32)src_height)==((kal_uint32)(*target_height)))
      REG_RESIZER_V_RATIO=(1<<21);
   else
      REG_RESIZER_V_RATIO=(kal_uint32)(((1<<21)/((kal_uint32)(*target_height)))*((kal_uint32)src_height));
   REG_RESIZER_H_RESIDUAL=0;
   REG_RESIZER_V_RESIDUAL=0;
#endif
   SET_RESIZER_BLOCK_CS_Y_H_FACTOR(jpeg_file_para.y_h_sample_factor);
   SET_RESIZER_BLOCK_CS_Y_V_FACTOR(jpeg_file_para.y_v_sample_factor);

   if (jpeg_file_para.number_of_component>=2)
   {
      if (jpeg_file_para.number_of_component>=3)
      {
         SET_RESIZER_BLOCK_CS_U_H_FACTOR(jpeg_file_para.u_h_sample_factor);
         SET_RESIZER_BLOCK_CS_U_V_FACTOR(jpeg_file_para.u_v_sample_factor);
         SET_RESIZER_BLOCK_CS_V_H_FACTOR(jpeg_file_para.v_h_sample_factor);
         SET_RESIZER_BLOCK_CS_V_V_FACTOR(jpeg_file_para.v_v_sample_factor);
      }
      else if (jpeg_file_para.u_h_sample_factor!=0)
      {
         SET_RESIZER_BLOCK_CS_U_H_FACTOR(jpeg_file_para.u_h_sample_factor);
         SET_RESIZER_BLOCK_CS_U_V_FACTOR(jpeg_file_para.u_v_sample_factor);
   #if (defined(MT6217))
         SET_RESIZER_BLOCK_CS_V_H_FACTOR(6);
         SET_RESIZER_BLOCK_CS_V_V_FACTOR(6);
   #endif
      }
      else if (jpeg_file_para.u_h_sample_factor==0)
      {
         SET_RESIZER_BLOCK_CS_V_H_FACTOR(jpeg_file_para.v_h_sample_factor);
         SET_RESIZER_BLOCK_CS_V_V_FACTOR(jpeg_file_para.v_v_sample_factor);
   #if (defined(MT6217))
         SET_RESIZER_BLOCK_CS_U_H_FACTOR(6);
         SET_RESIZER_BLOCK_CS_U_V_FACTOR(6);
   #endif
      }
   }
#if (defined(MT6217))
   else
   {
      SET_RESIZER_BLOCK_CS_U_H_FACTOR(6);
      SET_RESIZER_BLOCK_CS_U_V_FACTOR(6);
      SET_RESIZER_BLOCK_CS_V_H_FACTOR(6);
      SET_RESIZER_BLOCK_CS_V_V_FACTOR(6);
   }
#endif

   if ((*target_width>src_width)||(*target_height>src_height))
   {
      jpeg_decode_int_mem_size += (((src_width * ((jpeg_file_para.y_v_sample_factor<<3)+1))&0xFFFFFFFC)+4);
      jpeg_decode_int_mem_size += (((src_width * ((jpeg_file_para.u_v_sample_factor<<3)+1))&0xFFFFFFFC)+4);
      jpeg_decode_int_mem_size += (((src_width * ((jpeg_file_para.v_v_sample_factor<<3)+1))&0xFFFFFFFC)+4);
   }
   else
   {
      jpeg_decode_int_mem_size += (((src_width * (jpeg_file_para.y_v_sample_factor<<3))&0xFFFFFFFC)+4);
      jpeg_decode_int_mem_size += (((src_width * (jpeg_file_para.u_v_sample_factor<<3))&0xFFFFFFFC)+4);
      jpeg_decode_int_mem_size += (((src_width * (jpeg_file_para.v_v_sample_factor<<3))&0xFFFFFFFC)+4);
   }
   jpeg_decode_int_mem_size += (((((*target_width) * RESIZER_WORKING_MEM_LINE_NUMBER)&0xFFFFFFFC)+4)*3);
   if (jpeg_decode_int_mem_size>jpeg_decode_config_data.intmem_size)
      return (JPEG_DECODE_INT_BUFFER_NOT_ENOUGH);

#if (defined(MT6218B))
   if ((*target_width>src_width)||(*target_height>src_height))
   {   /* hardware limit , enlarge case*/
      SET_RESIZER_FINE_RESIZE_Y_LINE_BUFFER((jpeg_file_para.y_v_sample_factor<<3)+jpeg_file_para.y_v_sample_factor);
      REG_RESIZER_Y_LINE_BUFFER_ADDR = (kal_uint32) intmem_get_buffer((src_width * ((jpeg_file_para.y_v_sample_factor<<3)+jpeg_file_para.y_v_sample_factor)));

      SET_RESIZER_FINE_RESIZE_U_LINE_BUFFER((jpeg_file_para.u_v_sample_factor<<3)+jpeg_file_para.u_v_sample_factor);
      REG_RESIZER_U_LINE_BUFFER_ADDR = (kal_uint32) intmem_get_buffer((src_width * ((jpeg_file_para.u_v_sample_factor<<3)+jpeg_file_para.u_v_sample_factor)));

      SET_RESIZER_FINE_RESIZE_V_LINE_BUFFER((jpeg_file_para.v_v_sample_factor<<3)+jpeg_file_para.v_v_sample_factor);
      REG_RESIZER_V_LINE_BUFFER_ADDR = (kal_uint32) intmem_get_buffer((src_width * ((jpeg_file_para.v_v_sample_factor<<3)+jpeg_file_para.v_v_sample_factor)));
   }
   else
   {
      SET_RESIZER_FINE_RESIZE_Y_LINE_BUFFER((jpeg_file_para.y_v_sample_factor<<3));
      REG_RESIZER_Y_LINE_BUFFER_ADDR = (kal_uint32) intmem_get_buffer((src_width * (jpeg_file_para.y_v_sample_factor<<3)));

      SET_RESIZER_FINE_RESIZE_U_LINE_BUFFER((jpeg_file_para.u_v_sample_factor<<3));
      REG_RESIZER_U_LINE_BUFFER_ADDR = (kal_uint32) intmem_get_buffer((src_width * (jpeg_file_para.u_v_sample_factor<<3)));

      SET_RESIZER_FINE_RESIZE_V_LINE_BUFFER((jpeg_file_para.v_v_sample_factor<<3));
      REG_RESIZER_V_LINE_BUFFER_ADDR = (kal_uint32) intmem_get_buffer(src_width * (jpeg_file_para.v_v_sample_factor<<3));
   }
   SET_RESIZER_FINE_RESIZE_WORK_MEM_SIZE(RESIZER_WORKING_MEM_LINE_NUMBER);
   REG_RESIZER_Y_WORK_MEM_ADDR = (kal_uint32) intmem_get_buffer(((*target_width) * RESIZER_WORKING_MEM_LINE_NUMBER));
   REG_RESIZER_U_WORK_MEM_ADDR = (kal_uint32) intmem_get_buffer(((*target_width) * RESIZER_WORKING_MEM_LINE_NUMBER));
   REG_RESIZER_V_WORK_MEM_ADDR = (kal_uint32) intmem_get_buffer(((*target_width) * RESIZER_WORKING_MEM_LINE_NUMBER));
#elif (defined(MT6217))
      SET_RESIZER_CS_LINE_BUFFER((jpeg_file_para.y_v_sample_factor<<3));
      REG_RESIZER_Y_LINE_BUFFER_ADDR = (kal_uint32) intmem_get_buffer((src_width * (jpeg_file_para.y_v_sample_factor<<3)));
      REG_RESIZER_U_LINE_BUFFER_ADDR = (kal_uint32) intmem_get_buffer((src_width * (jpeg_file_para.u_v_sample_factor<<3)));
      REG_RESIZER_V_LINE_BUFFER_ADDR = (kal_uint32) intmem_get_buffer(src_width * (jpeg_file_para.v_v_sample_factor<<3));

   SET_RESIZER_FINE_RESIZE_WORK_MEM_SIZE(RESIZER_WORKING_MEM_LINE_NUMBER);
   REG_RESIZER_WORK_MEM_ADDR=(kal_uint32) intmem_get_buffer(((*target_width) * RESIZER_WORKING_MEM_LINE_NUMBER)*3);
#endif

   jpeg_decoder_decode_result=0;
   jpeg_file_resizer_result=0;

   DISABLE_RESIZER_YUV2RGB_INT;
   REG_RESIZER_TARGET_MEM_ADDR = target_address;
   ENABLE_RESIZER_YUV2RGB_INT;
   ENABLE_RESIZER;
   return 0;

#elif (defined(DRV_JPG_DATA_PATH_19_SERIES))
   resizer_dcb.owner = SCENARIO_JPEG_DECODE_ID;
   #if (defined(MT6226)||defined(MT6226M)||defined(MT6227)||defined(MT6227D)||defined(MT6226D))
   resizer_dcb.cfg.src1=SRC_JPEG_DECODER;
   #endif
   resizer_dcb.cfg.pcontinue=0;
   resizer_dcb.cfg.pixel_sel=0;
   resizer_dcb.cfg.run2=0;

   if ((src_width<=max_resizer_width) &&
      (src_height<=max_resizer_height))
   {
      resizer_cfg.csf=RESZ_CS_1_1;
   }
   else if ((src_width<(max_resizer_width<<1)) &&
            (src_height<(max_resizer_height<<1)))
   {
      resizer_cfg.csf=RESZ_CS_1_4;
      src_width>>=1;
      src_height>>=1;
   }
   else if ((src_width<=(max_resizer_width<<2)) &&
            (src_height<=(max_resizer_height<<2)))
   {
      resizer_cfg.csf=RESZ_CS_1_16;
      src_width>>=2;
      src_height>>=2;
   }
    #if defined(MT6219) // hardware issue: CS 1/64 will be error in YUV444 format
   else if((jpeg_file_para.y_h_sample_factor==1) &&
      (jpeg_file_para.y_v_sample_factor==1))
   {
     resizer_cfg.csf=RESZ_CS_1_16;
          src_width>>=2;
           src_height>>=2;
   }
    #endif
   else
   {
      resizer_cfg.csf=RESZ_CS_1_64;
      src_width>>=3;
      src_height>>=3;
   }

   if (src_width>2047)
      return (JPEG_DECODE_SRC_WIDHT_TOO_LARGE_FAIL);
   if (src_height>2047)
      return (JPEG_DECODE_SRC_HEIGHT_TOO_LARGE_FAIL);
   if ((*target_width)>2047)
      return (JPEG_DECODE_TARGET_WIDTH_TOO_LARGE_FAIL);
   if ((*target_height)>2047)
      return (JPEG_DECODE_TARGET_HEIGHT_TOO_LARGE_FAIL);

   resizer_cfg.hy=jpeg_file_para.y_h_sample_factor>>1;
   resizer_cfg.vy=jpeg_file_para.y_v_sample_factor>>1;
   if (jpeg_file_para.number_of_component==1)
   {
      resizer_cfg.hu=RESZ_HU_SF_NONE;
      resizer_cfg.vu=RESZ_VU_SF_NONE;
      resizer_cfg.hv=RESZ_HV_SF_NONE;
      resizer_cfg.vv=RESZ_VV_SF_NONE;
   }
   else if (jpeg_file_para.number_of_component==3)
   {
      resizer_cfg.hu=jpeg_file_para.u_h_sample_factor>>1;
      resizer_cfg.vu=jpeg_file_para.u_v_sample_factor>>1;
      resizer_cfg.hv=jpeg_file_para.v_h_sample_factor>>1;
      resizer_cfg.vv=jpeg_file_para.v_v_sample_factor>>1;
   }

   if ((*target_width>src_width)||(*target_height>src_height))
   {
      resizer_cfg.ylbsize=((jpeg_file_para.y_v_sample_factor<<3)+jpeg_file_para.y_v_sample_factor);
      resizer_cfg.ulbsize=((jpeg_file_para.u_v_sample_factor<<3)+jpeg_file_para.u_v_sample_factor);
      resizer_cfg.vlbsize=((jpeg_file_para.v_v_sample_factor<<3)+jpeg_file_para.v_v_sample_factor);
   }
   else
   {
      resizer_cfg.ylbsize=(jpeg_file_para.y_v_sample_factor<<3);
      resizer_cfg.ulbsize=(jpeg_file_para.u_v_sample_factor<<3);
      resizer_cfg.vlbsize=(jpeg_file_para.v_v_sample_factor<<3);
   }

   jpeg_decode_int_mem_size += (((src_width * resizer_cfg.ylbsize) & 0xFFFFFFFC)+4);
   jpeg_decode_int_mem_size += (((src_width * resizer_cfg.ulbsize) & 0xFFFFFFFC)+4);
   jpeg_decode_int_mem_size += (((src_width * resizer_cfg.vlbsize) & 0xFFFFFFFC)+4);
   jpeg_decode_int_mem_size += (((((*target_width) * RESIZER_WORKING_MEM_LINE_NUMBER) & 0xFFFFFFFC)+4)*3);
   if (jpeg_decode_int_mem_size>jpeg_decode_config_data.intmem_size)
      return (JPEG_DECODE_INT_BUFFER_NOT_ENOUGH);

   resizer_cfg.ylmbase=(kal_uint32) intmem_get_buffer((src_width * resizer_cfg.ylbsize));
   resizer_cfg.ulmbase=(kal_uint32) intmem_get_buffer((src_width * resizer_cfg.ulbsize));
   resizer_cfg.vlmbase=(kal_uint32) intmem_get_buffer((src_width * resizer_cfg.vlbsize));

   resizer_cfg.wmsize=RESIZER_WORKING_MEM_LINE_NUMBER;

   #if (defined(MT6219))
   resizer_cfg.ywmbase=(kal_uint32) intmem_get_buffer(((*target_width) * RESIZER_WORKING_MEM_LINE_NUMBER));
   resizer_cfg.uwmbase=(kal_uint32) intmem_get_buffer(((*target_width) * RESIZER_WORKING_MEM_LINE_NUMBER));
   resizer_cfg.vwmbase=(kal_uint32) intmem_get_buffer(((*target_width) * RESIZER_WORKING_MEM_LINE_NUMBER));
   #else
   resizer_cfg.ywmbase=(kal_uint32) intmem_get_buffer(((*target_width) * RESIZER_WORKING_MEM_LINE_NUMBER)*3);
   #endif

   RESZ_Open(resizer_dcb.owner);
   RESZ_Config((RESZ_CFG_STRUCT *) &resizer_dcb.cfg,&resizer_cfg, resizer_dcb.owner);
   RESZ_SetSize(src_width, src_height, *target_width, *target_height,resizer_dcb.owner);
   RESZ_Start(resizer_dcb.owner);

   _img_resizer_opened = 1;
   return 0;
#else
   return 0;
#endif
}  /* config_block_resizer() */
#endif



/// for encoding JPEG from camera only.
void jfif_thumbnail_swap(kal_uint32 jpeg_file_addr)
{
#if (defined(DRV_JPG_DEC_28_SERIES))
   kal_uint8 *jpg_file_ptr;
   kal_uint8 thumbnail_width,thumbnail_height;
   kal_uint8 i,j,r_data;

   jpg_file_ptr = (kal_uint8 *) jpeg_file_addr;

   if ((*(jpg_file_ptr)==0xFF) && (*(jpg_file_ptr+1)==0xD8) && (*(jpg_file_ptr+2)==0xFF) &&
       (*(jpg_file_ptr+3)==0xE0) && (*(jpg_file_ptr+6)=='J') && (*(jpg_file_ptr+7)=='F') &&
       (*(jpg_file_ptr+8)=='I') && (*(jpg_file_ptr+9)=='F'))
   {
      thumbnail_width=*(jpg_file_ptr+18);
      thumbnail_height=*(jpg_file_ptr+19);
      jpg_file_ptr+=20;
      for (i=0;i<thumbnail_height;i++)
      {
         for (j=0;j<thumbnail_width;j++)
         {
            r_data=*(jpg_file_ptr+2);
            *(jpg_file_ptr+2)=*jpg_file_ptr;
            *jpg_file_ptr= r_data;
            jpg_file_ptr+=3;
         }
      }
   }
#endif
}  /* jfif_thumbnail_swap() */



/*************************************************************************
* FUNCTION
*     config_jpeg_encoder
*
* DESCRIPTION
*     This function config the JPEG encoder engine
*
* PARAMETERS
*     jpeg_data    the data structure pointer for JPEG encode process
*
* RETURNS
*     KAL_TRUE    :  JPEG encoder configuration complete
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if (defined(DRV_JPG_HW_ENC_SUPPORT))
kal_uint8 config_jpeg_encoder(jpeg_encode_process_struct *jpeg_data)
{
   RESET_JPEG_ENCODER;
   ENABLE_JPEG_ENCODER_INT;

   DRV_WriteReg32(JPEG_ENCODER_DEST_ADDR_REG,jpeg_data->jpeg_file_start_address);
   DRV_WriteReg32(JPEG_ENCODER_STOP_ADDR_REG,(jpeg_data->jpeg_file_start_address+
                  jpeg_data->jpeg_file_buffer_size-4)&0xFFFFFFFC);
   DRV_WriteReg32(JPEG_ENCODER_QUALITY_REG,jpeg_data->image_quality);
   if (jpeg_data->jpeg_gray_mode)
   {
      SET_JPEG_ENCODER_GRAY_MODE;
   }
   else
   {
      SET_JPEG_ENCODER_COLOR_MODE;
   }

   #if (defined(DRV_JPG_ENC_28_SERIES))
   DISABLE_JPEG_ENCODER_JFIF_MODE;
   DISABLE_JPEG_ENCODER_CONT_SHOT;
   DISABLE_JPEG_ENCODER_ADDR_SWITCH;
   #endif
   jpeg_encoder_operation_state=JPEG_ENCODER_ENCODING_STATE;
   ENABLE_JPEG_ENCODER;
   return KAL_TRUE;
}  /* config_jpeg_encoder() */
#endif   /* MT6219, MT6226,MT6227, MT6228, MT6229*/

/*************************************************************************
* FUNCTION
*     decode_jpeg_next_block
*
* DESCRIPTION
*     This function continue to decode the next block of jpeg file.
*
* PARAMETERS
*
* RETURNS
*     0     :  if jpeg file decode procedure start correctly
*  others   :  if jpeg file decode procedure can not start due to some mistake
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 decode_jpeg_next_block(void)
{
   #if (defined(DRV_JPG_SW_DEC_SUPPORT))
     ASSERT(0);

   #elif (defined(DRV_JPG_HW_DEC_SUPPORT))

   volatile kal_uint8 read_data;
   kal_uint32 jpeg_file_handle,fs_read_size;
   kal_uint32 jpeg_file_buffer_size;
   kal_uint8 *jpg_file_ptr;
   volatile kal_uint32 i,maxcount=10;
   kal_bool restart_jpeg_flag=KAL_FALSE;

   jpeg_file_handle=jpeg_decode_config_data.jpeg_file_handle;
   jpg_file_ptr=(kal_uint8 *) jpeg_decode_config_data.jpeg_file_buffer_address;
   jpeg_file_buffer_size=jpeg_decode_config_data.jpeg_file_buffer_size-16;

   if (jpeg_decoder_operation_state==JPEG_DECODER_DECODING_STATE)
   {
      if ((jpeg_file_offset==jpeg_file_para.thumbnail_offset)&&
          ((jpeg_decode_config_data.jpeg_file_buffer_size-16)<jpeg_decode_config_data.jpeg_file_size))
      {
         restart_jpeg_flag=KAL_TRUE;
         jpeg_decode_config_data.rest_jpeg_file_size=jpeg_decode_config_data.jpeg_file_size;
      }

      jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_offset , FS_FILE_BEGIN);
      jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, jpeg_file_buffer_size, &fs_read_size);
      if (fs_read_size<jpeg_file_buffer_size)
         jpeg_decode_config_data.rest_jpeg_file_size=0;
      else
      {
         jpeg_decode_config_data.rest_jpeg_file_size-=jpeg_file_buffer_size;
         jpeg_file_offset+=jpeg_file_buffer_size;
         jpeg_decode_next_block=KAL_TRUE;
      }
      if (jpeg_decode_config_data.rest_jpeg_file_size==0)
      {
         jpeg_file_offset=jpeg_file_para.thumbnail_offset;
         if ((jpeg_file_buffer_size-fs_read_size)<16)
            jpeg_decode_break=KAL_TRUE;

         if (jpeg_file_without_eoi==KAL_FALSE)
         {
         read_data=*(jpg_file_ptr+fs_read_size);
         while (read_data!=0xD9 && fs_read_size!=0)
         {
            fs_read_size--;
            read_data=*(jpg_file_ptr+fs_read_size);
         }
         fs_read_size++;
         jpeg_decode_next_block=KAL_FALSE;

         /// Rey: CR 00235911
         if (jpeg_file_handle) {
            for (i = 0; i < 16; i++) {
               if ((fs_read_size + i) < jpeg_file_buffer_size) {
                  *(jpg_file_ptr + fs_read_size + i) = 0;
               }
            }
         }
      }
      }
      jpeg_decoder_decode_result=0;
      REG_JPEG_DECODER_JPEG_FILE_START_ADDR=(kal_uint32) jpg_file_ptr;
      if ((jpeg_file_para.jpg_progressive==KAL_TRUE)&& (restart_jpeg_flag==KAL_TRUE))
      {
   #if (defined(DRV_JPG_DEC_17_SERIES)||defined(DRV_JPG_DEC_19_SERIES))
         IRQUnmask(IRQ_JPEG_CODE);
   #elif (defined(DRV_JPG_DEC_28_SERIES))
         IRQUnmask(IRQ_JPEG_DEC_CODE);
#endif
         START_JPEG_DECODER;
      }

      for(i=0;i<maxcount;i++)
      {
         kal_sleep_task(1);
         if (REG_JPEG_DECODER_JPEG_FILE_START_ADDR!=(kal_uint32) jpg_file_ptr)
            break;
      }
      if(i==maxcount && jpeg_decode_config_data.jpeg_decode_cb!=NULL)
       jpeg_decode_config_data.jpeg_decode_cb(JPEG_DECODE_BUFFER_SIZE_FAIL);

   }
   #endif
 return 0;

}  /* decode_jpeg_next_block() */

/*************************************************************************
* FUNCTION
*     decode_jpeg_file
*
* DESCRIPTION
*     This function start to decode a jpeg file.
*
* PARAMETERS
*
* RETURNS
*     0     :  if jpeg file decode procedure start correctly
*  others   :  if jpeg file decode procedure can not start due to some mistake
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 decode_jpeg_file(void)
{
   volatile kal_uint8 read_data;
   kal_uint8 return_code;
   kal_uint32 jpeg_file_size,jpeg_file_handle,fs_read_size;
   kal_uint8 *jpg_file_ptr;
   kal_uint32 jpeg_file_buffer_size;
   volatile kal_uint16 i, j;

#if (defined(DRV_JPG_DEC_17_SERIES)||defined(DRV_JPG_DEC_19_SERIES))
   kal_uint16 target_width, target_height;
#endif

#if (defined(DRV_JPG_DEC_19_SERIES)||defined(DRV_JPG_DEC_28_SERIES))
   MMDI_SCENERIO_ID scenario_id=SCENARIO_JPEG_DECODE_ID;
#endif
   jpeg_driver_status=0;
   jpeg_decoder_decode_result=0;
   jpeg_decode_next_block=KAL_FALSE;
   jpg_file_ptr=(kal_uint8 *) jpeg_decode_config_data.jpeg_file_buffer_address;
   jpeg_file_buffer_size=jpeg_decode_config_data.jpeg_file_buffer_size;
   jpeg_file_handle=jpeg_decode_config_data.jpeg_file_handle;

#if(defined(DRV_JPG_SW_DEC_SUPPORT))
   if (jpeg_file_handle!=0)
   {
      jpeg_dec_intmem_init((kal_uint32 *) jpeg_decode_config_data.intmem_start_address,jpeg_decode_config_data.intmem_size);
      return_code=sw_jpeg_decode(jpeg_file_handle);
      jpeg_dec_intmem_deinit();
      return (return_code);
   }
   else
   {
      jpeg_dec_intmem_init((kal_uint32 *) jpeg_decode_config_data.intmem_start_address,jpeg_decode_config_data.intmem_size);
      return_code=sw_jpeg_decode(0);
        jpeg_dec_intmem_deinit();
      return (return_code);
   }
#elif(defined(DRV_JPG_HW_DEC_SUPPORT))
   if(jpeg_file_handle!=0)
   {
    parse_jpeg_file(jpeg_file_handle,jpg_file_ptr,jpeg_file_buffer_size);
   }
   else
   {
      parse_jpeg_file(jpeg_file_handle,jpg_file_ptr,jpeg_decode_config_data.jpeg_file_size);
   }

   if(jpeg_driver_status!=0)
    return jpeg_driver_status;

   if(jpeg_decode_config_data.jpeg_decode_retry_flag==JPEG_DECODER_RETRY_THUMBNAIL &&
      jpeg_file_para.jfif_mode==NO_THUMBNAIL_MODE)
      return JPEG_DECODE_NO_THUMBNAIL_FAIL;

   if (((jpeg_file_para.jpg_height==0xFFFF) && (jpeg_file_para.jpg_width)==0xFFFF))
      return (JPEG_DECODE_WRONG_JPEG_FILE);
   if ((jpeg_decode_config_data.jpeg_decode_retry_flag!=JPEG_DECODER_RETRY_THUMBNAIL)&&
       (jpeg_thumbnail_mode==KAL_TRUE)&&(jpeg_file_para.jfif_mode!=NO_THUMBNAIL_MODE))
   {
      if ((jpeg_file_para.jpg_width<jpeg_decode_config_data.image_width) ||
          (jpeg_file_para.jpg_height<jpeg_decode_config_data.image_height))
      {
         jpeg_decode_config_data.jpeg_thumbnail_mode=KAL_FALSE;
         jpeg_thumbnail_mode=KAL_FALSE;
         if (jpeg_file_handle!=0)
            parse_jpeg_file(jpeg_file_handle,jpg_file_ptr,jpeg_file_buffer_size);
         else
            parse_jpeg_file(jpeg_file_handle,jpg_file_ptr,jpeg_decode_config_data.jpeg_file_size);

         if(jpeg_driver_status!=0)
          return jpeg_driver_status;

         if (((jpeg_file_para.jpg_height==0xFFFF) && (jpeg_file_para.jpg_width)==0xFFFF))
            return (JPEG_DECODE_WRONG_JPEG_FILE);
      }
   }
   if (jpeg_decode_config_data.jpeg_thumbnail_mode==KAL_TRUE)
   {
   #if (defined(DRV_RGB_RESIZE_SUPPORT))
      if ((jpeg_file_para.jfif_mode==JFIF_MODE_RGB)||(jpeg_file_para.jfif_mode==JFIF_EXTENSION_MODE_RGB)||
          (jpeg_file_para.jfif_mode==EXIF_MODE_RGB))
      {  /* RGB888 mode */
         return (JPEG_DECODE_RGB_THUMBNAIL);
      }
   #endif
   }

   jpeg_decode_int_mem_size=0;
   jpeg_decode_ext_mem_size=0;
#if (defined(DRV_JPG_DEC_17_SERIES))
   #if (!defined(DRV_JPEG_DEC_GRAYSCALE_SUPPORT))
   if (jpeg_file_para.number_of_component<3)
   {
      return(JPEG_DECODE_NO_UV_COMPONENT);
   }
#endif   /* MT6218B */

   #if(defined(DRV_JPG_DATA_PATH_17_SERIES))
   return_code=config_block_resizer(&target_width, &target_height);
   #else
    #error "JPEG deocder 17 series must work with 17 data path  !!"
   #endif
   if (return_code)
      return return_code;

   kal_set_eg_events(jpeg_codec_event_id,0,KAL_AND);

   if (jpeg_file_handle!=0)
   {
      jpeg_file_buffer_size-=16;
      if ((jpeg_decode_config_data.jpeg_thumbnail_mode==KAL_TRUE)&&
          ((jpeg_file_para.jfif_mode==JFIF_EXTENSION_MODE_JPEG)||(jpeg_file_para.jfif_mode==EXIF_MODE_JPEG)))
      {
         jpeg_file_size=jpeg_file_para.thumbnail_size;
         jpeg_file_offset=jpeg_file_para.thumbnail_offset;
         jpeg_decode_config_data.jpeg_file_size=jpeg_file_size;
         jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_para.thumbnail_offset, FS_FILE_BEGIN);
         if (jpeg_file_size>=jpeg_file_buffer_size)
         {
            jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, jpeg_file_buffer_size, &fs_read_size);
            jpeg_decode_config_data.rest_jpeg_file_size=jpeg_file_size-jpeg_file_buffer_size+16;
            jpeg_file_offset+=jpeg_file_buffer_size;
            jpeg_decode_next_block=KAL_TRUE;
         }
         else
         {
            jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, jpeg_file_size, &fs_read_size);
            jpeg_decode_config_data.rest_jpeg_file_size=0;
            if ((jpeg_file_buffer_size-fs_read_size)<16)
               jpeg_decode_break=KAL_TRUE;
         }
      }
      else
      {
         DRM_file_size((FS_HANDLE) jpeg_file_handle, &jpeg_file_size);
         jpeg_file_size-=jpeg_file_para.thumbnail_offset;
         jpeg_file_offset=jpeg_file_para.thumbnail_offset;
         jpeg_decode_config_data.jpeg_file_size=jpeg_file_size;
         jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_para.thumbnail_offset, FS_FILE_BEGIN);
         jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, jpeg_file_buffer_size, &fs_read_size);
         jpeg_decode_config_data.rest_jpeg_file_size=jpeg_file_size + 32;
         if (fs_read_size<jpeg_file_buffer_size)
            jpeg_decode_config_data.rest_jpeg_file_size=0;
         else
         {
            jpeg_decode_config_data.rest_jpeg_file_size-=jpeg_file_buffer_size;
            jpeg_file_offset+=jpeg_file_buffer_size;
            jpeg_decode_next_block=KAL_TRUE;
         }
      }

      if (jpeg_decode_config_data.rest_jpeg_file_size==0)
      {
         jpeg_file_offset=jpeg_file_para.thumbnail_offset;
         if ((jpeg_file_buffer_size-fs_read_size)<16)
            jpeg_decode_break=KAL_TRUE;
         if (jpeg_file_without_eoi==KAL_FALSE)
         {
         read_data=*(jpg_file_ptr+fs_read_size);
         while (read_data!=0xD9 && fs_read_size!=0)
         {
            fs_read_size--;
            read_data=*(jpg_file_ptr+fs_read_size);
         }
         fs_read_size++;
         jpeg_decode_next_block=KAL_FALSE;

         for (i = 0; i < 16; i++) {
            if ((fs_read_size + i) < jpeg_file_buffer_size) {
               *(jpg_file_ptr + fs_read_size + i) = 0;
            }
         }
      }
      }

      return_code=config_jpeg_decoder((kal_uint32) jpg_file_ptr,fs_read_size);

      if (return_code)
         return return_code;

      jpeg_decoder_operation_state=JPEG_DECODER_DECODING_STATE;
   }
   else
   {
      jpeg_decode_next_block=KAL_FALSE;
      if ((jpeg_decode_config_data.jpeg_thumbnail_mode==KAL_TRUE)&&
          ((jpeg_file_para.jfif_mode==JFIF_EXTENSION_MODE_JPEG)||(jpeg_file_para.jfif_mode==EXIF_MODE_JPEG)))
      {
         /// Rey: CR 00235911
         /*
         jpg_file_ptr = (kal_uint8 *) (jpeg_decode_config_data.jpeg_file_buffer_address +
                                       jpeg_file_para.thumbnail_offset +
                                       jpeg_file_para.thumbnail_size - 16);
         for (i = 0; i < 32; i++) {
            if ((*(jpg_file_ptr + i) == 0xFF) && (*(jpg_file_ptr + i + 1) == 0xD9)) {
               for (i = (i + 2); i < 32; i++) {
                  *(jpg_file_ptr + i) = 0;
               }
            }
         }
         */

         return_code=config_jpeg_decoder((jpeg_decode_config_data.jpeg_file_buffer_address+jpeg_file_para.thumbnail_offset),
                                         (jpeg_file_para.thumbnail_size+32));
      }
      else
      {
         /// Rey: CR 00235911
         /*
         jpg_file_ptr = (kal_uint8 *) (jpeg_decode_config_data.jpeg_file_buffer_address +
                                       jpeg_decode_config_data.jpeg_file_size - 16);
         for (i = 0; i < 16; i++) {
            if ((*(jpg_file_ptr + i) == 0xFF) && (*(jpg_file_ptr + i + 1) == 0xD9)) {
               for (i = (i + 2); i < 16; i++) {
                  *(jpg_file_ptr + i)=0;
               }
            }
         }
         */

         return_code=config_jpeg_decoder(jpeg_decode_config_data.jpeg_file_buffer_address+jpeg_file_para.thumbnail_offset,
                     (jpeg_decode_config_data.jpeg_file_size-jpeg_file_para.thumbnail_offset+32));
      }
      if (return_code)
         return return_code;
      jpeg_decoder_operation_state=JPEG_DECODER_DECODING_STATE;
   }
   return JPEG_DECODE_DECODING;

#elif (defined(DRV_JPG_DEC_19_SERIES)||defined(DRV_JPG_DEC_28_SERIES))
   #if (defined(DRV_JPG_DATA_PATH_19_SERIES))
   return_code = config_block_resizer(&target_width, &target_height);
   if (return_code) {
      return return_code;
   }

   config_image_dma(scenario_id, target_width, target_height);
   _img_dma_opened = 1;

   config_image_processor(scenario_id);
   _img_processor_opened = 1;

   #elif (defined(DRV_JPG_DATA_PATH_28_SERIES))
   open_image_data_path(SCENARIO_JPEG_DECODE_ID);
   _idp_opened = 1;
   
   return_code=config_jpeg_decode_data_path(scenario_id,&jpeg_decode_config_data);
      if (return_code)
         return return_code;
   #endif
   kal_set_eg_events(jpeg_codec_event_id,0,KAL_AND);
   if (jpeg_file_handle!=0)
   {
      jpeg_file_buffer_size-=16;
      if ((jpeg_decode_config_data.jpeg_thumbnail_mode==KAL_TRUE)&&
          ((jpeg_file_para.jfif_mode==JFIF_EXTENSION_MODE_JPEG)||(jpeg_file_para.jfif_mode==EXIF_MODE_JPEG)))
      {
         jpeg_file_size=jpeg_file_para.thumbnail_size;
         jpeg_file_offset=jpeg_file_para.thumbnail_offset;
         jpeg_decode_config_data.jpeg_file_size=jpeg_file_size;
         jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_para.thumbnail_offset, FS_FILE_BEGIN);
         if (jpeg_file_size>=jpeg_file_buffer_size)
         {
            jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, jpeg_file_buffer_size, &fs_read_size);
//          jpeg_decode_config_data.rest_jpeg_file_size=jpeg_file_size-jpeg_file_buffer_size+16;
            jpeg_decode_config_data.rest_jpeg_file_size=jpeg_file_size+32;
            jpeg_file_offset+=jpeg_file_buffer_size;
            jpeg_decode_next_block=KAL_TRUE;
         }
         else
         {
            jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, jpeg_file_size, &fs_read_size);
            jpeg_decode_config_data.rest_jpeg_file_size=0;
         }
      }
      else
      {
         DRM_file_size((FS_HANDLE) jpeg_file_handle, &jpeg_file_size);
         jpeg_file_size-=jpeg_file_para.thumbnail_offset;
         jpeg_file_offset=jpeg_file_para.thumbnail_offset;
         jpeg_decode_config_data.jpeg_file_size=jpeg_file_size;
   //    jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, 0, FS_FILE_BEGIN);
         jpeg_DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_para.thumbnail_offset, FS_FILE_BEGIN);
         jpeg_DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, jpeg_file_buffer_size, &fs_read_size);
//       jpeg_decode_config_data.rest_jpeg_file_size=jpeg_file_size-jpeg_file_offset+16;
         jpeg_decode_config_data.rest_jpeg_file_size=jpeg_file_size+32;
         if (fs_read_size<jpeg_file_buffer_size)
            jpeg_decode_config_data.rest_jpeg_file_size=0;
         else
         {
            jpeg_decode_config_data.rest_jpeg_file_size-=jpeg_file_buffer_size;
            jpeg_file_offset+=jpeg_file_buffer_size;
            jpeg_decode_next_block=KAL_TRUE;
         }
      }
      if (jpeg_decode_config_data.rest_jpeg_file_size==0)
      {
         jpeg_file_offset=jpeg_file_para.thumbnail_offset;
         if ((jpeg_file_buffer_size-fs_read_size)<16)
            jpeg_decode_break=KAL_TRUE;
         if (jpeg_file_without_eoi==KAL_FALSE)
         {
         read_data=*(jpg_file_ptr+fs_read_size);
         while (read_data!=0xD9 && fs_read_size!=0)
         {
            fs_read_size--;
            read_data=*(jpg_file_ptr+fs_read_size);
         }
         fs_read_size++;
         jpeg_decode_next_block=KAL_FALSE;

         for (i = 0; i < 16; i++) {
            if ((fs_read_size + i) < jpeg_file_buffer_size) {
               *(jpg_file_ptr + fs_read_size + i)=0;
            }
         }
      }
      }

      return_code=config_jpeg_decoder((kal_uint32) jpg_file_ptr,fs_read_size);

      if (return_code)
         return return_code;

      jpeg_decoder_operation_state=JPEG_DECODER_DECODING_STATE;
   }
   else
   {
      jpeg_decode_next_block=KAL_FALSE;
      if ((jpeg_decode_config_data.jpeg_thumbnail_mode==KAL_TRUE)&&
          ((jpeg_file_para.jfif_mode==JFIF_EXTENSION_MODE_JPEG)||(jpeg_file_para.jfif_mode==EXIF_MODE_JPEG)))
      {
         /// Rey: CR 00235911
         /*
         if (jpeg_file_handle) {
            jpg_file_ptr = (kal_uint8 *) (jpeg_decode_config_data.jpeg_file_buffer_address +
                                          jpeg_file_para.thumbnail_offset +
                                          jpeg_file_para.thumbnail_size - 16);
            for (i = 0; i < 32; i++) {
               if ((*(jpg_file_ptr + i) == 0xFF) && (*(jpg_file_ptr + i + 1) == 0xD9)) {
                  for (i = (i + 2); i < 32; i++) {
                     *(jpg_file_ptr + i) = 0;
                  }
               }
            }
         }
         */

         return_code=config_jpeg_decoder((jpeg_decode_config_data.jpeg_file_buffer_address+jpeg_file_para.thumbnail_offset),
                                         (jpeg_file_para.thumbnail_size+32));
      }
      else
      {
         /// Rey: CR 00235911
         /*
         if (jpeg_file_handle) {
            jpg_file_ptr = (kal_uint8 *) (jpeg_decode_config_data.jpeg_file_buffer_address +
                                          jpeg_decode_config_data.jpeg_file_size - 16);

            for (i = 0; i < 16; i++) {
               if ((*(jpg_file_ptr + i) == 0xFF) && (*(jpg_file_ptr + i + 1) == 0xD9)) {
                  for (i = (i + 2); i < 16; i++) {
                     *(jpg_file_ptr + i)=0;
                  }
               }
            }
         }
         */
         return_code=config_jpeg_decoder(jpeg_decode_config_data.jpeg_file_buffer_address+jpeg_file_para.thumbnail_offset,
                     (jpeg_decode_config_data.jpeg_file_size-jpeg_file_para.thumbnail_offset+32));
      }
      if (return_code)
         return return_code;
      jpeg_decoder_operation_state=JPEG_DECODER_DECODING_STATE;
   }
   return JPEG_DECODE_DECODING;
#endif
#endif   //DRV_JPG_HW_DEC_SUPPORT
}   /* decode_jpeg_file() */

/*************************************************************************
* FUNCTION
*     resize_jpeg_thumbnail
*
* DESCRIPTION
*     This function resize the thumbnail of JPEG file when it is in RGB888 format
*
* PARAMETERS
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if (defined(DRV_RGB_RESIZE_SUPPORT))
void resize_jpeg_thumbnail(void)
{
   kal_uint32 jpeg_file_handle = 0;
   kal_uint32 fs_read_size = 0;
   kal_uint32 jpeg_file_offset = 0;
   kal_uint8 *jpg_file_ptr;
   kal_uint32 jpeg_file_buffer_size;
   kal_uint8 resize_times;
   kal_uint16 resize_src_width, resize_src_height, rest_src_height;
   kal_uint16 resize_tar_width, resize_tar_height, rest_tar_height;

   jpeg_file_buffer_size = jpeg_decode_config_data.jpeg_file_buffer_size;

   if (jpeg_decode_config_data.jpeg_file_handle) {
      jpg_file_ptr =(kal_uint8 *) jpeg_decode_config_data.jpeg_file_buffer_address;
      jpeg_file_handle = jpeg_decode_config_data.jpeg_file_handle;
      jpeg_file_offset = jpeg_file_para.thumbnail_offset;
      resize_times = (jpeg_file_para.thumbnail_size / jpeg_decode_config_data.jpeg_file_buffer_size);

      if (jpeg_file_para.thumbnail_size % jpeg_decode_config_data.jpeg_file_buffer_size) {
         resize_times += 1;
      }
   } else {
      resize_times = 1;
   }

   rest_src_height   = jpeg_file_para.jpg_height;
   rest_tar_height   = jpeg_decode_config_data.image_height;
   resize_src_width  = jpeg_file_para.jpg_width;
   resize_src_height = jpeg_file_para.jpg_height / resize_times;
   resize_tar_width  = jpeg_decode_config_data.image_width;
   resize_tar_height = jpeg_decode_config_data.image_height / resize_times;
   rest_src_height   -= resize_src_height;
   rest_tar_height   -= resize_tar_height;

   if (jpeg_file_handle) {
      DRM_seek_file((FS_HANDLE)jpeg_file_handle, jpeg_file_offset, FS_FILE_BEGIN);
      DRM_read_file((FS_HANDLE)jpeg_file_handle, jpg_file_ptr, resize_src_width * resize_src_height * 3, &fs_read_size);
      thumbnail_resize_data.src_image_address = jpeg_decode_config_data.jpeg_file_buffer_address;

   } else {
      thumbnail_resize_data.src_image_address = jpeg_decode_config_data.jpeg_file_buffer_address + jpeg_file_para.thumbnail_offset;
      resize_times = 1;
   }

   thumbnail_resize_data.intmem_start_address = jpeg_decode_config_data.intmem_start_address;
   thumbnail_resize_data.intmem_size          = jpeg_decode_config_data.intmem_size;
   thumbnail_resize_data.extmem_start_address = jpeg_decode_config_data.extmem_start_address;
   thumbnail_resize_data.extmem_size          = jpeg_decode_config_data.extmem_size;
   thumbnail_resize_data.type                 = IBR1_TYPE_RGB888;
   thumbnail_resize_data.data_order           = IBR1_ORDER_RGB888;

   thumbnail_resize_data.dest_image_address   = jpeg_decode_config_data.image_buffer_address;
   thumbnail_resize_data.dest_buffer_size     = jpeg_decode_config_data.image_buffer_size;
   thumbnail_resize_data.src_width            = resize_src_width;
   thumbnail_resize_data.src_height           = resize_src_height;
   thumbnail_resize_data.src_pitch            = resize_src_width;
   thumbnail_resize_data.target_width         = resize_tar_width;
   thumbnail_resize_data.target_height        = resize_tar_height;

#if(defined(DRV_IMG_CLIP_SUPPORT))
   thumbnail_resize_data.image_clip_x1 = jpeg_decode_config_data.image_clip_x1;
   thumbnail_resize_data.image_clip_x2 = jpeg_decode_config_data.image_clip_x2;
   thumbnail_resize_data.image_clip_y1 = jpeg_decode_config_data.image_clip_y1;
   thumbnail_resize_data.image_clip_y2 = jpeg_decode_config_data.image_clip_y2;
#endif

#if (defined(DRV_IMG_PITCH_MODE_SUPPORT))
   thumbnail_resize_data.image_pitch_mode = jpeg_decode_config_data.image_pitch_mode;
   thumbnail_resize_data.image_pitch_bytes = jpeg_decode_config_data.image_pitch_bytes;
#endif

#if (defined(DRV_IMG_RGB888_OUTPUT_SUPPORT))
   thumbnail_resize_data.image_data_format = jpeg_decode_config_data.image_data_format;
#endif

   image_resize_process(&thumbnail_resize_data);

   while (rest_tar_height) {
      jpeg_file_offset += resize_src_width*resize_src_height * 3;

#if (defined(DRV_IMG_RGB888_OUTPUT_SUPPORT))
      if (IMGDMA_IBW_OUTPUT_RGB565 == jpeg_decode_config_data.image_data_format) {
         thumbnail_resize_data.dest_image_address += resize_tar_width*resize_tar_height * 2;
         thumbnail_resize_data.dest_buffer_size   -= resize_tar_width*resize_tar_height * 2;

      } else if (IMGDMA_IBW_OUTPUT_RGB888 == jpeg_decode_config_data.image_data_format) {
         thumbnail_resize_data.dest_image_address += resize_tar_width*resize_tar_height * 3;
         thumbnail_resize_data.dest_buffer_size   -= resize_tar_width*resize_tar_height * 3;
      }
#else
      thumbnail_resize_data.dest_image_address += resize_tar_width * resize_tar_height * 2;
      thumbnail_resize_data.dest_buffer_size   -= resize_tar_width * resize_tar_height * 2;
#endif

      if (rest_src_height < resize_src_height) {
         resize_src_height = rest_src_height;
         resize_tar_height = rest_tar_height;
         rest_src_height = 0 ;
         rest_tar_height = 0;
      } else {
         rest_src_height -= resize_src_height;
         rest_tar_height -= resize_tar_height;
      }

      DRM_seek_file((FS_HANDLE)jpeg_file_handle, jpeg_file_offset, FS_FILE_BEGIN);
      DRM_read_file((FS_HANDLE)jpeg_file_handle, jpg_file_ptr, resize_src_width * resize_src_height * 3, &fs_read_size);

      thumbnail_resize_data.src_height    = resize_src_height;
      thumbnail_resize_data.target_height = resize_tar_height;
      thumbnail_resize_data.src_pitch     = resize_src_width;

   #if defined(DRV_IMG_CLIP_SUPPORT)
      thumbnail_resize_data.image_clip_y2 = resize_tar_height - 1;
   #endif
      image_resize_process(&thumbnail_resize_data);
   }
}  /* resize_jpeg_thumbnail() */
#endif
/*************************************************************************
* FUNCTION
*     jpeg_decode_process
*
* DESCRIPTION
*     This function start the jpeg decode process.
*
* PARAMETERS
*  *jpeg_decode_para : the required parameters for JPEG decode process
*
* RETURNS
*   return_code : the JPEG decode process error code
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 jpeg_decode_process(jpeg_decode_process_struct *jpeg_decode_para)
{
   kal_uint8 return_code;

#if defined(DRV_JPG_HW_DEC_SUPPORT) && defined(__MTK_TARGET__)
   if (JPEG_DECODER_STANDBY_STATE != jpeg_decoder_operation_state) {
      ASSERT(0);
   }
#endif

#if defined(DRV_IMG_MEM_OUTPUT_SUPPORT)
   if (jpeg_decode_para->jpeg_thumbnail_mode && jpeg_decode_para->memory_output) {
      ASSERT(0);
   }
#endif

   if ((jpeg_decode_para->image_height == 0)||(jpeg_decode_para->image_width == 0)) {
      return (JPEG_DECODE_TARGET_SIZE_FAIL);
   }

#if defined(MT6219)
   if (jpeg_decode_para->image_width < 3) {
      jpeg_decode_para->image_width = 3;
   }
#endif

   if ((jpeg_decode_para->image_width < 64) && (jpeg_decode_para->image_height < 64)) {
      jpeg_decode_config_data.jpeg_thumbnail_mode = KAL_TRUE;
      jpeg_decode_para->jpeg_thumbnail_mode = KAL_TRUE;
      jpeg_thumbnail_mode = KAL_TRUE;
   } else {
      jpeg_decode_config_data.jpeg_thumbnail_mode = KAL_FALSE;
      jpeg_decode_para->jpeg_thumbnail_mode = KAL_FALSE;
      jpeg_thumbnail_mode = KAL_FALSE;
   }

   /* Retry to decode thumbnail image instead of original image */
   jpeg_decode_config_data.jpeg_decode_retry_flag = jpeg_decode_para->jpeg_decode_retry_flag;

   if (JPEG_DECODER_RETRY_THUMBNAIL == jpeg_decode_para->jpeg_decode_retry_flag) {
      jpeg_decode_config_data.jpeg_thumbnail_mode = KAL_TRUE;
      jpeg_decode_para->jpeg_thumbnail_mode = KAL_TRUE;
      jpeg_thumbnail_mode = KAL_TRUE;
   }

   jpeg_decode_config_data.jpeg_file_handle         = jpeg_decode_para->jpeg_file_handle;
   jpeg_decode_config_data.jpeg_file_buffer_address = jpeg_decode_para->jpeg_file_buffer_address;
   jpeg_decode_config_data.jpeg_file_size           = jpeg_decode_para->jpeg_file_size;
   jpeg_decode_config_data.jpeg_file_buffer_size    = jpeg_decode_para->jpeg_file_buffer_size;
   jpeg_decode_config_data.intmem_start_address     = jpeg_decode_para->intmem_start_address;
   jpeg_decode_config_data.intmem_size              = jpeg_decode_para->intmem_size;
   jpeg_decode_config_data.extmem_start_address     = jpeg_decode_para->extmem_start_address;
   jpeg_decode_config_data.extmem_size              = jpeg_decode_para->extmem_size;
   jpeg_decode_config_data.image_buffer_address     = jpeg_decode_para->image_buffer_address;
   jpeg_decode_config_data.image_buffer_size        = jpeg_decode_para->image_buffer_size;
   jpeg_decode_config_data.image_width              = jpeg_decode_para->image_width;
   jpeg_decode_config_data.image_height             = jpeg_decode_para->image_height;
   jpeg_decode_config_data.jpeg_decode_cb           = jpeg_decode_para->jpeg_decode_cb;

#if defined(DRV_IMG_CLIP_SUPPORT)
   jpeg_decode_config_data.image_clip_x1 = jpeg_decode_para->image_clip_x1;
   jpeg_decode_config_data.image_clip_x2 = jpeg_decode_para->image_clip_x2;
   jpeg_decode_config_data.image_clip_y1 = jpeg_decode_para->image_clip_y1;
   jpeg_decode_config_data.image_clip_y2 = jpeg_decode_para->image_clip_y2;
#endif

#if defined(DRV_IMG_MEM_OUTPUT_SUPPORT)
   jpeg_decode_config_data.memory_output                = jpeg_decode_para->memory_output;
   jpeg_decode_config_data.memory_output_width          = jpeg_decode_para->memory_output_width;
   jpeg_decode_config_data.memory_output_height         = jpeg_decode_para->memory_output_height;
   jpeg_decode_config_data.memory_output_buffer_address = jpeg_decode_para->memory_output_buffer_address;
   jpeg_decode_config_data.memory_output_buffer_size    = jpeg_decode_para->memory_output_buffer_size;
#endif

#if defined(DRV_IMG_PITCH_MODE_SUPPORT)
   jpeg_decode_config_data.image_pitch_mode  = jpeg_decode_para->image_pitch_mode;
   jpeg_decode_config_data.image_pitch_bytes = jpeg_decode_para->image_pitch_bytes;
#endif

#if defined(DRV_IMG_RGB888_OUTPUT_SUPPORT)
   jpeg_decode_config_data.image_data_format = jpeg_decode_para->image_data_format;
#endif

#if defined(DRV_JPG_SW_DEC_SUPPORT)
   if(jpeg_decode_para->jpg_timeout_period > 0) {
      jpeg_decode_config_data.jpg_timeout_period = jpeg_decode_para->jpg_timeout_period;
   } else {
      jpeg_decode_config_data.jpg_timeout_period = 1000;
   }
#endif



#if defined (DRV_JPG_HW_DEC_SUPPORT) && defined(__MTK_TARGET__)

#if defined(DRV_JPG_DEC_17_SERIES)||defined(DRV_JPG_DEC_19_SERIES)
   intmem_init((kal_uint32 *) jpeg_decode_config_data.intmem_start_address,
               jpeg_decode_config_data.intmem_size);
   extmem_init((kal_uint32 *) jpeg_decode_config_data.extmem_start_address,
               jpeg_decode_config_data.extmem_size);
   jpeg_codec_power_up();
#endif
   return_code = decode_jpeg_file();

#if defined(DRV_RGB_RESIZE_SUPPORT)
   if (JPEG_DECODE_RGB_THUMBNAIL == return_code) {
      // resize image by resizer
      intmem_deinit();
      extmem_deinit();

      resize_jpeg_thumbnail();
      return JPEG_DECODE_SUCCESS;
   }
#endif

   if (JPEG_DECODE_DECODING != return_code) {
#if (defined(DRV_JPG_DEC_17_SERIES))
      stop_jpeg_decode_process();

#elif (defined(DRV_JPG_DEC_19_SERIES))

      if ((return_code == JPEG_DECODE_EXT_BUFFER_NOT_ENOUGH) ||
          (return_code == JPEG_DECODE_FILE_READ_ERROR)       ||
          (return_code == JPEG_DECODE_BUFFER_SIZE_FAIL)      ||
          (return_code == JPEG_DECODE_SUCCESS))
      {
         RESET_JPEG_DECODER;
         *((volatile unsigned int *) 0x80610004) = 0x670000;
         *((volatile unsigned int *) 0x80610004) = 0;

         if (_img_resizer_opened) {
            RESZ_Stop(SCENARIO_JPEG_DECODE_ID);
            RESZ_Close(SCENARIO_JPEG_DECODE_ID);
            _img_resizer_opened = 0;
         }

         if (_img_processor_opened) {
            IMGPROC_Stop(SCENARIO_JPEG_DECODE_ID);
            IMGPROC_Close(SCENARIO_JPEG_DECODE_ID);
            _img_processor_opened = 0;
         }

         if (_img_dma_opened) {
            stop_image_dma(SCENARIO_JPEG_DECODE_ID);
            IMGDMA_Close(SCENARIO_JPEG_DECODE_ID);
            _img_dma_opened = 0;
         }
      }
      jpeg_codec_power_down();
      intmem_deinit();
      extmem_deinit();

#elif (defined(DRV_JPG_DEC_28_SERIES))
/*
      if ((return_code == JPEG_DECODE_EXT_BUFFER_NOT_ENOUGH)   ||
          (return_code == JPEG_DECODE_BUFFER_SIZE_FAIL)        ||
          (return_code == JPEG_DECODE_INT_BUFFER_NOT_ENOUGH)   ||
          (return_code == JPEG_DECODE_TARGET_BUFFER_NOT_ENOUGH)||
          (return_code == JPEG_DECODE_FILE_READ_ERROR)         ||
          (return_code == JPEG_DECODE_SUCCESS)                 ||
          ((return_code & JPEG_DECODE_DIMENSION_FAIL) == JPEG_DECODE_DIMENSION_FAIL))
*/
      if (_idp_opened) {
         close_image_data_path(SCENARIO_JPEG_DECODE_ID);
         _idp_opened = 0;
      }
#endif
      jpeg_decoder_operation_state=JPEG_DECODER_STANDBY_STATE;
   }
   return return_code;
#else
   return_code = decode_jpeg_file();

#if (defined(DRV_JPG_HW_DEC_SUPPORT))
   jpeg_decode_config_data.jpeg_decode_cb(return_code);
#endif
   return return_code;
#endif
}  /* jpeg_decode_process() */

/*************************************************************************
* FUNCTION
*     stop_jpeg_decode_process
*
* DESCRIPTION
*     This function stops JPEG decoder processer forcely.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 stop_jpeg_decode_process(void)
{
#if (defined(DRV_JPG_DEC_19_SERIES)||defined(DRV_JPG_DEC_28_SERIES))
   MMDI_SCENERIO_ID scenario_id=SCENARIO_JPEG_DECODE_ID;
#endif

   if (jpeg_decoder_operation_state==JPEG_DECODER_IDLE_STATE)
   {
    #if (defined(DRV_JPG_SW_DEC_SUPPORT))
     return KAL_TRUE;
    #else
      ASSERT(0);
    #endif
   }

#if (defined(DRV_JPG_DEC_17_SERIES))
      IRQMask(IRQ_JPEG_CODE);
#elif (defined(DRV_JPG_DEC_19_SERIES))
      IRQMask(IRQ_JPEG_CODE);
      IRQMask(IRQ_IMGDMA_CODE);
#elif (defined(DRV_JPG_DEC_28_SERIES))
      IRQMask(IRQ_JPEG_DEC_CODE);
      IRQMask(IRQ_IMGDMA_CODE);
#endif

#if (defined(DRV_JPG_HW_DEC_SUPPORT))
   RESET_JPEG_DECODER;
#endif

#if (defined(DRV_JPG_DEC_17_SERIES))
   RESET_RESIZER;
#elif (defined(DRV_JPG_DEC_19_SERIES))
   *((volatile unsigned int *) 0x80610004)=0x670000;
   *((volatile unsigned int *) 0x80610004)=0;
#elif (defined(DRV_JPG_DEC_28_SERIES))
   RESET_PRZ;
#endif

#if (defined(DRV_JPG_DEC_19_SERIES))
   if (_img_resizer_opened) {
      RESZ_Stop(scenario_id);
      RESZ_Close(scenario_id);
      _img_resizer_opened = 0;
   }

   if (_img_processor_opened) {
      IMGPROC_Stop(scenario_id);
      IMGPROC_Close(scenario_id);
      _img_processor_opened = 0;
   }

   if (_img_dma_opened) {
      stop_image_dma(scenario_id);
      IMGDMA_Close(scenario_id);
      _img_dma_opened = 0;
   }
#endif   /* MT6219 */

#if (defined(DRV_JPG_DEC_17_SERIES)||defined(DRV_JPG_DEC_19_SERIES))
   intmem_deinit();
   extmem_deinit();
#endif

#if (defined(DRV_JPG_DEC_28_SERIES))
   if (_idp_opened) {
      close_image_data_path(scenario_id);
      _idp_opened = 0;
   }
#endif
   jpeg_decoder_operation_state=JPEG_DECODER_STANDBY_STATE;

   jpeg_codec_power_down();

#if (defined(DRV_JPG_DEC_17_SERIES))
      IRQUnmask(IRQ_JPEG_CODE);
#elif (defined(DRV_JPG_DEC_19_SERIES))
      IRQUnmask(IRQ_JPEG_CODE);
      IRQUnmask(IRQ_IMGDMA_CODE);
#elif (defined(DRV_JPG_DEC_28_SERIES))
      IRQUnmask(IRQ_JPEG_DEC_CODE);
      IRQUnmask(IRQ_IMGDMA_CODE);
#endif

   return KAL_TRUE;
}  /* stop_jpeg_decode_process() */

/*************************************************************************
* FUNCTION
*     jpeg_resize_process
*
* DESCRIPTION
*     This function resize one JPEG file as another resolution of JPEG file
*
* PARAMETERS
*  *jpeg_resize_para : the required parameters for JPEG resize process
*
* RETURNS
*   return_code : the JPEG decode process error code
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if (defined(DRV_JPG_RESIZE_SUPPORT))
kal_uint32 jpeg_resize_process(jpeg_file_resize_struct *jpeg_resize_para)
{
   volatile kal_uint8 read_data;
   kal_uint8 return_code;
   MMDI_SCENERIO_ID scenario_id=SCENARIO_JPEG_RESIZE_ID;
   kal_uint32 jpeg_file_size,jpeg_file_handle,fs_read_size;
   kal_uint8 *jpg_file_ptr;
   kal_uint32 jpeg_file_buffer_size,event_group;
   volatile kal_uint16 i;

   jpeg_decode_wait_event=KAL_FALSE;

   /* for config JPEG decoder */
   jpeg_decode_config_data.extmem_size=jpeg_resize_para->extmem_size;
   /* for config JPEG decoder */

   jpeg_resize_config_data.jpeg_file_handle=jpeg_resize_para->jpeg_file_handle;
   jpeg_resize_config_data.jpeg_file_buffer_address=jpeg_resize_para->jpeg_file_buffer_address;
   jpeg_resize_config_data.jpeg_file_size=jpeg_resize_para->jpeg_file_size;
   jpeg_resize_config_data.jpeg_file_buffer_size=jpeg_resize_para->jpeg_file_buffer_size;
   jpeg_resize_config_data.rest_jpeg_file_size=jpeg_resize_para->rest_jpeg_file_size;
   jpeg_resize_config_data.intmem_start_address=jpeg_resize_para->intmem_start_address;
   jpeg_resize_config_data.intmem_size=jpeg_resize_para->intmem_size;
   jpeg_resize_config_data.extmem_start_address=jpeg_resize_para->extmem_start_address;
   jpeg_resize_config_data.extmem_size=jpeg_resize_para->extmem_size;
   jpeg_decode_config_data.extmem_size=jpeg_resize_para->extmem_size;
   jpeg_resize_config_data.target_width=jpeg_resize_para->target_width;
   jpeg_resize_config_data.target_height=jpeg_resize_para->target_height;
   jpeg_resize_config_data.image_quality=jpeg_resize_para->image_quality;
   jpeg_resize_config_data.target_jpeg_file_address=jpeg_resize_para->target_jpeg_file_address;
   jpeg_resize_config_data.target_jpeg_file_buffer_size=jpeg_resize_para->target_jpeg_file_buffer_size;

   #ifdef DRV_JPG_ENC_MULTI_FORMAT_SUPPORT
   jpeg_resize_config_data.jpeg_yuv_mode=jpeg_resize_para->jpeg_yuv_mode;
   #endif

   #ifdef DRV_JPG_ENC_THUMBNAIL_SUPPORT
   jpeg_resize_config_data.thumbnail_mode=KAL_FALSE;
   jpeg_resize_config_data.thumbnail_width=jpeg_resize_para->thumbnail_width;
   jpeg_resize_config_data.thumbnail_height=jpeg_resize_para->thumbnail_height;
   #endif

   #ifdef DRV_JPG_ENC_OVERLAY_SUPPORT
   jpeg_resize_config_data.overlay_frame_mode=jpeg_resize_para->overlay_frame_mode;
   jpeg_resize_config_data.overlay_color_depth=jpeg_resize_para->overlay_color_depth;
   jpeg_resize_config_data.overlay_frame_source_key=jpeg_resize_para->overlay_frame_source_key;
   jpeg_resize_config_data.overlay_frame_width=jpeg_resize_para->overlay_frame_width;
   jpeg_resize_config_data.overlay_frame_height=jpeg_resize_para->overlay_frame_height;
   jpeg_resize_config_data.overlay_frame_buffer_address=jpeg_resize_para->overlay_frame_buffer_address;
   #endif

   kal_set_eg_events(jpeg_codec_event_id,0,KAL_AND);

   jpeg_decode_next_block=KAL_FALSE;
   jpg_file_ptr=(kal_uint8 *) jpeg_resize_config_data.jpeg_file_buffer_address;
   jpeg_file_buffer_size=jpeg_resize_config_data.jpeg_file_buffer_size;
   jpeg_file_handle=jpeg_resize_config_data.jpeg_file_handle;
   jpeg_thumbnail_mode=KAL_FALSE;
   if (jpeg_file_handle!=0)
      parse_jpeg_file(jpeg_file_handle,jpg_file_ptr,jpeg_file_buffer_size);
   else
      parse_jpeg_file(jpeg_file_handle,jpg_file_ptr,jpeg_resize_config_data.jpeg_file_size);

   if (((jpeg_file_para.jpg_height==0xFFFF) && (jpeg_file_para.jpg_width)==0xFFFF))
   {
      jpeg_codec_power_down();
//    return (JPEG_DECODE_WRONG_JPEG_FILE);
      return 0;
   }
   else if (jpeg_file_para.jpg_progressive==KAL_TRUE)
   {
      jpeg_codec_power_down();
//    return (JPEG_DECODE_UNSUPPORT_FORMAT);
      return 0;
   }

   jpeg_decode_int_mem_size=0;
   jpeg_decode_ext_mem_size=0;
   jpeg_encoder_encode_result=0;
   jpeg_file_size=0;

   open_image_data_path(scenario_id);
   _idp_opened = 1;

   return_code = config_jpeg_resize_data_path(scenario_id,&jpeg_resize_config_data);
   if (return_code)
   {
      if (_idp_opened) {
         close_image_data_path(scenario_id);
         _idp_opened = 0;
      }
      jpeg_codec_power_down();
//    return return_code;
      return 0;
   }

   if (jpeg_file_handle!=0)
   {
      jpeg_file_buffer_size-=16;
      DRM_file_size((FS_HANDLE) jpeg_file_handle, &jpeg_file_size);
      jpeg_file_size-=jpeg_file_para.thumbnail_offset;
      jpeg_file_offset=jpeg_file_para.thumbnail_offset;
      jpeg_resize_config_data.jpeg_file_size=jpeg_file_size;
      jpeg_decode_config_data.jpeg_file_size=jpeg_file_size;
      DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_para.thumbnail_offset, FS_FILE_BEGIN);
      DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, jpeg_file_buffer_size, &fs_read_size);
//    jpeg_resize_config_data.rest_jpeg_file_size=jpeg_file_size-jpeg_file_offset+16;
      jpeg_resize_config_data.rest_jpeg_file_size=jpeg_file_size+32;
      if (fs_read_size<jpeg_file_buffer_size)
         jpeg_resize_config_data.rest_jpeg_file_size=0;
      else
      {
         jpeg_resize_config_data.rest_jpeg_file_size-=jpeg_file_buffer_size;
         jpeg_file_offset+=jpeg_file_buffer_size;
         jpeg_decode_wait_event=KAL_TRUE;
      }
      jpeg_decode_config_data.rest_jpeg_file_size=jpeg_resize_config_data.rest_jpeg_file_size;
      if (jpeg_resize_config_data.rest_jpeg_file_size==0)
      {
         jpeg_file_offset=jpeg_file_para.thumbnail_offset;
         if ((jpeg_file_buffer_size-fs_read_size)<16)
            jpeg_decode_break=KAL_TRUE;
         jpeg_decode_wait_event=KAL_FALSE;
         if (jpeg_file_without_eoi==KAL_FALSE)
         {
         read_data=*(jpg_file_ptr+fs_read_size);
         while (read_data!=0xD9 && fs_read_size!=0)
         {
            fs_read_size--;
            read_data=*(jpg_file_ptr+fs_read_size);
         }
         fs_read_size++;
         
         for (i = 0; i < 16; i++) {
            if ((fs_read_size + i) < jpeg_file_buffer_size) {
               *(jpg_file_ptr + fs_read_size + i) = 0;
            }
         }
      }
      }

      jpeg_decoder_decode_result=0;
      return_code=config_jpeg_decoder((kal_uint32) jpg_file_ptr,fs_read_size);

      if (return_code && _idp_opened) {
         close_image_data_path(scenario_id);
         _idp_opened = 0;
         return 0;
      }

      jpeg_decoder_operation_state=JPEG_DECODER_DECODING_STATE;

      while (jpeg_resize_config_data.rest_jpeg_file_size!=0)
      {
         kal_retrieve_eg_events(jpeg_codec_event_id,JPEG_DECODE_BREAK_INT_EVENT,KAL_OR_CONSUME,
                                &event_group,KAL_SUSPEND);
         if (jpeg_decoder_operation_state==JPEG_DECODER_DECODING_STATE)
         {
            DRM_seek_file((FS_HANDLE) jpeg_file_handle, jpeg_file_offset , FS_FILE_BEGIN);
            DRM_read_file((FS_HANDLE) jpeg_file_handle, jpg_file_ptr, jpeg_file_buffer_size, &fs_read_size);
            if (fs_read_size<jpeg_file_buffer_size)
               jpeg_resize_config_data.rest_jpeg_file_size=0;
            else
            {
               jpeg_resize_config_data.rest_jpeg_file_size-=jpeg_file_buffer_size;
               jpeg_file_offset+=jpeg_file_buffer_size;
               jpeg_decode_wait_event=KAL_TRUE;
            }

            jpeg_decode_config_data.rest_jpeg_file_size=jpeg_resize_config_data.rest_jpeg_file_size;
            if (jpeg_resize_config_data.rest_jpeg_file_size==0)
            {
               jpeg_file_offset=jpeg_file_para.thumbnail_offset;
               if ((jpeg_file_buffer_size-fs_read_size)<16)
                  jpeg_decode_break=KAL_TRUE;
               if (jpeg_file_without_eoi==KAL_FALSE)
               {
               read_data=*(jpg_file_ptr+fs_read_size);
               while (read_data!=0xD9 && fs_read_size!=0)
               {
                  fs_read_size--;
                  read_data=*(jpg_file_ptr+fs_read_size);
               }

               fs_read_size++;
               jpeg_decode_wait_event=KAL_FALSE;
               
               for (i = 0; i < 16; i++) {
                  if ((fs_read_size + i) < jpeg_file_buffer_size) {
                     *(jpg_file_ptr + fs_read_size + i) = 0;
                  }
               }
            }
            }

            jpeg_decoder_decode_result=0;
            REG_JPEG_DECODER_JPEG_FILE_START_ADDR=(kal_uint32) jpg_file_ptr;
            
            for (i=0;i<0x400;i++){};
            
            if (REG_JPEG_DECODER_JPEG_FILE_START_ADDR==((kal_uint32) jpg_file_ptr)) {
               if (_idp_opened) {
                  close_image_data_path(scenario_id);
                  _idp_opened = 0;
               }
               return 0;
            }
         }
         else
            break;
      }
   }
   else
   {
      jpeg_decode_wait_event=KAL_FALSE;
      return_code=config_jpeg_decoder(jpeg_resize_config_data.jpeg_file_buffer_address,jpeg_resize_config_data.jpeg_file_size+32);

      if (return_code && _idp_opened) {
         close_image_data_path(scenario_id);
         _idp_opened = 0;
         return 0;
      }
      
      jpeg_decoder_operation_state=JPEG_DECODER_DECODING_STATE;
   }

   /* wait until JPEG encode completely */
   kal_retrieve_eg_events(jpeg_codec_event_id,JPEG_ENCODE_INT_EVENT,KAL_OR_CONSUME,
                          &event_group,KAL_SUSPEND);

   if (jpeg_encoder_encode_result & JPEG_ENCODE_DONE)
   {
      jpeg_file_size=DRV_Reg32(JPEG_ENCODER_DMA_ADDR_REG)-DRV_Reg32(JPEG_ENCODER_DEST_ADDR_REG);
      if (jpeg_resize_config_data.thumbnail_mode==KAL_TRUE)
         jpeg_file_size+=(jpeg_resize_config_data.thumbnail_width*jpeg_resize_config_data.thumbnail_height*3+20);
   }

   jpeg_encoder_operation_state=JPEG_ENCODER_STANDBY_STATE;
   jpeg_decoder_operation_state=JPEG_DECODER_STANDBY_STATE;

   if (_idp_opened) {
      close_image_data_path(scenario_id);
      _idp_opened = 0;
   }

   return jpeg_file_size;
}  /* jpeg_resize_process() */
#endif

#ifdef DRV_JPG_SNAPSHOT_SUPPORT
kal_uint32 jpeg_encode_snapshot_process(jpeg_encode_process_struct *jpeg_encode_para)
{
   kal_uint32 jpeg_file_size;
   kal_uint32 event_group;
   MMDI_SCENERIO_ID scenario_id=SCENARIO_MPEG_SNAPSHOT_ID;

   #ifdef DRV_JPG_ENC_THUMBNAIL_SUPPORT
   jpeg_encode_para->thumbnail_mode=KAL_FALSE;
   #endif

   #ifdef DRV_JPG_ENC_OVERLAY_SUPPORT
   jpeg_encode_para->overlay_frame_mode=KAL_FALSE;
   #endif

#if (defined(DRV_JPG_ENC_28_SERIES)) //bug
   jpeg_encode_para->jpeg_yuv_mode=JPEG_FORMAT_YUV422;
#endif
   if (jpeg_encoder_operation_state!=JPEG_ENCODER_STANDBY_STATE)
      ASSERT(0);

#if (defined(DRV_JPG_ENC_19_SERIES))
   if ((jpeg_encode_para->jpeg_gray_mode!=JPEG_ENCODER_COLOR_MODE)&&
       (jpeg_encode_para->jpeg_gray_mode!=JPEG_ENCODER_GRAY_MODE))
      ASSERT(0);
#endif

   kal_set_eg_events(jpeg_codec_event_id,0,KAL_AND);

   jpeg_encode_config_data.type=jpeg_encode_para->type;
   jpeg_encode_config_data.data_order=jpeg_encode_para->data_order;
   jpeg_encode_config_data.image_buffer_address=jpeg_encode_para->image_buffer_address;
   jpeg_encode_config_data.image_width=jpeg_encode_para->image_width;
   jpeg_encode_config_data.image_height=jpeg_encode_para->image_height;
   jpeg_encode_config_data.target_width=jpeg_encode_para->target_width;
   jpeg_encode_config_data.target_height=jpeg_encode_para->target_height;
   jpeg_encode_config_data.image_quality=jpeg_encode_para->image_quality;
   jpeg_encode_config_data.jpeg_file_start_address=jpeg_encode_para->jpeg_file_start_address;
   jpeg_encode_config_data.jpeg_file_buffer_size=jpeg_encode_para->jpeg_file_buffer_size;
   jpeg_encode_config_data.jpeg_encode_cb=jpeg_encode_para->jpeg_encode_cb;

   #ifdef DRV_JPG_ENC_THUMBNAIL_SUPPORT
   jpeg_encode_config_data.thumbnail_mode=KAL_FALSE;
   jpeg_encode_config_data.thumbnail_width=jpeg_encode_para->thumbnail_width;
   jpeg_encode_config_data.thumbnail_height=jpeg_encode_para->thumbnail_height;
   #endif

   #ifdef DRV_JPG_ENC_MULTI_FORMAT_SUPPORT
   jpeg_encode_config_data.jpeg_yuv_mode=jpeg_encode_para->jpeg_yuv_mode;
   #endif

   #ifdef DRV_JPG_ENC_OVERLAY_SUPPORT
   jpeg_encode_config_data.overlay_frame_mode=jpeg_encode_para->overlay_frame_mode;
   jpeg_encode_config_data.overlay_color_depth=jpeg_encode_para->overlay_color_depth;
   jpeg_encode_config_data.overlay_frame_source_key=jpeg_encode_para->overlay_frame_source_key;
   jpeg_encode_config_data.overlay_frame_width=jpeg_encode_para->overlay_frame_width;
   jpeg_encode_config_data.overlay_frame_height=jpeg_encode_para->overlay_frame_height;
   jpeg_encode_config_data.overlay_frame_buffer_address=jpeg_encode_para->overlay_frame_buffer_address;
#endif
   jpeg_encoder_encode_result=0;
   jpeg_file_size=0;

   #if (defined(DRV_JPG_DATA_PATH_19_SERIES))

   jpeg_codec_power_up();

   config_image_processor(scenario_id);
   _img_processor_opened = 1;

   config_pixel_resizer(scenario_id);
   _img_resizer_opened = 1;

   config_image_dma(scenario_id,0,0);
   config_jpeg_encoder(&jpeg_encode_config_data);
   IMGDMA_Start(IMGDMA_IBR1_CH,SCENARIO_MPEG_DECODE_ID);

   _img_dma_opened = 1;

   #elif (defined(DRV_JPG_DATA_PATH_28_SERIES))
   scenario_id=SCENARIO_MPEG_SNAPSHOT_ID;
   open_image_data_path(scenario_id);
   _idp_opened = 1;
   
   config_jpeg_encode_data_path(scenario_id,&jpeg_encode_config_data);
   /* config_jpeg_snapshot_data_path() */
   #endif
   /* wait until JPEG encode completely */
   kal_retrieve_eg_events(jpeg_codec_event_id,JPEG_ENCODE_INT_EVENT,KAL_OR_CONSUME,
                          &event_group,KAL_SUSPEND);

   if (jpeg_encoder_encode_result & JPEG_ENCODE_DONE)
   {
      jpeg_file_size=DRV_Reg32(JPEG_ENCODER_DMA_ADDR_REG)-DRV_Reg32(JPEG_ENCODER_DEST_ADDR_REG);
   #if (defined(DRV_JPG_ENC_THUMBNAIL_SUPPORT))
      if (jpeg_encode_config_data.thumbnail_mode==KAL_TRUE)
         jpeg_file_size+=(jpeg_encode_config_data.thumbnail_width*jpeg_encode_config_data.thumbnail_height*3+20);
   #endif
   }

   #if defined(DRV_JPG_DATA_PATH_19_SERIES)

      if (_img_dma_opened) {
         stop_image_dma(scenario_id);
         IMGDMA_Close(SCENARIO_MPEG_DECODE_ID);
         _img_dma_opened = 0;
      }
   
      if (_img_resizer_opened) {
         RESZ_Stop(SCENARIO_MPEG_DECODE_ID);
         RESZ_Close(SCENARIO_MPEG_DECODE_ID);
         _img_resizer_opened = 0;
      }
   
      if (_img_processor_opened) {
         IMGPROC_Stop(SCENARIO_MPEG_DECODE_ID);
         IMGPROC_Close(SCENARIO_MPEG_DECODE_ID);
         _img_processor_opened = 0;
      }
   
      jpeg_codec_power_down();
   
   #elif defined(DRV_JPG_DATA_PATH_28_SERIES)
   
      if (_idp_opened) {
         close_image_data_path(SCENARIO_MPEG_SNAPSHOT_ID);
         _idp_opened = 0;
      }
   
   #endif
   
   DRV_Reg(DRVPDN_CON3) &= ~DRVPDN_CON3_DCT;    /* power on DCT for MPEG4 decoder */

   if (jpeg_encoder_encode_result & JPEG_ENCODE_DONE)
      return jpeg_file_size;
   else
      return 0;
}  /* jpeg_encode_snapshot_process() */
#endif

#if (defined(DRV_JPG_HW_ENC_SUPPORT))
kal_uint32 jpeg_encode_process(jpeg_encode_process_struct *jpeg_encode_para)
{
   #if (defined(EXIF_SUPPORT))
   kal_uint16  exif_header_length;
   kal_uint16  exif_padding_length=0;
   #endif

  #if(!defined (__MTK_TARGET__))
    kal_uint32 jpeg_file_size;

  jpeg_sw_encode_process_struct jpeg_encode_config_data;

  jpeg_encode_config_data.image_quality=jpeg_encode_para->image_quality;

  if(jpeg_encode_para->jpeg_gray_mode)
    jpeg_encode_config_data.output_type=IMAGE_FORMAT_GRAY;
  else
    jpeg_encode_config_data.output_type=IMAGE_FORMAT_GRAY;

  jpeg_encode_config_data.input_type=IMAGE_FORMAT_RGB565;

  jpeg_encode_config_data.image_width=jpeg_encode_para->image_width;
  jpeg_encode_config_data.image_height=jpeg_encode_para->image_height;
  jpeg_encode_config_data.jpeg_file_start_address=(kal_uint32)jpeg_encode_para->jpeg_file_start_address;
  jpeg_encode_config_data.jpeg_file_buffer_size=jpeg_encode_para->jpeg_file_buffer_size;
  jpeg_encode_config_data.image_buffer_address=jpeg_encode_para->image_buffer_address;
  jpeg_encode_config_data.jpeg_yuv_data[0]=&y_channel[0];
  jpeg_encode_config_data.jpeg_yuv_data[1]=&u_channel[0];
  jpeg_encode_config_data.jpeg_yuv_data[2]=&v_channel[0];

  jpeg_encode_config_data.jpeg_yuv_size[0]=640*480;
  jpeg_encode_config_data.jpeg_yuv_size[1]=320*240;
  jpeg_encode_config_data.jpeg_yuv_size[2]=320*240;

  jpeg_encode_config_data.intmem_start_address=jpeg_encode_para->intmem_start_address;
  jpeg_encode_config_data.intmem_size=jpeg_encode_para->intmem_size;

  jpeg_file_size=jpeg_sw_encode_process(&jpeg_encode_config_data);

  return jpeg_file_size;

#else /* !__MTK_TARGET__ */

   kal_uint32 jpeg_file_size;
   kal_uint32 event_group;
   MMDI_SCENERIO_ID scenario_id=SCENARIO_JPEG_ENCODE_ID;

   if (jpeg_encoder_operation_state!=JPEG_ENCODER_STANDBY_STATE)
      ASSERT(0);

#if (defined(DRV_JPG_ENC_19_SERIES))
   if ((jpeg_encode_para->jpeg_gray_mode!=JPEG_ENCODER_COLOR_MODE)&&
       (jpeg_encode_para->jpeg_gray_mode!=JPEG_ENCODER_GRAY_MODE))
      ASSERT(0);
   jpeg_codec_power_up();
#endif
   kal_set_eg_events(jpeg_codec_event_id,0,KAL_AND);

   /* Hardware resize can not process the case that source image height is 1 */
    if (jpeg_encode_para->image_height==1)
    return 0;

   jpeg_encode_config_data.type=jpeg_encode_para->type;
   jpeg_encode_config_data.data_order=jpeg_encode_para->data_order;
   jpeg_encode_config_data.image_buffer_address=jpeg_encode_para->image_buffer_address;
   jpeg_encode_config_data.intmem_start_address=jpeg_encode_para->intmem_start_address;
   jpeg_encode_config_data.intmem_size=jpeg_encode_para->intmem_size;
   jpeg_encode_config_data.extmem_start_address=jpeg_encode_para->extmem_start_address;
   jpeg_encode_config_data.extmem_size=jpeg_encode_para->extmem_size;
   jpeg_encode_config_data.image_width=jpeg_encode_para->image_width;
   jpeg_encode_config_data.image_height=jpeg_encode_para->image_height;
   jpeg_encode_config_data.target_width=jpeg_encode_para->target_width;
   jpeg_encode_config_data.target_height=jpeg_encode_para->target_height;
   jpeg_encode_config_data.image_quality=jpeg_encode_para->image_quality;
   jpeg_encode_config_data.jpeg_gray_mode=jpeg_encode_para->jpeg_gray_mode;
   jpeg_encode_config_data.jpeg_file_start_address=jpeg_encode_para->jpeg_file_start_address;
   jpeg_encode_config_data.jpeg_file_buffer_size=jpeg_encode_para->jpeg_file_buffer_size;
   jpeg_encode_config_data.jpeg_encode_cb=jpeg_encode_para->jpeg_encode_cb;
#if (defined(DRV_JPG_ENC_19_SERIES))
   intmem_init((kal_uint32 *) jpeg_encode_config_data.intmem_start_address,
               jpeg_encode_config_data.intmem_size);
   extmem_init((kal_uint32 *) jpeg_encode_config_data.extmem_start_address,
               jpeg_encode_config_data.extmem_size);
#endif

#ifdef DRV_JPG_ENC_THUMBNAIL_SUPPORT
   jpeg_encode_config_data.thumbnail_mode=KAL_FALSE;
   jpeg_encode_config_data.thumbnail_width=jpeg_encode_para->thumbnail_width;
   jpeg_encode_config_data.thumbnail_height=jpeg_encode_para->thumbnail_height;
#endif

#ifdef DRV_JPG_ENC_MULTI_FORMAT_SUPPORT
   jpeg_encode_config_data.jpeg_yuv_mode=jpeg_encode_para->jpeg_yuv_mode;
#endif

#ifdef DRV_JPG_ENC_OVERLAY_SUPPORT
   jpeg_encode_config_data.overlay_frame_mode=jpeg_encode_para->overlay_frame_mode;
   jpeg_encode_config_data.overlay_color_depth=jpeg_encode_para->overlay_color_depth;
   jpeg_encode_config_data.overlay_frame_source_key=jpeg_encode_para->overlay_frame_source_key;
   jpeg_encode_config_data.overlay_frame_width=jpeg_encode_para->overlay_frame_width;
   jpeg_encode_config_data.overlay_frame_height=jpeg_encode_para->overlay_frame_height;
   jpeg_encode_config_data.overlay_frame_buffer_address=jpeg_encode_para->overlay_frame_buffer_address;
#endif

   jpeg_encoder_encode_result=0;
   jpeg_file_size=0;

#if (defined(EXIF_SUPPORT))
   exif_header_length=exif_get_custom_IFD_and_buffer_size(2);

   if(exif_header_length>0)
   {
      jpeg_encode_config_data.jpeg_file_start_address+=exif_header_length;

      if(jpeg_encode_config_data.jpeg_file_start_address % 4 !=0)
      {
         jpeg_encode_config_data.jpeg_file_start_address=((jpeg_encode_config_data.jpeg_file_start_address+4)>>2)<<2;
      }

      exif_padding_length=jpeg_encode_config_data.jpeg_file_start_address-((kal_uint32)jpeg_encode_para->jpeg_file_start_address+exif_header_length);
      jpeg_encode_config_data.jpeg_file_buffer_size-=(jpeg_encode_config_data.jpeg_file_start_address-(kal_uint32)jpeg_encode_para->jpeg_file_start_address);
   }
#endif

   #if (defined(DRV_JPG_DATA_PATH_19_SERIES))
   config_image_processor(scenario_id);
   _img_processor_opened = 1;

   config_pixel_resizer(scenario_id);
   _img_resizer_opened = 1;

   config_image_dma(scenario_id,0,0);
   config_jpeg_encoder(&jpeg_encode_config_data);
   IMGDMA_Start(IMGDMA_IBR1_CH,scenario_id);

   _img_dma_opened = 1;

   #elif (defined(DRV_JPG_DATA_PATH_28_SERIES))
   
   open_image_data_path(scenario_id);
   _idp_opened = 1;
   
   config_jpeg_encode_data_path(scenario_id,&jpeg_encode_config_data);
   #endif

   /* wait until JPEG encode completely */
   kal_retrieve_eg_events(jpeg_codec_event_id,JPEG_ENCODE_INT_EVENT,KAL_OR_CONSUME,
                          &event_group,KAL_SUSPEND);

   if (jpeg_encoder_encode_result & JPEG_ENCODE_DONE)
   {
      jpeg_file_size=DRV_Reg32(JPEG_ENCODER_DMA_ADDR_REG)-DRV_Reg32(JPEG_ENCODER_DEST_ADDR_REG);

   #if (defined(DRV_JPG_ENC_THUMBNAIL_SUPPORT))
      if (jpeg_encode_config_data.thumbnail_mode==KAL_TRUE)
         jpeg_file_size+=(jpeg_encode_config_data.thumbnail_width*jpeg_encode_config_data.thumbnail_height*3+20);
   #endif
   }

   #if (defined(DRV_JPG_DATA_PATH_19_SERIES))
      if (_img_dma_opened) {
         stop_image_dma(scenario_id);
         IMGDMA_Close(scenario_id);
         _img_dma_opened = 0;
      }
   
      if (_img_resizer_opened) {
         RESZ_Stop(scenario_id);
         RESZ_Close(scenario_id);
         _img_resizer_opened = 0;
      }
   
      if (_img_processor_opened) {
         IMGPROC_Stop(scenario_id);
         IMGPROC_Close(scenario_id);
         _img_processor_opened = 0;
      }
      
      intmem_deinit();
      extmem_deinit();
      jpeg_codec_power_down();

   #elif (defined(DRV_JPG_DATA_PATH_28_SERIES))
      if (_idp_opened) {
         close_image_data_path(scenario_id);
         _idp_opened = 0;
      }
   #endif

   if (jpeg_encoder_encode_result & JPEG_ENCODE_DONE)
   {
    #if (defined(EXIF_SUPPORT))
   /* Filling Exif header */
   if(exif_header_length>0)
   {
    kal_uint32 i;
   *((kal_uint8 *)jpeg_encode_para->jpeg_file_start_address)=0xFF;
   *((kal_uint8 *)jpeg_encode_para->jpeg_file_start_address+1)=0xD8;

   exif_set_extra_included_bytes(exif_padding_length);
   exif_Fillin_Header((kal_uint8 *)jpeg_encode_para->jpeg_file_start_address,2);

   /* padding bytes to cover SOI marker generated by JPEG encoder */
   for(i=0;i<exif_padding_length;i++)
    *((kal_uint8 *)(jpeg_encode_config_data.jpeg_file_start_address+1-i))=0x00;

    jpeg_file_size+=(jpeg_encode_config_data.jpeg_file_start_address-
           (kal_uint32)jpeg_encode_para->jpeg_file_start_address);
   }
   #endif
      return jpeg_file_size;
   }
   else
      return 0;
 #endif  /* !__MTK_TARGET__ */
}  /* jpeg_encode_process() */

#endif

kal_uint8 exit_jpeg_encode_process(void)
{
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
#endif
   return KAL_TRUE;
}  /* exit_jpeg_encode_process() */



void jpeg_video_play_callback(kal_uint8 return_code)
{
   jpeg_video_play_flag=return_code;
}

void start_jpeg_video_play(lcd_frame_update_struct *lcd_para)
{
   jpeg_video_play_lcd_id=lcd_para->lcd_id;
   jpeg_video_play_lcd_data.lcd_id=lcd_para->lcd_id;
   jpeg_video_play_lcd_data.module_id=LCD_UPDATE_MODULE_JPEG_VIDEO;
   jpeg_video_play_lcd_data.fb_update_mode=lcd_para->fb_update_mode;
   jpeg_video_play_lcd_data.lcm_start_x=lcd_para->lcm_start_x;
   jpeg_video_play_lcd_data.lcm_start_y=lcd_para->lcm_start_y;
   jpeg_video_play_lcd_data.lcm_end_x=lcd_para->lcm_end_x;
   jpeg_video_play_lcd_data.lcm_end_y=lcd_para->lcm_end_y;
   jpeg_video_play_lcd_data.roi_offset_x=lcd_para->roi_offset_x;
   jpeg_video_play_lcd_data.roi_offset_y=lcd_para->roi_offset_y;
   jpeg_video_play_lcd_data.update_layer=lcd_para->update_layer;
   jpeg_video_play_lcd_data.block_mode_flag=KAL_TRUE;
   jpeg_video_play_lcd_data.lcd_block_mode_cb=NULL;
#if (defined(MT6226)||defined(MT6226M)||defined(MT6227)||defined(MT6227D)||defined(MT6226D)||defined(DRV_JPG_DEC_28_SERIES))
   jpeg_video_play_lcd_data.memory_output=KAL_FALSE;
#endif
   lcd_start_jpeg_video_play(lcd_para);
}  /* start_jpeg_video_play() */

#if(defined(DRV_JPG_SW_DEC_SUPPORT))

kal_uint8 jpeg_video_play(jpeg_decode_process_struct *jpeg_decode_para,kal_bool update_to_lcd)
{
   kal_uint16 jpeg_decoded_width, jpeg_decoded_height;
   volatile kal_uint32 i,j;
   kal_uint8 return_code;

   if(jpeg_decode_para->jpeg_file_buffer_size==0) ASSERT(0);

   get_jpeg_resize_size(jpeg_decode_para->jpeg_file_handle,jpeg_decode_para->jpeg_file_buffer_address,
              jpeg_decode_para->jpeg_file_buffer_size,&jpeg_decode_para->image_width,
              &jpeg_decode_para->image_height,&jpeg_decoded_width,&jpeg_decoded_height);

   return_code=jpeg_decode_process(jpeg_decode_para);

   if (return_code!=JPEG_DECODE_SUCCESS)
      return return_code;

   jpeg_decoder_operation_state=JPEG_DECODER_STANDBY_STATE;


   if (update_to_lcd==KAL_TRUE)
   {
      lcd_jpeg_video_play(KAL_TRUE, &jpeg_video_play_lcd_data);
   }
    //stop_jpeg_decode_process();
   return JPEG_DECODE_SUCCESS;
}

#else /* ! defined(DRV_JPG_SW_DEC_SUPPORT)*/
kal_uint8 jpeg_video_play(jpeg_decode_process_struct *jpeg_decode_para,
                          kal_uint16 *frame_buf_ptr, kal_uint16 frame_buf_width,kal_bool update_to_lcd)
{
   kal_uint16 jpeg_decoded_width, jpeg_decoded_height;
   volatile kal_uint32 i,j;
   kal_uint16 *jpeg_decoded_buffer_ptr;
   kal_uint8 return_code;

   if(jpeg_decode_para->jpeg_file_buffer_size==0)
    ASSERT(0);

   jpeg_decode_para->jpeg_decode_cb=jpeg_video_play_callback;
   get_jpeg_resize_size(jpeg_decode_para->jpeg_file_handle,jpeg_decode_para->jpeg_file_buffer_address,
                        jpeg_decode_para->jpeg_file_buffer_size,&jpeg_decode_para->image_width,
                        &jpeg_decode_para->image_height,&jpeg_decoded_width,&jpeg_decoded_height);

   jpeg_video_play_flag=0xFF;

   return_code=jpeg_decode_process(jpeg_decode_para);
   if (return_code!=JPEG_DECODE_DECODING)
      return return_code;

   //while (jpeg_video_play_flag==0xFF)
   for(j=0;j<0x60000;j++)
   {
#if (defined(DRV_JPG_DEC_17_SERIES))
      if ((jpeg_decoder_decode_result & JPEG_DECODE_COMPLETE) &&
          (jpeg_file_resizer_result == JPEG_RESIZER_RESIZING))
#else
      if (jpeg_decoder_decode_result & JPEG_DECODE_COMPLETE)
#endif
      {
         for (i=0;i<0x20000;i++)
         {
            if (jpeg_video_play_flag!=0xFF)
               i=0x20000;
         };
         break;
      }

    if(jpeg_video_play_flag!=0xFF)
     break;
   };

   if (jpeg_video_play_flag==0xFF)
   {
#if (defined(MT6217))
      if (!(IS_VR_BUSY))
         jpeg_video_play_flag = JPEG_DECODE_SUCCESS;
      else
         jpeg_video_play_flag=JPEG_DECODE_RESIZER_TIMEOUT_FAIL;
#else
      jpeg_video_play_flag=JPEG_DECODE_RESIZER_TIMEOUT_FAIL;
#endif
      jpeg_decoder_operation_state=JPEG_DECODER_STANDBY_STATE;
   }

   if (jpeg_video_play_flag==JPEG_DECODE_SUCCESS)
   {
      jpeg_decoded_buffer_ptr=(kal_uint16 *) jpeg_decode_para->image_buffer_address;

   /* Need SW to remove the dummy pixles */
      for (i=0;i<jpeg_decode_para->image_height;i++)
      {
         for (j=0;j<jpeg_decode_para->image_width;j++)
         {
            *(frame_buf_ptr+j)=*(jpeg_decoded_buffer_ptr+j);
         }
         frame_buf_ptr+=frame_buf_width;
         jpeg_decoded_buffer_ptr+=jpeg_decoded_width;
      }

      if (update_to_lcd==KAL_TRUE)
      {
         lcd_jpeg_video_play(KAL_TRUE, &jpeg_video_play_lcd_data);
   }
   }
   else
   {
      if (update_to_lcd==KAL_TRUE)
      {
         lcd_jpeg_video_play(KAL_FALSE, &jpeg_video_play_lcd_data);
      }
   }
   stop_jpeg_decode_process();
   return (jpeg_video_play_flag);
}  /* jpeg_video_play() */
#endif /*defined(DRV_JPG_SW_DEC_SUPPORT)*/

void stop_jpeg_video_play(void)
{
   lcd_stop_jpeg_video_play(jpeg_video_play_lcd_data.lcd_id);
}  /* stop_jpeg_video_play() */

#endif /* */


