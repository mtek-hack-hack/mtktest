#ifndef _BT_COMMON_CONFIG_H_
#define _BT_COMMON_CONFIG_H_

//VIRTUAL_PORTS_NUM will be defined in make file and option.mak

//If DUMP_DATA_FROM_SPP_SRV 1: The received data from SPP server will be dumped in catcher log
#define DUMP_DATA_FROM_SPP_SRV 0
//If DUMP_DATA_FROM_SPP_CLI 1: The received data from SPP client will be dumped in catcher log
#define DUMP_DATA_FROM_SPP_CLI 0

/* Define the Number of SPP Servers */
#define NUM_SPP_SERVERS 1
/* Define the Number of SPP Clients */
#define NUM_SPP_CLIENTS 1

/* Define how many number of ms to ask the rssi value periodly: Currently, default value is 3000ms defined as follows */
#define CUSTOM_SPP_SCO_READ_RSSI_TIMER_PERIOD_IN_MS 1500

#endif /* _BT_COMMON_CONFIG_H_ */
