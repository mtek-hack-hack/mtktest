/***********************************************
File name : MTPNP_PFAL_category_screen.h
Contents : MTPNP pfal category screen API
History : Create by : Zhang Nan, May 9, 2007
************************************************/
#ifndef _MTPNP_PFAL_MMI_SCREEN_H_
#define _MTPNP_PFAL_MMI_SCREEN_H_

#ifdef __MMI_DUAL_SIM_MASTER__

/* MTK header file */
#include "gui_data_types.h"
#include "wgui_categories_defs.h"
/* MTK header file */

/* MTPNP header file */
#include "MTPNP_AD_master_header.h"
/* MTPNP header file */

/* ZN revise */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
extern void ShowCategory363Screen(MTPNP_UINT16 title,
                                MTPNP_UINT16 title_icon,
                                MTPNP_UINT16 left_softkey,
                                MTPNP_UINT16 left_softkey_icon,
                                MTPNP_UINT16 right_softkey,
                                MTPNP_UINT16 right_softkey_icon,
                                MTPNP_INT32 number_of_items,
                                MTPNP_UINT8 ** list_of_items,
                                MTPNP_UINT16 highlighted_item,
                                MTPNP_UINT32 duration, MTPNP_AD_FuncPtr callback, MTPNP_UINT8 * history_buffer);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
extern void SetCat363TimerExpireFunc(MTPNP_AD_FuncPtr f);
extern void wgui_cat363_clear_callback(void);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* idle screen */
void idle_screen_show_card2_network_name(MMI_BOOL is_clock);
void idle_screen_show_card2_network_status(void);
/* idle screen */

void mmi_mtpnp_entry_menu( U16 scr_id, FuncPtr exit_func, FuncPtr entry_func, U16 menu_id, U16 str_id, U16 img_id);

#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif // _MTPNP_PFAL_MMI_SCREEN_H_
