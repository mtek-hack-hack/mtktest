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
 *  GameFramework.h
  *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Game framework header file.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/

#ifndef __GAME_FRAMEWORK__
#define __GAME_FRAMEWORK__

#include "GameDefs.h"   /* include GAME_BASE id */

/****************************************************************************
* Define                                                              
*****************************************************************************/
#define GFX                      (g_gfx_cntx)

#define GFX_MAX_LEVEL_COUNT      (5)
#define GFX_MAX_MENU_ITEM_COUNT  (9)

#define GFX_AUDIO_GAMEOVER       (862)
#define GFX_AUDIO_COMPLETE       (310)

#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
#define GFX_AUDIO_DUMMYBACKGROUND_MIDI  (94)
#endif 

/****************************************************************************
* Struct / Typedef                                                                 
*****************************************************************************/
/* Screen ID */
typedef enum
{
    GFX_MENU_SCREEN = GAME_FRAMEWORK + 1,
    GFX_GAME_SCREEN,
    GFX_LEVEL_SCREEN,
    GFX_GRADE_SCREEN,
    GFX_HELP_SCREEN,
    GFX_GAMEOVER_SCREEN
} mmi_gfx_scr_id;

typedef struct
{
    /* Game menu */
    U16 game_img_id;        /* game icon img ID */
    U16 game_str_id;        /* game name string ID */
    U16 menu_resume_str_id; /* resume game string ID [OPTIONAL] */
    U16 menu_new_str_id;    /* new game string ID    [REQUIRED] */
    U16 menu_level_str_id;  /* game level string ID  [OPTIONAL] */
    U16 menu_grade_str_id;  /* best grade string ID  [OPTIONAL] */
    U16 menu_help_str_id;   /* help string ID     [OPTIONAL] */

    /* level / grade */
    U8 level_count;                                 /* how many levels */
    U16 level_str_id_list[GFX_MAX_LEVEL_COUNT];     /* level string ID */
    U16 grade_nvram_id_list[GFX_MAX_LEVEL_COUNT];   /* grade slot in NVRAM */
    U8 level_nvram_id;                              /* current lvl idnex stored in NVRAM */

    /* help */
    U16 help_str_id;    /* help description string id */

    /* misc */
    S16 *grade_value_ptr;   /* ptr to current level's grade */
    U8 *level_index_ptr;    /* ptr to current level index */
    BOOL *is_new_game;      /* ptr to new game flag */

    /* function ptr */
      S16(*best_grade_func_ptr) (S16 old_grade, S16 new_grade); /* function to calculate best grade */
    void (*enter_game_func_ptr) (void);     /* function to enter game */
    void (*exit_game_func_ptr) (void);      /* function to exit game */
    void (*draw_gameover_func_ptr) (void);  /* function to draw gameover screen */

    /* some flags */
    BOOL is_keypad_audio_enable;    /* play keypad tone or not */

} mmi_gfx_game_data_struct;

typedef struct
{
    mmi_gfx_game_data_struct game_data;
    BOOL is_vib_on;
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    BOOL is_background_music_on;
    BOOL is_sound_effect_on;
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    BOOL is_aud_on;
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    U8 aud_volume;
    BOOL is_level_changed;
    BOOL is_gameover;
    BOOL is_first_time_enter_gameover;
    BOOL is_resume_game;
    S32 hilight_index;
} mmi_gfx_cntx_struct;

/****************************************************************************
* Global Variable
*****************************************************************************/
extern mmi_gfx_cntx_struct g_gfx_cntx;
extern __align(2)
     const U8 g_gfx_audio_gameover[862];
     extern __align(2)
     const U8 g_gfx_audio_complete[310];

#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
     extern S32 dummy_background_midi;  /* /for dummy background */
     extern __align(2)
     const U8 g_gfx_Dummy_background_midi[94];

#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

/****************************************************************************
* Global Function
*****************************************************************************/
     extern void mmi_gfx_entry_menu_screen(void);       /* called by Game.c to enter game menu */
     extern void mmi_gfx_entry_gameover_screen(void);   /* called by each game to enter gameover screen */
     extern void mmi_gfx_draw_gameover_screen(U16 text_img_id, U16 box_img_id, U16 pic_img_id, S32 score);

     extern void mmi_gfx_store_setting(void);
     extern void mmi_gfx_load_setting(void);
     extern BOOL mmi_gfx_is_aud_on(void);
     extern BOOL mmi_gfx_is_vib_on(void);
     extern U8 mmi_gfx_get_audio_vol(void);
     extern void mmi_gfx_volume_up(void);
     extern void mmi_gfx_volume_down(void);

#ifndef __MMI_GAME_MULTICHANNEL_SOUND__
/****************************************************************************
* MACRO
*****************************************************************************/
#define GFX_PLAY_AUDIO_DVI(raw_data, size, play_style)                     \
do{                                                                        \
   if(GFX.is_aud_on && GFX.is_first_time_enter_gameover)                   \
   {                                                                       \
      mdi_audio_play_string_with_vol_path_non_block(  (void*)raw_data,     \
                                                      (U32)size,           \
                                                      MDI_FORMAT_DVI_ADPCM,\
                                                      play_style,          \
                                                      NULL,                \
                                                      NULL,                \
                                                      GFX.aud_volume,      \
                                                      MDI_DEVICE_SPEAKER2);\
   }                                                                       \
}while(0)

#define GFX_PLAY_AUDIO_WAV(raw_data, size, play_style)                     \
do{                                                                        \
   if(GFX.is_aud_on && GFX.is_first_time_enter_gameover)                   \
   {                                                                       \
      mdi_audio_play_string_with_vol_path_non_block(  (void*)raw_data,     \
                                                      (U32)size,           \
                                                      MDI_FORMAT_WAV,      \
                                                      play_style,          \
                                                      NULL,                \
                                                      NULL,                \
                                                      GFX.aud_volume,      \
                                                      MDI_DEVICE_SPEAKER2);\
   }                                                                       \
}while(0)

#define GFX_PLAY_AUDIO_MIDI(raw_data, size, play_style)                    \
do{                                                                        \
   if(GFX.is_aud_on && GFX.is_first_time_enter_gameover)                   \
   {                                                                       \
      mdi_audio_play_string_with_vol_path_non_block(  (void*)raw_data,     \
                                                      (U32)size,           \
                                                      MDI_FORMAT_SMF,      \
                                                      play_style,          \
                                                      NULL,                \
                                                      NULL,                \
                                                      GFX.aud_volume,      \
                                                      MDI_DEVICE_SPEAKER2);\
   }                                                                       \
}while(0)

#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
/****************************************************************************
* MACRO
*****************************************************************************/
#define GFX_PLAY_AUDIO_DVI(raw_data, size, play_style)                     \
do{                                                                        \
   if(GFX.is_first_time_enter_gameover)                                    \
   {                                                                       \
      mdi_audio_play_string_with_vol_path_non_block(  (void*)raw_data,     \
                                                      (U32)size,           \
                                                      MDI_FORMAT_DVI_ADPCM,\
                                                      play_style,          \
                                                      NULL,                \
                                                      NULL,                \
                                                      GFX.aud_volume,      \
                                                      MDI_DEVICE_SPEAKER2);\
   }                                                                       \
}while(0)

#define GFX_PLAY_AUDIO_WAV(raw_data, size, play_style)                     \
do{                                                                        \
   if(GFX.is_first_time_enter_gameover)                                    \
   {                                                                       \
      mdi_audio_play_string_with_vol_path_non_block(  (void*)raw_data,     \
                                                      (U32)size,           \
                                                      MDI_FORMAT_WAV,      \
                                                      play_style,          \
                                                      NULL,                \
                                                      NULL,                \
                                                      GFX.aud_volume,      \
                                                      MDI_DEVICE_SPEAKER2);\
   }                                                                       \
}while(0)

#define GFX_PLAY_AUDIO_MIDI(raw_data, size, play_style)                    \
do{                                                                        \
   if(GFX.is_first_time_enter_gameover)                                    \
   {                                                                       \
      mdi_audio_play_string_with_vol_path_non_block(  (void*)raw_data,     \
                                                      (U32)size,           \
                                                      MDI_FORMAT_SMF,      \
                                                      play_style,          \
                                                      NULL,                \
                                                      NULL,                \
                                                      GFX.aud_volume,      \
                                                      MDI_DEVICE_SPEAKER2);\
   }                                                                       \
}while(0)

#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ /* /__MMI_GAME_MULTICHANNEL_SOUND__ */

#define GFX_PLAY_VIBRATION()                            \
do{                                                     \
   if(GFX.is_vib_on && GFX.is_first_time_enter_gameover)\
   {                                                    \
      PlayVibratorOnce();                               \
   }                                                    \
}while(0)

#ifdef __MMI_GAME_MULTICHANNEL_SOUND__

#define GFX_PLAY_AUDIO_GAMEOVER()                                                        \
do{                                                                                      \
   if(GFX.is_background_music_on==TRUE)                                                  \
   GFX_PLAY_AUDIO_MIDI(g_gfx_audio_gameover, GFX_AUDIO_GAMEOVER, DEVICE_AUDIO_PLAY_ONCE);\
}while(0)

#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ /* /__MMI_GAME_MULTICHANNEL_SOUND__ */

#define GFX_PLAY_AUDIO_GAMEOVER()                                                        \
do{                                                                                      \
   GFX_PLAY_AUDIO_MIDI(g_gfx_audio_gameover, GFX_AUDIO_GAMEOVER, DEVICE_AUDIO_PLAY_ONCE);\
}while(0)

#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ /* /__MMI_GAME_MULTICHANNEL_SOUND__ */

#ifdef __MMI_GAME_MULTICHANNEL_SOUND__

#define GFX_PLAY_AUDIO_COMPLETE()                                                     \
   do{                                                                                   \
   if(GFX.is_background_music_on==TRUE)                                                  \
   GFX_PLAY_AUDIO_MIDI(g_gfx_audio_complete, GFX_AUDIO_COMPLETE, DEVICE_AUDIO_PLAY_ONCE);\
   }while(0)

#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
#define GFX_PLAY_AUDIO_COMPLETE()                                                        \
   do{                                                                                   \
   if(GFX.is_aud_on==TRUE)                                                               \
   GFX_PLAY_AUDIO_MIDI(g_gfx_audio_complete, GFX_AUDIO_COMPLETE, DEVICE_AUDIO_PLAY_ONCE);\
   }while(0)
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

/******************************************************************************************/
/* *************MULTICHANNEL SOUND APIS BASED MACROS *************************************
 *******************************************************************************************
 ******************************************************************************************/

#ifdef __MMI_GAME_MULTICHANNEL_SOUND__

   /* midi files are to be used both for background and sound effects */

/* MIDI OPEN-depending upon handleno paramter handle##handleno will be created */
#define GFX_OPEN_MULTICHANNEL_MIDI(raw_data, size, repeats,handleno)            \
   do{                                                                          \
      if( (GFX.is_background_music_on==TRUE) || (GFX.is_sound_effect_on==TRUE) )\
      {                                                                         \
      handleno=mdi_audio_mma_open_midi((void*) raw_data,                        \
                                      (U32)size,                                \
                                      repeats,                                  \
                                      NULL);                                    \
      }                                                                         \
   }while(0)

/* MIDI PLAY */
#define GFX_PLAY_MULTICHANNEL_MIDI(handle)                                                       \
      do{                                                                                        \
      if( ((GFX.is_background_music_on==TRUE) || (GFX.is_sound_effect_on==TRUE)) && (handle!= 0))\
      {                                                                                          \
         mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);                            \
         mdi_audio_set_volume(VOL_TYPE_MEDIA,GFX.aud_volume);                                    \
         mdi_audio_mma_play_midi( handle);                                                       \
      }                                                                                          \
   }while(0)

/* MIDI STOP */
#define GFX_STOP_MULTICHANNEL_MIDI(handle)                                                       \
      do{                                                                                        \
      if( ((GFX.is_background_music_on==TRUE) || (GFX.is_sound_effect_on==TRUE)) && (handle!= 0))\
      {                                                                                          \
         mdi_audio_mma_stop_midi( handle);                                                       \
      }                                                                                          \
   }while(0)

/* MIDI CLOSE */
#define GFX_CLOSE_MULTICHANNEL_MIDI(handle)                                                      \
      do{                                                                                        \
      if( ((GFX.is_background_music_on==TRUE) || (GFX.is_sound_effect_on==TRUE))&& (handle!= 0) )\
      {                                                                                          \
         mdi_audio_mma_close_midi( handle);                                                      \
      }                                                                                          \
   }while(0)

   /* waves files are to be used for sound effects */

/* WAV OPEN-depending upon handleno paramter handle##handleno will be created */
#define GFX_OPEN_MULTICHANNEL_WAV(raw_data, size, repeats,handleno) \
      do{                                                           \
      if(GFX.is_sound_effect_on)                                    \
      {                                                             \
      handleno=mdi_audio_mma_open_wav((void*) raw_data,             \
                                      (U32)size,                    \
                                      repeats,                      \
                                      NULL);                        \
       }                                                            \
   }while(0)

/* WAV PLAY */
#define GFX_PLAY_MULTICHANNEL_WAV(handle) \
      do{                                 \
      if(GFX.is_sound_effect_on)          \
      {                                   \
         mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);\
         mdi_audio_set_volume(VOL_TYPE_MEDIA,GFX.aud_volume);      \
         mdi_audio_mma_play_wav( handle); \
      }                                   \
   }while(0)

/* WAV STOP */
#define GFX_STOP_MULTICHANNEL_WAV(handle)     \
      do{                                     \
      if(GFX.is_sound_effect_on && handle!= 0)\
      {                                       \
         mdi_audio_mma_stop_wav( handle);     \
      }                                       \
   }while(0)

/* WAV CLOSE */
#define GFX_CLOSE_MULTICHANNEL_WAV(handle)    \
   do{                                        \
      if(GFX.is_sound_effect_on && handle!= 0)\
      {                                       \
         mdi_audio_mma_close_wav( handle);    \
      }                                       \
   }while(0)

#define GFX_OPEN_BACKGROUND_SOUND(raw_data, size, handleno)       \
      do {                                                        \
         if(GFX.is_background_music_on != FALSE)                  \
         {                                                        \
            GFX_OPEN_MULTICHANNEL_MIDI(raw_data,size,0,handleno); \
         }                                                        \
      }while(0)

#define GFX_PLAY_BACKGROUND_SOUND(handle)    \
   do{                                       \
      if(GFX.is_background_music_on !=FALSE) \
      {                                      \
         GFX_PLAY_MULTICHANNEL_MIDI(handle); \
      }                                      \
   }while(0)

#define GFX_STOP_BACKGROUND_SOUND(handle)                   \
   do{                                                      \
      if(GFX.is_background_music_on !=FALSE && handle!= 0)  \
      {                                                     \
         GFX_STOP_MULTICHANNEL_MIDI(handle);                \
      }                                                     \
   }while(0)

#define GFX_CLOSE_BACKGROUND_SOUND(handle)                \
   do{                                                    \
      if(GFX.is_background_music_on !=FALSE && handle!= 0)\
      {                                                   \
         GFX_CLOSE_MULTICHANNEL_MIDI(handle);             \
      }                                                   \
   }while(0)

/* when midi is used for sound effects */
#define GFX_OPEN_SOUND_EFFECTS_MIDI(raw_data, size, repeats,handleno)   \
      do {                                                              \
         if(GFX.is_sound_effect_on != FALSE)                            \
         {                                                              \
            GFX_OPEN_MULTICHANNEL_MIDI(raw_data,size,repeats,handleno); \
         }                                                              \
      }while(0)

#define GFX_PLAY_SOUND_EFFECTS_MIDI(handle)  \
   do{                                       \
      if(GFX.is_sound_effect_on !=FALSE)     \
      {                                      \
         GFX_PLAY_MULTICHANNEL_MIDI(handle); \
      }                                      \
   }while(0)

#define GFX_STOP_SOUND_EFFECTS_MIDI(handle)              \
   do{                                                   \
      if(GFX.is_sound_effect_on !=FALSE && handle!= 0)   \
      {                                                  \
         GFX_STOP_MULTICHANNEL_MIDI(handle);             \
      }                                                  \
   }while(0)

#define GFX_CLOSE_SOUND_EFFECTS_MIDI(handle)          \
   do{                                                \
      if(GFX.is_sound_effect_on !=FALSE && handle!= 0)\
      {                                               \
         GFX_CLOSE_MULTICHANNEL_MIDI(handle);         \
      }                                               \
   }while(0)

/* when midi is used for silent sound(dummy) midi */

#define GFX_OPEN_DUMMY_BACKGROUND_SOUND()                                                                                     \
      do {                                                                                                                    \
         if(GFX.is_background_music_on == FALSE  &&  GFX.is_sound_effect_on==TRUE)                                            \
         {                                                                                                                    \
            GFX_OPEN_MULTICHANNEL_MIDI(g_gfx_Dummy_background_midi,GFX_AUDIO_DUMMYBACKGROUND_MIDI,0,dummy_background_midi);   \
         }                                                                                                                    \
      }while(0)

#define GFX_PLAY_DUMMY_BACKGROUND_SOUND()                                        \
   do{                                                                           \
      if(GFX.is_background_music_on == FALSE  &&  GFX.is_sound_effect_on==TRUE)  \
      {                                                                          \
         GFX_PLAY_MULTICHANNEL_MIDI(dummy_background_midi);                      \
      }                                                                          \
   }while(0)

#define GFX_STOP_DUMMY_BACKGROUND_SOUND()                                        \
   do{                                                                           \
      if(GFX.is_background_music_on == FALSE  &&  GFX.is_sound_effect_on==TRUE)  \
      {                                                                          \
         GFX_STOP_MULTICHANNEL_MIDI(dummy_background_midi);                      \
      }                                                                          \
   }while(0)

#define GFX_CLOSE_DUMMY_BACKGROUND_SOUND()                                       \
   do{                                                                           \
      if(GFX.is_background_music_on == FALSE  &&  GFX.is_sound_effect_on==TRUE)  \
      {                                                                          \
         GFX_CLOSE_MULTICHANNEL_MIDI(dummy_background_midi);                     \
      }                                                                          \
   }while(0)

#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

#endif /* __GAME_FRAMEWORK__ */ 

