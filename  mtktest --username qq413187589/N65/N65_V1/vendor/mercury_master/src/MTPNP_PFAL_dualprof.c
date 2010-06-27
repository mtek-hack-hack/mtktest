#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

#ifdef __MMI_DUAL_PROFILE_SUPPORT__

#include "PixtelDataTypes.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "CustDataRes.h"
#include "SettingDefs.h"
#include "ProfileGprots.h"
#include "EventsGprot.h"
#include "ProfilesGexdcl.h"
#include "NVRAMEnum.h"
#include "NVRAMProt.h"
#include "NVRAMType.h"
#include "DebugInitDef.h"
#include "gpioInc.h"
#include "AudioInc.h"
#include "mdi_audio.h"
#include "Globaldefs.h"
#include "IdleAppDef.h"
#include "ProfilesGexdcl.h"
#include "CallManagementGProt.h"
#include "KeyBrd.h"
#include "Profiles_prot.h"
#include "ProfilesDefs.h"       /* MTK robin 1119, AT command set wallpaper and profile */
#include "ATHandlerProt.h"
/* Leo add for DLT */
#include "DownloadDefs.h"
#include "SimDetectionDef.h"
#include "SimDetectionGprot.h"
/* Leo end */
#ifdef __MMI_BT_PROFILE__
#include "BTMMICM.h"
#include "BTMMICMGprots.h"
#include "BTMMIScr.h"
#include "BTMMIScrGprots.h"
#ifdef __MMI_A2DP_SUPPORT__
#include "BTMMIA2DP.h"
#endif
#endif /* __MMI_BT_PROFILE__ */
#include "SmsGuiInterfaceType.h"

#include "MTPNP_PFAL_dualprof.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_OSAL_common.h"

MTPNP_BOOL MTPNP_PFAL_Play_MasterMsgsTone(MTPNP_UINT8 type)
{
    MTPNP_BOOL result = MTPNP_TRUE;

    switch (type)
    {
    case MSG_NEW_NONE:
        break;
    case MSG_NEW_VOICEMAIL:
        break;
    case MSG_NEW_FAX:
        break;
    case MSG_NEW_EMAIL:
        break;
    case MSG_NEW_MSG_NORMAL:
        if (MTPNP_AD_SMS_Is_Recv_From_Card2())
        {
            result = MTPNP_FALSE;
        }
        break;
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))
    case MSG_NEW_JMMS_MMS:
        break;
    case MSG_NEW_JMMS_JAVA_MMS:
        break;
#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */
#if (defined (JATAAYU_SUPPORT) && defined(WAP_SUPPORT))
    case MSG_NEW_PUSH:
        break;
    case MSG_NEW_PROV_SETTING:
        break;
#endif /* (defined (JATAAYU_SUPPORT) && defined(WAP_SUPPORT)) */
#if defined(__MMI_SMART_MESSAGE_MT__) || ( defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
    case MSG_NEW_MSG_PICTURE:
        break;
    case MSG_NEW_MSG_RINGTONE:
        break;
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || ( defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */
    case MSG_NEW_MSG_CLASS0:
        break;
#ifdef __MMI_BROWSER_2__
    case MSG_BRW_NEW_PUSH:
        break;
    case MSG_BRW_NEW_MESSAGE:
        break;
#endif /* __MMI_BROWSER_2__ */
#ifdef __MMI_CCA_SUPPORT__
    case MSG_NEW_CCA_SETTING:
        break;
#endif /* __MMI_CCA_SUPPORT__ */
    case MSG_NEW_DELIVERY_REPORT:
        if (MTPNP_AD_SMS_Report_Status_Is_From_Card2())
        {
            result = MTPNP_FALSE;
        }
        break;
#ifdef __MMI_MMS_2__
    case MSG_UMMS_NEW_JAVA_MMS:
        break;
    case MSG_UMMS_NEW_MMS:
        break;
#endif
    default:
        break;
    }

    return result;
}

#endif /* __MMI_DUAL_PROFILE_SUPPORT__ */

#endif /* __MMI_DUAL_SIM_MASTER__ */
