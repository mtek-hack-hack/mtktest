#ifndef __MTPNP_PFAL_DUALMODE_SETUP_H__
#define __MTPNP_PFAL_DUALMODE_SETUP_H__

#ifdef __MMI_DUAL_SIM_MASTER__

#include "MTPNP_AD_master_header.h"

void MTPNP_PFAL_Init(void);
void MTPNP_PFAL_DM_Setup_Init(void);
void MTPNP_PFAL_PhoneSetting_Init(void);
void MTPNP_PFAL_DM_Query_Init(void);
void MTPNP_PFAL_CallSetting_Init(void);
void MTPNP_PFAL_CallHistory_Init(void);
void MTPNP_PFAL_SecuritySetting_Init(void);

void MTPNP_PFAL_Goback_2_History(void);

/* dual mode startup setting */
void EntryDMSetScreen(void);
void HighlightDMSetMain(void);
void EntryStartupModeSetScreen(void);
void HighlightStartupModeSetMain(void);
void HintStartupModeSet(MTPNP_UINT16 index);
void HighlightDualCardSel(void);
void HighlightOnlyCard1Sel(void);
void HighlightOnlyCard2Sel(void);
#ifdef __DM_PWR_ON_QUERY_SUPPORT__
void HighlightDMQueryModeSel(void);
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */
void HighlightDMFlightModeSel(void);
void DualCardSel(void);
void OnlyCard1Sel(void);
void OnlyCard2Sel(void);
#ifdef __DM_PWR_ON_QUERY_SUPPORT__
void DMQueryModeSel(void);
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */
void DMFlightModeSel(void);
void CancelDMSwitch(void);
void EntryDualModeSwitchProgress(void);
E_MTPNP_AD_MODE_SWITCH_STATE MTPNP_PFAL_Switch_Mode(E_MTPNP_AD_NVRAM_STATUS curr_status);

void HighlightQuerySelDualMode(void);
void HighlightQuerySelCard1(void);
void HighlightQuerySelCard2(void);
void HighlightQuerySelFlight(void);

void SelectDualCard(void);
void SelectCard1(void);
void SelectCard2(void);
void SelectFlightMode(void);

void MTPNP_PFAL_Entry_PowerOn_Query_Screen(void);
void MTPNP_PFAL_Exit_QueryScreen(void);

void MTPNP_PFAL_Update_FlightMode_Status(void);
/* dual mode startup setting */

/* the card2 phone setting */
void HighlightCard2PhoneSetting(void);
void EntryCard2PhoneSetupMain(void);
/*  the card2 phone setting */

/* the card2 call setting */
void HighlightSlaveCallSetting(void);
void EntryCard2CallSetupMain(void);
void HighlightCard2LineSwitch(void);
void HighlightCard2CallID(void);
void HiliteCard2CallIDSetByNwk(void);
void HiliteCard2CallIDShowCid(void);
void HiliteCard2CallIDHideCid(void);
void HiliteCard2CallWait(void);
void HiliteCard2CallForward(void);
void HighlightCard2Barring(void);
void HintCard2CallID(MTPNP_UINT16 index);
void EntryCard2SetCallIDMain(void);
void HintCard2LineSwitch(MTPNP_UINT16 index);

void MTPNP_PFAL_SelectLine(void);
/* the card2 call setting */

/* the card2 security setting */
void HighlightCard2Security(void);
void EntryCard2SecurityMain(void);
void HighlightCard2ChangePassword(void);
void EntryCard2SecurityChangePassword(void);
void HighlightCard2SIMLock(void);
void HintCard2SIMLock(MTPNP_UINT16 index);
void EntryCard2SIMLockPIN1(void);
/* the card2 security setting */

void MTPNP_PFAL_Entry_SIM1CHV_Verify(void *param);
void MTPNP_PFAL_Entry_SIM2CHV_Verify(void *param);

#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* __MTPNP_PFAL_DUALMODE_SETUP_H__ */
