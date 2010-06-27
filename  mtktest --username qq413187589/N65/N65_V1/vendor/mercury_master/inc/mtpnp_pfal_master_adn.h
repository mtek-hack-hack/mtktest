/***********************************************
File name : MTPNP_PFAL_Master_ADN.h
Contents : mtpnp Slave ADN
		the file is part of phonebook module
History : Create by : LiHui, Jul 28, 2007
************************************************/
#ifndef __MTPNP_PFAL_MASTER_ADN_H__
#define __MTPNP_PFAL_MASTER_ADN_H__

#ifdef __MMI_DUAL_SIM_MASTER__

#include "MTPNP_AD_master_header.h"

void MTPNP_PFAL_ADN_Init(void);

void MTPNP_PFAL_ADN_HandleReadSuccessEntry(ST_MTPNP_DATA_PB_RECORD_INFO * info);
void MTPNP_PFAL_ADN_HandleUnload(void);
extern MTPNP_UINT16 MTPNP_AD_ADN_SIM2GetUsedNumber(void);
extern MTPNP_UINT8 MTPNP_AD_ADN_SIM2GetTagLen(void);
extern MTPNP_UINT8 MTPNP_AD_ADN_SIM2GetNumLen(void);
extern MTPNP_UINT16 MTPNP_AD_ADN_SIM2GetCapacity(void);
extern MTPNP_UINT8 MTPNP_AD_ADN_SIM2GetNumberSupport(void);
extern MTPNP_UINT16 MTPNP_AD_ADN_SIM2GetErrorNum(void);
extern void MTPNP_AD_ADN_SIMSetCapacity(MTPNP_UINT8 total);
extern void MTPNP_AD_ADN_SIMSetTagLen(MTPNP_UINT8 len);
extern void MTPNP_AD_ADN_SIMSetNumLen(MTPNP_UINT8 len);
extern void MTPNP_AD_ADN_HandleLoadFinish(void);
extern void MTPNP_AD_ADN_SetLoadFinish(MTPNP_BOOL value);
extern void MTPNP_AD_ADN_SetFailFlag(MTPNP_BOOL value);
extern void MTPNP_AD_ADN_SIMSetErrorNumber(MTPNP_UINT16 num);
extern void MTPNP_AD_ADN_SIMSetUsedNumber(MTPNP_UINT16 number);
extern void MTPNP_AD_ADN_HandleReadFailEntry(MTPNP_UINT16 index);
extern void MTPNP_AD_ADN_Unload(void);
extern void MTPNP_PFAL_ADN_HandleLoadFinish(void);
extern void MTPNP_PFAL_ADN_DelAllPreReq(void);
extern void MTPNP_PFAL_ADN_HandleDelAllDone(void);
extern void MTPNP_PFAL_ADN_HandleDelAllSuccess(void);
extern void MTPNP_PFAL_ADN_HandleDelAllFail(void);
extern void MTPNP_PFAL_ADN_HandleAddSuccess(MTPNP_UINT16 index, MTPNP_UINT16 name_length);
extern MTPNP_UINT8 MTPNP_AD_ADN_SIM2GetTagSupport(void);
extern MTPNP_UINT8 MTPNP_AD_ADN_SIM2GetUCS2LenSupport(void);
extern void MTPNP_AD_ADN_SIM2SetNumberSupport(MTPNP_UINT16 len);
extern MTPNP_BOOL MTPNP_PFAL_Phb_IsReady(void);
extern MTPNP_BOOL MTPNP_PFAL_ADN_HandleNeedLoad(ST_MTPNP_DATA_PB_CAPACITY * info);      //to prepare Slave SIM PB
extern MTPNP_BOOL MTPNP_PFAL_ADN_IsNeedHandlePBLoad(void);
extern void MTPNP_PFAL_ADN_GetSpeedDialInfo(void);
void HighlightSlaveAddEntry(void);
void Card2_ADN_entry_op_edit_entry(void);
void CARD2_ADN_edit_pre_save(void);
void CARD2_ADN_edit_save_confirm(void);
void CARD2_ADN_add_save_confirm(void);
void CARD2_ADN_exit_op_edit_entry(void);
void MTPNP_PFAL_ADN_EDITEntry(MTPNP_UINT16 index);
extern void mmi_phb_entry_op_add_entry(void);
extern void card2_mmi_phb_op_fill_inline_item(U8 field_index, U8 item_index, U16 store_index, U16 * string_list,
                                              U16 * image_list);
extern void MTPNP_PFAL_ADN_AddEntry(void);
extern void card2_mmi_phb_op_fill_inline_item(U8 field_index, U8 item_index, U16 store_index, U16 * string_list,
                                              U16 * image_list);
extern MTPNP_BOOL MTPNP_AD_Edit_ADN_Record(E_MTPNP_CODING_SCHEME coding_scheme, MTPNP_CHAR * name, MTPNP_CHAR * number,
                                           MTPNP_UINT8 TON_NPI, MTPNP_UINT16 index);

extern MTPNP_BOOL MTPNP_AD_Add_ADN_Record(E_MTPNP_CODING_SCHEME coding_scheme,
                                          MTPNP_CHAR * name, MTPNP_CHAR * number, MTPNP_UINT8 TON_NPI);
extern MTPNP_BOOL MTPNP_AD_DELETE_ADN_Record(MTPNP_UINT16 index);
extern MTPNP_BOOL MTPNP_AD_ADN_SIM2_PB_DeleteAll(void);
#if defined(__MMI_PHB_MULTI_OPERATION__)
#else /* __MMI_PHB_MULTI_OPERATION__ */
void HighlightSlaveDeleteAllEntry(void);
#endif /* __MMI_PHB_MULTI_OPERATION__ */
void HighlightSlaveCopylEntrySIM2Phone(void);
void HighlightSlaveMovelEntrySIM2Phone(void);
void MTPNP_Slave_PB_Copy_SIM2Phone_confirm(void);
void MTPNP_Slave_PB_Move_SIM2Phone_confirm(void);
void HighlightSlaveCopylEntrySIM2SIM(void);
void HighlightSlaveMovelEntrySIM2SIM(void);
void MTPNP_Slave_PB_Copy_SIM2SIM_confirm(void);
void MTPNP_Slave_PB_Move_SIM2SIM_confirm(void);
void MTPNP_Slave_PB_Duplicate_confirm(void);
void MTPNP_PFAL_ADN_Copy_Move_Dup_Entry(void);
void MTPNP_Slave_PB_Copy_Move_Dup_SIM2Phone_req(void);
void MTPNP_Slave_PB_Copy_Move_Dup_SIM2SIM_req(void);
void MTPNP_Slave_PB_Copy_Move_Dup_rsp(void *info);
void HintSlaveAddEntry(MTPNP_UINT16 index);
void HintSlaveDeleteAllEntry(MTPNP_UINT16 index);
void HighlightSlaveCopyAllSIM2toPhone(void);
void HighlightSlaveCopyAllPhonetoSIM2(void);
void HighlightSlaveCopyAllSIM1toSIM2(void);
void HighlightSlaveCopyAllSIM2toSIM1(void);
void HintSlaveCopyAllSIM2toPhone(MTPNP_UINT16 index);
void HintSlaveCopyAllPhonetoSIM2(MTPNP_UINT16 index);
void HintSlaveCopyAllSIM2toSIM1(MTPNP_UINT16 index);
void HintSlaveCopyAllSIM1toSIM2(MTPNP_UINT16 index);
void MTPNP_Slave_PB_copy_all_phone2sim_confirm(void);
void MTPNP_Slave_PB_copy_all_sim2sim_confirm(void);
void MTPNP_Slave_PB_copy_all_phone2sim_req(void);
void MTPNP_Slave_PB_copy_all_sim2sim_req(void);
void MTPNP_Slave_PB_copy_all_one_after_one_req(MTPNP_UINT8 from_storage);
void MTPNP_Slave_PB_copy_all_phone2sim_one_after_one_req(MTPNP_UINT8 from_storage);
void MTPNP_Slave_PB_copy_all_sim2sim_one_after_one_req(MTPNP_UINT8 from_storage);

void MTPNP_Slave_PB_copy_all_one_after_one_rsp(void *info);
void MTPNP_Slave_PB_copy_all_done(void);
void highlightPreferStoragLocationinSIM2(void);
void hintPreferStoragLocationinSIM2(MTPNP_UINT16 index);
void MTPNP_PFAL_PHB_op_copy_menu(void);
void MTPNP_PFAL_PHB_op_move_menu(void);
void MTPNP_Slave_PB_Copy_MainMenu(void);
void MTPNP_Slave_PB_Move_MainMenu(void);
void MTPNP_PFAL_PB_Option_Menu_Handle(void);
void MTPNP_PFAL_PB_CopyAll_Menu_Handle(void);

/* IP Dial */
void MTPNP_PFAL_PHB_op_SIM2_ip_number(void);
void MTPNP_PFAL_PHB_entry_list_choose_number_ip_dial(void);
void MTPNP_PFAL_phb_op_move_req(void);
void MTPNP_PFAL_phb_op_move_rsp(void *info);
void MTPNP_PFAL_ADN_SAT_Handler(MTPNP_BOOL adn_reset);
void MTPNP_PFAL_ADN_phb_ind_update(void *info);
MTPNP_BOOL MTPNP_PFAL_ADN_get_slave_is_copy_all(void);
void MTPNP_PFAL_ADN_set_slave_is_copy_all(MTPNP_BOOL is_copy_all);
MTPNP_BOOL MTPNP_PFAL_ADN_get_slave_is_delete_all(void);
void MTPNP_PFAL_ADN_set_slave_is_delete_all(MTPNP_BOOL is_delete_all);
void MTPNP_PFAL_ADN_set_slave_mass_op_success_flag(MTPNP_BOOL is_success);
MTPNP_UINT16 MTPNP_PFAL_ADN_get_slave_mass_op_count(void);

void MTPNP_PFAL_ADN_Init_SIM2_PHB(void);
MTPNP_BOOL MTPNP_PFAL_ADN_Is_PHB_Init(void);
BOOL MTPNP_PFAL_ADN_Is_PHB_Before_Sort(void);
void MTPNP_PFAL_ADN_Set_Is_PHB_Before_Sort(MTPNP_BOOL is_before_sort);
void MTPNP_PFAL_ADN_fdn_get_list_to_ram(void);
void MTPNP_PFAL_ADN_after_fdn_get_list_to_ram(void);
void MTPNP_PFAL_ADN_fdn_get_list_to_ram_req(void);
void MTPNP_PFAL_ADN_fdn_get_list_to_ram_rsp(void *info);
MTPNP_UINT16 MTPNP_PFAL_ADN_phb_fdn_search_by_number(S8 *number);
#if defined(__MMI_VCARD__)
void HighlightVcardRecvSaveToSim(void);
#endif /* defined(__MMI_VCARD__) */

#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MTPNP_PFAL_MASTER_ADN_H__ */
