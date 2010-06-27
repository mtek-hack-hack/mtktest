/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  j2me_custom.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *      This file is intends for customization of default Java midletsuites
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _J2ME_CUSTOM_H
#define _J2ME_CUSTOM_H

/*************************************************************************
 * Include Customize Options 
 *************************************************************************/

/*************************************************************************
 * Constant Definition
 *************************************************************************/
#define J2ME_JSR_75_FILE_HANDLER_RESERVE_COUNT           (6)

#if defined(__IJET_VM__)
#define OGDR_SECURITY_SETTING
#endif

typedef enum {
	GAMETYPE_JAVA_GAME,
	GAMETYPE_INFUSIO_EUREKA,
	GAMETYPE_INFUSIO_AP,
	GAMETYPE_SURFKITCHEN,
	GAMETYPE_MUSICWAV,
	GAMETYPE_INVALID_TYPE
} game_type_enum;
#ifdef SUPPORT_SURFKITCHEN
#define ALIAS_DRIVE_COUNT	3	/* Number of alias drives */ 
#else
#define ALIAS_DRIVE_COUNT	2	/* Number of alias drives */ 
#endif
#define SUPPORT_SURFKIT_DRIVE 1	/* 1 means support "surfkit" alias drive. Do NOT forget to configure SUPPORT_SURFKIT_DRIVE in DRAGONFLY_BB.mak also. */ /* Dennis Shih */

/*************************************************************************
 * Structure Definition
 *************************************************************************/
typedef struct j2me_virtual_file_info_struct_t
{
    const int virtual_file_count;
    const char **virtual_file_name;
    const unsigned char **virtual_file_data;
    const int *virtual_file_size;
} j2me_virtual_file_info_struct;

typedef struct j2me_normal_file_info_struct_t
{
    const int normal_file_count;
    const char **normal_file_name;
    const unsigned char **normal_file_data;
    const int *normal_file_size;
} j2me_normal_file_info_struct;

typedef struct j2me_custom_file_info_struct_t
{
    const int default_mids_count;
    j2me_virtual_file_info_struct virtual_file_info;
    j2me_normal_file_info_struct normal_file_info;
} j2me_custom_file_info_struct;

typedef struct confpropty_setting_struct_t
{
    char *key;
    char *value;
} confpropty_setting_struct;

/* Normal midletsuite execuite VM run with normal heap/runtime memory size, however, 
   installation/update/list/getinfo etc use basice memory size if with application 
   shared memory support */
typedef struct j2me_custom_resource_info_struct_t
{
    unsigned max_storage_space;         /* maximum storage space limitation */
    unsigned javaheap_space_size;       /* java heap space size */
    /* If with Application Shared Memory Management, needn't static memory */
    long *javaheap_space;               /* java heap space memory region */
    unsigned javaruntimemem_space_size; /* java runtime memory pool size */
    long *javaruntimemem_space;         /* java runtime memory pool region */
    char storage_drive;                 /* java storage drive/path */
    confpropty_setting_struct *default_imp_property;
    confpropty_setting_struct *default_app_property;
    unsigned int max_installed_mids;
    /* 
     * The original implementation on our platform for handling MT call on installing is as follows: 
     * when installing Java game, incomming call will suspend the installation and the installation will be resumed after the incomming call finished. 
     * But for passing the 7.1.5 test case of CMCC 1.0 spec, we'll add a compile option. 
     * When the compile option is ON, MTcall on installating will terminate the installation and the data for the installation will be cleaned up. 
     * The compile option definition will be "CMCC_7_1_5".
     */
    char is_cmcc_715;
	char* alias_drive[ALIAS_DRIVE_COUNT];	/* Dennis Shih */
	int alias_drive_type[ALIAS_DRIVE_COUNT];	/* Dennis Shih */
} j2me_custom_resource_info_struct;

/* Custom event handling */
typedef int (*j2me_custom_handler_ptr) (void *param);

#define J2ME_CUSTOM_NULL_HANDLER                   (0)
#define J2ME_CUSTOM_EVENT_HANDLER                     (1)
#define J2ME_CUSTOM_EXTEND_HANDLER                    (2)
/* Customer can extend define their specific handler id in  custom\j2me\j2me_custom.param.h */

/*************************************************************************
 * External Declaration
 *************************************************************************/
extern j2me_custom_file_info_struct *j2me_custom_file_info_ptr;
extern int j2me_default_game_count;
extern int virtual_file_count;

extern int game_j2me_default_game_count;
extern int game_virtual_file_count;

#ifdef __SUPPORT_INFUSIO__
extern j2me_custom_file_info_struct *eureka_custom_file_info_ptr;
extern int eureka_default_game_count;
extern int eureka_virtual_file_count;
#endif /* __SUPPORT_INFUSIO__ */

#ifdef SUPPORT_SURFKITCHEN
extern j2me_custom_file_info_struct *surfkitchen_custom_file_info_ptr;
extern int surfkitchen_default_game_count;
extern int surfkitchen_virtual_file_count;
#endif /* SUPPORT_SURFKITCHEN */

#ifdef SUPPORT_MUSICWAV
extern j2me_custom_file_info_struct *musicwav_custom_file_info_ptr;
extern int musicwav_default_game_count;
extern int musicwav_virtual_file_count;
#endif /* SUPPORT_MUSICWAV */

extern int j2me_custom_handler(unsigned int handle_id, void *param);
extern char* _jvm_get_dir_path(game_type_enum type);
extern j2me_custom_file_info_struct* _jvm_get_builtin_file_info(game_type_enum type);
extern int jvm_get_current_game_type(void);
extern int jvm_get_initiate_game_type(void);

#ifdef __IJET_VM__
#define __SUPPORT_NATIVE_INSTALLER__
#endif

#endif /* _J2ME_CUSTOM_H */
