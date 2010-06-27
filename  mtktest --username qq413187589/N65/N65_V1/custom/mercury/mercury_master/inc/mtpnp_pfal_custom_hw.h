#ifndef _MTPNP_PFAL_CUSTOM_HW_H_
#define _MTPNP_PFAL_CUSTOM_HW_H_

#include "MTPNP_AD_master_header.h"

typedef enum
{
    MTPNP_GPIO_BACKLIGHT_PERMANENT = 0,
    MTPNP_GPIO_BACKLIGHT_SHORT_TIME
} E_MTPNP_BACKLIGHT_TIME;

#define MTPNP_IO_INPUT			      0 /* IO in input */
#define MTPNP_IO_ALL_INPUT		      0x0000
#define MTPNP_IO_OUTPUT			      1 /* IO in output */
#define MTPNP_IO_ALL_OUTPUT		   0xffff
#define SLAVE_PWRKEY_DOWN_TIMEOUT	3000

MTPNP_BOOL MTPNP_AD_ShouldTurnOffMicBias(void);
void MTPNP_AD_SetTurnOffMicBias(MTPNP_BOOL on);
void MTPNP_PFAL_Turnon_Backlight(E_MTPNP_BACKLIGHT_TIME time);
void MTPNP_PFAL_GPIO_Deinit(void);

void MTPNP_PFAL_PowerOn_Slave(void);
void MTPNP_PFAL_PowerOff_Slave(void);
void MTPNP_PFAL_EndKey_Down(void);
void MTPNP_PFAL_Release_PowerKey(void);
void MTPNP_PFAL_Wakeup_Target(void);
void MTPNP_PFAL_Wakeup_Target_Stop(void);
void MTPNP_PFAL_TurnOnExtAmplifier(void);
void MTPNP_PFAL_TurnOffExtAmplifier(void);
void MTPNP_PFAL_SpeechStart(void);
void MTPNP_PFAL_SpeechStop(void);

void MTPNP_PFAL_MuteMasterSpeech(MTPNP_BOOL on);
//#ifdef __MERCURY_SLAVE_BT_MASTER_SIDE__
void MTPNP_PFAL_SetMasterBTNormalMode(void);
void MTPNP_PFAL_TurnOffBTNormalMode(void);
void MTPNP_PFAL_Master_Swtich_ToBTGpio(MTPNP_BOOL on);
void MTPNP_PFAL_SetSlaveBTNormalMode(void);
void MTPNP_PFAL_Master_Swtich_ToBTGpio(MTPNP_BOOL on);
void MTPNP_AD_SwitchBTAudioChanel(E_MTPNP_AUDIO_CHANEL_TYPE type);
//#endif /*__MERCURY_SLAVE_BT_MASTER_SIDE__*/
void MTPNP_AD_SwitchAudioChanel(E_MTPNP_AUDIO_CHANEL_TYPE type);
#endif // _MTPNP_PFAL_CUSTOM_HW_H_
