/*
 * Copyright (C) Obigo AB, 2002-2006.
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
 * msf_ptxt.h
 *
 * XML and HTML parser: text parser and main functions
 */

#ifndef _msf_ptxt_h
#define _msf_ptxt_h

#ifndef _msf_prsr_h
#include "msf_prsr.h"
#endif

#ifndef _msf_ptok_h
#include "msf_ptok.h"
#endif

#ifndef _msf_dcvt_h
#include "msf_dcvt.h"
#endif


/**************************************************************
 * Constants                                                  *
 **************************************************************/

/* Internal status codes */
#define MSF_PRSR_STATUS_OK            0    /* All went well.                            */
#define MSF_PRSR_STATUS_MORE          13   /* Need more input.                          */
#define MSF_PRSR_STATUS_RETURN        14   /* Changed processor, call again.            */
#define MSF_PRSR_STATUS_PAUSE         15   /* Time slot spent, but there is more to do. */
#define MSF_PRSR_STATUS_NEW_CHARSET   16   /* Change character set to use.              */
#define MSF_PRSR_STATUS_START_TAG     17   /* Start tag                                 */
#define MSF_PRSR_STATUS_EMPTY_ELEMENT 18   /* Empty element                             */
#define MSF_PRSR_STATUS_END_TAG       19   /* End tag                                   */

#define MSF_PRSR_STATUS_META_SCAN     21   /* Start scanning for meta charset           */
#define MSF_PRSR_STATUS_CDATA         22   /* CDATA                                     */

/* Internal application return code */
#define MSF_PRSR_APPLICATION_WARNING      3   /* Recoverable error if HTML, else failure */
#define MSF_PRSR_APPLICATION_HTML         4   /* Returned by the HTML init funct for HTML docs */
#define MSF_PRSR_APPLICATION_LOOSE_XHTML  5   /* Returned for XHTML docs when LOOSE_XHTML flag */
#define MSF_PRSR_APPLICATION_OK_BODY      6   /* This is the beginning of the document body */
#define MSF_PRSR_APPLICATION_WARNING_BODY 7   /* Warning; beginning of the document body */
#define MSF_PRSR_APPLICATION_WML          8


/* Type of opaque data */
#define MSF_PRSR_SECTION_CDATA           0    /* Data is CDATA */
#define MSF_PRSR_SECTION_COMMENT         1    /* Data is a comment */
#define MSF_PRSR_SECTION_PLAINTEXT       2    /* Data is plaintext content */
#define MSF_PRSR_SECTION_STYLE           3    /* Data is style content */
#define MSF_PRSR_SECTION_SCRIPT          4    /* Data is script content */
#define MSF_PRSR_SECTION_TEXTAREA        5    /* Data is textarea content */


/* Character constants */
#define MSF_PRSR_CHAR_CR          0x0D /* caridge return */
#define MSF_PRSR_CHAR_LF          0x0A /* line feed */


/* Internal flags used for indicate text handling mode */
#define MSF_PRSR_FLAG_FLUSH           0x01
#define MSF_PRSR_FLAG_NORMALIZE       0x02
#define MSF_PRSR_FLAG_ATTRIBUTE       0x04
#define MSF_PRSR_FLAG_NO_TEXT         0x08

#define MSF_PRSR_FLAG_CANCEL_SPACE    0x10
#define MSF_PRSR_FLAG_OPAQUE          0x20
#define MSF_PRSR_FLAG_WBXML_WML       0x40
#define MSF_PRSR_FLAG_WBXML_VARIABLE  0x80
#define MSF_PRSR_FLAG_TEXTAREA        0x80 /* Reuse flag. WBXML_VARIABLE not used internally */

/* Internal constants for text handling modes */
#define MSF_PRSR_STACKMODE_NONE            0
#define MSF_PRSR_STACKMODE_NORMALIZE       (MSF_PRSR_FLAG_NORMALIZE | MSF_PRSR_FLAG_FLUSH)
#define MSF_PRSR_STACKMODE_PRESERVE        (MSF_PRSR_FLAG_FLUSH)
#define MSF_PRSR_STACKMODE_ATTRIBUTE       (MSF_PRSR_FLAG_NORMALIZE | MSF_PRSR_FLAG_ATTRIBUTE)
#define MSF_PRSR_STACKMODE_ATTRIBUTE_CDATA (MSF_PRSR_FLAG_ATTRIBUTE)
#define MSF_PRSR_STACKMODE_WBXML_WML       (MSF_PRSR_FLAG_WBXML_WML)
#define MSF_PRSR_STACKMODE_NO_TEXT         (MSF_PRSR_FLAG_NO_TEXT)
#define MSF_PRSR_STACKMODE_OPAQUE          (MSF_PRSR_FLAG_FLUSH | MSF_PRSR_FLAG_OPAQUE)
#define MSF_PRSR_STACKMODE_TEXTAREA        (MSF_PRSR_FLAG_FLUSH | MSF_PRSR_FLAG_TEXTAREA)                         

/* Internal text handling flag */           
#define MSF_PRSR_CDATA            0x40 /* Data is CDATA */

/* Text handling flags specific for HTML */
#define MSF_PRSR_EMPTY            0x01 /* Empty element */
#define MSF_PRSR_MISMATCH         0x02 /* Elements allowed to be mismatched */
#define MSF_PRSR_CLOSE            0x04 /* Element may cause closure of another */
#define MSF_PRSR_HEAD             0x08 /* Element may be in the head section */
#define MSF_PRSR_BLOCK            0x10 /* This is a block element */
#define MSF_PRSR_STOP             0x20 /* This element takes block as data */
#define MSF_PRSR_HEADING          0x40 /* This element is a heading element */


/* Parser states */

/*
 *              -----------------------------------------
 *              |                         |             |             
 *              |                         v             v            
 *  init ---> start ---> xml_decl ---> doctype --->  content
 *                           |            |           ^ ^             
 *                           |            |           | |             
 *                           |            ------------- |
 *                           |                          |               
 *                           ----------------------------
 */

#define MSF_PRSR_STATE_INIT         0    /* At start                               */
#define MSF_PRSR_STATE_START        1    /* Passed start                           */
#define MSF_PRSR_STATE_XML_DECL     2    /* Found and used XML PI                  */
#define MSF_PRSR_STATE_DOCTYPE      3    /* Parsed the DOCTYPE statement           */
#define MSF_PRSR_STATE_CONTENT      4    /* Instance start found; parsing content  */

#define MSF_PRSR_STATE_DECODER      10   /* Using the WBXML decoder                */

/* Parser->html modes */
#define MSF_PRSR_XML_MODE           0
#define MSF_PRSR_HTML_MODE          1
#define MSF_PRSR_EXTENDED_WML_MODE  2
/**************************************************************
 * Type definitions                                           *
 **************************************************************/

typedef char* (*strchr_t) (const char* s, int c);

typedef int (*msf_prsr_processor_t) (msf_prsr_parser_t*  parser,
                                     const char*         start,
                                     const char*         end,
                                     const char*        *nextPtr,
                                     int                 limit);

/* Text buffer handling */
typedef struct msf_prsr_stack_st {
  char* sessionStart;     /* Start of current session */
  char* ptr;              /* Position of next character to write */
  char* start;            /* Start of buffer */
  char* end;              /* End of buffer */
  int   mode;             /* Text handling mode: STACKMODE_* */
  int   overflow;         /* True if there is an unwitten white-space */
  int   cancelSpace;      /* Ignore leading spaces */
  int   cancelSpace_bu;   /* Backup of cancelSpace. Used when STACKMODE_ATTRIBUTE. */
  int   downcase;         /* Downcase all character data written by prsr_writeData */
  int   error;            /* Error code set by stack functions */

} msf_prsr_stack_t;


struct msf_prsr_parser_lite_st {
  msf_prsr_parserData_t     p;
  msf_tok_data_t            data;           /* Tokenizer data */
  msf_prsr_stack_t          stack;          /* Work space */
  msf_prsr_processor_t      processor;      /* Parser or decoder used at the moment */
  msf_prsr_processor_t      returnProc;     /* Parser to return to after a comment is parsed */
  msf_prsr_piHandler_t*     piHandler;      /* Called for all processing instructions */

  msf_prsr_init_t*          initFunct;      /* Initializer */

  char*                     buffer;         /* Input buffer */
  char*                     bufferStart;
  char*                     bufferEnd;
  long                      bufferSize;

  int                       handle;         /* Handle to the input pipe or file */
  int                       inputType;      /* Pipe, file or buffer */

  msf_charset_convert_t*    cvtFunct;       /* Charset convertion function */
  char*                     cvtBuf;         /* Raw data buffer */
  char*                     cvtBufStart;
  long                      cvtBufLen;      /* Length of data */
  long                      cvtbufSize;     /* Size of buffer */

  int                       tagLevel;       /* Current element nesting depth */
  int                       state;          /* Prologue status */
  int                       charset;        /* Character set */
  int                       defaultCharset; /* Default character set */
  int                       numElems;       /* Current max nesting depth (HTML only) */
  int                       stackmode;      /* Stackmode telling how to handle PCDATA */
  int                       type;           /* Tell if data is a comment, CDATA or plaintext */
  int                       noMoreData;     /* TRUE if no more data is to be read */
  int                       mode;           /* Parse HTML instead of XML */
  int                       loose_xhtml;    /* TRUE when this is an XHTML doc parsed as HTML */
  int                       html_based;     /* XHTML or HTML */
  int                       meta_scan;      /* Scan the head section for meta charset */
  long                      meta_scan_offset;/*Where in buffer to restart during meta scan */
  int                       initalSize;     /* Initial buffer size */
  MSF_UINT8                 modId;          /* Id of the calling module */

  /* BRS specific */
  const unsigned char*      htmlTable;      /* HTML specific element table */
  msf_prsr_changeCharset_t* changeCharset;  /* Function to be called after meta charset */
};

/* Extended version of prsr_Parser_lite_st. Used together with the WBXML decoder. */
struct msf_prsr_parser_st {
  msf_prsr_parserData_t     p;
  msf_tok_data_t            data;           /* Tokenizer data */
  msf_prsr_stack_t          stack;          /* Work space */
  msf_prsr_processor_t      processor;      /* Parser or decoder used at the moment */
  msf_prsr_processor_t      returnProc;     /* Parser to return to after a comment is parsed */
  msf_prsr_piHandler_t*     piHandler;      /* Called for all processing instructions */

  msf_prsr_init_t*          initFunct;      /* Initializer */

  char*                     buffer;         /* Input buffer */
  char*                     bufferStart;
  char*                     bufferEnd;
  long                      bufferSize;

  int                       handle;         /* Handle to the input pipe or file */
  int                       inputType;      /* Pipe, file or buffer */

  msf_charset_convert_t*    cvtFunct;       /* Charset convertion function */
  char*                     cvtBuf;         /* Raw data buffer */
  char*                     cvtBufStart;
  long                      cvtBufLen;      /* Length of data */
  long                      cvtbufSize;     /* Size of buffer */

  int                       tagLevel;       /* Current element nesting depth */
  int                       state;          /* Prologue status */
  int                       charset;        /* Character set */
  int                       defaultCharset; /* Default character set */
  int                       numElems;       /* Current max nesting depth (HTML only) */
  int                       stackmode;      /* Stackmode telling how to handle PCDATA */
  int                       type;           /* Tell if data is a comment, CDATA or plaintext */
  int                       noMoreData;     /* TRUE if no more data is to be read */
  int                       mode;           /* Parse HTML instead of XML */
  int                       loose_xhtml;    /* TRUE when this is an XHTML doc parsed as HTML */
  int                       html_based;     /* XHTML or HTML */
  int                       meta_scan;      /* Scan the head section for meta charset */
  long                      meta_scan_offset;/*Where in buffer to restart during meta scan */
  int                       initalSize;     /* Initial buffer size */
  MSF_UINT8                 modId;          /* Id of the calling module */

  /* BRS specific */
  const unsigned char*      htmlTable;      /* HTML specific element table */
  msf_prsr_changeCharset_t* changeCharset;  /* Function to be called after meta charset */

  /* WBXML decoder specific */
  msf_prsr_decoderData_t    d;
  char*                     stringTable;    /* String table. Size limited to MAX_STRING_TABLE */
  int                       stringTableLen;
  int                       attrVal;
    
  int                       opaqueLen;      /* Nbr of bytes left in a half-read opaque block */ 
  msf_charset_convert_t*    codecvtFunct;   /* Convert function, document encoding to UTF-8 */
  MSF_UINT16                elemPage;       /* Element codepage */
  MSF_UINT16                attrPage;       /* Attribute codepage */  
  strchr_t                  strchr_funct;   /* strchr for the current encoding */
};


/**************************************************************
 * Functions                                                  *
 **************************************************************/

int
msf_prsr_expandStack (msf_prsr_parser_t* parser, int len);

int
msf_prsr_flushText (msf_prsr_parser_t* parser, int final);

int
msf_prsr_writeString (msf_prsr_parser_t* parser, const char* s, int len);

void
msf_prsr_writeData (msf_prsr_parser_t* parser, const char* s, int len, int flush);

msf_prsr_attr_value_t
msf_prsr_normalizeAttribute (msf_prsr_parser_t* parser,
                             int                type,
                             const char*        name, 
                             int                nameLen,
                             const char*        data, 
                             int                dataLen, 
                             int               *flag, 
                             int               *error);

int
msf_prsr_guess_encoding (const char* s, int *length, int type);


#endif
