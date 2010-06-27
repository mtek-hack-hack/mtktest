/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
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
 * uis_cfg.h
 *
 * Created by Klas Hermodsson, Thu May 22 15:50:11 2003.
 *
 * Revision history:
 * 2003-09-22 (MADE): removed define UIS_CONFIG_NOTIFY_SHELL
 *
 */
#ifndef _uis_cfg_h
#define _uis_cfg_h


/*
 * UIS_MSG_TYPE_OWNER_ARRAY defines an array where the msg type defines 
 * (see uis_if.h UIS_MSG_TYPE_... and uis_ecfg.h) is the index into the array.
 * The value at that index is the module id of the owner module.
 * A value of -1 means that the msg type is not part of the unified inbox (i.e. no owner).
 * A value of MSF_MODID_UIS means that UIS is the owner and that the msg type is 
 * stored in the UIS.
 *
 * NOTE that the number of entries in this array MUST be UIS_NBR_OF_MSG_TYPES!
 */
#ifdef WAP_SUPPORT
#define UIS_MSG_TYPE_OWNER_ARRAY { \
                    MSF_MODID_UIS, \
                    MSF_MODID_UIS, \
                    MSF_MODID_MMS, \
                    -1, \
                    -1, \
        }
#else
#define UIS_MSG_TYPE_OWNER_ARRAY { \
                    MSF_MODID_UIS, \
                    MSF_MODID_UIS, \
                    MSF_MODID_MMS, \
                    MSF_MODID_EMS, \
                    -1, \
        }
#endif
#endif


