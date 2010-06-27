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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/vendor/dict/motech/adaptation/inc/de_api.h,v 1.1 2007/05/17 07:26:37 bw Exp $
*
* $Id: de_api.h,v 1.1 2007/05/17 07:26:37 bw Exp $
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
* $Log: de_api.h,v $
* Revision 1.1  2007/05/17 07:26:37  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/*
    Copyright Reserved Mingtta
*/

#ifndef DE_API_H
#define DE_API_H

#ifdef __cplusplus
extern "C"
{
#endif

#define MAX_WORD_SIZE       31        /*the maximum length of a word,the size is temporaryly defined*/
#define MAX_PAGE_SIZE       20
#define MAX_LIB_NUM         31

typedef  unsigned short     DECHAR, *DESTR;
typedef  unsigned char      LIBIDX;

typedef enum
{
    DE_OK,                    /* function finished without error.*/
    DE_PARM_OUTOFRANGE,       /* parameters out of valid range.*/
    DE_INVALID_DICT,          /* dictionary assigned has wrong format.*/
    DE_NO_ENOUGH_MEMORY,      /* dynamic memory assigned not enough.*/
    DE_WORD_NOT_FOUND,        /* specified word not found.*/
    DE_UNKNOWN                /* unspecified error occurred.*/  
} DEReturnValue;

typedef enum
{
    TYPE_EMPTY = 0,           /* no word type or other type*/
    TYPE_NOUN = 1,            /* noun */
    TYPE_PRON,                /* pronoun */
    TYPE_VI,                  /* verb intransitive */
    TYPE_VT,                  /* verb transitive */
    TYPE_ADJ,                 /* adjective */
    TYPE_ADV,                 /* sdverb*/
    TYPE_PREP,                /* preposition */
    TYPE_CONJ,                /* conjunction */
    TYPE_INT,                 /* interjection*/
    TYPE_ABBR,                /*abbreviation*/
    TYPE_END
} WORDTYPE;

#ifndef BYTE
    typedef unsigned char   BYTE;
    typedef unsigned short  WORD;
    typedef unsigned long   DWORD;
#endif
#if 0
	#ifndef BOOL
/* under construction !*/
	#endif
/* under construction !*/
	#ifndef FALSE
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
	#ifndef NULL
/* under construction !*/
	#endif
#endif
typedef struct
{
    void    *pRAM;
    void    *pUserLib; // must be NULL
    void    *pStandardLib[3]; // ignored
    BYTE    NumofStandardLib; // ignored
} DEData, *LPDEData;

typedef struct tagWORDLIST
{
    DESTR               pWord;      /* pointer to a string */
    struct tagWORDLIST  *pNext;
} WORDLIST;

typedef struct tagONEEXP
{
    BYTE                typeofword;     /* WORDTYPE: parts of speech */
    WORDLIST            *interpretation;
    struct tagONEEXP    *pNext;
} ONEEXP, *ONEEXP_LIST;

typedef struct
{
    BYTE    dIndex;             /* indicate which library the content is from*/ 
    BYTE    numofIrregular;     /*number of irregularities*/          
    BYTE    numofSynonym;       /*number of synonyms*/        
    BYTE    numofAntonym;       /*number of antonyms*/        
    DESTR   *pIrregular;        /* a series of irregularities  */
    DESTR   *pSynonym;          /* a series of synonym  */
    DESTR   *pAntonym;          /* a series of Antonym   */
    DESTR   phoneSym;			/* phonetic symbol    */
    DESTR   pronunciation;
    ONEEXP_LIST explanation;    /* a series of explanation  */
} ONECONT;

typedef struct tagWCONTENT
{
    ONECONT             *pContent;  /* contents in one dictionary */
    struct tagWCONTENT  *pNext;     /* pointer to next Dictionary */
} WCONTENT, *WCONTENT_LIST;

unsigned long DEGetMemSize(DEData *pData, unsigned char* ErrCode);
unsigned char DEInit(DEData *pData);
unsigned char DETerminate(DEData *pData);
unsigned char DESearchWord(DEData *pData, DESTR InputWord, DESTR OutputWord);
unsigned char DEGetWord(DEData *pData, short steps, DESTR pWord);
short DEChangeFocus(DEData *pData, short steps);
unsigned long DEGetWordContentSize(DEData *pData, BYTE flag);
unsigned char DEGetWordContent(DEData *pData, BYTE flag, WCONTENT *content);
unsigned long DEInstantGetWordContentSize(DEData *pData, BYTE flag, DESTR InputWord);
unsigned char DEInstantGetWordContent(DEData *pData, BYTE flag, DESTR InputWord, WCONTENT *content);


#ifdef __cplusplus
}
#endif

#endif
