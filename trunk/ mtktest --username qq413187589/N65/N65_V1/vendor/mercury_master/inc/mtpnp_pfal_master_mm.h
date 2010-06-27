/***********************************************
File name : MTPNP_AD_custom_MM.h
Contents : MTPNP AD custom module management file
History : Create by : Zhang Nan, apr 3, 2007
************************************************/
#ifndef _MTPNP_AD_CUSTOM_MM_H_
#define _MTPNP_AD_CUSTOM_MM_H_

#include "MTPNP_SDK_master_if.h"

extern void MTPNP_PFAL_MM_Init(void);

extern void MTPNP_PFAL_Custom_Slave_PlugIn(void * inMsg);
extern void MTPNP_PFAL_Custom_Startup_Finished(void * inMsg);

extern MTPNP_BOOL MTPNP_PFAL_Is_InIdlescreen(void);

extern void MTPNP_PFAL_Shutdown_System(void);
extern void MTPNP_PFAL_Shutdown_Timeout(void);
extern void MTPNP_PFAL_Set_Startup_Mode(MTPNP_UINT8 dual_sim_setting);
extern void MTPNP_PFAL_Set_Card_Status(MTPNP_UINT8 sim_insert_status);

void MTPNP_PFAL_boot_up(void * inMsg);

#endif // _MTPNP_AD_CUSTOM_MM_H_
