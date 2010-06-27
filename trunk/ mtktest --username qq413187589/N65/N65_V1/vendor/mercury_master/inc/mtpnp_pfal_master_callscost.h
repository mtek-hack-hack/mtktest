/***********************************************
File name : MTPNP_PFAL_Master_CallsCost.h
Contents : mtpnp Slave CallsCost
		the file is part of phonebook module
History : Create by : LiHui, Sep 4, 2007
************************************************/
#ifndef __MTPNP_PFAL_MASTER_CALLSCOST_H__
#define __MTPNP_PFAL_MASTER_CALLSCOST_H__

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"

typedef struct
{
    MTPNP_UINT8 newMaxCostStr[10];
    double ppu;                 /* hold PS return ppu */
    MTPNP_UINT8 PPUStr[20 * ENCODING_LENGTH];   /* hold PS return currency */
    MTPNP_UINT8 newPPUStr[20 * ENCODING_LENGTH];        /* for edit currency */

    MTPNP_UINT8 currencyStr[4 * ENCODING_LENGTH];       /* hold PS return currency */
    MTPNP_UINT8 newCurrencyStr[4 * ENCODING_LENGTH];    /* for edit currency */
} ST_MTPNP_CALLCOST_INFO;

void MTPNP_PFAL_CallsCost_Init(void);
    
void HighlightSlaveCHISTCallCost(void);
void HighlightSlaveCHISTLastCost(void);
void HighlightSlaveCHISTAllCost(void);
void HighlightSlaveCHISTPriceAndUnit(void);
void HighlightSlaveCHISTResetCost(void);
void HighlightSlaveCHISTMaxCost(void);

void HintSlaveCHISTLastCost(U16 index);
void HintSlaveCHISTAllCost(U16 index);
void HintSlaveCHISTPriceAndUnit(U16 index);
void HintSlaveCHISTMaxCost(U16 index);

void MTPNP_PFAL_Set_Call_Cost_Hilite_Index(MTPNP_UINT8 index);
void RspSIM2Pin2ForCallCostSetMaxCostSuccess(void);
void RspSIM2Pin2ForCallCostSetPUCTSuccess(void);

void EntrySlaveCHISTCallCost(void);
void MTPNP_CARD2_CAI_ResetCallCostReq(void);
void MTPNP_CARD2_CAI_ResetMaxCost(void);
void MTPNP_CARD2_EntryCHISTSetPriceUnit(void);
void MTPNP_CARD2_CHISTGoBackCallCostHistory(void);


#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MTPNP_PFAL_MASTER_ADN_H__ */
