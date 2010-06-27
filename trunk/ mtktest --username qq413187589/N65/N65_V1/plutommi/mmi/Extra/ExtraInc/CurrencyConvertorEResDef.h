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
 * CurrencyConvertorEResDef.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines constant, enum values, structure, and function prototypes for currency converter application.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _MMI_CURRENCYCONVE_RESDEF_H
#define _MMI_CURRENCYCONVE_RESDEF_H
#include "MMI_features.h"
#ifdef __MMI_EXTENDED_CURRENCY_CONVERTER__

#include "MMIDataType.h" 


typedef enum
{
    STR_CURRENCYCONV_RATEINPUT = CURRENCY_CONVERTER + 1,
    STR_CURRENCYCONV_EXCHANGE,
    STR_CURRENCYCONV_RATE,
    STR_CURRENCYCONV_INPUT,
    STR_CURRENCYCONV_LOCAL,
    STR_CURRENCYCONV_FOREIGN,
    STR_CURRENCYCONV_USD,
    STR_CURRENCYCONV_EUR,
    STR_CURRENCYCONV_RUB,
    STR_CURRENCYCONV_JPY,
    STR_CURRENCYCONV_GBP,
    STR_CURRENCYCONV_HKD,
    STR_CURRENCYCONV_CUSTOM1,
    STR_CURRENCYCONV_CUSTOM2,
    STR_CURRENCYCONV_CUSTOM3,
    STR_CURRENCYCONV_USD_ABBR,
    STR_CURRENCYCONV_EUR_ABBR,
    STR_CURRENCYCONV_RUB_ABBR,
    STR_CURRENCYCONV_JPY_ABBR,
    STR_CURRENCYCONV_GBP_ABBR,
    STR_CURRENCYCONV_HKD_ABBR,
    ERROR_CURRENCYCONV_RATE1,
    ERROR_CURRENCYCONV_RATE2,
    STR_ID_CURRENCYCONVERTOR_RESET,
    EXTRA_MENU_CURRENCYCONVERTOR_STRINGID
} STR_CCONV_ENUM;

typedef enum
{
    EXTRA_MENU_CURRENCYCONVERTOR_IMAGEID = CURRENCY_CONVERTER + 1,
    CURRENCY_CONVERTOR_IMAGE
} IMG_ID_CCONV_ENUM;

typedef enum
{
    SCR_ID_CCONV_RATE_INPUT = CURRENCY_CONVERTER + 1,
    SCR_ID_CCONV_COMPUTE,
    SCR_ID_CCONV_DUMMY
} SCR_ID_CCONV_ENUM;
#endif /* __MMI_EXTENDED_CURRENCY_CONVERTER__ */
#endif /*_MMI_CURRENCYCONVE_RESDEF_H*/

