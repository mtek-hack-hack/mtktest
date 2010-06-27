/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */






#ifndef _prs_type_h
#define _prs_type_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _msf_mem_h
#include "msf_mem.h"
#endif

#ifndef _prs_cfg_h
#include "prs_cfg.h"
#endif

#ifndef _prs_wap_h
#include "prs_wap.h"
#endif






#define PRS_DOCTYPE_UNKNOWN               0
#define PRS_DOCTYPE_WAP                   1
#define PRS_DOCTYPE_OTA_BROWSER_SETTINGS  2
#define PRS_DOCTYPE_OTA_BROWSER_BOOKMARKS 3
#define PRS_DOCTYPE_OTA_SYNCML            4



#define PRS_STATUS_OK           0 
#define PRS_ERROR_ABORT         1 
#define PRS_STATUS_FIELD_SKIP   9 
#define PRS_STATUS_NODE_REMOVE  10


#define PRS_ACTION_NONE        0 
#define PRS_ACTION_EXTERNAL_1  1 
#define PRS_ACTION_EXTERNAL_2  2 
#define PRS_ACTION_IGNORE      3 



#define PRS_OUTPUT_PATH       MSF_REG_SET_TYPE_PATH
#define PRS_OUTPUT_INT        MSF_REG_SET_TYPE_INT
#define PRS_OUTPUT_STR        MSF_REG_SET_TYPE_STR



#define PRS_OTA_BR              0
#define PRS_OTA_SYN             1
#define PRS_WAP                 2
#define PRS_IOTA                3



#define PRS_END_OF_TABLE        0x7FFF
#define PRS_FIELD_HIGH_START    31






#define PRS_ALLOC(x)      MSF_MEM_ALLOC (MSF_MODID_PRS, x)
#define PRS_ALLOCTYPE(x)  MSF_MEM_ALLOCTYPE (MSF_MODID_PRS, x)
#define PRS_FREE(x)       MSF_MEM_FREE (MSF_MODID_PRS, x)


#define PRS_STRING(n)  (n == -1 ? 0 : 1L << n)
#define PRS_INTEGER(n) 0
#define PRS_MULTI(n)   PRS_STRING(n)






typedef struct prs_field_st         prs_field_t;
typedef struct prs_node_st          prs_node_t;
typedef struct prs_node_list_st     prs_node_list_t;
typedef struct prs_output_obj_st    prs_output_obj_t;      
typedef struct prs_job_st           prs_job_t;



typedef int prs_process_node_t (prs_node_t* node);      
typedef int prs_process_list_t (prs_node_list_t* list); 
typedef int prs_validate_node_t (prs_node_t* node);     
typedef int prs_fill_in_node_t (prs_node_t* node);      



struct prs_node_list_st {
  prs_node_t*             firstNode;        
  prs_node_t*             lastNode;         
  prs_node_t*             currentNode;      
  prs_node_t*             userDataNode;     
  prs_process_list_t*     processListPre;   
  prs_process_node_t*     processNode;      
  prs_process_list_t*     processListPost;  
  MSF_INT8*               elementAction;    
  int                     doctype;          
  int                     firstTime;        
  prs_output_obj_t*       outputVec[PRS_MAX_OUTPUT_OBJECTS]; 
#ifdef __MMI_DUAL_SIM__
  int                     network_account_id;
#endif
};



struct prs_field_st {
  MSF_INT8     id;            
  MSF_INT8     path;          
  MSF_INT8     destList;       
  prs_field_t *next;          
  union {
    char*        s;           
    int          i;           
  } data;                     
};



struct prs_node_st {
  struct prs_node_st* next;         
  int                 element;      
  int                 size;         
  MSF_UINT32          usedLow;      
  MSF_UINT32          usedHigh;     
  MSF_UINT32          isStringLow;  
  MSF_UINT32          isStringHigh; 
  MSF_UINT32          isMultiLow;   
  MSF_UINT32          isMultiHigh;  
  prs_field_t         fieldVec[1];  
};



typedef struct prs_field_def_st {
  int      field;       
  MSF_INT8 id;         
  MSF_INT8 path;      
  MSF_INT8 destList;  
} prs_field_def_t;



typedef MSF_INT8 prs_dest_list_t;   
























int
prs_set_field (prs_node_t* node, int field, int isString, int val_int, char* val_str);








int
prs_is_used (prs_node_t* node, int field);







void
prs_set_used (prs_node_t* node, int field);






void
prs_clear_used (prs_node_t* node, int field);








int
prs_is_string (prs_node_t* node, int field);









int
prs_is_multi (prs_node_t* node, int field);









prs_output_obj_t*
prs_output_init (int dst);








int
prs_output_start (prs_output_obj_t* obj);









int
prs_output_add (prs_output_obj_t* obj, int type, const char* name, 
                MSF_UINT32 val_int, const char* val_str);








void
prs_output_send (prs_output_obj_t *obj);


#endif


