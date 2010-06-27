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
 * CurrencyConvLGE.h
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

#ifndef _MMI_CURRENCYCONV_H
#define _MMI_CURRENCYCONV_H
#include "MMI_features.h"
#ifdef __MMI_EXTENDED_CURRENCY_CONVERTER__
#include "MMIDataType.h"
#include "CurrencyConvertorEResDef.h"
/* 
 * Define
 */

/* 
 * Typedef 
 */
typedef enum
{
    CCONV_CURRENCY_INLINE_LOCAL_SELECT = 0,
    CCONV_CURRENCY_INLINE_LOCAL,
    CCONV_CURRENCY_INLINE_FORE_SELECT,
    CCONV_CURRENCY_INLINE_FORE,
    CCONV_CURRENCY_INLINE_TOTAL
} CCONV_CURRENCY_INLINE_ITEM_ENUM;

typedef enum
{
    CCONV_RATE_INLINE_LOCAL_CAP = 0,
    CCONV_RATE_INLINE_LOCAL_SELECT,
    CCONV_RATE_INLINE_FORE_CAP,
    CCONV_RATE_INLINE_FORE_SELECT1,
    CCONV_RATE_INLINE_RATE1,
    CCONV_RATE_INLINE_FORE_SELECT2,
    CCONV_RATE_INLINE_RATE2,
    CCONV_RATE_INLINE_FORE_SELECT3,
    CCONV_RATE_INLINE_RATE3,
    CCONV_RATE_INLINE_FORE_SELECT4,
    CCONV_RATE_INLINE_RATE4,
    CCONV_RATE_INLINE_FORE_SELECT5,
    CCONV_RATE_INLINE_RATE5,
    CCONV_RATE_INLINE_TOTAL
} CCONV_RATE_INLINE_ITEM_ENUM;

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */
extern void mmi_cconv_init(void);
extern void mmi_cconv_deinit(void);
extern void mmi_cconv_menu_highlight_hdlr(void);
extern void mmi_cconv_pre_entry_app(void);
extern void mmi_cconv_entry_app(void);
extern void mmi_cconv_exit_app(void);
extern void mmi_cconv_pre_entry_rate(void);
extern void mmi_cconv_entry_rate(void);
extern void mmi_cconv_exit_rate(void);
#endif /* __MMI_EXTENDED_CURRENCY_CONVERTER__ */ // #ifdef __MMI_EXTENDED_CURRENCY_CONVERTER__
#endif /* _MMI_CURRENCYCONV_H */ // #ifndef _MMI_CURRENCYCONV_H

