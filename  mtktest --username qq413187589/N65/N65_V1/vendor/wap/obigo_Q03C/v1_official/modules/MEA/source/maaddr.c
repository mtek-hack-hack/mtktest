/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

/*!\file maaddr.c
 * \brief Utility functions for MEA.
 */

/* MSF */
#include "msf_mem.h"
#include "msf_def.h"
#include "msf_cmmn.h"
#include "msf_lib.h"
#include "msf_core.h"
#include "msf_log.h"
#ifdef WAP_SUPPORT
#include "msf_wid.h"  //for MEA_GET_STR_ID
#endif /* WAP_SUPPORT */

/* MMS */
#include "mms_def.h"

/* MEA */
#include "mea_cfg.h"
#include "mea_def.h"
#include "mea_env.h"
#include "matypes.h"
#include "mamem.h"
#include "maintsig.h"
#include "maaddr.h"
#include "mapbh.h"
#ifdef WAP_SUPPORT
#include "mea_rc.h"
#include "mauidia.h"
#include "mauicmn.h"
#include "mamr.h" //for mame.h
#include "mame.h" //for meaMeAddressAlreadyExists

#include "app_usedetails.h"
#include "phonebook\phonebookinc\PhoneBookTypes.h"	//for MAX_PB_NAME_LENGTH
#include "widget_extension.h"
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Data-types
 *****************************************************************************/

/******************************************************************************
 * Constants
 *****************************************************************************/

#define IS_PHONE_NO_CHARACTER(c)   ((c == '+') /*|| (c == 'w') || (c == 'p') */|| (c == '0') || \
                                    (c == '1') || (c == '2') || (c == '3') || \
                                    (c == '4') || (c == '5') || (c == '6') || \
                                    (c == '7') || (c == '8') || (c == '9'))

#define IS_PHONE_NO_WRITTEN_CHARACTER(c)   (c == '-')

/* Separator for multiple addresses */
#define MEA_ADDR_SEPARATOR          ','

#define MEA_ADDR_MIN_LEN    1
/******************************************************************************
 * Prototypes
 *****************************************************************************/

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*! \brief Check all address is valide.
 *
 * \param MeaAddrItem *items.
 * \return TRUE if all is valid.
 *****************************************************************************/
MSF_BOOL meaRemoveInvalidAddr(MeaAddrItem **addrItem)
{
    MSF_BOOL flag = TRUE;
    MeaAddrItem *nowAddr, *preAddr;
    MSF_INT32 check_len;

    nowAddr = *addrItem;
    preAddr = NULL;
    while(nowAddr != NULL)
    {
        if(nowAddr->addrType == MEA_ADDR_TYPE_EMAIL)
        {
            check_len = MEA_ME_MAX_EMAIL_ADDRESS_SIZE ;
        }
        else 
        {
            check_len = MEA_ME_MAX_ADDRESS_SIZE ;
        }
        
        if(msf_cmmn_utf8_strlen(nowAddr->address) > check_len || 
            msf_cmmn_utf8_strlen(nowAddr->address) < MEA_ADDR_MIN_LEN)
        {
            flag = FALSE;
            if(preAddr == NULL)
            {
                *addrItem = (*addrItem)->next;
                nowAddr->next = NULL;
                meaAddrListFree(&nowAddr);
                nowAddr = *addrItem;

            }
            else
            {
                preAddr->next = nowAddr->next;
                nowAddr->next = NULL;
                meaAddrListFree(&nowAddr);
                nowAddr = preAddr->next;
            }
        }
        else
        {
            preAddr = nowAddr;
            nowAddr = nowAddr->next;
        }
    }

    return flag;
    
}
/*! \brief De-allocates a list of addresses.
 *
 * \param addrList A list of addresses.
 *****************************************************************************/
void meaFreeMmsAddressList(MmsAddressList *addrList)
{
    MmsAddressList *cur = addrList;
    MmsAddressList *prev;

    while (NULL != cur)
    {
        MEA_FREE(cur->current.address);
        cur->current.address = NULL;
        MEA_FREE(cur->current.name.text);
        cur->current.name.text = NULL;
        prev = cur;
        cur = cur->next;
        MEA_FREE(prev);
        prev = NULL;
    }
}

/*!
 * \brief Validates if a string is a valid address and returns its type 
 *
 * \param addr A '\0'terminated string.
 * \return See #MeaAddrType
 *****************************************************************************/
MeaAddrType meaGetAddrType(const char *addr)
{
    int i;
    char *ch = NULL;

    if (*addr == CHR('+'))
    {
        addr++;
    }    

    /* Check that the string is valid */
    if ((NULL == addr) || (MSF_EOS == addr[0]))
    {
        return MEA_ADDR_TYPE_NONE;
    }
    /* Check if the string is a phone no */
    for(i = 0; addr[i] != '\0'; i++)
    {
        if (!IS_PHONE_NO_CHARACTER(addr[i]) && !IS_PHONE_NO_WRITTEN_CHARACTER(addr[i]))
        {
            break;
        }
    }
    if ('\0' == addr[i])
    {
        return MEA_ADDR_TYPE_PLMN;
    }

    if ((ch = strchr(addr, '@')) != NULL)
    {
        /* Check if it is an email address */
        if (applib_is_valid_email_local_part(addr, (ch - addr)) &&
            applib_is_valid_email_domain_name(ch + 1))
        {
            return MEA_ADDR_TYPE_EMAIL;
        }
    }
	return MEA_ADDR_TYPE_NONE;
}

/*!\brief Converts a MEA address list to a MMS address list.
 *
 * \param addr The current address list.
 * \param mmsAddr 
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaAddrListToMms(const MeaAddrItem *addr, MmsAddressList **mmsAddr)
{
    MmsAddressList *mmsItem;
    MmsAddressList *prev;
    /* Go through all the current addresses */
    prev = NULL;
    while(NULL != addr)
    {
        /* Create new item */
        mmsItem = MEA_ALLOC(sizeof(MmsAddressList));
        memset(mmsItem, 0, sizeof(MmsAddressList));
        /* Copy data */
        /* Address */
        if (NULL != addr->address)
        {
            mmsItem->current.address = MEA_ALLOC(strlen(addr->address) + 1);
            strcpy(mmsItem->current.address, addr->address);
        }
        /* Name */
        if ((NULL != addr->name) && (addr->addrType == MEA_ADDR_TYPE_EMAIL))
        {
            mmsItem->current.name.text = MEA_ALLOC(strlen(addr->name) + 1);
            strcpy(mmsItem->current.name.text, addr->name);
        }
        mmsItem->current.name.charset = MMS_UTF8;
        /* Type */
        /*lint -e{788}*/
        switch(addr->addrType)
        {
        case MEA_ADDR_TYPE_EMAIL:
            mmsItem->current.addrType = MMS_EMAIL;
            break;
        case MEA_ADDR_TYPE_PLMN:
            mmsItem->current.addrType = MMS_PLMN;
            break;
        default:
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                MAADDR_82196AB6C3887538172F6F84664DE148, "(%s) (%d) Erroneous address type = %d\n", __FILE__, __LINE__,
                addr->addrType));
            return FALSE;
        }
        /* Insert the new item */
        if (NULL == *mmsAddr)
        {
            *mmsAddr = mmsItem;
        }
        else
        {
            /*lint -e{613} */
            prev->next = mmsItem;
        }
        prev = mmsItem;

        /* Next item */
        addr = addr->next;
    }
    return TRUE;
}

/*! \brief Converts a MMS address list to a #MeaAddrItem list
 *
 * \param list The list of MMS addresses, NULL if not used..
 * \param fromAddr The MMS from address, NULL if not used.
 * \param ignoreAddr This address is ignored when copying data from the src, 
 *                   use NULL for a full copy.
 * \return The address list or NULL.
 *****************************************************************************/
MeaAddrItem *meaMmsToAddrList(const MmsAddressList *list, 
    const char *ignoreAddr)
{
    MeaAddrItem *items = NULL;
    MeaAddrItem *current;
    MeaAddrItem *prev = NULL;

    while(NULL != list)
    {
        if (list->current.address && strlen(list->current.address) > 0 && 
            !((NULL != ignoreAddr) && (0 == msf_cmmn_strcmp_nc(list->current.address, ignoreAddr))))
        {
            current = MEA_ALLOC(sizeof(MeaAddrItem));
            memset(current, 0, sizeof(MeaAddrItem));
            current->address = MEA_ALLOC(strlen(list->current.address) + 1);
            strcpy(current->address, list->current.address);
            current->addrType = meaMmsAddrTypeToMea(list->current.addrType);
            if ((NULL != list->current.name.text) && 
                (MMS_UTF8 == list->current.name.charset))
            {
                current->name = MEA_ALLOC(strlen(list->current.name.text) + 1);
                strcpy(current->name, list->current.name.text);
            }
            if (NULL == items)
            {
                items = current;
            }
            else
            {
                /*lint -e{613} */
                prev->next = current;
            }
            prev = current;
        }
        list = list->next;
    }
    return items;
}

/*! \brief Converts a #MmsAddress a #MeaAddrItem
 *
 * \param fromAddr The MMS from address, NULL if not used.
 * \return The address item or NULL.
 *****************************************************************************/
MeaAddrItem *meaMmsFromToAddrItem(const MmsAddress *fromAddr)
{
    MeaAddrItem *current = NULL;

    if (fromAddr->address)
    {
        current = MEA_ALLOC(sizeof(MeaAddrItem));
        memset(current, 0, sizeof(MeaAddrItem));

        current->address = MEA_ALLOC(strlen(fromAddr->address) + 1);
        strcpy(current->address, fromAddr->address);
        current->addrType = meaMmsAddrTypeToMea(fromAddr->addrType);
        if ((NULL != fromAddr->name.text) && 
            (MMS_UTF8 == fromAddr->name.charset))
        {
            current->name = MEA_ALLOC(strlen(fromAddr->name.text) + 1);
            strcpy(current->name, fromAddr->name.text);
        }
    }
    return current;
}

/*!\brief Inserts a address item first in the list of addresses.
 *
 * \param current The current address list.
 * \param name The name of the contact.
 * \param addrType The address type, #see #MeaAddrItem.
 * \param addr The address
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaAddrItemInsert(MeaAddrItem **current, const char *name, 
    MeaAddrType addrType, const char *addr)
{
    MeaAddrItem *item;
    if ((NULL == current) || ((NULL == addr) && (NULL == name)))
    {
        return FALSE;
    }
    /* Allocate a new item */
    item = MEA_ALLOC(sizeof(MeaAddrItem));
    memset(item, 0, sizeof(MeaAddrItem));
    /* Address */
    if (NULL != addr)
    {
        item->address = MEA_ALLOC(strlen(addr) + 1);
        strcpy(item->address, addr);
    }
    /* Name */
    if (NULL != name)
    {
        item->name = MEA_ALLOC(strlen(name) + 1);
        strcpy(item->name, name);
    }
    item->addrType = addrType;
    /* Insert first in the list */
    if (NULL != *current)
    {
        item->next = *current;
    }
    *current = item;
    return TRUE;
}

/*! \brief Converts a MMS addres type to a MEA address type
 *
 * \param mmsType The MMS address type.
 * \return The corresponding MEA addres type.
 *****************************************************************************/
MeaAddrType meaMmsAddrTypeToMea(MmsAddressType mmsType)
{
    /*lint -e{788} */
    switch(mmsType)
    {
    case MMS_PLMN:
        return MEA_ADDR_TYPE_PLMN;
    case MMS_EMAIL:
        return MEA_ADDR_TYPE_EMAIL;
    case MMS_IPV4:
        return MEA_ADDR_TYPE_IPV4;
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAADDR_DD6EFAA5BF870C3ADB0FE8A5FCDC6F5B, "(%s) (%d) unsupported address type = %d\n", __FILE__, __LINE__, 
            mmsType));
        return MEA_ADDR_TYPE_NONE;
    }
}

/*!\brief De-allocates a list of addresses.
 *
 * \param current The address list to de-allocate.
 *****************************************************************************/
void meaAddrListFree(MeaAddrItem **current)
{
    MeaAddrItem *item;
    while(NULL != *current)
    {
        item = *current;
        /* De-allocate structure */
        MEA_FREE(item->name);
        MEA_FREE(item->address);
        /* Next item */
        *current = item->next;
        MEA_FREE(item);
    }
    *current = NULL;
}

/*!\brief Counts the number of addresses in a list.
 *
 * \param items The list of items to count
 * \return The number of items.
 *****************************************************************************/
unsigned int meaAddrItemCount(const MeaAddrItem *items)
{
    unsigned int count = 0;

    while(NULL != items)
    {
        ++count;
        items = items->next;
    }
    return count;
}

/*! \brief Replaces/inserts the name entry of all items that have a 
 *         corresponding address as the lookuEntry
 *
 * \param items A list of addresses.
 * \param lookupEntry The entry to merge with the list items.
 *****************************************************************************/
void meaAddrItemMerge(MeaAddrItem *items, const MeaAddrItem *lookupEntry)
{
    char *str;
#ifdef WAP_SUPPORT
    if (NULL == lookupEntry->name || strlen(lookupEntry->name) < 1)
#else
    if (NULL == lookupEntry->name)
#endif /* WAP_SUPPORT */
    {
        return;
    }
    while(NULL != items)
    {
        if ((lookupEntry->addrType == items->addrType) &&
            (0 == msf_cmmn_strcmp_nc(lookupEntry->address, items->address)))
        {
            if (NULL != (str = MEA_ALLOC(strlen(lookupEntry->name) + 1)))
            {
                MEA_FREE(items->name);
                items->name = str;
                strcpy(items->name, lookupEntry->name);
            }
        }
        items = items->next;
    }
}

/*! \brief Delets an address item from the list
 *
 * \param items The list of items.
 * \param index The index to delete.
 *****************************************************************************/
#ifdef WAP_SUPPORT
void meaAddrItemDelete(MeaAddrItem **items, signed int index)
#else
void meaAddrItemDelete(MeaAddrItem **items, unsigned int index)
#endif
{
#ifdef WAP_SUPPORT
    signed int i = 0;
#else
    unsigned int i = 0;
#endif /* WAP_SUPPORT */
    MeaAddrItem *current;
    MeaAddrItem *prev;
    if (NULL != *items)
    {
#ifdef WAP_SUPPORT
        if (-1 == index)
        {
            meaAddrListFree(items);
            return;
        }
#endif /* WAP_SUPPORT */
        if (0 == index)
        {
            current = *items;
            *items = (*items)->next;
            MEA_FREE(current->address);
            MEA_FREE(current->name);
            MEA_FREE(current);
            return;
        }
        current = *items;
        prev = NULL;
        while(NULL != current)
        {
            if (i == index)
            {
                /*lint -e{613} */
                prev->next = current->next;
                MEA_FREE(current->address);
                MEA_FREE(current->name);
                MEA_FREE(current);
                return;
            }
            prev = current;
            current = current->next;
            i++;
        }
    }
}

/*! \brief Appends two list of addresses
 *
 * \param first The first list
 * \param second The second list (appended on the first one)
 * \return The new list.
 *****************************************************************************/
MeaAddrItem *meaAddrItemAppend(MeaAddrItem *first, MeaAddrItem *second)
{
    MeaAddrItem *tmp;
    if (NULL == first)
    {
        return second;
    }
    tmp = first;
    while(NULL != tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = second;
    return first;
}

/*! \brief Converts a address item to a string
 *
 * \param item A list of addresses
 *****************************************************************************/
char *meaAddrItemToStr(MeaAddrItem *item)
{
    MeaAddrItem *tmp;
    unsigned int strLen = 0;
    char *str = NULL;
    char *strPos;
    tmp = item;
    /* Count string length */
    while(NULL != tmp)
    {
        if (MEA_ADDR_TYPE_EMAIL == tmp->addrType)
        {
            if (NULL != tmp->name)
            {
                strLen += strlen(tmp->name);
                strLen += sizeof(MEA_CFG_EMAIL_BEGIN_STR) + 
                    sizeof(MEA_CFG_EMAIL_END_STR);
            }
            if (NULL != tmp->address)
            {
                strLen += strlen(tmp->address);
            }
        }
        else if (MEA_ADDR_TYPE_PLMN == tmp->addrType || MEA_ADDR_TYPE_IPV4 == tmp->addrType)
        {
            if (NULL != tmp->name)
            {
                strLen += strlen(tmp->name);
            }else if (NULL != tmp->address)
            {
                strLen += strlen(tmp->address);
            }
        }
        strLen += sizeof(MEA_CFG_MMS_ADDRESS_SEPARATOR);
        tmp = tmp->next;
    }
    strLen += sizeof(MSF_EOS);
    /* Allocate memory for the new string */
    str = MEA_ALLOC(strLen);
    /* Make the address string */
    tmp = item;
    strPos = str;
    strPos[0] = MSF_EOS;
    while(NULL != tmp)
    {
        if (MEA_ADDR_TYPE_EMAIL == tmp->addrType)
        {
            if ((NULL != tmp->name) && (NULL != tmp->address))
            {
                sprintf(strPos, "%s%s%s%s", tmp->name, MEA_CFG_EMAIL_BEGIN_STR, 
                    tmp->address, MEA_CFG_EMAIL_END_STR);
            }
            else if (NULL != tmp->address)
            {
                sprintf(strPos, "%s", tmp->address);
            }
            else
            {
                tmp = tmp->next;
                continue;
            }
        }
        else if (MEA_ADDR_TYPE_PLMN == tmp->addrType || MEA_ADDR_TYPE_IPV4 == tmp->addrType)
        {
            if (NULL != tmp->name)
            {
                sprintf(strPos, "%s", tmp->name);
            }else if (NULL != tmp->address)
            {
                sprintf(strPos, "%s", tmp->address);
            }
            else
            {
                tmp = tmp->next;
                continue;
            }
        }
        else
        {
            tmp = tmp->next;
            continue;
        }
        /* Append the comma separator */
        if (NULL != tmp->next)
        {
            strcat(strPos, MEA_CFG_MMS_ADDRESS_SEPARATOR);
        }
        /* Find the next position to add */
        strPos = &(str[strlen(str)]);
        tmp = tmp->next;
    }
    return str;
}

/*! \brief Converts a comma separated list in the a list of #MeaAddrItem.
 *
 * \param str A comma separated list of addresses
 *****************************************************************************/
MeaAddrItem *meaAddrStrToList(char *str)
{
    MeaAddrItem *list = NULL;
    MeaAddrItem *current;
    MeaAddrType addrType;
    char *currPos;
    char *prevPos;
    if (NULL == str)
    {
        return list;
    }
    currPos = NULL;
    prevPos = str;
    while(NULL != (currPos = strchr(prevPos, MEA_ADDR_SEPARATOR)))
    {
        currPos[0] = MSF_EOS;
        addrType = meaGetAddrType(prevPos);
        if (MEA_ADDR_TYPE_NONE != addrType)
        {
            /* Insert the address */
            current = MEA_ALLOC(sizeof(MeaAddrItem));
            memset(current, 0, sizeof(MeaAddrItem));
            current->addrType = addrType;
            current->address = msf_cmmn_strdup(MSF_MODID_MEA, prevPos);
            list = meaAddrItemAppend(list, current);
        }
        currPos[0] = MEA_ADDR_SEPARATOR;
        prevPos = currPos + 1;
    }
    /* Handle the first/last item in the list */
    addrType = meaGetAddrType(prevPos);
    if (MEA_ADDR_TYPE_NONE != addrType)
    {
        /* Insert the address */
        current = MEA_ALLOC(sizeof(MeaAddrItem));
        memset(current, 0, sizeof(MeaAddrItem));
        current->addrType = addrType;
        current->address = msf_cmmn_strdup(MSF_MODID_MEA, prevPos);
        list = meaAddrItemAppend(list, current);
    }
    return list;
}

/*! \brief Change an address item
 *
 * \param items The list of addresses.
 * \param newItem The new item.
 * \param index The index of the item to change.
 *****************************************************************************/
void meaChangeAddr(MeaAddrItem *items, MeaAddrItem *newItem, unsigned int index)
{
    unsigned int i;
#ifdef WAP_SUPPORT
    int foundIndex = meaMeAddressAlreadyExists(items, newItem);
    if ((foundIndex > -1) && (foundIndex != (int)index)) //if the same record, still update
    {
        /* Already Exists */
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ADDRESS_ALREADY_EXISTS), 
            MEA_DIALOG_ERROR);
        meaAddrListFree(&newItem);
        return;
    }
#endif /* WAP_SUPPORT */
    for(i = 0; index != i; i++)
    {
        items = items->next;
    }
    /* Delete old item */
    MEA_FREE(items->name);
    MEA_FREE(items->address);
    items->name     = newItem->name;
    items->address  = newItem->address;
    items->addrType = newItem->addrType;
    MEA_FREE(newItem);
}

char *meaLookupNameFromPHB(char *number_str)
{
    int dest_len = 0, sizeInByte = MAX_PB_NAME_LENGTH * 3 + 1; // length should be the same as MMI
    char *name = NULL, *number = NULL, *ptr = NULL;

    if (number_str == NULL)
    {
        return NULL;
    }

    ptr = number_str;
    number = MEA_ALLOC(strlen(number_str) + 1);
    while (*ptr != '\0')
    {
        if (IS_PHONE_NO_CHARACTER(*ptr) == KAL_TRUE)
        {
            number[dest_len++] = *ptr;
        }
        ptr++;
    }
    number[dest_len] = '\0';

    if (*number_str == '+')
    {
        dest_len--;
    }
    
    if (dest_len > MAX_PB_NUMBER_LENGTH)
    {
        return NULL;
    }
    
    name = MEA_ALLOC(sizeInByte);
    HDIa_widgetExtRemoteLookupPhbName(number, name, sizeInByte);
    MEA_FREE(number);
    return name; // name will be released later
}

/*! \brief Lookup a list of names.
 *
 * \param list the list of current addresses
 *****************************************************************************/
void meaNameLookup(MeaAddrItem *list, MeaStateMachine fsm, int sig)
{
    while(NULL != list)
    {
        if (NULL == list->name)
        {
            if (list->addrType == MEA_ADDR_TYPE_PLMN)
                list->name = meaLookupNameFromPHB(list->address);
        }
        list = list->next;
    }
}

