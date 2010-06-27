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
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "stack_types.h"
#include "task_config.h"
#include "wap_ps_struct.h"

/* applib */
#include "app_str.h"

/* MSF */
#include "msf_def.h"
#include "msf_core.h"
#include "msf_file.h"

/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"

/* MEA */
#include "mea_def.h"
#include "meal_if.h"
#include "matypes.h"
#include "maintsig.h"
#include "maconf.h"

/* MMA */
#include "mmsadp.h"

/* Misc */
#include "wapadp.h"

/******************************************************************************
 * Extern variables/functions
 ******************************************************************************/
extern int msm_get_module_status (MSF_UINT8 modId);

/*****************************************************************************
 * FUNCTION
 *  mma_conf_get_creation_mode
 * DESCRIPTION
 *  Get creation mode setting value
 * PARAMETERS
 * RETURNS
 *  mma_creation_mode_enum
 *****************************************************************************/
mma_creation_mode_enum mma_conf_get_creation_mode()
{
    MeaCreationModeType type = meaConfGetCreationMode();
    
    switch(type)
    {
    case MEA_CREATION_MODE_FREE:
        return MMA_CREATION_MODE_FREE;
        
    case MEA_CREATION_MODE_RESTRICTED:
        return MMA_CREATION_MODE_RESTRICTED;

    default:
        ASSERT(0);
        return MMA_CREATION_MODE_FREE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_conf_get_priority
 * DESCRIPTION
 *  Get MMS priority setting value
 * PARAMETERS
 * RETURNS
 *  mma_priority_enum
 *****************************************************************************/
mma_priority_enum mma_conf_get_priority()
{
    MeaPriorityType type = meaGetConfig()->priority;
    ASSERT(msm_get_module_status(MSF_MODID_MEA) == MODULE_STATUS_ACTIVE);
    
    switch(type)
    {
    case MEA_PRIORITY_LOW:
        return MMA_PRIORITY_LOW;
        
    case MEA_PRIORITY_NORMAL:
        return MMA_PRIORITY_MEDIUM;

    case MEA_PRIORITY_HIGH:
        return MMA_PRIORITY_HIGH;

    default:
        ASSERT(0);
        return MMA_PRIORITY_MEDIUM;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_conf_get_expiry_time
 * DESCRIPTION
 *  Get MMS expiry time setting value
 * PARAMETERS
 * RETURNS
 *  mma_expiry_time_enum
 *****************************************************************************/
mma_expiry_time_enum mma_conf_get_expiry_time()
{
    MeaExpiryTimeType type = meaGetConfig()->expiryTime;
    ASSERT(msm_get_module_status(MSF_MODID_MEA) == MODULE_STATUS_ACTIVE);
    
    switch(type)
    {
    case MEA_EXPIRY_1_HOUR:
        return MMA_EXPIRY_1_HOUR;

    case MEA_EXPIRY_6_HOURS:
        return MMA_EXPIRY_6_HOURS;
        
    case MEA_EXPIRY_12_HOURS:
        return MMA_EXPIRY_12_HOURS;

    case MEA_EXPIRY_1_DAY:
        return MMA_EXPIRY_1_DAY;

    case MEA_EXPIRY_1_WEEK:
        return MMA_EXPIRY_1_WEEK;

    case MEA_EXPIRY_MAX:
        return MMA_EXPIRY_MAX;

    default:
        ASSERT(0);
        return MMA_EXPIRY_MAX;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_conf_get_delivery_time
 * DESCRIPTION
 *  Get MMS delivery time setting value
 * PARAMETERS
 * RETURNS
 *  mma_delivery_time_enum
 *****************************************************************************/
mma_delivery_time_enum mma_conf_get_delivery_time()
{
    MeaDeliveryTimeType type = meaGetConfig()->deliveryTime;
    ASSERT(msm_get_module_status(MSF_MODID_MEA) == MODULE_STATUS_ACTIVE);
    
    switch(type)
    {
    case MEA_DELIVERY_TIME_IMMEDIATE:
        return MMA_DELIVERY_IMMEDIATE;
        
    case MEA_DELIVERY_TIME_1_HOUR:
        return MMA_DELIVERY_1_HOUR;

    case MEA_DELIVERY_TIME_12_HOURS:
        return MMA_DELIVERY_12_HOURS;

    case MEA_DELIVERY_TIME_24_HOURS:
        return MMA_DELIVERY_24_HOURS;

    default:
        ASSERT(0);
        return MMA_DELIVERY_IMMEDIATE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_conf_get_delivery_report
 * DESCRIPTION
 *  Get MMS delivery report setting value
 * PARAMETERS
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mma_conf_get_delivery_report()
{
    ASSERT(msm_get_module_status(MSF_MODID_MEA) == MODULE_STATUS_ACTIVE);
    return (kal_bool) meaGetConfig()->deliveryReport;
}

/*****************************************************************************
 * FUNCTION
 *  mma_conf_get_read_report
 * DESCRIPTION
 *  Get MMS read report setting value
 * PARAMETERS
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mma_conf_get_read_report()
{
    ASSERT(msm_get_module_status(MSF_MODID_MEA) == MODULE_STATUS_ACTIVE);
    return (kal_bool) meaGetConfig()->readReport;
}

/*****************************************************************************
 * FUNCTION
 *  mma_conf_get_max_mms_size
 * DESCRIPTION
 *  Get MMS maximum size setting value
 * PARAMETERS
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_uint32 mma_conf_get_max_mms_size()
{
    return (kal_uint32) MMS_DEFAULT_MAX_MSG_SIZE;
}

/*****************************************************************************
 * FUNCTION
 *  mma_conf_get_image_resizing
 * DESCRIPTION
 *  Get image resizing setting value
 * PARAMETERS
 *  resizing        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_conf_get_image_resizing(mma_image_resizing_struct *resizing)
{
#ifdef JPG_ENCODE
    MsfSize size = {0, 0};
    ASSERT(resizing != NULL);

    meaConfGetImageResizeValue(&size);
    memset(resizing, 0x00, sizeof(mma_image_resizing_struct));

    if(size.height == 0 && size.width == 0)
    {
        resizing->enable = KAL_FALSE;
    }
    else
    {
        resizing->enable = KAL_TRUE;
        resizing->width = size.width;
        resizing->height = size.height;
    }
#else
    ASSERT(resizing != NULL);
    memset(resizing, 0x00, sizeof(mma_image_resizing_struct));
    resizing->enable = KAL_FALSE;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mma_conf_get_signature
 * DESCRIPTION
 *  Get signature setting value
 * PARAMETERS
 *  sig        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_conf_get_signature(mma_signature_struct *sig)
{
    kal_uint8 *text_file = NULL;

    ASSERT(sig != NULL);
    memset(sig, 0x00, sizeof(mma_signature_struct));
    sig->enable = (kal_bool)meaConfGetAutoSignature();

    if(sig->enable == KAL_TRUE)
    {
        text_file = HDI_FileNameTranslate(MEAlib_getSignatureFilePath());
        ASSERT(app_ucs2_strlen((const kal_int8 *)text_file) < MMA_MAX_INTERNAL_FILENAME_LENGTH);
        app_ucs2_strcpy((kal_int8 *)sig->text_file, (const kal_int8 *)text_file);
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mma_conf_get_sliding_time
 * DESCRIPTION
 *  Get sliding time setting value
 * PARAMETERS
 *  sliding        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_conf_get_sliding_time(mma_setting_struct *sliding)
{
    ASSERT(sliding != NULL);
    ASSERT(msm_get_module_status(MSF_MODID_MEA) == MODULE_STATUS_ACTIVE);
    memset(sliding, 0x00, sizeof(mma_setting_struct));

    sliding->min = (kal_uint32)MEAlib_getMinSlidingTime();
    sliding->max = (kal_uint32)MEAlib_getMaxSlidingTime();
    sliding->value = (kal_uint32)meaGetConfig()->slideDuration;
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mma_conf_get_mmsc_version
 * DESCRIPTION
 *  Get MMS version
 * PARAMETERS
 * RETURNS
 *  MmsVersion
 *****************************************************************************/
MmsVersion mma_conf_get_mmsc_version()
{
    ASSERT(msm_get_module_status(MSF_MODID_MEA) == MODULE_STATUS_ACTIVE);
    return (MmsVersion) meaGetConfig()->proxyVersion;
}

/*****************************************************************************
 * FUNCTION
 *  mma_conf_get_mmsc_url
 * DESCRIPTION
 *  Get MMSC URL
 * PARAMETERS
 * RETURNS
 *  MMSC URL string
 *****************************************************************************/
char *mma_conf_get_mmsc_url()
{
    ASSERT(msm_get_module_status(MSF_MODID_MEA) == MODULE_STATUS_ACTIVE);
    return meaGetConfig()->proxyHost;
}

/*****************************************************************************
 * FUNCTION
 *  mma_conf_get_max_mms_no
 * DESCRIPTION
 *  Get MMS maximum number setting value
 * PARAMETERS
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_uint32 mma_conf_get_max_mms_no()
{
    return (kal_uint32) MMS_MAX_NO_OF_MSG;
}


/*****************************************************************************
 * FUNCTION
 *  mma_conf_get_max_mms_no
 * DESCRIPTION
 *  Get MMS maximum number setting value
 * PARAMETERS
 * RETURNS
 *  kal_bool
 *****************************************************************************/
int mma_conf_get_send_setting(void)
{
    ASSERT(msm_get_module_status(MSF_MODID_MEA) == MODULE_STATUS_ACTIVE);
    return meaGetConfig()->saveOnSend;
}
