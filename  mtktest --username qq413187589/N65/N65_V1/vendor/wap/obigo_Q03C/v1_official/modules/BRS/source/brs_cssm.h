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









#ifndef _brs_cssm_h
#define _brs_cssm_h

#ifndef  _msf_def_h
#include "msf_def.h"
#endif

#ifndef  _msf_cmmn_h
#include "msf_cmmn.h"
#endif

#ifndef  _msf_prsr_h
#include "msf_prsr.h"
#endif

#ifndef  _brs_css_h
#include "brs_css.h"
#endif

#ifndef  _brs_ddt_h
#include "brs_ddt.h"
#endif

#ifndef  _brs_memp_h
#include "brs_memp.h"
#endif







#define BRS_CSS_SIG_PREFERENCES_CHANGED           BRS_MODULE_CSS + 1


#define BRS_CSS_SIG_START                         BRS_MODULE_CSS + 2
#define BRS_CSS_SIG_DELETE                        BRS_MODULE_CSS + 3
#define BRS_CSS_SIG_PROCESSING_INSTRUCTION        BRS_MODULE_CSS + 4
#define BRS_CSS_SIG_PROCESS_DOCUMENT              BRS_MODULE_CSS + 5
#define BRS_CSS_SIG_COMMIT_CHANGES                BRS_MODULE_CSS + 6


#define BRS_CSS_SIG_CHANGES_COMMITTED             BRS_MODULE_CSS + 7


#define BRS_CSS_SIG_CONTINUE                      BRS_MODULE_CSS + 8















#define BRS_CSS_ITEM_TYPE_IMPORT                  1
#define BRS_CSS_ITEM_TYPE_TEXT                    2
#define BRS_CSS_ITEM_TYPE_RULE                    3

#define BRS_CSS_HTML_ELEMENT_CDATA                998
#define BRS_CSS_HTML_ELEMENT_ANY                  999

#define BRS_CSS_VALUE__DEFAULT                    999

#define BRS_CSS_FLAG_CHILD_SELECTOR               0x01
#define BRS_CSS_FLAG_SIBLING_SELECTOR             0x02

#define BRS_CSS_ATTRIBUTE_SET                     0x10
#define BRS_CSS_ATTRIBUTE_MATCH                   0x20
#define BRS_CSS_ATTRIBUTE_INCLUDES                0x40
#define BRS_CSS_ATTRIBUTE_DASHMATCH               0x80






typedef struct {
  int   instance_id;
  char *href;
  char *charset;
  int   alternate;
} brs_css_processing_instruction_t;

typedef struct brs_css_declaration_st {
  struct brs_css_declaration_st *next;

  int              property;       
  int              important;      

  int              num_values;
  brs_css_value_t  value[1];
} brs_css_declaration_t;

typedef struct {
  int                   element; 
  int                   flags;
  int                   num_attrs;
  msf_prsr_attribute_t *attrs;   
} brs_css_selector_t;

typedef struct {
  brs_css_declaration_t *declarations;
  int                    flags;        
  int                    num_selectors;
  brs_css_selector_t     selector[1];  
} brs_css_rule_t;

typedef struct {
  char *text;
  int   text_length;
  char *base_url;
  int   http_charset;
  int   other_charset;
} brs_css_text_t;

typedef struct {
  char *href;
  int   other_charset;
} brs_css_import_t;

typedef struct brs_css_item_st {
  struct brs_css_item_st  *next;

  int            type;
  union {
    brs_css_import_t import;
    brs_css_text_t   text;
    brs_css_rule_t   rule;
  } _u;
} brs_css_item_t;

typedef struct {
  brs_css_item_t          *first;
  brs_css_item_t          *last;
} brs_css_parse_result_t;


typedef struct brs_css_stack_st brs_css_stack_t;






extern const msf_strtable_info_t brs_css_properties;
extern const msf_strtable_info_t brs_css_values;
extern const msf_strtable_info_t brs_css_colors;
extern const msf_strtable_info_t brs_css_units;
extern const MSF_UINT32          brs_css_color_code[];






void
brs_css_init (void);

void
brs_css_terminate (void);


















void *
brs_css_parse_init (char *style_sheet, int length, char *base_url,
                    int http_charset, int other_charset,
                    brs_mempool_t *mempool);





void
brs_css_parse_terminate (void *css_handle);








int
brs_css_parse_style_sheet (void *css_handle, brs_css_parse_result_t *result);








brs_css_declaration_t *
brs_css_parse_style_attribute (const char *style_attribute, char *base_url,
                               brs_mempool_t *mempool);

brs_css_stack_t *
brs_css_new_stack (void);

void
brs_css_pop_stack (brs_css_stack_t *st);

void
brs_css_push_stack (brs_css_stack_t *st, int elt_type, brs_dt_element_t *elt);

void
brs_css_delete_stack (brs_css_stack_t *st);

brs_css_style_info_t *
brs_css_get_style_info (int ua_id, brs_css_stack_t *st,
                        const char *style_attribute,
                        const char *non_css_style);

void
brs_css_delete_style_info (int ua_id, brs_css_style_info_t *css_info);

int
brs_css_use_special_style_sheet (int ua_id);

void
brs_css_new_document (int ua_id, char *document_url);

void
brs_css_abort (int ua_id);

void
brs_css_stop_loading (int ua_id);

void
brs_css_delete_item (brs_css_item_t *item);

void
brs_css_delete_item_list (brs_css_item_t *item_list);

void
brs_css_delete_declarations (brs_css_declaration_t *declarations);

void
brs_css_delete_value (brs_css_value_t *value);

brs_css_declaration_t *
brs_css_vald_check_values (int property, int important, int num_values,
                           brs_css_value_t values[], brs_mempool_t *mempool);

#endif
