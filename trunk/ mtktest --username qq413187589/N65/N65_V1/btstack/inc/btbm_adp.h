#ifndef _BTBM_ADP_H
#define _BTBM_ADP_H

#define MTK_BTBM_TIMER_CHECK




typedef void (*gap_tester)(ilm_struct *ilm_ptr);


void bma_init(void);
void bma_gap_testing(gap_tester cb);
void bma_gap_testing_reset(void);

void bma_tester_handler(ilm_struct *ilm_ptr);
void bma_handler(ilm_struct *ilm_ptr);
void bma_reject_handler(ilm_struct *ilm_ptr);
void BTBMAdpGetWholePropertyCfm(bt_bm_read_property_cnf_struct source);
void BTBMAdpGetReadVisibleModeCfm(kal_uint8 modeconnected, kal_uint8 modenotconnected);
void BTBMAdpReadLocalDeviceClassCfm(kal_uint8 result, kal_uint32 cod);
void BTBMAdpReadLocalBDAddressCfm(kal_uint8	result, btbm_bd_addr_t bd_addr);
void BTBMAdpWriteScanEnabledCfm(kal_uint8 result);
void BTBMAdpGapDiscoveryCompCfm(kal_uint8 result, kal_uint8 total_number);
void BTBMAdpGapDiscoveryResultCfm(
                                                                                    btbm_bd_addr_t bd_addr,
                                                                                    kal_uint32 cod,
                                                                                    kal_uint8 name_len,
                                                                                    kal_uint8 *name
                                                                                    );


void BTBMAdpGapDiscoveryCancelCfm(kal_uint8 result, kal_uint8 total_number);
void BTBMAdpWriteLocalDeviceClassCfm(kal_uint8 result);
void BTBMAdpReadLocalNameCfm(kal_uint8 *name, kal_uint8 length);
void BTBMAdpWriteLocalNameCfm(kal_uint8 result);

void BTBMAdpReadRemoteNameCfm(
                                                                                    kal_uint8	result,
                                                                                    btbm_bd_addr_t	bd_addr,
                                                                                    kal_uint8	name_len,
                                                                                    kal_uint8	*name,
                                                                                    kal_uint32 cod
                                                                                    );

void BTBMAdpPinCodeRequiredInd(
                                                                                    btbm_bd_addr_t	bd_addr,
                                                                                    kal_uint8	name_len,
                                                                                    kal_uint8	*name
                                                                                    );

void BTBMAdpGapSetAuthenticationCfm(kal_uint8	result);


void BTBMAdpBondingDeviceCfm(kal_uint8 result, btbm_bd_addr_t bd_addr);

void BTBMAdpBondingResultInd(kal_uint8 result, kal_uint8 type, btbm_bd_addr_t bd_addr, kal_uint32 cod);

void BTBMAdpDeleteTrustCfm(kal_uint8 result, btbm_bd_addr_t bd_addr);

void BTBMAdpDeleteTrustAllCfm(kal_uint8 result);

void BTBMAdpBondingCancelCfm(kal_uint8 result, btbm_bd_addr_t bd_addr);

void BTBMAdpPairingCancelCfm(kal_uint8 result, btbm_bd_addr_t bd_addr);

void BTBMAdpSaveSettingCfm(kal_uint8 result);

void BTBMAdpRestoreSettingCfm(kal_uint8 result);

void BTBMAdpServiceSearchResult(kal_uint32 uuid, btbm_bd_addr_t addr);

void BTBMAdpServiceSearchComplete(kal_uint8 result, btbm_bd_addr_t bd_addr, kal_uint8 no);

void BTBMAdpAttributeSearchComplete(kal_uint8 result, btbm_bd_addr_t addr);

void BTBMAdpAttributeSearchResult(kal_uint16 len, kal_uint8 *data, btbm_bd_addr_t addr);

void BTBMAdpPowerOnResult(void);

void BTBMAdpPowerOffResult(void);

void BTBMAdpConnectAcceptInd(btbm_bd_addr_t addr);

#ifdef MTK_BTBM_TIMER_CHECK
void BTBMTimerStart(kal_uint32 timeout_count);
#endif /*end ifdef  MTK_BTBM_TIMER_CHECK*/

#endif






