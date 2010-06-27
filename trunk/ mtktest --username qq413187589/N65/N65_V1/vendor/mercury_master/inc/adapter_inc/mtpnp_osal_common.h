/***********************************************************
 * system name	: MT-PNP protocol SDK
 * file name	: MTPNP_OSAL_common.h
 * contents		: Common definition for OS abstract layer
 * History		: Feb8, 2006: Created by HYU
 ***********************************************************/
#ifndef __MTPNP_OSAL_COMMON_H__
#define __MTPNP_OSAL_COMMON_H__

#include "MTPNP_SDK_common_if.h"
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

/************************************************************
* Memory operation functions
*************************************************************/
void *MTPNP_OSAL_malloc(const MTPNP_UINT size);
void MTPNP_OSAL_memset(void *dest, MTPNP_UINT8 value, MTPNP_UINT len);
void MTPNP_OSAL_memcpy(void *dest, const void *src, const MTPNP_UINT len);
void MTPNP_OSAL_memfree(void *ptrBlock);

/************************************************************
* Message related functions
*************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
#endif
void MTPNP_OSAL_create_event(void);
void MTPNP_OSAL_release_event(void);
#if 0
/* under construction !*/
/* under construction !*/
#endif

/************************************************************
* Timer related functions
*************************************************************/
void MTPNP_OSAL_start_timer(MTPNP_UINT32 iElapse, void (*pTimerProc) (void));
void MTPNP_OSAL_stop_timer(void);

/************************************************************
* Thread related functions
*************************************************************/
void MTPNP_OSAL_create_DLL_thread(void (*pFunction) (void));
void MTPNP_OSAL_wait_DLL_thread_started(void);
void MTPNP_OSAL_wait_DLL_thread_exit(void);

void MTPNP_OSAL_thread_sleep(MTPNP_UINT iDelay);
void MTPNP_OSAL_thread_started_notification(void);
void MTPNP_OSAL_thread_exit(void);

/************************************************************
* Event related functions
*************************************************************/
MTPNP_UINT16 MTPNP_OSAL_get_event(void);
void MTPNP_OSAL_set_event(MTPNP_UINT16 iEvent);
void MTPNP_OSAL_iset_event(MTPNP_UINT16 iEvent);

/************************************************************
* System sleep related functions
*************************************************************/
void MTPNP_OSAL_enable_sleep(void);
void MTPNP_OSAL_EINT_enable_sleep(void);
void MTPNP_OSAL_disable_sleep(void);
void MTPNP_OSAL_EINT_disable_sleep(void);

/************************************************************
* Create random number functions
*************************************************************/
MTPNP_UINT32 MTPNP_OSAL_creat_random_number(void);

/************************************************************
* Internal message queue related functions
*************************************************************/
/* below is example for queue size
#define MTPNP_PRIMITIVE_QUEUE_TOTAL_SIZE		5
#define MTPNP_PRIMITIVE_QUEUE_REDUNDANT		3
#define MTPNP_HP_PRIMITIVE_QUEUE_SIZE		5
#define MTPNP_LP_PRIMITIVE_QUEUE_SIZE		3
#define MTPNP_DP_PRIMITIVE_QUEUE_SIZE		1
#define MTPNP_MAX_DATA_FRAME_LEN		240		// Max length of frame is 16384
// max memory used = (MTPNP_PRIMITIVE_QUEUE_TOTAL_SIZE+MTPNP_PRIMITIVE_QUEUE_REDUNDANT) * MTPNP_MAX_DATA_FRAME_LEN
*/
typedef struct
{
    MTPNP_UINT8 total_queue_size;
    MTPNP_UINT8 redundant_queue_size;
    MTPNP_UINT8 high_priority_queue_size;
    MTPNP_UINT8 low_priority_queue_size;
    MTPNP_UINT8 droppable_queue_size;
    MTPNP_UINT16 max_data_frame_length;	/* Max length of frame is 16384 */
} ST_OSAL_MSG_QUEUE_CAPACITY;

extern ST_OSAL_MSG_QUEUE_CAPACITY OSAL_get_msg_queue_capacity(void);

extern void MTPNP_DISABLE_INTERRUPT(void);
extern void MTPNP_ENABLE_INTERRUPT(void);

#ifdef __cplusplus
}
#endif


#endif /* __MTPNP_OSAL_COMMON_H__ */
