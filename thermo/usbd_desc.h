#ifndef __USBD_DESC_TEMPLATE_H
#define __USBD_DESC_TEMPLATE_H

#include "usbd_def.h"

#define DEVICE_ID1 (UID_BASE)
#define DEVICE_ID2 (UID_BASE + 0x4U)
#define DEVICE_ID3 (UID_BASE + 0x8U)

/*
 * USB Billboard Class USER string desc Defines Template
 * index should start form 0x10 to avoid using the reserved device string desc indexes
 */
#if (USBD_CLASS_USER_STRING_DESC == 1)
#define USBD_BB_IF_STRING_INDEX 0x10U
#define USBD_BB_URL_STRING_INDEX 0x11U
#define USBD_BB_ALTMODE0_STRING_INDEX 0x12U
#define USBD_BB_ALTMODE1_STRING_INDEX 0x13U
/* Add Specific USER string Desc */
#define USBD_BB_IF_STR_DESC (uint8_t *)"STM32 BillBoard Interface"
#define USBD_BB_URL_STR_DESC (uint8_t *)"www.st.com"
#define USBD_BB_ALTMODE0_STR_DESC (uint8_t *)"STM32 Alternate0 Mode"
#define USBD_BB_ALTMODE1_STR_DESC (uint8_t *)"STM32 Alternate1 Mode"
#endif /* USBD_CLASS_USER_STRING_DESC  */

#define USB_SIZ_STRING_SERIAL 0x1AU

#if (USBD_LPM_ENABLED == 1)
#define USB_SIZ_BOS_DESC 0x0CU
#elif (USBD_CLASS_BOS_ENABLED == 1)
#define USB_SIZ_BOS_DESC 0x5DU
#endif /* USBD_LPM_ENABLED  */

#define USBD_VID 0x0483
#define USBD_PID 0xaaaa
#define USBD_LANGID_STRING 0xbbb
#define USBD_MANUFACTURER_STRING "ZoftKo"
#define USBD_PRODUCT_HS_STRING "Thermo"
#define USBD_PRODUCT_FS_STRING "Thermo"
#define USBD_CONFIGURATION_HS_STRING \
    "USB Serial Config" /* Add your configuration High Speed string */
#define USBD_INTERFACE_HS_STRING "USB Serial Interface" /* Add your Interface High Speed string */
#define USBD_CONFIGURATION_FS_STRING \
    "USB Serial Config FS" /* Add your configuration Full Speed string */
#define USBD_INTERFACE_FS_STRING \
    "USB Serial Interface FS" /* Add your Interface Full Speed string */

extern USBD_DescriptorsTypeDef CDC_Desc;

#endif /* __USBD_DESC_TEMPLATE_H*/
