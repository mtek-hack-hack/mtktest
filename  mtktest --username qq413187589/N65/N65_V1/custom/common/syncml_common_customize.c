/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*******************************************************************************
 *
 * Filename:
 * ---------
 * syncml_common_customize.c
 *
 * Project:
 * --------
 * This file is used to implement customized syncml APIs.
 *   
 * Description:
 * ------------
 * Lina Yuan   
 *
 * Author:
 * -------
 *
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_release.h"
#include "custom_mmi_default_value.h"

#ifdef __SYNCML_SUPPORT__

#include "syncml_common_customize.h"


/* global variables */
kal_uint16 g_syncml_luid[MAX_SYNC_ITEMS];

/* size of SmlSyncItem, it should be updated when SmlSyncItem is changed. */
#define SYNCML_SMLSYNCITEM_SIZE 16 
/* Holds the modified luid's list for phonebok */
kal_uint8 g_syncml_ph_mod_item_ptr[MAX_PHB_PHONE_ENTRY * SYNCML_SMLSYNCITEM_SIZE];
/* Holds the added luid's list for phonebok */
kal_uint8 g_syncml_ph_add_item_ptr[MAX_PHB_PHONE_ENTRY * SYNCML_SMLSYNCITEM_SIZE];
/* Holds the deleted luid's list for phonebok */
kal_uint8 g_syncml_ph_delete_item_ptr[MAX_PHB_PHONE_ENTRY * SYNCML_SMLSYNCITEM_SIZE];

/* devinfo tag definition */
#define DI_CTCAP            "\x45"
#define DI_CTTYPE(s)        "\x46\x03"s"\x00\x01"
#define DI_DATASTORE        "\x47"
#define DI_DATATYPE(s)      "\x48\x03"s"\x00\x01"
#define DI_DEVID(s)         "\x49\x03"s"\x00\x01"
#define DI_DEVINF(s)          "\x02\x00\x00\x6A\x1D"s"\x4A"
//#define DI_DEVINF           "\x02\x9F\x54\x6A\x00\x4A"
#define DI_DEVTYP(s)        "\x4B\x03"s"\x00\x01"
#define DI_DISPLAYNAME(s)   "\x4C\x03"s"\x00\x01"
#define DI_DSMEM            "\x4D"
#define DI_EXT              "\x4E"
#define DI_FWV(s)           "\x4F\x03"s"\x00\x01"
#define DI_HWV(s)           "\x50\x03"s"\x00\x01"
#define DI_MAN(s)           "\x51\x03"s"\x00\x01"
#define DI_MAXGUIDSIZE(s)   "\x52\x03"s"\x00\x01"
#define DI_MAXID(s)         "\x53\x03"s"\x00\x01"
#define DI_MAXMEM(s)        "\x54\x03"s"\x00\x01"
#define DI_MOD(s)           "\x55\x03"s"\x00\x01"
#define DI_OEM(s)           "\x56\x03"s"\x00\x01"
#define DI_PARAMNAME(s)     "\x57\x03"s"\x00\x01"
#define DI_PROPNAME(s)      "\x58\x03"s"\x00\x01"
#define DI_RX(type,ver)     "\x59\x46\x03"type"\x00\x01\x64\x03"ver"\x00\x01\x01"
#define DI_RXPREF(type,ver) "\x5A\x46\x03"type"\x00\x01\x64\x03"ver"\x00\x01\x01"
#define DI_SHAREDMEM        "\x1B"              /* Flag, no need for "END" tag */
#define DI_SIZE(s)          "\x5C\x03"s"\x00\x01"
#define DI_SOURCEREF(s)     "\x5D\x03"s"\x00\x01"
#define DI_SWV(s)           "\x5E\x03"s"\x00\x01"
#define DI_SYNCCAP          "\x5F"
#define DI_SYNCTYPE(s)      "\x60\x03"s"\x00\x01"
#define DI_TX(type,ver)     "\x61\x46\x03"type"\x00\x01\x64\x03"ver"\x00\x01\x01"
#define DI_TXPREF(type,ver) "\x62\x46\x03"type"\x00\x01\x64\x03"ver"\x00\x01\x01"
#define DI_VALENUM(s)       "\x63\x03"s"\x00\x01"
#define DI_VERCT(s)         "\x64\x03"s"\x00\x01" /* Built into Tx, TxPref, Rx, RxPref */
#define DI_VERDTD(s)        "\x65\x03"s"\x00\x01"
#define DI_XNAM(s)          "\x66\x03"s"\x00\x01"
#define DI_XVAL(s)          "\x67\x03"s"\x00\x01"
#define DI_UTC              "\x28"              /* Flag, no need for "END" tag */
#define DI_SUPPORTNUMCHANGES "\x29"             /* Flag, no need for "END" tag */
#define DI_SUPPORTLARGEOBJS "\x2A"              /* Flag, no need for "END" tag */
#define DI_PROPERTY         "\x6B"
#define DI_PROPPARAM        "\x6C"
#define DI_MAXOCCUR(s)      "\x6D\x03"s"\x00\x01"
#define DI_NOTRUNCATE       "\x2E"
#define DI_FILTERRX         "\x70"
#define DI_FILTERCAP        "\x71"
#define DI_FILTERKEY(s)     "\x72\x03"s"\x00\x01"
#define DI_FIELDLEVEL       "\x33"
#define DI_SUPPORTHIERSYNC  "\x34"
#define DI_ELEMENT_END      "\x01"


#define LOCAL_DEVICE_URI        "IMEI:135790246811220"

/* if version 1.1 is used */

const kal_uint8 g_syncml_devinf_1_1[] = 
{
        DI_DEVINF("-//SYNCML//DTD DevInf 1.1//EN")
            DI_VERDTD("1.1")
            DI_MAN("Media Tek, Inc.")                       /* REPLACE */
            DI_SWV("v3.0")                                  /* REPLACE */
            DI_DEVID(LOCAL_DEVICE_URI)                      /* REPLACE */
            DI_DEVTYP("smartphone")                         /* REPLACE */
            DI_MOD("Mobile-Professional-1.1")               /* REPLACE */
            /*
             * These two options are automatically disabled if the
             * * smlconfig.h options are disabled.
             */
            DI_SUPPORTNUMCHANGES
            DI_SUPPORTLARGEOBJS
            /* Datastore information for contacts. Based on vCard 2.1. */
            DI_DATASTORE                                    /* Datastore definition */
                DI_SOURCEREF(SYNCML_LOCAL_CONTACT_DB)       /* Datastore URI */
                DI_MAXGUIDSIZE("4")
                DI_RX("text/x-vcard", "2.1")                /* Datastore can recieve vCard 2.1, */
                DI_RXPREF("text/x-vcard", "2.1")            /* and prefers to receive vCard 2.1. */
                DI_TXPREF("text/x-vcard", "2.1")            /* and prefers to transmit vCard 2.1. */
                DI_TX("text/x-vcard", "2.1")                /* Datastore can transmit vCard 2.1, */
                DI_SYNCCAP
                    DI_SYNCTYPE("1")                        /* Support 'two-way sync' */
                    DI_SYNCTYPE("2")                        /* Support 'slow two-way sync' */
                    DI_SYNCTYPE("3")                        /* Support 'one-way sync from client only' */
                    DI_SYNCTYPE("4")                        /* Support 'refresh sync from client only' */
                    DI_SYNCTYPE("5")                        /* Support 'one-way sync from server only' */
                    DI_SYNCTYPE("6")                        /* Support 'refresh sync from server only' */
                DI_ELEMENT_END
            DI_ELEMENT_END                                  /* End of datastore definition */
			/* Datastore information for calendars. Based on vCalendar 1.0 */
            DI_DATASTORE
                DI_SOURCEREF(SYNCML_LOCAL_CAL_DB)
                DI_MAXGUIDSIZE("4")
                DI_RX("text/x-vcalendar", "1.0")
                DI_RXPREF("text/x-vcalendar", "1.0")
                DI_TXPREF("text/x-vcalendar", "1.0")
                DI_TX("text/x-vcalendar", "1.0")
                DI_SYNCCAP
                    DI_SYNCTYPE("1")
                    DI_SYNCTYPE("2")
                    DI_SYNCTYPE("3")
                    DI_SYNCTYPE("4")
                    DI_SYNCTYPE("5")
                    DI_SYNCTYPE("6")
                DI_ELEMENT_END
            DI_ELEMENT_END                                  /* End of datastore definition */
			/* Content type definition for vCard 2.1 */
            DI_CTCAP                                        /* Content type definition */
                DI_CTTYPE("text/x-vcard")                   /* For vCard content type we support: */
                DI_PROPNAME("BEGIN")                        /* BEGIN property */
                    DI_VALENUM("VCARD")                     /* with value VCARD. */
                DI_PROPNAME("END")                          /* END property */
                    DI_VALENUM("VCARD")                     /* with value VCARD. */
                DI_PROPNAME("VERSION")                      /* VERSION property */
                    DI_VALENUM("2.1")                       /* with value 2.1. */
                DI_PROPNAME("N")                            /* N property */
#if 0
/* under construction !*/
#endif
                DI_PROPNAME("BDAY")
                DI_PROPNAME("ORG")
                DI_PROPNAME("URL")
                DI_PROPNAME("TITLE")
                DI_PROPNAME("NOTE")
                DI_PROPNAME("ADR")                          /* ADR property */
                    DI_PARAMNAME("INTL")                    /* with INTL parameter, */
                    DI_PARAMNAME("POSTAL")                  /* with POSTAL parameter, */
                    DI_PARAMNAME("PARCEL")                  /* with PARCEL parameter, */
                    DI_PARAMNAME("HOME")                    /* with HOME parameter, */
                    DI_PARAMNAME("WORK")                    /* with WORK parameter. */ 
                DI_PROPNAME("EMAIL")                        /* EMAIL property */
                    DI_PARAMNAME("INTERNET")
                DI_PROPNAME("TEL")                          /* TEL property */
#if 0
/* under construction !*/
#endif
                    DI_PARAMNAME("WORK")                    /* with WORK parameter, */
                    DI_PARAMNAME("HOME")                    /* with HOME parameter, */
#if 0
/* under construction !*/
#endif
                    DI_PARAMNAME("FAX")                     /* with FAX parameter, */
                    DI_PARAMNAME("CELL")
    #if 0   /* photo is not supported */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif 
            DI_ELEMENT_END                                  /* </CtCap> */
			/* End of content type definition */
			/* Content type definition for vCalendar/vEvent 1.0 */
            DI_CTCAP                                        /* capability for calendar */
                DI_CTTYPE("text/x-vcalendar")
                DI_PROPNAME("BEGIN")
                    DI_VALENUM("VCALENDAR")
                    DI_VALENUM("VEVENT")
                DI_PROPNAME("END")
                    DI_VALENUM("VCALENDAR")
                    DI_VALENUM("VEVENT")
                DI_PROPNAME("VERSION")
                    DI_VALENUM("1.0")
                DI_PROPNAME("DTSTART")
                DI_PROPNAME("DTEND")
                DI_PROPNAME("PRODID")
                DI_PROPNAME("DESCRIPTION")
                DI_PROPNAME("SUMMARY")
                DI_PROPNAME("PRIORITY")
                DI_PROPNAME("STATUS")
                DI_PROPNAME("SUMMARY")
                DI_PROPNAME("LOCATION")
                DI_PROPNAME("AALARM")
                DI_PROPNAME("DALARM")
                DI_PROPNAME("RRULE")
                DI_PROPNAME("END")
                DI_VALENUM("VCALENDAR")
                DI_VALENUM("VEVENT")
            DI_ELEMENT_END                                  /* </CtCap> */
			/* End of content type definition */
        DI_ELEMENT_END                                      /* devinf */
};

/* 1.2 version is used */
const kal_uint8 g_syncml_devinf_1_2[] = 
{
        DI_DEVINF("-//SYNCML//DTD DevInf 1.2//EN")
            DI_VERDTD("1.2")
            DI_MAN("Media Tek, Inc.")                       /* REPLACE */
            DI_SWV("v3.0")                                  /* REPLACE */
            DI_DEVID(LOCAL_DEVICE_URI)                      /* REPLACE */
            DI_DEVTYP("smartphone")                         /* REPLACE */
            DI_MOD("Mobile-Professional-1.2")               /* REPLACE */
            /*
             * These two options are automatically disabled if the
             * * smlconfig.h options are disabled.
             */
            DI_SUPPORTNUMCHANGES
            DI_SUPPORTLARGEOBJS
            /* Datastore information for contacts. Based on vCard 2.1. */
            DI_DATASTORE                                    /* Datastore definition */
                DI_SOURCEREF(SYNCML_LOCAL_CONTACT_DB)       /* Datastore URI */
                DI_MAXGUIDSIZE("4")
                DI_RX("text/x-vcard", "2.1")                /* Datastore can recieve vCard 2.1, */
                DI_RXPREF("text/x-vcard", "2.1")            /* and prefers to receive vCard 2.1. */
                DI_TXPREF("text/x-vcard", "2.1")            /* and prefers to transmit vCard 2.1. */
                DI_TX("text/x-vcard", "2.1")                /* Datastore can transmit vCard 2.1, */
                DI_CTCAP                                    /* Content type definition */
                /* Content type definition for vCard 2.1 */
                    DI_CTTYPE("text/x-vcard")               /* For vCard content type we support: */
                    DI_VERCT("2.1")
                    DI_PROPERTY
                        DI_PROPNAME("BEGIN")                /* BEGIN property */
                        DI_VALENUM("VCARD")                 /* with value VCARD. */
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("END")                  /* END property */
                        DI_VALENUM("VCARD")                 /* with value VCARD. */
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("VERSION")              /* VERSION property */
                        DI_VALENUM("2.1")                   /* with value 2.1. */
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("N")                    /* N property */
                        /* DI_SIZE("64") */
                        DI_DATATYPE("chr")                  /* with any character data value. */
                    DI_ELEMENT_END                          /* </Property> */
#if 0                    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif                    
                    DI_PROPERTY
                        DI_PROPNAME("BDAY")                 /* N property */
                        DI_DATATYPE("chr")                  /* with any character data value. */
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("ORG")                  /* N property */
                        /* DI_SIZE("64") */
                        DI_DATATYPE("chr")                  /* with any character data value. */
                    DI_ELEMENT_END                          /* </Property> */
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif 
                    DI_PROPERTY
                        DI_PROPNAME("EMAIL")                /* EMAIL property */
                        DI_DATATYPE("chr")                  /* with any character data value. */
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("TEL")                  /* TEL property */
                        /* DI_SIZE("64") */
                        DI_DATATYPE("chr")                  /* with any character data value, */
#if 0                        
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif                        
                        DI_PROPPARAM
                            DI_PARAMNAME("WORK")            /* with WORK parameter, */
                        DI_ELEMENT_END                      /* </PropParm> */
                        DI_PROPPARAM
                            DI_PARAMNAME("HOME")            /* with HOME parameter, */
                        DI_ELEMENT_END                      /* </PropParm> */
#if 0                        
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif                        
                        DI_PROPPARAM
                            DI_PARAMNAME("FAX")             /* with FAX parameter, */
                        DI_ELEMENT_END                      /* </PropParam> */
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("URL")                /* URL property */
                        DI_DATATYPE("chr")                  /* with any character data value. */
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("TITLE")                /* TITLE property */
                        DI_DATATYPE("chr")                  /* with any character data value. */
                    DI_ELEMENT_END                          /* </Property> */          
                    DI_PROPERTY
                        DI_PROPNAME("NOTE")                /* NOTE property */
                        DI_DATATYPE("chr")                  /* with any character data value. */
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("ADR")                  /* ADR property */
                        DI_DATATYPE("chr")                  /* with any character data value, */
                        DI_PROPPARAM
                            DI_PARAMNAME("INTL")            /* with INTL parameter, */
                            DI_DATATYPE("chr")
                        DI_ELEMENT_END                      /* </PropParm> */
                        DI_PROPPARAM
                            DI_PARAMNAME("POSTAL")          /* with POSTAL parameter, */
                            DI_DATATYPE("chr")
                        DI_ELEMENT_END                      /* </PropParm> */
                        DI_PROPPARAM
                            DI_PARAMNAME("PARCEL")          /* with PARCEL parameter, */
                            DI_DATATYPE("chr")
                        DI_ELEMENT_END                      /* </PropParm> */
                        DI_PROPPARAM
                            DI_PARAMNAME("HOME")            /* with HOME parameter, */
                            DI_DATATYPE("chr")
                        DI_ELEMENT_END                      /* </PropParm> */
                        DI_PROPPARAM
                            DI_PARAMNAME("WORK")            /* with WORK parameter. */
                            DI_DATATYPE("chr")
                        DI_ELEMENT_END                      /* </PropParm> */
                    DI_ELEMENT_END                          /* </Property> */
                
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif 
                  DI_ELEMENT_END                              /* </CtCap> */
                DI_SYNCCAP
                   DI_SYNCTYPE("1")                         /* Support 'two-way sync' */
                   DI_SYNCTYPE("2")                         /* Support 'slow two-way sync' */
                   DI_SYNCTYPE("3")                         /* Support 'one-way sync from client only' */
                   DI_SYNCTYPE("4")                         /* Support 'refresh sync from client only' */
                   DI_SYNCTYPE("5")                         /* Support 'one-way sync from server only' */
                   DI_SYNCTYPE("6")                         /* Support 'refresh sync from server only' */
                DI_ELEMENT_END
            DI_ELEMENT_END                                  /* End of datastore definition */
            /* Datastore information for calendars. Based on vCalendar 1.0 */
            DI_DATASTORE
                DI_SOURCEREF(SYNCML_LOCAL_CAL_DB)
                DI_MAXGUIDSIZE("4")
                DI_RX("text/x-vcalendar", "1.0")
                DI_RXPREF("text/x-vcalendar", "1.0")
                DI_TXPREF("text/x-vcalendar", "1.0")
                DI_TX("text/x-vcalendar", "1.0")
                DI_CTCAP
                    /* Content type definition for vCalendar/vEvent 1.0 */
                    DI_CTTYPE("text/x-vcalendar")
                    DI_VERCT("2.1")
                    DI_PROPERTY
                        DI_PROPNAME("BEGIN")
                        DI_VALENUM("VCALENDAR")
                        DI_VALENUM("VEVENT")
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("END")
                        DI_VALENUM("VCALENDAR")
                        DI_VALENUM("VEVENT")
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("VERSION")
                        DI_VALENUM("1.0")
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("DTSTART")
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("DTEND")
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("PRODID")
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("DESCRIPTION")
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("SUMMARY")
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("PRIORITY")
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("STATUS")
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("SUMMARY")
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("LOCATION")
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("AALARM")
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("DALARM")
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("RRULE")
                    DI_ELEMENT_END                          /* </Property> */
                    DI_PROPERTY
                        DI_PROPNAME("END")
                        DI_VALENUM("VCALENDAR")
                        DI_VALENUM("VEVENT")
                    DI_ELEMENT_END                          /* </Property> */
                DI_ELEMENT_END                              /* </CtCap> */
                DI_SYNCCAP
                    DI_SYNCTYPE("1")
                    DI_SYNCTYPE("2")
                    DI_SYNCTYPE("3")
                    DI_SYNCTYPE("4")
                    DI_SYNCTYPE("5")
                    DI_SYNCTYPE("6")
                DI_ELEMENT_END
            DI_ELEMENT_END                                  /* End of datastore definition */
        DI_ELEMENT_END                                      /* devinf */
};

/* APIs implementation */


/*****************************************************************************
* FUNCTION
*  syncml_get_max_sync_items_num 
* DESCRIPTION
*  This function is used to get the max sync items number.
* 
* PARAMETERS
*  void
* RETURNS
*  kal_uint16
*****************************************************************************/
kal_uint16 syncml_get_max_sync_items_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return (kal_uint16)MAX_SYNC_ITEMS;
}


/*****************************************************************************
* FUNCTION
*  syncml_get_max_sync_items_num 
* DESCRIPTION
*  This function is used to get the max sync items number.
* 
* PARAMETERS
*  void
* RETURNS
*  kal_uint16
*****************************************************************************/
kal_uint16 syncml_get_max_phb_items_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return (kal_uint16)MAX_PHB_PHONE_ENTRY;
}



/*****************************************************************************
* FUNCTION
*  syncml_get_devinfo_1_1 
* DESCRIPTION
*  This function is used to get devinfo and its length for v1.1.
* 
* PARAMETERS
*  void
* RETURNS
*  kal_uint16
*****************************************************************************/
void syncml_get_devinfo_1_1(kal_uint8 **devinfo, kal_uint16 *len)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	*devinfo = (kal_uint8 *)g_syncml_devinf_1_1;
    *len =  (kal_uint16)sizeof(g_syncml_devinf_1_1) - 1;
}

/*****************************************************************************
* FUNCTION
*  syncml_get_devinfo_1_2 
* DESCRIPTION
*  This function is used to get devinfo and its length for v1.2.
* 
* PARAMETERS
*  void
* RETURNS
*  kal_uint16
*****************************************************************************/
void syncml_get_devinfo_1_2(kal_uint8 **devinfo, kal_uint16 *len)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	*devinfo = (kal_uint8 *)g_syncml_devinf_1_2;
    *len =  (kal_uint16)sizeof(g_syncml_devinf_1_2) - 1;
}

#endif /* __SYNCML_SUPPORT__ */




