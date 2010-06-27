/*
 * Copyright (C) Obigo AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * brs_char.c
 *
 * Created by Örjan Percy. 021119
 *
 * Revision history:
 *   021119, Created
 *
 */
/************************************************************
 * This file is used for:
 * + validating wml input using a format string
 * + text transform
 ************************************************************/

#include "brs_char.h"
#include "msf_cmmn.h"
#include "msf_chrt.h"
#include "brs_main.h"
#include "brs_css.h"
#ifdef BRS_CFG_EXTENDED_FORMAT_CHECK
#include "msf_uncd.h"
#include "msf_chrs.h"
#endif

#ifndef BRS_CFG_EXTENDED_FORMAT_CHECK
/*
 * Returns TRUE if the character pointed to by 'v' 
 * conforms to the 'format_code'.
 * Returns FALSE otherwise and especially if
 * the number of characters in 'value' is less 
 * than the number specified in the format.
 */
static
int
brs_wml_input_validate_char(const char *v, char format_code,
                            brs_input_validation_error_t *err_type)
{
  /* If any character is not ascii it will be ignored,
   * i.e. true will be returned.
   */

  *err_type = INPUT_ERR_GENERAL;

  if (*v == '\0')
  {
    /* value ended before it was allowed by format */
    *err_type = INPUT_ERR_LENGTH;
    return FALSE;
  }

  switch (format_code)
  {
    case 'A':
      if (ct_isdigit(*v) || ct_islower(*v))
      {
        *err_type = INPUT_ERR_UPPER_PUNCT;
        return FALSE;
      }
      else
        return TRUE;
    case 'a':
      if (ct_isdigit(*v) || ct_isupper(*v))
      {
        *err_type = INPUT_ERR_LOWER_PUNCT;
        return FALSE;
      }
      else
        return TRUE;
    case 'N':
      if ( !ct_isdigit(*v))
      {
        *err_type = INPUT_ERR_NUMERIC;
        return FALSE;
      }
      else
        return TRUE;
    case 'n':
      if (ct_isupper(*v) || ct_islower(*v))
      {
        *err_type = INPUT_ERR_NUMERIC_PUNCT;
        return FALSE;
      }
      else
        return TRUE;
    case 'X':
      if (ct_islower(*v))
      {
        *err_type = INPUT_ERR_UPPER;
        return FALSE;
      }
      else
        return TRUE;
    case 'x':
      if (ct_isupper(*v))
      {
        *err_type = INPUT_ERR_LOWER;
        return FALSE;
      }
      else
        return TRUE;
    case 'M':
    case 'm':
      return TRUE;
  }
  return FALSE;
}
#endif

#ifdef BRS_CFG_EXTENDED_FORMAT_CHECK

/* Definitions according to the WML specification. */
#define isUpper(c) (((c) == MSF_UNICODE_GC_LU) || ((c) == MSF_UNICODE_GC_LM))
#define isLower(c) (((c) == MSF_UNICODE_GC_LL) || ((c) == MSF_UNICODE_GC_LM))
#define isLetter(c) (((c) == MSF_UNICODE_GC_LU) || ((c) == MSF_UNICODE_GC_LL) || ((c) == MSF_UNICODE_GC_LM) || ((c) == MSF_UNICODE_GC_LO))
#define isNumeric(c) ((c) == MSF_UNICODE_GC_ND)
#define isPunctuation(c) ((c) == MSF_UNICODE_GC_P)
#define isSymbol(c) ((c) == MSF_UNICODE_GC_S)
#define isSeparator(c) ((c) == MSF_UNICODE_GC_Z)

#define RETURN_VALUE_FOR_UNDEFINED_CATEGORY TRUE /* set to FALSE to enforce super-strict matching */

/*
 * Validates if a utf8 Unicode character matches a 
 * format specifier. Returnes TRUE is the character
 * matcher the format specifier, else FALSE is returned.
 */
int
brs_wml_unicode_matches_format_specifier(const char *v, char format_code,
                                         brs_input_validation_error_t *err_type)
{
  int cat;
  cat = msf_unicode_general_category(v);
  if(cat == MSF_UNICODE_GC_XX) /* Unknown category or illegal utf8 character*/
    return RETURN_VALUE_FOR_UNDEFINED_CATEGORY;

  switch (format_code)
  {
  case 'A':
   if (! (isUpper(cat) || isSymbol(cat) || isPunctuation(cat)))
      {
        *err_type = INPUT_ERR_UPPER_PUNCT;
        return FALSE;
      }
      else
        return TRUE;

    case 'a':
      if (! (isLower(cat) || isSymbol(cat) || isPunctuation(cat)))
      {
        *err_type = INPUT_ERR_LOWER_PUNCT;
        return FALSE;
      }
      else
        return TRUE;

    case 'N':
      if (! isNumeric(cat))
      {
        *err_type = INPUT_ERR_NUMERIC;
        return FALSE;
      }
      else
        return TRUE;

    case 'n':
      if (! (isNumeric(cat) || isSymbol(cat) || isPunctuation(cat)))
      {
        *err_type = INPUT_ERR_NUMERIC_PUNCT;
        return FALSE;
      }
      else
        return TRUE;

    case 'X':
      if (! (isUpper(cat) || isNumeric(cat) || isSymbol(cat) || isPunctuation(cat)))
      {
        *err_type = INPUT_ERR_UPPER;
        return FALSE;
      }
      else
        return TRUE;

    case 'x':
      if (! (isLower(cat) || isNumeric(cat) || isSymbol(cat) || isPunctuation(cat)))
      {
        *err_type = INPUT_ERR_LOWER;
        return FALSE;
      }
      else
        return TRUE;

    case 'M':
    case 'm':
      return (isLetter(cat) || isNumeric(cat) || isSymbol(cat) || isPunctuation(cat) || 
              isSeparator(cat));
  }

  return RETURN_VALUE_FOR_UNDEFINED_CATEGORY; /* invalid format specifier treated like
                                                 character of unspecified category */


}
#endif /* BRS_CFG_EXTENDED_FORMAT_CHECK */ 

/* 
 * Validate the 'value' using a valid 'format' string.
 * At return 'err_pos' contains the current position in the string which is the
 * character position an error occurred in case FALSE is returned. 
 * If TRUE is returned 'err_pos' simply contain the number of 
 * characters in the string supplied in 'value'.
 * If 'is_modified' is set then the 'value' has been changed due to constants.
 */
int
brs_wml_input_validate_value(const char *format,
                             int is_valid_format,
                             char **value,
                             int empty_ok,
                             int *is_modified,
                             int *err_pos,
                             brs_input_validation_error_t *err_type)
{
  const char *p = format;
  char *v = *value;
  (*err_pos) = 0;
  (*err_type) = INPUT_ERR_GENERAL;
  *is_modified = FALSE;
  
  if ((p == NULL) || (! is_valid_format))
  {
    /* equivalent to "*M" format */
    *err_type = INPUT_ERR_EMPTY;/* err_type will be set to INPUT_ERR_EMPTY even if value is ok?*/
    return empty_ok ? TRUE : ((v != NULL) && (*v != '\0'));
  }

  if (! empty_ok && (v == NULL || *v == '\0'))
  {
    *err_type = INPUT_ERR_EMPTY;
    return FALSE;
  }

  if (empty_ok && (v == NULL || *v == '\0'))
    return TRUE;

  while (*p != '\0')
  {
    switch (*p)
    {

    case 'A':
    case 'a':
    case 'N':
    case 'n':
    case 'X':
    case 'x':
    case 'M':
    case 'm':
#ifdef BRS_CFG_EXTENDED_FORMAT_CHECK
    {
      MSF_UINT32 uu;
      int    len = msf_cmmn_utf8_charlen(v);

      if ((msf_charset_utf8_to_unicode(v, &uu) > -1) &&
          (! (uu >> 16) > 0) && /* test only done on characters with value < 0xFF00 */
          (! brs_wml_unicode_matches_format_specifier (v, *p, err_type))) {
          return FALSE;
      }
      else { /* skip validation of non-ascii character. */
        (*err_pos) += len;
        v += len;
      }
    }
#else
      if (ct_isascii(*v)) {
        if (! brs_wml_input_validate_char(v, *p, err_type))
          return FALSE;
        (*err_pos)++;
        v++;
      }
      else {
        /* skip validation of non-ascii character. */
        int len = msf_cmmn_utf8_charlen(v);
        (*err_pos) += len;
        v += len;
      }
#endif
      p++;
      break;

    case '\\':
      p++;
      if (ct_isascii(*p)) {
        if (*p != *v) {
          /* reached end of value, add p which is a constant char */
          int length = strlen(*value);
          if (*err_pos >= length) {
            char* temp = msf_cmmn_strdup(MSF_MODID_BRS, *value);
            BRS_MEM_FREE(*value);
            *value = BRS_MEM_ALLOC(length + 2);
            strcpy(*value, temp);
            v = *value + *err_pos;
            BRS_MEM_FREE(temp);
          }
          *v = *p;
          *(v + 1) = '\0'; /* null terminate value */
          *is_modified = TRUE;
        }
        p++;
        v++;
        (*err_pos)++;
      }
      else {
        /* match the escaped unicode character */
        int char_len = msf_cmmn_utf8_charlen(p);
        while (char_len-- > 0) {
          if (*p == '\0' || *v == '\0' || *p != *v)
            return FALSE;
          p++;
          v++;
          (*err_pos)++;
        }
      }
      break;

    case '*':
      p++;
      while (*v != '\0') {
#ifdef BRS_CFG_EXTENDED_FORMAT_CHECK
        MSF_UINT32 uu;
        int    len = msf_cmmn_utf8_charlen (v);

        if ((msf_charset_utf8_to_unicode (v, &uu) > -1) &&
            (! (uu >> 16) > 0) && /* test only done on characters with value < 0xFF00 */
            (! brs_wml_unicode_matches_format_specifier (v, *p, err_type))){
            return FALSE;
        }
        else{
          v += len;
          (*err_pos) += len;
        }
#else
        if (! brs_wml_input_validate_char(v, *p, err_type))
          return FALSE;
        v++;
        (*err_pos)++;
#endif
      }
      return TRUE;

    default:
      if (ct_isdigit(*p)) {
        int i,str_length, n_chars = *p - '0';
        p++;
        while (ct_isdigit (*p)) {
          n_chars = n_chars * 10 + (*p - '0');
          p++;
        }
        
        str_length = strlen(v);

        if (str_length < n_chars) { 
          n_chars = str_length; 
        }
        
        for (i = 0; i < n_chars; i++) {
#ifdef BRS_CFG_EXTENDED_FORMAT_CHECK
          MSF_UINT32 uu;
          int        len;
#endif
          if (*v == '\0')
            break; /* if there are fewer characters than n in 
                    * the value, we skip testing here.
                    * The state should be success. 
                    */
#ifdef BRS_CFG_EXTENDED_FORMAT_CHECK
          len = msf_cmmn_utf8_charlen (v);

          if ((msf_charset_utf8_to_unicode (v, &uu) > -1) &&
              (! (uu >> 16) > 0) && /* test only done on characters with value < 0xFF00 */
              (! brs_wml_unicode_matches_format_specifier (v, *p, err_type))){
              return FALSE;
          }
          else{
            v += len;
            (*err_pos) += len;
          }
#else
          if (! brs_wml_input_validate_char(v, *p, err_type))
            return FALSE;

          v++;
          (*err_pos)++;
#endif
        }
        return (*v == '\0');
      }
    }
  }
  return (*v == '\0');
}

/* 
 * Validate wml data in utf8 using a format string.
 * If an incorrect character is found, the string is truncated at that
 * position.
 */
int
brs_wml_input_format_correct(MsfStringHandle* string,
                             int* is_modified,
                             const char* format,
                             int is_valid_format,
                             int empty_ok)
{
  int utf8_len = HDIa_widgetStringGetLength(*string, TRUE, MsfUtf8);
  int wml_ok = FALSE;
  *is_modified = FALSE;
  if(utf8_len)
  {
    char* utf8_c_str = BRS_MEM_ALLOC(utf8_len + 1);
    memset(utf8_c_str, 0, utf8_len + 1);
    HDIa_widgetStringGetData(*string, utf8_c_str, MsfUtf8);
    if (utf8_c_str)
    {
      int err_pos = 0;
      brs_input_validation_error_t err_type;
      /* make a safe copy to work on */
      char* utf8_str = msf_cmmn_strdup(MSF_MODID_BRS, utf8_c_str);
      wml_ok = brs_wml_input_validate_value(format, is_valid_format,
                                            &utf8_str, empty_ok, is_modified,
                                            &err_pos, &err_type);
      if (!wml_ok)
      {
        /* truncate at err_pos */
        utf8_str[err_pos] = '\0';
      }
      if (*is_modified || 0 != strcmp(utf8_str, utf8_c_str))
      {
        HDIa_widgetRelease(*string);
        *string = HDIa_widgetStringCreate(MSF_MODID_BRS, utf8_str, MsfUtf8,
                                          strlen(utf8_str) + 1, 0);
        *is_modified = TRUE;
      }
      BRS_MEM_FREE(utf8_c_str);
      BRS_MEM_FREE(utf8_str);
    }
  }
  return wml_ok;
}


/* Array of all ASCII characters, upper case only.
 * Used for transforming a string or character
 * into upper case. */
const unsigned char brs_ascii_uc[256] =
{
  0, 1, 2, 3, 4, 5, 6, 7,
  8, 9, 10, 11, 12, 13, 14, 15,
  16, 17, 18, 19, 20, 21, 22, 23,
  24, 25, 26, 27, 28, 29, 30, 31,
  ' ', '!', '"', '#', '$', '%', '&', '\'',
  '(', ')', '*', '+', ',', '-', '.', '/',
  '0', '1', '2', '3', '4', '5', '6', '7',
  '8', '9', ':', ';', '<', '=', '>', '?',
  '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
  'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
  'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
  'X', 'Y', 'Z', '[', '\\', ']', '^', '_',
  '`', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
  'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
  'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
  'X', 'Y', 'Z', '{', '|', '}', '~', 127,
  128, 129, 130, 131, 132, 133, 134, 135,
  136, 137, 138, 139, 140, 141, 142, 143,
  144, 145, 146, 147, 148, 149, 150, 151,
  152, 153, 154, 155, 156, 157, 158, 159,
  160, 161, 162, 163, 164, 165, 166, 167,
  168, 169, 170, 171, 172, 173, 174, 175,
  176, 177, 178, 179, 180, 181, 182, 183,
  184, 185, 186, 187, 188, 189, 190, 191,
  192, 193, 194, 195, 196, 197, 198, 199,
  200, 201, 202, 203, 204, 205, 206, 207,
  208, 209, 210, 211, 212, 213, 214, 215,
  216, 217, 218, 219, 220, 221, 222, 223,
  224, 225, 226, 227, 228, 229, 230, 231,
  232, 233, 234, 235, 236, 237, 238, 239,
  240, 241, 242, 243, 244, 245, 246, 247,
  248, 249, 250, 251, 252, 253, 254, 255
};


/*
 * Transform string according to CSS property supplied
 */
void
brs_text_transform(char** str, int transform)
{
  char* p = *str;
  if (! *str)
    return;
  switch (transform)
  {
    case BRS_CSS_VALUE_CAPITALIZE:
    {
      int cap_next_char = TRUE;
      while (*p)
      {
        if (ct_iswhitespace(*p))
        {
          cap_next_char = TRUE;
        }
        else if (ct_isascii(*p))
        {
          if (cap_next_char)
          {
            *p = (char)brs_ascii_uc[(unsigned char)(*p)];
            cap_next_char = FALSE;
          }
        }
        p++;
      }
    }
    break;
    case BRS_CSS_VALUE_UPPERCASE:
      while (*p)
      {
        *p = (char)brs_ascii_uc[(unsigned char)(*p)];
        p++;
      }
    break;
    case BRS_CSS_VALUE_LOWERCASE:
      while (*p)
      {
        *p = (char)msf_ascii_lc[(unsigned char)(*p)];
        p++;
      }
    break;
  }
}
