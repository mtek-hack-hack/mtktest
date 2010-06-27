/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/vendor/dict/gv/adaptation/inc/DictionaryCoreGV.h,v 1.1 2007/05/17 07:26:37 bw Exp $
*
* $Id: DictionaryCoreGV.h,v 1.1 2007/05/17 07:26:37 bw Exp $
*
* $Date: 2007/05/17 07:26:37 $
*
* $Name: 1.1 $
*
* $Locker$
*
* $Revision: 1.1 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: DictionaryCoreGV.h,v $
* Revision 1.1  2007/05/17 07:26:37  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_DICT_GV__

#include "stdC.h"
#include "PixtelDatatypes.h"
/* ------------------- Constants -------------------------------- */
#define MMI_DICT_ID_FETCH_MAX          16       /* MAX ID at one time */

#define MMI_DICT_CORE_WORD_MAX            32    /* ASCII word length */
// #define MMI_DICT_MEANING_RESULT_MAX                  512

#define MMI_DICT_SYNO_ANTO_LENGTH_MAX     MMI_DICT_ID_FETCH_MAX*(MMI_DICT_CORE_WORD_MAX+2)      /* 512+16+16 =542 // 16 for null for each word and 16 for '/' between words */
#define MMI_DICT_EXAMPLE_SENTENCE_MAX     1024
#define MMI_DICT_MEANING_RESULT_MAX       1024  /* MMI_DICT_CORE_WORD_MAX + MMI_DICT_CORE_WORD_MAX *2 + 512 // 672 */

#define MMI_DICT_SYNO                  0x01     /* synonym */
#define MMI_DICT_ANTO                  0x02     /* antonym */
#define MMI_DICT_INF                0x04        /* inflection */
#define MMI_DICT_DERIV                 0x08     /* derivative */
#define MMI_DICT_HOMO                  0x10     /* homonym */
#define MMI_DICT_SENTS                 0x20     /* example sentence */
#define MMI_DICT_CONFS                 0x40     /* confused word */

/* ------------------- ENUM ------------------------- */

/* For ENUM */
typedef enum
{
    DICT_ENGLISH,
    DICT_CHINESE,
    TOTALLANG
} MMI_DICT_LANGUAGE;

/* ------------------- Data Structures ------------------------- */

/* For List Display */
typedef struct
{
    U8 dict_word[(MMI_DICT_CORE_WORD_MAX + 1) *ENCODING_LENGTH];
    U32 dict_id;
} mmi_dict_id_str_struct;

/* For Search Result */
typedef struct
{
    U8 dict_word[(MMI_DICT_CORE_WORD_MAX + 1) *ENCODING_LENGTH];
    U8 dict_meaning[(MMI_DICT_MEANING_RESULT_MAX + 1) *ENCODING_LENGTH];
    U8 dict_synonym[(MMI_DICT_SYNO_ANTO_LENGTH_MAX + 1) *ENCODING_LENGTH];
    U8 dict_antonym[(MMI_DICT_SYNO_ANTO_LENGTH_MAX + 1) *ENCODING_LENGTH];
    U8 dict_example_sentence[(MMI_DICT_EXAMPLE_SENTENCE_MAX + 1) *ENCODING_LENGTH];
    U32 dict_suppflag;
} mmi_dict_result_struct;

/* ------------------- Global Functions ------------------------- */
extern pBOOL mmi_dict_init(void);
extern pBOOL mmi_dict_exit(void);
extern S32 mmi_dict_get_total_num(char *dict_word);
extern BOOL mmi_dict_get_word_by_indx(U8 lin, U32 Indx, char *dict_word);
extern U32 mmi_dict_wild_search(U8 lin, char *dict_word, U32 m, U32 n, void *wordlist[]);
extern BOOL mmi_dict_exact_search(char *dict_word, U8 lin, U8 lout, U32 supp, void *fetchresult);
extern S32 mmi_dict_exact_search_id(char *dict_word, U8 lin, U8 lout);
extern S32 mmi_dict_exact_search_prev_id(char *dict_word, S32 steps, U8 lin, U8 lout);
extern S32 mmi_dict_exact_search_next_id(char *dict_word, S32 steps, U8 lin, U8 lout);
extern void mmi_dict_compare_ucs2_strings(S8 *string1, S8 *string2, U8 *same_count, S32 *distance);
extern S32 mmi_dict_compare_chars(U16 char1, U16 char2);

#endif /* __MMI_DICT_GV__ */ 

