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
/*
 * prs_def.c
 *
 * Provisioning defines: defining supported elements and fields.
 */

#include "msf_cfg.h"
#include "msf_def.h"
#include "prs_def.h"
#include "prs_cnst.h"


/**********************************************************************
 * Constants
 **********************************************************************/

/* Common string table */
const char* const prs_Str_resources[] = {
   "/homepage",          /* PRS_PATH_HOMEPAGE */
   /* OTA Bookmark */
   "/ota_bookmark",      /* PRS_PATH_OTA_BOOKMARK */
   "name",               /* PRS_STR_NAME */   
   "url",                /* PRS_STR_URL */
   /* WAP gateway and proxy */
   "/ota_proxy",         /* PRS_PATH_OTA_PROXY */
   "/wap_proxy",         /* PRS_PATH_WAP_PROXY */
   "homeurl",            /* PRS_STR_HOMEURL */
   "mmsurl",             /* PRS_STR_MMSURL */
   "profile_name",       /* PRS_STR_PROFILE_NAME */
   "px_name",            /* PRS_STR_PX_NAME */
   "px_address",         /* PRS_STR_PX_ADDRESS */
   "px_port",            /* PRS_STR_PX_PORT */
   "px_service",         /* PRS_STR_PX_SERVICE */
   "px_type",            /* PRS_STR_PX_TYPE */
   "px_auth_name",       /* PRS_STR_PX_AUTH_NAME */
   "px_auth_secret",     /* PRS_STR_PX_AUTH_SECRET */
   /* Bearer setting */
   "ota_bearer",         /* PRS_PATH_OTA_BEARER */
   "wap_bearer",         /* PRS_PATH_WAP_BEARER */
   "addr_bearer",        /* PRS_STR_ADR_BEARER */
   "isp_name",           /* PRS_STR_ISP_NAME */
   "ppp_authtype",       /* PRS_STR_PPP_AUTHTYPE */
   "ppp_authname",       /* PRS_STR_PPP_AUTHNAME */
   "ppp_authpw",         /* PRS_STR_PPP_AUTHPW */
   "csd_calltype",       /* PRS_STR_CSD_CALLTYPE */
   "csd_callspeed",      /* PRS_STR_CSD_CALLSPEED */
   /* Bearer setting -- OTA setting only */
   "csd_dialstring",     /* PRS_STR_CSD_DAILSTRING */
   "gprs_apn",           /* PRS_STR_GPRS_APN */
   /* Bearer setting -- WAP setting only */
   "nap_addr",           /* PRS_STR_WAP_NAP_ADDR */
   "nap_addrtype",       /* PRS_STR_WAP_NAP_ADDRTYPE */
   "application",        /* PRS_PATH_WAP_APP */
   "appid",              /* PRS_STR_WAP_APP_APPID */
   "addr",               /* PRS_STR_WAP_APP_ADDR */
   "res_uri",            /* PRS_STR_WAP_APP_RES_URI */
   "res_name",           /* PRS_STR_WAP_APP_RES_NAME */
   /* for Dual SIM */
   "/mtk_info",          /* PRS_PATH_MTK_INFO */
   "sim_id"              /* PRS_STR_MTK_SIM_ID */
}; 


/* Common destination lists */

const prs_dest_list_t prs_Dest_bra[] = {
  MSF_MODID_BRA,
  -1
};


/* Common destination list table */
const prs_dest_list_t* const prs_Dest_list[] = {
  /* 00 */ prs_Dest_bra
};


/*************************************
 * User data element node
 *************************************/

/* Filter setting for the user data node.
 * Format:
 * - field value (PRS_USR_*) to associate the key, path and destination list with.
 * - key: string recource id (PRS_STR_*)
 * - path: string resource id (PRS_PATH_*)
 * - destination list: id for the destination list (PRS_DEST_*)
 *
 * The key and path values are used when filtering this node and
 * are indexes into the prs_Str_resources table. Destination list
 * is an index into the prs_Dest_list array and determines is a
 * field is to be sent in an output signal. If the destination
 * list value is less than zero, then the key and 
 */
const prs_field_def_t prs_user_data_Field_def[] = {
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};


/**********************************************************************/
/*                            OTA Settings                            */
/*                Browser Settings & Browser Bookmarks                */
/**********************************************************************/

/* Element action table */
MSF_INT8 prs_br_Element_action [] = {
  PRS_ACTION_NONE,  /* USER DATA */
  PRS_ACTION_NONE,  /* ADDRESS   */
  PRS_ACTION_NONE,  /* URL       */
  PRS_ACTION_NONE,  /* MMSURL    */
  PRS_ACTION_NONE,  /* NAME      */
  PRS_ACTION_NONE,  /* BOOKMARK  */
  PRS_ACTION_NONE   /* ID        */
};


/* Filter setting */
const prs_field_def_t prs_br_adr_Field_def[] = {
  {
    PRS_BR_ADR_PROXY,
    PRS_STR_PX_ADDRESS,
    PRS_PATH_OTA_PROXY,
    PRS_DEST_BRA
  },
  {
    PRS_BR_ADR_PORT,
    PRS_STR_PX_PORT,
    PRS_PATH_OTA_PROXY,
    PRS_DEST_BRA
  },
  {
    PRS_BR_ADR_PROXY_TYPE,
    PRS_STR_PX_TYPE,
    PRS_PATH_OTA_PROXY,
    PRS_DEST_BRA
  },
  {
    PRS_BR_ADR_PROXY_AUTHNAME,
    PRS_STR_PX_AUTH_NAME,
    PRS_PATH_OTA_PROXY,
    PRS_DEST_BRA
  },
  {
    PRS_BR_ADR_PROXY_AUTHSECRET,
    PRS_STR_PX_AUTH_SECRET,
    PRS_PATH_OTA_PROXY,
    PRS_DEST_BRA
  },
  {
    PRS_BR_ADR_BEARER,
    PRS_STR_ADR_BEARER,
    PRS_PATH_OTA_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_BR_ADR_ISP_NAME,
    PRS_STR_ISP_NAME,
    PRS_PATH_OTA_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_BR_ADR_PPP_AUTHTYPE,
    PRS_STR_PPP_AUTHTYPE,
    PRS_PATH_OTA_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_BR_ADR_PPP_AUTHNAME,
    PRS_STR_PPP_AUTHNAME,
    PRS_PATH_OTA_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_BR_ADR_PPP_AUTHSECRET,
    PRS_STR_PPP_AUTHPW,
    PRS_PATH_OTA_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_BR_ADR_CSD_CALLTYPE,
    PRS_STR_CSD_CALLTYPE,
    PRS_PATH_OTA_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_BR_ADR_CSD_CALLSPEED,
    PRS_STR_CSD_CALLSPEED,
    PRS_PATH_OTA_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_BR_ADR_CSD_DIALSTRING,
    PRS_STR_CSD_DAILSTRING,
    PRS_PATH_OTA_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_BR_ADR_GPRS_ACCESSPOINTNAME,
    PRS_STR_GPRS_APN,
    PRS_PATH_OTA_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

const prs_field_def_t prs_br_url_Field_def[] = {
  {
    PRS_BR_URL_URL,
    PRS_STR_HOMEURL,
    PRS_PATH_OTA_PROXY,
    PRS_DEST_BRA
  },
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

const prs_field_def_t prs_br_mmsurl_Field_def[] = {
  {
    PRS_BR_MMSURL_URL,
    PRS_STR_MMSURL,
    PRS_PATH_OTA_PROXY,
    PRS_DEST_BRA
  },
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

const prs_field_def_t prs_br_nm_Field_def[] = {
  {
    PRS_BR_NM_NAME,
    PRS_STR_PROFILE_NAME,
    PRS_PATH_OTA_PROXY,
    PRS_DEST_BRA
  },
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

const prs_field_def_t prs_br_bkm_Field_def[] = {
  {
    PRS_BR_BKM_NAME,
    PRS_STR_NAME,
    PRS_PATH_OTA_BOOKMARK,
    PRS_DEST_BRA
  },
  {
    PRS_BR_BKM_URL,
    PRS_STR_URL,
    PRS_PATH_OTA_BOOKMARK,
    PRS_DEST_BRA
  },
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

const prs_field_def_t prs_br_id_Field_def[] = {
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};


/**********************************************************************/
/*                            OTA Settings                            */
/*                           SyncML settings                          */
/**********************************************************************/


/**********************************************************************/
/*                          WAP Provisioning                          */
/**********************************************************************/

/* Element action table */
MSF_INT8 prs_wap_Element_action [] = {
  PRS_ACTION_NONE,  /* USER DATA      */
  PRS_ACTION_NONE,  /* PROXY          */
  PRS_ACTION_NONE,  /* NAPDEF         */
  PRS_ACTION_NONE,  /* BOOTSTRAP      */
  PRS_ACTION_NONE,  /* CLIENTIDENTITY */
  PRS_ACTION_NONE,  /* VENDORCONFIG   */
  PRS_ACTION_NONE,  /* APPLICATION */
  PRS_ACTION_NONE,  /* ACCESS */
#ifdef MTK_TMP_PATCH /* CR27923 */
  PRS_ACTION_NONE,  /* PXP */
  PRS_ACTION_NONE,  /* PXAUTHINFO */
  PRS_ACTION_NONE,  /* VALIDITY */
  PRS_ACTION_NONE,  /* NAPAUTHINFO */
  PRS_ACTION_NONE,  /* PORT_PXL */
  PRS_ACTION_NONE,  /* PORT_PXP */
  PRS_ACTION_NONE,  /* APPADDR */
  PRS_ACTION_NONE,  /* APPAUTH */
  PRS_ACTION_NONE,  /* RESOURCE */
  PRS_ACTION_NONE,  /* PXLOGICAL */
#ifdef PRS_CONFIG_DMP_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
  PRS_ACTION_NONE,  /* */
  PRS_ACTION_NONE,  /* */
  PRS_ACTION_NONE,  /* */
  PRS_ACTION_NONE,  /* */
  PRS_ACTION_NONE,  /* */
  PRS_ACTION_NONE,  /* */
#endif
/* OMA Extension */
  PRS_ACTION_NONE,  /* WLAN */
  PRS_ACTION_NONE,  /* SEC_SSID */
  PRS_ACTION_NONE,  /* EAP */
  PRS_ACTION_NONE,  /* CERT */
  PRS_ACTION_NONE  /* WEPKEY */
#endif  /* MTK_TMP_PATCH */
};


/* Filter setting */
const prs_field_def_t prs_wap_px_Field_def[] = {
  {
    PRS_WAP_PX_NAME,
    PRS_STR_PX_NAME,
    PRS_PATH_WAP_PROXY,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_PX_PXADDR,
    PRS_STR_PX_ADDRESS,
    PRS_PATH_WAP_PROXY,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_PX_PORTNBR,
    PRS_STR_PX_PORT,
    PRS_PATH_WAP_PROXY,
    PRS_DEST_BRA,
  },
  {
    PRS_WAP_PX_SERVICE,
    PRS_STR_PX_SERVICE,
    PRS_PATH_WAP_PROXY,
    PRS_DEST_BRA,
  },
  {
    PRS_WAP_PX_PXADDRTYPE,
    PRS_STR_PX_TYPE,
    PRS_PATH_WAP_PROXY,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_PX_PXAUTH_ID,
    PRS_STR_PX_AUTH_NAME,
    PRS_PATH_WAP_PROXY,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_PX_PXAUTH_PW,
    PRS_STR_PX_AUTH_SECRET,
    PRS_PATH_WAP_PROXY,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_PX_STARTPAGE,
    PRS_STR_HOMEURL,
    PRS_PATH_WAP_PROXY,
    PRS_DEST_BRA
  },
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

#ifdef WAP_SUPPORT
const prs_field_def_t prs_wap_nap_Field_def[] = {
  {
    PRS_WAP_NAP_BEARER,
    PRS_STR_ADR_BEARER,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_NAP_NAME,
    PRS_STR_ISP_NAME,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_NAP_CALLTYPE,
    PRS_STR_CSD_CALLTYPE,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_NAP_LINKSPEED,
    PRS_STR_CSD_CALLSPEED,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_NAP_NAP_ADDRESS,
    PRS_STR_WAP_NAP_ADDR,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_NAP_NAP_ADDRTYPE,
    PRS_STR_WAP_NAP_ADDRTYPE,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

const prs_field_def_t prs_wap_napauthinfo_Field_def[] = {
  {
    PRS_WAP_NAP_AUTHTYPE,
    PRS_STR_PPP_AUTHTYPE,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_NAP_AUTHNAME,
    PRS_STR_PPP_AUTHNAME,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_NAP_AUTHSECRET,
    PRS_STR_PPP_AUTHPW,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

const prs_field_def_t prs_wap_validity_Field_def[] = {
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

#else     /* WAP_SUPPORT */
const prs_field_def_t prs_wap_nap_Field_def[] = {
  {
    PRS_WAP_NAP_BEARER,
    PRS_STR_ADR_BEARER,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_NAP_NAME,
    PRS_STR_ISP_NAME,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_NAP_AUTHTYPE,
    PRS_STR_PPP_AUTHTYPE,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_NAP_AUTHNAME,
    PRS_STR_PPP_AUTHNAME,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_NAP_AUTHSECRET,
    PRS_STR_PPP_AUTHPW,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_NAP_CALLTYPE,
    PRS_STR_CSD_CALLTYPE,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_NAP_LINKSPEED,
    PRS_STR_CSD_CALLSPEED,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_NAP_NAP_ADDRESS,
    PRS_STR_WAP_NAP_ADDR,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_NAP_NAP_ADDRTYPE,
    PRS_STR_WAP_NAP_ADDRTYPE,
    PRS_PATH_WAP_BEARER,
    PRS_DEST_BRA
  },
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};
#endif  /* WAP_SUPPORT */

const prs_field_def_t prs_wap_bts_Field_def[] = {
  {
    PRS_WAP_BTS_NAME,
    PRS_STR_PROFILE_NAME,
    PRS_PATH_WAP_PROXY,
    PRS_DEST_BRA
  },
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

const prs_field_def_t prs_wap_cid_Field_def[] = {
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};


const prs_field_def_t prs_wap_vdc_Field_def[] = {
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

#ifdef WAP_SUPPORT
const prs_field_def_t prs_wap_app_Field_def[] = {
  {
    PRS_WAP_APP_APPID,
    PRS_STR_WAP_APP_APPID,
    PRS_PATH_WAP_APP,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_APP_ADDR,
    PRS_STR_WAP_APP_ADDR,
    PRS_PATH_WAP_APP,
    PRS_DEST_BRA
  },
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};
const prs_field_def_t prs_wap_appaddr_Field_def[] = {
  {
    PRS_WAP_APP_ADDR2,
    PRS_STR_WAP_APP_ADDR,
    PRS_PATH_WAP_APP,
    PRS_DEST_BRA
  },
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};
const prs_field_def_t prs_wap_appauth_Field_def[] = {
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};
const prs_field_def_t prs_wap_resource_Field_def[] = {
  {
    PRS_WAP_APP_RES_URI,
    PRS_STR_WAP_APP_RES_URI,
    PRS_PATH_WAP_APP,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_APP_RES_NAME,
    PRS_STR_WAP_APP_RES_NAME,
    PRS_PATH_WAP_APP,
    PRS_DEST_BRA
  },
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

#else  /* WAP_SUPPORT  */
const prs_field_def_t prs_wap_app_Field_def[] = {
  {
    PRS_WAP_APP_APPID,
    PRS_STR_WAP_APP_APPID,
    PRS_PATH_WAP_APP,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_APP_ADDR,
    PRS_STR_WAP_APP_ADDR,
    PRS_PATH_WAP_APP,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_APP_RES_URI,
    PRS_STR_WAP_APP_RES_URI,
    PRS_PATH_WAP_APP,
    PRS_DEST_BRA
  },
  {
    PRS_WAP_APP_RES_NAME,
    PRS_STR_WAP_APP_RES_NAME,
    PRS_PATH_WAP_APP,
    PRS_DEST_BRA
  },
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};
#endif  /* WAP_SUPPORT  */

const prs_field_def_t prs_wap_acc_Field_def[] = {
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

#ifdef MTK_TMP_PATCH /* CR27923 */
#ifdef PRS_CONFIG_DMP_SUPPORT
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
#endif  /* PRS_CONFIG_DMP_SUPPORT */
/* OMA Extension */
const prs_field_def_t prs_wap_wlan_Field_def[] = {
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

const prs_field_def_t prs_wap_secssid_Field_def[] = {
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

const prs_field_def_t prs_wap_eap_Field_def[] = {
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

const prs_field_def_t prs_wap_cert_Field_def[] = {
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};

const prs_field_def_t prs_wap_wepkey_Field_def[] = {
  {
    PRS_END_OF_TABLE, -1, -1, -1
  }
};
#endif  /* MTK_TMP_PATCH */

/**********************************************************************/
/*                          IOTA Provisioning                         */
/**********************************************************************/

