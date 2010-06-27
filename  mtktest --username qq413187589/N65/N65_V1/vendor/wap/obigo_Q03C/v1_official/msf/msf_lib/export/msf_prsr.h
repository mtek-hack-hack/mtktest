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
 * msf_prsr.h
 *
 * XML and HTML parser: parser interface
 */

#ifndef _msf_prsr_h
#define _msf_prsr_h

#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif

#ifndef _msf_cmmn_h
#include "msf_cmmn.h"
#endif

#ifndef _msf_chrs_h
#include "msf_chrs.h"
#endif


/*
 * creater              parser              validator
 *    |                    |                    |
 *    | create             |                    |
 *    |------------------->|                    |
 *    |                    |                    |
 *    | parse              |                    |
 *    | (one or more time) |                    |
 *    |------------------->|                    |
 *    |                    | pi (if any)        |
 *    |                    |------------------->|
 *    |                    |                    |
 *    |                    | extract_attributes |
 *    |                    |<-------------------|
 *    |                    |                    |
 *    |                    | init               |
 *    |                    |------------------->|
 *
 *
 *    | parse (repeatedly) |                    |
 *    |------------------->|                    |
 *    |                    | startElement       |
 *    |                    | endElement         |
 *    |                    | characterData      |
 *    |                    | specificFunct      |
 *    |                    |------------------->|
 *    |                    |------------------->|
 *    |                    |                    |
 *    |                    | free_attributes    |
 *    |                    | read_num           |
 *    |                    |<-------------------|
 *    |                    |<-------------------|
 *    |                    |                    |
 *
 *
 *    | delete             |                    |
 *    |------------------->|                    |
 *    |                    |                    |
 */


/**************************************************************
 * Constants                                                  *
 **************************************************************/

/* 
 * Standard XML character entity references:
 * amp (&), apos ('), gt (>), lt (<), quot (").
 */ 
extern const msf_strtable_info_t msf_prsr_XmlEntities;



/* 
 * Parser return status codes.
 */

/* The document uses an unsupported character set or encoding. */
#define MSF_PRSR_ERROR_UNKNOWN_CHARSET       1

/* The content contains a syntax error or violates another rule
 * in a basic content specification, such as WBXML or XML. */
#define MSF_PRSR_ERROR_SYNTAX                2

/* A document type was could not be determined or the specified
 * type is not supported. */
#define MSF_PRSR_ERROR_UNKNOWN_DOCTYPE       3

/* The document uses an unsupported version of WBXML. */
#define MSF_PRSR_ERROR_UNSUPPORTED_WBXML     4

/* Unexpected end of document. */
#define MSF_PRSR_ERROR_UNEXPECTED_END_OF_DOC 5

/* The application has aborted the parsing. */
#define MSF_PRSR_ERROR_APPLICATION           6

/* The parser or one of its resources is not initialized or
 * not available. */
#define MSF_PRSR_ERROR_ABORTED               7

/* Parsing aborted. Out of memory. */
#define MSF_PRSR_ERROR_OUT_OF_MEMORY         8

/* Document done. */
#define MSF_PRSR_STATUS_PARSING_COMPLETED    9

/* Scheduled pause; more to do. Call again. */
#define MSF_PRSR_STATUS_MORE_TO_DO           10

/* Unscheduled pause; waiting for more input.
 *
 * If reading from a pipe, then MSF_PIPE_POLL has been called
 * and the user will receive a MSF_PIPE_SIG_NOTIFY signal when
 * it is time to call again.
 *
 * If reading from a file, then MSF_FILE_SELECT has been called
 * and the user wíll receive a MSF_FILE_SIG_NOTIFY signal when
 * it is time to call again.
 */
#define MSF_PRSR_STATUS_WAIT                 11


/* 
 * Code given to all unknown elements when calling the start
 * element handler.
 */
#define MSF_PRSR_UNKNOWN_ELEMENT           -1


/* Tells the type of an attribute value */
#define MSF_PRSR_ATTRVAL_INT                1
#define MSF_PRSR_ATTRVAL_STR                0


/* Application return codes */
#define MSF_PRSR_APPLICATION_OK             0 /* All went well                    */
#define MSF_PRSR_APPLICATION_ERROR          1 /* Error; stop parsing document     */
#define MSF_PRSR_APPLICATION_OUT_OF_MEMORY  2 /* Out of memory; terminate parsing */


/* Text handling flags */           
#define MSF_PRSR_TEXT                       0x01 /* Data is PCDATA */
#define MSF_PRSR_CANCELSPACE_S              0x02 /* Cancel space after start tag */
#define MSF_PRSR_CANCELSPACE_E              0x04 /* Cancel space after end tag */
#define MSF_PRSR_PRE                        0x08 /* Element has xml:space = preserve property */
#define MSF_PRSR_VISUAL                     0x10 /* Visual element. Stops space cancelling. */
#define MSF_PRSR_OPAQUE                     0x20 /* All char data is preserved including CR LF */

#define MSF_PRSR_CANCELSPACE                0x06 /* Cancel space after start and end tag */


/* Constants used in WBXML decoder tables */
#define MSF_PRSR_NOT_USED                   0xFF
#define MSF_PRSR_DEC_DATA                   0x80


/* Type of input */
#define MSF_PRSR_PIPE                       0
#define MSF_PRSR_FILE                       1
#define MSF_PRSR_BUFFER                     2



/* Attribute classes */

/* 
 * An attribute with a value that does not fit the specified type
 * is ignored.
 *
 * Bit 0 - 5  is the type field.
 * Bit 6 - 14 is a bitmap.
 * Bit 15     is the no-case flag.
 *
 * Type values 0 - 9 are reserved for internal types, such as
 * CDATA. Type values 10 - 63 are for the corresponding
 * enumerate attribute values. The bitmap contains one bit for
 * each of the remaining enumerated values.
 *
 * MSF_PRSR_TYPE_CDATA is pure text. All white-space characters
 * are replaced with space charaters.
 *
 *     Example: CDATA
 *     --------
 *     "  text  TEXT  " -->  "  text  TEXT  "
 *
 *
 * MSF_PRSR_TYPE_ID is normalised text. ID is treated identically
 * to ENTITY, ENTITIES, IDREF, IDREFS, NMTOKEN, and NMTOKENS.
 * Leading and training white-space are removed. Multiple blanks
 * between words are compacted into a single space.
 *
 *     Example: IDREFS
 *     --------
 *     "  text  TEXT  " -->  "text TEXT"
 *
 *
 * MSF_PRSR_TYPE_PRCNT and MSF_PRSR_TYPE_NUM both takes a positive
 * integer, but MSF_PRSR_TYPE_PRCNT also accepts a positiv
 * percentage. A percentage is converted into a negative integer.
 *
 *     Example: NUM
 *     --------
 *     10  --> 10
 *     10% --> ignored
 * 
 *     Example: PRCNT
 *     --------
 *     10  --> 10
 *     10% --> -10
 * 
 *
 * MSF_PRSR_TYPE_FLAG takes a boolean attribute, i.e. an attribute
 * that takes its own name as value.
 *
 *     Example: FLAG
 *     --------
 *     checked = "checked" --> TRUE
 *     checked = "ChEcKeD" --> ignored
 *     checked = "true"    --> ignored
 *
 *
 * The emnumerated type uses the tokens defined in the attribute
 * value table. If attribute is of en enumerated type, then its
 * value is looked up in the attribute value table and the result
 * is then matched with the type. The check fails if the value
 * cannot be found or when found, it cannot not belong to the
 * group given by the type.
 *
 * Enum 0 - 8 can be used in any combination and paired with at
 * most one single enum value 10 - 63. Enum 10 - 63 can not be
 * combined.
 *
 * The lookup is case sensitive, if MSF_PRSR_TYPE_NO_CASE is not
 * set. See below.
 *
 *     Example: ENUM
 *     --------
 *     Four attributes have enumerated values:
 *
 *     ordered = (true, false)
 *     halign  = (left, center, right)
 *     valign  = (top, center, bottom)
 *     focus   = (center, corner, margin)
 *
 *     Attribute value table:
 *
 *     const strtable_entry_t Attrvals_stringTable[] = {
 *       {"true",   CONST_TRUE},     // ENUM_A
 *       {"false",  CONST_FALSE},    // ENUM_A
 *       {"left",   CONST_LEFT},     // ENUM_B
 *       {"right",  CONST_RIGHT},    // ENUM_B
 *       {"top",    CONST_TOP},      // ENUM_3F
 *       {"bottom", CONST_BOTTOM},   // ENUM_3F
 *       {"center", CONST_CENTER},   // ENUM_0
 *       {"corner", CONST_CORNER},   // ENUM_1
 *       {"margin", CONST_MARGIN}    // ENUM_2
 *     }
 *
 *     Attribute value normalization table:
 *
 *     const UINT16 html_AttributeTypes[] = {
 *       ENUM_A,                     // ordered
 *       ENUM_B  | ENUM_0,           // halign
 *       ENUM_3F | ENUM_0,           // valign
 *       ENUM_0  | ENUM_1 | ENUM_2   // focus
 *     }
 *   
 *     The constants CONST_* are defined below in such way form
 *     these groups:
 *
 *     ENUM_0  = center
 *     ENUM_1  = corner
 *     ENUM_2  = margin
 *     ENUM_A  = true, false
 *     ENUM_B  = left, right
 *     ENUM_3F = top, bottom
 *
 *     If focus = "center", the focus is looked up and CONST_FOCUS
 *     is returned. The constant is then checked if it belongs to
 *     group 0, 1 or 2.
 *
 * The corresponding attribute value constants consist of two
 * fields: the group and an index within the group.
 *
 * Bit 0 - 7  is the index.
 * Bit 8 - 14 is the group.
 *
 * The index can be chose at will and the group corresponds to
 * an enum value. The value do not have to be unique.
 *
 *     Example: ENUM continued
 *     --------
 *     #define CONST_TRUE   0x0A00   // group: A,  index: 0
 *     #define CONST_FALSE  0x0A01   // group: A,  index: 1
 *     #define CONST_LEFT   0x0B01   // group: B,  index: 1
 *     #define CONST_RIGHT  0x0B02   // group: B,  index: 2
 *     #define CONST_TOP    0x3F01   // group: 3F, index: 1
 *     #define CONST_BOTTOM 0x3F02   // group: 3F, index: 2
 *     #define CONST_CENTER 0x0000   // group: 0,  index: 0
 *     #define CONST_CORNER 0x0101   // group: 1,  index: 1
 *     #define CONST_MARGIN 0x0202   // group: 2,  index: 2
 *
 *
 * MSF_PRSR_TYPE_NO_CASE can be combined with any other type and
 * the in-data is down-cased.
 *
 *     Example: IDREFS | NO_CASE
 *     --------
 *     "  text  TEXT  "    -->  "text text"
 *
 *     Example: CDATA | NO_CASE
 *     --------
 *     "  text  TEXT  "    -->  "  text  text  "
 *
 *     Example: FLAG  | NO_CASE
 *     --------
 *     checked = "ChEcKeD" --> TRUE
 *
 *
 *     Example: ENUM  | NO_CASE
 *     --------
 *     focus = "CENTER"    --> CONST_CENTER
 */

#define MSF_PRSR_TYPE_CDATA     0
#define MSF_PRSR_TYPE_PRCNT     1
#define MSF_PRSR_TYPE_NUM       2
#define MSF_PRSR_TYPE_FLAG      3
#define MSF_PRSR_TYPE_ID        4
#define MSF_PRSR_TYPE_NDATA     5
#define MSF_PRSR_TYPE_ENTITY    MSF_PRSR_TYPE_ID
#define MSF_PRSR_TYPE_ENTITIES  MSF_PRSR_TYPE_ID
#define MSF_PRSR_TYPE_IDREF     MSF_PRSR_TYPE_ID
#define MSF_PRSR_TYPE_IDREFS    MSF_PRSR_TYPE_ID
#define MSF_PRSR_TYPE_NMTOKEN   MSF_PRSR_TYPE_ID
#define MSF_PRSR_TYPE_NMTOKENS  MSF_PRSR_TYPE_ID
#define MSF_PRSR_TYPE_NOTATION  MSF_PRSR_TYPE_ID

#define MSF_PRSR_TYPE_NO_CASE   0x8000

#define MSF_PRSR_TYPE_ENUM_0    0x0040
#define MSF_PRSR_TYPE_ENUM_1    0x0080
#define MSF_PRSR_TYPE_ENUM_2    0x0100
#define MSF_PRSR_TYPE_ENUM_3    0x0200
#define MSF_PRSR_TYPE_ENUM_4    0x0400
#define MSF_PRSR_TYPE_ENUM_5    0x0800
#define MSF_PRSR_TYPE_ENUM_6    0x1000
#define MSF_PRSR_TYPE_ENUM_7    0x2000
#define MSF_PRSR_TYPE_ENUM_8    0x4000

#define MSF_PRSR_TYPE_ENUM_A    0x000A
#define MSF_PRSR_TYPE_ENUM_B    0x000B
#define MSF_PRSR_TYPE_ENUM_C    0x000C
#define MSF_PRSR_TYPE_ENUM_D    0x000D
#define MSF_PRSR_TYPE_ENUM_E    0x000E
#define MSF_PRSR_TYPE_ENUM_F    0x000F
#define MSF_PRSR_TYPE_ENUM_10   0x0010
#define MSF_PRSR_TYPE_ENUM_11   0x0011
#define MSF_PRSR_TYPE_ENUM_12   0x0012
#define MSF_PRSR_TYPE_ENUM_13   0x0013
#define MSF_PRSR_TYPE_ENUM_14   0x0014
#define MSF_PRSR_TYPE_ENUM_15   0x0015
#define MSF_PRSR_TYPE_ENUM_16   0x0016
#define MSF_PRSR_TYPE_ENUM_17   0x0017
#define MSF_PRSR_TYPE_ENUM_18   0x0018
#define MSF_PRSR_TYPE_ENUM_19   0x0019
#define MSF_PRSR_TYPE_ENUM_1A   0x001A
#define MSF_PRSR_TYPE_ENUM_1B   0x001B
#define MSF_PRSR_TYPE_ENUM_1C   0x001C
#define MSF_PRSR_TYPE_ENUM_1D   0x001D
#define MSF_PRSR_TYPE_ENUM_1E   0x001E
#define MSF_PRSR_TYPE_ENUM_1F   0x001F
#define MSF_PRSR_TYPE_ENUM_20   0x8020
#define MSF_PRSR_TYPE_ENUM_21   0x0021
#define MSF_PRSR_TYPE_ENUM_22   0x0022
#define MSF_PRSR_TYPE_ENUM_23   0x0023
#define MSF_PRSR_TYPE_ENUM_24   0x0024
#define MSF_PRSR_TYPE_ENUM_25   0x0025
#define MSF_PRSR_TYPE_ENUM_26   0x0026
#define MSF_PRSR_TYPE_ENUM_27   0x0027
#define MSF_PRSR_TYPE_ENUM_28   0x0028
#define MSF_PRSR_TYPE_ENUM_29   0x0029
#define MSF_PRSR_TYPE_ENUM_2A   0x002A
#define MSF_PRSR_TYPE_ENUM_2B   0x002B
#define MSF_PRSR_TYPE_ENUM_2C   0x002C
#define MSF_PRSR_TYPE_ENUM_2D   0x002D
#define MSF_PRSR_TYPE_ENUM_2E   0x002E
#define MSF_PRSR_TYPE_ENUM_2F   0x002F
#define MSF_PRSR_TYPE_ENUM_30   0x0030
#define MSF_PRSR_TYPE_ENUM_31   0x0031
#define MSF_PRSR_TYPE_ENUM_32   0x0032
#define MSF_PRSR_TYPE_ENUM_33   0x0033
#define MSF_PRSR_TYPE_ENUM_34   0x0034
#define MSF_PRSR_TYPE_ENUM_35   0x0035
#define MSF_PRSR_TYPE_ENUM_36   0x0036
#define MSF_PRSR_TYPE_ENUM_37   0x0037
#define MSF_PRSR_TYPE_ENUM_38   0x0038
#define MSF_PRSR_TYPE_ENUM_39   0x0039
#define MSF_PRSR_TYPE_ENUM_3A   0x003A
#define MSF_PRSR_TYPE_ENUM_3B   0x003B
#define MSF_PRSR_TYPE_ENUM_3C   0x003C
#define MSF_PRSR_TYPE_ENUM_3D   0x003D
#define MSF_PRSR_TYPE_ENUM_3E   0x003E
#define MSF_PRSR_TYPE_ENUM_3F   0x003F



/**************************************************************
 * Type definitions                                           *
 **************************************************************/

/*
 * Attributes are given as an array of msf_prsr_attribute_t.
 *
 * type - attribute type as defined in table.
 * flag - MSF_PRSR_ATTRVAL_INT or MSF_PRSR_ATTRVAL_STR.
 * u    - string or int used depending on lag'.
 */
typedef union
{
  char*  s;
  int    i;
} msf_prsr_attr_value_t;

typedef struct msf_prsr_attribute_st
{
  short                  type;
  short                  flag;
  msf_prsr_attr_value_t  u;

} msf_prsr_attribute_t;


/*
 * Type defs of the parser struct and its configuration structs.
 */
typedef struct msf_prsr_parser_st       msf_prsr_parser_t;
typedef struct msf_prsr_parserData_st   msf_prsr_parserData_t;
typedef struct msf_prsr_decoderData_st  msf_prsr_decoderData_t;


/*
 * Type of initiation function. Called when the document prologue
 * is done.
 *
 * Return an application return code (MSF_PRSR_APPLICATION_*).
 */
typedef int
msf_prsr_init_t (msf_prsr_parserData_t*  p,
                 msf_prsr_decoderData_t* d,
                 const char*             doctype_str,
                 int                     len,
                 int                     wbxml_code,
                 int                     charset);


/*
 * Each start tag will cause a call to the start element handler
 * and each end tag a call to the end element handler. An empty
 * tag is both a start and an end element. 
 *
 * E,g. 
 * <a>  -> start a
 * </a> -> end
 * <a/> -> start a + end
 *
 * All calls are made in the same order as they are found in the
 * document.
 *
 * Text is sent to the character data handler. Large text can be
 * sent through several calls. A text can be divided between any
 * two characters, but not within a multi-byte character.
 * 
 * E.g.
 * "A very very long text" -> "A very ve" + "ry long tex" + "t"
 *
 * Unknown elements are ignored in textual documents, but for a
 * WBXML encoded document there will be a start/end pair of calls.
 * The type attribute for the start call is then 
 * MSF_PRSR_UNKNOWN_ELEMENT.
 */
typedef int
msf_prsr_startElementHandler_t (void*                 userData,
                                int                   type,
                                msf_prsr_attribute_t* attrs, /* Not used if 'numAttrs' == 0 */
                                int                   numAttrs);

typedef int
msf_prsr_endElementHandler_t (void* userData);

typedef int
msf_prsr_characterDataHandler_t (void*       userData,
                                 const char* s,
                                 int         len,
                                 int         mode);


/*
 * Type of function called when a processing instruction is found.
 *
 * <?some-pi data?>
 *   |      |    |
 *   target data end
 */
typedef int
msf_prsr_piHandler_t (void*              userData,
                      msf_prsr_parser_t* parser,
                      const char*        target, /* NOT null-terminated */
                      const char*        data,   /* NOT null-terminated */
                      const char*        end);

/*
 * Type of function handling WBXML opaque and extention tokens.
 */
typedef int
msf_prsr_specificFunct_t (msf_prsr_parser_t*  parser,
                          const char*        *s,
                          const char*         end,
                          int                 i, /* Opaque size or extention token */
                          int                 type);


/*
 * Type of the function called after a meta charset in HTML.
 */
typedef void msf_prsr_changeCharset_t (void* userData, msf_charset_convert_t* cvtFunct);


/* 
 * Parser document specific configuration. Structure is
 * initiated by a msf_prsr_init_t function.
 */
struct msf_prsr_parserData_st {
  void*                       userData;       /* Pointer to caller's private data. 'userData'
                                               * must point to an integer. This can be done by,
                                               * for example allocating a struct with the first
                                               * field beeing an int. This number is used as 
                                               * a key unique for each user agent. */

  msf_prsr_startElementHandler_t*  startHandler; /* Called for start and empty tags */
  msf_prsr_endElementHandler_t*    endHandler;   /* Called for end and empty tags */
  msf_prsr_characterDataHandler_t* charHandler;  /* Called for all non-element and non-pi data */

  const msf_strtable_info_t*  elements;       /* Known elements */
  const msf_strtable_info_t*  attributes;     /* Known attributes */
  const msf_strtable_info_t*  attrvals;       /* Known attribute values */
  const msf_strtable_info_t*  entities;       /* Known entities (&amp; &apos;...) */
  const MSF_UINT8*            elementTable;   /* Element specific information */
  const MSF_UINT16*           attributeType;  /* Type of each attribute */
};


/* 
 * Decoder document specific configuration. Structure is
 * initiated by a msf_prsr_init_t function.
 */
struct msf_prsr_decoderData_st {
  const MSF_UINT8*            transform;      /* AttrStart to attribut table */
  int                         transformSize;  /* Size of transform table */
  const msf_strtable_info_t*  attrStart;      /* Attribute values associated with attrStart */
  const msf_strtable_info_t*  attrValue;      /* Attribute values associated with attrValue */ 

  msf_prsr_specificFunct_t*   specific;       /* Extention and opaque handler. Point to
                                               * msf_dec_opaqueSpecific if WBXML opaque data
                                               * is not to be ignored, else set to NULL. */
};



/**************************************************************
 * Functions                                                  *
 **************************************************************/

/*
 * Instantiate a new parser. 
 *
 * modId          - Module id of the caller. Used for memory allocations.
 *
 * userData       - Pointer to opaque data. Not used by the parser, only passed on with
 *                  all call-backs. The caller can use this to save any information.
 *                  A typical use is to give a pointer to a struct containing data such
 *                  as nestling depth and the structure the parsed information is saved
 *                  in. 'userData' is also returned from a call to msf_prsr_delete and
 *                  it is the users responibility to deallocate all data.
 *
 * initFunct      - Pointer to the function called when the document prologue is parsed.
 *
 * piHandler      - Pointer to function called when a PI is found.
 *
 * type           - Type of input source: MSF_PRSR_PIPE, MSF_PRSR_FILE or MSF_PRSR_BUFFER.
 *
 * document       - If 'type' is MSF_PRSR_BUFFER, then this is a pointer to a complete
 *                  document. Must be terminated by a null character. This means a UCS-2
 *                  or UTF-16 document must be terminated by double null bytes. This
 *                  concerns both text and WBXML documents.
 *
 * length         - If 'type' is MSF_PRSR_BUFFER, then this is the document length
 *                  excluding the null-termination.
 *
 * handle         - If 'type' is MSF_PRSR_PIPE or MSF_PRSR_FILE, then this is a handle
 *                  to a pipe or file.
 *
 * bufferSize     - Buffer initial size. All other memory use parameters are scaled from
 *                  this parameter. This is only the initial size of the input buffer
 *                  and not an upper limit of memory usage. If needed any of the buffers
 *                  used can be expanded. Some less than 'bufferSize' data is parsed at
 *                  each call to msf_prsr_parse, if available.
 *
 * charset        - Character set of the input, or MSF_CHARSET_UNKNOWN if unknown.
 *
 * defaultCharset - The default charset to use if 'charset' is MSF_CHARSET_UNKNOWN and
 *                  the parser could neither get the charset from the document nor guess
 *                  it.
 *
 * textMode       - TRUE if this is a text document or FALSE if this is a WBXML document.
 *
 * Returns a pointer to a new parser object. If out of memory, NULL is
 * returned.
 *
 * Input comes from either a pipe, a file or as a complete doucument in a
 * buffer. 'type' tells the type of input. Can be either MSF_PRSR_PIPE,
 * MSF_PRSR_FILE or MSF_PRSR_BUFFER.
 *
 * If 'type' equals MSF_PRSR_BUFFER, then 'buffer' is used for input and
 * 'length' tells the buffer length _excluding_ any termination. The
 * buffer is deallocated by the parser, no later than when msf_prsr_delete
 * is called. Text document must be NUL terminated.
 *
 * If 'type' equals MSF_PRSR_PIPE or MSF_PRSR_FILE then the input is read
 * from a pipe or file given by 'handle'. 
 *
 * When calling msf_prsr_delete the 'userData', 'handle' and 'type'
 * attributes are returned. If used, it is then up to the caller to
 * close and maybe delete the pipe or file. The pipe name can be stored
 * in for instance 'userData'.
 * 
 * The XML 1.0 specification says the default charset is UTF-8, but
 * HTTP 1.1 says latin-1. Any charset can be used as default.
 */
msf_prsr_parser_t*
msf_prsr_create (MSF_UINT8             modId,
                 void*                 userData,
                 msf_prsr_init_t*      initFunct,
                 msf_prsr_piHandler_t* piHandler,
                 int                   type,
                 char*                 document,
                 int                   length,
                 int                   handle,
                 int                   bufferSize,
                 int                   charset,
                 int                   defaultCharset,
                 int                   textMode);


/*
 * Parse a section of the current document. Parser main function.
 *
 * Returns a status code.
 */
int
msf_prsr_parse (msf_prsr_parser_t* parser);


/*
 * Delete a parser object. All internal data is deallocated. If
 * reading from a pipe or file, '*handle' is set to its handle
 * value, else '*handle' is set to -1. '*type' is set to the input
 * type: MSF_PRSR_PIPE, MSF_PRSR_FILE or MSF_PRSR_BUFFER.
 * '*userData' returns userData.
 *
 * If reading from a pipe or file, it is the user's responsibility
 * to close and maybe delete it. The same goes for '*userData'.
 *
 * Returns a status code.
 */
int
msf_prsr_delete (msf_prsr_parser_t* parser, int *type, int *handle, void* *userData);


/*
 * Deallocates an attribute vector and its data.
 */
void
msf_prsr_free_attributes (MSF_UINT8             modId,
                          msf_prsr_attribute_t* attrs,
                          int                   size);


/*
 * Convert a char string 's' containing a positive number to an
 * integer. If the number is followed by a "%" then it is negated.
 *
 * Accepted forms are only "123" and "123%". Surrounding white
 * space is ignored as well as any trailing data, that is "123px"
 * is interpreted as "123".
 *
 * 'end' is not used.
 *
 * '*error' is set to FALSE on success else TRUE.
 */
int
msf_prsr_read_num (const char*  s,
                   const char*  end,
                   int         *error);


/*
 * Parse and extract attribute value pairs. Returns the size of
 * the '*attrs' vector. -1 if the the input was malformatted or
 * -2 if out of memory.
 *
 *   attr="val" att2="val" ?>
 * |                       |
 * s                       end
 */
int
msf_prsr_extract_attributes (msf_prsr_parser_t*          parser,
                             const char*                 s,
                             const char*                 end,
                             const msf_strtable_info_t*  attributes,
                             const MSF_UINT16*           attributeType,
                             msf_prsr_attribute_t*      *attrs);


/*
 * Common WBXML opaque data handler. Writes opaque data as normal
 * text. This means opaque data can be be a part of any string
 * in character data callbacks.
 *
 * If WBXML opaque data is not to be ignored, then in the
 * initiation callback, set d->specific = msf_dec_opaqueSpecific.
 */
int 
msf_dec_opaqueSpecific (msf_prsr_parser_t*  parser,
                        const char*        *s,
                        const char*         end,
                        int                 size,
                        int                 type);

/*
 * HTML specific configuration. Only used by the BRS.
 */
void
msf_prsr_html_config (msf_prsr_parser_t*        parser,
                      const unsigned char*      htmlTable,
                      msf_prsr_changeCharset_t* changeCharset);

#endif
