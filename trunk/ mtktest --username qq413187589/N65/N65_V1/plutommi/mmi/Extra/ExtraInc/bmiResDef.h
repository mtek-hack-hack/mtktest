/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * BmiResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file intends for defining the resource id used in BMI application
 *
 * Author:
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
 /*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2003
*
*******************************************************************************/
#ifndef _MMI_BMIRESDEF_H
#define _MMI_BMIRESDEF_H

#include "MMI_features.h"
#ifdef __MMI_BMI__

#include "MMIDataType.h" 

typedef enum
{
    STR_BMI_ACT1 = HEALTH_BMI + 1,
    STR_BMI_WELCOME_CAPTION,
    STR_BMI_INPUT_CAPTION,
    /* STR_BMI_RESULT_TEXT, */
    STR_BMI_RESULT_CAPTION,
    STR_BMI_MALE_TEXT,
    STR_BMI_FEMALE_TEXT,
    STR_BMI_HEIGHT_TEXT,
    STR_BMI_WEIGHT_TEXT,
    STR_BMI_HEIGHT_ERROR_TEXT,
    STR_BMI_WEIGHT_ERROR_TEXT,
    STR_BMI_HEIGHT_WEIGHT_ERROR,
    STR_BMI_BMI_TEXT,
    //STR_BMI_LEVEL,
    STR_BMI_NORMAL,
    STR_BMI_FAT,
    STR_BMI_THIN,
    EXTRA_HEALTH_MENU_BMI_STRINGID,
    STR_BMI_TOTAL
} STR_ID_BMI_ENUM;

typedef enum
{
    IMG_BMI_WELCOME_SCREEN = HEALTH_BMI + 1,
    IMG_BMI_WELCOME_CAPTION,
    IMG_BMI_RED_FLOWER,
    IMG_BMI_BLUE_FLOWER
} IMG_ID_BMI_ENUM;

typedef enum
{
    SCR_BMI_WELCOME = HEALTH_BMI + 1,
    SCR_BMI_INPUT,
    SCR_BMI_RESULT,
    SCR_POPUP_HEALTH
} SCR_ID_BMI_ENUM;
#endif /*__MMI_BMI__ */
#endif /*_MMI_BMIRESDEF_H*/

