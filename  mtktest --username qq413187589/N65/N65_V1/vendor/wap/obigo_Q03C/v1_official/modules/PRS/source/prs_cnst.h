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






#ifndef _prs_cnst_h
#define _prs_cnst_h







#define PRS_USER_DATA             0












#define PRS_BR_ADDRESS            1
#define PRS_BR_URL                2
#define PRS_BR_MMSURL             3
#define PRS_BR_NAME               4
#define PRS_BR_BOOKMARK           5
#define PRS_BR_ID                 6







#define PRS_VAL_BR_GSM_CSD        0    
#define PRS_VAL_BR_GSM_SMS        1    
#define PRS_VAL_BR_GSM_USSD       2    
#define PRS_VAL_BR_IS_136_CSD     3    
#define PRS_VAL_BR_GPRS           4    


#define PRS_VAL_BR_PAP            0    
#define PRS_VAL_BR_CHAP           1    
#define PRS_VAL_BR_MS_CHAP        2    



#define PRS_VAL_BR_AUTOMATIC      0    
#define PRS_VAL_BR_MANUAL         1    


#define PRS_VAL_BR_MSISDN_NO      0    
#define PRS_VAL_BR_IPV4           1    


#define PRS_VAL_BR_9200           9200 
#define PRS_VAL_BR_9201           9201 
#define PRS_VAL_BR_9202           9202 
#define PRS_VAL_BR_9203           9203 


#define PRS_VAL_BR_ANALOGUE       0    
#define PRS_VAL_BR_ISDN           1    


#define PRS_VAL_BR_AUTO           0    
#define PRS_VAL_BR_9600           1    
#define PRS_VAL_BR_14400          2    
#define PRS_VAL_BR_19200          3    
#define PRS_VAL_BR_28800          4    
#define PRS_VAL_BR_38400          5    
#define PRS_VAL_BR_43200          6    
#define PRS_VAL_BR_57600          7    


















#define PRS_WAP_PROXY             1
#define PRS_WAP_NAPDEF            2
#define PRS_WAP_BOOTSTRAP         3
#define PRS_WAP_VENDORCONFIG      4
#define PRS_WAP_CLIENTIDENTITY    5
#define PRS_WAP_APPLICATION       6
#define PRS_WAP_ACCESS            7
#define PRS_WAP_PXPHYSICAL        8

#define PRS_WAP_PXAUTHINFO        9
#define PRS_WAP_VALIDITY         10
#define PRS_WAP_NAPAUTHINFO      11
#define PRS_WAP_PORT_PXL         12
#define PRS_WAP_PORT_PXP         13
#define PRS_WAP_APPADDR          14
#define PRS_WAP_APPAUTH          15
#define PRS_WAP_RESOURCE         16

#define PRS_WAP_PXLOGICAL        17  

#ifdef MTK_TMP_PATCH /* CR27923 */
#ifdef PRS_CONFIG_DMP_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* PRS_CONFIG_DMP_SUPPORT */
/* OMA Extension */
#define PRS_WAP_WLAN        24
#define PRS_WAP_SEC_SSID    25
#define PRS_WAP_EAP         26
#define PRS_WAP_CERT        27
#define PRS_WAP_WEPKEY      28
#endif  /* MTK_TMP_PATCH CR27923 */




#define PRS_VAL_WAP_IPV4                  0 
#define PRS_VAL_WAP_IPV6                  1 
#define PRS_VAL_WAP_E164                  2 
#define PRS_VAL_WAP_ALPHA                 3 



#define PRS_VAL_WAP_CL_WSP                0 
#define PRS_VAL_WAP_CO_WSP                1 
#define PRS_VAL_WAP_CL_SEC_WSP            2 
#define PRS_VAL_WAP_CO_SEC_WSP            3 


#define PRS_VAL_WAP_OTA_HTTP_TO           4 
#define PRS_VAL_WAP_OTA_HTTP_TLS_TO       5 
#define PRS_VAL_WAP_OTA_HTTP_PO           6 
#define PRS_VAL_WAP_OTA_HTTP_TLS_PO       7 



#define PRS_VAL_WAP_GSM_USSD              0  
#define PRS_VAL_WAP_GSM_SMS               1  
#define PRS_VAL_WAP_GSM_CSD               2  
#define PRS_VAL_WAP_GSM_GPRS              3  
#define PRS_VAL_WAP_CDMA_SMS              4  
#define PRS_VAL_WAP_CDMA_CSD              5  
#define PRS_VAL_WAP_CDMA_PACKET           6  
#define PRS_VAL_WAP_ANSI_136_GUTS         7  
#define PRS_VAL_WAP_ANSI_136_CSD          8  
#define PRS_VAL_WAP_ANSI_136_GPRS         9  
#define PRS_VAL_WAP_ANSI_136_GHOST        10 
#define PRS_VAL_WAP_AMPS_CDPD             11 
#define PRS_VAL_WAP_PDC_CSD               12 
#define PRS_VAL_WAP_PDC_PACKET            13 
#define PRS_VAL_WAP_IDEN_SMS              14 
#define PRS_VAL_WAP_IDEN_CSD              15 
#define PRS_VAL_WAP_IDEN_PACKET           16 
#define PRS_VAL_WAP_FLEX_REFLEX           17 
#define PRS_VAL_WAP_PHS_SMS               18 
#define PRS_VAL_WAP_PHS_CSD               19 
#define PRS_VAL_WAP_TETRA_SDS             20 
#define PRS_VAL_WAP_TETRA_PACKET          21 
#define PRS_VAL_WAP_MOBITEX_MPAK          22 
#define PRS_VAL_WAP_CDMA2000_1X_SIMPLE_IP 23 
#define PRS_VAL_WAP_CDMA2000_1X_MOBILE_IP 24 


#define PRS_VAL_WAP_AUTOBAUDING    0  






#define PRS_VAL_WAP_APN           4 
#define PRS_VAL_WAP_SCODE         5 
#define PRS_VAL_WAP_TETRA_ITSI    6 
#define PRS_VAL_WAP_MAN           7 


#define PRS_VAL_WAP_ANALOG_MODEM  0 
#define PRS_VAL_WAP_V120          1 
#define PRS_VAL_WAP_V110          2 
#define PRS_VAL_WAP_X31           3 
#define PRS_VAL_WAP_BIT_TRANSP    4 
#define PRS_VAL_WAP_DIRECT_ASYNC  5 






#define PRS_VAL_WAP_HTTP_BASIC    0 
#define PRS_VAL_WAP_HTTP_DIGEST   1 


#define PRS_VAL_WAP_AAA           0 
#define PRS_VAL_WAP_HA            1 


#define PRS_VAL_WAP_APPSRV        0 
#define PRS_VAL_WAP_OBEX          1 




#define PRS_VAL_WAP_BASIC         2 
#define PRS_VAL_WAP_DIGEST        3 



#define PRS_VAL_SIM_1       1
#define PRS_VAL_SIM_2       2




#endif


