#include "MMI_Features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

#include "GlobalMenuItems.h"
#include "string.h"
#include "GlobalMenuItems.h"
#include "PixtelDataTypes.h"
#include "CustDataRes.h"
#include "CustMenuRes.h"
#include "gui_themes.h"
#include "FontDcl.h"
#include "gui.h"
#include "wgui.h"
#include "DownloadProtos.h"
#include "MMI_features.h"

#include "MTPNP_PFAL_resource.h"

extern CUSTOM_MENU nCustMenus[MAX_MENU_ITEMS];

void MTPNP_PFAL_Update_Menu_Item_String(MTPNP_UINT16 menu_id, MTPNP_UINT16 string_id)
{
    MTPNP_UINT16 i;
    for (i = 0; i < MAX_MENU_ITEMS_VALUE; i++)
    {
        if (nCustMenus[i].nMenuItemId == menu_id)
        {
            nCustMenus[i].nStrId = string_id;
        }
    }
}

#endif /* __MMI_DUAL_SIM_MASTER__ */
