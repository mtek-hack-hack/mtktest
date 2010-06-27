#ifndef __MTK_TARGET__

#include "kal_release.h"
#include "syscomp_config.h"

#include "wndrv_cnst.h"
#include "wndrv_ft_types.h"

kal_uint8      WNDRV_PTA_isOFF;        /* PTA Default is disable */
kal_uint32     Protocol_Status4WLAN = 0;
kal_uint32     BT_STATE_Report2WLAN = 0;


kal_bool wndrv_create(comptask_handler_struct **handle)
{
	return 1;
}

kal_bool dhcp_create(comptask_handler_struct **handle)
{
	return 1;
}


void RFTool_WiFi_EEPROM_Read(kal_uint32 eeprom_index, kal_uint16 *eeprom)
{
        
}

void RFTool_WiFi_EEPROM_Write(kal_uint32 eeprom_index, kal_uint16 eeprom)
{

}

void RFTool_WiFi_BBCR_Read(kal_uint32 bbcr_index, kal_uint8 *bbcr)
{

}

void RFTool_WiFi_BBCR_Write(kal_uint32 bbcr_index, kal_uint8 bbcr)
{

}

void RFTool_WiFi_MCR16_Write(kal_uint32 mcr_index, kal_uint16 mcr16)
{

}

void RFTool_WiFi_MCR16_Read(kal_uint32 mcr_index, kal_uint16 *mcr16)
{

}

void RFTool_WiFi_MCR32_Write(kal_uint32 mcr_index, kal_uint32 mcr32)
{

}

void RFTool_WiFi_MCR32_Read(kal_uint32 mcr_index, kal_uint32 *mcr32)
{

}

void RFTool_WiFi_PwrMgt(wndrv_test_pwr_mgt_enum pwr_mgt)
{
        
}

void RFTool_WiFi_PktRx(kal_uint32 ch_freq, void (* callback) (wndrv_test_rx_status_struct* result))
{
        
}

void RFTool_WiFi_PktTx(kal_uint8 country_code[2], wndrv_test_pkt_tx_struct pkt_tx)
{
        
}

void RFTool_WiFi_LocalFreq(kal_uint8 country_code[2], wndrv_test_tx_struct local_freq)
{
        
}

void RFTool_WiFi_CarrierSupp(kal_uint8 country_code[2], wndrv_test_tx_struct carrier_supp)
{
        
}

void RFTool_WiFi_ContTx(kal_uint8 country_code[2], wndrv_test_tx_struct cont_tx)
{
        
}

void RFTool_WiFi_DacDCOffset(kal_uint8 *i_ch, kal_uint8 *q_ch)
{
	
}

void RFTool_WiFi_EnterNormalMode(void)
{
        
}

void RFTool_WiFi_EnterTestMode(void)
{
	
}

void RFTool_WiFi_Stop(void)
{
        
}

void wndrv_PowerSave_Ctrl (kal_uint8 bCtl)
{
}

kal_uint8 wndrv_PS_GetHandle (kal_int8 *psName)
{
    return 1;
}

void wndrv_PS_Enable (kal_uint8 handle)
{

}

void wndrv_PS_Disable(kal_uint8 handle)
{
        
}
void wndrv_set_Protocol_Status(kal_uint32 value, kal_uint32 mask)
{

}

kal_bool wndrv_chip_isOK(void)
{
    return 0;
}
#endif

