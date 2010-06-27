/*
 * Copyright (C) Obigo AB, 2002-2005.
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





#ifndef _MCONFIG_H
#define _MCONFIG_H




struct MmsRegistryEntrySt 
{
    struct MmsRegistryEntrySt* next;
    char*           path;
    char*           key;
    MSF_UINT8       type;
    MSF_INT32       value_i;
    unsigned char*  value_bv;
    MSF_UINT16      value_bv_length;
};

typedef struct MmsRegistryEntrySt MmsRegistryEntry;


typedef enum
{
    





    MMS_SIG_CORE_READ_REGISTRY,

    





    MMS_SIG_CORE_REG_RESPONSE
} MmsCoreConfigSignalId;



typedef enum
{
    


    MMS_CFG_FROM_ADDRESS_INSERT_TYPE,

    













    MMS_CFG_IMMEDIATE_RETRIEVAL,

    


    MMS_CFG_PORT,

    


    MMS_CFG_REPORT_ALLOWED,

    
    MMS_CFG_FROM_ADDRESS_TYPE,
    
    






    MMS_CFG_MAX_SIZE_OF_MSG,
    
    







    MMS_CFG_MAX_RETRIEVAL_SIZE,

    






    MMS_CFG_ROAMING_MODE,


    





    MMS_CFG_CLASS_PERSONAL, 
    
    





    MMS_CFG_CLASS_ADVERTISEMENT, 

    





    MMS_CFG_CLASS_INFORMATIONAL, 
    
    





    MMS_CFG_CLASS_AUTO, 

    





    MMS_CFG_ANONYMOUS_SENDER,
 
    










    MMS_CFG_DISCONNECT_ON_IDLE,
 
    









    MMS_CFG_TREAT_AS_DELAYED_RETRIEVAL,

    

    MMS_CFG_PROXY_RELAY_VERSION,

    

    MMS_CFG_STK_CONNECTION_TYPE,

    
    MMS_CFG_NETWORK_ACCOUNT,

    









    MMS_CFG_NO_SMS_NOTIFY_RESP,

    






    MMS_CFG_NOTIFY_RESP_MODE,

    



    MMS_CFG_NOTIF_MATCH_TO_MMSC,

    
    MMS_CFG_GW_SECURE_PORT,

    
    MMS_CFG_GW_HTTP_PORT,

    
    MMS_CFG_NETWORK_STATUS_ROAMING,
    
    
    MMS_CFG_NETWORK_STATUS_BEARER,


#ifdef __MMS_DUAL_SIM_SUPPORT__
    MMS_CFG_SLAVE_SIM_PORT,

    MMS_CFG_SLAVE_SIM_STK_CONNECTION_TYPE,
    
    MMS_CFG_SLAVE_SIM_NETWORK_ACCOUNT,

    MMS_CFG_SLAVE_SIM_GW_SECURE_PORT,
    
    MMS_CFG_SLAVE_SIM_GW_HTTP_PORT,

    MMS_CFG_SLAVE_SIM_NETWORK_STATUS_ROAMING,

    MMS_CFG_SLAVE_SIM_NETWORK_STATUS_BEARER,
#endif
        
    MMS_CFG_TOTAL_INT
} MmsConfigInt;



typedef enum
{
    


    MMS_CFG_FROM_ADDRESS,

    



    MMS_CFG_IMMEDIATE_RETRIEVAL_SERVER,

    


    MMS_CFG_POST_URI,

    






    MMS_CFG_PROXY_RELAY,

    

    MMS_CFG_PROXY_RELAY_SCHEME,

    



    MMS_CFG_FROM_NAME,
    
    

    MMS_CFG_TEXT_YOUR_MSG,
    
    

    MMS_CFG_TEXT_FROM,
    
    

    MMS_CFG_TEXT_TO,
    
    

    MMS_CFG_TEXT_READ,
    
    

    MMS_CFG_TEXT_MSGID,
    
    

    MMS_CFG_TEXT_SENT,
    
    


    MMS_CFG_TEXT_WAS_READ,

    






    MMS_CFG_CLASS_STRING, 
    
    

    MMS_CFG_TEXT_SUBJECT,

    
    MMS_CFG_GW_ADDRESS,

    
    MMS_CFG_GW_PASSWORD,

    
    MMS_CFG_GW_REALM,

    













    MMS_CFG_CLIENT_HTTP_HEADER,
    
    
    MMS_CFG_GW_USERNAME,

    
    MMS_CFG_CLIENT_USER_AGENT,
    
#ifdef __MMS_DUAL_SIM_SUPPORT__
    MMS_CFG_SLAVE_SIM_PROXY_RELAY,    

    MMS_CFG_SLAVE_SIM_POST_URI,

    MMS_CFG_SLAVE_SIM_PROXY_RELAY_SCHEME,
  
    MMS_CFG_SLAVE_SIM_GW_ADDRESS,

    MMS_CFG_SLAVE_SIM_GW_USERNAME,
    
    MMS_CFG_SLAVE_SIM_GW_PASSWORD,
    
    MMS_CFG_SLAVE_SIM_GW_REALM,
#endif


    MMS_CFG_TOTAL_STR
} MmsConfigStr;










void cfgEmergencyAbort(void);
void cfgInit(void);
void cfgTerminate(void);
int cfgGetInt(MmsConfigInt key);
char *cfgGetStr(MmsConfigStr key);

#endif 

