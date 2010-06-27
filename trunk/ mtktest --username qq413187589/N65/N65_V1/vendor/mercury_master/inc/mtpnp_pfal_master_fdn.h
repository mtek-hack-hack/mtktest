#ifndef __MTPNP_PFAL_MASTER_FDN_H__
#define __MTPNP_PFAL_MASTER_FDN_H__

#ifdef __MMI_DUAL_SIM_MASTER__

#if 0
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
#else

extern void MTPNP_PFAL_InitFixedDialList(void);

extern void MTPNP_PFAL_HighlightFixedDial(void);
extern void MTPNP_PFAL_HighlightFdlMode(void);
extern void MTPNP_PFAL_HighlightFdlList(void);
extern void MTPNP_PFAL_HintFdl(U16 index);
extern void MTPNP_PFAL_HintFdlMode(U16 index);

extern void MTPNP_PFAL_HighlightAddFDL(void);
extern void MTPNP_PFAL_HighlightEditFDL(void);
extern void MTPNP_PFAL_HighlightDeleteFDL(void);

extern void MTPNP_PFAL_EntrySECSETFDNList(void);
extern void MTPNP_PFAL_ExitSECSETFDNListReload(void);
extern void MTPNP_PFAL_EntrySECSETFDNOption(void);
extern void MTPNP_PFAL_EntrySECSETFDNDetails(void);
extern void MTPNP_PFAL_ExitSECSETFDNDetails(void);
extern void MTPNP_PFAL_EntrySECSETFDNDelConfirm(void);
extern void MTPNP_PFAL_EntrySECSETFDNSaveConfirm(void);

extern void MTPNP_PFAL_SECSETGetFdlEntriesReq(void);
extern void MTPNP_PFAL_SECSETGetFdlEntriesRsp(void *);
extern void MTPNP_PFAL_SECSETSetFdlEntryReq(void);
extern void MTPNP_PFAL_SECSETSetFdlEntryRsp(void *);
extern void MTPNP_PFAL_SECSETDelFdlReq(void);
extern void MTPNP_PFAL_SECSETDelFdlRsp(void *);

extern void MTPNP_PFAL_GetActiveIndex(S32);
extern void MTPNP_PFAL_GetEntryTitle(S32);
extern void MTPNP_PFAL_PreNewFdlEntryReq(void);
extern void MTPNP_PFAL_FdlMakeCall(void);
extern void MTPNP_PFAL_ViewFDList(void);
extern void MTPNP_PFAL_FillFdlInlineEditStruct(void);
extern void MTPNP_PFAL_GoToFDLList(void);

extern void MTPNP_PFAL_PreSaveFdlBdlEntryReq(void);
extern void MTPNP_PFAL_EntryFdlList(void);

#endif

#endif /* __MMI_DUAL_SIM_MASTER__ */ 
#endif /* __MTPNP_PFAL_MASTER_FDN_H__ */ 

