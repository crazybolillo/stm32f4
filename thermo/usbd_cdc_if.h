#ifndef __USBD_CDC_IF_TEMPLATE_H
#define __USBD_CDC_IF_TEMPLATE_H

#include "usbd_cdc.h"

#define USB_RX_BUFFER_SIZE 64
#define USB_TX_BUFFER_SIZE 1024

extern USBD_CDC_ItfTypeDef USBD_CDC_Template_fops;

uint8_t CDC_Transmit(uint8_t* buffer, uint32_t len);

#endif /* __USBD_CDC_IF_TEMPLATE_H */
