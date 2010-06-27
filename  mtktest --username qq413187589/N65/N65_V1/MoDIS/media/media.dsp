# Microsoft Developer Studio Project File - Name="media" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=media - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "media.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "media.mak" CFG="media - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "media - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "media - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "media - Win32 Release"
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /W2 /Od /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" 
# ADD CPP @"media.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "$(CFG)" == "media - Win32 Debug"
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /W2 /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" 
# ADD CPP @"media.ini"
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "_DEBUG"
# ADD RSC /l 0x404 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ENDIF
# Begin Target
# Name "media - Win32 Release"
# Name "media - Win32 Debug"
# Begin Group "audio"
# Begin Group "include"
# Begin Source File 
SOURCE=..\..\media\audio\include\aud_amr_parser.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\include\aud_daf_parser.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\include\aud_defs.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\include\aud_id3_parser.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\include\aud_input_stream.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\include\aud_main.h
# End Source File 
# End Group "include"
# Begin Group "src"
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_api.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_audio.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_bt_a2dp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_bt_hfp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_bt_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_build_cache.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_ctm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_daf_parser.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_fmradio.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_id3_parser.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_ilm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_input_stream.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_keytone.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_media.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_melody.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_mma.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_post_process.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_rec_low.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_snd.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_speech.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_tone.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_tts.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_utility.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_vm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_vr_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_vr_sd.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_vr_si.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\audio\src\aud_vrsi_main.c
# End Source File 
# End Group "src"
# End Group "audio"
# Begin Group "camera"
# Begin Group "include"
# Begin Source File 
SOURCE=..\..\media\camera\include\ae_awb.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\include\af.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\include\cam_main.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\include\camera_para.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\include\ext_camera.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\include\isp_cct_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\include\isp_device_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\include\isp_flashlight.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\include\isp_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\include\isp_qc_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\include\isp_yuv_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\include\usbvideo_cam_if.h
# End Source File 
# End Group "include"
# Begin Group "src"
# Begin Source File 
SOURCE=..\..\media\camera\src\ae.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\af.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\awb.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\cam_api.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\cam_hp_ilm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\cam_hp_msg_handler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\cam_ilm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\cam_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\cam_msg_handler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\camera_process.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\ext_camera.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\isp_cct_if.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\isp_comm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\isp_device_if.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\isp_engmode.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\isp_flashlight.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\isp_if.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\isp_qc_if.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\isp_yuv_if.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\camera\src\usbvideo_cam_if.c
# End Source File 
# End Group "src"
# End Group "camera"
# Begin Group "common"
# Begin Group "include"
# Begin Source File 
SOURCE=..\..\media\common\include\bytestream_hw.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\include\image_effect.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\include\imgdma.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\include\imgproc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\include\med_api.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\include\med_context.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\include\med_global.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\include\med_main.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\include\med_smalloc.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\include\med_utility.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\include\med_v_context.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\include\med_v_main.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\include\resizer.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\include\visual_comm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\include\visualhisr.h
# End Source File 
# End Group "include"
# Begin Group "src"
# Begin Source File 
SOURCE=..\..\media\common\src\bytestream_hw.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\crc32.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\fsal.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\fsal_buffer.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\fsal_read.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\fsal_write.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\image_effect.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\imgdma.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\imgdma_6238_series.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\imgproc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\imgproc_6238_series.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\med_api.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\med_c_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\med_ext_smalloc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\med_ilm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\med_int_smalloc.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\med_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\med_utility.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\med_v_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\mp4_deblk_6238_series.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\mp4_parser.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\mp4_parser_audio.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\mp4_parser_audio_utility.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\mp4_parser_file.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\mp4_parser_stbl.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\mp4_parser_video.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\mp4_producer_audio.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\mp4_sample_data_audio.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\resizer.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\resizer_6238_series.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\visual_comm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\common\src\visualhisr.c
# End Source File 
# End Group "src"
# End Group "common"
# Begin Group "image"
# Begin Group "include"
# Begin Source File 
SOURCE=..\..\media\image\include\2d_engine.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\include\exif.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\include\exif_table.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\include\gif_decoder.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\include\gif_decoder_v2.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\include\image.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\include\img_comm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\include\img_main.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\include\jpeg.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\include\png_decoder.h
# End Source File 
# End Group "include"
# Begin Group "src"
# Begin Source File 
SOURCE=..\..\media\image\src\2d_engine.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\exif.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\gif_decoder.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\gif_decoder_v2.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\img_api.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\img_comm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\img_comm_6238_series.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\img_comm_6238_sw_block_filter.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\img_comm_fullduplex_video.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\img_comm_jpeg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\img_comm_legacy_series.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\img_comm_video_editor.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\img_comm_video_editor_6238_series.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\img_comm_video_editor_legacy_series.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\img_ilm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\img_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\img_msg_handler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\jpeg.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\png_decoder.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\tv_out.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\image\src\tv_out_test.c
# End Source File 
# End Group "src"
# End Group "image"
# Begin Group "mtv"
# Begin Group "src"
# Begin Source File 
SOURCE=..\..\media\mtv\src\cyberlink_dec.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\mtv\src\cyberlink_player.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\mtv\src\cyberlink_tdmb_demux.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\mtv\src\dab_demux.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\mtv\src\mtv_async_io.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\mtv\src\mtv_buffer_engine.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\mtv\src\mtv_cached_io.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\mtv\src\mtv_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\mtv\src\mtv_output_mp2.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\mtv\src\mtv_output_mp4.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\mtv\src\mtv_recorder.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\mtv\src\mtv_sm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\mtv\src\mtv_streaming_player.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\mtv\src\tdmb_demod.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\mtv\src\tdmb_sp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\mtv\src\tdmb_ts_demod.c
# End Source File 
# End Group "src"
# End Group "mtv"
# Begin Group "tvout"
# Begin Group "include"
# Begin Source File 
SOURCE=..\..\media\tvout\include\tvo_main.h
# End Source File 
# End Group "include"
# Begin Group "src"
# Begin Source File 
SOURCE=..\..\media\tvout\src\tvo_api.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\tvout\src\tvo_ilm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\tvout\src\tvo_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\tvout\src\tvo_msg_handler.c
# End Source File 
# End Group "src"
# End Group "tvout"
# Begin Group "vcall"
# Begin Group "src"
# Begin Source File 
SOURCE=..\..\media\vcall\src\vcall.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\vcall\src\vcall_ilm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\vcall\src\vcall_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\vcall\src\vcall_msg_hdlr.c
# End Source File 
# End Group "src"
# End Group "vcall"
# Begin Group "video"
# Begin Group "include"
# Begin Source File 
SOURCE=..\..\media\video\include\vid_avi.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\vid_main.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_call_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_codec.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_comm.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_dec_buffer_manager.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_dec_frame_buffer_manager.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_dec_glb.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_dec_hwcofig_buffer.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_dec_isr.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_dec_main.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_decore.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_dsp.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_editor.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_enc_glb.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_file_creator.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_fileparse_adap.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_glb.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_hw.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_rtp_h264_interleaved_buffer.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_rtp_if.h
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\include\video_rtp_reorder_buffer.h
# End Source File 
# End Group "include"
# Begin Group "src"
# Begin Source File 
SOURCE=..\..\media\video\src\vid_api.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\vid_avi.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\vid_ilm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\vid_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\vid_msg_handler.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_call_buffer.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_call_if.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_call_isr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_call_mp4.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_comm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_dec_api.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_dec_buffer_manager.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_dec_frame_buffer_manager.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_dec_isr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_dec_mp4_isr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_dsp.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_editor.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_editor_buffer_manager.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_editor_timectrl.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_enc_api.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_enc_buffer_manager.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_enc_isr.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_file_creator.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_fileparse_adap.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_rtp_h263.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_rtp_h264.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_rtp_h264_interleaved_buffer.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_rtp_if.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_rtp_mp4.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\video_rtp_reorder_buffer.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\vis_ilm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\video\src\vis_msg_handler.c
# End Source File 
# End Group "src"
# End Group "video"
# Begin Group "webcam"
# Begin Group "include"
# Begin Source File 
SOURCE=..\..\media\webcam\include\webcam_main.h
# End Source File 
# End Group "include"
# Begin Group "src"
# Begin Source File 
SOURCE=..\..\media\webcam\src\webcam_api.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\webcam\src\webcam_ilm.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\webcam\src\webcam_main.c
# End Source File 
# Begin Source File 
SOURCE=..\..\media\webcam\src\webcam_msg_handler.c
# End Source File 
# End Group "src"
# End Group "webcam"
# Begin Source File 
SOURCE=..\..\image_codec\sw_jpeg_codec\include\jpeg_sw.h
# End Source File 
# Begin Source File 
SOURCE=..\..\image_codec\sw_jpeg_codec\include\sw_jpeg_decoder.h
# End Source File 

# End Target
# End Project
